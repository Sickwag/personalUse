// #include<bits/stdc++.h>
// #include "dataStruct.cpp"
// using namespace std;
// int main() {
//     int length, target, count = 0;
//     cin >> length;
//     vector<int> nums(length);
//     for (int i = 0;i < length;i++) {
//         cin >> nums[i];
//     }
//     cin >> target;
//     for (int i = 0;i < length;i++) {
//         if (target == nums[i]) count++;
//     }
//     cout << count;
//     return 0;
// }
// 计算202320232023的阶乘和
// 只需要计算100就可以得到答案
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

// 2309 好数
// class functions{
//     public:
//     bool is_odd(int number){
//         return number % 2 == 1;
//     }
//     bool get_and_judge(int number,bool flag = false){
//         bool judgement = true;
//         while(number != 0){
//             int result = number % 10;
//             number /= 10;
//             if((is_odd(result)^flag)){
//                 judgement = true;
//             }else{
//                 return !judgement;
//             }
//             flag = !flag;
//         }
//         return judgement;
//     }
// };

// int main(){
//     functions f;
//     int range,count = 0;
//     cin >> range;
//     for (int i = 1; i <= range; i++){
//         if(f.get_and_judge(i)){
//             count++;
//         };
//     }
//     cout << count;
// }

// 握手问题

// R格式
// #include "header.h"

// int main(){
//     int n
//     cin >> n>> float_number;

// }

// 小球反弹
// #include "header.h"
// const int x0 = 343720;
// const int y0 = 233333;
// enum all_edges{
//     a,
//     b,
//     c,
//     d,
//     ab,
//     bc,
//     cd,
//     da
// };
// enum all_vecs{
//     vec1,
//     vec2,
//     vec3,
//     vec4
// };
// typedef struct status{
//     int x;
//     int y;
//     all_vecs vec;
//     all_edges edge;
// } s,*sta;

// all_edges get_pos(status s){
//     if(s.x==0){
//         return d;
//     }
//     else if (s.y == 0){
//         return a;
//     }else if(s.x==x0){
//         return c;
//     }else if(s.y==y0){
//         return b;
//     }
// }
// double calc_distance(int x,int y,int a,int b){
//     return sqrt(pow(x - a, 2) + pow(y - b, 2));
// }
// all_vecs calc_vec(status &s,double &distance){
//     int key = static_cast<int>(s.edge) * 8 + static_cast<int>(s.vec);
//     double temp_x = s.x;
//     double temp_y = s.y;
//     switch (key){
//     case a*8+vec4:
//         s.y = s.x * 17 / 15 + s.y;
//         s.x = 0;
//         s.vec = vec1;
//         s.edge = get_pos(s);
//         distance += calc_distance(s.x, s.y, temp_x, temp_y);
//         break;
//     };
// }