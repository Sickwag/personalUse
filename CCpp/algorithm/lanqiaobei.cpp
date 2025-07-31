#include <bits/stdc++.h>
#include "dataStruct.cpp"
using namespace std;

// -----------test module code----------------
// class MathTools {
// private:

// public:
//     long long get_factorial(long long n) {
//         long long result = 1;
//         for (long long i = 1;i <= n;i++) {
//             result *= i;
//         }
//         return result;
//     }

//     long long get_factorial_sum(long long n) {
//         if (n <= 0) return 0;
//         long long sum = 0, temp = 1;
//         for (long long i = 1; i <= n;i++) {
//             temp *= i;
//             sum += temp;
//         }
//         return sum;
//     }
// };

// class StringTools {
// public:
//     string convertBase(const string& input, int from, int to) {
//         string result;
//         const char* alpha = "0123456789abcdefghijklmnopqrstuvwxyz";
//         int num = 0;
//         // 转化为10进制
//         for (const char& c : input) {
//             int value = isdigit(c) ? c - '0' : tolower(c) - 'a' + 10;
//             num = num * from + value;
//         }
//         // 转化为to进制
//         while (num > 0) {
//             result.push_back(alpha[num % to]);
//             num /= to;
//         }
//         reverse(result.begin(), result.end());
//         return result;
//     }
//     string reverseWords(string& s) {
//         string result;
//         vector<string> temp_content;
//         regex pattern("\\w");
//         string::const_iterator search_start(s.cbegin());
//         smatch match;
//         while (regex_search(search_start, s.cend(), match, pattern)) {
//             temp_content.push_back(match.str(0));
//             search_start = match.suffix().first;
//         }
//         for_each(temp_content.rbegin(), temp_content.rend(), [&result](const string str) {
//             result += str + ' ';
//             });
//         return result;
//     }

//     string reverseWords(const string& s) {
//         vector<string> temp_content;
//         regex pattern("\\w+");
//         string result;
//         auto word_begin = sregex_iterator(s.begin(), s.end(), pattern);
//         auto word_end = sregex_iterator();
//         for (auto i = word_begin;i != word_end;i++) {
//             temp_content.emplace_back((*i).str());
//         }
//         for_each(temp_content.rbegin(), temp_content.rend(), [&result](const string str) {
//             result += str + ' ';
//             });
//         result.pop_back();
//         return result;
//     }

//     vector<string> get_permutation(string& input) {
//         vector<string> permutation;
//         sort(input.begin(), input.end());
//         do {
//             permutation.emplace_back(input);
//         } while (next_permutation(input.begin(), input.end()));
//         return permutation;
//     }
// };

// class TimeTools {
// private:
//     inline bool isLeapYear(int year) {
//         return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
//     }
// public:
//     // 两个日期之间的日期
//     vector<string> getDatesBetween(const string& start, const string& end) {
//         vector<string> res;
//         auto parse = [](const string& s) -> tm {
//             tm t = {};
//             t.tm_year = stoi(s.substr(0, 4)) - 1900;
//             t.tm_mon = stoi(s.substr(4, 2)) - 1;
//             t.tm_mday = stoi(s.substr(6, 2));
//             return t;
//             };
//         tm t1 = parse(start);
//         tm t2 = parse(end);
//         time_t time_1 = mktime(&t1);
//         time_t time_2 = mktime(&t2);
//         double timeDiff = difftime(time_2, time_1);
//         if (time_1 == -1 || time_2 == -1) return res;
//         while (time_1 < time_2) {
//             stringstream ss;
//             ss << put_time(&t1, "%Y%m%d");
//             res.push_back(ss.str());
//             t1.tm_mday++;
//             time_1 = mktime(&t1);
//         }
//         res.push_back("the time diff between " + start + " \\& " + end + " :" + to_string(timeDiff) + "s");
//         return res;
//     }

//     vector<string> generateAllDates(int year) {
//         vector<string> dates;
//         int monthDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//         if (isLeapYear(year)) monthDays[1] = 29;
//         for (int month = 1; month <= 12; month++) {
//             for (int day = 1; day <= monthDays[month - 1];day++) {
//                 ostringstream oss;
//                 oss << year
//                     << setw(2) << setfill('0') << month
//                     << setw(2) << setfill('0') << day;
//                 dates.emplace_back(oss.str());
//             }
//         }
//         return dates;
//     }
// };

// class TestFuctionsTools {
// private:
//     TimeTools tt;
//     StringTools st;
//     MathTools mt;
// public:
//     void test_permutation() {
//         string alpha = "abcd";
//         for (auto& x : st.get_permutation(alpha)) {
//             cout << x << '\n';
//         }
//     }

//     void test_reverseWords() {
//         string s = "hello world   blank";
//         cout << st.reverseWords(s);
//     }

//     void test_getDataBetween() {
//         string start = "20200426";
//         string end = "20200520";
//         for (auto& x : tt.getDatesBetween(start, end)) {
//             cout << x << endl;
//         }
//     }

//     void test_generateAllDates() {
//         int year = 2020;
//         for (auto& x : tt.generateAllDates(year)) {
//             cout << x << '\n';
//         }
//     }

//     void test_convertBase() {
//         string input = "2020";
//         int from = 9, to = 10;
//         cout << "number: " << input << " from " << from << " to " << to << " = " << st.convertBase(input, from, to);
//     }
//     void test_get_factorial() {
//         long long n = 10;
//         cout << mt.get_factorial(n) << '\n';
//     }
//     void test_get_factorial_sum() {
//         long long n = 10;
//         cout << mt.get_factorial_sum(n) << '\n';
//     }
// };

// int main() {
//     TestFuctionsTools tfs;
//     // tfs.test_get_factorial();
//     // tfs.test_get_factorial_sum();
//     // test_generateAllDates();
//     // test_getDataBetween();
//     // test_reverseWords();
//     // test_convertBase();
//     // test_permutation();
// }
// -----------test module code----------------
// class Solution {
// public:
//     string simplifyPath(string path) {
//         string res = filesystem::path{ path }.lexically_normal().string();
//         while (res.size() > 1 && (res.back() == '/' || res.back() == '\\'))
//             res.pop_back();
//         return res;
//     }
// };
// class Solution {
// public:
//     string simplifyPath(string path) {
//         return canonical(path).string(); // 或 path(path).lexically_normal().string()
//     }
// };

// int main() {
//     Solution sol;
//     string path = "C:\\Users\\Sickwag\\AppData\\Local\\VirtualStore\\Program Files (x86)\\..\\Dev-Cpp\\Projects";
//     cout << sol.simplifyPath(path);
// }

// 十一届蓝桥杯
// --------------------------------------------
// 扩散
// 自己重写一遍
// class Solution {
//     static const int N = 6500;
//     static const int offset = 2021;
//     struct node {
//         int x, y, t;
//     };
//     int dx[4] = { 0, 0, 1, -1 }; // 四个方向
//     int dy[4] = { 1, -1, 0, 0 };
//     queue<node> q;
//     bool visit[N][N];
// public:
//     Solution() {
//         memset(visit, false, sizeof(visit));
//         q.push({ 0 + offset, 0 + offset, 0 });
//         q.push({ 2020 + offset, 11 + offset, 0 });
//         q.push({ 11 + offset, 14 + offset, 0 });
//         q.push({ 2000 + offset, 2000 + offset, 0 });
//         visit[0 + offset][0 + offset] = 1;
//         visit[2020 + offset][11 + offset] = 1;
//         visit[11 + offset][14 + offset] = 1;
//         visit[2000 + offset][2000 + offset] = 1;
//     };
//     int bfs() {
//         int sum = 4;
//         while (!q.empty()) {
//             auto [x, y, t] = q.front();
//             q.pop();
//             if(t>=2020) continue;
//             for (int i = 0; i < 4; i++) {
//                 int nx = x + dx[i], ny = y + dy[i];
//                 if (nx < 0 || nx >= N || ny < 0 || ny >= N || visit[nx][ny] == true) continue;
//                 sum++;
//                 visit[nx][ny] = true;
//                 q.push({ nx,ny,t + 1 });
//             }
//         }
//         return sum;
//     }
// };
// int main() {
//     Solution sol;
//     cout << sol.bfs();
// }
// const int N = 10000;
// const int offset = 3021;
// bool st[N][N];

// struct node {
//     int x, y;
//     int m;
// };

// int bfs() {
//     queue<node> q;
//     q.push({ 0 + offset, 0 + offset, 0 });
//     q.push({ 2020 + offset, 11 + offset, 0 });
//     q.push({ 11 + offset, 14 + offset, 0 });
//     q.push({ 2000 + offset, 2000 + offset, 0 });
//     st[0 + offset][0 + offset] = 1;
//     st[2020 + offset][11 + offset] = 1;
//     st[11 + offset][14 + offset] = 1;
//     st[2000 + offset][2000 + offset] = 1;

//     int dx[4] = { 1, -1, 0, 0 };
//     int dy[4] = { 0, 0, 1, -1 };
//     int sum = 4;

//     while (!q.empty()) {
//         auto t = q.front();
//         q.pop();
//         if (t.m >= 2020) continue;
//         for (int i = 0; i < 4; i++) {
//             int nx = t.x + dx[i];
//             int ny = t.y + dy[i];

//             if (nx >= 0 && nx < N && ny >= 0 && ny < N && !st[nx][ny]) {
//                 st[nx][ny] = 1;
//                 q.push({ nx, ny, t.m + 1 });
//                 sum++;
//             }
//         }
//     }

//     return sum;
// }

// int main() {
//     cout << bfs() << endl;
//     return 0;
// }
// 异或为零的序列
// class Solution {
//     // struct VectorHash {
//     //     size_t operator()(const vector<int>& vec) const {
//     //         size_t hash = 0;
//     //         for (int x : vec) {
//     //             hash ^= std::hash<int>{}(x)+ 0x9e3779b9 + (hash << 6) + (hash >> 2);
//     //         }
//     //         return hash;
//     //     }
//     // };
//     // struct VectorHashEqual {
//     //     bool operator()(const vector<int>& a, const vector<int>& b) const {
//     //         return a == b;
//     //     }
//     // };
//     vector<int> init() {
//         int n;
//         cin >> n;
//         vector<int> nums(n);
//         for (int i = 0;i < n;i++) {
//             cin >> nums[i];
//         }
//         return nums;
//     }
//     inline bool isValid(vector<int>& path) {
//         return !reduce(path.begin(), path.end(), 0, bit_xor<int>());
//     }
//     void traceBack(vector<int>& nums, vector<int>& path, int startIndex, int& count) {
//         if (path.size() == nums.size()) return;
//         for (int i = startIndex; i < nums.size();i++) {
//             path.push_back(nums[i]);
//             // if (!records.contains(path)) {
//             //     records.insert(path);
//                 if (isValid(path)) {
//                     count = (count + 1) % mod;
//                 }
//             // }
//             traceBack(nums, path, i + 1, count);
//             path.pop_back();
//         }
//     }
//     const int mod = 998244353;
//     vector<int> path;
//     // unordered_set<vector<int>, VectorHash, VectorHashEqual> records;
// public:
//     void solve() {
//         int count = 0;
//         vector<int> nums = init(), path;
//         traceBack(nums, path, 0, count);
//         cout << count;
//     }
// };
// int main() {
//     Solution sol;
//     sol.solve();
// }
// 子串分值和

// 回文日期
// bool isValidDate(int year, int month, int day) {
//     if (month < 1 || month > 12 || day < 1) return false;
//     static const int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//     int maxDay = daysInMonth[month - 1];
//     if (month == 2) {
//         bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
//         maxDay += isLeap;
//     }
//     return day <= maxDay;
// }

// // 获取两个日期之间的所有回文日期
// vector<string> getDatesBetween(const string& startdate, const string& enddate) {
//     vector<string> dates;

//     // 将字符串解析为年份、月份、日期
//     int startYear = stoi(startdate.substr(0, 4));
//     int endYear = stoi(enddate.substr(0, 4));

//     // 枚举年份，生成回文日期
//     for (int year = startYear; year <= endYear; year++) {
//         string yearStr = to_string(year);
//         string monthDayStr = string(yearStr.rbegin(), yearStr.rend()); // 反转年份作为月日
//         int month = stoi(monthDayStr.substr(0, 2));
//         int day = stoi(monthDayStr.substr(2, 2));

//         // 检查日期是否合法
//         if (isValidDate(year, month, day)) {
//             string dateStr = yearStr + monthDayStr;
//             // 检查日期是否在目标范围内
//             if (dateStr >= startdate && dateStr <= enddate) {
//                 dates.emplace_back(dateStr);
//             }
//         }
//     }

//     return dates;
// }

