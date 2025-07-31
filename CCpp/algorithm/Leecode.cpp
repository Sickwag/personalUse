#include <bits/stdc++.h>
#include "dataStruct.cpp"
using namespace std;
// 45. 跳跃游戏 II
class Solution {
   public:
    int jump(vector<int>& nums) {
    }
};
// 75. 颜色分类 简单题
// 单循环复写法：
// class Solution {
//    public:
//     void sortColors(vector<int>& nums) {
//         int p0 = 0, p1 = 0;
//         for (int i = 0; i < nums.size(); i++) {
//             int x = nums[i];
//             nums[i] = 2;
//             if (x <= 1)
//                 nums[p1++] = 1;
//             if (x == 0)
//                 nums[p0++] = 0;
//         }
//     }
// };
// 计数写法：
// class Solution {
//    public:
//     void sortColors(vector<int>& nums) {
//         int zero = 0, one = 0, two = 0;
//         for (const auto& item : nums) {
//             if (item == 0)
//                 zero++;
//             else if (item == 1)
//                 one++;
//             else
//                 two++;
//         }
//         for (int i = 0; i < zero; i++) {
//             nums[i] = 0;
//         }
//         for (int i = zero; i < zero + one; i++) {
//             nums[i] = 1;
//         }
//         for (int i = zero + one; i < zero + one + two; i++) {
//             nums[i] = 2;
//         }
//     }
// };

// // 872. 叶子相似的树
// 11 min
// class Solution {
//     void backtrace(TreeNode* node, vector<int>& path) {
//         if (!node->left && !node->right) {
//             path.push_back(node->val);
//             return;
//         }
//         if (node->left) backtrace(node->left, path);
//         if (node->right) backtrace(node->right, path);
//     }
// public:
//     bool leafSimilar(TreeNode* root1, TreeNode* root2) {
//         vector<int> v1, v2;
//         backtrace(root1, v1);
//         backtrace(root2, v2);
//         return v1 == v2;
//     }
// };

// int main() {
//     GenerateDataType gdt;
//     string root1 = "[3,5,1,6,2,9,8,null,null,7,4]";
//     string root2 = "[3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]";
//     gdt.tree.build(root1);
//     auto r1 = gdt.tree.builtTreeRoot();
//     gdt.tree.build(root2);
//     auto r2 = gdt.tree.builtTreeRoot();
//     Solution sol;
//     cout << sol.leafSimilar(r1, r2);
// }

// 前中后序遍历只需要调整traversal函数中三个语句顺序即可
// class Solution {
//     void traversal(TreeNode* node, vector<int>& path) {
//         if (node->left) traversal(node->left, path);
//         if (node->right) traversal(node->right, path);
//         path.push_back(node->val);
//     }
// public:
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int> path;
//         if (!root) return path;
//         traversal(root, path);
//         return path;
//     }
// };

// int main() {
//     GenerateDataType gdt;
//     string raw = "[1,2,3,4,5,null,8,null,null,6,7,9]";
//     gdt.tree.build(raw);
//     auto root = gdt.tree.builtTreeRoot();
//     Solution sol;
//     for (const auto& it : sol.preorderTraversal(root)) {
//         cout << it << endl;
//     }
// }

// 1436. 旅行终点站
// class Solution {
// public:
//     string destCity(vector<vector<string>>& paths) {
//         unordered_map<string, int> map;
//         for (auto& item : paths) {
//             map[item[0]] += 1;
//             map[item[1]] -= 1;
//         }
//         for (auto& it : map) {
//             if (it.second == -1) return it.first;
//         }
//         return string();
//     }
// };
// 55. 跳跃游戏;
// class Solution {
// public:
//     bool canJump(vector<int>& nums) {
//         int point = 0;
//         int maxone = nums[point];
//         while (point < nums.size() - 1 && point < maxone) {
//             maxone = max(point + 1 + nums[point + 1], maxone);
//             point += 1;
//         }
//         return maxone < nums.size() - 1 ? false : true;
//     }
// };
// // for循环优化
// class Solution {
// public:
//     bool canJump(vector<int>& nums) {
//         int maxone = nums[0];
//         for (int i = 0;i < nums.size() - 1 && i < maxone; i++) {
//             maxone = max(i + 1 + nums[i + 1], maxone);
//         }
//         return maxone < nums.size() - 1 ? false : true;
//     }
// };
// int main() {
//     vector<int> test = { 3,2,1,0,4 };
//     Solution sol;
//     cout << sol.canJump(test);
// }
////////////////////hot 100 ///////////////////////////
// 560. 和为 K 的子数组
// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         vector<int> presum(nums.size() + 1, 0);
//         unordered_set<int> record;
//         int count = 0;
//         partial_sum(nums.begin(), nums.end(), presum.begin() + 1);
//         for (int i = 0;i < presum.size();i++) {
//             if (record.contains(presum[i])) count++;
//             else record.insert(presum[i] + k);
//         }
//         return count;
//     }
// };
// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         unordered_map<int, int> prefix_count;
//         prefix_count[0] = 1;  // 初始前缀和为 0 出现 1 次
//         int prefix_sum = 0;
//         int count = 0;

//         for (int num : nums) {
//             prefix_sum += num;
//             // 检查是否存在 prefix_sum - k
//             if (prefix_count.find(prefix_sum - k) != prefix_count.end()) {
//                 count += prefix_count[prefix_sum - k];
//             }
//             // 更新当前前缀和的出现次数
//             prefix_count[prefix_sum]++;
//         }

//         return count;
//     }
// };

// int main() {
//     vector<int> vec = { 1,2,3 };
//     int k = 3;
//     Solution sol;
//     cout << sol.subarraySum(vec, k);
// }
// 3. 无重复字符的最长子串
// 写不出来
// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         unordered_map<char, int> record;
//         int max_length = 0, left = 0, n = s.length();
//         for (int right = 0;right < n;right++) {
//             if (record.contains(s[right]) && record[s[right]] > left) {
//                 left = record[s[right]];
//             }
//             max_length = max(max_length, right - left + 1);
//             record[s[right]] = right;
//         }
//         return max_length;
//     }
// };

// 283. 移动零
// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
//         int slow = 0;
//         for(int fast = 0;fast < nums.size(); fast++){
//             if (nums[fast] != 0) {
//                 swap(nums[fast], nums[slow]);
//                 slow++;
//             }
//         }
//     }
// };
// void getTarget(const vector<int>& vec, const int target) {
//     auto matches = vec | views::filter([&target](const int x) { return x == target;});
//     for (auto& x : matches ) {
//         cout << x << " ";
//     }
// }
// void getTargetIndex(const vector<int>& vec, const int target) {
//     for (const auto& [index, value] : vec | views::enumerate
//         | views::filter([&](auto p) {return get<1>(p) == target;})) {
//         cout << index << " ";
//     }
// }

// 128. 最长连续序列
// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         unordered_set<int> records(nums.begin(), nums.end());
//         int result = 0;
//         for (const auto& x : records) {
//             if (records.contains(x - 1)) continue;
//             int y = x + 1;
//             while (records.contains(y)) {
//                 y++;
//             }
//             result = max(result, y - x);
//         }
//         return result;
//     }
// };
// 1. 两数之和
// 双指针法
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         multimap<int, int> records;
//         for (int i = 0;i < nums.size();i++) {
//             records.insert({ nums[i], i });
//         }
//         auto left = records.begin(), right = prev(records.end());
//         while (left != right) {
//             if (left->first + right->first < target)
//                 left++;
//             else if (left->first + right->first > target)
//                 right--;
//             else
//                 return { left->second, right->second };
//         }
//         return {};
//     }
// };
// 438. 找到字符串中所有字母异位词
// 暴力模拟 超时， ，w
// class Solution {
// public:
//     vector<int> findAnagrams(string s, string p) {
//         vector<int> result;
//         do {
//             int start = 0;
//             for (;;) {
//                 auto x = s.find(p, start);
//                 if (x == s.npos) break;
//                 else {
//                     start = x + 1;
//                     result.push_back(x);
//                 }
//             }
//         } while (next_permutation(p.begin(), p.end()));
//         return result;
//     }
// };

// 字符频率识别方法
// 看上去没问题，但是 逻辑让复杂度变为 `O(m* n)`
// class Solution {
// public:
//     vector<int> findAnagrams(string s, string p) {
//         unordered_map<char, int> pattern, window;
//         queue<char> q;
//         vector<int> result;
//         for (const char& c : p) {
//             pattern[c]++;
//         }
//         for (int i = 0;i <= s.size();i++) {
//             if (q.size() < p.length()) {
//                 window[s[i]]++;
//                 q.push(s[i]);
//             }
//             else {
//                 if (window == pattern) {
//                     result.push_back(i - p.length());
//                 }
//                 char& c = q.front();
//                 window[c]--;
//                 if(window[c] == 0) window.erase(c);
//                 window[s[i]]++;
//                 q.push(s[i]);
//                 q.pop();
//             }
//         }
//         return result;
//     }
// };
// 定长窗口
// class Solution {
// public:
//     vector<int> findAnagrams(string s, string p) {
//         vector<int> result;
//         array<int, 26> cnt_p{}, cnt_s{};
//         for (const auto& c : p) {
//             cnt_p[c - 'a']++;
//         }
//         for (int right = 0; right < s.size(); right++) {
//             cnt_s[s[right] - 'a']++;
//             int left = right - p.size() + 1;
//             if (left < 0) continue;
//             if (cnt_s == cnt_p) result.push_back(left);
//             cnt_s[s[left] - 'a']--;
//         }
//         return result;
//     }
// };
// 不定长窗口
// class Solution {
// public:
//     vector<int> findAnagrams(string s, string p) {
//         vector<int> ans;
//         int cnt[26]{}; // 统计 p 的每种字母的出现次数
//         for (char c : p) {
//             cnt[c - 'a']++;
//         }
//         int left = 0;
//         for (int right = 0; right < s.size(); right++) {
//             int c = s[right] - 'a';
//             cnt[c]--; // 右端点字母进入窗口
//             while (cnt[c] < 0) { // 字母 c 太多了
//                 cnt[s[left] - 'a']++; // 左端点字母离开窗口
//                 left++;
//             }
//             if (right - left + 1 == p.length()) { // s' 和 p 的每种字母的出现次数都相同
//                 ans.push_back(left); // s' 左端点下标加入答案
//             }
//         }
//         return ans;
//     }
// };

