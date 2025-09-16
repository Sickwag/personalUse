#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int M = 2e5 + 5;
const int LOG = 20;

struct PersistentDSU {
    struct Node {
        int l, r;
        int parent, rank;
    } t[N * LOG * 2];

    int roots[M], cnt;
    int n, current_version;

    void init(int _n) {
        n = _n;
        cnt = 0;
        current_version = 0;
        roots[0] = build(1, n);
    }

    int build(int l, int r) {
        int p = ++cnt;
        if (l == r) {
            t[p].parent = l;
            t[p].rank = 1;
            return p;
        }
        int mid = (l + r) >> 1;
        t[p].l = build(l, mid);
        t[p].r = build(mid + 1, r);
        return p;
    }

    int update(int pre, int l, int r, int pos, int new_parent, int new_rank) {
        int p = ++cnt;
        t[p] = t[pre];
        if (l == r) {
            if (new_parent != -1)
                t[p].parent = new_parent;
            if (new_rank != -1)
                t[p].rank = new_rank;
            return p;
        }
        int mid = (l + r) >> 1;
        if (pos <= mid)
            t[p].l = update(t[pre].l, l, mid, pos, new_parent, new_rank);
        else
            t[p].r = update(t[pre].r, mid + 1, r, pos, new_parent, new_rank);
        return p;
    }

    pair<int, int> query(int p, int l, int r, int pos) {
        if (l == r)
            return {t[p].parent, t[p].rank};
        int mid = (l + r) >> 1;
        if (pos <= mid)
            return query(t[p].l, l, mid, pos);
        return query(t[p].r, mid + 1, r, pos);
    }

    int find(int version, int x) {
        auto [parent, _] = query(roots[version], 1, n, x);
        return parent == x ? x : find(version, parent);
    }

    void merge(int a, int b) {
        int root_a = find(current_version, a);
        int root_b = find(current_version, b);

        if (root_a == root_b) {
            roots[current_version + 1] = roots[current_version];
            current_version++;
            return;
        }

        auto [_, rank_a] = query(roots[current_version], 1, n, root_a);
        auto [__, rank_b] = query(roots[current_version], 1, n, root_b);

        int new_version = current_version + 1;
        if (rank_a > rank_b) {
            roots[new_version] = update(roots[current_version], 1, n, root_b, root_a, -1);
        } else if (rank_a < rank_b) {
            roots[new_version] = update(roots[current_version], 1, n, root_a, root_b, -1);
        } else {
            roots[new_version] = update(roots[current_version], 1, n, root_a, root_b, -1);
            roots[new_version] = update(roots[new_version], 1, n, root_b, -1, rank_b + 1);
        }
        current_version = new_version;
    }

    bool same(int version, int a, int b) {
        return find(version, a) == find(version, b);
    }

