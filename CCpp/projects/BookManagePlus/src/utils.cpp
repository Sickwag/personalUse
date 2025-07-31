#include "utils.h"

void get_weather() {
    CURL* curl = curl_easy_init();
    if (!curl)
        return;

    std::string response;
    curl_easy_setopt(curl, CURLOPT_URL, "https://api.dwo.cc/api/tianqi?districtId=上海市");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L);
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

    CURLcode rc = curl_easy_perform(curl);
    if (rc != CURLE_OK) {
        std::cerr << "request failed: " << curl_easy_strerror(rc) << '\n';
        curl_easy_cleanup(curl);
        return;
    }

    long status = 0;
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &status);
    curl_easy_cleanup(curl);

    if (status != 200 || response.empty()) {
        std::cerr << "HTTP error/empty\n";
        return;
    }

    try {
        json j = json::parse(response);
        if (j.value("code", 0) == 1) {
            const auto& d = j["data"];
            std::cout << "城市: " << d.value("city", "") << "\n"
                      << "日期: " << d.value("date", "") << "\n"
                      << "天气: " << d.value("weather", "") << "\n"
                      << "当前温度: " << d.value("temp", "") << "\n"
                      << "体感: " << d.value("feelsLike", "") << "\n"
                      << "最低/最高: " << d.value("lowTemp", "") << "/" << d.value("highTemp", "") << "\n"
                      << "风向风力: " << d.value("wind", "") << "\n";
        } else {
            std::cerr << "API error: " << j.value("message", "") << '\n';
        }
    } catch (const std::exception& e) {
        std::cerr << "JSON parse error: " << e.what() << '\n';
    }
}
