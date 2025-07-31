#pragma once
#include <time.h>
#include <algorithm>
#include <boost/asio.hpp>
#include <chrono>
#include <format>
#include <functional>
#include <iostream>
#include <limits>
#include <numeric>
#include <regex>
#include <string>
#include <vector>
#include <nlohmann/json.hpp>
#include <curl/curl.h>
#include <curl/easy.h>

using json = nlohmann::json;
namespace asio = boost::asio;

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output) {
    size_t total = size * nmemb;
    output->append(static_cast<char*>(contents), total);
    return total;
}

void get_weather();
class Time {
   public:
    static std::pair<tm, std::string> get_current_time() {
        auto now = std::chrono::system_clock::now();
        auto now_c = std::chrono::system_clock::to_time_t(now);
        std::tm now_tm = *std::localtime(&now_c);
        std::string now_time_str = std::format("{:%Y-%m-%d %H:%M:%S}", now);
        return std::make_pair(now_tm, now_time_str);
    }
};

/**
 * @brief A versatile input validator class template.
 *
 * This class provides a flexible way to validate user inputs of various types.
 * It supports a wide range of built-in validators and allows for custom validation functions.
 * The class is designed to be used in a chainable manner for ease of use.
 *
 * @tparam T The type of the input to be validated.
 */
template <typename T>
class InputValidator {
   public:
    using ValidatorFunc = std::function<bool(const T&)>;
    using ValidatorFuncAsync = std::function<asio::awaitable<bool>(const T&)>;
    using ValidatorPair = std::pair<ValidatorFunc, std::string>;
    using ValidatorPairAsync = std::pair<ValidatorFuncAsync, std::string>;
    InputValidator();
    bool validate(const T& input) const;
    InputValidator& prompt(const std::string& prompt);
    InputValidator& enum_str(const std::vector<std::string>& allowed, const std::string& error_msg = "You must input one of ({}).");

    template <typename U = T, typename = std::enable_if_t<std::is_arithmetic_v<U>>>
    InputValidator& range(U min, U max, const std::string& error_fmt = "Must be between {} and {}.");
    InputValidator& regex(const std::string& pattern, const std::string& error_msg = "Input does not match the required pattern.");
    InputValidator& length_range(size_t min, size_t max, const std::string& error_fmt = "Length must be between {} and {}.");
    InputValidator& length_range(size_t length, const std::string& error_fmt = "Length must be {}.");
    InputValidator& not_emtpy(const std::string& error_msg = "Input cannot be empty.");
    InputValidator& not_contains(const std::vector<std::string>& not_allowed, const std::string& error_msg = "Input must not contain ({}).");
    InputValidator& contains(const std::vector<std::string>& must_contains, const std::string& error_msg = "Input must contain ({}).");
    InputValidator& custom(ValidatorFunc condition, const std::string& error_msg);
    InputValidator& yes_or_no(const std::string& error_msg = "Please input yes (Y, Yes, YES) or no (N, No, NO).");
    InputValidator& email(const std::string& error_msg = "Invalid email format.");
    InputValidator& url(const std::string& error_msg = "Invalid URL format.");
    InputValidator& numeric(const std::string& error_msg = "Input must be a valid number.");
    InputValidator& date(const std::string& error_msg = "Invalid date format. Use YYYY-MM-DD.");
    InputValidator& password_strength(const std::string& error_msg = "Password must contain at least one uppercase letter, one lowercase letter, one digit, and one special character.", bool upper = true, bool lower = true, bool digit = true, bool special = true);
    InputValidator& ignore_case(const std::string& error_msg = "you have input nothing.") const;
    T render() const;

    InputValidator& custom_async(ValidatorFuncAsync condition_async, const std::string& error_msg);
    asio::awaitable<T> render_async() const;

   private:
    std::string prompt_;
    std::string general_error_msg_;
    std::vector<ValidatorPair> validators_;
    std::vector<ValidatorPairAsync> async_validators_;
    void handleInputError(const std::string& error_msg) const;
};

template <typename T>
InputValidator<T>::InputValidator()
    : prompt_("Input: "), general_error_msg_("Invalid input, please try again.") {}

template <typename T>
InputValidator<T>& InputValidator<T>::prompt(const std::string& prompt) {
    if (!prompt.empty()) {
        prompt_ = prompt;
    }
    return *this;
}

