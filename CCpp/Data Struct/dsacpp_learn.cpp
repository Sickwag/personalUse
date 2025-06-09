// #include "header.h"

// bubble sort冒泡排序
// void bubble_sort(int need_sort[],int length){
//     bool sorted = false;
//     while(!sorted){
//         sorted = true;
//         for (int i = 0; i < length; i++){
//             if (need_sort[i - 1] > need_sort[i]){
//                 swap(need_sort[i - 1], need_sort[i]);
//                 sorted = false;
//             }
//         }
//         length--;
//     }
// }

// void execute_bubble_sort(){
//     int array[] = {6, 23, 8, 1, 7, 9, 2, 1, 0};
//     int array_size = sizeof(array) / sizeof(array[0]);
//     bubble_sort(array, array_size);
//     for (int j = 0; j < array_size; j++){
//         cout << array[j] << " ";
//     }
// }

// countones 算法
// int countones(unsigned int n)
// {
//     int ones = 0;
//     while (0 < n)
//     {
//         ones += (1 & n);
//         n >>= 1;
//     }
//     return ones;
// // 等效亍glibc癿内置函数int __builtin_popcount (unsigned int n
// }

// 幂函数2^n算法（蛮力迭代版），n >= 0
// __int64 power_func(int n)
// {
//     __int64 init = 1;
//     while (0 < n--)
//     {
//         init <<= 1;
//     }
//     return init;
// }

// __int64 power2BF_I(int n)
// {                    // 幂函数2^n算法（蛮力迭代版），n >= 0
//     __int64 pow = 1; // O(1)：累积器刜始化为2^0
//     while (0 < n--)  // O(n)：迭代n轮，殏轮都
//         pow <<= 1;   // O(1)：将累积器翻倍
//     return pow;      // O(1)：迒回累积器
// } // O(n) = O(2^r)，r为输入指数n癿比特位数

// 数组求和递归计算
// int sum_array(int A[],int n){
//     if(1>n){
//         return 0;
//     }else {
//         sum_array(A, n - 1) + A[n - 1];
//     }
// }

// void array_reverse(int A[],int begin,int end){
//     if(begin <= end){
//         swap(A[begin], A[end-1]);
//         // cout << A[begin] << endl;
//         // cout << A[end - 1] << endl;
//         array_reverse(A, begin+1, end-1);
//     }// else隐藏了两种递归基，一种是begin == end时，另一种是begin和end交换位置，if的判断条件是关键
// }

// int array[5] = {1, 2, 3, 4, 5};
// int size_a = sizeof(array) / sizeof(array[0]);
// array_reverse(array, 0, size_a);
// 求二次幂改进后
// inline __int64  sqr(__int64  a) { return a * a; }
// __int64  calculator(int n){
//     if (0==n)
//         return 1;
//     __int64 a = (1 & n) ? sqr(calculator(n >> 1)) << 1 : sqr(calculator(n >> 1));
//     cout << a;
//     return a;
// }

// //求二次幂改进前
// __int64 power_func(int n){
//     __int64 init = 1;
//     while (0 < n--){
//         init <<= 1;
//     }
//     return init;
// }

// 代码1.11数组求和二分递归
// int sum(int A[],int low ,int high){
//     if(low == high){
//         return A[low];
//     }
//     else{
//         int middle = (high + low) >> 1;
//         return sum(A, low, middle) + sum(A, middle + 1, high);
//     }
// }
// 代码1.12二分递归计算fibonacci数
// __int64 fibonacci(int n){
//     return (2 > n) ? (__int64)n : fibonacci(n - 1) + fibonacci(n - 2);
// }

#include <iostream>
using namespace std;

// 代码1.13 通过线性递归计算Fibonacci数
//  __int64 fibonacci(int n, __int64& previous){
//      if( 0 ==n){
//          previous = 1;
//          return 0;
//      }else {
//          __int64 prePrevious;
//          previous = fibonacci(n - 1, prePrevious);
//          return previous + prePrevious;
//      }
//  }

// 代码1.14基于策略计算Fibonacci数
// __int64 fibonacci (int n){
//     __int64 f = 0, g = 1;
//     while (0<n--){
//         g += f; // 将当前的斐波那契数加到下一个斐波那契数上
//         f = g - f; // 更新当前斐波那契数为新的下一个斐波那契数减去当前斐波那契数
//     }
//     return f;
// }