    void rollback(int version) {
        roots[current_version + 1] = roots[version];
        current_version++;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    PersistentDSU dsu;
    dsu.init(n);

    for (int i = 1; i <= m; i++) {
        int opt, a, b, k;
        cin >> opt;

        if (opt == 1) {
            cin >> a >> b;
            dsu.merge(a, b);
        } else if (opt == 2) {
            cin >> k;
            dsu.rollback(k);
        } else if (opt == 3) {
            cin >> a >> b;
            cout << (dsu.same(dsu.current_version, a, b) ? "1" : "0") << '\n';
            dsu.rollback(dsu.current_version);  // 查询操作也创建一个新版本
        }
    }

    return 0;
}

// // P3402 【模板】可持久化并查集，错误做法
// const int N = 1e6 + 5;
// int pre[N], node_rank[N];
// void init(int n) {
//     for (int i = 0; i < n; i++) {
//         pre[i] = i;
//         node_rank[i] = 1;
//     }
// }

// int find_root(int x) {
//     if (pre[x] == x)
//         return x;
//     return pre[x] = find_root(pre[x]);
// }

// void unite(int x, int y) {
//     int root_x = find_root(x);
//     int root_y = find_root(y);
//     if (root_x == root_y)
//         return;
//     // pre[root_x] = root_y;
//     if (node_rank[root_x] > node_rank[root_y]) {
//         pre[root_y] = root_x;
//     } else {
//         pre[root_x] = root_y;
//         if (node_rank[root_x] == node_rank[root_y]) {
//             node_rank[root_y]++;
//         }
//     }
// }
// void remove(int x, int y) {
//     pre[x] = x;
//     pre[y] = y;
// }
// struct Step {
//     bool check;
//     int order, a, b, k;
//     Step(int order_, int a_, int b_) : order(order_), a(a_), b(b_), k(-1), check(false) {}
//     Step(int order_, int k_) : order(order_), k(k_), a(-1), b(-1) {}
//     Step(int order_, int a_, int b_, bool is_check) : order(order_), a(a_), b(b_), k(-1), check(is_check) {}
// };
// int main() {
//     int n, m, opt, a, b, cur, to;
//     cin >> n >> m;
//     vector<Step> moves;
//     for (int i = 1; i <= m; i++) {
//         cin >> opt;
//         if (opt == 1) {
//             cin >> a >> b;
//             unite(a, b);
//             moves.emplace_back(Step(i, a, b));
//             cur++;
//         } else if (opt == 2) {
//             cin >> to;
//             if (to > cur) {
//                 for (int i = cur + 1; i <= to; i++) {
//                     auto& pair = moves[i + 1];
//                     if (pair.check == false) {
//                         unite(pair.a, pair.b);
//                     }
//                 }
//             } else if (to < cur) {
//                 for (int i = cur; i > to; i--) {
//                     auto& pair = moves[i + 1];
//                     if (pair.check == false) {
//                         remove(moves[i+1].a, moves[i+1].b);
//                     }
//                 }
//             }
//             cur = to;
//             moves.emplace_back(Step(i, to));
//         } else if (opt == 3) {
//             cin >> a >> b;
//             cout << (find_root(a) == find_root(b)) ? "1" : "0";
//             cout << endl;
//             cur++;
//             moves.emplace_back(Step(i, a, b, true));
//         }
//     }
//     return 0;
// }

// P3367 【模板】并查集
// 2025年9月16日14:06:22  17min
// const int N = 1e6 + 5;
// int pre[N], node_rank[N];
// void init(int n) {
//     for (int i = 0; i < n; i++) {
//         pre[i] = i;
//         node_rank[i] = 1;
//     }
// }

// int find_root(int x) {
//     if (pre[x] == x)
//         return x;
//     return pre[x] = find_root(pre[x]);
// }

// void unite(int x, int y) {
//     int root_x = find_root(x);
//     int root_y = find_root(y);
//     if (root_x == root_y)
//         return;
//     // pre[root_x] = root_y;
//     if (root_x > root_y) {
//         pre[root_y] = pre[root_x];
//     } else {
//         pre[root_x] = root_y;
//         if (root_x == root_y) {
//             node_rank[root_y]++;
//         }
//     }
// }

// int main() {
//     int n, m, z, x, y;
//     cin >> n >> m;
//     // vector<pair<int, int>> request;
//     init(n);
//     while (m--) {
//         cin >> z >> x >> y;
//         if (z == 1) {
//             unite(x, y);
//         } else {
//             // request.push_back(make_pair(x, y));
//             bool flag = (find_root(x) == find_root(y));
//             cout << (flag ? "Y\n" : "N\n");
//         }
//     }
//     // for(const auto& pair : request){
//     //     bool flag = (find_root(pair.first) == find_root(pair.second));
//     //     cout << (flag ? "Y\n" : "N\n");
//     // }
// }

// MT2137 附庸的附庸 模板题，跳过

// P2097 资料分发 1
// 国王的烦恼 官网上找不到,
// 时间复杂度n
// const int N = 10010;
// const int M = 100010;
// struct Bridge  // 代表桥
// {
//     int x, y;  // 表示桥连接的两个地方
//     int day;   // 表示这个桥的可用时限（天数）
//     Bridge() {}
//     Bridge(int a, int b, int c) : x(a), y(b), day(c) {}
// };
// Bridge bridge[M];  // 用于存储所有的桥
// int pre[N];        // 用于存储每个小岛的“上级”

// void init(int n) {
//     for (int i = 1; i <= n; i++)
//         pre[i] = i;
// }
// int find_pre(int n) {
//     if (pre[n] == n)
//         return n;
//     else
//         return pre[n] = find_pre(pre[n]);
// }
// bool unite(int x, int y) {
//     int root_x = find_pre(x);
//     int root_y = find_pre(y);
//     if (root_x != root_y) {
//         pre[root_x] = root_y;
//         return true;
//     } else
//         return false;
// }
// bool cmp(Bridge a, Bridge b) {
//     return a.day > b.day;
// }

// int main() {
//     int n, m, a, b, t;
//     cin >> n >> m;
//     init(n);
//     for (int i = 1; i <= m; i++) {
//         cin >> a >> b >> t;
//         bridge[i] = Bridge(a, b, t);
//     }
//     sort(bridge + 1, bridge + 1 + m, cmp);
//     int ans = 0, lastDay = 0;  // lastDay用于探测一次某个桥的生命时限
//     for (int i = 1; i <= m; i++) {
//         bool flag = unite(bridge[i].x, bridge[i].y);  // 如果为真表示当前这两个岛未联通
//         if (flag && bridge[i].day != lastDay)         // 未连通，且此桥的天数是第一次出现，那么就增加了抗议的天数
//         {
//             ans++;
//             lastDay = bridge[i].day;
//         }
//     }
//     cout << ans << endl;
//     return 0;
// }

// 时间复杂度为2n^2有点高

// const int N = 10010;
// struct Bridge {
//     int day, x, y;
//     Bridge() {}
//     Bridge(int a, int b, int c) : x(a), y(b), day(c) {}
// };
// int pre[N], node_rank[N];

// void init(int n) {
//     for (int i = 1; i <= n; i++){
//         pre[i] = i;
//         node_rank[i] = 1;
//     }

// }
// int find_root(int n) {
//     if (pre[n] == n)
//         return n;
//     else
//         return pre[n] = find_root(pre[n]);
// }

// void unite(int x, int y) {
//     int root_x = find_root(x);
//     int root_y = find_root(y);
//     // if (root_x != root_y) {
//     //     pre[root_x] = root_y;
//     // }
//     if(root_x == root_y)
//         return;
//     if(root_x > root_y){
//         pre[root_y] = root_x;
//     }else{
//         pre[root_x] = root_y;
//         if(root_x == root_y){
//             node_rank[root_y]++;
//         }
//     }
// }
// int main() {
//     int n, m, a, b, t, boycott = 0;
//     cin >> n >> m;
//     auto compare = [](const Bridge& a, const Bridge& b) { return a.day < b.day; };
//     // multiset<Bridge, decltype(compare)> bridges(compare);
//     vector<Bridge> bridges;
//     set<int> life, counter;
//     for (int i = 1; i <= m; i++) {
//         cin >> a >> b >> t;
//         bridges.emplace_back(Bridge(a, b, t));
//         life.insert(t);
//     }
//     sort(bridges.begin(), bridges.end(), compare);
//     vector<int> day_left(life.rbegin(), life.rend());
//     for (int i = 0; i < day_left.size(); i++) {
//         init(n);
//         for (const auto& item : bridges) {
//             if (item.day < day_left[i]) {
//                 unite(item.x, item.y);
//             }
//         }
//         for (const auto& bridge : bridges) {
//             counter.insert(find_root(bridge.x));
//         }
//         if (counter.size() != 1){
//             boycott += i == 0 ? 1 : day_left[i - 1] - day_left[i];
//         }
//         counter.clear();
//     }
//     cout << boycott;
// }
// 合根植物--通用加权标记法
// constexpr int N = 1005 * 1005;
// int pre[N], node_rank[N];
// void init(int sum) {
//     for (int i = 1; i <= sum; i++) {
//         pre[i] = i;
//         node_rank[i] = 0;
//     }
// }

// int find_root(int x) {
//     if (pre[x] != x) {
//         pre[x] = find_root(pre[x]);
//     }
//     return pre[x];
// }

// void unite(int x, int y) {
//     int root_x = find_root(x);
//     int root_y = find_root(y);
//     if(root_x == root_y)
//         return;
//     if (node_rank[root_x] > node_rank[root_y]) {
//         pre[root_y] = root_x;
//     }
//     else{
//         pre[root_x] = root_y;
//         if (node_rank[root_x] == node_rank[root_y]) {
//             node_rank[root_y]++;
//         }
//     }
// }

// int main() {
//     int m, n, k, x, y;
//     cin >> m >> n >> k;
//     init(n * m);
//     for (int i = 0; i < k; ++i) {
//         cin >> x >> y;
//         unite(x, y);
//     }
//     unordered_set<int> st;
//     for (int i = 1; i <= n * m; i++) {
//         st.insert(find_root(i));
//     }
//     cout << st.size();
// }
// 合根植物--通用合并法
// constexpr int N = 1005 * 1005;
// int pre[N];
// void init(int sum) {
//     for (int i = 1; i <= sum; i++) {
//         pre[i] = i;
//     }
// }
// int find_root(int x) {
//     if (pre[x] == x)
//         return x;
//     return pre[x] = find_root(pre[x]);
// }

// void unite(int x, int y) {
//     int root_x = find_root(x);
//     int root_y = find_root(y);
//     if (root_x != root_y)
//         pre[root_x] = root_y;
// }
// int main() {
//     int m, n, k, x, y;
//     cin >> m >> n >> k;
//     init(n * m);
//     for (int i = 0; i < k; ++i) {
//         cin >> x >> y;
//         unite(x, y);
//     }
//     unordered_set<int> st;
//     for (int i = 1; i <= n * m; i++) {
//         st.insert(find_root(i));
//     }
//     cout << st.size();
// }

// P9749[CSP - J 2023] 公路
// int main() {
//     int station_num, miles_per_gas;
//     vector<int> distance(station_num), gas_cost(station_num + 1);
//     cin >> station_num >> miles_per_gas;
//     for (int i = 1; i <= station_num - 1; ++i) {
//         cin >> distance[i];
//     }
//     for (int j = 1; j <= station_num; ++j) {
//         cin >> gas_cost[j];
//     }
//     int current_gas_cost = gas_cost[1];
//     double total_cost = 0;
//     int already_run = 0;

//     for (int i = 1; i <= station_num ; ++i){
//         if(current_gas_cost <= gas_cost[i]){
//             already_run += distance[i];
//         }else{
//             // already_run += distance[i];
//             total_cost += ceil((double(already_run) / double(miles_per_gas))) * current_gas_cost;
//             current_gas_cost = gas_cost[i];
//             already_run = distance[i];
//         }
//     }

//     std::cout << total_cost;
// }

// string convertBase(int from, int to, const string& input) {
//     string result;
//     const char* alpha = "0123456789abcdefghijklmnopqrstuvwxyz";
//     long long num = 0;
//     for (auto& c : input) {
//         int value = isdigit(c) ? c - '0' : tolower(c) - 'a' + 10;
//         num = num * from + value;
//     }
//     while (num > 0) {
//         result.push_back(alpha[num % to]);
//         num /= to;
//     }
//     reverse(result.begin(), result.end());
//     return result;
// }

// // P4710 「物理」平抛运动
// void horizonThrowing(double v, double arc) {
//     const double c = arc / acos(-1.0);
//     double x = pow(v, 2) * sin(c) * cos(c) / 10.0;
//     double y = pow(v, 2) * pow(cos(c), 2) / 2 / 10.0;
//     cout << x << " " << y;
// }

// // P1147 连续自然数和
// void continuousNumber(int target) {
//     vector<int> pre_sum(2000001);
//     for (int i = 0; i < pre_sum.size(); i++) {
//         pre_sum[i] = i * (i + 1) / 2;
//     }
// }

// int main() {
//     // cout << convertBase(9, 10, "2022");
//     double v = 14.142136, arc = 0.785398;
//     horizonThrowing(v, arc);
// }
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
