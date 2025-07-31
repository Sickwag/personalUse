#include <vector>
#include <functional>
#include <string>
#include <format>
#include <algorithm>
#include <regex>
#include<numeric>

template<typename T>
class InputValidator {
private:
    std::string prompt_ = "input: ";
    std::vector < std::pair < std::function<bool(const T&)>, std::string >> validators_;
    std::string general_error_msg = "Invalid input, please try again.";
    void handle_input_error(const std::string& error_msg) const;

public:
    InputValidator& prompt(const std::string& prompt);
    InputValidator& enum_str(const std::vector<std::string>& allowed, const std::string& error_msg = "you should input one of ({}), try again.");
    InputValidator& range(int min, int max, const std::string& error_fmt = "Must be between {} and {}.");
    InputValidator& regex(const std::string& pattern, const std::string& error_msg = "Input does not match pattern.");
    InputValidator& length_range(size_t min, size_t max, const std::string& error_fmt = "Length must be between {} and {}.");
    InputValidator& not_empty(const std::string& error_msg = "Input cannot be empty.");
    InputValidator& not_contains(const std::vector<std::string>& chars_not_allowed, const std::string& error_msg = "Your input must without ({}) :");
    InputValidator& contains(const std::vector<std::string> chars_must_contains, const std::string& error_msg = "Your input must contains ({}) :");
    InputValidator& custom(const std::function<bool(const T&)>& condition, const std::string& error_msg);
    InputValidator& yes_or_no(const std::string& error_msg = "you have to input yes(Yes, YES, Y, y) or no(NO, No, N, n), try again.");

    T render() const;
};

template<typename T>
inline void InputValidator<T>::handle_input_error(const std::string& error_msg) const {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << error_msg << std::endl;
}

template<typename T>
inline InputValidator<T>& InputValidator<T>::prompt(const std::string& prompt) {
    if (!prompt.empty()) {
        prompt_ = prompt;
    }
    return *this;
}

template<typename T>
inline InputValidator<T>& InputValidator<T>::enum_str(const std::vector<std::string>& allowed, const std::string& error_msg) {
    if (allowed.empty()) {
        throw std::runtime_error("you have not input allowed list yet!");
    }
    std::string result_string = std::accumulate(allowed.begin(), allowed.end(), allowed[0], [](const std::string& str1, const std::string& str2) {return str1 + " " + str2; });
    std::string msg = std::vformat(error_msg, std::make_format_args(result_string));
    validators_.emplace_back(
        [&allowed](const std::string& s) {
            return std::find(allowed.begin(), allowed.end(), std::string_view(s)) != allowed.end();
        },
        msg
    );
    return *this;
}

template<typename T>
inline InputValidator<T>& InputValidator<T>::range(int min, int max, const std::string& error_fmt) {
    std::string msg = std::vformat(error_fmt, std::make_format_args(min, max));
    validators_.emplace_back(
        [min, max](const int& value) { return value >= min && value <= max; },
        msg
    );
    return *this;
}

template<typename T>
inline InputValidator<T>& InputValidator<T>::regex(const std::string& pattern, const std::string& error_msg) {
    std::regex re(pattern);
    validators_.emplace_back(
        [&re](const std::string& s) { return std::regex_match(s, re); },
        error_msg
    );
    return *this;
}

template<typename T>
inline InputValidator<T>& InputValidator<T>::length_range(size_t min, size_t max, const std::string& error_fmt) {
    std::string msg = std::vformat(error_fmt, std::make_format_args(min, max));
    validators_.emplace_back(
        [min, max](const std::string& s) {return (s.size() >= min && s.size() <= max); },
        msg
    );
    return *this;
}

template<typename T>
inline InputValidator<T>& InputValidator<T>::not_empty(const std::string& error_msg) {
    validators_.emplace_back(
        [](const std::string& s) {return !s.empty(); },
        error_msg
    );
    return *this;
}

template<typename T>
inline InputValidator<T>& InputValidator<T>::not_contains(const std::vector<std::string>& strs_not_allowed, const std::string& error_msg) {
    if (strs_not_allowed.empty()) return *this;
    std::string result_string = std::accumulate(strs_not_allowed.begin(), strs_not_allowed.end(), strs_not_allowed[0], [](const std::string& str1, const std::string& str2) {return str1 + " " + str2; });
    std::string msg = std::vformat(error_msg, std::make_format_args(result_string));
    validators_.emplace_back(
        [&strs_not_allowed](const std::string& s) { return std::none_of(strs_not_allowed.begin(), strs_not_allowed.end(), [&s](const std::string& str) {return s.find(str) != std::string::npos; }); },
        msg
    );
    return *this;
}

template<typename T>
inline InputValidator<T>& InputValidator<T>::contains(const std::vector<std::string> strs_must_contains, const std::string& error_msg) {
    if (strs_must_contains.empty()) return *this;
    std::string result_string = std::accumulate(strs_must_contains.begin(), strs_must_contains.end(), strs_must_contains[0], [](const std::string& str1, const std::string& str2) {return str1 + " " + str2; });
    std::string msg = std::vformat(error_msg, std::make_format_args(result_string));
    validators_.emplace_back(
        [&strs_must_contains](const std::string& s) { return std::any_of(strs_must_contains.begin(), strs_must_contains.end(), [&s](const std::string& str) {return s.find(str) != std::string::npos; }); },
        msg
    );
    return *this;
}

template<typename T>
inline InputValidator<T>& InputValidator<T>::custom(const std::function<bool(const T&)>& condition, const std::string& error_msg) {
    validators_.emplace_back(condition, error_msg);
    return *this;
}

//template<typename T>
//inline InputValidator<T>& InputValidator<T>::numeric(const std::string& error_msg) {
//	validators_.emplace_back(
//		[](const std::string& s) {
//			return !s.empty() && std::all_of(s.begin(), s.end(),[](const char& c) {return std::isdigit(static_cast<unsigned char>(c));});
//		},
//		error_msg
//	);
//	return *this;
//}


template<typename T>
inline InputValidator<T>& InputValidator<T>::yes_or_no(const std::string& error_msg) {
    validators_.emplace_back(
        [](const std::string& s) {
            return s == "Y" || s == "y" || s == "Yes" || s == "YES" || s == "N" || s == "n" || s == "NO" || s == "No";
        },
        error_msg
    );
    return *this;
}

template<typename T>
inline T InputValidator<T>::render() const {
    T value{};
    while (true) {
        std::cout << prompt_;
        std::cin >> value;
        if (std::cin.fail()) {
            handle_input_error(general_error_msg);
            continue;
        }
        bool valid = true;
        for (const auto& [cond, msg] : validators_) {
            if (!cond(value)) {
                handle_input_error(msg);
                valid = false;
                break;
            }
        }
    if (valid) break;
    }
    return value;
}