// int main() {
//     string start, end;
//     cin >> start >> end;
//     cout << getDatesBetween(start, end).size() << endl;
//     return 0;
// }
// 超时做法，最大的时间消耗在不断日期++遍历的同时不断使用mktime消耗资源
// inline bool isHuiWen(string& date) {
//     int l = 0, r = date.size() - 1;
//     while (l < r) {
//         if (date[l++] != date[r--]) return false;
//     }
//     return true;
// }
// vector<string> getDdatasBetween(string& startdate, string& enddate) {
//     vector<string> dates;
//     auto parse = [](string s) -> tm {
//         tm t = {};
//         t.tm_year = stoi(s.substr(0, 4)) - 1900;
//         t.tm_mon = stoi(s.substr(4, 2)) - 1;
//         t.tm_mday = stoi(s.substr(6, 2));
//         return t;
//         };
//     tm t1 = parse(startdate);
//     tm t2 = parse(enddate);
//     time_t time_1 = mktime(&t1);
//     time_t time_2 = mktime(&t2);
//     if (time_1 == -1 || time_2 == -1) return dates;
//     while (time_1 <= time_2) {
//         stringstream ss;
//         ss << put_time(&t1, "%Y%m%d");
//         string judge = ss.str();
//         if (isHuiWen(judge)) {
//             dates.emplace_back(judge);
//         }
//         t1.tm_mday++;
//         time_1 = mktime(&t1);
//     }
//     return dates;
// }

// int main() {
//     string start, end;
//     cin >> start >> end;
//     cout << getDdatasBetween(start, end).size();
//     return 0;
// }

// 既约分数
// int main() {
//     // cout << gcd(5, 7);  2481215  2481214
//     long long count = 0;
//     for (int i = 1;i <= 2020;i++) {
//         for (int j = 1;j <= 2020;j++) {
//             if (gcd(i, j) == 1) count++;
//         }
//     }
//     cout << count;
// }

// 二进制问题 60%通过率
// int main() {
//     long long n, count = 0;
//     int k;
//     cin >> n >> k;
//     for (long long i = 1; i <= n; i++) {
//         if (__builtin_popcount(i) == k) count++;
//     }
//     cout << count;
//     return 0;
// }
// 异或变换 70% 通过率
// inline string change(string& input) {
//     string output;
//     output.resize(input.size());
//     output[0] = input[0];
//     for (int i = 1;i < input.size();i++) {
//         output[i] = (input[i] - '0') ^ (input[i - 1] - '0') + '0';
//     }
//     return output;
// }
// int main() {
//     int length, times;
//     cin >> length >> times;
//     string input;
//     cin >> input;
//     for (int i = 0;i < times;i++) {
//         input = change(input);
//     }
//     cout << input;
// }
// inline bool isLeapYear(int year) {
//     return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
// }
// vector<string> generateAllDates(int year) {
//     vector<string> dates;
//     int monthDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//     if (isLeapYear(year)) monthDays[1] = 29;
//     for (int month = 1; month <= 12; month++) {
//         for (int day = 1; day <= monthDays[month - 1];day++) {
//             ostringstream oss;
//             oss << year
//                 << setw(2) << setfill('0') << month
//                 << setw(2) << setfill('0') << day;
//             dates.emplace_back(oss.str());
//         }
//     }
//     return dates;
// }
// int getCount() {
//     int count = 0;
//     for (int i = 2001; i <= 2021;i++) {
//         vector<string> dates = generateAllDates(i);
//         for (string& x : dates) {
//             int sum = accumulate(x.begin(), x.end(), 0, [&](int acc, char& y) {
//                 return acc + (y - '0');
//                 });
//             int res = sqrt(sum);
//             if (res * res == sum) count++;
//         }
//     }
//     return count;
// }
// int main() {
//     cout << getCount();
// }
// 货物摆放
// template <typename T>
// vector<T> getFactors(T n) {
//     vector<T> factors;
//     for (T i = 1; i * i <= n; i++) {
//         if (n % i == 0) {
//             factors.push_back(i);
//             if (i != n / i) {
//                 factors.push_back(n / i);
//             }
//         }
//     }
//     sort(factors.begin(), factors.end());
//     return factors;
// }
// template <typename T>
// int countCuboids(T n) {
//     vector<T> factors = getFactors(n);
//     int res = 0;
//     for (T a : factors) {
//         T m = n / a;
//         vector<T> mFactors = getFactors(m);
//         for (T b : mFactors) {
//             if (b < a) continue;
//             if (m % b != 0) continue;
//             T c = m / b;
//             if (c < b) continue;
//             if (a == b && b == c) res++;
//             else if (a == b || b == c) res += 3;
//             else res += 6;
//         }
//     }
//     return res;
// }
// 123
// using ll = long long;
// const int limit = 1414214 + 10;
// // void build_record(unordered_map<int,ll>& records) {
// //     ll sum = 0;
// //     for (int i = 1;i <= limit;i++) {
// //         sum += i;
// //         records.insert({ i, sum });
// //     }
// // }
// void build_record(unordered_map<int, ll> & records) {
//     ll sum = 0;
//     for (int i = 0;i <= limit;i++) {
//         sum += i;
//         records.insert({ i, sum });
//     }
// }
// void test_build() {
//     map<int, ll> records;
//     // build_record(records);
//     int count = 30;
//     for (auto it = records.rbegin(); it != records.rend(); it++) {
//         count--;
//         cout << (*it).first << " " << (*it).second << endl;
//         if(count == 0) break;
//     }
// }
// inline ll get_item(ll m) {
//     for (ll i = 1;;i++) {
//         if ((i - 1) * i >= 2 * m) {
//             return i - 1;
//         }
//     }
//     return 1;
// }
// inline ll calcuSum(ll l, ll r, unordered_map<int, ll>& records) {
//     ll left = get_item(l), right = get_item(r);
//     if (left == right) {
//         return ((l - left * (left - 1) / 2) + (r - right * (right - 1) / 2)) * (r - l + 1) / 2;
//     }
//     else if (left < right) {
//         ll sum = 0;
//         int temp_left = left;
//         while (temp_left < right) {
//             sum += records[++temp_left];
//         }
//         sum -= ((l - left * (left - 1) / 2)) * (l - left * (left - 1) / 2) / 2;
//         return sum;
//     }
//     return 0;
// }
// void pre_sum(unordered_map<int, ll>& records) {
//     vector<uint64_t> pre_sum(records.size() + 1, 0);
//     for (ll i = 1;i < records.size();i++) {
//         pre_sum[i] = records[i] + records[i + 1];
//     }
// }
// void get_ans() {
//     unordered_map<int, ll> records;
//     build_record(records);
//     ll n, l, r;
//     cin >> n;
//     for (int i = 0;i < n;i++) {
//         cin >> l >> r;
//         cout << calcuSum(l, r, records);
//     }
// }
// int main() {
//     get_ans();
//     // cout << get_item(1) << endl;
//     // cout << get_item(3) << endl;
//     // cout << get_item(5) << endl;
//     // cout << get_item(8) << endl;
// }
// const ll target = 1000000000000;
// int main() {
//     for (ll i = 100;;i++) {
//         if (i * (i + 1) / 2 > target) {
//             cout << i;
//             break;
//         }
//     }
//     return 0;
//     // found 1414214
// }
// 大写
// int main() {
//     string input;
//     cin >> input;
//     for (char& x : input ) {
//         x = toupper(x);
//     }
//     cout << input;
//     return 0;
// }
// 完全日期
// inline bool isValid(int sum) {
//     int root = sqrt(sum);
//     if (root * root == sum) return true;
//     else return false;
// }
// int generate_data_sum(int year, bool is_run) {
//     int year_sum = 0, sum = 0, count = 0;
//     while (year > 0) {
//         year_sum += year % 10;
//         year /= 10;
//     }
//     int p_month[13] = { 0,31,28,31,30,31,30,
//                         31,31,30,31,30,31 };
//     int r_month[13] = { 0,31,29,31,30,31,30,
//                         31,31,30,31,30,31 };
//     if (is_run) {
//         for (int m = 1;m <= 12;m++) {
//             for (int d = 1;d <= r_month[m];d++) {
//                 sum = sum + m + d;
//                 // cout << sum << endl;
//                 if (isValid(sum)) count++;
//                 sum = 0;
//             }
//         }
//     }
//     else {
//         for (int m = 1;m <= 12;m++) {
//             for (int d = 1;d <= p_month[m];d++) {
//                 sum = sum + year_sum + m + d;
//                 // cout << sum << endl;
//                 if (isValid(sum)) count++;
//                 sum = 0;
//             }
//         }
//     }
//     // int arr_size = sizeof(month) / sizeof(month[0]);
//     // cout << accumulate(month, month + arr_size, 0);
//     return count;
// }
// bool isLeapYear(int year) {
//     // 判断是否是闰年
//     if (year % 400 == 0) {
//         return true; // 能被 400 整除，是闰年
//     }
//     else if (year % 100 == 0) {
//         return false; // 能被 100 整除但不能被 400 整除，不是闰年
//     }
//     else if (year % 4 == 0) {
//         return true; // 能被 4 整除但不能被 100 整除，是闰年
//     }
//     else {
//         return false; // 其他情况，不是闰年
//     }
// }
// void test_gene() {
//     generate_data_sum(2021, false);
// }
// void test_isValid() {
//     cout << isValid(16) << endl;
//     cout << isValid(32) << endl;
//     cout << isValid(4) << endl;
//     cout << isValid(8) << endl;
//     cout << isValid(81) << endl;
// }
// int main() {
//     int sum = 0;
//     for (int i = 2001;i <= 2021;i++) {
//         sum += generate_data_sum(i, isLeapYear(i));
//     }
//     cout << sum;
//     return 0;
//     // test_gene();
//     // test_isValid();
// }
// 纯质数
// vector<int> euler(int b) {
//     vector<int> primes;
//     vector<bool> isPrime(b + 1, true);
//     isPrime[0] = isPrime[1] = false;
//     for (int i = 2;i <= b;i++) {
//         if (isPrime[i]) {
//             primes.push_back(i);
//         }
//         for (int j = 0;j < primes.size() && primes[j] * i <= b;j++) {
//             isPrime[primes[j] * i] = false;
//             if (i % primes[j] == 0) {
//                 break;
//             }
//         }
//     }
//     return primes;
// }

// bool isPure(int n, unordered_set<int>& records) {
//     while (n > 0) {
//         int temp = n % 10;
//         if (!records.contains(temp)) {
//             return false;
//         }
//         n /= 10;
//     }
//     return true;
// }
// int main() {
//     const int target = 20210605;
//     int count = 0;
//     vector<int> primes = euler(target);
//     unordered_set<int> records(primes.begin(), primes.end());
//     for (int& x : primes) {
//         if (isPure(x, records)) {
//             count++;
//         }
//     }
//     cout << count;
//     return 0;
// }
// int test_euler() {
//     vector<int> test = euler(100);
//     for (auto& x : test ) {
//         cout << x << " ";
//     }
// }
// int fib(int n) {
//     if (n == 1 || n == 2) return 1;
//     return fib(n - 1) + fib(n - 2);
// }
// int main() {
//     for (int i = 3;;i++) {
//         if (fib(i) > 20230232) {
//             cout << i;
//             break;
//         }
//     }
//     return 0;
// }