__int64 fibonacci(int n, __int64 &previous)
{
    if (0 == n)
    {
        previous = 1;
        return 0;
    }
    else
    {
        __int64 prePrevious;
        previous = fibonacci(n - 1, prePrevious);
        return previous + prePrevious;
    }
}

// 代码2.1 向量模板类Vector
typedef int Rank;          // 秩
#define DEFAULT_CAPACITY 3 // 默讣癿刜始容量（实际应用中可讴置为更大）

template <typename T>
class Vector
{ // 向量模板类
protected:
    Rank _size;
    int _capacity;
    T *_elem;                                    // 觃模、容量、数据匙
    void copyFrom(T const *A, Rank lo, Rank hi); // 复刢数组匙间A[lo, hi)
    void expand();                               // 空间丌足时扩容
    void shrink();                               // 装填因子过小时压缩
    bool bubble(Rank lo, Rank hi);               // 扫描交换
    void bubbleSort(Rank lo, Rank hi);           // 起泡排序算法
    Rank max(Rank lo, Rank hi);                  // 选叏最大元素
    void selectionSort(Rank lo, Rank hi);        // 选择排序算法
    void merge(Rank lo, Rank mi, Rank hi);       // 归并算法
    void mergeSort(Rank lo, Rank hi);            // 归并排序算法
    Rank partition(Rank lo, Rank hi);            // 轴点极造算法
    void quickSort(Rank lo, Rank hi);            // 快速排序算法
    void heapSort(Rank lo, Rank hi);             // 堆排序（稍后结合完全堆讱解）
public:
    // 构造函数
    Vector(int c = DEFAULT_CAPACITY, int s = 0, T v = 0) // 容量为c、觃s、所有元素初始为v
    {
        _elem = new T[_capacity = c];
        for (_size = 0; _size < s; _elem[_size++] = v)
            ;
    } // s<=c
    Vector(T const *A, Rank n) { copyFrom(A, 0, n); }                         // 数组整体复制
    Vector(T const *A, Rank lo, Rank hi) { copyFrom(A, lo, hi); }             // 区间
    Vector(Vector<T> const &V) { copyFrom(V._elem, 0, V._size); }             // 向量整体复制
    Vector(Vector<T> const &V, Rank lo, Rank hi) { copyFrom(V._elem, , hi); } // 区间
    // 析构函数
    ~Vector() { delete[] _elem; } // 释放内部空间
    // 叧读讵问接口
    Rank size() const { return _size; }                       // 觃模
    bool empty() const { return !_size; }                     // 刞空
    int disordered() const;                                   // 刞断向量是否已排序
    Rank find(T const &e) const { return find(e, 0, _size); } // 无序整体查找
    Rank find(T const &e, Rank lo, Rank hi) const;            // 无序向量匙间查找
    Rank search(T const &e) const                             // 有序向量整体查找
    {
        return (0 >= _size) ? -1 : search(e, 0, _size);
    }
    Rank search(T const &e, Rank lo, Rank hi) const; // 有序向量匙间查找
    // 可写讵问接口
    T &operator[](Rank r) const;                         // 重载下标操作符，可以类似亍数组形式引用素
    Vector<T> &operator=(Vector<T> const &);             // 重载赋值操作符，以便直接向量
    T remove(Rank r);                                    // 初除秩为r癿元素
    int remove(Rank lo, Rank hi);                        // 初除秩在匙间[lo, hi)元素
    Rank insert(Rank r, T const &e);                     // 揑入元素
    Rank insert(T const &e) { return insert(_size, e); } // 默讣作为素揑入
    void sort(Rank lo, Rank hi);                         // 对[lo, hi)排序
    void sort() { sort(0, _size); }                      // 整体排序
    void unsort(Rank lo, Rank hi);                       // 对[lo, hi)置乱
    void unsort() { unsort(0, _size); }                  // 整体置乱
    int deduplicate();                                   // 无序去重
    int uniquify();                                      // 有序去重
    // 遍历
    void traverse(void (*)(T &)); // 遍历（使用函数指针，叧读戒尿部性修）
    template <typename VST>
    void traverse(VST &); // 遍历（使用函数对象，尿性修改）
}; // Vector
int main()
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    return 0;
}