// 49. 字母异位词分组
// class Solution {
//     unordered_map<string, vector<string>> records;
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         for (const auto& x : strs) {
//             string temp = x;
//             sort(temp.begin(), temp.end());
//             records[temp].push_back(x);
//         }
//         vector<vector<string>> result;
//         for (const auto& [_, group] : records) {
//             result.push_back(group);
//         }
//         return result;
//     }
// };
// 49. 字母异位词分组
// 211. 添加与搜索单词 - 数据结构设计
// 哈希表遍历解决
// class WordDictionary {
//     unordered_map<int, unordered_set<string>> dict;
//     bool wordMatch(const string& word, const string& pattern) {
//         for (int i = 0;i < word.size();i++) {
//             if (pattern[i] != '.' and (word[i] != pattern[i]))
//                 return false;
//         }
//         return true;
//     }
// public:
//     WordDictionary() { }
//     void addWord(string word) {
//         int len = word.size();
//         dict[len].insert(word);
//     }

//     bool search(string word) {
//         for (const auto& w : dict[word.size()]) {
//             if (wordMatch(w, word)) return true;
//         }
//         return false;
//     }
// };
////////////////////hot 100  ///////////////////////////
// int main() {
//     WordDictionary wd;
//     wd.addWord("bad");
//     wd.addWord("dad");
//     wd.addWord("mad");
//     cout << wd.search("pad") << '\n'; // 返回 False
//     cout << wd.search("bad") << '\n'; // 返回 True
//     cout << wd.search(".ad") << '\n'; // 返回 True
//     cout << wd.search("b..") << '\n'; // 返回 True
// }
// 278. 第一个错误的版本
// class Solution {
// public:
//     bool isBadVersion(int n) {

//     }
//     int firstBadVersion(int n) {
//         vector<int> versions(n);
//         iota(versions.begin(), versions.end(), 1);
//         auto cmp = [this](int, int version) {
//             return isBadVersion(version);
//             };
//         auto it = *lower_bound(versions.begin(), versions.end(), true, cmp);
//         return it;
//     }
// };
// 355. 设计推特
// 链表实现，时间复杂度为O(n)
// struct Tweet {
//     int sender;
//     int tweetId;
// };

// class Twitter {
//     struct Follow {
//         unordered_set<int> followee; // 关注的人userId
//         unordered_set<int> follower; // 被谁关注userId
//     };
//     unordered_map<int, Follow> users;
//     list<Tweet> news;

// public:
//     Twitter() { }
//     void postTweet(int userId, int tweetId) {
//         news.push_front({ userId, tweetId });
//     }
//     vector<int> getNewsFeed(int userId) {
//         vector<int> result;
//         auto& x = users[userId].followee;
//         for (const auto& node : news) {
//             if (x.contains(node.sender) or node.sender == userId) {
//                 result.emplace_back(node.tweetId);
//                 if (result.size() == 10) break;
//             }
//         }
//         return result;
//     }

//     void follow(int followerId, int followeeId) {
//         if (followeeId == followerId) return;
//         users[followerId].followee.insert(followeeId);
//     }

//     void unfollow(int followerId, int followeeId) {
//         if (followeeId == followerId) return;
//         users[followerId].followee.erase(followeeId);
//     }
// };
// // [用时:14 m 25 s] 一个栈搭配哈希表完成
// class MinStack {
//     priority_queue<int> pq;
//     map<int, int> records;
//     stack<int> st;
// public:
//     MinStack() { }
//     void push(int val) {
//         st.push(val);
//         records[val]++;
//     }

//     void pop() {
//         auto temp = st.top();
//         if (records[temp] == 1)records.erase(temp);
//         else if (records[temp] > 1) records[temp]--;
//         st.pop();
//     }

//     int top() {
//         return st.top();
//     }

//     int getMin() {
//         return (*records.begin()).first;
//     }
// };
// int main() {
//     MinStack minStack;
//     minStack.push(-2);
//     minStack.push(0);
//     minStack.push(-3);
//     cout << minStack.getMin();   // --> 返回 - 3.
//     minStack.pop();
//     cout << minStack.top();      // --> 返回 0.
//     cout << minStack.getMin();   // --> 返回 - 2.
// }
// 146. LRU 缓存
// 错误写法 没明白哪里错了
// class LRUCache {
//     int cap;
//     unordered_map<int, int> records;
//     deque<pair<int, int>> q;
// public:
//     LRUCache(int capacity) :cap(capacity) {};

//     int get(int key) {
//         if (records.contains(key)) {
//             auto updata = q.front();
//             q.pop_front();
//             q.push_back(updata);
//             return records[key];
//         }
//         else return -1;
//     }
//     void put(int key, int value) {
//         if (!records.contains(key) && q.size() == cap) {
//             auto need_erase = q.front().first;
//             q.pop_front();
//             q.push_back({ key, value });
//             records.erase(need_erase);
//             records.insert({ key,value });
//         }
//         else if (!records.contains(key) && q.size() < cap) {
//             records.insert({ key,value });
//             q.push_back({ key,value });
//         }
//         else if (records.contains(key)) {
//             records[key] = value;
//             q.pop_front();
//             q.push_back({ key,value });
//         }
//     }
// };
// 2071. 你可以安排的最多任务数目
// class Solution {
// public:
//     int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
//         sort(tasks.begin(), tasks.end(), greater<int>());
//         sort(workers.begin(), workers.end(), greater<int>());
//         int lo = 0, hi = min(workers.size(), tasks.size());
//         while (lo < hi) {
//             int m = lo + (hi - lo + 1) / 2;
//             if (ok({ tasks.cend() - m, tasks.cend() }, { workers.begin(), workers.begin() + m }, pills, strength)) {
//                 lo = m;
//             }
//             else {
//                 hi = m - 1;
//             }
//         }
//         return lo;
//     }
// private:
//     bool ok(const vector<int> tasks, const vector<int> workers, int pills, int strength) {
//         map<int, int> ws;
//         for (const auto w : workers) ws[w]++;
//         for (const auto t : tasks) {
//             if (ws.empty()) return false;
//             auto curr = prev(ws.end())->first;
//             if (curr >= t) {
//                 if (--ws[curr] == 0) ws.erase(curr);
//             }
//             else {
//                 if (pills == 0) return false;
//                 auto it = ws.lower_bound(t - strength);
//                 if (it == ws.end()) return false;
//                 --pills;
//                 if (--ws[it->first] == 0) ws.erase(it->first);
//             }
//         }
//         return true;
//     }
// };
// 2810. 故障键盘
// 简化版本
// class Solution {
// public:
//     string finalString(string s) {
//         deque<char> str;
//         bool flag = true;
//         for (const char& c : s) {
//             if (c == 'i') {
//                 flag = !flag;
//             }
//             else if (flag) str.push_back(c);
//             else str.push_front(c);
//         }
//         return flag ? string(str.begin(), str.end()) : string(str.rbegin(), str.rend());
//     }
// };
// 原始版本
// class Solution {
// public:
//     string finalString(string s) {
//         deque<char> str;
//         bool flag = false;
//         for (int i = 0;i < s.size();i++) {
//             if (s[i] == 'i') {
//                 flag = !flag;
//                 continue;
//             }
//             if (flag) {
//                 str.push_front(s[i]);
//             }
//             else {
//                 str.push_back(s[i]);
//             }
//         }
//         string output;
//         if (flag) {
//             while(!str.empty()) {
//                 output.push_back(str.back());
//                 str.pop_back();
//             }
//         }
//         else {
//             while (!str.empty()) {
//                 output.push_back(str.front());
//                 str.pop_front();
//             }
//         }
//         return output;
//     }
// };
// class MyStack {
// public:
//     queue<int> q, p;
//     MyStack() {}
//     void push(int x) {
//         p.push(x);
//     }
//     int pop() {
//         for (int i = 0;i < p.size() - 1;i++) {
//             auto temp = p.front();
//             p.push(temp);
//             p.pop();
//         }
//         int res = p.front();
//         p.pop();
//         return res;
//     }

//     int top() {
//         for (int i = 0;i < p.size() - 1;i++) {
//             auto temp = p.front();
//             p.push(temp);
//             p.pop();
//         }
//         int res = p.front();
//         p.push(res);
//         p.pop();
//         return res;
//     }

//     bool empty() {
//         return p.size() == 0;
//     }
// };

// 3508. 设计路由器
// 模板元编程
// struct TupleHash {
//     template<typename T>
//     static void hash_combine(size_t& seed, const T& v) {
//         // 参考 boost::hash_combine
//         seed ^= hash<T>{}(v)+0x9e3779b9 + (seed << 6) + (seed >> 2);
//     }

//     template<typename Tuple, size_t Index = 0>
//     static void hash_tuple(size_t& seed, const Tuple& t) {
//         if constexpr (Index < tuple_size_v<Tuple>) {
//             hash_combine(seed, get<Index>(t));
//             hash_tuple<Tuple, Index + 1>(seed, t);
//         }
//     }

//     template<typename... Ts>
//     size_t operator()(const tuple<Ts...>& t) const {
//         size_t seed = 0;
//         hash_tuple(seed, t);
//         return seed;
//     }
// };

// class Router {
//     int memory_limit;
//     queue<tuple<int, int, int>> packet_q; // packet 队列
//     // 注：如果不想手写 TupleHash，可以用 set
//     unordered_set<tuple<int, int, int>, TupleHash> packet_set; // packet 集合
//     unordered_map<int, pair<vector<int>, int>> dest_to_timestamps; // destination -> [[timestamp], head]

// public:
//     Router(int memoryLimit) {
//         memory_limit = memoryLimit;
//     }

//     bool addPacket(int source, int destination, int timestamp) {
//         auto packet = make_tuple(source, destination, timestamp);
//         if (!packet_set.insert(packet).second) {
//             return false;
//         }
//         if (packet_q.size() == memory_limit) {  // 太多了
//             forwardPacket();
//         }
//         packet_q.push(packet); // 入队
//         dest_to_timestamps[destination].first.push_back(timestamp);
//         return true;
//     }

//     vector<int> forwardPacket() {
//         if (packet_q.empty()) {
//             return {};
//         }
//         auto packet = packet_q.front(); // 出队
//         packet_q.pop();
//         packet_set.erase(packet);
//         auto [source, destination, timestamp] = packet;
//         dest_to_timestamps[destination].second++; // 队首下标加一，模拟出队
//         return { source, destination, timestamp };
//     }

//     int getCount(int destination, int startTime, int endTime) {
//         auto& [timestamps, head] = dest_to_timestamps[destination];
//         auto left = ranges::lower_bound(timestamps.begin() + head, timestamps.end(), startTime);
//         auto right = ranges::upper_bound(timestamps.begin() + head, timestamps.end(), endTime);
//         return right - left;
//     }
// };
// 简化一下哈希函数写法
// struct MyStruct {
//     int id;
//     string name;
//     pair<int, string> info;
//     unordered_set<int> values;
// };
// struct MyStructHash {
//     template<typename T>
//     static void  hashCombine(size_t& seed, const T& v) {
//         // 参考 boost::hash_combine
//         seed ^= hash<T>(v) + 0x9e377b9 + (seed << 6) + (seed >> 2);
//     }
//     size_t operator()(const MyStruct& s) const {
//         size_t hashSeed = 0;
//         hashCombine(hashSeed, s.id);
//         hashCombine(hashSeed, s.info);
//         hashCombine(hashSeed, s.name);
//         for (const auto& x : s.values) {
//             hashCombine(hashSeed, x);
//         }
//         return hashSeed;
//     }
// };

// 自定义比较函数和哈希函数，但是会很慢，超时
// class Router {
// public:
//     struct Package {
//         int source, destination, timestamp;
//     };
//     struct PackageHash {
//         size_t operator()(const Package& p) const {
//             size_t hash1 = hash<int>{}(p.source);
//             size_t hash2 = hash<int>{}(p.destination);
//             size_t hash3 = hash<int>{}(p.timestamp);
//             return hash1 ^ (hash2 << 1) ^ (hash3 << 2);
//         }
//     };
//     struct PackageEqual {
//         bool operator()(const Package& lp, const Package& rp)  const {
//             return lp.destination == rp.destination &&
//                 lp.source == rp.source &&
//                 lp.timestamp == rp.timestamp;
//         }
//     };
//     unordered_set<Package, PackageHash, PackageEqual> records;
//     queue<Package> q;
//     int memoryLimit;
//     Router(int memoryLimit) : memoryLimit(memoryLimit) {}

//     bool addPacket(int source, int destination, int timestamp) {
//         Package temp_pkg = { source,destination,timestamp };
//         if (!records.contains(temp_pkg)) {
//             records.insert(temp_pkg);
//             q.push(temp_pkg);
//             if (records.size() > memoryLimit) {
//                 records.erase(q.front());
//                 q.pop();
//             }
//             return true;
//         }
//         return false;
//     }

//     vector<int> forwardPacket() {
//         if (q.empty()) {
//             return {};
//         }
//         auto pkg = q.front();
//         records.erase(q.front());
//         q.pop();
//         return { pkg.source, pkg.destination, pkg.timestamp };
//     }

//     int getCount(int destination, int startTime, int endTime) {
//         int count = 0;
//         for (const auto& x : records) {
//             if (x.destination == destination && x.timestamp <= endTime && x.timestamp >= startTime) {
//                 count++;
//             }
//         }
//         return count;
//     }
// };
// 933. 最近的请求次数
// n
// class RecentCounter {
// public:
//     queue<int> q;
//     RecentCounter() {}
//     int ping(int t) {
//         q.push(t);
//         while (q.front() < t - 3000) {
//             q.pop();
//         }
//         return q.size();
//     }
// };
// logn n
// class RecentCounter {
//     vector<int> records;
// public:
//     RecentCounter() { }
//     int ping(int t) {
//         records.push_back(t);
//         auto it = lower_bound(records.begin(), records.end(), t - 3000);
//         if (it != records.end()) {
//             // cout << distance(it, cur.first) + 1;
//             return distance(it, records.end());
//         }
//         return 0;
//     }
// };
// n set 是一个有序容器，但它的迭代器不支持随机访问，因此 distance 和 lower_bound 的时间复杂度是 O(n)，而不是 O(log n)。
// class RecentCounter {
//     set<int> records;
// public:
//     RecentCounter() {}
//     int ping(int t) {
//         auto cur = records.insert(t);
//         auto it = lower_bound(records.begin(), records.end(), t - 3000);
//         if (it != records.end()) {
//             // cout << distance(it, cur.first) + 1;
//             return distance(it, cur.first) + 1;
//         }
//         return 0;
//     }
// };
// 63. 不同路径 II
// class Solution {
// public:
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int m = obstacleGrid.size();
//         int n = obstacleGrid[0].size();
//         if (obstacleGrid[0][0] == 1 or obstacleGrid[m - 1][n - 1] == 1) return 0;
//         vector<vector<int>> dp(m, vector<int>(n, 0));
//         for (int i = 0;i < m && obstacleGrid[i][0] == 0;i++)
//             dp[i][0] = 1;
//         for (int j = 0;j < n && obstacleGrid[0][j] == 0;j++)
//             dp[0][j] = 1;
//         for (int i = 1; i < m;i++) {
//             for (int j = 1;j < n;j++) {
//                 if (obstacleGrid[i][j] == 1) continue;
//                 dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//             }
//         }
//         return dp[m - 1][n - 1];
//     }
// };
// int main() {
//     Solution sol;
//     vector grid(3, vector<int>(3));
//     grid = { { 0, 0, 0 }, { 0,1,0 }, { 0,0,0 } };
//     cout << sol.uniquePathsWithObstacles(grid);
// }
// 62. 不同路径
// class Solution {
// public:
//     int uniquePaths(int m, int n) {
//         vector dp(m + 1, vector<int>(n + 1, 1));
//         dp[m][n] = 0;
//         for(int i = 1; i< m; i++){
//             for (int j = 1;j < n;j++) {
//                 dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//             }
//         }
//         return dp[m - 1][n - 1];
//     }
// };
// int main(){
//     Solution sol;
//     cout << sol.uniquePaths(3,7);
// }
// 62. 不同路径
// 37. 解数独
// using vuc = vector<unordered_set<char>>;
// class Solution {
//     // int count = 0;
//     void readSudoku(vector<vector<char>>& board,
//         vuc& line, vuc& col, vuc& box) {
//         for (int i = 0;i < 9;i++) {
//             for (int j = 0;j < 9;j++) {
//                 if (board[i][j] != '.') {
//                     // count++;
//                     char num = board[i][j];
//                     int k = (i / 3) * 3 + (j / 3);
//                     line[i].insert(num);
//                     col[j].insert(num);
//                     box[k].insert(num);
//                 }
//             }
//         }
//     }
//     bool traceBack(vector<vector<char>>& board,
//         vuc& line, vuc& col, vuc& box) {
//         // if (count == 81) return;
//         for (int i = 0;i < 9;i++) {
//             for (int j = 0;j < 9;j++) {
//                 if (board[i][j] == '.') {
//                     int k = (i / 3) * 3 + (j / 3);
//                     for (char m = '1';m <= '9';m++) {
//                         if (line[i].count(m) ||
//                             col[j].count(m) ||
//                             box[k].count(m)) {
//                             continue;
//                         }
//                         line[i].insert(m);
//                         col[j].insert(m);
//                         box[k].insert(m);
//                         board[i][j] = m;
//                         if(traceBack(board, line, col, box)) return true;
//                         line[i].erase(m);
//                         col[j].erase(m);
//                         box[k].erase(m);
//                         board[i][j] = '.';
//                     }
//                     return false;
//                 }
//             }
//         }
//         return true;
//     }
// public:
//     vector<vector<char>> solveSudoku(vector<vector<char>>& board) {
//         vuc line(9), col(9), box(9);
//         readSudoku(board, line, col, box);
//         traceBack(board, line, col, box);
//         return board;
//     }
// };
// int main() {
//     vector<vector<char>> board = {
//         {'5','3','.','.','7','.','.','.','.'},
//         {'6','.','.','1','9','5','.','.','.'},
//         {'.','9','8','.','.','.','.','6','.'},
//         {'8','.','.','.','6','.','.','.','3'},
//         {'4','.','.','8','.','3','.','.','1'},
//         {'7','.','.','.','2','.','.','.','6'},
//         {'.','6','.','.','.','.','2','8','.'},
//         {'.','.','.','4','1','9','.','.','5'},
//         {'.','.','.','.','8','.','.','7','9'} };
//     Solution sol;
//     for (auto& x : sol.solveSudoku(board)) {
//         for (auto& y : x) {
//             cout << y << " ";
//         }
//         cout << endl;
//     }
// }
// 51. N 皇后
// 由于棋盘不是复制传递，节省大量时间，每一次放置皇后都判断是否正确，使得每一步都是正确的，大量剪枝
// class Solution {
// private:
//     vector<vector<string>> result;
//     void backtracking(int n, int row, vector<string>& chessboard) {
//         if (row == n) {
//             result.push_back(chessboard);
//             return;
//         }
//         for (int col = 0; col < n; col++) {
//             if (isValid(row, col, chessboard, n)) {
//                 chessboard[row][col] = 'Q';
//                 backtracking(n, row + 1, chessboard);
//                 chessboard[row][col] = '.';
//             }
//         }
//     }
//     bool isValid(int row, int col, vector<string>& chessboard, int n) {
//         for (int i = 0; i < row; i++) { // 这是⼀个剪枝
//             if (chessboard[i][col] == 'Q') {
//                 return false;
//             }
//         }
//         for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
//             if (chessboard[i][j] == 'Q') {
//                 return false;
//             }
//         }
//         for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
//             if (chessboard[i][j] == 'Q') {
//                 return false;
//             }
//         }
//         return true;
//     }
// public:
//     vector<vector<string>> solveNQueens(int n) {
//         result.clear();
//         vector<string> chessboard(n, string(n, '.'));
//         backtracking(n, 0, chessboard);
//         return result;
//     }
// }
// 剪枝，但是由于chessBoard是复制传递，消耗很多时间和空间
// class Solution {
// private:
//     vector<int> posX;
//     vector<vector<string>> result;
//     bool is_valid(vector<string>& board) {
//         int n = board.size();
//         for (int i = 0; i < n; i++) {
//             int count = 0;
//             for (int j = 0; j < n; j++) {
//                 if (board[i][j] == 'Q') {
//                     count++;
//                 }
//             }
//             if (count != 1) {
//                 return false;
//             }
//         }
//         for (int j = 0; j < n; j++) {
//             int count = 0;
//             for (int i = 0; i < n; i++) {
//                 if (board[i][j] == 'Q') {
//                     count++;
//                 }
//             }
//             if (count != 1) {
//                 return false;
//             }
//         }
//         for (int d = 0; d < 2 * n - 1; d++) {
//             int count = 0;
//             for (int i = 0; i < n; i++) {
//                 int j = d - i;
//                 if (j >= 0 && j < n && board[i][j] == 'Q') {
//                     count++;
//                 }
//             }
//             if (count > 1) {
//                 return false;
//             }
//         }
//         for (int d = 0; d < 2 * n - 1; d++) {
//             int count = 0;
//             for (int i = 0; i < n; i++) {
//                 int j = i - d + n - 1;
//                 if (j >= 0 && j < n && board[i][j] == 'Q') {
//                     count++;
//                 }
//             }
//             if (count > 1) {
//                 return false;
//             }
//         }
//         return true;
//     }
//     void traceBack(int& queens, vector<string>& chessBoard, const int width) {
//         if (queens == 0 && posX.size() == width) {
//             for (int i = 0; i < width; i++) {
//                 chessBoard[i][posX[i]] = 'Q';
//             }
//             if (is_valid(chessBoard))
//                 result.push_back(chessBoard);
//             chessBoard = vector<string>(width, string(width, '.'));
//         }
//         for (int i = 0; i < width; i++) {
//             if (find(posX.begin(), posX.end(), i) != posX.end())
//                 continue;
//             if (!posX.empty() && (abs(posX.back() - i) == 1)) // 仍然是不彻底的剪枝条件
//                 continue;
//             posX.push_back(i);
//             chessBoard[posX.size() - 1][i] = 'Q';
//             queens -= 1;
//             traceBack(queens, chessBoard, width);
//             queens += 1;
//             chessBoard[posX.size() - 1][i] = '.';
//             posX.pop_back();
//         }
//     }
// public:
//     vector<vector<string>> solveNQueens(int n) {
//         vector<string> chessBoard(n, string(n, '.'));
//         traceBack(n, chessBoard, n);
//         return result;
//     }
// };
// int main() {
//     Solution sol;
//     for (auto& x : sol.solveNQueens(4)) {
//         for (auto& y : x ) {
//             cout << y << " ";
//             cout << endl;
//         }
//         cout << "----" << endl;
//     }
// }
// 90. 子集 II
// 哈希表做法
// 491. 非递减子序列
// class Solution {
//     vector<int> path;
//     unordered_set<vector<int>> result;
//     void traceBack(int startIndex, vector<int>& nums) {
//         if (path.size() >= 2) {
//             result.insert(path);
//             if (startIndex == nums.size())
//                 return;
//         }
//         for (int i = startIndex; i < nums.size(); i++) {
//             if (!path.empty() && nums[i] < path.back()) continue;
//             path.push_back(nums[i]);
//             traceBack(i + 1, nums);
//             path.pop_back();
//         }
//     }
// public:
//     vector<vector<int>> findSubsequences(vector<int>& nums) {
//         // sort(nums.begin(), nums.end());
//         traceBack(0, nums);
//         return vector<vector<int>>(result.begin(),result.end());
//     }
// };
// 90. 子集 II
// class Solution {
//     vector<int> path;
//     vector<vector<int>> result;
//     void traceBack(vector<int>& nums, int startIndex, vector<bool>& visited) {
//         result.push_back(path);
//         for (int i = startIndex;i < nums.size();i++) {
//             if (i && nums[i] == nums[i - 1] && visited[i - 1] == false) {
//                 continue;
//             }
//             path.push_back(nums[i]);
//             visited[i] = true;
//             traceBack(nums, i + 1, visited);
//             path.pop_back();
//             visited[i] = false;
//         }
//     }
// public:
//     vector<vector<int>> subsetsWithDup(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         vector<bool> visited(nums.size(), false);
//         traceBack(nums, 0, visited);
//         return result;
//     }
// };
// 93. 复原 IP 地址
// class Solution {
//     vector<string> result;
//     bool isValid(string& segment) {
//         if (segment.back() == '.') return false;
//         stringstream ss(segment);
//         string buffer;
//         while (getline(ss, buffer, '.')) {
//             if (buffer.size() > 1 && buffer[0] == '0') return false;
//             int num = stoi(buffer);
//             if (num > 255) return false;
//         }
//         return true;
//     }
//     void traceBack(string& path, int dots, int startIndex, string& target) {
//         if (dots == 3 && (path.size() == target.size() + 3) && isValid(path)) {
//             result.emplace_back(path);
//             return;
//         }
//         if (target.size() - startIndex > (4 - dots) * 3) return;
//         for (int i = startIndex; i < target.size(); i++) {
//             path.push_back(target[i]);
//             if (dots < 3) {
//                 path += '.';
//                 traceBack(path, dots + 1, i + 1, target);
//                 path.pop_back();
//             }
//             traceBack(path, dots, i + 1, target);
//             path.pop_back();
//         }
//     }
// public:
//     vector<string> restoreIpAddresses(string s) {
//         if (s.size() < 4 || s.size() > 12) return result;
//         string path = "";
//         traceBack(path, 0, 0, s);
//         return result;
//     }
// };
// 组合总和
// class Solution {
//     vector<int> path;
//     vector<vector<int>> result;
//     void traceBack(int& curSum, int& target, int startIndex, vector<int>& candidates) {
//         if (curSum == target) {
//             result.push_back(path);
//             return;
//         }
//         if (curSum > target) return;
//         for (int i = startIndex; i < candidates.size(); i++) {
//             path.push_back(candidates[i]);
//             curSum += candidates[i];
//             traceBack(curSum, target, i, candidates);
//             path.pop_back();
//             curSum -= candidates[i];
//         }
//     }
// public:
//     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//         int curSum = 0;
//         traceBack(curSum, target, 0, candidates);
//         return result;
//     }
// };
// 46. 全排列 II
// class Solution {
//     vector<int> path;
//     vector<vector<int>> result;
//     void traceBack(vector<bool>& used, vector<int>& nums) {
//         if (path.size() == nums.size()) {
//             result.push_back(path);
//             return;
//         }
//         for (int i = 0;i < nums.size(); i++) {
//             if (i && nums[i] == nums[i - 1] && used[i - 1/* 为什么是i-1而不是i？因为i当前数字能否使用取决于相同的前一个数字是否使用过 */] == false) {
//                 continue;
//             }
//             if (used[i] == false) {
//                 used[i] = true;
//                 path.push_back(nums[i]);
//                 traceBack(used, nums);
//                 path.pop_back();
//                 used[i] = false;
//             }
//         }
//     }
//     public:
//     vector<vector<int>> permuteUnique(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         vector<bool> used(nums.size(), false);
//         traceBack(used, nums);
//         return result;
//     }
// };
// 77. 组合
// 组合优化
// class Solution {
//     int n, k;
//     vector<int> path;
//     vector<vector<int>> result;
//     void traceBack(int startIndex, int level) {
//         if (level == k) {
//             result.push_back(path);
//             return;
//         }
//         for (int i = startIndex; i <= n - (k - path.size()) + 1;i++) {
//             path.push_back(i);
//             traceBack(i + 1, level + 1);
//             path.pop_back();
//         }
//     }
// public:
//     vector<vector<int>> combine(int nnn, int kkk) {
//         k = kkk;
//         n = nnn;
//         traceBack(1, 0);
//         return result;
//     }
// };
// 常规做法
// class Solution {
//     int n, k;
//     vector<int> path;
//     vector<vector<int>> result;
//     void traceBack(int startIndex, int level) {
//         if (level == k) {
//             result.push_back(path);
//             return;
//         }
//         for (int i = startIndex; i <= n;i++) {
//             path.push_back(i);
//             traceBack(i + 1, level + 1);
//             path.pop_back();
//         }
//     }
// public:
//     vector<vector<int>> combine(int nnn, int kkk) {
//         k = kkk;
//         n = nnn;
//         traceBack(1, 0);
//         return result;
//     }
// };
// LCR 079. 子集
// class Solution {
//     vector<int> path;
//     vector<vector<int>> result = {{}};
//     void traceBack(int startIndex, vector<int>& nums) {
//         if (startIndex == nums.size()) {
//             return;
//         }
//         for (int i = startIndex; i < nums.size(); i++) {
//             path.push_back(nums[i]);
//             result.push_back(path);
//             traceBack(i + 1, nums);
//             path.pop_back();
//         }
//     }
// public:
//     vector<vector<int>> subsets(vector<int>& nums) {
//         traceBack(0, nums);
//         return result;
//     }
// };
// int main(){
//     vector<int> test = { 1,2,3 };
//     Solution sol;
//     for (auto x : sol.subsets(test)){
//         for (auto& y : x ) {
//             cout << y << " ";
//         }
//     }
// }
// 131. 分割回文串
// 00 : 30 : 17 回溯模板题，需要注意分割字符串的方法
// class Solution {
//     vector<vector<string>> ans;
//     vector<string> path;
//     bool is_valid(const string& str) {
//         size_t start = 0, end = str.size() - 1;
//         while (start < end) {
//             if (str[start++] != str[end--]) return false;
//         }
//         return true;
//     }
//     void traceback(const string& s, int startIndex) {
//         if (startIndex >= s.size()) {
//             ans.push_back(path);
//             return;
//         }
//         for (int i = startIndex; i < s.size();i++) {
//             string str = s.substr(startIndex, i - startIndex);
//             if (is_valid(str)) path.push_back(str);
//             else continue;
//             traceback(s, i + 1);
//             path.pop_back();
//         }
//     }

// public:
//     vector<vector<string>> partition(string s) {
//         traceback(s, 0);
//         return ans;
//     }
// };
// 40. 组合总和 II
// class Solution {
//     vector<int> path;
//     vector<vector<int>> ans;
//     void dfs(unordered_map<int,bool>& records, vector<int>& candidates, int& target, int curSum, int startIndex) {
//         if (curSum > target) return;
//         if (curSum + candidates[startIndex] > target) return;
//         if (curSum == target) {
//             ans.push_back(path);
//             return;
//         }
//         for (int i = startIndex; i < candidates.size() && records[candidates[i]] == true;i++) {
//             path.push_back(candidates[i]);
//             curSum += candidates[i];
//             records[candidates[i]] = false;
//             dfs(records, candidates, target, curSum, startIndex + 1);
//             records[candidates[i]] = true;
//             curSum -= candidates[i];
//             path.pop_back();
//         }
//     }
// public:
//     vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//         unordered_map<int, bool> records;
//         for (auto& x : candidates) {
//             records[x] = false;
//         }
//         dfs(records, candidates, target, 0, 0);
//         return ans;
//     }
// };
// 39. 组合总和
// class Solution {
//     vector<vector<int>> ans;
//     vector<int> path;
//     // int curSum = 0;
//     void traceback(vector<int>& nums, int curSum, int& target, int startIndex) {
//         if (target == curSum) {
//             ans.push_back(path);
//             return;
//         }
//         if (curSum > target) return;
//         // if (target - curSum > nums[startIndex]) return;
//         for (int i = startIndex;i < nums.size() && target - curSum >= nums[startIndex];i++) {
//             path.push_back(nums[i]);
//             curSum += nums[i];
//             traceback(nums, curSum, target, i);
//             path.pop_back();
//             curSum -= nums[i];
//         }
//     }
// public:
//     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//         ranges::sort(candidates);
//         traceback(candidates, 0, target, 0);
//         return ans;
//     }
// };
// 17. 电话号码的字母组合
// class Solution {
//     map<char, string> mapping = {
//         {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
//         {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
//         {'8', "tuv"}, {'9', "wxyz"}
//     };
//     string curString;
//     vector<string> ans;
//     void traceback(int index/* 键 */, string digits) {
//         if (digits.size() == index) {
//             ans.push_back(curString);
//             return;
//         }
//         for (int i = 0; i < mapping[digits[index]].size(); i++) {
//             curString.push_back(mapping[digits[index]][i]);
//             traceback(index + 1, digits);
//             curString.pop_back();
//         }
//     }
// public:
//     vector<string> letterCombinations(string digits) {
//         if (digits.size() == 0) return {};
//         traceback(0, digits);
//         return ans;
//     }
// };
// 216. 组合总和 III
// class Solution {
//     vector<int> path;
//     vector<vector<int>> ans;
//     void traceback(int& n, int& k, int curSum, int curLen, int curStart) {
//         if (curLen == k && curSum == n) {
//             ans.push_back(path);
//             return;
//         }
//         if (curLen == k && curSum != n) return;
//         if (curSum > n && curLen <= k) return;
//         for (int i = curStart; i <= 9;i++) {
//             curSum += i;
//             path.push_back(i);
//             traceback(n, k, curSum, curLen + 1, i + 1);
//             curSum -= i;
//             path.pop_back();
//         }
//     }
// public:
//     vector<vector<int>> combinationSum3(int k, int n) {
//         traceback(n, k, 0, 0, 1);
//         return ans;
//     }
// };
// 77. 组合
// 剪枝优化
// class Solution {
// private:
//     vector<vector<int>> result;
//     vector<int> path;
//     void backtracking(int n, int k, int startIndex) {
//         if (path.size() == k) {
//             result.push_back(path);
//             return;
//         }
//         for (int i = startIndex; i <= n - (k - path.size()) + 1; i++) { // 优化的地?
//             path.push_back(i); // 处理节点
//             backtracking(n, k, i + 1);
//             path.pop_back(); // 回溯，撤销处理的节点
//         }
//     }
// public:
//     vector<vector<int>> combine(int n, int k) {
//         backtracking(n, k, 1);
//         return result;
//     }
// };
// class Solution {
//     vector<int> path;
//     vector<vector<int>> ans;
//     void dfs(int n, int k, int startIndex) { // 题目条件，组合数达到k个停止递归
//         if (path.size() == k) {
//             ans.push_back(path);
//             return;
//         }
//         for (int i = startIndex; i <= n;i++) {
//             path.push_back(i);
//             dfs(n, k, i/* 注意这里不要写startIndex */ + 1);
//             path.pop_back();
//         }
//     }
// public:
//     vector<vector<int>> combine(int n, int k) {
//         dfs(n, k, 1/* 题目要求从1开始 */);
//         return ans;
//     }
// };
// 17. 电话号码的字母组合
// class Solution {
//     map<char, string> mapping = {
//         {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
//     };

//     vector<string> ans;
//     string current;

//     void dfs(int index, string digits) {
//         if (mapping.size() == index) {
//             return;
//         }
//         for (int i = 0; i < mapping[digits[index]].size(); i++) {
//             current.push_back(mapping[digits[index]][i]);
//             dfs(index + 1, digits);
//             current.pop_back();
//         }
//     }
// public:
//     vector<string> letterCombinations(string digits) {
//         if (digits.size() == 0) {
//             return ans;
//         }
//         dfs(0, digits);
//         return ans;
//     }
// };
// 递归做法
// class Solution {
// public:
//     int combinationSum4(vector<int>& nums, int target) {
//         vector<int> memo(target + 1, -1);
//         auto dfs = [&](this auto&& dfs, int index) {
//             if (index == 0) return 1;
//             int& res = memo[index];
//             if (res != -1)  return res;
//             res = 0;
//             for (int j = 0; j < nums.size(); j++) {
//                     res += dfs(j);
//             }
//             return res;
//             };
//         return dfs(target);
//     }
// };
// 欧拉筛法
// vector<int> euler(int a, int b) {
//     vector<int> primes, result;
//     if (a < 2) a = 2;
//     if (b < 2) return primes;
//     vector<bool> isPrime(b + 1, true);
//     isPrime[0] = isPrime[1] = false;
//     for (int i = 2; i <= b; i++) {
//         if (isPrime[i])
//             primes.push_back(i);
//         for (int j = 0; j < primes.size() && primes[j] * i <= b; j++) {
//             isPrime[primes[j] * i] = false;
//             if (i % primes[j] == 0) break;
//         }
//     }
//     for (auto& x : primes ) {
//         if (a <= x && x <= b)
//             result.push_back(x);
//     }
//     return result;
// }
// 14. 最长公共前缀
// 寻找，不断替换方法
// class Solution {
// public:
//     string longestCommonPrefix(vector<string>& strs) {
//         string res = strs.empty() ? "" : strs[0];
//         for (string s : strs)
//             while (s.find(res) != 0) res = res.substr(0, res.length() - 1);
//         return res;
//     }
// };
// 排序方法
// class Solution {
// public:
//     string longestCommonPrefix(vector<string>& strs) {
//         sort(strs.begin(), strs.end());
//         string ans;
//         for (int i = 0, j = 0;i < strs[0].size() && j < strs.back().size();i++, j++) {
//             if (strs[0][i] == strs.back()[j])
//                 ans += strs[0][i];
//             else return ans;
//         }
//         return ans;
//     }
// };
// int main() {
//     vector<string> strs = { "flower","flow","flight" };
//     Solution sol;
//     cout << sol.longestCommonPrefix(strs);
// }
// 17. 电话号码的字母组合

// 1372. 二叉树中的最长交错路径

// 988. 从叶结点开始的最小字符串
// class Solution {
//     void dfs(TreeNode* node, string& path, string& target) {
//         if (!node) return;
//         path = char('a' + node->val) + path;
//         if (!node->left && !node->right) {
//             if (target.empty() || path < target) {
//                 target = path;
//             }
//         }
//         dfs(node->left, path, target);
//         dfs(node->right, path, target);
//         path.erase(0,1);
//     }
// public:
//     string smallestFromLeaf(TreeNode* root) {
//         if (!root) return "";
//         string path, target;
//         dfs(root, path, target);
//         return target;
//     }
// };
// 字符串尾部添加，需要reverse并且不能引用传递，费时间
// class Solution {
//     void dfs(TreeNode* node, string path, string& target) {
//         if (!node) return;
//         path.append(1,(char)('a' + node->val));
//         if (!node->left && !node->right) {
//             reverse(path.begin(), path.end());
//             if (target.empty()) target = path;
//             else if (target > path) {
//                 target = path;
//             }
//         }
//         dfs(node->left, path, target);
//         dfs(node->right, path, target);
//         path.pop_back();
//     }
// public:
//     string smallestFromLeaf(TreeNode* root) {
//         if (!root) return "";
//         string path, target;
//         dfs(root, path, target);
//         return target;
//     }
// };
// 1315. 祖父节点值为偶数的节点和
// 简洁符合直觉的思路
// class Solution {
//     int ans = 0;
//     void dfs(TreeNode* grand, TreeNode* father, TreeNode* son) {
//         if (!son) return;
//         if (grand != nullptr/* 判空放前面 */ && grand->val % 2 == 0)
//             ans += son->val;
//         dfs(father, son, son->left);
//         dfs(father, son, son->right);
//     }
// public:
//     int sumEvenGrandparent(TreeNode* root) {
//         dfs(nullptr, nullptr, root);
//         return ans;
//     }
// };
// 1457. 二叉树中的伪回文路径
// class Solution {
//     int count = 0;
//     unordered_map<int, int> records;
//     bool canFormPalindrome(const unordered_map<int, int>& records) {
//         int oddCount = 0;
//         for (const auto& pair : records) {
//             if (pair.second % 2 != 0) {
//                 oddCount++;
//             }
//         }
//         return oddCount <= 1;
//     }
//     void dfs(TreeNode* node, int& count, unordered_map<int, int>& records) {
//         records[node->val]++;
//         if (!node->left && !node->right) {
//             if (canFormPalindrome(records))
//                 count++;
//         }
//         if (node->left) dfs(node->left, count, records);
//         if (node->right) dfs(node->right, count, records);
//         records[node->val]--;
//     }
// public:
//     int pseudoPalindromicPaths(TreeNode* root) {
//         if (!root) return 0;
//         dfs(root, count, records);
//         return count;
//     }
// };
// dfs+哈希表还用值传递，非常慢的解法
// class Solution {
//     int count = 0;
//     unordered_map<int, int> records;
//     bool canFormPalindrome(const unordered_map<int, int>& records) {
//         int oddCount = 0;
//         for (const auto& pair : records) {
//             if (pair.second % 2 != 0) {
//                 oddCount++;
//             }
//         }
//         return oddCount <= 1;
//     }
//     void dfs(TreeNode* node, int& count, unordered_map<int, int> records) {
//         records[node->val]++;
//         if (!node->left && !node->right) {
//             if (canFormPalindrome(records)) count++;
//             return;
//         }
//         if (node->left) dfs(node->left, count, records);
//         if (node->right) dfs(node->right, count, records);
//     }
// public:
//     int pseudoPalindromicPaths(TreeNode* root) {
//         if (!root) return 0;
//         dfs(root, count, records);
//         return count;
//     }
// };
// 1448. 统计二叉树中好节点的数目
// 递归分治思想，一棵二叉树中好节点数量=左子树好节点数量+右子树的
// class Solution {
// public:
//     int goodNodes(TreeNode* root, int pathMax = INT_MIN) {
//         if (!root) return 0;
//         if (root->val >= pathMax) {
//             pathMax = root->val;
//         }
//         int left = goodNodes(root->left, pathMax);// 因为左右子树统计结果直接相加，所以前年一定要有判空处理
//         int right = goodNodes(root->right, pathMax);
//         return left + right + (root->val >= pathMax);
//     }
// };
// dfs做法，递归更改外部变量型，dfs函数中没有做判空处理，只能在分支位置做
// class Solution {
//     void dfs(TreeNode* node, int pathMax, int& goodNodes) {
//         if (node->val >= pathMax) {
//             pathMax = node->val;
//             goodNodes++;
//         }
//         if (node->left) dfs(node->left, pathMax ,goodNodes);
//         if (node->right) dfs(node->right, pathMax, goodNodes);
//     }
// public:
//     int goodNodes(TreeNode* root) {
//         if (!root) return 0;
//         int goodNodes = 0, pathMax = root->val;
//         dfs(root, pathMax, goodNodes);
//         return goodNodes;
//     }
// };
// 199. 二叉树的右视图
// dfs方法
// class Solution {
//     void dfs(TreeNode* node, int curLevel, int& maxLevel, vector<int>& ans) {
//         if (!node) return;
//         if (curLevel > maxLevel) {
//             maxLevel = curLevel;
//             ans.push_back(node->val);
//         }
//         dfs(node->right, curLevel + 1, maxLevel, ans);
//         dfs(node->left, curLevel + 1, maxLevel, ans);
//     }
// public:
//     vector<int> rightSideView(TreeNode* root) {
//         vector<int> ans;
//         int cur = 1, max = 0;
//         dfs(root, cur, max, ans);
//         return ans;
//     }
// };
// bfs方法,笨方法 bfs，每次取每层最后一个
// class Solution {
// public:
//     vector<int> rightSideView(TreeNode* root) {
//         if (!root) return {};
//         vector<int> ans;
//         queue<TreeNode*> cur, next;
//         cur.push(root);
//         do {
//             while (!cur.empty()) {
//                 TreeNode* node = cur.front();
//                 if (node->left) next.push(node->left);
//                 if (node->right) next.push(node->right);
//                 cur.pop();
//             }
//             ans.push_back(cur.back()->val);
//             cur = next;
//             while (!next.empty()) {
//                 next.pop();
//             }
//         } while (!cur.empty());
//         return ans;
//     }
// };
// 129. 求根节点到叶节点数字之和
// dfs有返回值
// class Solution {
// public:
//     int sumNumbers(TreeNode* root, int curSum = 0) {
//         if (!root) return 0;
//         curSum = curSum * 10 + root->val;
//         if (!root->left && !root->right)
//             return curSum;
//         return sumNumbers(root->left, curSum) + sumNumbers(root->right, curSum);
//     }
// };
// dfs无法返回值
// class Solution {
//     void dfs(TreeNode* root, int sum, int& ans) {
//         if (!root) return;
//         sum = sum * 10 + root->val;
//         if (!root->left && !root->right) {
//             ans += sum;
//         }
//         dfs(root->left, sum, ans);
//         dfs(root->right, sum, ans);
//         // return ans + left + right;
//     }
// public:
//     int sumNumbers(TreeNode* root) {
//         int ans = 0;
//         dfs(root, 0, ans);
//         return ans;
//     }
// };
// 112. 路径总和
// class Solution {
// public:
//     bool hasPathSum(TreeNode* root, int& targetSum) {
//         if (!root) return false;
//         targetSum -= root->val;
//         if (!root->left && !root->right && targetSum == 0)
//             return true;
//         bool left = hasPathSum(root->left, targetSum);
//         bool right = hasPathSum(root->right, targetSum);
//         targetSum += root->val;
//         return false;
//     }
// };
// 235. 二叉搜索树的最近公共祖先
// class Solution {
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         int x = root->val;
//         if (x < p->val && x < q->val) {
//             return lowestCommonAncestor(root->right, p, q);
//         }
//         if (x > p->val && x > q->val) {
//             return lowestCommonAncestor(root->left, p, q);
//         }
//         return root;
//     }
// };
// 236. 二叉树的最近公共祖先
// class Solution {
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         if (!root /* 子递归中访问到空节点时用的 */ && root == q && root == p/* 防止p和q在同一条路径上 */) return root;
//         TreeNode* left =  lowestCommonAncestor(root->left, p, q);
//         TreeNode* right = lowestCommonAncestor(root->right, p, q);
//         if (left && right) return root;
//         return left ? left : right;//这一条return是给子递归用的，最后的答案由上面的if语句返回，因为题目保证p，q存在
//     }
// };
// class Solution {
// public:
//     void dfs(TreeNode* node, TreeNode* to_find, vector<TreeNode*>& routine) {
//         if (!node) return;// root
//         routine.push_back(node);
//         if (node->val == to_find->val) return;
//         if (node->left)
//             dfs(node->left, to_find, routine);
//         if (node->right)
//             dfs(node->right, to_find, routine);
//         if (routine.back()->val != to_find->val) routine.pop_back();
//     }
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         vector<TreeNode*> routine_p, routine_q;
//         dfs(root, p, routine_p);
//         dfs(root, q, routine_q);
//         TreeNode* accent = nullptr;
//         int i = 0;
//         while (i < routine_p.size() && i < routine_q.size() && routine_p[i] == routine_q[i]) {
//             accent = routine_p[i];
//             i++;
//         }
//         return accent;
//     }
// };
// 560. 和为 K 的子数组
// class Solution {
//     int count = 0;
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         int temp = 0;
//         unordered_map<int, int> mapping = {{0,1}};
//         for (auto& elem : nums) {
//             temp += elem;
//             if (mapping.contains(temp - k))
//                 count += mapping[temp - k];
//             mapping[temp]++;
//         }
//         return count;
//     }
// };
// 437. 路径总和 III
// 前缀和哈希表做法
// class Solution {
// public:
//     int pathSum(TreeNode* root, int targetSum) {
//         int ans = 0;
//         unordered_map<long long, int > mapping = { {0,1} };
//         auto dfs = [&](this auto&& dfs, TreeNode* root, long long preSum) -> void {
//             if (!root) return;
//             preSum += root->val;
//             ans += mapping.contains(preSum - targetSum) ? mapping[preSum - targetSum] : 0;
//             mapping[preSum]++;
//             dfs(root->left, preSum);
//             dfs(root->right, preSum);
//             mapping[preSum]--;
//             };
//         dfs(root, 0);
//         return ans;
//     }
// };
// class Solution {
// public:
//     int pathSum(TreeNode* root, int targetSum) {

//     }
// };
// 双重递归
// class Solution {
//     int count = 0;
// public:
//     void dfs(TreeNode* root, long long sum) {
//         if (!root) return;
//         sum -= root->val;
//         if (sum == 0)  count++;
//         dfs(root->left, sum);
//         dfs(root->right, sum);
//     }
//     int pathSum(TreeNode* root, int targetSum) {
//         if (!root) return;
//         dfs(root, (long long)targetSum); // 对当前节点递归
//         pathSum(root->left, targetSum); // 对当前节点左右节点递归
//         pathSum(root->right, targetSum);
//         return count;
//     }
// };
// 113. 路径总和 II
// 使用回溯写法
// class Solution {
//     void dfs(TreeNode* node, vector<int>& path, vector<vector<int>>& ans, int& targetSum, int& curSum) {
//         curSum += node->val;
//         path.push_back(node->val);
//         if (curSum == targetSum /* 如果不加后面内容就是从任意节点开始判断，到任意节点结束 */&& !node->left && !node->right) {
//             ans.push_back(path);
//         }
//         if(node->left) dfs(node->left, path, ans, targetSum, curSum);
//         if (node->right) dfs(node->right, path, ans, targetSum, curSum);
//         curSum -= node->val;
//         path.pop_back();
//     }
// public:
//     vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
//         if (!root) return {};
//         vector<int> path;
//         vector<vector<int>> ans;
//         int curSum = 0;
//         dfs(root, path, ans, targetSum, curSum);
//         return ans;
//     }
// };
// 和257差不多的思路，注意听怕判空和特殊情况下的处理，不使用回溯写法
// class Solution {
// public:
//     void dfs(TreeNode* root, vector<vector<int>>& ans, int path_sum, int targetSum, vector<int> routine) {
//         routine.push_back(root->val);
//         path_sum += root->val;
//         if (!root->left && !root->right) {
//             if (path_sum == targetSum)
//                 ans.push_back(routine);
//             return;
//         }
//         if (root->left) {
//             dfs(root->left, ans, path_sum, targetSum, routine);
//         }
//         if (root->right) {
//             dfs(root->right, ans, path_sum, targetSum, routine);
//         }
//     }
//     vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
//         if (!root) return {};
//         vector<vector<int>> ans;
//         vector<int> routine;
//         dfs(root, ans, 0, targetSum, routine);
//         return ans;
//     }
// };
// 257. 二叉树的所有路径
// bfs写法
// class Solution {
// public:
//     vector<string> binaryTreePaths(TreeNode* root) {
//         if (!root) return;
//         queue<TreeNode*> q;
//         q.push(root);
//         while (!q.empty()) {
//             TreeNode* node = q.front();

//         }
//     }
// };
// dfs写法
// class Solution {
// public:
//     void dfs(TreeNode* root, vector<string>& path, string routine) {
//         if (!root) return;
//         routine += to_string(root->val) + "->";
//         if (root->left == nullptr && root->right == nullptr) {
//             auto it = routine.find_last_of("->");
//             routine.erase(it-1);
//             path.emplace_back(routine);
//             return;
//         }
//         if (root->left != nullptr) {
//             dfs(root->left, path, routine);
//         }
//         if (root->right != nullptr) {
//             dfs(root->right, path, routine);
//         }
//     }
//     vector<string> binaryTreePaths(TreeNode* root) {
//         vector<string> path;
//         string routine;
//         dfs(root, path, routine);
//         return path;
//     }
// };
// class Solution {
// public:
//     int dfs(TreeNode* root, int level) {

//     }
//     int minDepth(TreeNode* root) {

//     }
// };
// 104. 二叉树的最大深度
// class Solution {
// public:
//     int dfs(TreeNode* root, int level) {
//         level++;
//         if (root == nullptr) {
//             level--;
//             return level;
//         }
//         return max(dfs(root->left, level), dfs(root->right, level));
//     }
//     int maxDepth(TreeNode* root) {
//         return dfs(root, 1);
//     }
// };
// 2244. 完成所有任务需要的最少轮数
// 不使用哈希表
// class Solution {
// public:
//     int minimumRounds(vector<int>& tasks) {
//         tasks.push_back(INT_MAX);
//         ranges::sort(tasks);
//         int pre_index = 0, rounds = 0;
//         for (int i = 1; i < tasks.size(); i++) {
//             if (tasks[i] != tasks[i - 1]) {
//                 int distance = i - pre_index;
//                 if (distance == 1) return -1;
//                 else if (distance % 3 == 0) rounds += distance / 3;
//                 else rounds += (distance / 3) + 1;
//                 pre_index = i;
//             }
//         }
//         return rounds;
//     }
// };
// 无优化版本
// class Solution {
// public:
//     inline int calcu(int amount) {
//         if (amount % 3 == 0) return amount / 3;
//         else return (amount / 3) + 1;
//     }
//     int minimumRounds(vector<int>& tasks) {
//         map<int, int> mapping;
//         int rounds = 0;
//         for (auto& x : tasks) {
//             mapping[x]++;
//         }
//         for (auto& [_, freq] : mapping) {
//             if (freq == 1) return -1;
//             else rounds += calcu(freq);
//         }
//         return rounds;
//     }
// };

// class Solution {
// public:
//     vector<int> minSubsequence(vector<int>& nums) {
//         ranges::sort(nums);
//         int sum = reduce(nums.begin(), nums.end());
//         vector<int> ans;
//         int sequenceSum = 0;
//         for (int i = nums.size() - 1;i >= 0;i--) {
//             ans.push_back(nums[i]);
//             sequenceSum += nums[i];
//             if (sequenceSum > sum / 2) return ans;
//         }
//         return ans;
//     }
// };
// 860. 柠檬水找零
// class Solution {
// public:
//     bool lemonadeChange(vector<int>& bills) {
//         int five = 0, ten = 0, twenty = 0;
//         for (int& bill : bills) {
//             if (bill == 5) five++;
//             if (bill == 10) {
//                 if (five == 0)return false;
//                 else five--;
//                 ten++;
//             }
//             if (bill == 20) {
//                 if (ten != 0 && five != 0) {
//                     ten--, five--, twenty++;
//                     continue;
//                 }
//                 if (five >= 3) {
//                     five -= 3;
//                     twenty++;
//                     continue;
//                 }
//                 else return false;
//             }
//         }
//         return true;
//     }
// };

// 写成lambda稍微快了一点
// 1980. 找出不同的二进制字符串
// class Solution {
// public:
//     string findDifferentBinaryString(vector<string>& nums) {
//         unordered_set<string> records(nums.begin(), nums.end());
//         string result;
//         auto f = [&](this auto&& f,string binstr, int size) {
//             if (!result.empty()) return;
//             if (binstr.size() > size) return;
//             if (binstr.size() == size && !records.contains(binstr)) {
//                 result = binstr;
//                 return;
//             }
//             else {
//                 f(binstr + "0", size);
//                 f(binstr + "1", size);
//             }
//             };
//         int size = nums[0].size();
//         f("", size);
//         return result;
//     }
// };
// 些许优化版本通过
// class Solution {
// public:
//     void dfs(unordered_set<string>& records, string binstr, int size, string& result) {
//         if (!result.empty()) return;
//         if (binstr.size() >= size && !records.contains(binstr)) {
//             result = binstr;
//             return;
//         }
//         if (binstr.size() >= size) return;
//         else {
//             dfs(records, binstr + "0", size, result);
//             dfs(records, binstr + "1", size, result);
//         }
//     }
//     string findDifferentBinaryString(vector<string>& nums) {
//         int size = nums[0].size();
//         string result;
//         unordered_set<string> records;
//         for (auto& x: nums ) {
//             records.insert(x);
//         }
//         dfs(records, "", size, result);
//         return result;
//     }
// };
// 暴力回溯+无记忆化搜索TLE
// class Solution {
// public:
//     void dfs(unordered_set<string>& records, string binstr ,int size) {
//         if (binstr.size() >= size) {
//             records.insert(binstr);
//             return;
//         }
//         else {
//             dfs(records, binstr + "0", size);
//             dfs(records, binstr + "1", size);
//         }
//     }
//     string findDifferentBinaryString(vector<string>& nums) {
//         int size = nums[0].size();
//         unordered_set<string> records;
//         dfs(records, "", size);
//         for (string& x : nums) {
//             if (records.contains(x))
//                 records.erase(x);
//         }
//         return *records.begin();
//     }
// };
// 3457. 吃披萨
// 写不出来，没看题解
// 3397. 执行操作后不同元素的最大数量
// 不会写看题解
// class Solution {
// public:
//     int maxDistinctElements(vector<int>& nums, int K) {
//         ios::sync_with_stdio(false);
//         cin.tie(nullptr);
//         cout.tie(nullptr);
//         int n = nums.size(), pre = INT_MIN, ans = 0;
//         if (n <= 2 * K + 1) return n;
//         for (int& x : nums) {
//             x = clamp(pre + 1, x - K, x + K);
//             if (x > pre) {
//                 ans++;
//                 pre = x;
//             }
//         }
//         return ans;
//     }
// };
// 暴力回溯+记忆化搜索
// class Solution {
//     const int mod = 1e9 + 7;
// public:
//     int countGoodStrings(int low, int high, int zero, int one) {
//         vector<int> memo(high + 1, -1);
//         auto f = [&](this auto&& f, int length) -> int {
//             if (length > high) return 0;
//             if (memo[length] != -1) return memo[length];
//             int res = 0;
//             if (length <= high && length >= low) res = 1;
//             res += (f(length + zero) + f(length + one)) % mod;
//             memo[length] = res;
//             };
//         return f(0);
//     }
// };
// 动态规划
// class Solution {
//     const int mod = 1e9 + 7;
// public:
//     int countGoodStrings(int low, int high, int zero, int one) {
//         vector<int> dp(high + 1, 0);
//         dp[0] = 1;
//         for (int i = 1; i <= high; i++) {
//             if (i >= zero)
//                 dp[i] += dp[i - zero];
//             if (i >= one)
//                 dp[i] += dp[i - one];
//         }
//         int count = 0;
//         for (auto& x: dp ) {
//             count = (count + x) % mod;
//         }
//         return count;
//     }
// };
// 122. 买卖股票的最佳时机 II
// 动态规划
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         // 数组意义是第i天在j种持有股票的状态下现金数，求dp[n-1][0]最后一天未持有股票和持有股票两种情况下谁的现金多
//         int n = prices.size();
//         if (n < 2) return 0;
//         vector<array<int, 2>> dp(n + 1);
//         // 初始化，第一天只有两种状态，由于递推方程是一个2*n的矩阵，并且从左向右遍历一次遍历一列，每次递推需要当前递推位置前一个位置的状态，不许知道第一列的信息才能递推
//         dp[0][0] = 0;dp[0][1] = -prices[0];
//         for (int i = 1; i < n; i++) {
//             // 递推方程：第i天有股票是因为昨天也有并且今天没有出手或者昨天没有但是今天4入手 dp[i][1] = max(dp[i-1][0] - prices[i], dp[i-1][1]);
//             // dp[i][0] = max(dp[i-1][1] + prices[i], dp[i-1][0]);第i天没有股票同理
//             dp[i][1] = max(dp[i - 1][0] - prices[i], dp[i - 1][1]);
//             dp[i][0] = max(dp[i - 1][1] + prices[i], dp[i - 1][0]);
//         }
//         return dp[n - 1][0];
//     }
// };
// 自己写一遍 回溯
// class Solution {
// public:
//     int dfs(vector<int>& prices, vector<array<int, 2>>& memo, int index, bool is_hold) {
//         // 第一天不可能在持有股票的同时获取最大利润，有股票就付了钱，付了钱的情况不会是最大利润，返回INT_MIN表示这个结果是无效的
//         if (index < 0) return is_hold == true ? INT_MIN : 0;
//         int& res = memo[index][is_hold];
//         if (res != -1) return res;
//         if (is_hold == true)
//             return res =  max(dfs(prices, memo, index - 1, true), dfs(prices, memo, index - 1, false) - prices[index]);
//         else
//             return res = max(dfs(prices, memo, index - 1, false), dfs(prices, memo, index - 1, true) + prices[index]);
//     }

//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         vector<array<int, 2>> memo(n, { -1,-1 });;
//         return dfs(prices, memo, n - 1, false);
//     }
// };
// 回溯算法+记忆化递归
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         vector<array<int, 2>> memo(n, { -1, -1 }); // -1 表示还没有计算过
//         auto dfs = [&](this auto&& dfs, int i, bool hold) -> int {
//             if (i < 0) {
//                 return hold ? INT_MIN : 0;
//             }
//             int& res = memo[i][hold]; // 注意这里是引用
//             if (res != -1) {
//                 return res; // 之前计算过
//             }
//             if (hold) {
//                 return res = max(dfs(i - 1, true), dfs(i - 1, false) - prices[i]);
//             }
//             return res = max(dfs(i - 1, false), dfs(i - 1, true) + prices[i]);
//             };
//         return dfs(n - 1, false);
//     }
// };
// class Solution {
// public:
//     int dfs(vector<int>& prices, vector<array<int,2>>& memo, int index, bool is_hold) {
//         if (index < 0) return is_hold ? -1e9 : 0;
//         int& res = memo[index][is_hold];
//         if (res != -1) return res;
//         if (is_hold) {
//             return res = max(dfs(prices, memo, index - 1, true), dfs(prices, memo, index - 1, false) - prices[index]);
//         }
//         return res = max(dfs(prices, memo, index - 1, false), dfs(prices, memo, index - 1, true) + prices[index]);
//     }
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         vector<array<int, 2>> memo(n, { -1,-1 });
//         return dfs(prices, memo, prices.size() - 1, false);
//     }
// };
// dp优化空间
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         if (prices.size() < 2) return 0;
//         int cash = 0, pre_cash = cash;
//         int hold = -prices[0], pre_hold = hold;
//         for (int i = 1; i < prices.size(); i++) {
//             cash = max(pre_cash, pre_hold + prices[i]);
//             hold = max(pre_hold, pre_cash - prices[i]);

//             pre_cash = cash;
//             pre_hold = hold;
//         }
//         return cash;
//     }
// };
// dp做法
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         if (prices.size() < 2) return 0;
//         vector<vector<int>> dp(prices.size() + 1,vector<int>(2));
//         dp[0][0] = 0, dp[0][1] = -prices[0];
//         for (int i = 1/* 初始化定义完了第1天的所有情况 */; i < prices.size(); i++) {
//             dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
//             dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
//         }
//         return dp[prices.size() -1][0];
//     }
// };
// 贪心做法
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int max_diff = 0;
//         for (int i = 1; i < prices.size(); i++) {
//             max_diff += prices[i] - prices[i - 1] > 0 ? prices[i] - prices[i - 1] : 0;
//         }
//         return max_diff;
//     }
// };
// class Solution {
// public:
//     #define i(a) a.begin(),a.end()
//     int maximumCount(vector<int>& nums) {
//         auto zero_start = lower_bound(i(nums), 0);
//         auto zero_end = upper_bound(i(nums), 0);
//         return max(distance(nums.begin(), zero_start), distance(zero_end, nums.end()));
//     }
// };
// 1451. 重新排列句子中的单词
// 稳定排序
// class Solution {
// public:
//     string arrangeWords(string text) {
//         stringstream ss(text);
//         string temp;
//         vector<string> words;
//         while (getline(ss, temp, ' ')) {
//             words.emplace_back(temp);
//         }
//         stable_sort(words.begin(), words.end(), [](const string& a, const string& b) {return a.size() < b.size();});
//         temp.clear();
//         for (auto& x: words ) {
//             if (x[0] <= 97) x[0] = tolower(x[0]);
//             temp += x + " ";
//         }
//         temp[0] = toupper(temp[0]);
//         temp.pop_back();
//         return temp;
//     }
// };
// 哈希排序，数据记录相对位置
// class Solution {
// public:
//     string arrangeWords(string text) {
//         stringstream ss(text);
//         map<int, vector<string>> words;
//         string temp;
//         while (getline(ss, temp,' ')) {
//             int len = temp.size();
//             words[len].emplace_back(temp);
//         }
//         temp.clear();
//         for (auto& x : words) {
//             for (auto& y: x.second ) {
//                 if (y[0] < 97) y[0] += 32;
//                 temp += y + " ";
//             }
//         }
//         temp.pop_back();
//         temp[0] = toupper(temp[0]);
//         return temp;
//     }
// };
// 3223. 操作后字符串的最短长度
// 利用只有26个字母，二分查找
// class Solution {
// public:
//     int minimumLength(string s) {
//         ranges::sort(s);
//         char start = s[0];
//         int length = 0;
//         auto it = s.begin();
//         do {
//             auto pt = upper_bound(it, s.end(), start);
//             length += distance(pt, it) % 2 == 0 ? 2 : 1;
//             it = pt;
//             start = *pt;
//         } while (it != s.end());
//         return length;
//     }
// };
// nlogn时间，空间1不知道为什么反而leetcode空间占用更多了
// class Solution {
// public:
//     int minimumLength(string s) {
//         int length = 0, slow = 0;
//         ranges::sort(s);
//         s.append("#");
//         for (int fast = 1; fast < s.size(); fast++) {
//             if (s[fast] != s[fast - 1]) {
//                 if ((fast - slow) % 2 == 0) length += 2;
//                 else length += 1;
//                 slow = fast;
//             }
//         }
//         // length += (s.size() - slow) % 2 == 0 ? 2 : 1;
//         if (length == 0) {
//             length = (s.size() & 2 == 1) ? 1 : 2;
//         }
//         return length;
//     }
// };
// 朴素哈希表
// class Solution {
// public:
//     int minimumLength(string s) {
//         unordered_map<char, int> mapping;
//         for (char& c : s) {
//             mapping[c]++;
//         }
//         int length = 0;
//         for (auto& x : mapping) {
//             if (x.second % 2 == 0) length += 2;
//             else length++;
//         }
//         return length;
//     }
// };
// 377. 组合总和 Ⅳ
// 递归写法
// class Solution {
// public:
//     int combinationSum4(vector<int>& nums, int target) {
//         vector<unsigned int/* 防止溢出 */> dp(target + 1);
//         dp[0] = 1;
//         for (int i = 1; i <= target; i++) {
//             for (int j = 0; j < nums.size(); j++) {
//                 if(i <= nums[j])
//                     dp[i] += dp[i - nums[j]];
//             }
//         }
//         return dp[target];
//     }
// };
// 本质是爬楼梯，但是一次爬楼梯高度不确定而从数组中选择状态转移方程有点难写
// lambda捕获外部数组
// class Solution {
// public:
//     int combinationSum4(vector<int>& nums, int target) {
//         vector<int> memo(target + 1, -1);
//         auto dfs = [&/* 捕获外部的nums */](this auto&& dfs/* 能够调起自身递归 */, int i) -> int {
//             if (i == 0) return 1;
//             if (memo[i] != -1) return memo[i];
//             else {
//                 int res = 0;
//                 for (int j = 0; j < nums.size(); j++) {
//                     if (i < nums[j]) continue;
//                     else res += dfs(i - nums[j]);
//                 }
//                 memo[i] = res;
//             }
//             };
//         return dfs(target);
//     }
// };
// 记忆化搜索+递归
// class Solution {
//     vector<int> memo;
//     int dfs(int i, vector<int>& nums) {
//         if (i == 0) return 1;
//         if (memo[i] != -1) return memo[i];
//         else {
//             int res = 0;
//             for (int j = 0; j < nums.size(); j++) {
//                 if (i < nums[j]) continue;;
//                 res += dfs(i - nums[j], nums);
//             }
//             memo[i] = res;
//         }
//         return memo[i];
//     }
// public:
//     int combinationSum4(vector<int>& nums, int target) {
//         int n = nums.size();
//         memo.resize(target + 1, -1);
//         return dfs(target, nums);
//     }
// };
// 746. 使用最小花费爬楼梯
// 00 : 14 : 22 简单dp
// 状态压缩
// class Solution {
// public:
//     int minCostClimbingStairs(vector<int>& cost) {
//         int n = cost.size();
//         vector<int> dp(n + 1);
//         for (int i = 2; i <= n; i++) {
//             dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
//         }
//         return dp[n];
//     }
// };
// 70. 爬楼梯
// 将递归改为迭代，其实就是将状态转移方程写入循环中
// class Solution {
//     public:
//     int climbStairs(int n) {
//         vector<int> dp(n + 1);
//         dp[0] = 1;
//         dp[1] = 1;
//         for (int i = 2; i < n; i++) {
//             dp[i] = dp[i - 1] + dp[i - 2];
//         }
//         return dp[n];
//     }
// };
// 状态压缩
// class Solution {
// public:
//     int climbStairs(int n) {
//         int pre = 1, cur = 1, ans = 0;
//         for (int i = 2; i <= n; i++) {
//             ans = pre + cur;
//             cur = pre;
//             pre = ans;
//         }
//         return ans;
//     }
// };
// 递归+记忆化搜索
// class Solution {
// public:
//     int dfs(int n, vector<int>& memo) {
//         if (n <= 1) return 1;
//         if (memo[n] != -1) return memo[n];
//         return memo[n] = dfs(n - 1, memo) + dfs(n - 2, memo);
//     }
//     int climbStairs(int n) {
//         vector<int> memo(n + 1, -1);
//         return dfs(n, memo);
//     }
// };
// 电池分配问题
// double maxGameTime(vector<double>& batteries) {
//     if (batteries.size() <= 1) return 0.0;
//     double sum = reduce(batteries.begin(), batteries.end(), 0.0);
//     double max_battery = *max_element(batteries.begin(), batteries.end());
//     if (sum - max_battery > max_battery) {
//         return sum / 2.0;
//     }
//     else {
//         return max_battery;
//     }

//     return 0.0;
// }
// 丢手绢淘汰问题，josephus环问题
// int josephus(int n) {
//     if (n == 0) return 0;
//     int res = 0;
//     for (int i = 2; i <= n; ++i) {
//         res = (res + 3) % i;
//     }
//     return res + 1;
// }

// int main() {
//     int n;
//     cin >> n;
//     cout << josephus(n) << endl;
//     return 0;
// }
// class Solution {
//     vector<int> memo;
// public:
//     int rob_to(vector<int>& nums, int last_index, vector<int>& memo) {
//         if (last_index < 0) return 0;
//         if (memo[last_index] != -1) return memo[last_index];
//         int not_skip = rob_to(nums, last_index - 2, memo) + nums[last_index];
//         int skip = rob_to(nums, last_index - 1, memo);
//         memo[last_index] = max(not_skip, skip);
//         return memo[last_index];
//     }

//     int rob(vector<int>& nums) {
//         if (nums.empty()) return 0;
//         vector<int> memo(nums.size(), -1);
//         return rob_to(nums, nums.size() - 1, memo);
//     }
// };

// int main() {
//     vector<int> test = { 1,2,3,1 };
//     //	cout << Solution().rob(test);
//     Solution sol;
//     cout << sol.rob(test);
// }
// LCP 40. 心算挑战
// class Solution {
// public:
//     int maximumScore(vector<int>& cards, int cnt) {
//         ranges::sort(cards, greater());
//         int s = reduce(cards.begin(), cards.begin() + cnt); // 最大的 cnt 个数之和
//         if (s % 2 == 0) { // s 是偶数
//             return s;
//         }

//         auto replaced_sum = [&](int x) -> int {
//             for (int i = cnt; i < cards.size(); i++) {
//                 if (cards[i] % 2 != x % 2) { // 找到一个最大的奇偶性和 x 不同的数
//                     return s - x + cards[i]; // 用 cards[i] 替换 s
//                 }
//             }
//             return 0;
//             };

//         int x = cards[cnt - 1];
//         int ans = replaced_sum(x); // 替换 x
//         for (int i = cnt - 2; i >= 0; i--) { // 前 cnt-1 个数
//             if (cards[i] % 2 != x % 2) { // 找到一个最小的奇偶性和 x 不同的数
//                 ans = max(ans, replaced_sum(cards[i])); // 替换
//                 break;
//             }
//         }
//         return ans;
//     }
// };
// 1509. 三次操作后最大值与最小值的最小差
// 00 : 12 : 35 有点脑筋急转弯，只有四种情况，和2971一样
// class Solution {
// public:
//     int minDifference(vector<int>& nums) {
//         int n = nums.size();
//         if (n <= 4) return 0;
//         ranges::sort(nums);
//         vector<int> answers;
//         answers.push_back(nums[n - 1] - nums[3]);
//         answers.push_back(nums[n - 2] - nums[2]);
//         answers.push_back(nums[n - 3] - nums[1]);
//         answers.push_back(nums[n - 4] - nums[0]);
//         return *min_element(answers.begin(), answers.end());
//     }
// };
// 2971. 找到最大周长的多边形
// class Solution {
// public:
//     long long largestPerimeter(vector<int>& nums) {
//         ranges::sort(nums);
//         int n = nums.size();
//         vector<long long> preSum(n,0);
//         preSum[0] = nums[0];
//         for (int i = 1; i < nums.size(); i++) {
//             preSum[i] = (long long)nums[i] + preSum[i - 1];
//         }
//         for (int i = n - 2, j = n - 1; i >= 0; i--, j--) {
//             if (nums[j] < preSum[i]) return preSum[i] + nums[j];
//         }
//         return -1;
//     }
// };
// 1561. 你可以获得的最大硬币数目
// class Solution {
// public:
//     int maxCoins(vector<int>& piles) {
//         ranges::sort(piles);
//         int n = piles.size();
//         int sum = 0;
//         for (int i = n / 3; i < n; i+=2) {
//             sum += piles[i];
//         }
//         return sum;
//     }
// };
// 2587. 重排数组以得到最大前缀分数
// class Solution {
// public:
//     int maxScore(vector<int>& nums) {
//         // auto newEnd = remove_if(nums.begin(), nums.end(), [](const int& a) { return a >= 0;});
//         auto newEnd = remove_if(nums.begin(), nums.end(), [](const int& a) {
//             return a >= 0; // 保留非负数，移动负数
//             });
//         sort(newEnd, nums.end());
//         int maxScore = distance(nums.begin(), newEnd);
//         long long sum = reduce(nums.begin(), newEnd);
//         for (auto it = newEnd; it != nums.end();it++) {
//             sum -= *it;
//             maxScore++;
//             if (sum < 0) return --maxScore;
//             if (sum == 0) return maxScore;
//         }
//         return maxScore;
//     }
// };
// 2554. 从一个范围内选择最多整数 I
// 使用set方法
// class Solution {
// public:
//     int maxCount(vector<int>& banned, int n, int maxSum) {
//         set<int> st(banned.begin(), banned.end());
//         int sum = 0, count = 0;
//         for (int i = 1; i <= n; i++) {
//             if (!st.contains(i) && sum < maxSum) {
//                 sum += i;
//                 count++;
//                 if (sum > maxSum) return --count;
//                 if (sum == maxSum) return count;
//             }
//         }
//         return count;
//     }
// };
// 取差集做法（傻瓜做法）
// #define ran(a) a.begin(),a.end()
// class Solution {
// public:
//     int maxCount(vector<int>& banned, int n, int maxSum) {
//         vector<int> nums(n), diff;
//         iota(ran(nums), 1);
//         sort(ran(banned));
//         auto it = upper_bound(ran(banned), n);
//         set_difference(nums.begin(),nums.end(), banned.begin(), it, back_inserter(diff));
//         int sum = 0, i = 0;
//         for (;i < diff.size(); i++) {
//             sum += diff[i];
//             if (sum == maxSum) return i + 1;
//             if (sum > maxSum) return i;
//         }
//         return i; // 处理遍历之后sum<maxSum的情况
//     }
// };
// #define it(a) a.begin(),a.end()
// class Solution {
// public:
//     int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
//         using pii = pair<int, int>;
//         unordered_map<int, int> mapping;
//         priority_queue<int, vector<int>, greater<int>> pq;
//         for (auto& x : arr) {
//             mapping[x]++;
//         }
//         for (auto& [_, freq] : mapping) {
//             pq.push(freq);
//         }
//         while (!pq.empty() && k > 0) {
//             int freq = pq.top();
//             pq.pop();
//             if (k >= freq)
//                 k -= freq;
//             else {
//                 pq.push(freq - k);
//                 k = 0;
//             }
//         }
//         return pq.size();
//     }
// };
// #define it(a) a.begin(),a.end()
// class Solution {
// public:
//     int largestSumAfterKNegations(vector<int>& nums, int k) {
//         priority_queue<int, vector<int>, greater<int>> pq;
//         make_heap(it(nums), greater<int>());
//         for (int i = 0;i < k;i++) {
//             nums[0] = -nums[0];
//             pop_heap(it(nums), greater<int>());
//             push_heap(it(nums), greater<int>());
//         }
//         return reduce(it(nums));
//     }
// };
// 984. 不含 AAA 或 BBB 的字符串
// class Solution {
// public:
//     string change(int big, string bigChar, int small, string smallChar) {
//         string output;
//         while (big - small > 2) {
//             big -= 2;
//             output += bigChar + bigChar;
//             small -= 1;
//             output += smallChar;
//         }
//         while (big > 0 || small > 0) {
//             if (big != 0) {
//                 big--;
//                 output += bigChar;
//             }
//             if (small != 0) {
//                 small--;
//                 output += smallChar;
//             }
//         }
//         return output;
//     }
//     string strWithout3a3b(int a, int b) {
//         return a > b ? change(a, "a", b, "b") : change(b, "b", a, "a");
//     }
// };
// class Solution {
// public:
//     int maxIceCream(vector<int>& costs, int coins) {
//         ranges::sort(costs.begin(), costs.end());
//         int count = 0;
//         for (int i = 0;i < costs.size();i++) {
//             coins -= costs[i];
//             count++;
//             if (coins == 0) return count;
//             if (coins < 0) return --count;
//         }
//         return count;
//     }
// };
// 2279. 装满石头的背包的最大数量
// 前缀和做法转化为分苹果问题,理论上可行，但是只有Python不会爆内存
// class Solution {
// public:
//     int maximumBags(vector<int>& cap, vector<int>& rocks, int additionalRocks) {
//         transform(cap.begin(), cap.end(), rocks.begin(), cap.begin(), minus<int>());
//         sort(cap.begin(), cap.end(), less<int>());
//         partial_sum(cap.begin(), cap.end(), cap.begin());
//         auto it = upper_bound(cap.begin(), cap.end(), additionalRocks);
//         return distance(cap.begin(), it);
//     }
// };
// 库函数
// class Solution {
// public:
//     int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
//         transform(capacity.begin(), capacity.end(), rocks.begin(),capacity.begin(), minus<int>());
//         ranges::sort(capacity);
//         int count = 0;
//         return count_if(capacity.begin(), capacity.end(), [&additionalRocks,&count](const int& diff) {
//             if (diff == 0) return true;
//             if (count + diff <= additionalRocks) {
//                 count += diff;
//                 return true;
//             }
//             return false;
//             });
//     }
// };

// class Solution {
// public:
//     using ll = long long;
//     int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
//         ll sum = reduce(rocks.begin(), rocks.end()) + additionalRocks;
//         ranges::sort(capacity, less<int>());
//         int count = 0;
//         for (auto& x : capacity) {
//             sum -= x;
//             count++;
//             if (sum == 0) return count;
//             if (sum < 0) return --count;
//         }
//         return count;
//     }
// };

// 贪心做法
// class Solution {
// public:
//     int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
//         int count = 0;
//         for (int i = 0;i < capacity.size();i++) {
//             capacity[i] -= rocks[i];
//         }
//         sort(capacity.begin(), capacity.end(),less<int>());
//         for (int i = 0;i < capacity.size();i++) {
//             additionalRocks -= capacity[i];
//             count++;
//             if (additionalRocks == 0) return count;
//             if (additionalRocks < 0) return --count;
//         }
//         return count;
//     }
// };

// 3074. 重新分装苹果
// class Solution {
// public:
//     int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
//         int sum = reduce(apple.begin(), apple.end());
//         ranges::sort(capacity);
//         int count = 0;
//         for (int i = capacity.size() - 1;i >= 0;i--) {
//             sum -= capacity[i];
//             count++;
//             if (sum <= 0) break;
//         }
//         return count;
//     }
// };
// 3296. 移山所需的最少秒数
// 堆写法
// class Solution {
// public:
//     long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
//         using tlii = tuple<long long, int, int>;
//         int n = workerTimes.size();
//         priority_queue<tlii, vector<tlii>, greater<tlii>> pq;
//         // initialize
//         for (int i = 0;i < n;i++) {
//             long long time = (long long)workerTimes[i];
//             int index = i;
//             int round = 1;
//             pq.emplace(time, index, round);
//         }
//         long long ans = 0;
//         // remove 1 unit in every loop
//         while (mountainHeight--) {
//             auto [time, index, round] = pq.top(); pq.pop();
//             int nextRound = round + 1;
//             long long nextRoundTime = time + nextRound * (long long)workerTimes[index];
//             int nextIndex = index;
//             ans = max(ans, time);
//             pq.emplace(nextRoundTime, nextIndex, nextRound);
//         }
//         return ans;
//     }
// };
// 2233. K 次增加后的最大乘积
// 最小堆做法
// class Solution {
// public:
//     int maximumProduct(vector<int>& nums, int k) {
//         const int mod = 1e9 + 7;
//         priority_queue<int, vector<int>, greater<int>> pq;
//         for (int& x : nums) {
//             pq.push(x);
//         }
//         while (k > 0) {
//             int min_val = pq.top();
//             pq.pop();
//             pq.push(min_val + 1);
//             k--;
//         }
//         long long ans;
//         while (!pq.empty()) {
//             ans = (ans * pq.top()) % mod;
//             pq.pop();
//         }
//         return ans % mod;
//     }
// };
// 3275. 第 K 近障碍物查询
// O(1)空间，O(logn)时间，线程池思想做法，抓住unreserve操作之前必定进行了对应位置的reserve这一点
// class SeatManager {
//     priority_queue<int, vector<int>, greater<int>> pq;
//     int size = 0;
// public:
//     SeatManager(int n) {}
//     int reserve() {
//         if (!pq.empty()) {
//             int seat = pq.top();
//             pq.pop();
//             return seat;
//         }
//         return ++size;
//     }

//     void unreserve(int seatNumber) {
//         pq.push(seatNumber);
//     }
// };
// 有复杂度 00 : 11 : 30 简单堆管理，可以优化到O(1)
// class SeatManager {
//     priority_queue<int, vector<int>, greater<int>> pq;
// public:
//     SeatManager(int n) {
//         do {
//             pq.push(n);
//         } while (--n > 0);
//     }

//     int reserve() {
//         int seat = pq.top();
//         pq.pop();
//         return seat;
//     }

//     void unreserve(int seatNumber) {
//         pq.push(seatNumber);
//     }
// };
// class Solution {
// public:
//     vector<int> resultsArray(vector<vector<int>>& queries, int k) {
//         priority_queue<int> pq;
//         vector<int> ans(queries.size(), -1);
//         for (int i = 0;i < queries.size();i++) {
//             pq.push(abs(queries[i][0]) + abs(queries[i][1]));
//             if (pq.size() > k) {
//                 pq.pop();
//             }
//             if(pq.size() == k){
//                 ans[i] = pq.top();
//             }
//         }
//         return ans;
//     }
// };
// 1046. 最后一块石头的重量
// 最大堆做法
// class Solution {
// public:
//     int lastStoneWeight(vector<int>& stones) {
//         priority_queue<int, vector<int>> pq;
//         for (auto& x : stones) {
//             pq.push(x);
//         }
//         while (!pq.empty()) {
//             if (pq.size() == 1) return pq.top();
//             int a = pq.top();
//             pq.pop();
//             int b = pq.top();
//             pq.pop();
//             if (a != b) pq.push(max(a, b) - min(a, b));
//         }
//         return 0;
//     }
// };
// 3170. 删除星号以后字典序最小的字符串
// 04 : 46 : 19 九牛二虎之力弄懂比较器，二元操作符，仿函数，优先队列，decltype，lambda之间联系后写的
// class Solution {
// using pci = pair<char, int>;
// public:
//     struct compare {
//         bool operator()(const pci& a, const pci& b) {
//             if (a.first > b.first) return true;
//             else if (a.first == b.first && a.second < b.second) return true;
//             else return false;
//         }
//     };
//     string clearStars(string s) {
//         priority_queue<pci,vector<pci>, compare> pq;
//         for (int i = 0;i < s.size();i++) {
//             if (s[i] == '*') pq.pop();
//             else pq.push({s[i], i});
//         }
//         auto f = [](const pci& a, const pci& b) -> bool {
//             return a.second < b.second;
//             };
//         set <pci, decltype(f)> result;
//         while (!pq.empty()) {
//             result.insert(pq.top());
//             pq.pop();
//         }
//         s.clear();
//         for (auto& x : result){
//             s.append(1,x.first);
//         }
//         return s;
//     }
// };
// 71. 简化路径
// 正则写法
// class Solution {
// public:
//     string simplifyPath(string path) {
//         path = regex_replace(path, regex("/+"), "/");
//         if (path.size() > 1 && path.back() == '/') path.pop_back();
//         stack<string> st;
//         regex pattern("[^/]+");
//         auto word_begin = sregex_iterator(path.begin(), path.end(), pattern);
//         auto word_end = sregex_iterator();
//         for (auto i = word_begin; i != word_end;i++) {
//             // st.push("/" + (*i).str());
//             string s = (*i).str();
//             if (s == ".." && !st.empty()) st.pop();
//             else if (s == "." || (s==".." && st.empty())) continue;
//             else st.push("/" + s);
//         }
//         string out;
//         while(!st.empty()) {
//             out = st.top() + out;
//             st.pop();
//         }
//         return out.empty()? "/" : out;
//     }
// };
// 946. 验证栈序列
// class Solution {
// public:
//     bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
//         if (pushed.size() != popped.size()) return false;
//         stack<int> st;
//         int j = 0;
//         for (auto& x : pushed) {
//             st.push(x);
//             while (!st.empty() && st.top() == popped[j]) {
//                 st.pop();
//                 j++;
//             }
//         }
//         return st.empty();
//     }
// };
// 2390. 从字符串中移除星号
// 双指针
// class Solution {
// public:
//     string removeStars(string s) {
//         int n = s.size(), slow = 0;
//         string out;
//         for (int fast = 0; fast < n; fast++) {
//             if (s[fast] == '*') {
//                 if (!out.empty()) out.pop_back();
//                 slow = fast + 1;
//             }
//             else {
//                 out.append(1, s[slow++]);
//             }
//         }
//         return out;
//     }
// };
// 栈,字符和字符串之间的连接总是忘记，已经写入笔记中，尤其是append方法，append(1,char)才是插入一个字符
// class Solution {
// public:
//     string removeStars(string s) {
//         string out;
//         stack<char> st;
//         for (char c : s) {
//             if (c != '*') {
//                 st.push(c);
//             }
//             else if (c == '*' && !st.empty()) {
//                 st.pop();
//             }
//         }
//         while (!st.empty()) {
//             out += st.top();
//             st.pop();
//         }
//         ranges::reverse(out);
//         return out;
//     }
// };
// 844. 比较含退格的字符串
// 栈做法，还可以用双指针，更快更小
// class Solution {
//     public:
//     void getString(string& input, stack<char>& st) {
//         for (char c : input) {
//             if (c != '#') {
//                 st.push(c);
//             }
//             else if (c == '#' && !st.empty()) {
//                 st.pop();
//             }
//         }
//     }
//     bool backspaceCompare(string s, string t) {
//         stack<char> st1, st2;
//         getString(s, st1);
//         getString(t, st2);
//         if (st1.size() != st2.size()) return false;
//         while (!st1.empty()) {
//             if (st1.top() != st2.top()) return false;
//             st1.pop(), st2.pop();
//         }
//         return true;
//     }
// };

// 1441. 用栈操作构建数组
// class Solution {
// public:
//     vector<string> buildArray(vector<int>& target, int n) {
//         vector<string> ans;
//         int index = 0; // 用于遍历 target 数组
//         for (int i = 1; i <= n && index < target.size(); i++) {
//             ans.push_back("Push");
//             if (target[index] == i) {
//                 index++; // 匹配成功，移动到下一个目标元素
//             }
//             else {
//                 ans.push_back("Pop"); // 不匹配，执行 Pop 操作
//             }
//         }
//         return ans;
//     }
// };
// 732. 我的日程安排表 III
// class MyCalendarThree {
//     map<int, int> records;
//     int maxnum;
// public:
//     MyCalendarThree() {
//         maxnum = 0;
//     }

//     int book(int startTime, int endTime) {
//         records[startTime]++;
//         records[endTime]--;
//         int s = 0;
//         for (auto& x : records) {
//             s += x.second;
//             maxnum = max(maxnum, s);
//         }
//         return maxnum;
//     }
// };
// 57. 插入区间
// 差分做法
// class Solution {
// public:
//     vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
//         int index = 0, n = intervals.size();
//         vector<vector<int>> ans;
//         // 这里只能到intervals[index][1] < newInterval[0]，不然会在ans中放入一个多余数组
//         while (index <= n && intervals[index][1] < newInterval[0]) {
//             ans.push_back(intervals[index++]);
//         }
//         // 这里需要<=，不然会不会完整包裹newInterval范围
//         while (index <= n && intervals[index][1] <= newInterval[1]) {
//             newInterval[0] = min(newInterval[0], intervals[index][0]);
//             newInterval[1] = max(newInterval[1], intervals[index][1]);
//             index++;
//         }
//         // 处理后newintevals是所有和源newinterval沾边的区间合并后的大区间
//         ans.push_back(newInterval);
//         // newinteval在覆盖到inteval的尾部，后面剩余部分进入ans
//         while (index <= n) {
//             ans.push_back(intervals[index++]);
//         }
//         return ans;
//     }
// };
// 转化为56题，用一样的代码
// class Solution {
//     vector<vector<int>> ans;
// public:
//     vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
//         intervals.push_back(newInterval);
//         ranges::sort(intervals, [&](const auto& x, const auto& y) {
//             return x[0] < y[0];
//             });
//         int left = intervals[0][0], right = intervals[0][1];
//         for (auto& x : intervals) {
//             int start = x[0], end = x[1];
//             if (start <= right && end > right) {
//                 right = end;
//             }
//             else if (start > right) {
//                 ans.push_back({ left,right });
//                 left = start;
//                 right = end;
//             }
//         }
//         ans.push_back({ left,right });
//         return ans;
//     }
// };
// 56. 合并区间
// 不适使用差分数组，双指针
// class Solution {
// public:
//     vector<vector<int>> merge(vector<vector<int>>& intervals) {
//         ranges::sort(intervals, [&](const auto& x, const auto& y) {
//             return x[0] < y[0];
//             });
//         int left = intervals[0][0], right = intervals[0][1];
//         vector<vector<int>> ans;
//         for (auto& x : intervals) {
//             int start = x[0], end = x[1];
//             if (start <= right && end > right) {
//                 right = end;
//             }
//             else if (start > right) {
//                 ans.push_back({ left,right });
//                 left = start;
//                 right = end;
//             }
//         }
//         ans.push_back({ left,right });
//         return ans;
//     }
// };
// 1893. 检查是否区域内所有整数都被覆盖
// 差分数组
// class Solution {
// public:
//     bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
//         int records[10100] = {};
//         for (auto& q : queries) {
//             int start = q[0], end = q[1];
//             records[start]--;
//             records[end + 1]++;
//         }
//         int s = 0;
//         for (int i = 0;i < nums.size();i++) {
//             s += records[i];
//             if (nums[i] + s > 0) return false;
//         }
//         return true;
//     }
// };
// 排序做法
// class Solution {
// public:
//     bool isCovered(vector<vector<int>>& range, int left, int right) {
//         ranges::sort(range, [&](auto& x, auto& y) {
//             return x[0] < y[0];
//             });
//         for (auto& x : range) {
//             int l= x[0], r = x[1];
//             if (l <= left && left <= r) {
//                 left = r + 1;
//             }
//         }
//         return left > right;
//     }
// };
// 暴力法
// class Solution {
// public:
//     int maximumPopulation(vector<vector<int>>& logs) {
//         int s = 0, max_num = 0, ans = 1950;
//         int records[101] = {};
//         for (auto x : logs) {
//             int birth = x[0], death = x[1];
//             for (int i = birth;i < death;i++) {
//                 records[i - 1950]++;
//             }
//         }
//         for (int i = 0; i < 101; i++) {
//             if (records[i] > max_num) {
//                 max_num = records[i];
//                 ans = i + 1950;
//             }
//         }
//         return ans;
//     }
// };
// 00 : 28 : 22简单差分模板题，由于输出不要求和输入（或者输入规模）有关，所以使用 map 更省空间并保证遍历顺序
// class Solution {
// public:
//     int maximumPopulation(vector<vector<int>>& logs) {
//         // vector<int> records(2100);
//         map<int, int> records;
//         for (auto x : logs) {
//             int birth = x[0], death = x[1];
//             records[birth]++;
//             records[death]--;
//         }
//         int s = 0, max_year = 0, temp = 0, ans = 0;
//         for (auto x : records) {
//             temp = s;
//             s += x.second;
//             if (s > max_year) {
//                 ans = x.first;
//                 max_year = max(max_year, s);
//             }
//         }
//         return ans;
//     }
// };
// 1893. 检查是否区域内所有整数都被覆盖
// class Solution {
// public:
//     int numberOfPoints(vector<vector<int>>& nums) {
//         ranges::sort(nums, [&](auto x, auto y) {
//             return x[0] < y[0];
//             });
//         int ans = 0, p = 0;
//         for (auto x : nums) {
//             if (p < x[1]) {
//                 ans += x[1] - max(p, x[0] - 1);
//                 p = x[1];
//             }
//         }
//         return ans;
//     }
// };
// 00 : 09 : 48 简单模拟题
// class Solution {
// public:
//     bool isCovered(vector<vector<int>>& ranges, int left, int right) {
//         vector<int> record(55);
//         for (auto x : ranges) {
//             int start = x[0], end = x[1];
//             record[start]++;
//             record[end + 1]--;
//         }
//         int s = 0;
//         for (int i = 0;i < left;i++) {
//             s += record[i];
//         }
//         for (int i = left;i <= right;i++) {
//             s += record[i];
//             if (s <= 0) return false;
//         }
//         return true;
//     }
// };
// 2848. 与车相交的点
// [用时:10 m 22 s] 差分模板题，需要注意的是初始数组大小。end + 1类型题目，vector<int> record(101);就多一个容易溢出，最好增加总数组容量的10% ，不然下标0下标1一变化需要改为record(101)，少了一个容量丢了10% 的分
// class Solution {
// public:
//     int numberOfPoints(vector<vector<int>>& nums) {
//         vector<int> record(101);
//         for (auto x : nums) {
//             int start = x[0], end = x[1];
//             record[start]++;
//             record[end + 1]--;
//         }
//         int s = 0, count = 0;
//         for (int x : record) {
//             s += x;
//             if(s != 0) count++;
//         }
//         return count;
//     }
// };
// 1700. 无法吃午餐的学生数量
// 简化版本
// class Solution {
// public:
//     int countStudents(vector<int>& students, vector<int>& sandwiches) {
//         int stud[2] = { 0,0 };
//         for (int student : students) stud[student]++;
//         for (int sand : sandwiches) {
//             if (stud[sand] != 0) stud[sand]--;
//             else break;
//         }
//         return stud[0] + stud[1];
//     }
// };
// class Solution {
// public:
//     int countStudents(vector<int>& students, vector<int>& sandwiches) {
//         queue<int> q(students.begin(), students.end());
//         int pointer = 0, size = q.size(), count = 0;;
//         while (pointer!=sandwiches.size()) {
//             if (sandwiches[pointer] == q.front()) {
//                 pointer++;
//                 q.pop();
//                 size = q.size();
//                 count = 0;
//             }
//             else {
//                 q.push(q.front());
//                 q.pop();
//                 if (count++ == size - 1) return count;
//             }
//         }
//         return count;
//     }
// };

// 1508. 子数组和排序后的区间和
// class Solution {
//     const int mod = 1e9 + 7;
// public:
//     int rangeSum(vector<int>& nums, int n, int left, int right) {
//         nums.insert(nums.begin(), 0);
//         partial_sum(nums.begin(), nums.end(), nums.begin());
//         vector<int> ordered;
//         for (int i = 0; i < nums.size(); i++) {
//             for (int j = i + 1; j < nums.size(); j++) {
//                 ordered.push_back(nums[j] - nums[i]);
//             }
//         }
//         sort(ordered.begin(), ordered.end());
//         int result = 0;
//         for (int i = left - 1; i <= right - 1;i++) {
//             result += ordered[i];
//             result %= mod;
//         }
//         return result;
//     }
// };
// 2381. 字母移位 II
// 一旦出现循环数组中元素查询，取模一定要注意
// class Solution {
// public:
//     string shiftingLetters(string s, vector<vector<int>>& shifts) {
//         // map<int, int> mapping;
//         vector<int> nums(s.size() + 1);
//         vector<char> alpha = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
//         for (auto& x : shifts) {
//             int start = x[0], end = x[1], direct = x[2];
//             nums[start] += direct == 1 ? 1 : -1;
//             nums[end + 1] += direct == 1 ? -1 : 1;
//         }
//         int sum = 0, n = s.size();
//         for (int i = 0;i < n;i++) {
//             sum += nums[i];
//             s[i] = alpha[((s[i] - 97 + sum) % 26 + 26) % 26];
//         }
//         return s;
//     }
// };
// 2406. 将区间分为最少组数
// 差分解法，可以转化为上下车问题
// class Solution {
// public:
//     int minGroups(vector<vector<int>>& intervals) {
//         map<int, int> mapping;
//         for (auto& x : intervals) {
//             int start = x[0], end = x[1];
//             mapping[start] += 1;
//             mapping[end + 1] -= 1;
//         }
//         int s = 0, ans = 0;
//         for (auto n : mapping) {
//             ans = max(ans, s += n.second);
//         }
//         return ans;
//     }
// };
// 不会，看题解，贪心算法+优先队列
// #define all(a) a.begin(),a.end()
// using vi = vector<int>;
// class Solution {
// public:
//     int minGroups(vector<vector<int>>& intervals) {
//         sort(all(intervals), [](const vi& a, const vi& b) {
//             return a[0] < b[0];
//             });
//         priority_queue<int, vi, greater<int>> pq;
//         for (auto x : intervals) {
//             int start = x[0], end = x[1];
//             // pq.push(end);
//             if (pq.empty()) pq.push(end);
//             else if (start < pq.top()) pq.push(end);
//             else {
//                 pq.pop();
//                 pq.push(end);
//             }
//         }
//         return pq.size();
//     }
// };
// 1109. 航班预订统计
// [用时:39 m 40 s] 常规差分做法， 就是下标搞得有点晕
// class Solution {
// public:
//     vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
//         // int num[n + 1]{};
//         vector<int> num(n + 2, 0);
//         vector<int> ans;
//         for (auto x : bookings) {
//             int first = x[0], last = x[1], seats = x[2];
//             num[first] += seats;
//             num[last + 1] -= seats;
//         }
//         int s = 0;
//         for (int i = 0;i < n;i++) {
//             s += num[i + 1];
//             ans.emplace_back(s);
//         }
//         return ans;
//     }
// };
// class Solution {
// public:
//     vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
//         map<int, int> mapping;
//         vector<int> ans;
//         for (auto x : bookings) {
//             int first = x[0], last = x[1], seats = x[2];
//             mapping[first] += seats;
//             mapping[last + 1] -= seats;
//         }
//         int s = 0;
//         for (auto [_, v] : mapping) {
//             s += v;
//             ans.push_back(s);
//         }
//         return ans;
//     }
// };
// 1094. 拼车
// 模板题，看题解学差分
// 差分数组最后还原成原有数组，数组相邻位置是一样的数字（也就是没有变化），差分数组对应位置就是0，由于没有人上下车的车站不需要改动map初始化的0
// class Solution {
// public:
//     bool carPooling(vector<vector<int>>& trips, int capacity) {
//         map<int, int> mapping;
//         for (auto& x : trips) {
//             int num = x[0], from = x[1], to = x[2];
//             mapping[from] += num;
//             mapping[to] -= num;
//         }
//         int s = 0;
//         for (auto [_, v] : mapping) {
//             s += v;
//             if (s > capacity) return false;
//         }
//         return true;
//     }
// };
// 一维数组大小还是需要根据输入数据规模而定，可以改用map哈希表方法
// class Solution {
// public:
//     bool carPooling(vector<vector<int>>& trips, int capacity) {
//         int array[1001];
//         for (auto& x : trips) {
//             int num = x[0], from = x[1], to = x[2];
//             array[from] += num;
//             array[to] -= num;
//         }
//         int s = 0;
//         for (int n : array) {
//             s += n;
//             if (s > capacity) return false;
//         }
//         return true;
//     }
// };
// 3148. 矩阵中的最大得分
// class Solution {
// public:
//     int maxScore(vector<vector<int>>& grid) {
//         int n = grid.size(), m = n == 0 ? 0 : grid[0].size();
//         int max_diff = INT_MIN;
//         vector dp(n + 1, vector<int>(m + 1, INT_MAX));
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 int mn = min(dp[i + 1][j], dp[i][j + 1]);
//                 max_diff = max(max_diff, grid[i][j] - mn);
//                 dp[i + 1][j + 1] = min(mn, grid[i][j]);
//             }
//         }
//         return max_diff;
//     }
// };
// 1504. 统计全 1 子矩形
// class Solution {
// public:
//     int numSubmat(vector<vector<int>>& mat) {
//         int n = mat.size(), m = n == 0 ? 0 : mat[0].size(), sum = 0;
//         vector dp(n, vector<int>(m));
//         for (int i = 0; i < mat.size(); i++) {
//             dp[i][0] = mat[i][0];
//         }
//         for (int i = 0; i < n; i++) {
//             int max_len = 0;
//             for (int j = 0; j < m; j++) {
//                 if (mat[i][j] == 0) {
//                     dp[i][j] = 0;
//                     continue;
//                 }
//                 int min_len = INT_MAX;
//                 if (j != 0)  dp[i][j] = dp[i][j - 1] + 1;
//                 for (int k = i;k >= 0;k--) {
//                     min_len = min(min_len, dp[k][j]);
//                     sum += min_len;
//                 }
//             }
//         }
//         return sum;
//     }
// };
// 1277. 统计全为 1 的正方形子矩阵
// class Solution {
//     vector<vector<int>> sum;
// public:
//     int getSum(int r1, int c1, int r2, int c2){
//         return sum[r2 + 1][c2 + 1] - sum[r2 + 1][c1] - sum[r1][c2 + 1] + sum[r1][c1];
//     }
//     int countSquares(vector<vector<int>>& matrix) {
//         int n = matrix.size(), m = n == 0 ? 0 : matrix[0].size(), count = 0;
//         sum.resize(n + 1, vector<int>(m + 1));
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + matrix[i][j];
//                 int len = min(i, j) + 1;
//                 while (len >= 0) {
//                     int temp_i = max(0, i - len + 1);
//                     int temp_j = max(0, j - len + 1);
//                     if (getSum(temp_i, temp_j, i, j) == len * len) {
//                         count++;
//                         // break;
//                     }
//                     len--;
//                 }
//             }
//         }
//         return count;
//     }
// };
// 1277. 统计全为 1 的正方形子矩阵
// 221. 最大正方形
// class Solution {
//     vector<vector<int>> sum;
// public:
//     int getSum(int r1, int c1, int r2, int c2) {
//         return sum[r2 + 1][c2 + 1] - sum[r2 + 1][c1] - sum[r1][c2 + 1] + sum[r1][c1];
//     }
//     int maximalSquare(vector<vector<char>>& matrix) {
//         int n = matrix.size(), m = n == 0 ? 0 : matrix[0].size(), maxLength = 0;
//         sum.resize(n + 1, vector<int>(m + 1));
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + (matrix[i][j] - '0');
//                 // auto it = matrix[i][j];
//                 int len = min(i, j) + 1;
//                 while (len > maxLength) {
//                     if (getSum(i - len + 1, j - len + 1, i, j) == len * len) {
//                         maxLength = len;
//                         break;
//                     }
//                     len--;
//                 }
//             }
//         }
//         return maxLength * maxLength;
//     }
// };
// 1292. 元素和小于等于阈值的正方形的最大边长
// class Solution {
// public:
//     int maxSideLength(vector<vector<int>>& mat, int threshold) {
//         int a[301][301];
//         int ans = 0, m;
//         for (int i = 0; i < mat.size(); ++i) {
//             for (int j = 0; j < mat[i].size(); ++j) {
//                 a[i + 1][j + 1] = a[i + 1][j] + a[i][j + 1] + mat[i][j] - a[i][j];
//                 m = min(i, j) + 1;
//                 while (m > ans) {
//                     if (a[i + 1][j + 1] - a[i + 1][j - m + 1] - a[i - m + 1][j + 1] + a[i - m + 1][j - m + 1] <= threshold) {
//                         ans = m;
//                         break;
//                     }
//                     --m;
//                 }
//             }
//         }
//         return ans;
//     }
// };
// class Solution {
//     int transfer(char c) {
//         if (c == 'X') return 1;
//         if (c == 'Y') return 2;
//         if (c == '.') return 0;
//         return 0;
//     }
// public:
//     int numberOfSubmatrices(vector<vector<char>>& grid) {
//         int n = grid.size(), m = n == 0 ? 0 : grid[0].size(), count = 0;
//         vector sum(n + 1, vector<int>(m + 1));
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + transfer(grid[i][j]);
//                 if (sum[i + 1][j + 1] != 0 && sum[i + 1][j + 1] % 3 == 0) count++;
//             }
//         }
//         return count;
//     }
// };
// 1738. 找出第 K 大的异或坐标值
// 使用优先队列
// class Solution {
// public:
//     int kthLargestValue(vector<vector<int>>& matrix, int k) {
//         int n = matrix.size(), m = n == 0 ? 0 : matrix[0].size();
//         priority_queue<int, vector<int>, greater<int>> pq;
//         vector sum(n + 1, vector<int>(m + 1));
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 sum[i + 1][j + 1] = sum[i + 1][j] ^ sum[i][j + 1] ^ sum[i][j] ^ matrix[i][j];
//                 pq.push(sum[i + 1][j + 1]);
//             }
//         }
//         k = pq.size() - k;
//         while (k--) {
//             pq.pop();
//         }
//         return pq.top();
//     }
// };
// 内置函数求第k大
// class Solution {
//     vector<vector<int>> sum;
// public:
//     int kthLargestValue(vector<vector<int>>& matrix, int k) {
//         int n = matrix.size(), m = n == 0 ? 0 : matrix[0].size();
//         vector<int> a;
//         sum.resize(n + 1, vector<int>(m + 1));
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 sum[i + 1][j + 1] = sum[i + 1][j] ^ sum[i][j + 1] ^ sum[i][j] ^ matrix[i][j];
//             }
//             a.insert(a.end(), sum[i + 1].begin() + 1, sum[i + 1].end());
//         }
//         ranges::nth_element(a.begin(), a.end() - k, a.end());
//         return a[a.size() - k];
//     }
// };
// 3070. 元素和小于等于 k 的子矩阵的数目
// 13mins 模板题变形而已
// class Solution {
//     vector<vector<int>> sum;
// public:
//     int getSum(int r1, int c1, int r2, int c2) {
//         return sum[r2 + 1][c2 + 1] - sum[r2 + 1][c1] - sum[r1][c2 + 1] + sum[r1][c2];
//     }
//     int countSubmatrices(vector<vector<int>>& grid, int k) {
//         int n = grid.size(), m = n == 0 ? 0 : grid[0].size();
//         sum.resize(n + 1, vector<int>(m + 1));
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + grid[i][j];
//             }
//         }
//         int count = 0;
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 if (getSum(0, 0, i, j) >= k)
//                     count++;
//             }
//         }
//         return count;
//     }
// };
// 1314. 矩阵区域和
// 模板题，但是测试自己写 2025-03-06 18:41:37
// class Solution {
//     vector<vector<int>> pre;
//     vector<vector<int>> ans;
// public:
//     int getSum(int r1, int c1, int r2, int c2) {
//         return pre[r2 + 1][c2 + 1] - pre[r2 + 1][c1] - pre[r1][c2 + 1] + pre[r1][c1];
//     }
//     vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
//         int n = mat.size(), m = n == 0 ? 0 : mat[0].size();
//         pre.resize(n + 1, vector<int>(m + 1));
//         ans.resize(n + 1, vector<int>(m + 1));
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 pre[i + 1][j + 1] = pre[i][j + 1] + pre[i + 1][j] - pre[i][j] + mat[i][j];
//             }
//         }
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 int r1 = i - k, c1 = j - k, r2 = i + k, c2 = j + k;
//                 r1 = max(r1, 0);
//                 c1 = max(c1, 0);
//                 r2 = min(r2, n - 1);
//                 c2 = min(c2, m - 1);
//                 ans[i][j] = getSum(r1, c1, r2, c2);
//             }
//         }
//         return ans;
//     }
// };
// 304. 二维区域和检索 - 矩阵不可变
// 二维前缀和模板题，看题解得到方法先
// class NumMatrix {
//     vector<vector<int>> sum;
// public:
//     NumMatrix(vector<vector<int>>& matrix) {
//         int m = matrix.size(), n = m == 0 ? 0 : matrix[0].size();
//         sum.resize(m + 1, vector<int>(n + 1));
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + matrix[i][j];
//             }
//         }
//     }

//     int sumRegion(int r1, int c1, int r2, int c2) {
//         return sum[r2 + 1][c2 + 1] - sum[r2 + 1][c1] - sum[r1][c2 + 1] + sum[r1][c1];
//     }
// };

// 455.分发饼⼲
// class Solution {
// public:
//     int findContentChildren(vector<int>& greedy, vector<int>& sol) {
//         ranges::sort(greedy);
//         ranges::sort(sol);
//         int gp = greedy.size() - 1, sp = sol.size() - 1, count = 0;
//         for (;gp != -1 && sp != -1;) {
//             if (sol[sp] >= greedy[gp]) {
//                 count++;
//                 sp--, gp--;
//             }
//             else {
//                 gp--;
//             }
//         }
//         return count;
//     }
// };
// 343. 整数拆分
// class Solution {
// public:
//     vector<int> integerBreak(int n) {
//         vector<int> dp(n + 1);
//         dp[2] = 1;
//         for (int i = 3; i <= n; i++) {
//             for (int j = 1; j <= i / 2; j++) {
//                 dp[i] = max(dp[i], max((i - j) * j, dp[i - j] * j));
//             }
//         }
//         return dp;
//     }
// };
// class Solution {
// public:
//     vector<int> integerBreak(int n) {
//         vector<int> dp(n + 1);
//         dp[2] = 1;
//         for (int i = 3;i <= n;i++) {
//             for (int j = 1;j < i;j++) {
//                 dp[i] = max(dp[i], max(dp[i - j] * j, j * (i - j)));
//             }
//         }
//         return dp;
//     }
// };
// 63. 不同路径 II
// class Solution {
// public:
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int m = obstacleGrid.size(), n = obstacleGrid[0].size();
//         if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) return 0;
//         vector dp(m, vector<int>(n, 0));
//         // initialize
//         for (int i = 0;i < m && obstacleGrid[i][0] == 0;i++)
//             dp[i][0] = 1;
//         for (int j = 0;j < n && obstacleGrid[0][j] == 0;j++)
//             dp[0][j] = 1;
//         for (int i = 1;i < m;i++) {
//             for (int j = 1;j < n;j++) {
//                 if(obstacleGrid[i][j] == 0) continue;
//                 dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//             }
//         }
//         return dp[m - 1][n - 1];
//     }
// };
// 优化空间
// class Solution {
// public:
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         if (obstacleGrid[0][0] == 1)
//             return 0;
//         vector<int> dp(obstacleGrid[0].size());
//         for (int j = 0; j < dp.size(); ++j)
//             if (obstacleGrid[0][j] == 1)
//                 dp[j] = 0;
//             else if (j == 0)
//                 dp[j] = 1;
//             else
//                 dp[j] = dp[j - 1];
//         for (int i = 1; i < obstacleGrid.size(); ++i)
//             for (int j = 0; j < dp.size(); ++j) {
//                 if (obstacleGrid[i][j] == 1)
//                     dp[j] = 0;
//                 else if (j != 0)
//                     dp[j] = dp[j] + dp[j - 1];
//             }
//         return dp.back();
//     }
// };
// 普通dp做法
// class Solution {
// public:
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int m = obstacleGrid.size();
//         int n = obstacleGrid[0].size();
//         if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][m - 1] == 1) return 0;
//         vector<vector<int>> dp(m, vector<int>(n, 0));
//         // ⼀旦遇到obstacleGrid[i][0] == 1的情况就停⽌dp[i][0]的赋值1的操作，这样就不会赋值到后面的位置
//         for (int i = 0; i < m && obstacleGrid[i][0] == 0; i++) dp[i][0] = 1;
//         for (int j = 0; j < n && obstacleGrid[0][j] == 0; j++) dp[0][j] = 1;
//         for (int i = 1;i < m;i++) {
//             for (int j = 1; j < n; j++) {
//                 if (obstacleGrid[i][j] == 0) continue;
//                 dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//             }
//         }
//         return dp[m - 1][n - 1];
//     }
// };
// 62. 不同路径
// 组合数学
// class Solution {
// public:
//     // 需要注意到的是题目并没有大数据，但涉及到乘法要使用longlong作为返回值
//     long long comb(int n, int k) {
//         if (k > n) return 0;
//         if (n - k < k) k = n - k;
//         long long res = 1;
//         for (int i = 1;i <= k;i++) {
//             res = res * (n - i + 1) / i;//不能这样，((n - i + 1) / i)整数相除会将小数部分截断，影响精度，正常来说/i的操作会被res约分
//         }
//         return res;// 最后得到的内容由于之前除以i会是一个int可以容纳的数字
//     }
//     int uniquePaths(int m, int n) {
//         return comb(m + n - 2, m - 1);
//     }
// };
// 动态规划方法
// 动态规划优化空间方法
// class Solution {
// public:
//     int uniquePaths(int m, int n) {
//         vector<int> dp(n, 1);// 初始化最左边一条和最上面一条，其他的值后面都会被改动不用管
//         for (int i = 1;i < m;i++) {
//             // 因为每次更新只需要当前行的上一行数据即可，并且上一行用完就要被舍弃，所以使用两层循环更新一行内容
//             for (int j = 1;j < n;j++) {
//                 dp[j] = dp[j]/* 这里的dp[j]未更新，是上一行的同一列数据*/ + dp[j - 1];
//             }
//         }
//         return dp[n - 1];
//     }
// };
// [用时:13 m 13 s] 标准dp做法，由dp数组是二维的，不能使用固定的几个变量记录dp最新状态，空间复杂度为on
// class Solution {
// public:
//     int uniquePaths(int m, int n) {
//         // vector<vector<int>> dp(m, vector<int>(n));
//         vector dp(m, vector<int>(n));
//         for (int i = 0;i < m;i++) dp[i][0] = 1;
//         for (int j = 0;j < n;j++) dp[0][j] = 1;
//         for (int i = 1;i < m;i++) {
//             for (int j = 1;j < n;j++) {
//                 dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//             }
//         }
//         return dp[m - 1][n - 1];
//     }
// };
// 46. 使用最小花费爬楼梯
// 更标准的做法
// class Solution {
// public:
//     int minCostClimbingStairs(vector<int>& cost) {
//         int n = cost.size();
//         vector<int> dp(n + 1);
//         dp[0] = 0;
//         dp[1] = 0;//从第一个和第二个台阶起步都不要耗费体力
//         for (int i = 2/* 跳过前两个 */;i <= n/* 遍历到最后一个 */;i++) {
//             dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
//             // 离开相应台阶才会消耗体力
//         }
//         return dp[n];
//     }
// };
// 17mins
// dp容易出错的就是特殊情况处理，初始化处理上，这一提就很清楚体现了
// class Solution {
// public:
//     int minCostClimbingStairs(vector<int>& cost) {
//         int n = cost.size();
//         if (n == 0) return 0;
//         if (n == 1) return cost[0];
//         vector<int> dp(n);
//         dp[0] = cost[0];
//         dp[1] = cost[1];
//         for (int i = 2;i < n;i++) {
//             dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
//         }
//         return min(dp[n - 1], dp[n - 2]);
//     }
// };
// 509. 斐波那契数
// [用时:17 m 44 s] 注意动态规划如果使用常数空间（即仅记录最新的几个数据）for循环的次数是希望DP的次数，初始化的内容要在循环开头作为特殊情况处理
// 常规做法
// class Solution {
// public:
//     int fib(int n) {
//         vector<int> dp(n);
//         dp[0] = 0, dp[1] = 1;
//         for (int i = 2;i <= n;i++) {
//             dp[i] = dp[i - 1] + dp[i - 2];
//         }
//         return dp[n];
//     }
//     // 递归写法
//     int fib(int n) {
//         if (n < 2) return n;
//         return fib(n - 1) + fib(n - 2);
//     }
// };
// class Solution {
// public:
//     int fib(int n) {
//         int temp0 = 0, temp1 = 0;
//         if (n == 1) return 1;
//         int dp[3] = { 0,1,0 };
//         for (int i = 0;i < n - 1;i++) {
//             dp[2] = dp[1] + dp[0];
//             temp0 = dp[1];
//             temp1 = dp[2];
//             dp[0] = temp0;
//             dp[1] = temp1;
//         }
//         return dp[2];
//     }
// };
// 387
// class Solution {
// public:
//     int myAtoi(string s) {
//         regex number_match(R"(^\s*([+-]?\d+*))");
//         smatch match;
//         long long result = 0;
//         if (!regex_search(s,match,number_match)) {
//             return 0;
//         }
//         else {
//             string extract_num = match.str();
//             try {
//                 result = stoll(extract_num);
//             }
//             catch (const invalid_argument& e) {
//                 return 0;
//             }
//             catch (const out_of_range& e) {
//                 return (extract_num[0] = '-') ? INT_MIN : INT_MAX;
//             }
//             result = max(min(result, (long long)INT_MAX), (long long)INT_MIN);
//         }
//         return result;
//     }
// };
// int main(){
//     string test = "20000000000000000000";
//     Solution sol;
//     cout << sol.myAtoi(test);
// }
// 151. 反转字符串中的单词
// 正则表达式暴力解法
// class Solution {
// public:
//     string reverseWords(string s) {
//         vector<string> temp_content;
//         string result;
//         regex word_regex("\\w+");
//         string::const_iterator search_start(s.cbegin());
//         smatch matches;
//         while (regex_search(search_start, s.cend(), matches, word_regex)) {
//             temp_content.push_back(matches.str(0));
//             search_start = matches.suffix().first;
//         }
//         // auto word_begin = sregex_iterator(s.begin(), s.end(),word_regex);
//         // auto word_end = sregex_iterator();
//         // for (auto i = word_begin; i != word_end; i++) {
//         //     smatch match = *i;
//         //     temp_content.push_back(match.str());
//         // }
//         // 也可以创建自动迭代器省去手动控制迭代器移动过程
//         // 翻转过程也可以写为
//         for_each(temp_content.rbegin(), temp_content.rend(), [&](string str) {result += (str + ' ');});
//         result.pop_back();
//         return result;
//     }
// };
// 904. 水果成篮
// [用时:48 m 36 s] 思路正确但是写不出来看AI
// class Solution {
// public:
//     int totalFruit(vector<int>& fruits) {
//         int n = fruits.size();
//         int left = 0, max_length = 0;
//         map<int, int> basket; // 哈希表，记录水果类型及其最新索引
//         for (int right = 0; right < n; right++) {
//             basket[fruits[right]] = right; // 将当前水果加入哈希表
//             if (basket.size() > 2) {
//                 int earliest_index = n;
//                 int delete_type = -1;
//                 for (const auto& entry : basket) {
//                     if (entry.second < earliest_index) {
//                         earliest_index = entry.second;
//                         delete_type = entry.first;
//                     }
//                 }
//                 basket.erase(delete_type);
//                 left = earliest_index + 1;
//             }
//             max_length = max(max_length, right - left + 1);
//         }
//         return max_length;
//     }
// };
// 977. 有序数组的平方
// class Solution {
// public:
//     vector<int> sortedSquares(vector<int>& nums) {
//         int n = nums.size(), left = 0, right = n - 1;
//         vector<int> ans(n);
//         for (int i = n - 1;i >= 0;i--) {
//             int x = nums[left] * nums[left];
//             int y = nums[right] * nums[right];
//             if (x > y) {
//                 ans[i] = x;
//                 left++;
//             }
//             else {
//                 ans[i] = y;
//                 right--;
//             }
//         }
//         return ans;
//     }
// };
// int returnPos(string haystack, string needle) {
//     return haystack.find(needle, 0);
// }

// void getNext(int* next, const string& s) {
//     int j = 0;// j指向最长公共前缀的最后一个字符，也表示最长公共前后缀长度
//     next[0] = 0;
//     for (int i = 1;i < s.size();i++) {// i指向现在匹配的位置，也是最长公共前后缀的字符串**后面**的一个字符
//         while (j > 0 && s[i] != s[j]) {// 如果不匹配（在试探延长前后缀字符串过程中发现不匹配并且j没有已经回退到0（回退到0不能再退了）
//             j = next[j - 1];// 回退到
//         }
//         if (s[i] == s[j]) { // 匹配上了就换下一个模式串字符继续匹配，下一轮i++
//             j++;
//         }
//         next[i] = j; // 更新next数组
//     }
// }
// int strStr(string haystack, string needle) {
//     if (needle.size() == 0) {
//         return 0;
//     }
//     vector<int> next(needle.size());
//     getNext(&next[0], needle);
//     int j = 0;
//     for (int i = 0; i < haystack.size(); i++) {
//         while (j > 0 && haystack[i] != needle[j]) { // 如果模式串和匹配串中的一个字符没有匹配上，并且模式串还能够回退
//             j = next[j - 1];// 回退，会退的是指针而不是让数组移动
//         }
//         if (haystack[i] == needle[j]) {// 匹配上了就继续看下一个匹配上没
//             j++;
//         }
//         if (j == needle.size()) {// 如果没有下一个
//             return (i - needle.size() + 1); // 结束，返回匹配串中第一个出现模式串的位置
//         }
//     }
//     return -1;
// }
// void getNext(int* next, string& s) {
//     int j = 0;
//     next[0] = 0;
//     for (int i = 1;i < s.length();i++) {
//         while (j > 0 && s[i] != s[j]) {
//             j = next[j - 1];
//         }
//         if (s[i] == s[j]) {
//             j++;
//         }
//         next[i] = j;
//     }
// }
// int strStr(string haystack, string needle) {
//     if (needle.size() == 0) return 0;
//     vector<int> next(needle.size());
//     getNext(&next[0], needle);
//     int j = 0;
//     for (int i = 0;i < haystack.size();i++) {
//         while (j > 0 && haystack[i] != needle[j]) {
//             j = next[j - 1];
//         }
//         if (haystack[i] == needle[j]) {
//             j++;
//         }
//         if (j == needle.size()) {
//             return (i - needle.size() + 1);
//         }
//     }
//     return -1;
// }

// 844. 比较含退格的字符串
// 2025-02-24 14:17:46
// 辅助空间为O(n)
// class Solution {
// public:
//     string afterModify(string input) {
//         string output;
//         for (int i = 0;i < input.length();i++) {
//             if (input[i] == '#') {
//                 if (output.length() != 0) {
//                     output.pop_back();
//                 }
//             }
//             else {
//                 output += input[i];
//             }
//         }
//         return output;
//     }
//     bool backspaceCompare(string s, string t) {
//         return afterModify(s) == afterModify(t);
//     }
// };
// 辅助空间为O(1)
// class Solution {
// public:
//     string afterModify(string input) {
//         int slow = 0, count = 0, fast = 0;
//         for (fast = 0;fast < input.length();fast++) {
//             if (input[fast] != '#') {
//                 input[slow++] = input[fast];
//             }
//             else {
//                 slow > 0 ? slow-- : 1;
//             }
//         }
//         count = fast - slow;
//         while (count--) {
//             input.pop_back();
//         }
//         return input;
//     }
//     bool backspaceCompare(string s, string t) {
//         return afterModify(s) == afterModify(t);
//     }
// };
// 反转字符串
// int main() {
//     string input;
//     cin >> input;
//     int length = input.length();
//     for (int left = 0;left < length / 2;left++) {
//         swap(input[left], input[length - left - 1]);
//     }
//     cout << input;
// }
// class Solution {
// public:
//     int findContentChildren(vector<int>& greed, vector<int>& sol) {
//         ranges::sort(greed);
//         ranges::sort(sol);
//         int index = 0;
//         for (int i = 0;i < sol.size();i++) {
//             if (index < greed.size() && sol[i] >= greed[index]) {
//                 index++;
//             }
//         }
//         return index;
//     }
// };
// class Solution {
// public:
//     int findContentChildren(vector<int>& g, vector<int>& s) {
//         ranges::sort(s);
//         ranges::sort(g);
//         int gsize = g.size(), ssize = s.size(), count = 0, i = 0, j = 0;
//         while (i < gsize && j < ssize) {
//             if (s[j] >= g[i]) {
//                 i++;j++;count++;
//             }
//             else {
//                 j++;
//             }
//         }
//         return count;
//     }
// };

// 递归中序遍历
// class Solution {
// public:
//     TreeNode* invertTree(TreeNode* root) {
//         if (root == NULL) return root;
//         invertTree(root->left);         // 左
//         swap(root->left, root->right);  // 中
//         invertTree(root->left);         // 注意 这里依然要遍历左孩子，因为中间节点已经翻转了
//         return root;
//     }
// };
// 迭代法，前序遍历
// class Solution {
// public:
//     TreeNode* invertTree(TreeNode* root) {
//         if (root == NULL) return root;
//         stack<TreeNode*> st;
//         st.push(root);
//         while (!st.empty()) {
//             TreeNode* node = st.top();
//             st.pop();
//             swap(node->left, node->right);
//             if (node->right) st.push(node->right);
//             if (node->left) st.push(node->left);
//         }
//         return root;
//     }
//     // 中序遍历，虽然用不着，复习一下
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> result;
//         stack<TreeNode*> st;
//         st.push(root);
//         TreeNode* cur = root;
//         while (!st.empty() && cur!=NULL) {
//             if (cur != NULL) {
//                 st.push(cur);
//                 cur = cur->left;
//             }
//             else {
//                 cur = st.top();
//                 st.pop();
//                 // result.push_back(cur->val);
//                 swap(cur->left, cur->right);
//                 cur = cur->right;
//             }
//         }
//         return result;
//     }
// };
// 递归法
// class Solution {
// public:
//     TreeNode* invertTree(TreeNode* root) {
//         if (root == NULL) return root;
//         swap(root->left, root->right);
//         invertTree(root->left);
//         invertTree(root->right);
//         return root;
//     }
// };
// 111. 二叉树的最小深度
// 常规做法
// class Solution {
// public:
//     int minDepth(TreeNode* root) {
//         if (root == NULL) return 0;
//         if (root->left == nullptr && root->right == nullptr) return 1;
//         if (root->left != nullptr && root->right != nullptr)
//             return min(minDepth(root->left), minDepth(root->right)) + 1;
//         if (root->left) return minDepth(root->left) + 1;
//         if (root->right) return minDepth(root->right) + 1;
//     }
// };
// 极值化简
// class Solution {
// public:
//     int minDepth(TreeNode* root) {
//         if (root == nullptr) return 0;
//         if (root->left && root->right) return 1 + min(minDepth(root->left), minDepth(root->right));
//         // 最后，若当前节点的左右子节点有一个不存在，则说明***当前节点的子节点中存在叶子节点***，故返回不为空的孩子节点（叶子节点）的深度
//         // 当然了，若当前节点的左右子节点都不存在，那它就是叶子节点，总深度直接 +1 就好了，也符合这个 return 句法。
//         return 1 + max(minDepth(root->left), minDepth(root->right));
//     }
// };
// 116. 填充每个节点的下一个右侧节点指针
// 递归写法
// class Solution {
// public:
//     Node* connect(Node* root) {
//         if (root == NULL) return root;
//         if (root->left != NULL) {
//             root->left->next = root->right;
//             if (root->next != NULL) {
//                 root->right->next = root->next->left;
//             }
//         }
//         connect(root->left);
//         connect(root->right);
//         return root;
//     }
// };
// [用时:12 m 5 s] 常规做法，n  n
// class Solution {
// public:
//     Node* connect(Node* root) {
//         if (root == NULL) return root;
//         vector<Node*> cur = { root }, next;
//         while (!cur.empty()) {
//             for (int i = 0;i < cur.size();i++) {
//                 Node* node = cur[i];
//                 if (node->left) next.push_back(node->left);
//                 if (node->right) next.push_back(node->right);
//                 if (i == cur.size() - 1) break;
//                 cur[i]->next = cur[i + 1];
//             }
//             cur = next;
//             next.clear();
//         }
//         return root;
//     }
// };
// 515. 在每个树行中找最大值
// [用时:9 m 54 s] 内存消耗主要在三个数组和sort内存上，可以改为max_element
// class Solution {
// public:
//     vector<int> largestValues(TreeNode* root) {
//         if (root == NULL) return {};
//         vector<TreeNode*> cur = { root }, next;
//         vector<int> result;
//         while (!cur.empty()) {
//             auto it = max_element(cur.begin(), cur.end(), [](const TreeNode* a, const TreeNode* b) {
//                 return a->val < b->val;
//                 });
//             result.push_back((*it)->val);
//             // vector<TreeNode*> temp = cur;
//             // sort(temp.begin(), temp.end(), [](const TreeNode* a, const TreeNode* b) {
//             //     return a->val > b->val;
//             //     });
//             // result.push_back(temp[0]->val);
//             for (auto node : cur) {
//                 if (node->left) next.push_back(node->left);
//                 if (node->right) next.push_back(node->right);
//             }
//             cur = next;
//             next.clear();
//         }
//         return result;
//     }
// };
// 199. 二叉树的右视图
// 迭代写法
// class Solution {
// public:
//     vector<int> rightSideView(TreeNode* root) {
//         if (root == NULL) return {};
//         vector<TreeNode*> cur = { root }, next;
//         vector<int> result;
//         while (!cur.empty()) {
//             result.push_back(cur.back()->val);
//             for (auto node : cur) {
//                 if (node->left) next.push_back(node->left);
//                 if (node->right) next.push_back(node->right);
//             }
//             cur = next;
//             next.clear();
//         }
//         return result;
//     }
// };
// [用时:11 m 10 s] 递归写法
// class Solution {
// public:
//     void dfs(TreeNode* root, int depth, int& max_depth, vector<int>& result) {
//         if (root == NULL) return;
//         if (depth > max_depth) {
//             max_depth = depth;
//             result.push_back(root->val);
//         }
//         if (root->right) dfs(root->right, depth + 1, max_depth, result);
//         if (root->left) dfs(root->left, depth + 1, max_depth, result);
//     }
//     vector<int> rightSideView(TreeNode* root) {
//         int max_depth = -1;
//         vector<int> result;
//         dfs(root, 0, max_depth, result);
//         return result;
//     }
// };
// 513. 找树左下角的值
// 单队列写法，反转入队序列这样最后一个出队的就是最低端最左节点
// class Solution {
//     public:
//     int findBottomLeftValue(TreeNode* root) {
//         queue<TreeNode*> que;
//         TreeNode* node;
//         que.push(root);
//         while (!que.empty()) {
//             node = que.front();
//             que.pop();
//             if (node->right) que.push(node->right);
//             if (node->left) que.push(node->left);
//         }
//         return node->val;
//     }
// };
// BFS双数组方法
// class Solution {
//     public:
//     int findBottomLeftValue(TreeNode* root) {
//         if (root == NULL) return 0;
//         vector<TreeNode*> cur = { root }, next;
//         int left = 0;
//         while (!cur.empty()) {
//             left = cur[0]->val;
//             for (auto node : cur) {
//                 if (node->left) next.push_back(node->left);
//                 if (node->right) next.push_back(node->right);
//             }
//             cur = next;
//             next.clear();
//         }
//         return left;
//     }
// };
// dfs
// class Solution {
// public:
//     // int treeDepth(TreeNode* root) {
//     //     if (root == NULL) return 0;
//     //     return max(treeDepth(root->left), treeDepth(root->right)) + 1;
//     // }
//     void dfs(TreeNode* root, int depth, int& maxDepth, int& left) {
//         if (root == NULL) return;
//         if (depth > maxDepth) {
//             maxDepth = depth;
//             left = root->val;
//         }
//         dfs(root->left, depth + 1, maxDepth, left);
//         dfs(root->right, depth + 1, maxDepth, left);
//     }
//     int findBottomLeftValue(TreeNode* root) {
//         int left = 0, maxDepth = -1;
//         dfs(root, 0, maxDepth, left);
//         return left;
//     }
// };
// 深度优先搜索算法 12mins
// class Solution {
// public:
//     int treeDepth(TreeNode* root) {
//         if (root == NULL) return 0;
//         int max_left = treeDepth(root->left);
//         int max_right = treeDepth(root->right);
//         return max(max_left, max_right) + 1;
//     }
//     void dfs(vector<vector<int>>& result, TreeNode* node, int deep) {
//         if (node == NULL) return;
//         else {
//             result[deep].push_back((node->val));
//             dfs(result, node->left, deep + 1);
//             dfs(result, node->right, deep + 1);
//         }
//     }
//     vector<vector<int>> levelOrder(TreeNode* root) {
//         int deep = treeDepth(root);
//         vector<vector<int>> result(deep);
//         dfs(result, root, 0);
//         return result;
//     }
// };
// vector<int> preorderTraversal(TreeNode* root) {
//     stack<TreeNode*> st;
//     vector<int> result;
//     if (root == NULL) return result;
//     st.push(root);
//     while (!st.empty()) {
//         TreeNode* node = st.top();
//         st.pop();
//         result.push_back(node->val);
//         if (node->left != nullptr) st.push(root->left);
//         if (node->right != nullptr) st.push(root->right);
//     }
//     return result;
// }

// 递归模板，顺序随意调整
// void traversal(TreeNode* root, vector<int>& result) {
//     if (root == NULL) return;
//         traversal(root->left, result);
//         result.push_back(root->val);
//         traversal(root->right, result);
// }
// vector<int> preorderTraversal(TreeNode* root) {
//     vector<int> result;
//     traversal(root, result);
//     return result;
// }

// 根左右
// vector<int> preorderTraversal(TreeNode* root) {
//     vector<int> result;
//     if (root == NULL) return result;
//     stack<TreeNode*> st;
//     st.push(root);
//     while (!st.empty()) {
//         TreeNode* node = st.top();
//         result.push_back(node->val);
//         st.pop();
//         if (!st.empty()) {
//             if (node->left != nullptr) st.push(root->left);
//             if (node->right != nullptr) st.push(root->right);
//         }
//     }
//     reverse(result.begin(),result.end());// 左右根
//     return result;
// }

// 中序遍历
// vector<int> inorderTraversal(TreeNode* root) {
//     vector<int> result;
//     stack<TreeNode*> st;
//     st.push(root);
//     TreeNode* cur = root;
//     while (!st.empty() && cur!=NULL) {
//         if (cur != NULL) {
//             st.push(cur);
//             cur = cur->left;
//         }
//         else {
//             cur = st.top();
//             st.pop();
//             result.push_back(cur->val);
//             cur = cur->right;
//         }
//     }
//     return result;
// }
// 103. 二叉树的锯齿形层序遍历
// 2025-02-22 23:55:16
// 12mins 层序遍历的双数组做法，通过翻转level数组得到，本质上还是层序遍历
// class Solution {
// public:
//     vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
//         if (root == NULL) return {};
//         vector<vector<int>> result;
//         vector<TreeNode*> cur = { root }, next;
//         bool need_reversal = false;
//         while (!cur.empty()) {
//             vector<int> level;
//             // TreeNode* node = root;
//             for (auto node : cur) {
//                 level.push_back(node->val);
//                 if (node->left) next.push_back(node->left);
//                 if (node->right) next.push_back(node->right);
//             }
//             cur = next;
//             next.clear();
//             if (need_reversal) {
//                 reverse(level.begin(), level.end());
//             }
//             result.push_back(level);
//             need_reversal = !need_reversal;
//         }
//         return result;
//     }
// };
// 102. 二叉树的层序遍历
// 2025-02-22 23:09:28
// 双数组写法
// 9:23  两个数组形式
// class Solution {
// public:
//     vector<vector<int>> levelOrder(TreeNode* root) {
//         if (root == NULL) return {};
//         vector<TreeNode*> cur, next;
//         vector<vector<int>> result;
//         cur.push_back(root);
//         while (!cur.empty()) {
//             vector<int> level;
//             for (auto node : cur) {
//                 level.push_back(node->val);
//                 if (node->left) next.push_back(node->left);
//                 if (node->right) next.push_back(node->right);
//             }
//             cur = next;
//             next.clear();
//             result.push_back(level);
//         }
//         return result;
//     }
// };
// 5mins 理解代码之后写 队列写法
// class Solution {
// public:
//     vector<vector<int>> levelOrder(TreeNode* root) {
//         queue<TreeNode*> que;
//         if (root != NULL) que.push(root);
//         vector<vector<int>> result;
//         while (!que.empty()) {
//             int size = que.size();
//             vector<int> level;
//             for (int i = 0;i < size;i++) {
//                 TreeNode* node = que.front();
//                 que.pop();
//                 level.push_back(node->val);
//                 if (node->left) que.push(node->left);
//                 if (node->right) que.push(node->right);
//             }
//             result.push_back(level);
//         }
//         return result;
//     }
// };
// 层序遍历模板
// vector<vector<int>> levelOrderTraversal(TreeNode* root) {
//     vector<vector<int>> ans;
//     queue<TreeNode*> q;
//     if (root != NULL) q.push(root);
//     while (!q.empty()) {
//         int levelSize = q.size();
//         vector<int> level;
//         for (int i = 0;i < levelSize;i++) {
//             TreeNode* node = q.front();
//             q.pop();
//             level.push_back(node->val);
//             if (node->left != NULL) q.push(node->left);
//             if (node->right != NULL) q.push(node->right);
//         }
//         ans.push_back(level);
//     }
//     return ans;
// }

// vector<vector<int>> levelOrder(TreeNode* root) {
//     vector<vector<int>> result; // 存储最终结果
//     if (!root) return result;   // 如果树为空，直接返回
//     queue<TreeNode*> q; // 使用队列进行 BFS
//     q.push(root);       // 将根节点加入队列
//     while (!q.empty()) {
//         int levelSize = q.size(); // 当前层的节点数
//         vector<int> currentLevel; // 存储当前层的节点值
//         for (int i = 0; i < levelSize; ++i) {
//             TreeNode* currentNode = q.front(); // 取出队首节点
//             q.pop();
//             currentLevel.push_back(currentNode->val); // 将节点值存入当前层
//             if (currentNode->left) q.push(currentNode->left);
//             if (currentNode->right) q.push(currentNode->right);
//         }
//         result.push_back(currentLevel); // 将当前层加入结果
//     }
//     return result;
// }
// 中序遍历模板
// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> result;
//         stack<TreeNode*> st;
//         st.push(root);
//         TreeNode* cur = root;
//         while (cur != NULL && !st.empty()) {
//             if (cur != NULL) {
//                 st.push(cur);
//                 cur = cur->left;
//             }
//             else {
//                 cur = st.top();
//                 st.pop();
//                 result.push_back(cur->val);
//                 cur = cur->right;
//             }
//         }
//         return result;
//     }
// vector<int> inorderTraversal(TreeNode* root) {
//     stack<TreeNode*> st;
//     vector<int> result;
//     TreeNode* cur = root;
//     while (cur != NULL && !st.empty()) {
//         if (cur != NULL) {
//             st.push(cur);
//             cur = cur->left;
//         }
//         else {
//             cur = st.top();
//             st.pop();
//             result.push_back(cur->val);
//             cur = cur->right;
//         }
//     }
//     return result;
// }
// };
// 前序遍历模板
// class Solution {
//     vector<int> preorderTraversal(TreeNode* root) {
//         stack<TreeNode*> st;
//         vector<int> result;
//         if (root == NULL) return result;
//         st.push(root);
//         while (!st.empty()) {
//             TreeNode* node = st.top();
//             st.pop();
//             result.push_back(node->val);
//             if (node->right) st.push(node->right);
//             if (node->left) st.push(node->left);
//         }
//     }
// }
// 841. 钥匙和房间
// 2025-02-20 13:48:31
// class Solution {
// public:
//     bool dfs(vector<vector<int>>& adjacent, int current, int& count, vector<bool>& visited) {
//         if (!visited[current]) {
//             visited[current] = true;
//             count++;
//         }
//         if (count == adjacent.size()) {
//             return true;
//         }
//         for (int neighbor : adjacent[current]) {
//             if (!visited[neighbor]) {
//                 if (dfs(adjacent, neighbor, count, visited)) {
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }
//     bool canVisitAllRooms(vector<vector<int>>& rooms) {
//         int content = rooms.size();
//         int count = 0;
//         vector<bool> visited(content, false);
//         return dfs(rooms, 0, count, visited);
//     }
// };
// 797. 所有可能的路径
// 2025-02-20 13:48:16
// class Solution {
// public:
//     void dfs(vector<vector<int>>& graph, int current, vector<int>& path, vector<vector<int>>& result) {
//         int n = graph.size();
//         path.push_back(current);
//         if (current == n - 1) {
//             result.push_back(path);
//         }
//         else {
//             for (auto neighbor : graph[current]) {
//                 dfs(graph, neighbor, path, result);
//             }
//         }
//         path.pop_back();
//     }
//     vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
//         vector<int> path;
//         vector<vector<int>> result;
//         dfs(graph, 0, path, result);
//         return result;
//     }
// };
/////////////////复习之前的算法////////////////
// 3404. 统计特殊子序列的数目
// 1995. 统计特殊四元组
// 2025-01-30 11:20:26
// 三数之和翻版
// 2025-01-30 10:34:13
// 00 : 44 : 55  想不出更好的方法
// n4 n3 做法，朴素枚举或者使用一个哈希表
// class Solution {
// public:
//     int countQuadruplets(vector<int>& nums) {
//         int n = nums.size(),count = 0;
//         unordered_map<int, int> mapping;
//         for (int c = n - 2; c >= 2;c--){
//             ++mapping[nums[c + 1]];
//             for (int a = 0; a < c;a++){
//                 for (int b = a + 1; b < c;b++){
//                     count += mapping[nums[a] + nums[b] + nums[c]];
//                 }
//             }
//         }
//             return count;
//     }
// };
// 1031. 两个非重叠子数组的最大和
// 2025-01-30 09:55:20
// class Solution {
// public:
//     int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
//         int n = nums.size(), ans = 0, maxA = 0, maxB = 0 ,s[n + 1];
//         s[0] = 0;
//         partial_sum(nums.begin(), nums.end(), s + 1);
//         for(int i=firstLen+secondLen;i<=n;i++){
//             maxA = max(maxA, s[i - secondLen] - s[i - firstLen - secondLen]);
//             maxB = max(maxB, s[i - firstLen] - s[i - firstLen -  secondLen]);
//             ans = max(ans, max(maxA + s[i] - s[i - secondLen],
//                                maxB + s[i] - s[i - firstLen]));
//         }
//         return ans;
//     }
// };
// 1031. 两个非重叠子数组的最大和
// class Solution {
// public:
//     int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
//         int n = nums.size();
//         int result = 0, ps[n + 1] = {};
//         partial_sum(nums.begin(), nums.end(), ps+1);
//         auto func = [&](int f, int s){
//             int maxSum = 0;
//             for (int i = f + s; i < n;i++){
//                 maxSum = max(maxSum, ps[i - s] - ps[i - f - s]);
//                 result = max(result, maxSum + ps[i] - ps[i - s]);
//             }
//         };
//         func(firstLen, secondLen);
//         func(secondLen, firstLen);
//         return result;
//     }
// };
// 2874. 有序三元组中的最大值 II
// 两种解法共耗时34mins
// 枚举k
// class Solution {
// public:
//     long long maximumTripletValue(vector<int>& nums) {
//         long long result = 0;
//         int max_diff = 0, maxone = 0;// 注意这里必须设置为0
//         for (int i = 0; i < nums.size();i++){ // 循环也必须从零开始
//             result = max(result, (long long)nums[i] * max_diff);
//             max_diff = max(max_diff, maxone - nums[i]);
//             maxone = max(maxone, nums[i]);
//         }
//         return result;
//     }
// };
// 枚举j
// class Solution {
// public:
//     long long maximumTripletValue(vector<int>& nums) {
//         int n = nums.size();
//         long long maxresult = 0;
//         vector<int> premax(n);
//         vector<int> aftermax(n);
//         premax[0] = nums[0];
//         aftermax[n - 1] = nums.back();
//         for (int i = 1, j = n - 2; i<n-1, j>= 0;i++,j--){
//             premax[i] = max(premax[i - 1], nums[i]);
//             aftermax[j] = max(aftermax[j + 1], nums[j]);
//         }
//         for (int k = 1; k < n - 1;k++){
//             maxresult = max(maxresult, (long long)(premax[k - 1] - nums[k]) * aftermax[k+1]);
//         }
//         return maxresult;
//     }
// };
// hot200题，这题没过，交换字符
// class Solution {
// public:
//     void insert(unordered_map<string,int>& mapping,int input){
//         string str = to_string(input);
//         int temp = input,count=0;
//         while(temp>0){
//             temp /= 10;
//             count++;
//         }
//         for (int i = 0; i < count;i++){
//             for (int j = i; j < count;j++){
//                 char tempA = str[i], tempB = str[j];
//                 str[i] = tempB;
//                 str[j] = tempA;
//                 mapping[str]++;
//             }
//         }
//         for (int i = 0; i < count;i++){
//             for (int j = i; j < count;j++){
//                 char tempA = str[i], tempB = str[j];
//                 str[i] = tempB;
//                 str[j] = tempA;
//                 mapping[str]++;
//             }
//         }
//     }
//     int countPairs(vector<int>& nums) {
//         unordered_map<string,int> mapping;
//         int ans = 0;
//         for(int num : nums){
//             string key_string = to_string(num);
//             if(mapping.find(key_string)!=mapping.end()){
//                 ans += mapping[key_string];
//             }
//             insert(mapping, num);
//         }
//         return ans;
//     }
// };
// 3371. 识别数组中的最大异常值
// 2025-01-26 22:09:51
// 2025-01-26 23:26:09
// 没做出来，看提示因为stl数据结构特性导致算法有漏洞，看题解和多种做法
// class Solution {
// public:
//     int getLargestOutlier(vector<int>& nums) {
//         int sum = reduce(nums.begin(), nums.end(), 0);
//         int result = INT_MIN;
//         for (int i = 0;i<nums.size();i++){
//             if((sum-nums[i])%2==1){
//                 continue;
//             }
//             nums.erase(nums.begin() + i);
//             auto it = find(nums.begin(), nums.end(), (sum - nums[i])/2);
//             if(it!=nums.end()){
//                 result = max(result, nums[i]);
//             }
//             nums.emplace_back(nums[i]);
//         }
//         return result;
//     }
// };
// 454. 四数相加 II
// 2025-01-26 20:45:22
// 00 : 18 : 06  2n n 两数之和模拟法本质上是两数之和翻版
// class Solution {
// public:
//     int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
//         unordered_map<int, int> mapping1;
//         unordered_map<int, int> mapping2;
//         int ans = 0;
//         for(int x : nums1){
//             for(int y : nums2){
//                 mapping1[x + y]++;
//             }
//         }
//         for(int x : nums3){
//             for(int y : nums4){
//                 mapping2[x + y]++;
//             }
//         }
//         for (auto it1 = mapping1.begin();it1!=mapping1.end();it1++){
//             auto it2 = mapping2.find(-it1->first);
//             if(it2!=mapping2.end()){
//                 ans += (it1->second) * (it2->second);
//             }
//         }
//         return ans;
//     }
// };
// 面试题 16.24. 数对和
// 2025-01-26 20:18:50
// class Solution {
// public:
//     vector<vector<int>> pairSums(vector<int>& nums, int target) {
//         sort(nums.begin(), nums.end());
//         vector<vector<int>> ans;
//         int left = 0,right = nums.size()-1;
//         while(left < right){
//             if(nums[left]+nums[right]>target){
//                 right--;
//             }else if(nums[left]+nums[right]<target){
//                 left++;
//             }else{
//                 ans.emplace_back(vector<int>{nums[left++], nums[right--]});
//             }
//         }
//         return ans;
//     }
// };

