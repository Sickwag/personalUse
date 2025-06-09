#include<bits/stdc++.h>
#include<cmath>
using namespace std;

string convertBase(int from, int to, const string& input) {
    string result;
    const char* alpha = "0123456789abcdefghijklmnopqrstuvwxyz";
    long long num = 0;
    for (auto& c : input) {
        int value = isdigit(c) ? c - '0' : tolower(c) - 'a' + 10;
        num = num * from + value;
    }
    while (num > 0) {
        result.push_back(alpha[num % to]);
        num /= to;
    }
    reverse(result.begin(), result.end());
    return result;
}

// P4710 「物理」平抛运动
void horizonThrowing(double v, double arc) {
    const double c = arc / acos(-1.0);
    double x = pow(v, 2) * sin(c) * cos(c) / 10.0;
    double y = pow(v, 2) * pow(cos(c), 2) / 2 / 10.0;
    cout << x << " " << y;
}

// P1147 连续自然数和
void continuousNumber(int target) {
    vector<int> pre_sum(2000001);
    for (int i = 0;i < pre_sum.size(); i++) {
        pre_sum[i] = i * (i + 1) / 2;
    }
}

int main() {
    // cout << convertBase(9, 10, "2022");
    double v = 14.142136, arc = 0.785398;
    horizonThrowing(v, arc);
}
// B2122 单词翻转
// int main() {
//     string input, buffer;
//     cin >> input;
//     istringstream iss(input);
//     while (iss >> buffer) {
//         reverse(buffer.begin(), buffer.end());
//         cout << buffer << " ";
//     }
//     return 0;
// }


// P7072[CSP - J2020] 直播获奖
// 桶排序
// int main() {
//     int scores[601] = {};
//     int n, w, cur = 0, score;
//     cin >> n >> w;
//     while (n--) {
//         cin >> score;
//         scores[score]++;
//         cur++;
//         int line = max(1, cur * w / 100);
//         int sum = 0, record = 0;
//         for (int i = 600; i>=0;i--) {
//             sum += scores[i];
//             if (sum >= line) {
//                 record = i;
//                 break;
//             }
//         }
//         cout << record << " ";
//     }
//     return 0;
// }
// 对顶堆，及格线题
// class Solution {
// private:
//     priority_queue<int> min_heap;
//     priority_queue<int, vector<int>, greater<int>> max_heap;
//     int line, crossed;
//     void adjust() {
//         if (min_heap.size() < crossed) {
//             min_heap.push(max_heap.top());
//             max_heap.pop();
//         }
//         if (min_heap.size() > crossed) {
//             max_heap.push(min_heap.top());
//             min_heap.pop();
//         }
//     }
//     void insert(int& num) {
//         if (num > max_heap.top()) min_heap.push(num);
//         else max_heap.push(num);
//         adjust();
//     }
// public:
//     void start() {
//         int n, w;
//         cin >> n >> w;
//         max_heap.push(0);
//         for (int i = 1;i < n;i++) {
//             int now = max(1, i * w / 100);
//             int temp;
//             cin >> temp;
//             insert(temp);
//             cout << min_heap.top();
//         }
//     }
// };
// int main() {
//     Solution sol;
//     sol.start();
//     return 0;
// }
// 部分测试集超时
// int main() {
//     int num, temp;
//     float rate;
//     cin >> num;
//     cin >> temp;
//     rate = temp / 100.0;
//     vector<int> scores;
//     for (int i = 0;i < num;i++) {
//         cin >> temp;
//         int line = max(1, (int)floor((i + 1) * rate));
//         scores.push_back(temp);
//         sort(scores.begin(), scores.end(),greater<int>());
//         // make_heap(scores.begin(), scores.end());
//         cout << scores[line-1] << " ";
//     }
//     return 0;
// }
// int main() {
//     string str = "192384576";
//     vector<array<int, 3>> ans;
//     do {
//         int one = stoi(str.substr(0, 3));
//         int two = stoi(str.substr(3, 3));
//         int three = stoi(str.substr(6, 3));
//         if (one * 2 == two && one * 3 == three)
//             ans.push_back({ one, two,three });
//     } while (next_permutation(str.begin(), str.end()));
//     for (auto& x : ans ) {
//         for (auto& y : x ) {
//             cout << y << " ";
//         }
//         cout << endl;
//     }
// }
// P1217[USACO1.5] 回文质数 Prime Palindromes
// vector<int> eulerSieve(int a, int b) {
//     vector<int> primes;
//     if (b < 2) return primes;
//     vector<bool> isPrime(b + 1, true);
//     isPrime[0] = isPrime[1] = false;
//     for (int i = 2; i <= b; ++i) {
//         if (isPrime[i]) {
//             primes.push_back(i);
//         }
//         for (int j = 0; j < primes.size() && primes[j] * i <= b; ++j) {
//             isPrime[primes[j] * i] = false;
//             if (i % primes[j] == 0) {
//                 break;
//             }
//         }
//     }
//     vector<int> result;
//     for (int i = a; i <= b; ++i) {
//         if (isPrime[i]) {
//             result.push_back(i);
//         }
//     }
//     return result;
// }
// bool isValid(int n) {
//     string num = to_string(n);
//     int head = 0, end = num.size() - 1;
//     while (head <= end) {
//         if (num[head] != num[end])
//             return false;
//         head++, end--;
//     }
//     return true;
// }
// int main() {
//     vector<int> primes = eulerSieve(5, 100);
//     for (auto& x : primes) {
//         if (isValid(x)) cout << x << endl;
//     }
// }
// lambda比较方式
// int main() {
//     int n = 0;
//     cin >> n;
//     auto comp = [&](const string& a, const string& b) {
//         if (a.size() > b.size()) return true;
//         else if (a.size() < b.size()) return false;
//         else return a > b;
//         };
//     map<string, int, decltype(comp)> records(comp);
//     for (int i = 0; i < n; i++) {
//         string temp;
//         cin >> temp;
//         records.insert({ temp,i + 1 });
//     }
//     cout << (*records.begin()).second << endl;;
//     cout << (*records.begin()).first;
// }
// P1781 宇宙总统
// #include<string>
// #include<map>
// #include<algorithm>
// #include<utility>
// using namespace std;
// struct Comp {
//     bool operator()(const string& a, const string& b) const {
//         if (a.size() > b.size()) {
//             return true;
//         }
//         else if (a.size() < b.size()) {
//             return false;
//         }
//         else {
//             return a > b;
//         }
//     }
// };
// int main() {
//     int n = 0;
//     cin >> n;
//     map<string, int, Comp> records;
//     for (int i = 0; i < n; i++) {
//         string temp;
//         cin >> temp;
//         records.insert({ temp,i + 1 });
//     }
//     cout << (*records.begin()).first;
// }

