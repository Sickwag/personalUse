#include<bits/stdc++.h>
using namespace std;

// 203. 移除链表元素

// class Solution {
// public:
//     ListNode* removeElements(ListNode* head, int val) {
//         ListNode *dummy = new ListNode(-1, head);
//         ListNode *fore = dummy;
//         ListNode *curr = head;
//         while (curr!=NULL) {
//             curr->val == val ? fore->next = curr->next :  fore = curr;
//             curr = curr->next;
//         }
//         return dummy->next;
//     }
// };
// 19. 删除链表的倒数第 N 个结点
// 2025-01-31 17:47:57
// Definition for singly-linked list.
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };
// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         ListNode *dummy = new ListNode(0, head);
//         ListNode* slow = dummy;
//         ListNode* fast = dummy;
//         for (int i = 0; i < n;i++){
//             fast = fast->next;
//         }
//         while (fast->next != nullptr){
//             fast = fast->next;
//             slow = slow->next;
//         }
//         ListNode *toDelete = slow->next;
//         // delete slow->next;
//         slow->next = slow->next->next;
//         delete toDelete;
//         ListNode* newhead = dummy->next;
//         delete dummy;
//         return newhead;
//     }
// };
// 160. 相交链表
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };
// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         unordered_set<ListNode*> mapping;
//         while(headA!=NULL){
//             mapping.insert(headA);
//             headA = headA->next;
//         }
//         while(true){
//             if(headB == NULL){
//                 return NULL;
//             }else if(mapping.find(headB)!=mapping.end()){
//                 return headB;
//             }else{
//                 headB = headB->next;
//             }
//         }
//     }
// };
// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         if(headA == NULL || headB == NULL){
//             return NULL;
//         }
//         ListNode *pa = headA, *pb = headB;
//         while(pa!=pb){
//             pa == NULL ? pa = headB : pa = pa->next;
//             // 化简为 pa = pa ? headB : pa->next;但有点过于抽象
//             pb == NULL ? pb = headA : pb = pb->next;
//         }
//         return pa;
//     }
// };
// 485. 最大连续 1 的个数
// 2025-01-31 12:33:51
// 5mins n 1 简单模拟方法
// class Solution {
// public:
//     int findMaxConsecutiveOnes(vector<int>& nums) {
//         int n = nums.size(), count = 0, result = 0;
//         for (int i = 0; i < n;i++){
//             if(nums[i]==0){
//                 count = 0;
//             }else{
//                 count++;
//             }
//             result = max(result, count);
//         }
//         return result;
//     }
// };
// 两极记录法
// class Solution {
// public:
//     int findMaxConsecutiveOnes(vector<int>& nums) {
//         int n = nums.size(), result = 0,index = -1;
//         for (int i = 0; i < n;i++){
//             if (nums[i] == 0){
//                 index = i;
//             }else{
//                 result = max(result, i - index);
//             }
//         }
//         return result;
//     }
// };
// 283. 移动零
// 快慢指针一次遍历
// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
//         // solution: twp pointer(fast slow)
//         int slow = 0;
//         for (int fast = 0; fast < nums.size(); ++fast) {
//             if (nums[fast] != 0) {
//                 swap(nums[slow], nums[fast]);
//                 slow++;
//             }
//         }
//     }
// };
// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
//         int j = 0;
//         for (int i = 0; i < nums.size();i++){
//             if(nums[i]!=0){
//                 if(i>j){
//                     nums[j] = nums[i];
//                     nums[i] = 0;
//                 }
//                 j++;
//             }
//         }
//     }
// };
// 2025-01-30 16:07:24
// 似乎leetcode不熟的环境不允许过，本地测试集是可以过的
// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
//         int count = 0, n=nums.size();
//         for (int i = 0;i<n;i++){
//             if(nums[i]==0){
//                 count++;
//             }
//         }
//         for (int j = n - count - 1; j >= 0;j--){

//         }
//     }
// };
// 2025-01-30 16:30:32
// 通过解法，两次遍历，n n 还想了很久
// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
//         int n = nums.size(), low = 0, fast = 0, count=0;
//         while(fast < n){
//             if(nums[fast] != 0){
//                 nums[low++] = nums[fast];
//                 count++;
//             }
//             fast++;
//         }
//         for (int i = count;i<n;i++){
//             nums[i] = 0;
//         }
//     }
// };
// 27. 移除元素
// 2025-01-30 15:42:45
// 00 : 07 : 52 n 1 模拟法
// class Solution {
// public:
//     int removeElement(vector<int>& nums, int val) {
//         int i = 0, j = 0, n = nums.size();
//         while(i<n){
//             nums[i] ^ val == 1 ? nums[j++] = nums[i] : i++;
//         }
//         return j;
//     }
// };
// 26. 删除有序数组中的重复项
// 2025-01-30 15:19:35
// 00 : 07 : 52  n 1 像是刚学时候写的代码，但是快
// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         int j = 0;
//         for(int i = 0;i<nums.size();i++){
//             if(i==0 || nums[i]!=nums[i-1]){
//                 nums[j++] = nums[i];
//             }
//         }
//         return j;
//     }
// };
// 2025-01-30 15:10:48
// 00 : 07 : 52 n n 最简单两次遍历，借助set容器
// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         set<int> mapping(nums.begin(), nums.end());
//         nums.assign(mapping.begin(), mapping.end());
//         return mapping.size();
//     }
// };

