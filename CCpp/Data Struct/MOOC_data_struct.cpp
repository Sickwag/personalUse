// 1 打印沙漏

// #include<iostream>
// #include<utility>
// using namespace std;
// pair<int,int> get_lines(int sum){
//     for (int n = 1; n < 1000;n++){
//         int left = sum - (2 * n * n - 1);
//         if(left < 4 *n -2){
//             return make_pair(left, n);
//         }
//     }
//     return make_pair(-1, -1);
// }
// void draw(int lines,char sign){
//     for (int i = lines; i > 0; i--){
//         for (int k = lines - i; k > 0; k--){
//             cout << " ";
//         }
//         for (int j = 2 * i - 1; j > 0; j--){
//             cout << sign;
//         }
//         cout << "\n";
//     }
//     for (int i = 1; i < lines; i++){
//         for (int k = lines - i - 1; k > 0; k--){
//             cout << " ";
//         }
//         for (int j = 2 * i + 1; j > 0; j--){
//             cout << sign;
//         }
//         cout << "\n";
//     }
// }
// int main(){
//     int numbers;
//     char signature;
//     cin >> numbers >> signature;
//     pair<int, int> p = get_lines(numbers);
//     draw(p.second, signature);
//     cout<< p.first;
// }


// 素数对猜想
// #include <iostream>
// #include <vector>

// // 函数：使用埃拉托斯特尼筛法生成不超过 n 的所有素数
// int eratosthenes(int n) {
//     std::vector<bool> is_prime(n + 1, true); // 初始化所有数为素数
//     is_prime[0] = is_prime[1] = false; // 0 和 1 不是素数

//     for (int i = 2; i * i <= n; ++i) {
//         if (is_prime[i]) {
//             // 标记所有 i 的倍数为非素数
//             for (int j = i * i; j <= n; j += i) {
//                 is_prime[j] = false;
//             }
//         }
//     }
//     int count = 0;
//     for (int i = 2; i <= n; ++i) {
//         if (is_prime[i] && is_prime[i + 2]) {
//             count++;
//         }
//     }
//     return count;
// }

// int main() {
//     int N;
//     std::cin >> N; // 读取输入
//     std::cout << eratosthenes(N);
//     return 0;
// }
// #include <iostream>
// #include <vector>

// // 函数：使用埃拉托斯特尼筛法生成不超过 n 的所有素数
// std::vector<int> eratosthenes(int n) {
//     std::vector<bool> is_prime(n + 1, true); // 初始化所有数为素数
//     is_prime[0] = is_prime[1] = false; // 0 和 1 不是素数

//     for (int i = 2; i * i <= n; ++i) {
//         if (is_prime[i]) {
//             // 标记所有 i 的倍数为非素数
//             for (int j = i * i; j <= n; j += i) {
//                 is_prime[j] = false;
//             }
//         }
//     }

//     // 收集所有素数
//     std::vector<int> primes;
//     int count = 0;
//     for (int i = 2; i <= n; ++i) {
//         if (is_prime[i] && is_prime[i-2]){
//             count++;
//         }
//         if (is_prime[i]) {
//             primes.push_back(i);
//             std::cout << count;
//         }
//     }

//     return primes;
// }

// int main() {
//     int N;
//     std::cin >> N; // 读取输入

//     std::vector<int> primes = eratosthenes(N); // 生成素数列表

//     // 输出素数列表
//     for (int prime : primes) {
//         std::cout << prime << " ";
//     }
    

//     return 0;
// }