// 1031. 两个非重叠子数组的最大和
// 2025-01-26 17:13:24
// 2025-01-26 17:47:42
// 写不出来，不能凭记忆做题，对于两数之和类型题目，如果“数”是容器，则需要前缀和解决
// class Solution {
// public:
//     int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
//         int n = nums.size();
//         auto f = [&](int firstlen, int secondlen){
//             int sum1 = reduce(nums.begin(), nums.begin() + firstlen);
//             int sum2 = reduce(nums.begin()+firstlen, nums.begin() + firstlen+secondlen);
//             int result = sum1 + sum2;
//             for (int i = firstlen + secondlen; i < n;i++){
//                 sum1 = max(sum1, sum1 + nums[i - secondlen] - nums[i - firstlen - secondlen]);
//                 sum2 = max(sum2, sum2 + nums[i] - nums[i - secondlen]);
//                 result = max(result, sum1 + sum2);
//             }
//             return result;
//         };
//         return max(f(firstLen, secondLen), f(secondLen, firstLen));
//     }
// };
// 第一次写，没写出来，看题解
// class Solution {
// public:
//     vector<int> findIndices(vector<int> &nums, int indexDifference, int valueDifference) {
//         int max_idx = 0, min_idx = 0;
//         for (int j = indexDifference; j < nums.size(); j++) {
//             int i = j - indexDifference;
//             if (nums[i] > nums[max_idx]) {// mark1
//                 max_idx = i;
//             } else if (nums[i] < nums[min_idx]) { // mark2
//                 min_idx = i;
//             }
//             if (nums[max_idx] - nums[j] >= valueDifference) { // mark3
//                 return {max_idx, j};
//             }
//             if (nums[j] - nums[min_idx] >= valueDifference) { // mark4
//                 return {min_idx, j};
//             }
//         }
//         return {-1, -1};
//     }
// };
// 1814. 统计一个数组中好对子的数目
// 2025-01-26 15:08:54
// 2025-01-26 15:30:25
// 00 : 22 : 02  n n 同样的套路
// class Solution {
// public:
//     const int p = 1000000007;
//     int rev(int x ){
//         int result = 0;
//         while(x>0){
//             result = result * 10 + x % 10;
//             x /= 10;
//         }
//         return result;
//     }
//     int countNicePairs(vector<int>& nums) {
//         unordered_map<int,int> mapping;
//         int count = 0,tem0 =0;
//         for (int x:nums){
//             count += mapping[x - rev(x)]++;
//             count %= p;
//         }
//         return count;
//     }
// };

