#include<bits/stdc++.h>
using namespace std;

void get(auto& input) {
    for (const auto& x : input) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    vector<int> v = { 1, 2, 3, 4 };
    list<int> l = { 5, 6, 7 };

    get(v); // 输出: 1 2 3 4
    get(l); // 输出: 5 6 7

    int arr[] = { 10, 20, 30 };
    get(arr); // 输出: 10 20 30

    return 0;
}
// 137. 只出现一次的数字 II random
// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         if(nums.size()==1){
//             return nums[0];
//         }
//         sort(nums.begin(), nums.end());
//         int all_sum = reduce(nums.begin(), nums.end(), 0);
//         auto last = unique(nums.begin(), nums.end());
//         int merely_sum = reduce(nums.begin(), last, 0);
//         return (all_sum - 3 * merely_sum) * -1 / 2;
//     }
// };
// 287. 寻找重复数
// 2025-02-07 15:09:43
// 想到了对号入座方法，但没想到原地更新，本来想要辅助数组容器，仔细看测试集发现测试集大小范围和下标匹配，符合原地更新，否则只能用辅助容器
// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         int i = 0;
//         for (i;i < nums.size();) {
//             if (nums[i] == 0) {
//                 return i;
//             }
//             int num = nums[i];
//             nums[i] = 0;
//             i = num;
//         }
//         return i;
//     }
// };
// 240. 搜索二维矩阵 II
// 2025-02-02 11:23:18
// [ 用时: 11 m 3 s ] 传统做法，对每一层进行二分查找  传统做法 nlogn 1
// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int row = matrix.size();
//         int col = matrix[0].size();
//         for (int i = 0; i < row;i++){
//             auto found = lower_bound(matrix[i].begin(), matrix[i].end(), target);
//             if(found==matrix[i].end() || *found > target){
//                 continue;
//             }else if(*found == target){
//                 return true;
//             }else{
//                 return false;
//             }
//         }
//         return false;
//     }
// };
// 代码确实按照设想的样子跑，但是设想出错了，代码是错的
// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         vector<int> head;
//         int row = matrix.size(), col = matrix[0].size();
//         for(auto x : matrix){
//             head.emplace_back(x[0]);
//         }
//         auto it = lower_bound(head.begin(), head.end(),target);
//         if(*it == target){
//             return true;
//         }else if(it==head.begin()){
//             return false;
//         }else{
//             auto last = matrix[it - head.begin() - 1];
//             auto it2 = lower_bound(last.begin(), last.end(), target);
//             if(*it2 == target){
//                 return true;
//             }else{
//                 return false;
//             }
//         }
//     }
// };
// 169. 多数元素
// 2025-02-02 10:19:31
// Boyer-Moore 投票算法：时间复杂度 O(n)，空间复杂度 O(1)，但仅适用于众数出现次数超过一半的情况。
// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         int winner = nums[0];
//         int enemy = 0, n = nums.size(), members = 1;
//         for (int i = 1; i < n;i++){
//             if(nums[i]==winner){
//                 members++;
//             }else if(members==0){
//                 winner = nums[i];
//                 members++;
//             }else{
//                 members--;
//             }
//         }
//         return winner;
//     }
// };
// 排序但是不遍历算法
// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         int n = nums.size();
//         sort(nums.begin(), nums.end());
//         return nums[n / 2];
//     }
// };
// 5mins nlogn 1排序算法
// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         int n = nums.size(), count = 1 ,major = nums[0];
//         for (int i = 0; i < n - 1;i++){
//             if(nums[i]==nums[i+1]){
//                 count++;
//                 if(count > n/2){
//                     major = nums[i];
//                     break;
//                 }
//             }
//         }
//         return major;
//     }
// };
// 5mins最简单n n 哈希表法
// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         unordered_map<int,int> mapping;
//         int length = nums.size(),major =0;
//         for(int x : nums){
//             mapping[x]++;
//             if(mapping[x]>length/2){
//                 major = x;
//                 break;
//             }
//         }
//         return major;
//     }
// };