// 卡片
// int main() {
//     int n;
//     cin >> n;
//     for (int i = 0;;i++) {
//         if (i * (i + 1) >= n * 2) {
//             cout << i;
//             break;
//         }
//     }
// }
// 双向排序
// #include<iostream>
// #include<algorithm>
// #include<vector>
// #include<numeric>
// using namespace std;
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     int n, m, p, q;
//     cin >> n >> m;
//     vector<int> nums(n);
//     iota(nums.begin(), nums.end(), 1);
//     for (int i = 0;i < m;i++) {
//         cin >> p >> q;
//         if (p == 0) {
//             sort(nums.begin(), nums.begin() + q, greater<int>());
//         }
//         else {
//             sort(nums.begin() + q - 1, nums.end());
//         }
//     }
//     for (int& x : nums) {
//         cout << x << " ";
//     }
// }
// 卡片
// int main() {
//     int n;
//     cin >> n;
//     cout << ((int)sqrt(1 + 8 * n) - 1) / 2;
//     return 0;
// }
// 2718. 查询后矩阵的和
// 不超时版本
// class Solution {
// public:
//     long long matrixSumQueries(int n, vector<vector<int>>& queries) {
//         long long ans = 0;
//         unordered_set<int> vis[2];
//         for (int i = queries.size() - 1; i >= 0; i--) {
//             auto& q = queries[i];
//             int type = q[0], index = q[1], val = q[2];
//             if (!vis[type].count(index)) { // 后面（>i）没有对这一行/列的操作
//                 // 这一行/列还剩下 n-vis[type^1].size() 个可以填入的格子
//                 ans += (long long)(n - vis[type ^ 1].size()) * val;
//                 vis[type].insert(index);
//             }
//         }
//         return ans;
//     }
// };
// 超时
// class Solution {
// public:
//     long long matrixSumQueries(int n, vector<vector<int>>& queries) {
//         long long result = 0;
//         const int length = queries.size();
//         int count = 0;
//         vector<vector<bool>> isVisited(n, vector<bool>(n, false));
//         for (int x = length - 1; x >= 0; x--) {
//             int type = queries[x][0], index = queries[x][1], val = queries[x][2];
//             if (count < n * n) {
//                 if (type == 0) {
//                     for (int j = 0;j < n;j++) {
//                         if (isVisited[index][j] == false) {
//                             result += val;
//                             isVisited[index][j] = true;
//                             count++;
//                         }
//                     }
//                 }
//                 else {
//                     for (int i = 0;i < n;i++) {
//                         if (isVisited[i][index] == false) {
//                             result += val;
//                             isVisited[i][index] = true;
//                             count++;
//                         }
//                     }
//                 }
//             }
//             else {
//                 break;
//             }
//         }
//         return result;
//     }
// };
// int main() {
//     vector<vector<int>> matrix = { {0,0,1},{1,2,2},{0,2,3},{1,0,4} };
//     cout << Solution().matrixSumQueries(3, matrix);
// }
// X进制减法
// vector<int> get_result(vector<int>& a, vector<int>& b) {
//     vector<int> result;
//     for (int i = a.size() - 1, j = b.size() - 1;i >= 0 || j >= 0;) {
//         if (i >= 0 && j >= 0) {
//             result.push_back(max(a[i], b[j]) + 1);
//             i--, j--;
//         }
//         if (i < 0 && j >= 0) {
//             result.push_back(b[j] + 1);
//             j--;
//         }
//         if (i >= 0 && j < 0) {
//             result.push_back(a[i] + 1);
//             i--;
//         }
//     }
//     reverse(result.begin(),result.end());
//     return result;
// }
// int main() {
//     int limit, a, b;
//     cin >> limit;
//     cin >> a;
//     vector<int> num_a(a);
//     for (int i = 0;i < a;i++) {
//         cin >> num_a[i];
//     }
//     cin >> b;
//     vector<int> num_a(b);
//     for (int i = 0;i < b;i++) {
//         cin >> num_a[i];
//     }
// }
// bool isValid(string data) {
//     if (data[0] + 1 == data[1] && data[1] + 1 == data[2])
//         return true;
//     if (data[1] + 1 == data[2] && data[2] + 1 == data[3])
//         return true;
//     return false;
// }
// void judge() {
//     int month[13] = { 0, 31,28,31,30,31,30,
//                  31,31,30,31,30,31 };
//     string m, d;
//     int count = 0;
//     for (int i = 1; i <= 12; i++) {
//         for (int j = 1; j <= month[i]; j++) {
//             if (i < 10)
//                 m = '0' + to_string(i);
//             else
//                 m = to_string(i);
//             if (j < 10)
//                 d = '0' + to_string(j);
//             else
//                 d = to_string(j);
//             string data = m + d;

//             if (isValid(data)) {
//                 cout << data << endl;
//                 count++;
//             }
//         }
//     }
//     cout << count;
// }
// int main() {
//     judge();
//     return 0;
// }
// 进制转换，九进制转换为十进制
// string convertBase(const string& input, int fromBase, int toBase) {
//     string result;
//     const char* alpha = "0123456789abcdefghijklmnopqrstuvwxyz";
//     int num = 0;
//     for (char c : input) {
//         int value = isdigit(c) ? c - '0' : tolower(c) - 'a' + 10;
//         num = num * fromBase + value;
//     }
//     while (num > 0) {
//         result.push_back(alpha[num % toBase]);
//         num /= toBase;
//     }
//     reverse(result.begin(), result.end());
//     return result.empty() ? "0" : result;
// }

// 子串缩写
// 正则表达式方法由于懒惰匹配问题很难实现，所以使用遍历方法
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     int k, count = 0;
//     cin >> k;
//     string input;
//     cin >> input;
//     char start, end;
//     cin >> start >> end;
//     vector<int> head, tail;
//     for (int i = 0;i < input.size();i++) {
//         if (input[i] == start) head.push_back(i);
//         if (input[i] == end) tail.push_back(i);
//     }
//     for (int i = 0;i < head.size();i++) {
//         for (int j = 0;j < tail.size();j++) {
//             if (tail[j] - head[i] > k - 2) count++;
//         }
//     }
//     cout << count;
//     return 0;
// }
// 日期统计
// 冶炼金属
// int main() {
//     int n;
//     int x, y, low, high;
//     int lowest = INT_MIN, highest = INT_MAX;
//     // cin >> n;
//     ifstream inputFile("D:\\edge下载目录\\3510.in(1)");
//     inputFile >> n;
//     for (int i = 0;i < n;i++) {
//         inputFile >> x >> y;
//         low = ceil(1.0 * x / (y + 1.0));
//         high = floor(1.0 * x / y);
//         lowest = max(low, lowest);
//         highest = min(high, highest);
//     }
//     cout << lowest << " " << highest;
// }
// 数字接龙
// const int N = 11;
// class Solution {
// private:
//     int n, k;
//     string path;
//     int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 }; // 定义8个方向的x坐标偏移
//     int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
//     int board[N][N];
//     bool visited[N][N] = {};
//     bool edge[N][N][N][N] = {};
//     bool dfs(int a, int b) {
//         if (a == n - 1 && b == n - 1) return path.size() == n * n - 1;
//         visited[a][b] = true;
//         for (int i = 0; i < 8; i++) {
//             int x = a + dx[i], y = b + dy[i];
//             if (x < 0 || x >= n || y < 0 || y >= n) continue;
//             if (visited[x][y] == true) continue;
//             if (board[x][y] != (board[a][b] + 1) % k) continue;
//             if (i % 2 && (edge[a][y][x][b] || edge[x][b][a][y])) continue;
//             edge[a][b][x][y] = true;
//             path += i + '0';
//             if (dfs(x, y)) return true;
//             edge[a][b][x][y] = false;
//             path.pop_back();
//         }
//         visited[a][b] = false;
//         return false;
//     }

