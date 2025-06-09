#include<bits/stdc++.h>
using namespace std;


// 动态数组代码实现

// 2073. 买票需要的时间
// 2025-02-01 13:34:52
// n n模拟方法
// class Solution {
// public:
//     int timeRequiredToBuy(vector<int>& tickets, int k) {
//         queue<pair<int, bool>> q;
//         int n = tickets.size(),time =0;
//         for (int i = 0; i < n;i++){
//             i==k ? q.push(make_pair(tickets[i], true)) : q.push(make_pair(tickets[i], false));
//         }
//         while(true){
//             int front = q.front().first;
//             bool is_target = q.front().second;
//             time++;
//             if(front>1){
//                 q.pop();
//                 q.push(make_pair(--front,is_target));
//             }else if(is_target){
//                 return time;
//             }else{
//                 q.pop();
//             }
//         }
//         return time;
//     }
// };
// 2025-02-01 13:28:11
// [ 用时: 09 m 29 s ] n 1 数学方法，不使用队列模拟
// class Solution {
// public:
//     int timeRequiredToBuy(vector<int>& tickets, int k) {
//         int time = 0;
//         for (int i = 0; i < k;i++){
//             time += tickets[i] >= tickets[k] ? tickets[k] : tickets[i];
//         }
//         for (int j = k + 1; j < tickets.size();j++){
//             time+= tickets[j] >= tickets[k] ? tickets[k]-1 : tickets[j];
//         }
//         return time + tickets[k];
//     }
// };
// 20. 有效的括号
// 2025-02-01 10:43:18
// [ 用时: 26 m 44 s ] n 1 知道应该用栈但是总是在边界问题上出错，看题解后做出来
// class Solution {
// public:
//     bool isValid(string s) {
//         stack<char> content;
//         for(char single : s){
//             if(single == '{' || single == '[' || single == '('){
//                 content.push(single);
//             }else{
//                 if(content.empty())  return false;
//                 if(single == '}'&& content.top()!='{')  return false;
//                 if(single == ')'&& content.top()!='(')  return false;
//                 if(single == ']'&& content.top()!='[')  return false;
//                 content.pop();
//             }
//         }
//         return content.empty();
//     }
// };
// 136. 只出现一次的数字
// 想不出来符合题意的解法，最多只能nlogn，看题解，发现异或做法
// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         return reduce(nums.begin(), nums.end(), 0, bit_xor());
//     }
// };
// 704. 二分查找
// 2025-02-01 09:58:29
// [ 用时: 5 m 40 s ] logn 1 借助库函数，lower_bound和upper_bound底层原理就是二分查找
// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//         auto it = lower_bound(nums.begin(), nums.end(), target);
//         if(it!=nums.end()&&*it==target){
//             // return static_cast<size_t>(it - nums.begin());
//             return it - nums.begin();
//         }else{
//             return -1;
//         }
//     }
// };