template <typename T>
InputValidator<T>& InputValidator<T>::enum_str(const std::vector<std::string>& allowed, const std::string& error_msg) {
    if (allowed.empty()) {
        throw std::invalid_argument("Allowed list cannot be empty.");
    }
    std::string allowed_str = std::accumulate(allowed.begin() + 1, allowed.end(), allowed[0],
                                              [](const std::string& a, const std::string& b) { return a + ", " + b; });
    // std::string msg = std::format(error_msg, allowed_str);
    std::string msg = std::vformat(error_msg, std::make_format_args(allowed_str));
    validators_.emplace_back(
        [allowed](const std::string& s) {
            return std::find(allowed.begin(), allowed.end(), s) != allowed.end();
        },
        msg);
    return *this;
}

template <typename T>
template <typename U, typename>
InputValidator<T>& InputValidator<T>::range(U min, U max, const std::string& error_fmt) {
    std::string msg = std::vformat(error_fmt, std::make_format_args(min, max));
    validators_.emplace_back(
        [min, max](const U& value) { return value >= min && value <= max; },
        msg);
    return *this;
}

template <typename T>
InputValidator<T>& InputValidator<T>::regex(const std::string& pattern, const std::string& error_msg) {
    std::regex re(pattern);
    validators_.emplace_back(
        [re](const std::string& s) { return std::regex_match(s, re); },
        error_msg);
    return *this;
}

template <typename T>
InputValidator<T>& InputValidator<T>::length_range(size_t min, size_t max, const std::string& error_fmt) {
    // std::string msg = std::format(error_fmt, min, max);
    std::string msg = std::vformat(error_fmt, std::make_format_args(min, max));
    validators_.emplace_back(
        [min, max](const std::string& s) { return s.size() >= min && s.size() <= max; },
        msg);
    return *this;
}

template <typename T>
InputValidator<T>& InputValidator<T>::length_range(size_t length, const std::string& error_fmt) {
    // std::string msg = std::format(error_fmt, length);
    std::string msg = std::vformat(error_fmt, std::make_format_args(length));
    validators_.emplace_back(
        [length](const std::string& s) -> bool { return s.size() == length; },
        msg);
    return *this;
}

template <typename T>
InputValidator<T>& InputValidator<T>::not_emtpy(const std::string& error_msg) {
    validators_.emplace_back(
        [](const std::string& s) { return !s.empty(); },
        error_msg);
    return *this;
}

template <typename T>
InputValidator<T>& InputValidator<T>::not_contains(const std::vector<std::string>& not_allowed, const std::string& error_msg) {
    if (not_allowed.empty())
        return *this;
    std::string not_allowed_str = std::accumulate(not_allowed.begin() + 1, not_allowed.end(), not_allowed[0],
                                                  [](const std::string& a, const std::string& b) { return a + ", " + b; });
    std::string msg = std::format(error_msg, not_allowed_str);
    validators_.emplace_back(
        [not_allowed](const std::string& s) {
            return std::none_of(not_allowed.begin(), not_allowed.end(),
                                [&s](const std::string& str) { return s.find(str) != std::string::npos; });
        },
        msg);
    return *this;
}

template <typename T>
InputValidator<T>& InputValidator<T>::contains(const std::vector<std::string>& must_contains, const std::string& error_msg) {
    if (must_contains.empty())
        return *this;
    std::string must_contains_str = std::accumulate(must_contains.begin() + 1, must_contains.end(), must_contains[0],
                                                    [](const std::string& a, const std::string& b) { return a + ", " + b; });
    std::string msg = std::format(error_msg, must_contains_str);
    validators_.emplace_back(
        [must_contains](const std::string& s) {
            return std::all_of(must_contains.begin(), must_contains.end(),
                               [&s](const std::string& str) { return s.find(str) != std::string::npos; });
        },
        msg);
    return *this;
}

template <typename T>
InputValidator<T>& InputValidator<T>::custom(ValidatorFunc condition, const std::string& error_msg) {
    validators_.emplace_back(condition, error_msg);
    return *this;
}