// public:
//     Solution(int& nn, int& kk) {
//         n = nn;
//         k = kk;
//         path = "";
//     }
//     void solve() {
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < n;j++) {
//                 cin >> board[i][j];
//             }
//         }
//         if (!dfs(0, 0))
//             cout << -1 << endl;
//         else
//             cout << path << endl;
//     }
// };

// int main() {
//     int n, k;
//     cin >> n >> k;
//     Solution sol(n, k);
//     sol.solve();
//     return 0;
// }
// const int N = 11; // 定义棋盘的最大大小为11×11
// int n, k; // n为棋盘大小，k为数字循环的范围
// int g[N][N]; // 存储棋盘上的数字
// int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 }; // 定义8个方向的x坐标偏移
// int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 }; // 定义8个方向的y坐标偏移
// string path; // 存储路径的方向编号
// bool st[N][N]; // 标记棋盘上的格子是否被访问过
// bool edge[N][N][N][N]; // 检查路径是否交叉

// // 深度优先搜索函数，用于寻找路径
// bool dfs(int a, int b) {
//     // 如果到达右下角格子，检查路径长度是否为n*n-1（因为起点不计入路径）
//     if (a == n - 1 && b == n - 1)
//         return path.size() == n * n - 1;

//     st[a][b] = true; // 标记当前格子已访问
//     for (int i = 0; i < 8; i++) { // 遍历8个方向
//         int x = a + dx[i], y = b + dy[i]; // 计算目标格子的坐标
//         // 检查目标格子是否越界、是否访问过、数字是否满足循环序列要求
//         if (x < 0 || x >= n || y < 0 || y >= n) continue;
//         if (st[x][y]) continue;
//         if (g[x][y] != (g[a][b] + 1) % k) continue;
//         // 检查路径是否交叉（对于斜向移动，检查是否有反向的路径）
//         if (i % 2 && (edge[a][y][x][b] || edge[x][b][a][y])) continue;

//         edge[a][b][x][y] = true; // 标记路径
//         path += i + '0'; // 将方向编号加入路径
//         if (dfs(x, y)) return true; // 递归搜索下一个格子
//         path.pop_back(); // 回溯，移除路径中的最后一个方向
//         edge[a][b][x][y] = false; // 回溯，取消路径标记
//     }
//     st[a][b] = false; // 回溯，取消当前格子的访问标记
//     return false; // 如果所有方向都无法到达终点，返回false
// }

// int main() {
//     cin >> n >> k; // 输入棋盘大小和数字循环范围
//     for (int i = 0; i < n; i++) // 读取棋盘上的数字
//         for (int j = 0; j < n; j++)
//             cin >> g[i][j];
//     // 从起点(0,0)开始搜索路径
//     if (!dfs(0, 0))
//         cout << -1 << endl; // 如果没有找到路径，输出-1
//     else
//         cout << path << endl; // 输出路径的方向编号序列

//     return 0;
// }
// 宝石组合
// inline int calcu(int& a, int& b, int& c) {
//     if (a < b) swap(a, b); // 确保 a >= b
//     if (a < c) swap(a, c); // 确保 a >= c
//     if (b < c) swap(b, c); // 确保 b >= c
//     return gcd(gcd(a, b), c);
// }
// int main() {
//     int n;
//     cin >> n;
//     vector<int> nums(n);
//     for (int i = 0;i < n;i++) {
//         cin >> nums[i];
//     }
//     string bestComb;
//     vector<int> cur, order;
//     int maxShine = 0;
//     for (int i = 0; i < nums.size(); i++) {
//         for (int j = i + 1; j < nums.size(); j++) {
//             for (int k = j + 1; k < nums.size(); k++) {
//                 int a = nums[i], b = nums[j], c = nums[k];
//                 cur = { a,b,c };
//                 int result = calcu(a, b, c);
//                 if (bestComb.empty()) bestComb = to_string(a) + to_string(b) + to_string(c);
//                 if (result > maxShine) {
//                     maxShine = result;
//                     order = cur;
//                 }
//                 else if (result == maxShine) {
//                     string str = to_string(a) + to_string(b) + to_string(c);
//                     if (str < bestComb) {
//                         bestComb = str;
//                         order = cur;
//                     }
//                 }
//                 cur.clear();
//             }
//         }
//     }
//     for (int i = 0;i < 3;i++) {
//         cout << order[i] << ' ';
//     }
//     return 0;
// }
// 完全背包问题
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     int n, v;
//     cin >> n >> v;
//     vector<int> weight(n + 1), value(n + 1);
//     vector<vector<int>> dp(n + 1, vector<int>(v + 1, 0));
//     for (int i = 1;i <= n;i++) {
//         cin >> weight[i] >> value[i];
//     }
//     for (int i = 1;i <= n;i++) {
//         for (int j = 0;j <= v;j++) {
//             for (int k = 0;k * weight[i] <= j;k++) {
//                 dp[i][j] =
//                     max(dp[i][j],
//                         dp[i - 1][j - weight[i] * k] + value[i] * k);
//             }
//         }
//     }
//     cout << dp[n][v];
//     return 0;
// }
// 01背包问题
// int main() {
//     int n, v;
//     cin >> n >> v;
//     vector<int> weight(n + 1), value(n + 1);
//     for (int i = 1;i <= n;i++) {
//         cin >> weight[i] >> value[i];
//     }
//     vector<vector<int>> dp(n + 1, vector<int>(v + 1, 0));
//     for (int i = 1;i <= n;i++) {
//         for (int j = 0;j <= v;j++) {
//             if (j >= weight[i]) {
//                 dp[i][j] = max(dp[i - 1][j], dp[i][j - weight[i]] + value[i]);
//             }
//             else {
//                 dp[i][j] = dp[i - 1][j];
//             }
//         }
//     }
//     cout << dp[n][v];
//     return 0;
// }

// 整数删除，题中出现了相邻元素操作，所以使用双向链表来实现更改元素，最小堆来返回现在需要操作的数字
//  三带一
//  set<int> records;
//  vector<int> weights;
//  void traceBack(int startIndex, int curWeight) {
//      if (startIndex == weights.size()) return;
//      records.insert(curWeight);
//      for (int i = startIndex; i < weights.size(); i++) {
//          traceBack(i + 1, curWeight + weights[i]);
//      }
//  }
//  int main() {
//      weights = { 1,2,3,4,5,6 };
//      traceBack(0, 0);
//      cout << records.size() - 1;
//      return 0;
//  }
//  报数游戏
//  2019签到题
//  bool isValid(int input) {
//      while (input > 0) {
//          int temp = input % 10;
//          input /= 10;
//          if (temp % 2 != 1) return false;
//      }
//      return true;
//  }
//  int main() {
//      for (int i = 2019;i < INT_MAX;i += 2019) {
//          if (isValid(i)) {
//              cout << i;
//              break;
//          }
//      }
//      return 0;
//  }
// 公因数匹配 超时
//  pair<int, int> get_input() {
//      unordered_map<int, pair<bool, int>> records;
//      int n, temp, min_i = INT_MAX, min_j = INT_MAX;
//      cin >> n;
//      for (int i = 0;i < n;i++) {
//          cin >> temp;
//          if (records[temp].first == true) {
//              min_i = min(records[temp].second, min_i);
//              min_j = min(temp, min_j);
//          }
//          else {
//              for (int j = 1; j * temp < 1000000; j++) {
//                  records[j * temp].first = true;
//                  if (records[j * temp].second != 0) continue;
//                  else records[j * temp].second = i + 1;
//              }
//          }
//      }
//      return { min_i, min_j };
//  }

// int main() {
//     pair<int, int> result = get_input();
//     cout << result.first << " " << result.second;
//     //	system("pause");
//     return 0;
// }
// 正则表达式
// int dfs(string expression, const int& len, int& pos) {
//     int temp = 0, ans = 0;
//     while (pos < len) {
//         char& c = expression[pos];
//         if (c == '(') {
//             pos++;
//             temp += dfs(expression, len, pos);
//         }
//         else if (c == ')') {
//             pos++;
//             break;
//         }
//         else if (c == '|') {
//             ans = max(temp, ans);
//             temp = 0;
//             pos++;
//         }
//         else if (c == 'x') {
//             temp++;
//             pos++;
//         }
//     }
//     ans = max(ans, temp);
//     return ans;
// }
// int main() {
//     string input;
//     int pos = 0;
//     cin >> input;
//     cout << dfs(input, input.size(), pos);
//     return 0;
// }
// chrono::system_clock::time_point stringToTime(const long long& miniSeconds, const string& format = "%h:%m:%s") {

// }
// int main() {
//     // stringToTime(46800999);
//     long long miniSeconds;
//     cin >> miniSeconds;
//     int aDay = (miniSeconds % 86400000) / 1000;
//     int hours = aDay / 3600;
//     int mins = (aDay - hours * 3600) / 60;
//     int second = aDay - hours * 3600 - mins * 60;
//     if (hours < 10) cout << "0" + to_string(hours) << ':';
//     else cout << hours << ':';
//     if (mins < 10) cout << "0" + to_string(mins) << ':';
//     else cout << mins << ':';
//     if (second < 10) cout << "0" + to_string(second);
//     else cout << second;
// }
// long long pre[100010], cur[100010];
// int main()
// {
//     pre[0] = 1;
//     cur[0] = 1;
//     long long n;
//     cin >> n;
//     if (n == 1) {
//         cout << 1;
//         return 0;
//     }
//     for (int i = 3;i <= 44723;i++) {
//         int m = i / 2;
//         for (int j = 1;j <= m;j++) {
//             if (j == m && i % 2 == 1) {//如果行数为奇数那么就有个中间数，就是上一行前面数的两倍
//                 cur[j] = pre[j - 1] * 2;
//             }
//             else {
//                 cur[j] = pre[j - 1] + pre[j];//根据定义构建
//             }
//             pre[j - 1] = cur[j - 1]; // 传递数组
//             if (cur[j] == n) {
//                 cout << i * (i - 1) / 2 + j + 1;
//                 return 0;
//             }
//         }
//         pre[m] = cur[m];
//         if (cur[1] > n) {//快速判断，我们想想，在没找到目的数之前，如果有一行的第二个数比目的数还要大，那么肯定就不会再次出现，直接快速判断输出结果为n行的第二个数。
//             cout << n * (n + 1) / 2 + 2;
//             return 0;
//         }
//     }
//     cout << n * (n + 1) / 2 + 2;//防止溢出
//     return 0;
// }

// 动态规划, 本质上是选和不选问题
// int records[200][200], dp[200][200], n;
// int main(){
//     cin >> n;
//     // 这里不需要初始化所有边缘变量为0,因为下标为0的变量没有用
//     for (int i = 1;i <= n;i++)
//         for (int j = 1;j <= i;j++)
//             cin >> records[i][j];
//     dp[1][1] = records[1][1];
//     for (int i = 2;i <= n;i++)
//         for (int j = 1;j <= i;j++)
//             dp[i][j] = records[i][j] + max(dp[i - 1][j], dp[i - 1][j - 1]);
//     cout << max(dp[n][(n + 1) / 2], dp[n][(n + 2) / 2]);
//     return 0;
// }
// dfs超时版本
// pair<int, int> findChildren(int i) {
//     int row = static_cast<int> (floor((sqrt(8 * i + 1) - 1)) / 2);
//     int left = row + 1 + i;
//     int right = row + 2 + i;
//     return { left, right };
// }
// void dfs(int level, int left_m, int right_m, const int layer, int sum, int index, int& result, vector<int>& records) {
//     if (left_m > layer / 2 + 1 || right_m > layer / 2 + 1) return;
//     if (abs(left_m - right_m) > 1 && level == layer) return;
//     if (abs(left_m - right_m <= 1 && level == layer)) {
//         result = max(result, sum);
//         return;
//     }
//     int left_index = findChildren(index).first;
//     int right_index = findChildren(index).second;
//     dfs(level + 1, left_m + 1, right_m, layer, sum + records[left_index], left_index, result, records);
//     dfs(level + 1, left_m, right_m + 1, layer, sum + records[right_index], right_index, result, records);
// }
// int main() {
//     int layer, temp, result = INT_MIN;
//     cin >> layer;
//     vector<int> records;
//     for (int i = 0;i < layer * (layer + 1) / 2;i++) {
//         cin >> temp;
//         records.push_back(temp);
//     }
//     dfs(1, 0, 0, layer, records[0], 0, result, records);
//     cout << result;
//     system("pause");
//     return 0;
// }
// int main() {
//     vector<int> records = { 7,3,8,8,1,0,2,7,4,4,4,5,2,6,5 };
//     int result = INT_MIN;
//     dfs(1, 0, 0, 5, records[0], 0, result, records);
//     cout << result;
// }
// string convertBase(int input, int fromBase, int toBase) {
//     if (input == 0) return "";
//     string result;
//     const char* alpha = "0123456789abcdefghijklmnopqrstuvwxyz";
//     // convert input to 10 base
//     int num = 0/* 10Base number */, power = 1;
//     while (input > 0) {
//         num += (input % 10) * power;
//         power *= fromBase;
//         input /= 10; // 因为输入的数字是十进制的int，/=10表示去掉最后一位
//     }
//     // convert 10 base to toBase
//     while (num > 0) {
//         result.push_back(alpha[num % toBase]);
//         num /= 10;
//     }
//     ranges::reverse(result);
//     return result;
// }
// int main() {
//     cout << convertBase(2022, 9, 10);
// }
// string transform(int input, int fromBase, int toBase) {
//     if (input == 0) return "0"; // 特殊情况处理
//     string result;
//     const char* digits = "0123456789abcdefghijklmnopqrstuvwxyz";
//     // 将 input 从 fromBase 进制转换为 10 进制
//     int num = 0, power = 1;
//     while (input > 0) {
//         num += (input % 10) * power;
//         power *= fromBase;
//         input /= 10;
//     }
//     // 将 num 从 10 进制转换为 toBase 进制
//     while (num > 0) {
//         result.push_back(digits[num % toBase]);
//         num /= toBase;
//     }
//     reverse(result.begin(), result.end()); // 反转字符串
//     return result;
// }
// int main() {
//     cout << transform(2022, 9, 10);
// }
// 成绩分析
// int main() {
//     int n, num = 0, sum = 0, minone = INT_MAX, maxone = INT_MIN;
//     cin >> n;
//     for (int i = 0; i < n; i++) {
//         cin >> num;
//         sum += num;
//         if (num < minone) minone = num;
//         if (num > maxone) maxone = num;
//     }
//     float avg = sum * 1.0 / n * 1.0;
//     cout << maxone << endl;
//     cout << minone << endl;
//     cout << fixed << setprecision(2) << avg;
// }
// 卡片
// bool change(int input, unordered_map<int,int>& records) {
//     string s = to_string(input);
//     for (auto& x : s) {
//         int n = x - 48;
//         if (records[n] == 0) return false;
//         else records[n]--;
//     }
//     return true;
// }
// int main() {
//     unordered_map<int, int> records;
//     for (int i = 0; i <= 9; i++) {
//         records[i] = 2021;
//     }
//     int i = 0;
//     while (++i) {
//         if(!change(i, records)) break;
//     }
//     cout << i - 1;
//     return 0;
// }
// 数字三角形
// int main() {
//     int layer = 0 ,temp = 0, sum = 0;
//     cin >> layer;
//     vector<int> level;
//     for (int i = 1;i <= layer;i++) {
//         for (int j = 0;j < i;j++) {
//             cin >> temp;
//             level.push_back(temp);
//         }
//         // for (int i = 0;i < level.size();i++) {
//         if (i % 2 == 1) sum += level[i / 2];
//         else sum += max(level[i / 2], level[i / 2 - 1]);
//         // }
//         level.clear();
//     }
//     cout << sum;
//     return 0;
// }
// 门牌制作
// int count(int num) {
//     int c = 0;
//     string s = to_string(num);
//     for (auto& x : s ) {
//         if (x == '2') c++;
//     }
//     return c;
// }
// int main() {
//     int result = 0;
//     for (int i = 1; i <= 2020; i++) {
//         result += count(i);
//     }
//     cout << result;
//     return 0;
// }
// 成绩统计
// int main() {
//     int num, score, excellent = 0, pass = 0, under = 0;
//     cin >> num;
//     for (int i = 0;i < num;i++) {
//         cin >> score;
//         if (score >= 85) excellent++;
//         else if (score >= 60) pass++;
//     }
//     int e_rate = round(100.0 * (float)excellent / (float)num);
//     int p_rate = 100 - round(100.0 * (float)(pass+excellent) / (float)num);
//     cout << p_rate << '%' << endl;
//     cout << e_rate << '%' ;
//     return 0;
// }
// 单词分析
// int main() {
//     vector<int> records(26);
//     char ch;
//     while ((ch = getchar()) != '\n') {
//         records[int(ch - 97)]++;
//     }
//     auto it = max_element(records.begin(), records.end());
//     cout << char(distance(records.begin(), it) + 97) << endl;
//     cout << *it;
// }
// using pci = pair<char, int>;
// struct Comp {
//     bool operator()(pci& a, pci& b) {
//         if (a.second > b.second)
//             return true;
//         else if (a.second == b.second && a.first < b.first)
//             return true;
//         else return false;
//     }
// };
// int main() {
//     string input;
//     cin >> input;
//     map<char, int> records;
//     for (int i = 0;i < input.size(); i++) {
//         records[input[i]]++;
//     }
//     vector<pci> result(records.begin(), records.end());
//     sort(result.begin(), result.end(), Comp());
//     cout << result[0].first << endl;
//     cout << result[0].second;
// }
// 小明的背包1
// 0-1背包标准模板
// int main() {
//     int n, v;
//     cin >> n >> v;
//     vector<int> weight(n + 1);
//     vector<int> value(n + 1);
//     for (int i = 1; i <= n; i++) {
//         cin >> weight[i] >> value[i];
//     }
//     vector<vector<int>> dp(n + 1, vector<int>(v + 1, 0));

//     for (int i = 1; i <= n; i++) {
//         for (int j = 0; j <= v; j++) {
//             if (j - weight[i] >= 0)
//                 dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
//             else dp[i][j] = dp[i - 1][j];
//         }
//     }
//     cout << dp[n][v];
//     return 0;
// }
// int main() {
//     int n, v;
//     cin >> n >> v;
//     vector<int> weight(n + 1);
//     vector<int> value(n + 1);
//     for (int i = 0; i < n; i++) {
//         cin >> weight[i] >> value[i];
//     }
//     // i 物品范围，j重量剩余dp[i][j]价值
//     vector<vector<int>> dp(n + 1, vector<int>(v + 1, 0));
//     /*
//     初始化省略了下面内容
//     for (int i = 1; i < weight.size(); i++) {  // 当然这一步，如果把dp数组预先初始化为0了，这一步就可以省略，但很多同学应该没有想清楚这一点。
//         dp[i][0] = 0; // 无论选择物品范围是多少，如果背包重量限制为0则总价值为0
//     }
//     */
//     // 正序遍历
//     for (int j = 0;j <= n;j++) {
//         dp[0][j] = value[0];
//     }
//     for (int i = 1; i <= n; i++) {
//         for (int j = 0; j <= v; j++) {
//             dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
//         }
//     }
//     return dp[n][v];
// }
// 统计子矩阵
// 2025-03-06 14:11:22
// vector<vector<int>> get_grid() {
//     int n, m, k, prev = 0;
//     cin >> n >> m >> k;
//     vector grid(n, vector<int>(m + 1, 0));
//     vector<int> data(n * m);
//     for (int i = 0;i < m * n;i++) {
//         cin >> data[i];
//     }
//     partial_sum(data.begin(), data.end(), data.begin());
//     for (int i = 0;i < n;i++) {
//         for (int j = 0;j < m;j++) {
//             grid[i][j] = data[i * m + j];
//         }
//     }
//     return grid;
// }
// int main() {
//     for (auto x: get_grid() ) {
//         for (auto y: x ) {
//             cout << y << " ";
//         }
//         cout << endl;
//     }
// }
// 顺子日期
// 2025-03-06 08:49:48
// 九进制转十进制

// 杨辉三角
// class Solution {
// public:
//     int combination(int n, int k) { // C(n底数, k指数)
//         if (k > n)
//             return 0; // 这一段一定要有，防止组合数不存在仍然得到1的结果
//         if (k > n - k) k = n - k;
//         int res = 1;
//         for (int i = 1; i <= k; ++i) {
//             res = res * (n - i + 1) / i;
//         }
//         return res;
//     }
//     vector<int> getRow(int rowIndex) {
//         vector<int> result;
//         for (int i = 0;i < rowIndex + 1;i++) {
//             result.push_back(combination(rowIndex, i));
//         }
//         return result;
//     }
// };
// X 进制减法
// 60min 进制计算很不熟练
// const int N = 1e5 + 5;
// const long long MOD = 1000000007;

// int numsA[N], numsB[N];

// int main() {

//     int maxN, m, n;
//     cin >> maxN >> m;
//     for (int i = m - 1; i >= 0; i--) cin >> numsA[i];
//     cin >> n;
//     for (int j = n - 1; j >= 0; j--) cin >> numsB[j];

//     long long ret = 0, base = 1;
//     int weight;
//     for (int i = 0; i < max(m, n); i++) {
//         weight = max(max(numsA[i], numsB[i]) + 1, 2);
//         ret = (ret + (numsA[i] - numsB[i]) * base) % MOD;
//         base = (base * weight) % MOD;
//     }
//     cout << ret % MOD;
//     return 0;
// }
// 修剪灌木
// 18mins
// int main() {
//     int n = 0;
//     cin >> n;
//     vector<int> shrub(n);
//     for (int i = 0;i < n;i++) {
//         shrub[i] = i + 1;
//     }
//     for (int i = 0;i < n;i++) {
//         int left = 2 * i;
//         int right = 2 * (n - i - 1);
//         shrub[i] = max(shrub[i], max(left, right));
//     }
//     for (int i = 0; i < n; i++) {
//         cout << shrub[i] << endl;
//     }
//     return 0;
// }
// 刷题统计
// int main() {
//     long long a, b, n;
//     cin >> a >> b >> n;
//     long long days = 0;
//     int runner = 0;
//     vector<long long> daily{ a,a,a,a,a,b,b };
//     long long aWeek = 5 * a + 2 * b;
//     long long rounds = n / aWeek;
//     n -= rounds * aWeek;
//     while (n > 0) {
//         n -= daily[runner % 7];
//         days++;
//         runner++;
//     }
//     cout << days + 7* rounds;
// }
// 日期统计
// int main() {
//     vector<int> daysInMonth = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//     vector<int> array = { 5, 6, 8, 6, 9, 1, 6, 1, 2, 4, 9, 1, 9, 8, 2, 3, 6, 4, 7, 7, 5, 9, 5, 0, 3, 8, 7, 5, 8, 1, 5, 8, 6, 1, 8, 3, 0, 3, 7, 9, 2, 7, 0, 5, 8, 8, 5, 7, 0, 9, 9, 1, 9, 4, 4, 6, 8, 6, 3, 3, 8, 5, 1, 6, 3, 4, 6, 7, 0, 7, 8, 2, 7, 6, 8, 9, 5, 6, 5, 6, 1, 4, 0, 1, 0, 0, 9, 4, 8, 0, 9, 1, 2, 8, 5, 0, 2, 5, 3, 3 };
//     int count = 0;
//     for(int month = 1;month<=12;month++){
//         for (int day = 1;day <= daysInMonth[month];day++) {
//             vector<int> data = { 2,0,2,3,month / 10,month % 10,day / 10,day % 10 };
//             int dp = 0;
//             for (int i = 0;i < 100;i++) {
//                 if (data[dp] == array[i]) {
//                     dp++;
//                     if (dp == 8) {
//                         count++;
//                         break;
//                     }
//                 }
//             }
//         }

//     }
//     cout << count;
// }
// 01串的熵
// 纯傻逼题，一定要按照他要求的写法写，否则怎么写精度都不够
// const double n = 23333333;
// const double m = 11625907.5798;
// double get_number(int x) {
//     return (x * x * -1 * log2(x / n)) / n;
// }
// int main() {
//     for (int i = 0;i < n / 2; i++) {
//         double sum = 0;
//         sum += get_number(i) + get_number(n - i);
//         if (sum > 11625907.5 && sum < 11625907.6) {}
//         // if ( - m <= 0.0001) {
//         cout << i << endl;
//         break;
//     }
//     return 0;
// }
// 这段能过
// int main() {
//     double n = 23333333, sum = 0;
//     int o = 0, l = 0;
//     for (o = 0;o <= n / 2;o++) {
//         sum = 0;
//         sum -= o * (o / n) * log2(o / n) + (n - o) * ((n - o) / n) * log2((n - o) / n);
//         if (sum > 11625907.5 && sum < 11625907.6) {
//             printf("%d", o);
//             break;
//         }
//     }
//     return 0;
// }
// 日期统计
// 2025年3月5日08:03 : 53
// bool is_legal(string data) {
//     int year = stoi(data.substr(0, 4));
//     int month = stoi(data.substr(5, 2));
//     int day = stoi(data.substr(7, 2));
//     tm tm{ 0,0,0, day, month - 1,year - 1900 };
//     time_t timestamp = mktime(&tm);
//     if (timestamp == -1) { // 无法转换，即负数，超过合法的日期范围日期
//         return false;
//     }
//     // 如果调整后的日期与输入日期不一致，说明原始日期非法
//     if (tm.tm_mday != day || tm.tm_mon + 1 != month || tm.tm_year + 1900 != year) {
//         return false;
//     }
//     return true;
// }
// unordered_set<string> get_datas(string& s) {
//     int n = s.size();
//     string data;
//     unordered_set<string> datas;
//     for (int i = 0;i < n;i++) {
//         if (s[i] != '0' || s[i] != '1' || s[i] != '2') continue;
//         for (int j = 0;j < n;j++) {
//             for (int k = 0;k < n;k++) {
//                 if (s[k] != '0' || s[k] != '1' || s[k] != '2' || s[k] != '3') continue;
//                 for (int l = 0;l < n;l++) {
//                     data.append(to_string(s[i]))
//                         .append(to_string(s[j]))
//                         .append(to_string(s[k]))
//                         .append(to_string(s[l]));
//                     datas.insert(data);
//                 }
//             }
//         }
//     }
//     return datas;
// }
// int main() {
//     string nums = "38516346707827689565614010094809128502533";
//     unordered_set<string> datas = get_datas(nums);
//     for (auto x : datas) {
//         if (!is_legal(x)) {
//             datas.erase(x);
//         }
//     }
//     for (auto x : datas) {
//         cout << x << '\n';
//     }
//     return 0;
// }
// 通过率45%
// typedef pair<double, double> pdd;

// // 判断三个点是否共线（使用对数坐标）
// bool is_in_line(pdd a, pdd b, pdd c) {
//     // 使用向量叉积公式判断是否共线
//     double area = (b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first);
//     return fabs(area) < 1e-9; // 浮点数比较，使用一个极小值作为阈值
// }

// // 判断三个点是否构成等腰三角形（使用对数坐标）
// bool is_isosceles(pdd a, pdd b, pdd c) {
//     // 计算三条边的平方距离（对数坐标系中的距离公式）
//     double dis1 = pow(a.first - b.first, 2) + pow(a.second - b.second, 2);
//     double dis2 = pow(c.first - b.first, 2) + pow(c.second - b.second, 2);
//     double dis3 = pow(a.first - c.first, 2) + pow(a.second - c.second, 2);
//     bool situ1 = dis1 == dis2 && dis1 != dis3;
//     bool situ2 = dis2 == dis3 && dis1 != dis3;
//     bool situ3 = dis1 == dis3 && dis2 != dis3;
//     return situ1 || situ2 || situ3;
// }

// int get_tangles(vector<pdd>& p) {
//     int n = p.size(), count = 0;
//     for (int i = 0; i < n; i++) {
//         for (int j = i + 1; j < n; j++) {
//             for (int k = j + 1; k < n; k++) {
//                 if (!is_in_line(p[i], p[j], p[k]) && is_isosceles(p[i], p[j], p[k])) {
//                     count++;
//                 }
//             }
//         }
//     }
//     return count;
// }

// int main() {
//     int points = 0, x, y;
//     cin >> points;
//     vector<pdd> positions;
//     while (points--) {
//         cin >> x >> y;
//         positions.push_back({ log(x), log(y) });
//     }
//     cout << get_tangles(positions);
//     return 0;
// }
// 班级活动 重写
// int change_time(vector<int> nums) {
//     int one = 0, two = 0, count =0;
//     unordered_map<int, int> mapping;
//     for (int i = 0;i < nums.size(); i++) {
//         mapping[nums[i]]++;
//     }
//     for (auto it = mapping.begin(); it != mapping.end(); it++) {
//         if (it->second >= 2) two+=(it->second-2);
//         else one++;
//     }
//     if (one > two) count = (one - two) / 2 + two;
//     else count = two;
//     return count;
// }
// int main() {
//     int sum, temp;
//     cin >> sum;
//     vector<int> nums(sum);
//     for (int i = 0;i < sum;i++) {
//         cin >> temp;
//         nums[i] = temp;
//     }
//     cout << change_time(nums);
//     return 0;
// }
// 双子数——模拟题
// 反向思路 求出开根的结果
// int main() {
//     const int N = 1e9 + 7;
//     using ll = long long;
//     ll upper = 23333333333333LL;
//     ll lower = 2333;
//     int count = 0;
//     int pri[N + 1 >> 1], now;
//     bool vis[N + 1];
//     for (int i = 2;i <= N;i++) {
//         if (!vis[i]) pri[++now] = i;
//         for (int j = 1;j <= now && pri[j] * i <= N;j++) {
//             vis[pri[j] * i] = 1;
//             if (i % pri[j] == 0)break;
//         }
//     }
//     for (int i = 0;i < now;i++) {
//         ll pp = pri[i] * pri[i];
//         if (pp * pp > upper) break;
//         for (int j = i + 1;j < now;j++) {
//             ll qq = pri[j] * pri[j];
//             if (pp * qq > upper) break;;
//             if (qq * qq < lower) continue;
//             count++;
//         }
//     }
//     cout << count;
//     return 0;
// }
// 这样正向思路，求出范围内所有素数然后枚举素数需要大量空间，需要upper + 1的容量，会超出限制，理论可以，但实际是错误的
// vector<long long> eulerSieve(long long n) {
//     vector<long long> primes;
//     vector<long long> isPrime(n + 1, 1);

//     for (long long i = 2; i <= n; ++i) {
//         if (isPrime[i]) {
//             primes.push_back(i);
//         }
//         for (long long j = 0; j < primes.size() && primes[j] * i <= n; ++j) {
//             isPrime[primes[j] * i] = 0;
//             if (i % primes[j] == 0) {
//                 break;
//             }
//         }
//     }

//     return primes;
// }
// int main() {
//     long long lower = 2333;
//     long long upper = 23333333333333;
//     int count = 0;
//     vector<long long> primes = eulerSieve(upper);
//     int n = primes.size();
//     for (int i = 0;i < n;i++) {
//         for (int j = i + 1;j < n;j++) {
//             long long temp = i * i * j * j;
//             if (temp <= upper && temp >= lower) {
//                 count++;
//             }
//         }
//     }
//     cout << count;
//     return 0;
// }
// 数三角
// int main() {
//     int length = 0;
//     double x = 0, y = 0;
//     cin >> length;
//     vector<pair<double, double>> positions(length);
//     for (int i = 0; i < length; i++) {
//         cin >> x >> y;
//         x += 1e9;// 防止log底数 <0
//         y += 1e9;
//         positions[i] = make_pair(log(x), log(y));
//     }
//     unordered_map<double, int> mapping;
//     int count = 0;
//     for (int i = 0; i < length; i++) {
//         for (int j = i + 1; j < length; j++) {
//             double dx = pow(positions[i].first - positions[j].first, 2);
//             double dy = pow(positions[i].second - positions[j].second, 2);
//             count += mapping[dx + dy]++;
//         }
//         mapping.clear();
//     }
//     cout << count;
//     return 0;
// }

// 数三角
// 46mins
// int main() {
//     int length = 0;
//     double x = 0, y = 0;
//     cin >> length;
//     vector<pair<double, int>> positions(length);
//     for (int i = 0; i < length; i++) {
//         cin >> x >> y;
//         positions[i] = make_pair(log(x),log(y));
//     }
//     unordered_map<double, int> mapping;
//     int count = 0;
//     for (int i = 0; i < positions.size(); i++) {
//         for (int j = i + 1; j < positions.size(); j++) {
//             double dx = pow(positions[i].first - positions[j].first, 2);
//             double dy = pow(positions[i].second - positions[j].second, 2);
//             count += mapping[dx + dy]++;
//         }
//         mapping.clear();
//     }
//     cout << count;
//     return 0;
// }
// 班级活动 正确率60%
// int change_time(vector<int> input) {
//     int only_one = 0;
//     int bigger_two = 0;
//     unordered_map<int, int> mapping;
//     for (int i = 0;i < input.size();i++) {
//         if (mapping[input[i]] < 2) {
//             mapping[input[i]]++;
//         }
//         else {
//             bigger_two++;
//         }
//     }
//     for (auto x : mapping) {
//         if (x.second == 1) {
//             only_one++;
//         }
//     }
//     int count = 0, temp = abs(only_one - bigger_two);
//     if (only_one > bigger_two) {
//         if (temp % 2 == 1) count++;
//         count += (bigger_two + temp/2);
//     }
//     else if (only_one < bigger_two) {
//         if (temp % 2 == 1) count++;
//         count += (only_one + temp/2);
//     }
//     else {
//         count = only_one;
//     }
//     return count;
// }
// int main() {
//     int sum, temp;
//     cin >> sum;
//     vector<int> nums(sum);
//     for (int i = 0;i < sum;i++) {
//         cin >> temp;
//         nums[i] = temp;
//     }
//     cout << change_time(nums);
//     return 0;
// }
// 双子数
// 暴力结果1089022079
// vector<__int64> sieve_of_eratosthenes(__int64 n) {
//     // 创建一个布尔向量，初始化所有元素为 true
//     vector<bool> is_prime(n + 1, true);
//     is_prime[0] = is_prime[1] = false; // 0 和 1 不是素数
//     // 只需要检查到 sqrt(n)
//     __int64 sqrt_n = sqrt(n);
//     for (__int64 i = 2; i <= sqrt_n; ++i) {
//         if (is_prime[i]) {
//             // 将 i 的倍数标记为 false
//             for (__int64 j = i * i; j <= n; j += i) {
//                 is_prime[j] = false;
//             }
//         }
//     }
//     // 将所有素数存储到 vector<__int64> 中
//     vector<__int64> primes;
//     for (__int64 i = 2; i <= n; ++i) {
//         if (is_prime[i]) {
//             primes.push_back(i);
//             /* 将这里改成 count ++;可以直接计算结果 */
//         }
//     }
//     return primes;
// }

// int main() {
//     vector<__int64> numbers = sieve_of_eratosthenes(23333333333333);
//     int n = numbers.size(), count = 0;
//     for (int i = 0;i < n;i++) {
//         for (int j = i + 1;j < n;j++) {
//             if (numbers[i] * numbers[j] > 2333 && numbers[i] * numbers[j] < 23333333333333LL) {
//                 count++;
//             }
//         }
//     }
//     cout << count;
//     system("pause");
// }
// 子2023 12mins
// int main() {
//     string s, output;;
//     for (int i = 1;i <= 2023;i++) {
//         s += to_string(i);
//     }

//     // cout << output;
//     // s = "2023";
//     long long count = 0;
//     unordered_map<int,int> mapping;
//     for (int i = 0;i < s.length();i++) {
//         if (s[i] == '3') {
//             count += mapping[2] * (mapping[2] - 1) * mapping[0] / 2;
//         }
//         else if (s[i] == '2') {
//             mapping[2]++;
//         }
//         else if (s[i] == '0') {
//             mapping[0]++;
//         }
//     }
//     cout << count;
// }
// vector<long long> sieve_of_eratosthenes(int n) {
//     // 创建一个布尔向量，初始化所有元素为 true
//     vector<bool> is_prime(n + 1, true);
//     is_prime[0] = is_prime[1] = false; // 0 和 1 不是素数

//     // 只需要检查到 sqrt(n)
//     long long sqrt_n = sqrt(n);
//     for (long long i = 2; i <= sqrt_n; ++i) {
//         if (is_prime[i]) {
//             // 将 i 的倍数标记为 false
//             for (long long j = i * i; j <= n; j += i) {
//                 is_prime[j] = false;
//             }
//         }
//     }

//     // 将所有素数存储到 vector<long long> 中
//     vector<long long> primes;
//     for (long long i = 2; i <= n; ++i) {
//         if (is_prime[i]) {
//             primes.push_back(i);
//             /*
//                 将这里改成 count ++;可以直接计算结果
//             */
//         }
//     }

//     return primes;
// }

// int main() {
//     vector<long long> numbers = sieve_of_eratosthenes(4830458);
//     int n = numbers.size(), count = 0;
//     for (int i = 0;i<n;i++){
//         for (int j = i + 1;j < n;j++) {
//             if (numbers[i] * numbers[j] > 2333 && numbers[i] * numbers[j] < 23333333333333LL) {
//                 count++;
//             }
//         }
//     }
//     cout << count;
// }
// 工作时间
// string formatTime(const tm& tm) {
//     char buffer[80];
//     strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &tm);
//     return string(buffer);
// }
// inline double get_diff(tm& time1, tm& time2) {
//     time_t t1 = mktime(&time1);
//     time_t t2 = mktime(&time2);
//     return difftime(t2, t1);
// }
// tm traverse_to_tm(const string& s) {
//     tm tm = {};
//     stringstream ss(s);
//     ss >> get_time(&tm, "%Y-%m-%d %H:%M:%S");
//     return tm;;
// }

// bool compare(tm& t1, tm& t2) {
//     return mktime(&t1) < mktime(&t2);
// }

// vector<tm> format_times() {
//     string input;
//     vector<tm> times;
//     while (getline(cin, input)) {
//         times.push_back(traverse_to_tm(input));
//     }
//     sort(times.begin(), times.end(), compare);
//     return times;
// }
// int main() {
//     vector<tm> ordered_times = format_times();
//     double whole_time = 0.0;
//     for (int i = 0;i < ordered_times.size();i += 2) {
//         auto temp1 = ordered_times[i];
//         auto temp2 = ordered_times[i + 1];
//         whole_time += get_diff(temp1, temp2);
//     }
//     cout << whole_time;
// }
// Playfair密码
// 垃圾题目
// 四平方和
// 2025-02-22 15:57:18
// int main() {
//     int input;
//     cin >> input;
//     set<string> results;
//     int start = static_cast<int>(sqrt(input)) + 1;
//     for (int i = 0;i < start;i++) {
//         for (int j = i;j < start;j++) {
//             for (int k = j;k < start;k++) {
//                 for (int l = k;l < start;l++) {
//                     if (i * i + j * j + k * k + l * l == input) {
//                         cout << i << " " << j << " " << k << " " << l;
//                         return 0;
//                     }
//                 }
//             }
//         }
//     }
// }
// 日期问题
// 2025-02-22 14:03:59
// bool isValidDate(string y, string m, string d) {
//     int year = stoi(y);
//     int month = stoi(m);
//     int day = stoi(d);
//     tm tm = { 0,0,0,day,month - 1,year - 1900 };
//     time_t timestamp = mktime(&tm);
//     if (timestamp == -1) {
//         return false;
//     }
//     // 如果调整后的日期与输入日期不一致，说明原始日期非法
//     if (tm.tm_mday != day || tm.tm_mon + 1 != month || tm.tm_year + 1900 != year) {
//         return false;
//     }
//     return true;
// }
// int main() {
//     string input, a, b, c;
//     const string start = "1960-01-01", end ="2059-12-31";
//     cin >> input;
//     // input = "02/03/04";
//     a = input.substr(0, 2);
//     b = input.substr(3, 2);
//     c = input.substr(6, 2);
//     set<string> dates;
//     input = ("19" + a + "-" + b + "-" + c);
//     if (start < input && input < end && isValidDate("19" + a,b,c)) {
//         dates.insert(input);
//     }
//     input = ("19" + c + "-" + b + "-" + a);
//     if (start < input && input < end && isValidDate("19" + c,b,c)) {
//         dates.insert(input);
//     }
//     input = ("19" + c + "-" + a + "-" + b);
//     if (start < input && input < end && isValidDate("19" + c,a,b)) {
//         dates.insert(input);
//     }
//     input = ("20" + a + "-" + b + "-" + c);
//     if (start < input && input < end && isValidDate("20" + a,b,c)) {
//         dates.insert(input);
//     }
//     input = ("20" + c + "-" + b + "-" + a);
//     if (start < input && input < end && isValidDate("20" + c,b,a)) {
//         dates.insert(input);
//     }
//     input = ("20" + c + "-" + a + "-" + b);
//     if (start < input && input < end && isValidDate("20" + c,a,b)) {
//         dates.insert(input);
//     }
//     int length = dates.size();
//     for(string x : dates){
//         cout << x << "\n";
//     }
// }
// mlgb傻逼题
// static char cur = 'A';
// void toggle() {
//     cur = (cur == 'A') ? 'B' : 'A';
// }
// void get_card_out(queue<char>& side, vector<char>& cards, string& win, char side_out, char cur) {
//     side.pop();
//     auto it1 = find(cards.begin(), cards.end(), side_out);
//     if (it1 != cards.end()) {
//         side.push(side_out);
//         auto position = it1;
//         for (it1;it1 != cards.end();it1++) {
//             win.push_back(*it1);
//         }
//         cards.erase(position, cards.end());
//         for (int i = win.length() - 1;i >= 0;i--) {
//             side.push(win[i]);
//         }
//         win.clear();
//     }
//     else {
//         cards.push_back(side_out);
//         toggle();
//     }
// }
// int main() {
//     queue<char> A, B;
//     string str1, str2;
//     str1 = "K8XKA2A95A";
//     str2 = "27K5J5Q6K4";
//     // cin >> str1;
//     // cin >> str2;
//     vector<char> cards;
//     for (int i = 0;i < str1.size();i++) {
//         A.push(str1[i]);
//     }
//     for (int i = 0;i < str2.size();i++) {
//         B.push(str2[i]);
//     }
//     while (A.size() != 0 || B.size() != 0) {
//         string win;
//         char A_out = A.front(), B_out = B.front();
//         if (cur == 'A') {
//             get_card_out(A, cards, win, A_out, cur);
//         }
//         else {
//             get_card_out(B, cards, win, B_out, cur);
//         }
//     }
//     for(int i = 0;i<A.size();i++){
//         cout << A.front();
//         A.pop();
//     }
//     for(int i = 0;i<B.size();i++){
//         cout << B.front();
//         B.pop();
//     }
//     return 0;
// }
// 九宫幻方
// Excel地址
// 2025-02-21 18:45:39
// 15mins n 1 **空隙比进制更重要**
// int main() {
//     int input;
//     string result;
//     cin >> input;
//     while (input > 0) {
//         result += input % 26 + 'A';
//         input /= 26;
//     }
//     reverse(result.begin(), result.end());
//     cout << result;
// }
// k倍区间  10mins 没明白错在哪里，代码逻辑是一样的
// int main() {
//     unordered_map<int, int> mapping = {{0,1}};
//     int n, k, pre_sum = 0;
//     long long count = 0;
//     cin >> n >> k;
//     vector<int> nums(n);
//     for (int i = 0;i < n;i++) {
//         cin >> nums[i];
//         pre_sum += nums[i];
//         auto it = mapping.find(pre_sum % k);
//         if (it != mapping.end()) {
//             count += it->second;
//         }
//         mapping[pre_sum % k]++;
//     }
//     cout << count;
// }

// 2的幂次方
// 50mins 70%通过
// void recursion(int n, string& result) {
//     bitset<128> bits(n);
//     int length = bits.size();
//     for (int i = length -1; i >= 0;i--) {
//         if (bits[i] == 1) {
//             if (i == 2) {
//                 result += "2(2)+";
//             }
//             if (i == 1) {
//                 result += "2+";
//             }
//             if (i == 0) {
//                 result += "2(0)+";
//             }
//             if (i > 2) {
//                 result += "2(";
//                 recursion(i, result);
//                 result += ")+";
//             }
//         }
//     }
//     result.pop_back();
// }
// int main() {
//     string result;
//     long long input;
//     cin >> input;
//     recursion(input, result);
//     cout << result;
// }
// 2(2(2) + 2 + 2(0)) + 2(2 + 2(0)) + 2(0)
// 2(2(2) + 2 + 2(0)) + 2(2 + 2(0)) + 2(0)
// int main() {
//     int power = 0;
//     double f = 0;
//     cin >> power >> f;
//     int result = round((double)pow(2, power) * f);
//     cout << result;
//     return 0;
// }
// 好数
// 2025-02-21 10:05:24  9mins n 1
// bool is_right(int input) {
//     int temp = 0, count = 1;
//     while (input > 0) {
//         temp = input % 10;
//         if (count % 2 != temp % 2) {
//             return false;
//         }
//         input /= 10;
//         count++;
//     }
//     return true;
// }

// int main() {
//     int range = 0, count = 0;
//     cin >> range;
//     for (int i = 1;i <= range;i++) {
//         is_right(i) ? count++ : 1;
//     }
//     cout << count;
// }
// 握手问题
// 2025-02-21 00:02:09   6mins
// int combination(int n, int k) {
//     if (k > n) return 0;
//     if (k > n - k) k = n - k;
//     int result = 1;
//     for (int i = 1;i <= k;i++) {
//         result = result * (n - i + 1) / i;
//     }
//     return result;
// }
// int main() {
//     cout << combination(50, 2) - combination(7, 2);
// }
// 完全二叉树的权值
// 简化做法：
// int main() {
//     int N;
//     cin >> N;
//     vector<int> weights(N);
//     for (int i = 0; i < N; ++i) {
//         cin >> weights[i];
//     }
//     int depth = 1; // 当前深度
//     int start = 0; // 当前层的起始索引
//     int maxSum = weights[0]; // 最大权值和
//     int resultDepth = 1; // 结果深度

//     while (start < N) {
//         int end = start + (1 << (depth - 1)); // 当前层结束索引
//         if (end > N) {
//             end = N; // 最后一层可能不完整
//         }
//         int sum = accumulate(weights.begin() + start, weights.begin() + end, 0);
//         if (sum > maxSum) {
//             maxSum = sum;
//             resultDepth = depth;
//         }
//         start = end; // 更新起始索引
//         ++depth; // 更新深度
//     }
//     cout << resultDepth << endl;
//     return 0;
// }
// 2025-02-21 00:00:18  30mins
// int main() {
//     int length = 0, level = 0, maxone = INT_MIN, targetFloor = 1;
//     cin >> length;
//     level = floor(log2(length))+1;
//     vector<int> ans(length);
//     for (int i = 0;i < length;i++) {
//         cin >> ans[i];
//     }
//     for (int i = 0, step = 1;i < level;i++,step*=2) {
//         int start = pow(2, i) - 1, end = start + step;
//         int level_max = accumulate(ans.begin() + start, ans.begin() + end, 0);
//         level_max > maxone ? maxone = level_max,targetFloor = i + 1 : 1;
//     }
//     cout << targetFloor;
//     return 0;
// }
// 1217解立方根
// 2025-02-15 17:47:49

// 1371.回文判定
// 2025-02-15 17:38:49 4mins
// 头尾判断法
// int main() {
//     string input;
//     getline(cin, input);
//     int length = input.length();
//     auto it = input.begin();
//     auto rit = input.rbegin();
//     for (int i = 0;i < length / 2;i++) {
//         if (*it != *rit) {
//             cout << "N";
//             return 0;
//         }
//     }
//     cout << "Y";
//     return 0;
// }
// 翻转比较法
// int main() {
//     string input, reverse_input;
//     getline(cin, input);
//     reverse_input = string(input.rbegin(), input.rend());
//     if (reverse_input == input) {
//         cout << "Y";
//     }
//     else {
//         cout << "N";
//     }
//     return 0;
// }
// 1265.排序
// int main() {
//     int n, temp;
//     cin >> n;
//     vector<int> arr;
//     for (int i = 0;i < n;i++) {
//         cin >> temp;
//         arr.emplace_back(temp);
//     }
//     sort(arr.begin(),arr.end());
//     copy(arr.begin(), arr.end(), ostream_iterator<int>(cout, " "));
//     cout << endl;
//     copy(arr.rbegin(), arr.rend(), ostream_iterator<int>(cout, " "));
//     return 0;
// }
// 长草
// 2025-02-14 16:44:11

// 音节判断
// 2025-02-14 15:52:00
// 16mins n 1一会yesno大写一会小写我超少女动漫
// typedef unordered_set<char> uc;
// inline bool is_vowel(char c, uc& map) {
//     return map.find(c) == map.end() ? false : true;
// }
// int main() {
//     uc mapping = { 'a','e','i','o','u' };
//     string input;
//     cin >> input;
//     int n = input.length();
//     int change = 0;
//     for (int i = 1;i < n;i++) {
//         if (is_vowel(input[i], mapping) != is_vowel(input[i - 1], mapping)) {
//             change++;
//             if (change > 3) {
//                 cout << "no";
//                 return 0;
//             }
//         }
//     }
//     cout << (change == 3 ? "yes" : "no");
//     return 0;
// }
// 三元组中心问题
// 2025-02-14 15:10:32
// int main() {
//     int n, minone = INT_MAX, maxone = INT_MIN, count = 0;
//     cin >> n;
//     vector<int> arr(n);
//     vector<vector<int>> min_and_max(n,{10001,-1});
//     for (int i = 0;i < n;i++) {
//         cin >> arr[i];
//         minone = min(minone, arr[i]);
//         min_and_max[i][0] = minone;
//     }
//     for (int i = n - 1;i >= 0;i--) {
//         maxone = max(maxone, arr[i]);
//         min_and_max[i][1] = maxone;
//     }
//     for (int i = 1;i < n - 1;i++) {
//         if (arr[i]<min_and_max[i + 1][1] && arr[i]>min_and_max[i - 1][0]) {
//             count++;
//         }
//     }
//     cout << count;
//     return 0;
// }
// 数位递增的数
// 简单省事写法
// int main() {
//     int n;
//     int ans = 0;
//     cin >> n;
//     for (int i = 1;i <= n;i++) {
//         string s = to_string(i);
//         string s1 = s;
//         sort(s.begin(), s.end());
//         if (s == s1)ans++;
//     }
//     cout << ans;
//     return 0;
// }
// 2025-02-14 14:31:35
// 16mins n 1 isright 函数花了不值得的时间
// bool is_right(int x) {
//     int temp = 0;
//     while (x > 0) {
//         temp = x % 10;
//         x /= 10;
//         if (temp < x % 10) {
//             return false;
//         }
//     }
//     return true;
// }
// int main() {
//     int n, count = 0;
//     cin >> n;
//     for (int i = 1;i <= n;i++) {
//         is_right(i) ? count++ : 1;
//     }
//     cout << count;
//     return 0;
// }
// 蓝桥王国2
// 2025-02-14 13:40:09
// 逆天题目
// typedef pair<int, int> pii;
// class Graph {
// public:
//     Graph (int v) : vertex(v), adjacent(v){};
//     int vertex;
//     vector<vector<pii>> adjacent;
//     void addEdge(int u, int v, int weight) {
//         adjacent[u].emplace_back(weight, v);
//     }
// };
// vector<int> dijkstra(Graph& graph,int source) {
//     priority_queue <pii, vector<pii>, greater<pii>> pq;
//     pq.emplace(0, source);
//     vector<int> dist(graph.vertex, numeric_limits<int>::max());
//     dist[source] = 0;
//     while (!pq.empty()) {
//         int current_dist = pq.top().first;
//         int u = pq.top().second;
//         pq.pop();
//         if (current_dist > dist[u]) {
//             continue;
//         }
//         for (auto& edge : graph.adjacent[u]) {
//             int weight = edge.first;
//             int v = edge.second;
//             if (dist[u] + weight > dist[v]) {
//                 dist[v] = dist[u] + weight;
//                 pq.emplace(dist[v], v);
//             }
//         }
//     }
//     return dist;
// }
// 蓝桥公园
// 2025-02-13 22:31:52
// dijkstra算法经典实现
// typedef pair<int, int> pii;
// class Graph {
// public:
//     int V; // vertex number
//     vector<vector<pii>> adjacent;// adjacent table,index for startpoint,then weight and endpoint
//     Graph(int v) : V(v), adjacent(v)/*initialize the size of table*/ {}
//     void addEdge(int u, int v, int weight) {
//         adjacent[u].emplace_back(weight, v);
//         // If undirected, uncomment the following line:
//         adjacent[v].emplace_back(weight, u);
//     }
// };

// vector<int> dijkstra(Graph& graph, int source /*the start point for begin*/) {
//     int v = graph.V;
//     vector<int> dist(v, numeric_limits<int>::max());//initialize the distance table
//     dist[source] = 0;
//     priority_queue<pii, vector<pii>, greater<pii>> pq;
//     pq.emplace(0, source);
//     while (!pq.empty()) {
//         int current_dist = pq.top().first; // must get 0,node1 -> node1 is determined ,weight of current point to which it is connecting(by loop gets)
//         int u = pq.top().second; // must get source,the closet route is node1 -> node1, the point of current point connets
//         pq.pop();
//         if (current_dist > dist[u]) {
//             continue;
//         }
//         for (auto& edge : graph.adjacent[u]) {
//             // get all connections of current point
//             int weight = edge.first;
//             int v = edge.second;
//             if (dist[u] + weight < dist[v]) {
//                 // find the shortest way to connect vpoint in dist_tablet within current point u
//                 dist[v] = dist[u] + weight;
//                 pq.emplace(dist[v], v);
//             }
//         }
//     }
//     return dist;
// }

// int main() {
//     int n, m, q, u,v,w,st,ed;
//     cin >> n >> m >> q;
//     Graph graph(n);
//     for (int i = 0;i < m;i++) {
//         cin >> u >> v >> w;
//         graph.addEdge(u - 1, v - 1, w);
//     }
//     for (int i = 0;i < q;i++) {
//         cin >> st >> ed;
//         auto dist = dijkstra(graph, st - 1);
//         if (dist[ed - 1] == numeric_limits<int>::max()) {
//             cout << -1 << endl;
//         }
//         else {
//             cout << dist[ed - 1] << endl;
//         }
//     }
//     return 0;
// }
// 查找两个总和为特定值的索引
// 2025-02-13 18:19:29
// int main() {
//     int length = 0, target = 0, temp = 0, left = INT_MAX, right = INT_MAX;
//     cin >> length;
//     vector<int> arr(length);
//     for (int i = 0;i < length;i++) {
//         cin >> temp;
//         arr[i] = temp;
//     }
//     cin >> target;
//     unordered_map<int, int> mapping;
//     for (int i = 0;i < length;i++) {
//         auto it = mapping.find(arr[i]);
//         if (it != mapping.end()) {
//             left > it->second ? left = it->second, right = i : 1;
//         }
//         mapping[target - arr[i]] = i;
//     }
//     cout << left << " " << right;
//     return 0;
// }

// 找到给定字符串中的不同字符
// 2025-02-13 18:11:30
// 10mins n 1 不支持reduce笑了
// int main() {
//     string str1, str2;
//     getline(cin, str1);
//     getline(cin, str2);
//     int sum1 = 0, sum2 = 0,l1 = str1.length(),l2 = str2.length();
//     for (int i = 0;i < l1;i++) {
//         sum1 += str1[i];
//     }
//     for (int j = 0;j < l2;j++) {
//         sum2 += str2[j];
//     }
//     cout << static_cast<char>(abs(sum1 - sum2));
//     return 0;
// }
// int main() {
//     string str1, str2;
//     getline(cin, str1);
//     getline(cin, str2);
//     int sum1 = reduce(str1.begin(), str1.end(), 0);
//     int sum2 = reduce(str2.begin(), str2.end(), 0);
//     cout << static_cast<char>(sum1 - sum2 > 0 ? sum1 - sum2 : sum2 - sum1);
//     return 0;
// }
// 反转字符串中的字符
// 2025-02-13 17:49:53
// 9mins n 1
// #include <iostream>
// using namespace std;
// int main(){
//     string input;
//     getline(cin, input);
//     reverse(input.begin(), input.end());
//     cout << input;
//     return 0;
// }
// 压缩字符串
// #include <iostream>
// #include<unordered_map>
// #include<algorithm>
// using namespace std;
// int main() {
//     string input = "", output = "";
//     int count = 0, length = 0;
//     char temp;
//     getline(cin, input);
//     sort(input.begin(),input.end(),less<char>());
//     temp = input[0];
//     for (char c : input) {
//         if (c != temp) {
//             length += (count == 1 ? 2 : count);
//             string add = to_string(count);
//             count = 1;
//             output += temp + add;
//             temp = c;
//         }
//         else {
//             count++;
//         }
//     }
//     if (length >= input.length()) {
//         cout << "NO";
//         return 0;
//     }
//     cout << output;
//     return 0;
// }

// 确定字符串是否是另一个的排列\
// 2025-02-13 15:21:47
// 5mins
// #include<iostream>
// #include<unordered_map>
// #include<string>
// using namespace std;
// int main() {
//     string str1, str2;
//     unordered_map<int, int> mapping;
//     getline(cin, str1);
//     getline(cin, str2);
//     for (char x : str1) {
//         mapping[x]++;
//     }
//     for (char x : str2) {
//         auto it = mapping.find(x);
//         if (it!= mapping.end()&&it->second>0) {
//             mapping[x]--;
//         }
//         else {
//             cout << "NO";
//             return 0;
//         }
//     }
//     cout << "YES";
//     return 0;
// }

// 确定字符串是否包含唯一字符
// 10mins 有点慢，由于蓝桥杯不支持C++20
// #include <iostream>
// #include<unordered_set>
// using namespace std;
// int main() {
//     unordered_set<char> mapping;
//     string input;
//     cin >> input;
//     for (char x : input) {
//         if (mapping.find(x)!= mapping.end()) {
//             cout << "NO";
//             return 0;
//         }
//         else {
//             mapping.insert(x);
//         }
//     }
//     cout << "YES";
//     return 0;
// }
// k倍区间
// #include<iostream>
// #include<vector>
// #include<unordered_map>
// using namespace std;
// int main() {
//     unordered_map<int, int> mapping;
//     int n, k, count = 0;
//     long long pre_sum = 0;
//     cin >> n >> k;
//     vector<int> nums(n);
//     for (int i = 0;i < n;i++) {
//         cin >> nums[i];
//     }
//     for (int i = 0;i < n;i++) {
//         nums[i] % k == 0 ? count++ : 1;
//         pre_sum += nums[i];
//         auto it = mapping.find(pre_sum % k);
//         if (it != mapping.end()) {
//             count += mapping[pre_sum % k];
//         }
//         mapping[pre_sum % k]++;
//     }
//     cout << count;
// }
// 2025-02-08 22:45:36
// 日志统计
// #include<iostream>
// #include<unordered_map>
// #include<map>
// using namespace std;
// void pretreatment() {
//     int n, d, k;
//     cin >> n >> d >> k;
//     unordered_map<int, map<int, int>> records;
//     unordered_map<int, int> likes_records;
//     for (int i = 0;i < n;i++) {
//         int time = 0, id = 0;
//         cin >> time >> id;
//         likes_records[id]++;
//         // if (records.find(id) == records.end()) {
//         records[id].insert(make_pair(time, likes_records[id]));
//         // }
//     }
// }
// 2025-02-08 22:15:52
// 12mins n 1 看了next_permutation全排列原理再写
// #include<iostream>
// #include<algorithm>
// using namespace std;
// int main() {
//     string input, target;
//     getline(cin, input);
//     target = input;
//     int index = 0;
//     sort(input.begin(), input.end());
//     do{
//         if (target == input) {
//             break;
//         }
//         index++;
//     } while (next_permutation(input.begin(), input.end()));
//     cout << index;
//     return 0;
// }
// 2. 分巧克力
// 40mins nlogn n经典二分查找题目，比较简单
// #include <iostream>
// #include <vector>
// using namespace std;
// bool canCut(int size, int k, const vector<pair<int, int>>& chocolates) {
//     int total = 0;
//     for (auto x : chocolates) {
//         int height = x.first;
//         int width = x.second;
//         total += (height / size) * (width / size);
//         if (total >= k) return true;
//     }
//     return total >= k;
// }
// int get_max_length(int max_size, int k, const vector<pair<int, int>>& chocolates) {
//     int left = 1, right = max_size;
//     int result = -1;
//     while (left <= right) {
//         int mid = left + (right - left) / 2;
//         if (canCut(mid, k, chocolates)) {
//             result = mid;
//             left = mid + 1;
//         }
//         else {
//             right = mid - 1;
//         }
//     }
//     return result;
// }

// int main() {
//     int n, k, maxone = 0;
//     cin >> n >> k;
//     vector<pair<int, int>> chocolates(n);
//     for (int i = 0;i < n;i++) {
//         cin >> chocolates[i].first >> chocolates[i].second;
//         maxone = max(maxone, max(chocolates[i].first, chocolates[i].second));
//     }
//     cout << get_max_length(maxone, k, chocolates);
//     return 0;
// }

// 归并排序
// const int N = 110;
// int array[N], temp[N];
// void solve(int array[],int left,int right){
//     if(left>right){
//         return;
//     }
//     int mid = (left + right) >> 1;
//     solve(array, left, mid);
//     solve(array, mid+1,right);
//     int k = 0, i = left, j = mid + 1;
//     while(i<=mid&&j<=right){
//         if(array[i] < array[j])
//             temp[k++] = array[i];
//         else
//             temp[k++] = array[j];
//     }
//     while(i<=mid)
//         temp[k++] = array[i++];
//     while(j<=right)
//         temp[k++] = array[j++];
//     for (int i = left, j = 0; i <= right;i++,j++){
//         array[i] = temp[j];
//     }
// }

// int main(){
//     int list[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
//     merge(list,0,9);
//     for (int i = 0; i < 10;i++){
//         cout << list[i] << "\t";
//     }
// }

// #include <iostream>
// using namespace std;
// const int N = 110;
// int init_array[N];
// int temp[N];

// void merge(int array[],int left ,int right){
//     int mid = (left + right)>>1;
//     if(left >= right) return ;
//     merge(array,left,mid);
//     merge(array,mid+1,right);
//     int i = left,j=mid+1,k=0;
//     while(i<=mid && j<=right){
//     if(array[i]<array[j]) temp[k++] = array[i++];
//     else temp[k++] = array[j++];
//     }
//     while(i<=mid) temp[k++] = array[i++];
//     while(j<=right) temp[k++] = array[j++];

//     for(int i = left,j=0;i<=right;i++,j++){
//     array[i] = temp[j];
//     }
// }
// int main(){
//     // 请在此输入您的代码
//     int n= 0;
//     cin >> n;
//     for(int i =0;i<n;i++){
//         cin >> init_array[i];
//     }
//     merge(init_array,0,n-1);
//     for(int i =0;i<n;i++){
//         cout << init_array[i] <<" ";
//     }
//     return 0;
// }

// 2. 二维差分

// int main(){
//     int n = 0, m = 0, operate = 0;
//     int x1 = 0, y1 = 0, x2 = 0, y2 = 0, d = 0;
//     cin >> n >> m >> operate;
//     int matrix[n][m];
//     for (int i = 0; i < n;i++){
//         for (int j = 0; j < m; j++){
//             cin >> matrix[i][j];
//         }
//     }
//     for (int k = 0; k < operate;k++){
//         cin >> x1 >> y1 >> x2 >> y2 >> d;
//         for (int i = x1-1; i < x2;i++){
//             for (int j =  y1-1; j < y2;j++){
//                 matrix[i][j] += d;
//             }
//         }
//     }
//     for(int i = 0; i < n; i++){
//         for(int j = 0; j < m; j++){
//             if(j != m - 1){
//                 cout << matrix[i][j] << " ";
//             }
//             else{
//                 cout << matrix[i][j];
//             }
//         }
//         cout << endl;
//     }
// }

// 一维差分(太简单不写了)

// int main(){
//     int n = 0, numbers = 0;
//     int l = 0, r = 0, d = 0;
//     cin >> n >> numbers;
//     int array[n] = {};
//     for (int i = 0; i < n;i++){
//         cin >> array[i];
//     }
//     int list[numbers] = {};
//     for()
//     for (int j = 0; j < numbers;j++){

//     }
// }

// 7. 二分查找数组元素
// 使用algorithm库直接查找方法
// int main(){
//     vector<int> vec(200,0);
//     for(int i = 0 ; i < 200 ; i ++)
//         vec[i] = 4 * i + 6;
//     int n;
//     cin >> n;
//     auto result = find(vec.begin(), vec.end(), n);
//     cout << result - vec.begin();
//     return 0;
// }

// 规规矩矩法
// int main(){
//     int data[200];
//     for(int i = 0 ; i < 200 ; i ++)
//         data[i] = 4 * i + 6;

//     int left = 0, right = 199;
//     int target;
//     cin >> target;
//     while(left<=right){
//         int mid = (left + right) >> 1;
//         if(data[mid]>target){
//             right = mid;
//         }else if(data[mid]<target){
//             left = mid;
//         }else{
//             cout << mid;
//             break;
//         }
//     }
//     return 0;
// }

// 443.二分法

// #include <stdio.h>
// #define N 23

// int find(int* m, int k)
// {
//     int lo = 0;
//     int hi = N-1;

//     while(lo<=hi){
//         int mid = (lo+hi)/2;
//         if      (k<m[mid]) hi = mid-1;
//         else if (k>m[mid]) lo = mid+1;
//         else return mid ;
//     }

//     return -1;
// }

// int main()
// {
//     int m[N] = {
//     1,4,5,8,11,
//     13,14,15,22,27,
//     35,46,48,49,49,
//     51,60,62,62,62,
//     71,74,88};
//     printf("%d ", find(m,60));
//     printf("%d ", find(m,55));
//     printf("%d ", find(m,1));
//     printf("\n");
//     return 0;
// }

// 牛客 DP 34【模板】一维前缀和
// #include<iostream>
// #include<vector>
// using namespace std;
// int main() {
// 	int n , q ;
// 	cin >> n >> q;
// 	vector<int> array(n + 1,0);
// 	for(int i = 1; i <= n; i++) {
// 		cin >> array[i];
// 	}
// 	vector<long long> sum(n + 1,0);
// 	for(int i = 1 ; i <= n; i++) {
// 		sum[i] = sum[i - 1] + array[i];
// 	}
// 	int left , right;
// 	while(q--) {
// 		cin >> left >> right;
//         cout << sum[right] - sum[left - 1] << endl;
//     }
// 	return 0;
// }

// 牛客DP35 【模板】二维前缀和
// int main(){
//     int n, m, q;
//     cin >> n >> m >> q;
//     vector<vector<int>> matrix(n+1,vector<int>(m+1 , 0));
//     for (int i = 1; i <= n;i++){
//         for (int j = 1; j <= m;j++){
//             cin >> matrix[i][j];
//         }
//     }
//     vector<vector<long long>> sum(n + 1, vector<long long>(m + 1, 0));
//     for (int i = 1; i <= n;i++){
//         for (int j = 1; j <= m;j++){
//             sum[i][j] = sum[i - 1][j] + sum[i][j - 1] + matrix[i][j] - sum[i-1][j-1];
//         }
//     }
//     int x1, y1, x2, y2;
//     while(q--){
//         cin >> x1 >> y1 >> x2 >> y2;
//         cout << sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1] << endl;
//     }
// }

// 724 寻找数组的中心下标
// 只使用前缀和方法
// class Solution {
// public:
//     int pivotIndex(vector<int>& nums) {
//         int length = nums.size();
//         vector<int> sum(length+1,0);
//         for (int i = 1; i <= length;i++){
//             sum[i] = sum[i - 1] + nums[i - 1];
//         }
//         for (int index = 0; index <= length ;index ++){
//             if(sum[index]==sum[length] - sum[index+1])
//                 return index;
//         }
//         return -1;
//     }
// };
// int main(){
//     Solution s;
//     vector<int> numbers{1, 2, 3};
//     cout << s.pivotIndex(numbers);
//     return 0;
// }

// 使用前后缀和两个数组，更大内存
// class Solution{
// public:
//     int pivotIndex(vector<int> &nums){
//         int n = nums.size();
//         vector<int> f(n);
//         vector<int> g(n);
//         for (int i = 1; i < n; i++)
//             f[i] = f[i - 1] + nums[i - 1];
//         for (int i = n - 2; i >= 0; i--)
//             g[i] = g[i + 1] + nums[i + 1];

//         for (int i = 0; i < n; i++)
//             if (f[i] == g[i])
//                 return i;

//         return -1;
//     }
// };

// int main()
// {
//     Solution s;
//     vector<int> numbers{1, 2, 3};
//     cout << s.pivotIndex(numbers);
//     return 0;
// }

// 238 除自身以外数组的乘积
// 不限制时间暴力解法，会超时
// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         int length = nums.size();
//         vector<int> new_nums;
//         int product = 1;
//         vector<int> temp = nums;
//         for (int i = 0; i < length;i++){
//             temp.erase(find(temp.begin(),temp.end(),temp[i]));
//             for (int j = 0; j < temp.size();j++){
//                 product *= temp[j];
//             }
//             new_nums.push_back(product);
//             product = 1;
//             temp = nums;
//         }
//         return new_nums;
//     }
// };

// 使用前后缀和方法
// class Solution{
//     public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         int length = nums.size();
//         vector<int> left(length+1);
//         vector<int> right(length+1);
//         vector<int> answer;
//         left[0] = 1;
//         right[length] = 1;
//         for (int i = 1; i <= length;i++){
//             left[i] = left[i - 1] * nums[i - 1];
//         }
//         for (int j = length - 1; j >= 0;j--){
//             right[j] = right[j + 1] * nums[j];
//         }
//         for (int k = 0; k < length;k++){
//             answer.push_back(left[k] * right[k + 1]);
//         }
//         return answer;
//     }
// };

// int main(){
//     Solution s;
//     vector<int> test1 = {1, 2, 3, 4};
//     vector<int> test2 = {-1,1,0,-3,3};
//     s.productExceptSelf(test1);
//     for (int temp = 0; temp < test1.size();temp++){
//         cout << s.productExceptSelf(test1)[temp] << " ";
//     }
//     cout << endl;
//     for (int temp = 0; temp < test2.size();temp++){
//         cout << s.productExceptSelf(test2)[temp] << " ";
//     }
// }

// int main(){
//     // test arrays
//     // vector<int> test_g1{1, 2, 3};
//     // vector<int> test_s1{1, 1};
//     // vector<int> test_g2{1, 2};
//     // vector<int> test_s2{1, 2, 3};
//     vector<int> test_g3{1, 2,3};
//     vector<int> test_s3{3};
//     Solution s;
//     // cout << s.findContentChildren(test_g1, test_s1);
//     // cout << s.findContentChildren(test_g2, test_s2);
//     cout << s.findContentChildren(test_g3, test_s3);
// }
// 209翻硬币
// n 1 40mins很快就想到了思路但是ifelse条件选择上有点问题浪费了很多时间
// #include<iostream>
// #include<vector>
// using namespace std;
// int main(){
//     string input, target;
//     cin >> input >> target;
//     int n = input.length(), ans = 0;
//     vector<int> positions;
//     for (int i = 0,temp = -1; i < n;i++){
//         if(input[i]!=target[i]){
//             if(temp == -1){
//                 temp = i;
//             }else{
//                 ans += i - temp;
//                 temp = -1;
//             }
//         }
//     }
//     cout << ans;
// }