// 1014. 最佳观光组合
// 2025-01-26 14:57:57
// 2025-01-26 15:06:06
// 00 : 08 : 57 n 1 简单模拟，和前面的题一样套路，先检索，后更新
// class Solution {
// public:
//     int maxScoreSightseeingPair(vector<int>& values) {
//         int maxA = 0, result = 0;
//         for (int i = 0; i < values.size();i++){
//             result = max(result, maxA + values[i] - i);
//             maxA = max(maxA, values[i] + i);
//         }
//         return result;
//     }
// };
// 2874. 有序三元组中的最大值 II
//  00 : 12 : 49   n n 枚举k做法
// 2025-01-26 14:55:39
// class Solution {
// public:
//     long long maximumTripletValue(vector<int>& nums) {
//         int n = nums.size();
//         long long ans =0;
//         vector<int> premax(n, 0), aftermax(n, 0);
//         premax[0] = nums[0];
//         aftermax[n - 1] = nums[n - 1];
//         for (int i = 1,j = n - 2; i < n - 1,j >= 0;i++,j--){
//             premax[i] = max(premax[i - 1], nums[i]);
//             aftermax[j] = max(aftermax[j + 1], nums[j]);
//         }
//         for (int i = 1; i < n - 1;i++){
//             ans = max(ans, (long long)(premax[i - 1] - nums[i]) * aftermax[i + 1]);
//         }
//         return ans;
//     }
// };
// int main(){
//     vector<int> test = {12,6,1,2,7};
//     Solution sol;
//     cout << sol.maximumTripletValue(test);
// }
// 2025-01-26 14:01:35
// 2025-01-26 14:41:42
// class Solution {
// public:
//     long long maximumTripletValue(vector<int>& nums) {
//         long long result = 0;
//         int maxone = 0;
//         int max_sub = 0;
//         for(int num :nums){
//             result = max(result,(long long) max_sub * num);
//             max_sub = max(max_sub, maxone - num);
//             maxone = max(maxone, num);
//         }
//         return result;
//     }
// };
// 2748. 美丽下标对的数目
// 2025-01-26 10:11:50
// 2025-01-26 10:42:01
// 00 : 29 : 18  对于定容数组vector，要注意循环的终止条件，
// class Solution {
// public:
//     int countBeautifulPairs(vector<int>& nums) {
//         int first[10] = {};
//         int count = 0;
//         for(int x : nums){
//             int tail = x % 10;
//             int head = x;
//             while (head >= 10){
//                 head /= 10;
//             }
//             for (int i = 0; i <= 9;i++) {
//                 if(gcd(i,tail)==1){
//                     count += first[i];
//                 }
//             }
//             first[head]++;
//         }
//         return count;
//     }
// };

