#include<bits/stdc++.h>
using namespace std;

class I18n {
private:
    enum class Language : unsigned int { ENGLISH, CHINESE };
    Language current_lang;
    bool loaded = false;
    I18n() :current_lang(Language::ENGLISH) { load_if_is_not_load(); }
    unordered_map<string, unordered_map<Language, string>> dict;
    void load_if_is_not_load() {
        if (!loaded) {
            load_translations(R"(D:\Code Files\vscode\CCpp\modernCpp\lang\en.txt)", R"(D:\Code Files\vscode\CCpp\modernCpp\lang\zh.txt)");
        }
    }

public:
    static I18n& get_instance() {
        static I18n instance;
        return instance;
    }
    void set_language(string lang) {
        auto to_lower = [&lang]() {for_each(lang.begin(), lang.end(), ::tolower);};
        if (lang == "chinese") current_lang = Language::CHINESE;
        else if (lang == "english") current_lang = Language::ENGLISH;
    }
    void load_translations(const string& en_path, const string& zh_path) {
        auto load = [this](const string& lang_file_path, Language lang) {
            ifstream fin(lang_file_path);
            if (!fin) return;
            string line;
            while (getline(fin, line)) {
                string key, value;
                istringstream iss(line);
                if (getline(iss, key, '=') && getline(iss, value)) {
                    dict[key][lang] = value;
                }
            }
            };
        load(en_path, Language::ENGLISH);
        load(zh_path, Language::CHINESE);
    }

    string translate(const string& key) {
        if (dict.contains(key) && dict[key].contains(current_lang)) {
            return dict[key][current_lang];
        }
        return "[NOT FOUND]";
    }
};

string operator"" _i18n(const char* key, size_t) {
    return I18n::get_instance().translate(key);
}

int main() {
    I18n::get_instance().load_translations(R"(D:\Code Files\vscode\CCpp\modernCpp\lang\en.txt)", R"(D:\Code Files\vscode\CCpp\modernCpp\lang\zh.txt)");
    I18n::get_instance().set_language("CHINESE");
    cout << "login_button"_i18n << endl;
    cout << "sava_file"_i18n << endl;
    return 0;
}











// template <size_t n, typename... T>
// constexpr variant<T...> _tuple_index(const tuple<T...>& tpl, size_t i) {
//     if constexpr (n >= sizeof...(T))
//         throw out_of_range("heap-out-of-range.");
//     if (i == n)
//         return variant<T...>{ in_place_index<n>, get<n>(tpl) };
//     return _tuple_index<(n < sizeof...(T) - 1 ? n + 1 : 0)>(tpl, i);
// }
// template <typename... T>
// constexpr variant<T...> tuple_index(const tuple<T...>& tpl, size_t i) {
//     return _tuple_index<0>(tpl, i);
// }
// template <typename T0, typename ... Ts>
// ostream& operator<< (ostream& s, variant<T0, Ts...> const& v) {
//     visit([&](auto&& x) { s << x;}, v);
//     return s;
// }

// template<typename Tuple>
// void perfect_print_tuple(Tuple&& t) {
//     apply([&](auto&& ... items) {
//         ((cout << "value: " << items << ", type: " << typeid(decltype(items)).name() << '\n'), ...);
//         }, forward<Tuple>(t));
// }

// template <typename Key, typename Value, typename F>
// void update(map<Key, Value>& m, F foo) {
//     for (auto& [k, v] : m) {
//         v = foo(k);
//     }
//     return;
// }

// template<typename num, typename... Args>
// auto calcu_avg(num n, Args... nums) {
//     int count = 1;
//     double sum = 0.0 + n;
//     ((sum += nums), ...);
//     return sum / count;
// }

// int main() {
//     map<string, long long int> m{
//         {"a", 1},
//         {"b", 2},
//         {"c", 3}
//     };
//     update(m, [](string key) {
//         return hash<string>{}(key);
//         });
//     for (auto&& [key, value] : m)
//         cout << key << ":" << value << endl;
// }

// using foo = void(int); // 定义函数类型, using 的使用见上一节中的别名语法
// void functional(foo f) { // 参数列表中定义的函数类型 foo 被视为退化后的函数指针类型 foo*
//     f(1); // 通过函数指针调用函数
// }

// int main() {
//     auto f = [](int value) {
//         cout << value << endl;
//         };
//     functional(f); // 传递闭包对象，隐式转换为 foo* 类型的函数指针值
//     f(1); // lambda 表达式调用

//     auto lamb = [](auto value) noexcept(is_same<decltype(value), double>()) -> int {return value * value;};
//     cout << lamb(10);
//     return 0;
// }

// void f(int a, int b, int c) {
//     cout << a << " " << b << " " << c << endl;
// }
// int main() {
//     auto g = bind(f, 1, placeholders::_1, placeholders::_2);
//     g(2, 3); // 等价于 f(1, 2, 3)
//     // 类比于：
//     void f(int a = 1, int b, int c); // a 为默认值
    
// }
// atomic<int> atomic_count(0);
// int non_atomic_count = 0;
// void atomic_increment() {
//     for (int i = 0; i < 100000; ++i) {
//         ++atomic_count;
//     }
// }
// void non_atomic_increment() {
//     for (int i = 0; i < 100000; ++i) {
//         ++non_atomic_count;
//     }
// }

// int main() {

//     thread t3(non_atomic_increment);
//     t3.join();
//     thread t4(non_atomic_increment);
//     t4.join();
//     cout << "atomic_count = " << atomic_count << endl;  // 精确为 200000
//     cout << "non_atomic_count = " << non_atomic_count << endl; // 可能随机更高、更低
// }

// struct Distance {
//     double dis;
// };

// Distance operator"" _km(long double dis) {
//     string result;
//     return Distance{ static_cast<double>(dis * 1000) };
// }

// regex operator"" _re(const char* restr, size_t len) {
//     return regex(restr, len);
// }

// struct BigStruct {
//     int id;
//     string name;
//     pair<float, string> info;
//     unordered_map<double, string> values;
// };

// constexpr size_t operator"" _str_hash(const char* str, size_t len) {
//     size_t result = 14695981039346656037ULL;
//     for (size_t i = 0;i < len;i++) {
//         result ^= hash<char>{}(str[i]);
//     }
//     return result;
// }