template <typename T>
InputValidator<T>& InputValidator<T>::yes_or_no(const std::string& error_msg) {
    validators_.emplace_back(
        [](const std::string& s) {
            std::string lower_s = s;
            std::transform(lower_s.begin(), lower_s.end(), lower_s.begin(), ::tolower);
            return lower_s == "y" || lower_s == "yes" || lower_s == "n" || lower_s == "no";
        },
        error_msg);
    return *this;
}

template <typename T>
InputValidator<T>& InputValidator<T>::email(const std::string& error_msg) {
    return regex(R"(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$)", error_msg);
}

template <typename T>
InputValidator<T>& InputValidator<T>::url(const std::string& error_msg) {
    return regex(R"(^(https?://)?([a-zA-Z0-9.-]+)(\.[a-zA-Z]{2,})(:\d+)?(/.*)?$)", error_msg);
}

template <typename T>
InputValidator<T>& InputValidator<T>::numeric(const std::string& error_msg) {
    return regex(R"(^-?\d+(\.\d+)?([eE][-+]?\d+)?$)", error_msg);
}

template <typename T>
InputValidator<T>& InputValidator<T>::date(const std::string& error_msg) {
    return regex(R"(^\d{4}-\d{2}-\d{2}$)", error_msg);
}

template <typename T>
InputValidator<T>& InputValidator<T>::password_strength(const std::string& error_msg, bool upper, bool lower, bool digit, bool special) {
    validators_.emplace_back(
        [&](const std::string& s) {
            bool has_upper = upper ? std::any_of(s.begin(), s.end(), ::isupper) : false;
            bool has_lower = lower ? std::any_of(s.begin(), s.end(), ::islower) : false;
            bool has_digit = digit ? std::any_of(s.begin(), s.end(), ::isdigit) : false;
            bool has_special = special ? std::any_of(s.begin(), s.end(), [](char c) { return !std::isalnum(c); }) : false;
            return has_upper && has_lower && has_digit && has_special;
        },
        error_msg);
    return *this;
}

template <typename T>
inline InputValidator<T>& InputValidator<T>::ignore_case(const std::string& error_msg) const {
    validators_.emplace(validators_.begin(), [](std::string& s) -> bool {
        if (s.empty())
            return false;
        for (auto& c : s) {
            c = std::tolower(c);
        }
        return true;
    });
    return *this;
}

template <typename T>
bool InputValidator<T>::validate(const T& input) const {
    for (const auto& validator_pair : validators_) {
        if (!validator_pair.first(input)) {
            return false;
        }
    }
    return true;
}

template <typename T>
T InputValidator<T>::render() const {
    if (!async_validators_.empty()) {
        throw std::runtime_error("you have coroutine validators, you should use `render_async()` instead of `render()`");
    }
    T value;
    while (true) {
        std::cout << prompt_;
        std::cin >> value;
        if (std::cin.fail()) {
            handleInputError(general_error_msg_);
            continue;
        }
        bool valid = true;
        for (const auto& [cond, msg] : validators_) {
            if (!cond(value)) {  // Changed from cond(value) to cond(value)
                std::cout << msg << '\n';
                handleInputError(msg);
                valid = false;
                break;
            }
        }
        if (valid)
            break;
    }
    return value;
}

template <typename T>
inline InputValidator<T>& InputValidator<T>::custom_async(ValidatorFuncAsync condition_async, const std::string& error_msg) {
    async_validators_.emplace_back(condition_async, error_msg);
    return *this;
}

template <typename T>
inline asio::awaitable<T> InputValidator<T>::render_async() const {
    T value;
    while (true) {
        std::cout << prompt_;
        std::cin >> value;
        if (std::cin.fail()) {
            handleInputError(general_error_msg_);
            continue;
        }
        bool async_valid = true;
        for (const auto& [async_cond, msg] : async_validators_) {
            auto async_validate_result = co_await async_cond(value);
            if (!async_validate_result) {
                std::cout << msg << '\n';
                async_valid = false;
                break;
            }
        }
        if (!async_valid)
            continue;

        bool sync_valid = true;
        for (const auto& [cond, msg] : validators_) {
            if (!cond(value)) {
                std::cout << msg << '\n';
                async_valid = false;
                break;
            }
        }
        if (sync_valid && async_valid)
            co_return value;
    }
}

template <typename T>
void InputValidator<T>::handleInputError(const std::string& error_msg) const {
    std::cin.clear();
    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
    // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << error_msg << std::endl;
}