// 3185. 构成整天的下标对数目 II
// 20mins 同上一题
// class Solution {
// public:
//     long long countCompleteDayPairs(vector<int>& hours) {
//         vector<int> mapping(24, 0);
//         int i = 1, j = 23;
//         long ans = 0;
//         for(int x : hours){
//             mapping[x % 24]++;
//         }
//         while(i<j){
//             ans += mapping[i++] * mapping[j--];
//         }
//         return ans + (long)mapping[0] * (mapping[0] - 1) / 2 + (long)mapping[12] * (mapping[12] - 1) / 2;
//     }
// };
// 1010. 总持续时间可被 60 整除的歌曲
// 2025-01-25 19:45:55
// 2025-01-25 20:30:55
// class Solution {
// public:
//     int numPairsDivisibleBy60(vector<int>& time) {
//         unordered_map<int,int> mapping;
//         long ans = 0;
//         long temp = 0;
//         for(int i =0;i<time.size();i++){
//             if(time[i]%60==0)
//                 temp++;
//             if (mapping.count(time[i]%60) > 0){
//                 ans += mapping[time[i] % 60];
//             // }else{
//             }
//             mapping[60 - time[i] % 60]++;
//         }
//         return ans + temp*(temp-1)/2;
//     }
// };
// 2260. 必须拿起的最小连续卡牌数
// 2025-01-25 19:00:50
// 00 : 36 : 28  n n 还是先查询再更新的操作，但是这种两数之和题目要注意更新条件，
// class Solution {
// public:
//     int minimumCardPickup(vector<int>& cards) {
//         unordered_map<int, int> mapping;
//         int ans = INT_MAX;
//         for (int i = 0; i < cards.size();i++) {
//             if(mapping.find(cards[i])!=mapping.end()){
//                 ans = min(ans, i - mapping[cards[i]]);
//             // }else{ 不能在这里使用else
//             }
//             mapping[cards[i]] = i;
//         }
//         return ans == INT_MAX ? -1 : ans+1;
//     }
// };
// 1679. K 和数对的最大数目
// 2025-01-25 18:49:24
// 00 : 42 : 07 n n
// class Solution {
// public:
//     int maxOperations(vector<int>& nums, int k) {
//         unordered_map<int,int> mapping;
//         int count = 0;
//         for (int i = 0; i < nums.size();i++){
//             auto it = mapping.find(nums[i]);
//             if (it!=mapping.end()&&it->second!=0){
//                 mapping[nums[i]]--;
//                 count++;
//             }else{
//                 mapping[k - nums[i]]++;
//             }
//         }
//         return count;
//     }
// };
// 2815. 数组中的最大数对和
// 2025-01-25 17:04:44
// 00 : 23 : 00 n 1 标记此处法和，思路和2815. 数组中的最大数对和一样
// class Solution {
// public:
//     int maxone(int i){
//         int result = 0;
//         while(i>0){
//             result = max(result, i % 10);
//             i /= 10;
//         }
//         return result;
//     }
//     int maxSum(vector<int>& nums) {
//         int r = 0, maxresult = -1;
//         int mapping[10] = {};
//         for (int i = 0;i<nums.size();i++){
//             r = maxone(nums[i]);
//             if(mapping[r]!= 0){
//                 maxresult = max(maxresult, mapping[r]+nums[i]);
//             }
//             mapping[r] = max(mapping[r], nums[i]);
//         }
//         return maxresult;
//     }
// };
// 121. 买卖股票的最佳时机,
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int max_profit = INT_MIN;
//         int minone = INT_MAX;
//         for (int i = 0; i < prices.size();i++){
//             max_profit = max(max_profit, prices[i] - minone);
//             minone = min(minone, prices[i]);
//         }
//         return max_profit > 0 ? max_profit : 0;
//     }
// };
// 219. 存在重复元素 II
// 2025-01-25 15:32:45
// 滑动窗口经典做法，需要注意边界值，在读完题目后仔细看测试数据范围写在草稿最上面
// class Solution {
// public:
//     bool containsNearbyDuplicate(vector<int>& nums, int k) {
//         unordered_set<int> hash;
//         if(k<1)
//             return false;
//         for (int i = 0; i < nums.size();i++){
//             if(hash.find(nums[i])!=hash.end()){
//                 return true;
//             }
//             if(hash.size() == k){
//                 hash.erase(nums[i - k]);
//             }
//             hash.insert(nums[i]);
//         }
//         return false;
//     }
// };
// 2001. 可互换矩形的组数
// 2025年1月25日14:42:18
// 00 : 04 : 25 n  n 这题重点在于精度控制和类型转换，思路和1512一致，使用double时刻提醒要用1.0*，题目数据量很大注意long而不是int
// class Solution {
// public:
//     long long interchangeableRectangles(vector<vector<int>>& rectangles) {
//         unordered_map<double ,int> mapping;
//         long long  ans = 0;
//         for (int i = 0; i < rectangles.size();i++){
//             ans += mapping[1.0 * rectangles[i][0] / rectangles[i][1]]++;
//         }
//         return ans;
//     }
// };
// 1512. 好数对的数目
// 2025年1月25日14:27:19
// 3rd n n 00 : 10 : 03 ++i和i++最有用的一次
// class Solution {
// public:
//     int numIdenticalPairs(vector<int>& nums) {
//         unordered_map<int, int> myMap;
//         int ans = 0;
//         for (int i = 0; i < nums.size();i++){
//             ans += myMap[nums[i]]++;
//         }
//         return ans;
//     }
// };
// 1. 两数之和
// 00 : 20 : 21 nlogn n labuladuo双指针法，因为不知道怎么向前移动一次迭代器而浪费了一点时间，prev函数可以实现并且可以自定义移动距离。双指针经常用与 a$b%c 三数字关系题目中，左右两边（根据某种条件）交替遍历（一般需要满足某种条件的数组才可以），不然双指针不会向中间靠拢 while 循环也就无法结束
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         multimap<int,int> mapping;
//         int n = nums.size();
//         for (int i = 0; i < n;i++){
//             mapping.insert({nums[i],i});
//         }
//         auto left = mapping.begin();
//         auto right = prev(mapping.end());
//         while(left!=right){
//             if((left->first)+(right->first)<target){
//                 left++;
//             }else if((left->first)+(right->first)>target){
//                 right--;
//             }else{
//                 return {left->second, right->second};
//             }
//         }
//         return {-1, -1};
//     }
// };
// 2025年1月25日13:27:11
// 00 : 10 : 44   n n 第三次复习，最常用的先查询，后更新思路
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         unordered_map<int,int> mapping;
//         vector<int> ans(2, -1);
//         for (int i = 0; i < nums.size();i++){
//             auto it = mapping.find(nums[i]);
//             if(it!=mapping.end()){
//                 ans = {it->second, i};
//             }
//             mapping[target - nums[i]] = i;
//         }
//         return ans;
//     }
// };

/////////////////上面是复习之前的算法/////////////
// typedef pair<int, int> pii;
// class Graph {
// public:
//     int vertex;
//     vector<vector<pii>> adjacent;// weight, to_point
//     Graph(int v) : vertex(v), adjacent(vertex) {};
//     void addEdge(int u, int v, int weight) {
//         adjacent[u].emplace_back(weight, v);
//         // adjacent[v].emplace_back(weight, u);
//     }
// };
// class Solution {
// public:
//     vector<int> dijkstra(Graph& graph, int source) {
//         int v = graph.vertex;
//         priority_queue <pii, vector<pii>, greater<pii>> pq;
//         pq.emplace(0, source);
//         vector<int> dist(v, numeric_limits<int>::max());
//         dist[source] = 0;
//         while (!pq.empty()) {
//             int current_dist = pq.top().first;
//             int u = pq.top().second;
//             pq.pop();
//             if (current_dist > dist[u]) {
//                 continue;
//             }
//             for (auto& edge : graph.adjacent[u]) {
//                 int weight = edge.first;
//                 int v = edge.second;
//                 if (dist[u] + weight < dist[v]) {
//                     dist[v] = dist[u] + weight;
//                     pq.emplace(dist[v], v);
//                 }
//             }
//         }
//         return dist;
//     }
//     int networkDelayTime(vector<vector<int>>& times, int n, int k) {
//         const int m = numeric_limits<int>::max();
//         int max_time = 0;
//         Graph g(n);
//         for (auto x : times) {
//             g.addEdge(x[0] - 1, x[1] - 1, x[2]);
//         }
//         vector<int> ans = dijkstra(g, k - 1);
//         for (auto x : ans) {
//             if (x == m) {
//                 return -1;
//             }
//             else {
//                 max_time = max(max_time, x);
//             }
//         }
//         return max_time;
//     }
// };

