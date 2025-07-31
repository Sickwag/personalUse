#pragma once
#include <string>
#include <vector>

struct EmailData {
    std::vector<std::string> parts;
    size_t current_part;
    size_t pos_in_part;
};
struct EmailTemplate {
    std::string smtp_server, username, password, from, to, subject, body;
    int port;
    std::vector<std::string> attachments;
};

class EmailSender {
   private:
   
   public:
    std::string generateCaptcha() const;
    EmailTemplate email_config;
    /**
     * @note 建议主函数开头使用curl_global_init(CURL_GLOBAL_DEFAULT)，发送完邮件之后使用curl_global_cleanup()，释放资源，不建议纳入send_email函数中，否则建立连接和释放连接开销较大
     */
    bool send_email(EmailTemplate& et);

   private:
    std::string simple_base64_encode(const std::string& data);
    std::vector<std::string> encode_file_chunks(const std::string& filepath);
    std::string get_filename(const std::string& filepath);
    void prepare_email_content(EmailData& email_data,
                               EmailTemplate& et);
};
size_t payload_source(void* ptr, size_t size, size_t nmemb, void* userp);