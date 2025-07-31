#include "email_sender.h"
#include <curl/curl.h>
#include <algorithm>
#include <fstream>
#include <random>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>



// 简单的base64编码（简化版）
std::string EmailSender::simple_base64_encode(const std::string& data) {
    static const char* chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    std::string result;
    int val = 0, valb = -6;

    for (unsigned char c : data) {
        val = (val << 8) + c;
        valb += 8;
        while (valb >= 0) {
            result.push_back(chars[(val >> valb) & 0x3F]);
            valb -= 6;
        }
    }
    if (valb > -6)
        result.push_back(chars[((val << 8) >> (valb + 8)) & 0x3F]);
    while (result.size() % 4)
        result.push_back('=');
    return result;
}

// 分块读取文件并编码
std::vector<std::string> EmailSender::encode_file_chunks(const std::string& filepath) {
    std::vector<std::string> chunks;
    std::ifstream file(filepath, std::ios::binary);
    if (!file.is_open()) {
        throw std::runtime_error("Cannot open file: " + filepath);
    }

    const size_t chunk_size = 57;  // base64编码后为76字符
    char buffer[chunk_size];

    while (file.read(buffer, chunk_size) || file.gcount() > 0) {
        std::string chunk(buffer, file.gcount());
        chunks.push_back(simple_base64_encode(chunk) + "\r\n");
    }

    return chunks;
}

std::string EmailSender::get_filename(const std::string& filepath) {
    size_t pos = filepath.find_last_of("/\\");
    return (pos != std::string::npos) ? filepath.substr(pos + 1) : filepath;
}

// 准备邮件内容
void EmailSender::prepare_email_content(EmailData& email_data, EmailTemplate& et) {
    std::string boundary = "----=_NextPart_SimpleBoundary";

    if (et.attachments.empty()) {
        // 简单邮件
        std::stringstream ss;
        ss << "From: " << et.from << "\r\n"
           << "To: " << et.to << "\r\n"
           << "Subject: " << et.subject << "\r\n"
           << "\r\n"
           << et.body << "\r\n"
           << ".\r\n";
        email_data.parts.push_back(ss.str());
    } else {
        // 多部分邮件 - 头部
        std::stringstream ss;
        ss << "From: " << et.from << "\r\n"
           << "To: " << et.to << "\r\n"
           << "Subject: " << et.subject << "\r\n"
           << "MIME-Version: 1.0\r\n"
           << "Content-Type: multipart/mixed; boundary=" << boundary << "\r\n"
           << "\r\n"
           << "This is a multi-part message in MIME format.\r\n"
           << "--" << boundary << "\r\n"
           << "Content-Type: text/plain; charset=UTF-8\r\n"
           << "\r\n"
           << et.body << "\r\n";
        email_data.parts.push_back(ss.str());

        // 每个附件
        for (const auto& filepath : et.attachments) {
            try {
                // 附件分隔符
                std::stringstream header_ss;
                header_ss << "\r\n--" << boundary << "\r\n"
                          << "Content-Type: application/octet-stream\r\n"
                          << "Content-Transfer-Encoding: base64\r\n"
                          << "Content-Disposition: attachment; filename=\"" << get_filename(filepath) << "\"\r\n"
                          << "\r\n";
                email_data.parts.push_back(header_ss.str());

                // 附件内容（分块添加）
                auto chunks = encode_file_chunks(filepath);
                for (const auto& chunk : chunks) {
                    email_data.parts.push_back(chunk);
                }
            } catch (const std::exception& e) {
                std::cerr << "Warning: Failed to process attachment " << filepath << ": " << e.what() << std::endl;
            }
        }

        // 结束边界
        std::stringstream end_ss;
        end_ss << "\r\n--" << boundary << "--\r\n.\r\n";
        email_data.parts.push_back(end_ss.str());
    }
}

size_t payload_source(void* ptr, size_t size, size_t nmemb, void* userp) {
    EmailData* data = static_cast<EmailData*>(userp);
    size_t max_size = size * nmemb;
    size_t copied = 0;
    char* buffer = static_cast<char*>(ptr);

    while (data->current_part < data->parts.size() && copied < max_size) {
        const std::string& part = data->parts[data->current_part];
        size_t part_remaining = part.size() - data->pos_in_part;

        if (part_remaining > 0) {
            // size_t to_copy = std::min(max_size - copied, part_remaining);
            size_t to_copy = max_size - copied > part_remaining ? part_remaining : max_size - copied;
            memcpy(buffer + copied, part.data() + data->pos_in_part, to_copy);
            data->pos_in_part += to_copy;
            copied += to_copy;
        }

        if (data->pos_in_part >= part.size()) {
            data->current_part++;
            data->pos_in_part = 0;
        }
    }
    return copied;
}

std::string EmailSender::generateCaptcha() const {
    std::random_device rd;                           // 随机设备，用于种子
    std::mt19937 gen(rd());                          // 用随机设备初始化随机数引擎
    std::uniform_int_distribution<> dis(0, 999999);  // 均匀分布，范围[0, 999999]
    int code = dis(gen);                             // 生成随机数
    char buffer[7];                                  // 6位数字 + 终止符 '\0'
    snprintf(buffer, sizeof(buffer), "%06d", code);  // 格式化为6位，不足补0
    return std::string(buffer);
}

bool EmailSender::send_email(EmailTemplate& et) {
    CURL* curl = curl_easy_init();
    if (!curl)
        return false;

    CURLcode res = CURLE_OK;
    struct curl_slist* recipients = nullptr;

    // 设置基本SMTP参数
    std::string url = "smtp://" + et.smtp_server + ":" + std::to_string(et.port);
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_USE_SSL, (long)CURLUSESSL_ALL);
    curl_easy_setopt(curl, CURLOPT_USERNAME, et.username.c_str());
    curl_easy_setopt(curl, CURLOPT_PASSWORD, et.password.c_str());
    curl_easy_setopt(curl, CURLOPT_MAIL_FROM, et.from.c_str());

    recipients = curl_slist_append(recipients, et.to.c_str());
    curl_easy_setopt(curl, CURLOPT_MAIL_RCPT, recipients);

    // 准备邮件数据
    EmailData email_data = {};
    email_data.current_part = 0;
    email_data.pos_in_part = 0;

    try {
        prepare_email_content(email_data, et);
    } catch (const std::exception& e) {
        std::cerr << "Error preparing email: " << e.what() << std::endl;
        curl_slist_free_all(recipients);
        curl_easy_cleanup(curl);
        return false;
    }

    // 设置数据读取回调
    curl_easy_setopt(curl, CURLOPT_READFUNCTION, payload_source);
    curl_easy_setopt(curl, CURLOPT_READDATA, &email_data);
    curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);
    // curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L); // send email process debug

    res = curl_easy_perform(curl);

    if (res != CURLE_OK) {
        std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
    }else {
        std::cout << "send email from " + et.from + " to " + et.to + " successfully!";
    }

    curl_slist_free_all(recipients);
    curl_easy_cleanup(curl);

    return res == CURLE_OK;
}