// 3. 无重复字符的最长子串
// 哈希表记录位置法
// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int n = s.length(), max_length = 0, left = 0;
//         unordered_map<char, int> mapping;
//         for (int right = 0;right < n;right++) {
//             if (mapping.contains(s[right]) && mapping[s[right]] >= left) {
//                 left = mapping[s[right]] + 1;
//             }
//             mapping[s[right]] = right;
//             max_length = max(max_length, right - left + 1);
//         }
//         return max_length;
//     }
// };
// 滑动窗口没有正确收缩的错误写法
// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         unordered_set<char> mapping;
//         int n = s.length(), left = 0, max_length = 0, temp_length = 0;
//         for (int right = 0;right < n;right++) {
//             if (mapping.find(s[right])!=mapping.end()) {
//                 temp_length = max(temp_length, right - left);
//                 max_length = max(max_length, temp_length);
//                 temp_length = 0;
//                 left = right;
//                 mapping.clear();
//             }
//             else {
//                 mapping.insert(s[right]);
//             }
//         }
//         return max_length;
//     }
// };

// 713. 乘积小于 K 的子数组
// 2025-02-17 11:31:42 18mins 写不出来看题解
// 前缀和做法
// class Solution {
// public:
//     int numSubarrayProductLessThanK(vector<int>& nums, int k) {
//         if (k <= 1) {
//             return 0;
//         }
//         int n = nums.size();
//         vector<double> logPrefix(n + 1);
//         for (int i = 0; i < n; i++) {
//             logPrefix[i + 1] = logPrefix[i] + log(nums[i]);
//         }
//         double logk = log(k);
//         int ret = 0;
//         for (int j = 0; j < n; j++) {
//             int l = upper_bound(logPrefix.begin(), logPrefix.begin() + j + 1, logPrefix[j + 1] - log(k) + 1e-10) - logPrefix.begin();
//             ret += j + 1 - l;
//         }
//         return ret;
//     }
// };
// class Solution {
// public:
//     int numSubarrayProductLessThanK(vector<int>& nums, int k) {
//         if (k <= 1) return 0;
//         int n = nums.size(), count = 0, left = 0;
//         vector<long long> pre_multi(n + 1, 1);
//         partial_sum(nums.begin(), nums.end(), pre_multi.begin() + 1, [](const int a, const int b) {
//             return a * b;
//             });
//         for (int right = 0;right < n;right++) {
//             long long to_find = pre_multi[right + 1] / k;
//             auto it = upper_bound(pre_multi.begin(), pre_multi.begin() + right + 1, to_find);
//             if (it != pre_multi.end()) {
//                 int temp = it - pre_multi.begin();
//                 count += right + 1 - temp;
//             }
//         }
//         return count;
//     }
// };
// class Solution {
// public:
//     int numSubarrayProductLessThanK(vector<int>& nums, int k) {
//         int n = nums.size(), left = 0, count = 0;
//         long long multi = 1;
//         for (int right = 0;right < n;right++) {
//             multi *= nums[right];
//             while (left <= right && multi >= k) {
//                 multi /= nums[left];
//                 left++;
//             }
//             count += right - left + 1;
//         }
//         return count;
//     }
// };
// 209. 长度最小的子数组
// 前缀和方法
// class Solution {
// public:
//     int minSubArrayLen(int target, vector<int>& nums) {
//         int n = nums.size();
//         vector<int> pre_sum(n + 1, 0); // 前缀和数组
//         partial_sum(nums.begin(), nums.end(), pre_sum.begin() + 1);
//         int min_length = INT_MAX;
//         for (int i = 1; i <= n; i++) {
//             int to_find = pre_sum[i] - target;
//             auto it = upper_bound(pre_sum.begin(), pre_sum.end(), to_find);
//             if (it != pre_sum.begin()) {
//                 int j = it - pre_sum.begin() - 1;
//                 min_length = min(min_length, i - j);
//             }
//         }
//         return min_length == INT_MAX ? 0 : min_length;
//     }
// };
// 2025-02-17 10:02:32
// 写不出来看题解
// class Solution {
// public:
//     int minSubArrayLen(int target, vector<int>& nums) {
//         int n = nums.size(), left = 0, right = 0, sum = 0, length = INT_MAX;
//         for (right; right < n;right++) {
//             sum += nums[right];
//             while (left <= right&&sum >= target) {
//                 length = min(length, right - left + 1);
//                 sum -= nums[left];
//                 left++;
//             }
//         }
//         return length == INT_MAX ? 0 : length;
//     }
// };
// 739. 每日温度
// 2025-02-16 15:11:04
// 42. 接雨水
// 左右前缀和判断方法
// 24mins 相向双指针方法
// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int left_max = -1, right_max = -1, n = height.size(), count = 0;
//         int left = 0, right = n - 1;
//         while (left < right) {
//             left_max = max(left_max, height[left]);
//             right_max = max(right_max, height[right]);
//             if (left_max < right_max) {
//                 count += left_max - height[left++];
//             }
//             else {
//                 count += right_max - height[right--];
//             }
//         }
//         return count;
//     }
// };
// 2025-02-16 14:28:14
// 17mins 简单类似11.盛最多水的容器的解法
// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int n = height.size(), content = 0;
//         vector<int> left_max(n), right_max(n);
//         int temp_left = -1, temp_right = -1;
//         for (int i = 0,j=n-1;i < n - 1,j>=0;i++,j--) {
//             temp_left = max(temp_left, height[i]);
//             temp_right = max(temp_right, height[j]);
//             left_max[i] = temp_left;
//             right_max[j] = temp_right;
//         }
//         for (int k = 0;k < n;k++) {
//             content += min(left_max[k], right_max[k]) - height[k];
//         }
//         return content;
//     }
// };

// 15. 三数之和
// 2025-02-15 19:48:50
// 写不出来看题解
// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         ranges::sort(nums);
//         vector<vector<int>> ans;
//         int n = nums.size();
//         for (int i = 0;i < n - 2;i++) {
//             if (nums[i] > 0) break;
//             if (i && nums[i] == nums[i - 1]) continue;
//             if (nums[i] + nums[i + 1] + nums[i + 2] > 0) continue;
//             if (nums[i] + nums[n - 1] + nums[n - 2] < 0) continue;
//             int left = i + 1, right = n - 1;
//             while (left < right) {
//                 int s = nums[i] + nums[left] + nums[right];
//                 if (s > 0) right--;
//                 else if (s < 0) left++;
//                 else {
//                     ans.emplace_back(vector<int>{ nums[i], nums[left], nums[right] });
//                     for (++left;left < right && nums[left] == nums[left - 1];left + 1);
//                     for (--right;left < right && nums[right] == nums[right + 1];right--);
//                 }
//             }
//         }
//         return ans;
//     }
// };
// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         vector<vector<int>> ans;
//         int n = nums.size();
//         for (int i = 0;i < n - 2;i++) {
//             int x = nums[i];
//             if (i && x == nums[i - 1]) continue;
//             int left = i + 1, right = n - 1;
//             while (left < right) {
//                 int s = nums[right] + nums[left] + x;
//                 if (s > 0) right--;
//                 else if (s < 0) left++;
//                 else {
//                     ans.emplace_back(vector<int>{nums[i], nums[left], nums[right]});
//                     for (left++;left < right && nums[left] == nums[left - 1]; left++);
//                     for (right--;left < right && nums[right] == nums[right + 1];right--);
//                 }
//             }
//         }
//         return ans;
//     }
// };
// 167. 两数之和 II - 输入有序数组
// 5mins n 1 如果数组是有序的，可以使用双指针，因为指针的移动可以缩减范围
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& numbers, int target) {
//         int n = numbers.size(), left = 0, right = n - 1;
//         while (left < right) {
//             if (numbers[left] + numbers[right] > target) {
//                 right--;
//             }
//             else if (numbers[left] + numbers[right] < target) {
//                 left++;
//             }
//             else {
//                 return { left + 1,right + 1 };
//             }
//         }
//         return { left,right };
//     }
// };
// int main() {
//     unordered_map<int, int> mapping = { {0,1} };
//     cout << mapping.contains(0);
// }
// 1094. 拼车
// 2025-02-11 14:22:58
// struct Event {
//     int position;
//     int passengers;
//     bool is_pickup; // true for pick ,false for drop
// };
// class Solution {
// public:
//     bool carPooling(vector<vector<int>>& trips, int capacity) {
//         vector<Event> events;
//         for(auto& x : trips){
//             int num = x[0], from = x[1], to = x[2];
//             events.emplace_back(Event{ from,num,true });
//             events.emplace_back(Event{ to,num,false });
//         }
//         sort(events.begin(), events.end(), [&](const Event& x, const Event& y) -> bool {
//             if (x.position != y.position) {
//                 return x.position < y.position; // 如果x的position<y的position，则x需要先处理，x.position < y.position;得到true，true表示左边事件x需要放在右边事件y的左边
//             }
//             return !x.is_pickup && y.is_pickup; // 表示现在的情况是有两个事件的position相同，并且是左边的事件(x)要下车，右边事件(y)上车，如果是则两者的比较结果是左边数字应该放在右边数字的左边，反之则反之
//             });
//         int current_passe = 0;
//         for (auto event : events) {
//             if (event.is_pickup) {
//                 current_passe += event.passengers;
//                 if (current_passe > capacity) {
//                     return false;
//                 }
//             }
//             else {
//                 current_passe -= event.passengers;
//             }
//         }
//         return true;
//     }
// };
// 1477. 找两个和为目标值且不重叠的子数组
// 2025-02-11 14:09:58
// class Solution {
// public:
//     int minSumOfLengths(vector<int>& arr, int target) {
//         int presum = 0, n = arr.size();
//         unordered_map<int, int> mapping = {{0,0}};
//         for (int i = 0;i < n;i++) {
//             presum += arr[i];
//             auto it = mapping.find(presum);
//             if (it != mapping.end()) {

//             }
//             else {
//                 mapping[target + presum] = i;
//             }
//         }
//     }
// };
// 3026. 最大好子数组和
// 2025-02-11 10:34:52
// n n 总是卡在奇奇怪怪的测试集上
// class Solution {
// public:
//     long long maximumSubarraySum(vector<int>& nums, int k) {
//         int n = nums.size(), pre_sum = 0;
//         long long ans = 0;
//         long long max_sum = LONG_LONG_MIN;
//         unordered_map<long long, long long> mapping;
//         for (int x : nums) {
//             auto it1 = mapping.find(x + k);
//             auto it2 = mapping.find(x - k);
//             auto it = mapping.find(x);
//             if (it1 != mapping.end()) {
//                 ans = max(ans, pre_sum + x - it1->second);
//             }
//             if (it2 != mapping.end()) {
//                 ans = max(ans, pre_sum + x - it2->second);
//             }
//             if (it == mapping.end() || pre_sum < it->second) {
//                 mapping[x] = pre_sum;
//             }
//             pre_sum += x;
//         }
//         return ans == LONG_LONG_MIN ? 0 : ans;
//     }
// };
// 面试题 17.05.字母与数字
// [用时:49 m 36 s] n n 同525题，做的有点久
// 2025-02-11 09:30:00
// class Solution {
// public:
//     vector<string> findLongestSubarray(vector<string>& array) {
//         int n = array.size(), pre_sum = 0, max_length =0;
//         unordered_map<int, int> mapping = {{0,0}};
//         int position[2] = { 0,0 };
//         for (int i = 0;i < n;i++) {
//             isdigit(array[i][0]) ? pre_sum++ : pre_sum--;
//             if (!mapping.contains(pre_sum)) {
//                 mapping[pre_sum] = i + 1;
//             }
//             else {
//                 int index = i - mapping[pre_sum];
//                 if (max_length < index+1) {
//                     max_length = index+1;
//                     position[0] = mapping[pre_sum], position[1] = i;
//                 }
//             }
//         }
//         return max_length == 0 ? vector<string>{} : vector<string>(array.begin() + position[0], array.begin() + position[1] + 1);
//     }
// };
// 525. 连续数组
// 2025-02-10 21:27:27
// class Solution {
// public:
//     int findMaxLength(vector<int>& nums) {
//         int n = nums.size(), pre_sum = 0, max_length = 0;
//         unordered_map<int, int> mapping;
//         for (int i = 0;i < n;i++) {
//             pre_sum += nums[i] == 0 ? -1 : 1;
//             if (!mapping.contains(pre_sum)) {
//                 mapping[pre_sum] = i;
//             }
//             else {
//                 max_length = max(max_length, i - mapping[pre_sum]);
//             }
//         }
//         return max_length;
//     }
// };
// 53mins n n 写出的笨方法
// class Solution {
// public:
//     int findMaxLength(vector<int>& nums) {
//         int n = nums.size(), max_length =0;
//         vector<int> pre_sum(n + 1, 0);
//         unordered_map<int,int> mapping = {{0,0}};
//         partial_sum(nums.begin(), nums.end(), pre_sum.begin() + 1);
//         for (int i = 0;i < n + 1;i++) {
//             int result = 2 * pre_sum[i] - i;
//             if (!mapping.contains(result)) {
//                 mapping[result] = i;
//             }
//             else {
//                 max_length = max(max_length, i - mapping[result]);
//             }
//         }
//         return max_length;
//     }
// };
// int main(){
//     vector<int> test = {0,1};
//     Solution sol;
//     cout << sol.findMaxLength(test);
// }
// 2588. 统计美丽子数组数目
// 2025-02-10 20:54:42
// 暴力法
// class Solution {
// public:
//     bool is_right(vector<int> nums) {
//         vector<int> counts(32, 0);
//         int n = nums.size();
//         for (int i = 0;i < n;i++) {
//             string binary = bitset<32>(nums[i]).to_string();
//             for (int j = 0;j <32;j++) {
//                 counts[j] += (binary[j] - '0');
//             }
//         }
//         for (int i = 0;i < 32;i++) {
//             if (counts[i] % 2) {
//                 return false;
//             }
//         }
//         return true;
//     }
//     long long beautifulSubarrays(vector<int>& nums) {
//         int n = nums.size(),count = 0;
//         for (int i = 0;i < n;i++) {
//             for (int j = i;j < n;j++) {
//                 auto it = vector<int>(nums.begin() + i, nums.begin() + j + 1);
//                 is_right(it) ? count++ : 1;
//             }
//         }
//         return count;
//     }
// };
// 41mins n 1不会看题解 哈希表方法+异或
// class Solution {
// public:
//     long long beautifulSubarrays(vector<int>& nums) {
//         int n = nums.size(), s = 0;
//         unordered_map<int, int> mapping = {{s,1}};
//         long long count = 0;
//         for (int i = 0;i < n;i++) {
//             s ^= nums[i];
//             count += mapping[s]++;
//         }
//         return count;
//     }
// };
// 523. 连续的子数组和
// 2025-02-10 14:48:45
// 00 : 11 : 35 n n 延迟进入哈希表方法：
// class Solution {
// public:
//     bool checkSubarraySum(vector<int>& nums, int k) {
//         int n = nums.size();
//         long long pre_sum = 0;
//         unordered_set<int> mapping;
//         for (int i = 0;i < n;i++) {
//             pre_sum += nums[i];
//             int key = pre_sum % k;
//             auto it = mapping.find(key);
//             if (it != mapping.end()) {
//                 return true;
//             }
//             else {
//                 mapping.insert((pre_sum - nums[i])%k);
//             }
//         }
//         return false;
//     }
// };
// [用时:31 m 29 s] n k 哈希表 + 前缀和
// class Solution {
// public:
//     bool checkSubarraySum(vector<int>& nums, int k) {
//         int n = nums.size();
//         long long pre_sum = 0;
//         unordered_map<int, int> mapping;
//         mapping[0] = 0;
//         for (int i = 0;i < n;i++) {
//             pre_sum += nums[i];
//             int key = pre_sum % k;
//             if (mapping.count(key)&&i - mapping[key] >= 1) {
//                 return true;
//             }
//             else if (!mapping.count(key)) {
//                 mapping[key] = i+1;
//             }
//         }
//         return false;
//     }
// };
// 16 mins n 1 直接照搬974做法，思路是正确的，不知道输入1e9时为什么超内存，改成longlong仍然超内存
// class Solution {
// public:
//     bool checkSubarraySum(vector<int>& nums, int k) {
//         int n = nums.size();
//         int pre_sum = 0, count = 0, sub = 0;
//         vector<int> mapping(k, 0);
//         mapping[0] = 1;
//         for (int i = 0;i < n;i++) {
//             nums[i] % k == 0 ? sub++ : 1;
//             pre_sum += nums[i];
//             int key = (pre_sum % k + k) % k;
//             count += mapping[key]++;
//         }
//         return count - sub > 0 ? true : false;
//     }
// };
// 974. 和为奇数的子数组数目
// n 1 静态数组初始化大小的参数 * *必须是一个常量 * *，不能传入参数k进入
// class Solution {
// public:
//     int subarraysDivByK(vector<int>& nums, int k) {
//         int n = nums.size(), pre_sum = 0, count = 0, mapping[k] = {};
//         mapping[0] = 1;
//         for (int i = 0;i < n;i++) {
//             pre_sum += nums[i];
//             int key = (pre_sum % k + k) % k;
//             count += mapping[key]++;
//         }
//         return count;
//     }
// };
// 1524. 和为奇数的子数组数目
// n 1哈希表，结果是二元的，只需要数组即可做法比较费空间
// class Solution {
// public:
//     const int sigma = 1e9 + 7;
//     int numOfSubarrays(vector<int>& arr) {
//         long long pre_sum = 0, count = 0;
//         int mapping[2] = { 1,0 }, n = arr.size();
//         for (int i = 0;i < n;i++) {
//             pre_sum += arr[i];
//             int key = pre_sum % 2;
//             key == 1 ? count += mapping[0] : count += mapping[1];
//             mapping[key]++;
//             count %= sigma;
//         }
//         return count;
//     }
// };
// 暴力解法 n2 n
// class Solution {
// public:
//     const int SIGMA = 100000007;
//     int numOfSubarrays(vector<int>& arr) {
//         int n = arr.size(),count =0;
//         vector<int> pre_sum(n + 1);
//         partial_sum(arr.begin(), arr.end(), pre_sum.begin() + 1);
//         for (int i = 0;i <= n;i++) {
//             for (int j = i + 1;j <= n;j++) {
//                 int a = pre_sum[j] - pre_sum[i];
//                 if ((pre_sum[j] - pre_sum[i]) % 2 == 1) {
//                     count++;
//                     count %= SIGMA;
//                 }
//             }
//         }
//         return count;
//     }
// };
// 53. 最大子数组和
// 2025-02-08 17:09:15
// 11mins n n 之前用kadane算法过了，现在用前缀和算法
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int n = nums.size(), max_sum = INT_MIN, min_one = INT_MAX;
//         vector<int> pre_sum(n + 1);
//         partial_sum(nums.begin(), nums.end(), pre_sum.begin() + 1);
//         for (int i = 0;i <= n;i++) {
//             max_sum = max(max_sum, pre_sum[i] - min_one);
//             min_one = min(min_one, pre_sum[i]);
//         }
//         return max_sum==INT_MIN ? nums[0] : max_sum;
//     }
// };
// 1744. 你能在你最喜欢的那天吃到你最喜欢的糖果吗？
// 23mins 90%通过，n n计算天数莫名其妙会错，必须用糖果数量来计算
// class Solution {
// public:
//     vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
//         int n = candiesCount.size(), m = queries.size();
//         vector<long long> pre_sum(n + 1);
//         vector<bool> ans;
//         partial_sum(candiesCount.begin(), candiesCount.end(), pre_sum.begin() + 1);
//         for (int i = 0;i < m;i++) {
//             int longest = pre_sum[queries[i][0] + 1]-1;
//             int shortest = floor(pre_sum[queries[i][0]] / queries[i][2]);
//             if (queries[i][1] > shortest && queries[i][1] <= longest) {
//                 ans.emplace_back(true);
//             }
//             else {
//                 ans.emplace_back(false);
//             }
//         }
//         return ans;
//     }
// };
// 2055. 蜡烛之间的盘子
// 预处理每个盘子左边最近和右边最近的蜡烛，需要时直接查询
// class Solution {
// public:
//     vector<int> platesBetweenCandles(string s, vector<vector<int>>& qs) {
//         vector<int> l(s.length(), 0), r(s.length(), 0);
//         vector<int> pre_sum(s.length() + 1, 0);
//         for (int i = 0, j = s.length() - 1, closest_left = -1, closest_right = -1; i < s.length(); i++, j--) {
//             if (s[i] == '|') closest_left = i;
//             if (s[j] == '|') closest_right = j;
//             l[i] = closest_left; r[j] = closest_right;
//             pre_sum[i + 1] = pre_sum[i] + (s[i] == '*' ? 1 : 0);
//         }
//         vector<int> ans(qs.size(), 0);
//         for (int i = 0; i < qs.size(); i++) {
//             int a = qs[i][0], b = qs[i][1];
//             int c = r[a], d = l[b];
//             if (c != -1 && c <= d) ans[i] = pre_sum[d + 1] - pre_sum[c];
//         }
//         return ans;
//     }
// };
// 普通前缀和+二分查找的简化思路(不使用前缀和)
// class Solution {
// public:
//     vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
//         vector<int> list, ans;
//         for (int i = 0;i < s.length();i++)
//             if (s[i] == '|')
//                 list.emplace_back(i);
//         if (list.size() <= 1) return {0};
//         for (auto x : queries) {
//             auto left = lower_bound(list.begin(), list.end(), x[0]);
//             auto right = prev(upper_bound(list.begin(), list.end(), x[1]));
//             if (left >= right) {
//                 ans.emplace_back(0);
//             }else {
//                 ans.emplace_back(*right - *left - distance(left, right));
//             }
//         }
//         return ans;
//     }
// };

// [ 用时: 1 hrs 14 m 44 s ]nlogn n 前缀和+二分查找，普通的思路
// class Solution {
// public:
//     vector<int> platesBetweenCandles(string s, vector<vector<int>>& qs) {
//         vector<int> ans(qs.size(), 0);
//         vector<int> sum(s.length() + 1, 0);
//         vector<int> list;
//         for (int i = 0; i < s.length(); i++) {
//             if (s[i] == '|') list.push_back(i);
//             sum[i + 1] = sum[i] + (s[i] == '*' ? 1 : 0);
//         }
//         if (list.empty()) return ans;
//         for (int i = 0; i < qs.size(); i++) {
//             int a = qs[i][0], b = qs[i][1];
//             int c = -1, d = -1;
//             // 找到 a 右边最近的蜡烛
//             int l = 0, r = list.size() - 1;
//             while (l < r) {
//                 int mid = l + r >> 1;
//                 if (list[mid] >= a) r = mid;
//                 else l = mid + 1;
//             }
//             if (list[r] >= a) c = list[r];
//             else continue;
//             // 找到 b 左边最近的蜡烛
//             l = 0; r = list.size() - 1;
//             while (l < r) {
//                 int mid = l + r + 1 >> 1;
//                 if (list[mid] <= b) l = mid;
//                 else r = mid - 1;
//             }
//             if (list[r] <= b) d = list[r];
//             else continue;
//             if (c <= d) ans[i] = sum[d + 1] - sum[c];
//         }
//         return ans;
//     }
// };
// 2025-02-08 12:44:02
// 50min没写出来
// 这是错误写法,看题解
// class Solution {
// public:
//     vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
//         int n = s.length();
//         vector<int> str(n), ans(queries.size());
//         vector<int> pre_sum(n + 1);
//         for (int i = 0;i < n;i++) {
//             s[i] == '*' ? str[i] = 0 : str[i] = 1;
//             pre_sum[i + 1] = pre_sum[i] + str[i];
//         }
//         for (auto x : queries) {
//             auto left1 = str.begin()+x[0], right1 = str.begin() +  x[1];
//             auto it1 = find_if(left1, right1, 1);
//             auto left2 = reverse_iterator<decltype(left1)>(left1);
//             auto right2 = reverse_iterator<decltype(right1)>(right1);
//             auto it2 = find_if(right2,left2,1);
//             int length = x[1] - x[0] + 1, first = 0, second = 0;
//             if (it1 != str.end() && it2 != str.rend()) {
//                 first = it1 - str.begin(), second = length - (it2 - str.rbegin());
//                 ans.emplace_back(length - (pre_sum[second + 1]-pre_sum[first]));
//             }
//         }
//         return ans;
//     }
// };

// 3361. 两个字符串的切换距离
// 50mins 知道思路写不出来看题解
// class Solution {
// public:
//     long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
//         long long ans=0;
//         const int N = 26;
//         vector<long long> pre(2*N+1,0);
//         vector<long long> next(2*N+1,0);
//         for(int i=0;i<2*N;i++) {
//             pre[i+1]=pre[i]+previousCost[i%N];
//             next[i+1]=next[i]+nextCost[i%N];
//         }
//         for(int i=0;i<s.size();i++){
//             long long forward=0,back=0;
//             int x=s[i]-'a',y=t[i]-'a';
//             forward=next[x<y ? y: y+N]-next[x];
//             back=pre[(x<y ? x+N : x)+1]-pre[y+1];

//             ans+=min(forward,back);
//         }
//         return ans;
//     }
// };

// 53. 最大子数组和
// 2025-02-06 13:12:44
// [ 用时: 4 m 25 s ]n 1 写的最快的一次
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int curr_max = 0;
//         int global_max = INT_MIN;
//         for(int elem : nums){
//             curr_max = max(curr_max + elem, elem);
//             global_max = max(global_max, curr_max);
//         }
//         return global_max;
//     }
// };
// 1749. 任意子数组和的绝对值的最大值
// 2025-02-06 11:15:23
// [ 用时: 43 m 38 s ] n 1简单模拟和新旧更替方法
// class Solution {
// public:
//     int maxAbsoluteSum(vector<int>& nums) {
//         int minone = 0, maxone = 0, max_sub = -10001, max_leap = -10001, n = nums.size(), presum = 0;
//         for (int i = 0; i < n;i++){
//             presum += nums[i];
//             max_sub = max(max_sub, maxone - presum);
//             max_leap = max(max_leap, presum - minone);
//             minone = min(minone, presum);
//             maxone = max(maxone, presum);
//         }
//         return max(abs(max_sub), abs(max_leap));
//     }
// };
// 3151. 特殊数组 I
// 2025-02-06 10:49:14
// class Solution {
// public:
//     bool isArraySpecial(vector<int>& nums) {
//         auto it = adjacent_find(nums.begin(), nums.end(), [](const int a, const int b)
//             { return ((a ^ b) & 1) == 0; });
//         return it == nums.end();
//     }
// };
// 3152. 特殊数组 II
// 看题解 n n
// class Solution {
// public:
//     vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
//         int n = nums.size(), q = queries.size();
//         vector<int> s(n);
//         vector<bool> ans(q);
//         for (int i = 1; i < n;i++){
//             s[i] = s[i - 1] + ((nums[i] ^ nums[i - 1] ^ 1) & 1);
//         }
//         for (int i = 0; i < q;i++){
//             ans[i] = s[queries[i][0]] == s[queries[i][1]];
//         }
//         return ans;
//     }
// };
// 2025-02-06 09:02:51
// 20mins n2 1 算是一种暴力方法，但是超时了
// class Solution {
// public:
//     vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
//         int n = nums.size(), m = queries.size();
//         vector<bool> ans(m);
//         for (int i = 0; i < m;i++){
//             auto it = adjacent_find(nums.begin() + queries[i][0], nums.begin() + queries[i][1]+1, [](const int a, const int b)
//                 { return ((a ^ b) & 1) == 0; });
//             if(it==nums.begin()+queries[i][1]+1){
//                 ans[i] = true;
//             }else{
//                 ans[i] = false;
//             }
//         }
//         return ans;
//     }
// };
// 2025-02-06 00:06:26
// 做了一个小时还是错了 95%以上测试数据通过，忽略哈希表中没查找的情况
// class Solution {
// public:
//     vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
//         int n = nums.size(), q_size = queries.size();
//         for(int& x : nums){
//             x = x % 2;
//         }
//         vector<bool> ans(queries.size());
//         unordered_map<int, int> mapping;
//         int first = 0, last = 0;
//         for (int i = 1; i < n;){
//             if(nums[i - 1]%2 == nums[i]%2){
//                 mapping.insert({first, i-1});
//                 first = i;
//             }
//             i++;
//         }
//         mapping.insert({first, nums.size() - 1});
//         for (int i = 0; i < q_size;i++){
//             if(queries[i][0]==queries[i][1]){
//                 ans[i] = true;
//                 continue;
//             }
//             auto it = mapping.find(queries[i][0]);
//             (it==mapping.end()||it->second<queries[i][1]) ? ans[i] = false : ans[i] = true;
//         }
//         return ans;
//     }
// };

// 2389. 和有限的最长子序列
// 2025-02-05 22:12:10
// 20mins n2 1两次遍历
// 思考题：把子序列改成子数组要怎么做？
// class Solution {
// public:
//     vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
//         int temp_sum = 0, max_length = 0, result = 0;
//         for (int& q : queries){
//             for (int& n : nums){
//                 if(n>q){
//                     continue;
//                 }else{
//                     if(temp_sum+n<=q){
//                         max_length++;
//                         temp_sum += n;
//                     }else{
//                         result = max(result, max_length);
//                         max_length = 0;
//                         temp_sum = 0;
//                     }
//                 }
//             }
//             q = max_length;
//         }
//         return queries;
//     }
// };
/**
 * for(int& q : queries){
 *     q = ranges::upper_bound(nums, q);
 * }
 */
// 2025-02-05 21:36:05
// 25mins nlogn 1原地修改,关键是看懂这jb题目翻译
// class Solution{
// public:
//     vector<int> answerQueries(vector<int> &nums, vector<int> &queries){
//         sort(nums.begin(), nums.end());
//         partial_sum(nums.begin(), nums.end(), nums.begin());
//         int n = nums.size(), m = queries.size();
//         for (int i = 0; i < m; i++){
//             auto it = lower_bound(nums.begin(), nums.end(), queries[i]);
//             if (it == nums.end()){
//                 queries[i] = n;
//             }
//             else if (*it > queries[i]){
//                 queries[i] = it - nums.begin();
//             }
//             else{
//                 queries[i] = it - nums.begin() + 1;
//             }
//         }
//         return queries;
//     }
// };

// 930. 和相同的二元子数组
// 2025-02-05 15:34:48
// 双指针做法，由于测试集导致的前缀和单调递增，可以使用滑动窗口
// class Solution {
// public:
//     int numSubarraysWithSum(vector<int>& nums, int goal) {
//         int n = nums.size();
//         int ans = 0;
//         for (int r = 0, l1 = 0, l2 = 0, s1 = 0, s2 = 0; r < n; r++) {
//             s1 += nums[r];
//             s2 += nums[r];
//             while (l1 <= r && s1 > goal) s1 -= nums[l1++];
//             while (l2 <= r && s2 >= goal) s2 -= nums[l2++];
//             ans += l2 - l1;
//         }
//         return ans;
//     }
// };
// n n 和560一致，没什么好说的做法
// class Solution {
// public:
//     int numSubarraysWithSum(vector<int>& nums, int goal) {
//         int n = nums.size(), count = 0, pre_sum = 0;
//         unordered_map<int, int> mapping = {{0, 1}};
//         for(int elem : nums){
//             pre_sum += elem;
//             if(mapping.contains(pre_sum - goal)){
//                 count += mapping[pre_sum - goal];
//             }
//             mapping[pre_sum]++;
//         }
//         return count;
//     }
// };

// 560. 和为 K 的子数组
// n n 45mins数组中只有新旧替换中两个数字被用到，所以只用两个数
// class Solution{
// public:
// 	int subarraySum(vector<int>& nums, int k) {
//         int n = nums.size(), count = 0, sum = 0;
//         unordered_map<int, int> mapping;
// 		mapping[0] = 1;
// 		for(int elem : nums){
//             sum += elem;
//             if (mapping.count(sum - k)){
//                 count += mapping[sum - k];
//             }
//             mapping[sum]++;
//         }
// 		return count;
// 	}
// };
// 传统前缀和方法，用数组存储前缀和
// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         int n = nums.size(),count =0;
//         vector<int> pre_sum(n+1,0);
//         unordered_map<int, int> mapping;
//         mapping[0] = 1;
//         for (int i = 0; i < n;i++){
//             pre_sum[i + 1] = pre_sum[i] + nums[i];
//             if(mapping.find(pre_sum[i + 1] - k)!=mapping.end()){
//                 count += mapping[pre_sum[i + 1] - k]++;
//             }
//             mapping[pre_sum[i + 1]]++;
//         }
//         return count;
//     }
// };
// 724. 寻找数组的中心下标
// 2025-02-05 10:47:38
// 15mins 方法很多：1维护两个数组--前缀和和后缀和（再遍历一遍数组直接查询两个数组对应下标即可） 2维护一个前缀和数组，后缀和通过计算得到，真正思考的是如何在一遍遍历情况下减少空间
// class Solution {
// public:
//     int pivotIndex(vector<int>& nums) {
//         int all_sum = reduce(nums.begin(), nums.end(), 0);
//         int n = nums.size(), pre_sum = 0;
//         for (int i = 0; i < n;i++){
//             if(all_sum-nums[i]-pre_sum == pre_sum){
//                 return i;
//             }
//             pre_sum += nums[i];
//         }
//     }
// };
// 974. 和可被 K 整除的子数组
// 看题解发现的同余定理
// class Solution {
// public:
//     int subarraysDivByK(vector<int>& nums, int k) {
//         int count = 0,sum =0;
//         unordered_map<int ,int> mapping = {{0,1}};
//         for(int elem : nums){
//             sum += elem;
//             int modulus = (sum % k + k) % k;
//             if(mapping.count(modulus)){
//                 count += mapping[modulus];
//             }
//             ++mapping[modulus];
//         }
//         return count;
//     }
// };
// 超时写法
// class Solution {
// public:
//     int subarraysDivByK(vector<int>& nums, int k) {
//         int n = nums.size(), count = 0;
//         vector<int> s(n + 1, 0);
//         s[0] = 0;
//         partial_sum(nums.begin(), nums.end(), s.begin()+1);
//         for (int i = 0; i < n + 1;i++){
//             for (int j = i + 1; j < n + 1;j++){
//                 if((s[j]-s[i])%k==0){
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }
// };
// 2025-01-26 18:02:33
// 1512. 好数对的数目的翻版
// 00 : 12 : 16  n n
// class Solution {
// public:
//     vector<vector<int>> pairSums(vector<int>& nums, int target) {
//         vector<vector<int>> ans;
//         unordered_map<int, int> mapping;
//         for(int x : nums){
//             if(mapping.find(x)!=mapping.end()&&mapping[x]!=0){
//                 mapping[x]--;
//                 ans.emplace_back(vector<int>{x, target - x});
//             }else{
//                 mapping[target - x]++;
//             }
//         }
//         return ans;
//     }
// };
// 2441. 与对应负数同时存在的最大正整数
// 2025-01-26 20:13:12
// 00 : 04 : 49  n 1 双指针法
// class Solution {
// public:
//     int findMaxK(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         int left = 0,right = nums.size()-1;
//         while(left<right){
//             if(nums[left]>0||nums[right]<0)
//                 return -1;
//             if(nums[left]+nums[right]>0){
//                 right--;
//             }else if(nums[left]+nums[right]<0){
//                 left++;
//             }else{
//                 return nums[right];
//             }
//         }
//         return -1;
//     }
// };
// 2025-01-26 17:59:54
// 00 : 10 : 29  n n 两数之和翻版
// class Solution {
// public:
//     int findMaxK(vector<int>& nums) {
//         unordered_set<int> mapping;
//         int temp = INT_MIN;
//         for(int k : nums){
//             if(mapping.find(k)!=mapping.end()){
//                 temp = max(temp, k > 0 ? k : -k);
//             }else{
//                 mapping.insert(-k);
//             }
//         }
//         return temp == INT_MIN ? -1 : temp;
//     }
// };

// 3371. 识别数组中的最大异常值
// 2025-01-26 22:09:51
// 2025-01-26 23:26:09
// 没做出来，看提示因为stl数据结构特性导致算法有漏洞，看题解和多种做法
// class Solution {
// public:
//     int getLargestOutlier(vector<int>& nums) {
//         int sum = reduce(nums.begin(), nums.end(), 0);
//         int result = INT_MIN;
//         for (int i = 0;i<nums.size();i++){
//             if((sum-nums[i])%2==1){
//                 continue;
//             }
//             nums.erase(nums.begin() + i);
//             auto it = find(nums.begin(), nums.end(), (sum - nums[i])/2);
//             if(it!=nums.end()){
//                 result = max(result, nums[i]);
//             }
//             nums.emplace_back(nums[i]);
//         }
//         return result;
//     }
// };
// 454. 四数相加 II
// 2025-01-26 20:45:22
// 00 : 18 : 06  2n n 两数之和模拟法本质上是两数之和翻版
// class Solution {
// public:
//     int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
//         unordered_map<int, int> mapping1;
//         unordered_map<int, int> mapping2;
//         int ans = 0;
//         for(int x : nums1){
//             for(int y : nums2){
//                 mapping1[x + y]++;
//             }
//         }
//         for(int x : nums3){
//             for(int y : nums4){
//                 mapping2[x + y]++;
//             }
//         }
//         for (auto it1 = mapping1.begin();it1!=mapping1.end();it1++){
//             auto it2 = mapping2.find(-it1->first);
//             if(it2!=mapping2.end()){
//                 ans += (it1->second) * (it2->second);
//             }
//         }
//         return ans;
//     }
// };
// 面试题 16.24. 数对和
// 2025-01-26 20:18:50
// class Solution {
// public:
//     vector<vector<int>> pairSums(vector<int>& nums, int target) {
//         sort(nums.begin(), nums.end());
//         vector<vector<int>> ans;
//         int left = 0,right = nums.size()-1;
//         while(left < right){
//             if(nums[left]+nums[right]>target){
//                 right--;
//             }else if(nums[left]+nums[right]<target){
//                 left++;
//             }else{
//                 ans.emplace_back(vector<int>{nums[left++], nums[right--]});
//             }
//         }
//         return ans;
//     }
// };
// 枚举j做法
// class Solution {
// public:
//     bool find132pattern(vector<int>& nums) {
//         int n = nums.size();
//         multiset<int> rightall;
//         int leftmin = nums[0];
//         for (int i = 2;i<n;i++){
//             rightall.insert(nums[i]);
//         }
//         for (int j = 1;j<n-1;j++){
//             if(leftmin<nums[j]){
//                 auto it = rightall.upper_bound(leftmin);
//                 if(it!=rightall.end()&&*it<nums[j]){
//                     return true;
//                 }
//             }
//             leftmin = min(leftmin, nums[j]);
//             rightall.erase(rightall.find(nums[j+1]));
//         }
//         return false;
//     }
// };
// 447. 回旋镖的数量
// 数学方法，作图看交点,太过复杂，涉及浮点数运算非常吃性能而且精度有限，思路见ob朱提路线对应题目
// 经典做法 n3 n 20mins
// class Solution {
// public:
//     int numberOfBoomerangs(vector<vector<int>>& points) {
//         int ans = 0;
//         for(auto& a : points){
//             unordered_map<int,int> dist;
//             for(auto& b : points){
//                 int result = (a[1] - b[1]) * (a[1] - b[1]) + (a[0] - b[0]) * (a[0] - b[0]);
//                 dist[result]++;
//             }
//             for(auto temp : dist){
//                 ans += temp.second * (temp.second - 1);
//             }
//         }
//         return ans;
//     }
// };
// 3128. 直角三角形
// class Solution {
// public:
//     long long numberOfRightTriangles(vector<vector<int>>& grid) {
//         int column = grid.size();
//         int row = grid[0].size();
//         vector<int> column_sum(column);
//         vector<int> row_sum(row);
//         int ans = 0;
//         for (int i = 0; i < column;i++){
//             for (int j = 0; j < row; j++){
//                 if(grid[i][j] == 1){
//                     row_sum[i] += 1;
//                     column_sum[j] += 1;
//                 }
//             }
//         }
//         for (int i = 0; i < column;i++){
//             for (int j = 0; j < row; j++){
//                 if(grid[i][j] == 1){
//                     ans += (row_sum[i] - 1) * (column_sum[j] - 1);
//                 }
//             }
//         }
//         return ans;
//     }
// };
// 极致优化版本，只存储行或者列的一个，另一个在计算中更新迭代，看灵神题解 n n 30min
// class Solution {
// public:
//     long long numberOfRightTriangles(vector<vector<int>>& grid) {
//         int n = grid[0].size();
//         long long ans = 0;
//         vector<int> col_sum(n);
//         for(auto& row : grid){
//             for (int i = 0; i < n;i++){
//                 col_sum[i] += row[i];
//             }
//         }
//         for(auto& row : grid){
//             int row_sum = reduce(row.begin(), row.end());
//             for (int i = 0; i < n;i++){
//                 if(row[i]==1){
//                     ans += (row_sum - 1) * (col_sum[i] - 1);
//                 }
//             }
//         }
//         return ans;
//     }
// };
// 三角形三个数是相邻的版本解法，第一遍看错了以为是相邻的  n 1 6mins
// class Solution {
// public:
//     long long numberOfRightTriangles(vector<vector<int>>& grid) {
//         int column = grid.size();
//         int row = grid[0].size();
//         int temp = 0,count=0;
//         for (int i = 0; i < column - 1;i++){
//             for (int j = 0; j < row - 1;j++){
//                 temp = grid[i][j] + grid[i][j + 1] + grid[i + 1][j] + grid[i + 1][j + 1];
//                 if(temp == 4){
//                     count += 4;
//                 }
//                 if(temp == 3){
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }
// };
// 自己写超时，看官方思路
// class Solution {
// public:
//     int countPalindromicSubsequence(string s) {
//         vector<int> last(26,-1);
//         vector<int> first(26,-1);
//         int ans = 0;
//         for (int i = 0; i < s.size();i++){
//             int pos = s[i] - 'a';
//             last[pos] = i;
//             if(first[pos]==-1){
//                 first[pos] = i;
//             }
//         }
//         for (char ch = 'a'; ch <= 'z';ch++){
//             int left = first[ch - 'a'];
//             int right = last[ch - 'a'];
//             if(right - left>=2){
//                 unordered_set<int> only;
//                 for (int j = left + 1; j <= right - 1;j++){
//                     only.insert(s[j]);
//                 }
//                 ans += only.size();
//             }
//         }
//         return ans;
//     }
// };
// 1930. 长度为 3 的不同回文子序列
// 逻辑没问题，但是超时了 n n 60mins
// class Solution {
// public:
//     int countPalindromicSubsequence(string s) {
//         int n = s.length(),count =0;
//         set<char> temp1 = {} ,temp2 = {};
//         vector<set<char>> pre(n) , after(n);
//         vector<char> common;
//         unordered_set<string> only;
//         string temp3;
//         for (int i = 0,j = n - 1; i < n,j >= 0;i++,j--){
//             temp1.insert(s[i]);
//             pre[i] = temp1;
//             temp2.insert(s[j]);
//             after[j] = temp2;
//         }
//         for (int k = 1; k < n - 1; k++){
//             set_intersection(pre[k - 1].begin(), pre[k - 1].end(), after[k + 1].begin(), after[k + 1].end(), back_inserter(common));
//             if(common.size()!=0){
//                 for(auto c : common){
//                     string str = {c, s[k], c};
//                     if(only.insert(str).second == true){
//                         count++;
//                     }
//                 }
//                 common.clear();
//             }
//         }
//         return count;
//     }
// };
// 2909. 元素和最小的山形三元组 II
// 00 : 40 : 12
// 需要使用2874中的**普通解法**之一，同样是枚举维护问题，关键字在于边界问题的处理和初始值设定 n n
// class Solution {
// public:
//     int minimumSum(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> pre(n + 1,INT_MAX);
//         vector<int> after(n + 1,INT_MAX);
//         int result = INT_MAX;
//         for (int i = 0,j=n; i < n,j>0;i++,j--){
//             pre[i + 1] = min(pre[i], nums[i]);
//             after[j - 1] = min(after[j], nums[j-1]);
//         }
//         // pre[i]返回nums[i]前面元素中最小的一个
//         // after[i]返回nums[i]后面元素中最小的一个
//         for (int j = 1; j < nums.size();j++){
//             if(pre[j]<nums[j]&&after[j]<nums[j]){
//                 result = min(result, nums[j] + pre[j] + after[j]);
//             }
//         }
//         return result == INT_MAX ? -1 : result;
//     }
// };
// 上面开始枚举中间章节
// 2555. 两个线段获得的最多奖品
// 做不出来，太难了，2000难度分有点高
// 2905. 找出满足差值条件的下标 II
// 2025年1月22日12:00:08 写不出来，题解看不懂
// 1031. 两个非重叠子数组的最大和
// 2025年1月22日10:26:48
// 一般人能想到的，两遍循环，分别计算firstLen + secondLen和secondLen + firstLen两种情况
// class Solution {
// public:
//     int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
//         int n = nums.size();
//         int s[n + 1], ans =0;
//         s[0] = 0;
//         partial_sum(nums.begin(), nums.end(), s + 1);
//         auto f = [&](int firstLen, int secondLen) {
//             int maxSumA = 0;
//             for (int i = firstLen + secondLen; i <= n; i++) {
//                 maxSumA = max(maxSumA, s[i - secondLen] - s[i - secondLen - firstLen]);
//                 ans = max(ans, maxSumA + s[i] - s[i - secondLen]);
//             }
//         };
//         f(firstLen, secondLen);
//         f(secondLen,firstLen);
//         return ans;
//     }
// };
// 2025年1月22日09:22:08
// 01 : 03 : 57
// 看题解，自己写一遍，前缀和思路 n n
// class Solution {
// public:
//     int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
//         int ans = 0, n = nums.size(), s[n + 1], maxA = 0,maxB =0;
//         s[0] = 0;
//         partial_sum(nums.begin(), nums.end(),s+1);
//         for (int i = firstLen + secondLen; i <= n;i++){
//             maxA = max(maxA, s[i - secondLen] - s[i - secondLen - firstLen]);
//             maxB = max(maxB, s[i- firstLen] - s[i - firstLen - secondLen]);
//             ans = max(ans, max(maxA+s[i]-s[i-secondLen],
//                                maxB+s[i]-s[i-firstLen]));
//         }
//         return ans;
//     }
// };
// 超时写法
// class Solution {
// public:
//     vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
//         long long count = 0;
//         vector<long long> ans(queries.size());
//         for (int i = 0; i < queries.size();i++){
//             for(int n : nums){
//                 if(n-queries[i]>0){
//                     count += (n - queries[i]);
//                 }else{
//                     count += (queries[i] - n);
//                 }
//             }
//             ans[i] = count;
//             count =0;
//         }
//         return ans;
//     }
// };
// int main(){
//     vector<int> nums = {3, 1, 6, 8};
//     vector<int> queries = {1,5};
//     Solution s;
//     for(long long x : s.minOperations(nums,queries))
//         cout << x << " ";
// }
// 303. 区域和检索 - 数组不可变
// 最简单的前缀和 n n 6mins
// class NumArray {
//     vector<int> sum;
// public:
//     NumArray(vector<int>& nums) {
//         sum.resize(nums.size()+1);
//         for(int i =0;i<nums.size();i++){
//             sum[i+1] = sum[i] + nums[i];
//         }
//     }

//     int sumRange(int left, int right) {
//         return sum[right+1]-sum[left];
//     }
// };
// 2559. 统计范围内的元音字符串数
// 在数据量比较大时尽量减少函数调用能够提高速度
// class Solution {
// public:
//     vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
//         unordered_set<char> vowels = {'a', 'e', 'i', 'u', 'o'};
//         int n = words.size();
//         vector<int> sum(n + 1);
//         for(int i = 0; i < n; i ++ ) {
//             if(vowels.count(words[i][0]) && vowels.count(words[i].back()))
//                 sum[i + 1] = 1 + sum[i];
//             else
//                 sum[i + 1] = sum[i];
//         }
//         vector<int> result(queries.size());
//         for (int i = 0; i < queries.size();i++){
//             result[i] = sum[queries[i][1]+1] - sum[queries[i][0]];
//         }
//         return result;
//     }
// };
// 简化一些代码
// class Solution {
// public:
//     vector<char> vowel = {'a', 'e', 'i', 'o', 'u'};
//     bool is_correct (string x){
//         if(find(vowel.begin(),vowel.end(),x[0])!=vowel.end()&&find(vowel.begin(),vowel.end(),x[x.length()-1])!=vowel.end()){
//             return true;
//         }
//         return false;
//     }
//     vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
//         vector<int> sum(words.size());
//         vector<int> result(0);
//         int left = 0, right = 0, temp = 0,count = 0;
//         for(auto q : queries){
//             int left = q[0], right = q[1];
//             for (int i = temp; i <= right;++i){
//                 if(is_correct(words[i]))
//                     count++;
//                 sum[i] = count;
//             }
//             temp = right + 1;
//             result.emplace_back(sum[right] - sum[left] + is_correct(words[left]));
//         }
//         return result;
//     }
// };
// 2025年1月21日17:02:45
// 最简单的模拟算法，先计算每一个word是否符合条件，再计算前缀和，通过前缀和计算结果时间有点慢（不熟练），n n 45mins
// class Solution {
// public:
//     vector<char> vowel = {'a', 'e', 'i', 'o', 'u'};
//     bool is_correct (string x){
//         if(find(vowel.begin(),vowel.end(),x[0])!=vowel.end()&&find(vowel.begin(),vowel.end(),x[x.length()-1])!=vowel.end()){
//             return true;
//         }
//         return false;
//     }
//     vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
//         vector<int> result;
//         vector<int> sum(words.size());
//         int count = 0;
//         for (int i = 0; i < words.size();i++){
//             if(is_correct(words[i])){
//                 ++count;
//             }
//             sum[i] = count;
//         }
//         for (int j = 0; j < queries.size();j++){
//             result.emplace_back(sum[queries[j][1]] - sum[queries[j][0]] + is_correct(words[queries[j][0]]));
//         }
//         return result;
//     }
// };
// 1031. 两个非重叠子数组的最大和
// 超时，用了错误的思路，下面的解答是错的
// class Solution {
// public:
//     int find_sub_sum(vector<int>& nums,int length,int flag){
//         int content = 0, temp = 0, result = 0,start_index =0;
//         for (int i = 0; i < length;i++){
//             content += nums[i];
//         }
//         for (int i = length; i < nums.size();i++){
//             temp = content + nums[i] - nums[i - length];
//             if(temp > result){
//                 result = temp;
//                 start_index = i - length + 1;
//             }
//             content = temp;
//         }
//         if(flag){
//             nums.erase(nums.begin() + start_index, nums.begin() + start_index + length);
//         }
//         return result;
//     }
//     int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
//         bool flag = true;
//         int result1 =  find_sub_sum(nums, firstLen, flag);
//         int result2 =  find_sub_sum(nums, secondLen, !flag);
//         return result1+result2;
//     }
// };
// 2905. 找出满足差值条件的下标 II
// 2025年1月20日12:02:08 中途有事跳过
// 1814. 统计一个数组中好对子的数目
// 2025年1月20日12:01:57
// 简单哈希表，次数统计法，对于c(n,2)的累加计算有点不熟悉，应该先result+=访问次数，再访问次数++的，浪费有点多的时间，n n 30mins
// 由于数据量很大，不能使用下标法用动态数组完成，会爆内存
// class Solution {
// public:
//     int rev(int input){
//         int result = 0;
//         while(input>0){
//             result = result * 10 + input % 10;
//             input /= 10;
//         }
//         return result;
//     }
//     int countNicePairs(vector<int>& nums) {
//         unordered_map<int, int> mp;
//         int result = 0;
//         for(int num :nums){
//             result = (result + mp[num - rev(num)]) % 1000000007;
//             ++mp[num - rev(num)];
//         }
//         return result;
//     }
// };
// 1410. HTML 实体解析器
// 20分钟包括查询正则表达式用法和源输入格式写法
// class Solution {
// public:
//     string entityParser(string text) {
//         vector<pair<__cxx11::regex, string>> replacements = {
//             {regex("&quot;"), "\""},
//             {regex("&apos;"), "\'"},
//             {regex("&gt;"), ">"},
//             {regex("&lt;"), "<"},
//             {regex("&frasl;"), "/"},
//             {regex("&amp;"), "&"}
//         };
//         for(const auto& pair : replacements){
//             text = regex_replace(text, pair.first, pair.second);
//         }

//         return text;
//     }
// };
// int main(){
//     string test = "&amp; is an HTML entity but &ambassador; is not.";
//     Solution s;
//     cout << s.entityParser(test);
// }
// 217. 存在重复元素
// 简单哈希表，出现次数统计法n n 3mins
// class Solution {
// public:
//     bool containsDuplicate(vector<int>& nums) {
//         unordered_map<int, int> mapping;
//         for(int x : nums){
//             if(++mapping[x] > 1){
//                 return true;
//             }
//         }
//         return false;
//     }
// };

// 1014. 最佳观光组合
// 十三分钟
// 简单模拟算法  n 1
// class Solution {
// public:
//     int maxScoreSightseeingPair(vector<int>& values) {
//         int ans = 0, max_i = values[0];
//         for (int i = 1; i < values.size();i++){
//             ans = max(ans, max_i + values[i] - i);
//             max_i = max(max_i, values[i] + i);
//         }
//         return ans;
//     }
// };

// 2874. 有序三元组中的最大值 II
// 重写一遍
// 2025年1月19日09:44:212
// 枚举k  最关键在于新旧值更替的顺序，被用掉之后的值可以被更新，有先计算答案，后插入内容（更新内容）的，return值在循环语句中的更新语句前写 n 1 30mins
// class Solution {
// public:
//     long long maximumTripletValue(vector<int>& nums) {
//         int sub = 0, pre_max =0;
//         long long ans = 0;
//         for(int num : nums){
//             ans = max(ans, (long long)num * sub);
//             sub = max(sub, pre_max - num);
//             pre_max = max(pre_max, num);
//         }
//         return ans;
//     }
// };
// 枚举j
// class Solution {
// public:
//     long long maximumTripletValue(vector<int>& nums) {
//         vector<int> pre(nums.size() + 1);
//         vector<int> after(nums.size() + 1);
//         pre[0] = 0;
//         after[nums.size()] = 0;
//         long long ans = 0;
//         for (int i = 0,j = nums.size(); i < nums.size(), j > 0;i++,j--){
//             pre[i + 1] = max(pre[i], nums[i]);
//             after[j - 1] = max(after[j], nums[j-1]);
//         }
//         for (int k = 0; k < nums.size();k++){
//             ans = max(ans, (long long)(pre[k] - nums[k]) * after[k + 1]);
//         }
//         return ans;
//     }
// };
// 没做出来看题解
// class Solution {
// public:
//     long long maximumTripletValue(vector<int>& nums) {
//         long long ans = 0;
//         int max_diff = 0, minone = 0;
//         for(int x : nums){
//             ans = max(ans, (long long)max_diff * x);
//             max_diff = max(max_diff, x- minone);
//             minone = max(minone, x);
//         }
//         return ans;
//     }
// };
// 2748. 美丽下标对的数目
// 2025年1月17日18:26:18
// 简单模拟算法，枚举——维护思想
// class Solution {
// public:
//     int countBeautifulPairs(vector<int>& nums) {
//         int ans = 0, cnt[10]{};
//         for (int x : nums) {
//             for (int y = 1; y < 10; y++) {
//                 if (cnt[y] && gcd(y, x % 10) == 1) {
//                     ans += cnt[y];
//                 }
//             }
//             while (x >= 10) {
//                 x /= 10;
//             }
//             cnt[x]++; // 统计最高位的出现次数
//         }
//         return ans;
//     }
// };
// 2025年1月17日18:00:34
// 5分钟 n 1 和1010题一模一样
// class Solution {
// public:
//     long long countCompleteDayPairs(vector<int>& hours) {
//         vector<int> mapping(24, 0);
//         int i = 1, j = 23;
//         long ans = 0;
//         for(int x : hours){
//             mapping[x % 24]++;
//         }
//         for (int j = 0; j < 24;j++){
//             if(mapping[j]==0) continue;
//             if(j==0||j==12)
//                 ans += (long)mapping[j] * (mapping[j]-1);
//             else
//                 ans += (long)mapping[j] * mapping[24 - j];
//         }
//         return ans/2;
//     }
// };
// 1010. 总持续时间可被 60 整除的歌曲
// 2025年1月17日15:32:01
// 2025年1月17日16:20:39
// 简单模拟算法 难就难在特殊情况处理上，余数为0和余数为30时有特殊处理方式 n n 40mins
// 如果不在最后return转化为long，则用int作为相乘项的结果也是int，可能会overflow，如果vector<long>又会增加一倍空间，所以在结果处转换更明智
// class Solution {
// public:
//     int numPairsDivisibleBy60(vector<int>& time) {
//         vector<long> mapping(60, 0);
//         long ans = 0;
//         int i = 1, j = 59;
//         for(int t : time){
//             mapping[t % 60]++;
//         }
//         while(i<j){
//             ans += mapping[i++] * mapping[j--];
//         }
//         ans += mapping[0]*(mapping[0]-1)/2+mapping[30]*(mapping[30]-1)/2;
//         return ans;
//     }
// };
// 2260. 必须拿起的最小连续卡牌数
// 2025年1月17日14:37:06
// 2025年1月17日15:17:24
// 最高密度的访问次数标记法 n 1 40mins
// class Solution {
// public:
//    int minimumCardPickup(vector<int>& cards) {
//        unordered_map<int,int>mapping;
//        int ans=INT_MAX;
//        for(int i=0;i<cards.size();++i){
//            if(mapping.count(cards[i])!=0){
//                ans=min(ans,i-mapping[cards[i]]+1);
//            }
//            mapping[cards[i]]=i;
//        }
//        return ans == INT_MAX ? -1 : ans;
//    }
// };
// 1679. K 和数对的最大数目
// 2025年1月17日10:10:46
// 使用find_if暴力解法，多条件匹配 n*n! 1 超时
// 记录访问次数法 n,1 题解 20mins
// class Solution {
// public:
//     int maxOperations(vector<int>& nums, int k) {
//         unordered_map<int, bool> mapping;
//         int count = 0;
//         for (int i = 0; i < nums.size();i++){
//             auto it = mapping.find(k - nums[i]);
//             if(it!=mapping.end()&&it->second==true){
//                 count++;
//                 it->second = false;
//             }else{
//                 mapping[nums[i]] = true;
//             }
//         }
//         return count;
//     }
// };
// 一小时，还是错了，但很接近答案，需要换一种思路 n 1 60mins
// class Solution {/* 错误解法 */
// public:
//     int maxOperations(vector<int>& nums, int k) {
//         unordered_map<int, bool> mapping;
//         int count = 0;
//         for (int i = 0; i < nums.size();i++){
//             bool flag = true;
//             auto it = mapping.find(k - nums[i]);
//             if(it!=mapping.end()&&it->second==true){
//                 count++;
//                 flag = false;
//                 it->second = flag;
//             }
//             mapping.insert({nums[i], flag});
//         }
//         return count;
//     }
// };
// 2342. 数位和相等数对的最大和
// 简化的算法，抓住核心逻辑的枚举左，维护右方法
// class Solution {
// public:
//     int getSum(int x,int ans =0){
//         while(x>0){
//             ans += x % 10;
//             x /= 10;
//         }
//         return ans;
//     }
//     int maximumSum(vector<int>& nums) {
//         int ans = -1;
//         unordered_map<int, int> mx;
//         for (int num : nums) {
//             int s = getSum(num);
//             if (mx[s]) {
//                 ans = max(ans, mx[s] + num);
//             }
//             mx[s] = max(mx[s], num);
//         }
//         return ans;
//     }
// };
// 模拟算法，只维护一个数组中最大的两个值，空间复杂度大大减少O(1)，由于代码逻辑较为复杂，时间上慢了点  n 1 20mins
// class Solution {
// public:
//     int getSum(int x, int ans = 0){
//         do{
//             ans += x % 10;
//         } while (x/=10);
//         return ans;
//     }
//     int maximumSum(vector<int>& nums) {
//         int max_result = -1;
//         unordered_map <int, vector<int>> mapping;
//         for (int i = 0; i < nums.size();i++){
//             if(mapping[getSum(nums[i])].size()<2){
//                 mapping[getSum(nums[i])].emplace_back(nums[i]);
//             }else if(nums[i]>min(mapping[getSum(nums[i])][0],mapping[getSum(nums[i])][1])){
//                 mapping[getSum(nums[i])][0] = nums[i];
//             }
//             sort(mapping[getSum(nums[i])].begin(), mapping[getSum(nums[i])].end());
//         }
//         for(auto x : mapping){
//             if(x.second.size()>1)
//                 max_result = max(max_result, x.second[0] + x.second[1]);
//         }
//         return max_result;
//     }
// };
// 2025年1月16日18:24:13
// 2025年1月16日18:48:23
//
// 同2815，最简单的模拟算法，类似2815，同样利用multiset自动排序对数组分组之后小组内容排序，不更新而是完全存储所有数组存储，nlogn n Leetcode严重超时，400ms 144.95mb内存消耗
// class Solution {
// public:
//     int getSum(int x){
//         int ans = 0;
//         while(x>0){
//             ans += x % 10;
//             x /= 10;
//         }
//         return ans;
//     }
//     int maximumSum(vector<int>& nums) {
//         unordered_map<int,multiset<int>> mapping(9);
//         for (int i = 0; i < nums.size();i++){
//             mapping[getSum(nums[i])].insert(nums[i]);
//         }
//         int max_result = -1;
//         for(auto x :mapping){
//             if(x.second.size()>1){
//                 max_result = max(max_result, *x.second.rbegin() + *(++x.second.rbegin()));
//             }
//         }
//         return max_result;
//     }
// };
// int main(){
//     vector<int> test = {18, 43, 36, 13, 7};
//     Solution s;
//     cout << s.maximumSum(test);
//     // cout << s.getSum(12345);
// }
// 2815. 数组中的最大数对和
// 2025年1月16日17:08:58
// 2025年1月16日18:15:48
// 模拟算法，太过精妙的逻辑我写不出来，能流畅写出所想的思路就算赢，这个写起来太慢了，归根结底是数据结构学的不好，各种容器不熟练导致的 nlogn n
// class Solution {
// public:
//     // 获取数字的最高位
//     int findMaxDigit(int number) {
//         if (number == 0) return 0; // 0 的最大数字是 0
//         int max_digit = INT32_MIN;
//         while (number > 0) {
//             int digit = number % 10;
//             max_digit = max(max_digit, digit);
//             number /= 10;
//         }
//         return max_digit;
//     }
//     int maxSum(vector<int>& nums) {
//         vector<multiset<int>> mapping(10);
//         int max_result = -1;
//         for (int i = 0; i < nums.size();i++){
//             int section = findMaxDigit(nums[i]);
//             mapping[section].insert(nums[i]);
//             if(mapping[section].size()>1){
//                 auto it = mapping[section].rbegin();
//                 max_result = max(max_result, *it + *(++it));
//             }
//         }
//         return max_result;
//     }
// };
// 121. 买卖股票的最佳时机、
// 2025年1月16日16:41:07
// 2025年1月16日17:04:02
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int max_profit = INT_MIN;
//         int min_price = INT_MAX;
//         for (int i = 0; i < prices.size();i++){
//             min_price = min(min_price, prices[i]);
//             max_profit = max(max_profit, prices[i] - min_price);
//         }
//     }
// };
// 219. 存在重复元素 II
// 2025年1月16日16:09:04
// 2025年1月16日16:30:33
// 滑动窗口经典做法，三步走，使用访问次数统计方法并不优雅而且可读性较差
// class Solution {
// public:
//     bool containsNearbyDuplicate(vector<int>& nums, int k) {
//         unordered_set<int> window;
//         bool flag = false;
//         for (int i = 0; i < nums.size();i++){
//             // check whether elem is exist
//             if(window.find(nums[i])!=window.end()){
//                 flag = true;
//             }
//             // add new elem
//             window.insert(nums[i]);
//             // overflow situation
//             if(window.size()>k){
//                 window.erase(nums[i - k]);
//             }
//         }
//         return flag;
//     }
// };
// 2001. 可互换矩形的组数
// 2025年1月16日14:42:02
// 2025年1月16日14:47:19
// 简单哈希表，类似于1512好数，一样的原理，只是这里多了数据精度控制 n 1 5min
// class Solution {
// public:
//     long long interchangeableRectangles(vector<vector<int>>& rectangles) {
//         unordered_map<double, int> myMap;
//         long long ans = 0;
//         for (int i = 0; i < rectangles.size();i++){
//             ans +=myMap[double(rectangles[i][0]) / double(rectangles[i][1])]++;
//         }
//         return ans;
//     }
// };
// 1512. 好数对的数目
// 2025年1月16日14:22:42
// 2025年1月16日14:30:54
// 简单一遍哈希表，自增的同时累加（原因是计算C（2/value）组合数可以化简为公差为一等差数列求和
// class Solution {
// public:
//     int numIdenticalPairs(vector<int>& nums) {
//         unordered_map<int, int> myMap;
//         int ans = 0;
//         for (int i = 0; i < nums.size();i++){
//             ans += myMap[nums[i]]++;
//         }
//         return ans;
//     }
// };
// 1. 两数之和
// 2025年1月16日13:21:21
// 2025年1月16日13:48:49
// 一遍哈希表，在新增的同时匹配**新增之前**的哈希表中的内容是否有结果，新增和匹配的顺序是关键
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         unordered_map<int, int> myMap;
//         vector<int> ans(2,0);
//         for (int i = 0;i<nums.size();i++){
//             auto it = myMap.find(nums[i]);
//             if(it!=myMap.end()){
//                 ans = {i, it->second};
//             }
//             myMap[target - nums[i]] = i;
//         }
//         return ans;
//     }
// };

// 两遍哈希表，一遍构建，一遍遍历 2n 1 28mins。有点忘记C++基本语法了
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         unordered_map<int,int> myMap;
//         vector<int> ans(0,2);
//         for (int i = 0; i < nums.size();i++){
//             myMap[target - nums[i]] = i;
//         }
//         for (int i = 0; i < nums.size(); i++){
//             auto it = myMap.find(nums[i]);
//             if(it != myMap.end()&&it->second!=i){
//                 ans = {i, it->second};
//             }
//         }
//         return ans;
//     }
// };
// 2260. 必须拿起的最小连续卡牌数
// 2025年1月8日10:43:52
// 2815. 数组中的最大数对和
// 一个半小时
// 2025年1月7日16:35:31
// 优化版本，只用一遍循环做完分组和更新两个操作 n 1
// class Solution {
// public:
//     int maxSum(vector<int>& nums) {
//         int ans = -1;
//         vector<int> max_val(10, INT_MIN);
//         for (int v: nums) {
//             int max_d = 0;
//             for (int x = v; x; x /= 10)
//                 max_d = max(max_d, x % 10);
//             ans = max(ans, v + max_val[max_d]);
//             max_val[max_d] = max(max_val[max_d], v);
//         }
//         return ans;
//     }
// };

// 中规中矩模拟算法  nlogn 1
// class Solution {
// public:
//     // 获取数字的最高位
//     int findMaxDigit(int number) {
//         int max_d = INT_MIN;
//         for (int x = number; x;x/=10){
//             max_d = max(max_d, x % 10);
//         }
//         return max_d;
//     }
//     int maxSum(vector<int>& nums) {
//         int max_result = -1;
//         unordered_map<int, vector<int>> mymap;
//         for (int x : nums) {
//             mymap[findMaxDigit(x)].emplace_back(x);
//         }
//         for (auto& entry : mymap) {
//             int length = entry.second.size();
//             if (length > 1) {
//                 sort(entry.second.begin(), entry.second.end());
//                 max_result = max(max_result, entry.second[length - 1] + entry.second[length - 2]);
//             }
//         }
//         return max_result;
//     }
// };
// 121. 买卖股票的最佳时机
// 2025年1月7日13:52:04
// 20分钟
// 简单逻辑推演做法
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int min_one = INT_MAX, max_profit =0;
//         for (int i = 0; i < prices.size();i++){
//             min_one = min(min_one, prices[i]);
//             max_profit = max(max_profit, prices[i] - min_one);
//         }
//         return max_profit;
//     }
// };
// 219. 存在重复元素 II
// 2025年1月7日11:52:32
// 40分钟
// 暴力方法 n2 1
// 经典方法  n 1
// class Solution {
// public:
//     bool containsNearbyDuplicate(vector<int>& nums, int k) {
//         // 哈希表用于存储滑动窗口内的元素
//         unordered_set<int> window;
//         for(int i = 0; i < nums.size(); ++i){
//             // 检查当前元素是否已经在窗口中
//             if(window.find(nums[i]) != window.end()){
//                 return true;
//             }
//             // 将当前元素插入到窗口中
//             window.insert(nums[i]);
//             // 如果窗口大小超过k，移除最左边的元素
//             if(window.size() > k){
//                 window.erase(nums[i - k]);
//             }
//         }
//         // 如果没有找到符合条件的元素
//         return false;
//     }
// };
// 自定义判断几次访问次数 n n
// class Solution {
// public:
//     bool containsNearbyDuplicate(vector<int>& nums, int k,int count = 3) {
//         int n = nums.size();
//         unordered_map<int, pair<int,bool>> set;
//         for(int i = 0; i < n; ++i){
//             if(i > k) // mark 1
//                 set[nums[i - k - 1]].second = false;
//             if(set[nums[i]].first == count-1&&set[nums[i]].second == true) // mark 2
//                 return true;
//             set[nums[i]].first++;
//             set[nums[i]].second = true; // mark 3
//         }
//         return false;
//     }
// };
// 判断访问次数方法（两次终止
// class Solution {
// public:
//     bool containsNearbyDuplicate(vector<int>& nums, int k) {
//         int length = nums.size();
//         map<int, bool> set;
//         for (int i = 0; i < length;i++){
//             if(i>k) // judge whether window overflow
//                 set[nums[i]] = false; // and set the tail elem to false
//             if(set[nums[i] == true])// the second visit ,if it is true means this nums[i] is visited two times
//                 return true;
//             set[nums[i]] = true; // first mark elem to true
//         }
//     }
// };
// 2001. 可互换矩形的组数
// 2025年1月6日19:23:46
// 20分钟
// class Solution {
// public:
//     long long interchangeableRectangles(vector<vector<int>>& rectangles) {
//         unordered_map<double, int> count;
//         long long result = 0;
//         for (int i = 0; i < rectangles.size();i++){
//             double index = 1.0 * rectangles[i][0] / rectangles[i][1];
//             result += count[index]++;
//         }
//         return result;
//     }
// };
// 1512. 好数对的数目
// 2025年1月6日13:56:32
// 暴力法 n2 1
// 2025年1月6日14:06:10
// class Solution {
// public:
//     int numIdenticalPairs(vector<int>& nums) {
//         map<int, int> nums_map;
//         int count = 0;
//         if(nums.size()==1)
//             return 0;
//         for (int i = 0; i < nums.size();i++){
//             for (int j = i+1; j < nums.size();j++){
//                 if (nums[i] == nums[j]){
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }
// };
// 最简短，优雅的解法
// class Solution {
// public:
//     int numIdenticalPairs(vector<int>& nums) {
//         unordered_map<int, int> nums_map;
//         int result = 0;
//         for (int i = 0; i < nums.size();i++){
//             result += nums_map[nums[i]]++;
//         }
//         return result;
//     }
// };
// 使用排列组合方法，发现算法计算本质，有多个数字相等，问多个数字中有几个好数对，等价于计算组合数C(n,2) nlogn 1
// 2025年1月6日14:40:40 20分钟
// class Solution {
// public:
//     int combination(int n, int k) {// 计算C(n,k)
//         if(k>n)
//             return 0;
//         if(k > n - k) k = n - k;
//         int res = 1;
//         for(int i = 1; i <= k; ++i) {
//             res = res * (n - i + 1) / i;
//         }
//         return res;
//     }
//     int numIdenticalPairs(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         nums.emplace_back(-1);
//         int result = 0,count=1;
//         for (int i = 0; i < nums.size()-1;i++){
//             if(nums[i]==nums[i+1]){
//                 count++;
//             }else{
//                 result += combination(count,2);
//                 count = 1;
//             }
//         }
//         return result;
//     }
// };
// 发现算法本质，并且使用优化后的计算方法  n 1
// class Solution {
// public:
//     int combination(int n, int k =2) {// 计算C(n,k)
//         if(k>n)
//             return 0;
//         if(k > n - k) k = n - k;
//         int res = 1;
//         for(int i = 1; i <= k; ++i) {
//             res = res * (n - i + 1) / i;
//         }
//         return res;
//     }
//     int numIdenticalPairs(vector<int>& nums) {
//         vector<int> content(100,0);
//         int result = 0;
//         for (int i = 0; i < nums.size();i++){
//             content[nums[i]-1]++;
//         }
//         for (int i = 0; i <= 99;i++){
//             if(content[i]!=0){
//                 result += combination(content[i]);
//             }
//         }
//         return result;
//     }
// };
// 再次发现优化的本质可以用一种数据结构——哈希表 n  n
// class Solution {
// public:
//     int numIdenticalPairs(vector<int>& nums) {
//         int ans = 0;
//         unordered_map<int, int> cnt;
//         for (int x : nums) {
//             ans += cnt[x]++;
//         }
//         return ans;
//     }
// };
// 1. 两数之和
// 2025年1月6日11:06:17
// 30分钟
// 题目关键不在于等于，而是转化为target-nums[i]><0问题
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         map<int,int> a;//建立hash表存放数组元素
//         vector<int> b(2,-1);//存放结果
//         for(int i=0;i<nums.size();i++)
//             a.insert(map<int,int>::value_type(nums[i],i));
//         for(int i=0;i<nums.size();i++){
//             if(a.count(target-nums[i])>0&&(a[target-nums[i]]!=i)){
//                 b[0]=i;
//                 b[1]=a[target-nums[i]];
//                 break;
//             }
//         }
//         return b;
//     };
// };
// // 一遍哈希表，添加元素的同时判断是否大于零
// class Solution{
//     public:
//         vector<int> twoSum(vector<int> nums,int target){
//             map<int, int> a;
//             vector<int> result(2, -1);
//             for (int i = 0; i < nums.size(); i++){
//                 if (a.count(target - nums[i]) > 0){
//                     result[0]=a[target-nums[i]];
//                     result[1]=i;
//                     break;
//                 }
//                 a[nums[i]] = i;
//             }
//             return result;
//         }
// };
// 1431. 拥有最多糖果的孩子
// 2025年1月1日09:29:54
// 40分钟，没看懂题目意思白白浪费很多时间
// class Solution {
// public:
//     vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
//         vector<bool> result;
//         int max_candy = *max_element(candies.begin(), candies.end());
//         for (int i = 0; i < candies.size(); i++){
//             result.emplace_back(candies[i] + extraCandies > max_candy);
//         }
//         return result;
//     }
// };
// 3074. 重新分装苹果
// 2024年12月31日14:31:39
// class Solution {
// public:
//     int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
//         int count =0;
//         int sum = accumulate(apple.begin(), apple.end(), 0);
//         sort(capacity.begin(), capacity.end());
//         int a_length = apple.size(), c_length = capacity.size()-1;
//         while(sum>0){
//             sum -= capacity[c_length--];
//             count++;
//         }
//         return count;
//     }
// };
// 1446. 连续字符
// 2024年12月30日15:32:13
// 2024年12月30日15:49:49
// class Solution {
// public:
//     int maxPower(string s) {
//         int temp = 1, maxResult = 1;
//         for (int i = 0; i < s.length()-1;i++){
//             s[i] == s[i + 1] ? temp++ : temp = 1;
//             maxResult = max(maxResult, temp);
//         }
//         return maxResult;
//     }
// };
// int main(){
//     string str = "leeeeetcodeeee";
//     Solution s;
//     cout << s.maxPower(str);
// }

// 1464. 数组中两元素的最大乘积
// 2024年12月30日15:15:40]
// 五分钟
// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
//         int length = nums.size()-1;
//         sort(nums.begin(), nums.end());
//         return (nums[length] - 1) * (nums[length - 1] - 1);
//     }
// };
// int main(){
//     vector<int> vec = {1, 2, 3, 4, 5};
//     Solution s;
//     cout << s.maxProduct(vec);
// }
// 1470. 重新排列数组
// 双指针额外数组法
// class Solution {
// public:
//     vector<int> shuffle(vector<int>& nums, int n) {
//         vector<int> result(2*n);
//         for (int i = 0, j = n,k=0; k < 2*n;i++,j++){
//             result[k++] = nums[i];
//             result[k++] = nums[j];
//         }
//         return result;
//     }
// };
// int main(){
//     Solution s;
//     vector<int> vec1 = {2,5,1,3,4,7};
//     for(int x:s.shuffle(vec1,3)){
//         cout << x << " ";
//     }
// }
// 利用题目测试数据集条件转化方法
// 利用每一个数字都是正数，利用负数部分存储数据
// class Solution {
// public:
//     vector<int> shuffle(vector<int>& nums, int n) {
//         for(int i = 0; i < 2 * n; i ++)
//             if(nums[i] > 0){
//                 // j 描述当前的 nums[i] 对应的索引，初始为 i
//                 int j = i;
//                 while(nums[i] > 0){
//                     // 计算 j 索引的元素，也就是现在的 nums[i]，应该放置的索引
//                     j = j < n ? 2 * j : 2 * (j - n) + 1;
//                     // 把 nums[i] 放置到 j 的位置，
//                     // 同时，把 nums[j] 放到 i 的位置，在下一轮循环继续处理
//                     swap(nums[i], nums[j]);
//                     // 使用负号标记上，现在 j 位置存储的元素已经是正确的元素了
//                     nums[j] = -nums[j];
//                 }
//             }
//         for(int& e: nums) e = -e;
//         return nums;
//     }
// };
// 利用每一个数字最大只有1000，只占用了一个32位int中的10位，22位是空闲的
// class Solution {
// public:
//     vector<int> shuffle(vector<int>& nums, int n) {

//         for(int i = 0; i < 2 * n; i ++){
//             int j = i < n ? 2 * i : 2 * (i - n) + 1;
//             nums[j] |= (nums[i] & 1023) << 10;
//         }
//         for(int& e: nums) e >>= 10;
//         return nums;
//     }
// };
// 1394. 找出数组中的幸运数
// 2024年12月27日19:26:08
// 2024年12月27日20:05:39
// 哈希表遍历两遍
// class Solution {
// public:
//     int findLucky(vector<int>& arr) {
//         unordered_map<int, int> hashTable;
//         for(int x : arr){
//             hashTable[x]++;
//         }
//         int result = -1;
//         for(pair<int,int> temp : hashTable){
//             if(temp.first == temp.second){
//                 result = max(temp.first, result);
//             }
//         }
//         return result;
//     }
// };
// 统计最大值，判断幸运数字，找到最大的幸运数字三合一
// class Solution {
// public:
//     int findLucky(vector<int>& arr) {
//         sort(arr.begin(), arr.end());
//         int count = 1;
//          for(int i=arr.size()-1;i>0;i--){
//              if(arr[i]==arr[i-1]){
//                  count++;
//              }
//              else{
//                  if(count==arr[i]) return arr[i];
//                  count = 1;
//              }
//          }
//         if(arr[0]==count)
//             return arr[0];
//         return -1;
//     }
// };
// int main(){
//     vector<int> vec = {1, 2, 3, 4, 5};
//     Solution s;
//     cout <<s.findLucky(vec);
// }
// 1480. 一维数组的动态和
// 五分钟
// class Solution {
// public:
//     vector<int> runningSum(vector<int>& nums) {
//         for (int i = 1; i < nums.size();i++){
//             nums[i] += nums[i - 1];
//         }
//         return nums;
//     }
// };
// int main(){
//     Solution s;
//     vector<int> vec = {1,2,3,4,5,6,7};
//     for(int x : s.runningSum(vec)){
//         cout << x << " ";
//     }
// }
// 66. 加一
// 2024年12月22日13:14:51
// 十分钟 写入笔记 算法优化分析 ### 原地删除容器中元素（可能补全
// class Solution {
// public:
//     int removeElement(vector<int>& nums, int val) {
//         int current = 0;
//         for (int i = 0; i < nums.size();i++){
//             if(nums[i]!=val){
//                 nums[current++] = nums[i];
//             }
//         }
//         // nums.erase(nums.begin() + current, nums.end());
//         nums.resize(current);
//         return current;
//     }
// };
// 使用迭代器移除元素
// class Solution {
// public:
//     int removeElement(vector<int>& nums, int val) {
//         int count = 0,length = nums.size();
//         for (int i = 0; i < nums.size();i++){
//             if(nums[i]==val){
//                 count++;
//                 nums.erase(nums.begin() + i--);
//             }
//         }
//         return length - count;
//     }
// };
// int main(){
//     vector<int> test = {0,1,2,2,3,0,4,2};
//     int val = 2;
//     Solution s;
//     s.removeElement(test, val);
//     for(int x : test){
//         cout << x;
//     }
// }
// 202. 快乐数
// 2024年12月21日15:37:33
// class Solution {
// public:
//     bool isHappy(int n) {
//         for (int i = 0; i < 10;i++){
//             int sum = 0;
//             while(n>0){
//                 int temp = n % 10;
//                 sum += temp * temp;
//                 n /= 10;
//             }
//             n = sum;
//         }
//         return n == 1;
//     }
// };

// 2446. 判断两个事件是否存在冲突
// 2024年12月19日21:24:01
// 2024年12月19日21:45:01
// class Solution {
// public:
//     bool haveConflict(vector<string>& event1, vector<string>& event2) {
//         return ((stoi(event1[0].substr(0, 2)) * 60 + stoi(event1[0].substr(3, 2)) <= stoi(event2[1].substr(0, 2)) * 60 + stoi(event2[1].substr(3, 2))) && (stoi(event2[0].substr(0, 2)) * 60 + stoi(event2[0].substr(3, 2)) <= stoi(event1[1].substr(0, 2)) * 60 + stoi(event1[1].substr(3, 2))));
//     }
// };
// int main(){
//     vector<string> test1 = {"01:15", "02:00"};
//     vector<string> test2 = {"02:00", "03:00"};
//     vector<string> test3 = {"01:00 ","02:00"};
//     vector<string> test4 = {"01:20", "03:00"};
//     vector<string> test4 = {"01:20", "03:00"};
//     vector<string> test4 = {"01:20", "03:00"};
//     Solution s;
//     cout << s.haveConflict(test1, test2);
//     cout << s.haveConflict(test3, test4);
// }
// 2956. 找到两个数组中的公共元素
// 2024年12月19日21:17:21
// class Solution {
// public:
//     vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
//         vector<int> result{2};
//         unordered_set<int> us1(nums1.begin(), nums1.end()), us2(nums2.begin(), nums2.end());
//         for(int x : nums1){
//             result[0] += us2.count(x);
//         }
//         for(int x : nums2){
//             result[1] += us1.count(x);
//         }
//         return result;
//     }
// };
// 2418. 按身高排序
// 2024年12月19日15:25:55
// class Solution {
// public:
//     vector<string> sortPeople(vector<string>& names, vector<int>& heights,vector<string> results = {}) {
//         map<int, string> mapping;
//         for (int i = 0; i < heights.size();i++){
//             mapping[heights[i]] = names[i];
//         }
//         for (map<int, string>::reverse_iterator it = mapping.rbegin(); it != mapping.rend();it++){
//             results.emplace_back(it->second);
//         }
//             return results;
//     }
// };
// 红黑树逆序遍历
// class Solution {
// public:
//     vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
//         vector<int>index(heights.size()); // 索引数组
//         vector<string> result; // 答案数组
//         iota(index.begin(),index.end(),0); // 初始化索引数组
//         sort(index.begin(),index.end(),::greater()); // 降序排序索引并将索引记录在索引数组中
//         for(int i=0;i<heights.size();i++) result.emplace_back(names[index[i]]); // 通过排序后的索引顺序依次将对应的字符串记录到答案数组中，即得到最后的正确答案
//         return result; // 返回最后的答案
//     }
// };
// int main(){
//     Solution s;
//     vector<string> names = {"Mary", "John", "Emma"};
//     vector<int> heights = {180, 165, 170};
//     for(string x : s.sortPeople(names, heights)){
//         cout << x << " ";
//     }
// }
// 3099. 哈沙德数
// 2024年12月19日15:22:01
// 2024年12月19日15:24:04
// class Solution {
// public:
//     int sumOfTheDigitsOfHarshadNumber(int x) {
//         int sum = 0, tmp = x;
//         while(tmp) {
//             sum += tmp % 10;
//             tmp /= 10;
//         }
//         return (x % sum == 0)? sum: -1;
//     }
// };
// 1108. IP 地址无效化+
// 2024年12月19日12:58:25
// 2024年12月19日13:33:41 查方法，添加新内容到笔记 `find()` 和 `replace()` 循环，完成时间9分钟
// 同类型题1455  3114  面试题01.03
// 正则表达式解法
// class Solution {
// public:
//     string defangIPaddr(string& address) {
//         regex reg_patten("\\.");
//         string result = regex_replace(address, reg_patten, "[.]");
//         return result;
//     }
// };
// find&replace解法
// class Solution {
// public:
//     string defangIPaddr(string& address) {
//         size_t pos=0;
//         while((pos = address.find(".",pos))!=string::npos){
//             address.replace(pos, 1, "[.]");
//             pos += 3;
//         }
//         return address;
//     }
// };
// int main(){
//     Solution s;
//     string str = "1.1.1.1";
//     cout << s.defangIPaddr(str);
// }
// 3285. 找到稳定山的下标 每日一题
// 2024年12月19日12:20:58
// 2024年12月19日12:55:37 写题解，笔记`push_back()` 和 `emplace_back()`
// class Solution {
// public:
//     vector<int> stableMountains(vector<int>& height, int threshold) {
//         vector<int> result(0);
//         for (int i = 1; i < height.size() ;i++){
//             if(height[i-1]>threshold){
//                 result.emplace_back(i);
//             }
//         }
//         return result;
//     }
// };
// int main(){
//     Solution s;
//     vector<int> vec = {10,1,10,1,10};
//     for(int x : s.stableMountains(vec, 2)){
//         cout << x << " ";
//     }
// }
// 2024年12月17日19:30:28
// someone interrupt frequently,and write optimization analysis in ob
// 2024年12月17日20:20:22
// class Solution {
// public:
//     int hammingDistance(int x, int y) {
//         int count = 0;
//         if(x==y){
//             return 0;
//         }
//         while (x != 0||y!=0){
//             if(x%2!=y%2){
//                 count++;
//             }
//             x /= 2;
//             y /= 2;
//         }
//         return count;
//     }
// };
// int main(){
//     Solution s;
//     cout << s.hammingDistance(3,1);
// }
// 3028. 边界上的蚂蚁
// 2024年12月17日18:50:34
// class Solution {
// public:
//     int returnToBoundaryCount(vector<int>& nums) {
//         int count = 0,result=0;
//         for(int x : nums){
//             result += x;
//             if(result==0){
//                 count++;
//             }
//         }
//         return count;
//     }
// };
// int main(){
//     Solution s;
//     vector<int> vec = {3,2,-3,-4};
//     cout << s.returnToBoundaryCount(vec);
// }
// 58. 最后一个单词的长度
// 2024年12月17日12:51:57

// class Solution {
// public:
//     int lengthOfLastWord(string s) {
//         int wordLength = 0;
//         for (int i = s.size() - 1; i >= 0;i--){
//             if(s[i]!=' ')
//                 wordLength++;
//             if(wordLength != 0 && s[i] == ' ')
//                 break;
//         }
//         return wordLength;
//     }
// };
// int main(){
//     Solution s;
//     cout<<s.lengthOfLastWord("a");
// }
// 167. 两数之和 II - 输入有序数组
// 2024年12月16日17:00:03
// 2024年12月16日17:16:09
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& numbers, int target) {
//         int left = 0, right = numbers.size()-1, temp = 0;
//         while(left < right){
//             temp = numbers[left] + numbers[right];
//             if(temp == target){
//                 break;
//             }
//             temp < target ? left++ : right--;
//         }
//         return {left+1, right+1};
//     }
// };
// int main(){
//     Solution s;
//     vector<int> vec = {2, 7, 11, 15};
//     int target = 9;
//     for(int x : s.twoSum(vec, target))
//     cout << x;
// }
// 11. 盛最多水的容器
// 2024年12月16日17:04:58
// 36分钟+看提示题解
// class Solution {
// public:
//     int maxArea(vector<int>& height) {
//         int i = 0, j = height.size() - 1, max_area = 0;
//         while(i < j){
//             int result = min(height[i], height[j]) * (j - i);
//             max_area = max(result, max_area);
//             height[i]<height[j] ? i++ : j-- ;
//         }
//         return max_area;
//     }
// };
// int main(){
//     Solution s;
//     vector<int> test{1, 8, 6, 2, 5, 4, 8, 3, 7};
//     cout << s.maxArea(test);
// }
// 2183. 统计可以被 K 整除的下标对数目困难
// 2024年12月13日15:34:14

// 3162. 优质数对的总数 I
// 2024年12月13日15:11:50
// class Solution {
// public:
//     int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
//         int count = 0;
//         for (int i = 0; i < nums1.size();i++){
//             for (int j = 0; j < nums2.size();j++){
//                 if(nums1[i] % (nums2[j]*k) == 0)
//                     count++;
//             }
//         }
//         return count;
//     }
// };
// int main(){
//     vector<int> vec1 = {1, 2, 4, 12};
//     vector<int> vec2 = {2, 4};
//     Solution s;
//     cout << s.numberOfPairs(vec1, vec2, 3);
// }
// 2024年12月12日15:45:32
// 2024年12月12日15:54:28
// class Solution {
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         for (int i = 0; i < n;i++){
//             nums1[m + i] = nums2[i];
//         sort(nums1.begin(),nums1.end());
//         }
//     }
// };
// int main(){
//     vector<int> vec1 = {1, 2, 3, 0, 0, 0};
//     vector<int> vec2 = {2, 5, 6};
//     Solution s;
//     s.merge(vec1, 3, vec2, 3);
//     for(int x : vec1){
//         cout << x << " ";
//     }
// }

// 3248. 矩阵中的蛇
// 2024年12月12日15:21:37
// 2024年12月12日15:31:30
// class Solution {
// public:
//     int finalPositionOfSnake(int n, vector<string>& commands) {
//         // vector<vector<int>> matrix(n,vector<int>(n));
//         int i = 0, j = 0;
//         for(string x :commands){
//             if(x=="LEFT")
//                 j--;
//             else if(x=="RIGHT")
//                 j++;
//             else if(x=="UP")
//                 i--;
//             else
//                 i++;
//         }
//         return i * n + j;
//     }
// };

// int main(){
//     Solution s;
//     vector<string> commands = {"DOWN", "RIGHT", "UP"};
//     cout << s.finalPositionOfSnake(2, commands);
// }
// 9.回文数
// class Solution {
// public:
//     int the_positive = 0;
//     int get_size(int x){
//         int count = 1;
//         int temp = x;
//         while(temp / 10 != 0){
//             count++;
//             temp /= 10;
//         }
//         return count;
//     }

//     pair<int,int> get_start_end(int x){
//         int start = x / pow(10, get_size(x) - 1);
//         int end = x % 10;
//         return make_pair(start, end);
//     }

//     array<int,5> get5numbers(int start,int end,int number,int size){
//         int new_start = number / pow(10, size-1) ;
//         int new_end = number % 10;
//         if(new_start != new_end){
//             return array<int, 5>{-1, -1, -1, -1, 1};
//         }else if(new_start == 0){
//             int new_number = new_number + pow(10, size) + 1;
//         }
//         int new_number = number / 10 - new_start * pow(10, size - 2);
//         int new_size = size - 2;
//         if(new_size <2){
//             return array<int, 5>{-1, -1, -1, -1, 0};
//         }
//         return get5numbers(new_start, new_end, new_number, new_size);
//     }

//     bool judgement(array<int,5> arr){
//         if(arr[4]){
//             return false;
//         }else{
//             return true;
//         }
//     }
//     bool isPalindrome(int x) {
//         if(x<0){
//             return false;
//         }else{
//             return true;
//         }
//         return judgement(get5numbers(get_start_end(x).first, get_start_end(x).second, x, get_size(x)));
//     }
// };

// int main(){
//     Solution s;
//     int x = 10;
//     array<int, 5> arr = s.get5numbers(1,0,10,2);
//     cout << arr[4] << endl;
//     if(s.judgement(arr)){
//         cout << "it is !" << endl;
//     }else{
//         cout << "it is not" << endl;
//     }
// }

// 35搜索插入位置
// #include"header.h"
// class Solution {
// public:
//     int searchInsert(vector<int>& nums, int target) {
//         int end = nums.size() - 1;
//         for (int head= 0; head<=end; ){
//             int mid = (head + end) / 2;
//             if(target>nums[mid]){
//                 head = mid + 1;
//             }else if (target<nums[mid]){
//                 end = mid - 1;
//             }else{
//                 return mid;
//             }
//         }
//         return end + 1;
//     }
// };

// 278 第一个错误的版本
// #include "header.h"

// class Solution {
// public:
//     int firstBadVersion(int n) {
//         size_t head = 1;
//         size_t end = n;
//         int mid = 1;
//         while (head <= end){
//             if(head == mid && mid +1 == end){
//                 return end;
//             }
//             mid = (head + end) / 2;
//                 if(isBadVersion(mid)){
//                     head = mid;
//                 }else{
//                     end = mid;
//                 }
//             }
//         return end;
//     }
//     bool isBadVersion(int version){
//         vector<bool> vec = {1, 1, 1, 0, 0};
//         if(vec[version-1]){
//             return true;
//         }else{
//             return false;
//         }
//     }
// };

// int main(){
//     Solution s;
//     cout << s.firstBadVersion(10);
// }

// 2974. 最小数字游戏
// class Solution {
// public:
//     vector<int> numberGame(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         for (int i = 0; i < nums.size(); i += 2){
//             swap(nums[i], nums[i + 1]);
//         }
//         return nums;
//     }
// };

// int main(){
//     Solution s;
//     vector<int> vec = {4, 7, 83, 2, 1, 8, 834};
//     vector<int> new_vec = s.numberGame(vec);
//     for(int x : new_vec){
//         cout << x << " ";
//     }
// }

// // 蓝桥杯填空题
// #include "header.h"
// long long factorial_sum_iterative(long long number) {
//     if (number <= 0) {
//         return 0;
//     }
//     long long sum = 0;       // 用于存储阶乘的和
//     long long temp = 1;      // 用于存储当前的阶乘值

//     for(long long i = 1; i <= number; ++i){
//         temp = (temp * i) % 1000000000;
//         sum = (sum + temp) % 1000000000;
//     }
//     return sum;
// }
// int main(){
//     cout << factorial_sum_iterative(100) << endl;
// }

// 2194.Excel 表中某个范围内的单元格
// 字母和数字位数都只有一位版本
// class Solution
// {
// public:
//     vector<string> cellsInRange(string s){
//         vector<string> results;
//         for (char i = s[0]; i <= s[3]; i++){
//             for (char j = s[1]; j <= s[4]; j++){
//                 string single;
//                 single += i;
//                 single += j;
//                 results.push_back(single);
//             }
//         }
//             return results;
//     }
// };
// 字母一位数，数字任意位数版本
// class Solution {
// public:
//     vector<string> split_string(const string& str){
//         string current = "";
//         vector<string> result;
//         for(char c : str){
//             if(current.empty() || isalpha(c) == current.back()){
//                 current += c;
//             }else{
//                 result.push_back(current);
//                 current = c;
//             }
//         }
//         if(!current.empty()){
//             result.push_back(current);
//         }
//         return result;
//     }
//     void identify_and_classify(const vector<string> result){
//         for(string x : result){
//             if(isalpha(x[0])){
//                 characters.push_back(x);
//             }else if(isdigit(x[0])){
//                 numbers.push_back(x);
//             }
//         }
//     }
//     vector<string> characters;
//     vector<string> numbers;
// };

// int main(){
//     string s = "A10:B12";
//     Solution sol;
//     sol.identify_and_classify(sol.split_string(s));
//     for (char i = sol.characters[0][0]; i <= sol.characters[1][0];i++){
//         for (int j = stoi(sol.numbers[0]);j<(stoi(sol.numbers[1])-stoi(sol.numbers[0]));j++){
//             cout << i + j << "\t";
//         }
//     }
// }

// 正则表达式匹配字符串
// class Regular {
// public:
//     Regular(const string& input) {
//         re_numbers = regex("\\d+");
//         re_characters = regex("[A-Za-z]+");
//         this->input = input;
//     }

//     void classify() {
//         smatch match;
//         string str = input; // 使用成员变量 input
//         while (true) {
//             if (regex_search(str, match, re_characters)) {
//                 characters.push_back(match.str());
//                 str = match.suffix().str();
//             } else if (regex_search(str, match, re_numbers)) {
//                 numbers.push_back(stoi(match.str()));
//                 str = match.suffix().str();
//             }
//             // else if (/* other conditions */){
//             //     /* code */
//             // }

//             if (match.empty()) {
//                 break;
//             }
//         }
//     }

//     void show_results() {
//         for (auto x : numbers) {
//             cout << x << "\t";
//         }
//         cout << endl;
//         for (auto y : characters) {
//             cout << y << "\t";
//         }
//     }

//     void one_click() {
//         classify();
//         show_results();
//     }

// private:
//     regex re_numbers;
//     regex re_characters;
//     vector<int> numbers;
//     vector<string> characters;
//     string input;
// };

// int main() {
//     string str = "abc123def45";
//     Regular obj(str);
//     obj.one_click();
//     return 0;
// }

// 455. 分发饼干
// class Solution {
// public:
//     int findContentChildren(vector<int>& g, vector<int>& s) {
//         sort(g.begin(), g.end());
//         sort(s.begin(), s.end());
//         int count = 0;
//          for(int i = s.size() -1;i>= 0;i--){
//             for(int j = g.size() - 1;j>= 0;j--){
//                 if(s.empty()){          // mark
//                     return count;       // mark
//                 }                       // mark
//                 if(s[i] >= g[j]){
//                     count++;
//                     auto it = next(g.begin(), j);
//                     g.erase(it, g.end());
//                     s.pop_back();
//                 }
//             }
//         }
//         return count;
//     }
// };
// 2024年12月6日14:36:44 实现归并查找
// const int N =110;
// int init_array[N]{0};
// int temp[N]{0};

// void merge(int array[],int left ,int right){
//     int mid = (left + right) >> 1;
//     if(left >= right)
//         return;
//     merge(array, left, mid);
//     merge(array, mid + 1, right);
//     int i = left;
//     int j = mid + 1;
//     int k = 0;
//     while(i<=mid && j<=right){
//         if(array[i]<array[j]){
//             temp[k++] = array[i++];
//         }else{
//             temp[k++] = array[j++];
//         }
//     }
//     while(i<=mid){
//         temp[k++] = array[i++];
//     }
//     while(j<=right){
//         temp[k++] = array[j++];
//     }
//     for (int i = left, j = 0; i < right; i++,j++){
//         array[i] = temp[j];
//     }
// }
// int main(){
//     int n = 0;
//     cin >> n;
//     for (int i = 0; i < n;i++){
//         cin >> init_array[i];
//     }
//     merge(init_array, 0, n);
//     for (int i = 0; i < n;i++){
//         cout << init_array[i]<<" ";
//     }
//     return 0;
// }

// 88. 合并两个有序数组
// 莫名其妙抛出错误
// class Solution {
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
// 		while(nums2.size()){
//         	for(int i = m;i>0;i--){
//         		if(nums1[m -1]<=nums2[--n]){
//         			nums1.insert(nums1.begin()+i+1,nums2[nums2.size()-1]);
//         			nums2.pop_back();
//                 }
// 			}
// 		}
//     }
// };

// int main(){
//     vector<int> nums1 = {1, 2, 3, 4,5,6};
//     vector<int> nums2 = {2, 5, 6};
//     int m = 6;
//     int n = 3;
//     Solution s;
//     s.merge(nums1, m, nums2, n);
//     for (int i = 0; i < m;i++){
//         cout << nums1[i] << " ";
//     }
//         return 0;
// }

// 算法复习：计算阶乘
// 普通定义法
// long get_factorial(long number){
//     long result = 1;
//     for (long i = i; i <= number;i++){
//         result = result * i;
//     }
//     return result;
// }

// 迭代法
// long get_factorial(long number){
//     if (number < 0){
//         return 0;
//     }
//     if(number == 0|| number == 1){
//         return 1;
//     }
//     return get_factorial(number - 1) * number;
// }
// 计算阶乘的和
// long get_sum_of_factorial(long n){
//     long long sum = 0;
//     while(n){
//         sum += get_factorial(n--);// 注意这里要在factorial中使用，n--而不是在while终止条件中
//     }
//     return sum;
// }

// 获得范围内的素数
// 判断一个数是否是素数
// bool isPrime(long n){
//     if(n<2||(n!=2&&n%2==0)){
//         return false;
//     }else{
//         for (long i = 3; i * i <= n; i += 2){
//             if(n%i==0){
//                 return false;
//             }
//         }
//     }
//     return true;
// }

// int main(){
// cout << get_factorial(4) << endl;
// cout << get_sum_of_factorial(4) << endl;
// cout << isPrime(17)<<endl;
// cout << isPrime(19)<<endl;
// cout << isPrime(20)<<endl;
// }

// vector<string> splitString(const string& input, const string& delimiter) {
//     vector<string> result;
//     string current = "";

//     for (size_t i = 0; i < input.length(); i++) {
//         // 检查当前字符和下一个字符是否构成分隔符
//         if (i + delimiter.length() <= input.length()) {
//             string substr = input.substr(i, delimiter.length());
//             if (substr == delimiter) {
//                 if (!current.empty()) {
//                     result.push_back(current);
//                     current.clear();
//                 }
//                 i += delimiter.length() - 1; // 跳过分隔符
//                 continue;// 防止分隔符被加入current中
//             }
//         }

//         // 如果不是分隔符，则将当前字符加入 current
//         current += input[i];
//     }

//     // 如果最后一个子字符串不为空，加入结果
//     if (!current.empty()) {
//         result.push_back(current);
//     }

//     return result;
// }

// int main() {
//     string input = "ghj$\\akgho\\$\\dsghi$\\ageua$\\gdksg";
//     string delimiter = "$\\";

//     vector<string> output = splitString(input, delimiter);

//     // 输出结果
//     cout << "分割后的字符串部分：" << endl;
//     for (const auto& str : output) {
//         cout << "\"" << str << "\"" << endl;
//     }

//     return 0;
// }
