#include <thread>
#include <future>
#include <chrono>
#include <regex>
#include <queue>
#include <numeric>
#include <functional>
#include <bitset>
#include <map>
#include <queue>
#include <variant>
#include <deque>
#include <list>
#include <array>
#include <cctype>
#include <sstream>
#include <fstream>
#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <algorithm>
#include <condition_variable>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    vector<int> vec = { 1,2,3,4,5 };
    initializer_list<int> il{ ([&vec] {cout << vec << endl;}(), 0)... };
}

template<typename T, typename... Ts>
auto printf3(T value, Ts... args) {
    std::cout << value << std::endl;
    (void)std::initializer_list<T>{([&args] {
        std::cout << args << std::endl;
        }(), value)...};
}
volatile
vector<int>
// 二维数组创建和删除

// #include<iostream>
// using namespace std;
// int main(){
//     // 创建一个[4][8] 数组
//     int **p;
//     int i, j;
//     p = new int *[4];
//     for (i = 0; i < 4; i++){
//         p[i] = new int[8];
//     }

//     // fill content in array
//     for (i = 0; i < 4;i++){
//         for (j = 0; j < 8;j++){
//             p[i][j] = i * j;
//         }
//     }

//     //print the contend
//     for (i = 0; i < 4;i++){
//         for (j = 0; j < 8;j++){
//             if(j==0)
//                 cout << endl;
//             cout << p[i][j] << "\t";
//         }
//     }

//     // release the resource
//     for (i = 0; i < 4;i++){
//         delete p[i];
//     }
//     delete[] p;
//     return 0;
// }

// 三维数组创建和删除

// #include<iostream>
// using namespace std;
// int main(){
//     //create 3 dimension array
//     int ***array;
//     int i, j, k; // [3][4][5]
//     array = new int **[3];
//     for (i = 0; i < 3; i++){
//         array[i] = new int *[4];
//         for (j = 0; j < 4; j++){
//             array[i][j] = new int[5];
//         }
//     }

//     // fill contend in array and print
//     for (i = 0; i < 3;i++){
//         for (j = 0; j < 4; j++){
//             for (k = 0; k < 5; k++){
//                 array[i][j][k] = i * j * k;
//                 cout << array[i][j][k] << "\t";
//             }
//             cout << endl;
//         }
//         cout << endl;
//     }

// release the resource

//     for (i = 0; i < 3; i++){
//         for (j = 0; j < 4; j++){
//             delete[] p[i][j];
//         }
//     }
//     for (i = 0; i < 3; i++){
//         delete[] p[i];
//     }
//     delete[] p;
//  return 0;
// }

// 创建链表
// #include <iostream>
// using namespace std;

// struct node
// {
//     // 链表的节点
//     int data;          // 数据
//     int num;           // 节点编号
//     struct node *next; // 指向下一个节点
// };

// int main()
// {
//     struct node *head /*头节点*/, *p, *q;
//     head = NULL;
//     p = NULL;
//     q = new node;
//     q->next = NULL;
//     q->num = 1;
//     int a = -1;
//     cout << "请输入第1个数字:";
//     cin >> a;
//     q->data = a;
//     head = q;
//     while (a != 0)
//     {
//         p = q;
//         q = new node;
//         q->next = NULL;
//         p->next = q;
//         q->num = p->num + 1;
//         cout << "请输入第" << q->num << "个数字:";
//         cin >> a;
//         q->data = a;
//     }

//     // 前面都是输入,这以下都是输出

//     q = head;
//     p = NULL;
//     while (1)
//     {
//         printf("%d %d\n", q->num, q->data);
//         if (q->data == 0)
//             break;
//         q = q->next;
//     }

//     // 释放内存

//     q = head;
//     p = q;
//     while (1)
//     {
//         p = q->next;
//         delete[] q;
//         q = p;
//         if (!q)
//             break;
//     }
//     return 0;
// }

// object memory dynamic
// #include<iostream>
// using namespace std;
// class Box{
//     public:
//     Box(){
//         cout << "call constructor \n";
//     };
//     ~Box(){
//         cout << "call destructor \n";
//     }
// };
// int main(){
//     Box *box_array = new Box[2];
//     delete box_array;
//     return 0;
// }

// #include <iostream>
// using std::cout;
// int main()
// {
//     int a;
//     cout << "std::endl is used with std!" << std::endl;
//     std::cin >> a;
//     return 0;
// }

// #include<iostream>
// using namespace std;

// template <typename T,typename S >
// void Swap(T &a, S &b)
// {
//     T tmp = a;
//     a = b;
//     b = tmp;
// }
// int main(){
//     int a = 10;
//     int b = 30;
//     Swap(a, b);
//     cout << "a = " << a << "   b = " << b << endl;
// }

// #include <iostream>
// using namespace std;

// int main()
// {
//     cout << "Value of __LINE__ : " << __LINE__ << endl;
//     cout << "Value of __FILE__ : " << __FILE__ << endl;
//     cout << "Value of __DATE__ : " << __DATE__ << endl;
//     cout << "Value of __TIME__ : " << __TIME__ << endl;
//     system("pause");
//     return 0;
// }

// #include <iostream>
// #include <csignal>
// #include <unistd.h>

// using namespace std;

// void signalHandler(int signum)
// {
//     cout << "Interrupt signal (" << signum << ") received.\n";

//     // 清理并关闭
//     // 终止程序

//     exit(signum);
// }

// int main()
// {
//     // 注册信号 SIGINT 和信号处理程序
//     signal(SIGINT, signalHandler);

//     while (1)
//     {
//         cout << "Going to sleep...." << endl;
//         sleep(1);
//     }

//     return 0;
// }

// #include<iostream>
// #include<csignal>
// #include<unistd.h>

// using namespace std;
// void signalHandler(int signum){
//     cout << "interrupt signal " << signum << " received.";
//     exit(signum);
// }
// int main(){
//     signal(SIGINT, signalHandler);// due to second argument is a pointer ,so write signalHandler instead of signalHandle()
//     while(1){
//         cout << "go to sleep " << endl;
//         sleep(1);
//     }
//     return 0;
// }

// #include<iostream>
// #include<csignal>
// #include<unistd.h>
// using namespace std;

// void signalHandler(int signum){
//     cout << "interrupt signal " << signum << " received ." << endl;
//     exit(signum);
// }
// int main(){
//     int i = 0;
//     signal(SIGINT, signalHandler);
//     while(++i){
//         cout << "go to sleep " << endl;
//         if (i == 3 )
//             raise(SIGINT);
//         sleep(1);
//     }
// }

// #include <iostream>
// #include <mingw.thread.h>
// using namespace std;

// void printMessage(int count){
//     for (int i = 0; i < count; i++){
//         cout << "print a message ." << endl;
//     }
// }
// int main()
// {
//     thread t1(printMessage, 5);
//     t1.join();
//     return 0;
// }

// #include <iostream>
// #include <mingw.thread.h>

// class PrintTask
// {
// public:
//     void operator()(int count) const{
//         for (int i = 0; i < count; ++i){
//             std::cout << "Hello from thread (function object)!\n";
//         }
//     }
// };

// int main(){
//     std::thread t2(PrintTask(), 5);
//     /*
//    按理说PrintTask()本意是创建一个临时对象，
//    但是void operator()这个重载函数不是构造函数，
//    创建对象的时候不会调用，为什么5会传入
//    void operator()(int count)中？
//     */
//     t2.join();
//     return 0;
// }

//
//// define lock and ready
// mutex mtx;
// condition_variable cv;
// bool ready = false;
//
// void WorkerThread() {
//     unique_lock<mutex> lock(mtx); // get lock autonomy
//     cv.wait(lock, [] { return ready; }); //  use lambda to control ready
//     cout << "Worker thread: ready is now true." << endl;
// }
//
// void mainThread() {
//     lock_guard<mutex> lock(mtx); // 自动获取锁
//     ready = true;
//     cv.notify_one();
// }
//
// int main() {
//     thread worker(WorkerThread);
//     mainThread();
//     worker.join();
//     return 0;
// }

// 原子操作
// #include <atomic>
// #include <thread>
// #include <iostream>
//
// std::atomic<int> count(0);
//
// void increment() {
//    int temp = count.fetch_add(1, std::memory_order_relaxed);
//    std::cout << "incremented to : " << temp << std::endl;
//}
//
// int main() {
//    std::thread t1(increment);
//    std::thread t2(increment);
//    t1.join();
//    t2.join();
//    std::cout << "the final counter is : " << count << std::endl;
//    return count; // 应返回2
//}

// 线程局部存储
// #include <iostream>
// #include <thread>
// using namespace std;
//
// thread_local int threadData = 0;
//
// void increment() {
//	++threadData;
//	cout << "thread id = " << this_thread::get_id() << "result = " << threadData;
//}
// int main() {
//	thread t1(increment);
//	thread t2(increment);
//	thread t3(increment);
//
//	t1.join();
//	t2.join();
//	t3.join();
//}

// 线程中通信
// #include <iostream>
// #include <future>
// #include <thread>
//
// using namespace std;
//
// void printMsg(future<int>& fut) {
//	int x = fut.get();//wait for fut obj_value be set
//	cout << "x = " << x << endl;
//}
//
// int main() {
//	promise<int> prom;
//	future<int> fut = prom.get_future(); // initialize fut var
//	thread t(printMsg, ref(fut));
//
//	prom.set_value(10);// this set value operation is in main(main func) "thread" ,once set,printMsg func will work
//	t.join();
//	return 0;
//}

// 线程标准库
// #include <iostream>
// #include <thread>
//
// std::thread::id main_thread_id = std::this_thread::get_id();

// void hello()
// {
//    std::cout << "Hello Concurrent World\n";
//    if (main_thread_id == std::this_thread::get_id())
//        std::cout << "This is the main thread.\n";
//    else
//        std::cout << "This is not the main thread.\n";
// }

// void pause_thread(int n) {
//    std::this_thread::sleep_for(std::chrono::seconds(n));
//    std::cout << "pause of " << n << " seconds ended\n";
// }

// int main() {
//    std::thread t(hello);
//    std::cout << t.hardware_concurrency() << std::endl;//可以并发执行多少个(不准确)
//    std::cout << "native_handle " << t.native_handle() << std::endl;//可以并发执行多少个(不准确)
//    t.join();
//    std::thread a(hello);
//    a.detach();
//    std::thread threads[5];                         // 默认构造线程

//    std::cout << "Spawning 5 threads...\n";
//    for (int i = 0; i < 5; ++i)
//        threads[i] = std::thread(pause_thread, i + 1);   // move-assign threads
//    std::cout << "Done spawning threads. Now waiting for them to join:\n";
//    for (auto& thread : threads)
//        thread.join();
//    std::cout << "All threads joined!\n";
// }

// detach分离线程
// #include <iostream>
// #include <thread>
// #include <vetor>

// using namespace std;
// void printMsg() {
// 	for (int i = 0; i < 5; i++) {
// 		cout << i+1 << endl;
// 		std::this_thread::sleep_for(chrono::seconds(1));//temporary sleep current thread 1 second
// 	}
// }
// int main() {
// 	thread t(printMsg);
// 	t.detach();
// 	cout << "main thread is going on ." << endl;
// 	this_thread::sleep_for(chrono::seconds(6));
// 	cout << "main thread is executed ." << endl;
// }

// vector 和for_each迭代器
// int main() {
//	vector<int> vec = { 1,2,3,4,5 };
//	for_each(vec.begin(), vec.end(), [](int x) {cout << x << " "; });
//	return 0;
//}

// 复现标准线程库

// thread::id main_thread_id = this_thread::get_id();

// void printHello() {
// 	cout << "hello " << endl;
// 	if (this_thread::get_id() == main_thread_id) {
// 		cout << "this is main thread " << endl;
// 	}
// 	else {
// 		cout << "this is not main thread " << endl;
// 	}
// }
// void pause_thread(int n) {
// 	this_thread::sleep_for(chrono::seconds(n));
// 	cout << "this thread is paused " << n << " second .\n" << endl;
// }

// int main() {
// 	thread h(printHello);
// 	cout << h.hardware_concurrency() << endl;
// 	cout <<"the native handle is "<< h.native_handle() << "\n" << endl;
// 	h.join();

// 	thread a(printHello);
// 	a.detach();

// 	cout << "spawning 5 threads .... \n";
// 	thread threads[5];
// 	for (int i = 0; i < 5; ++i) {
// 		threads[i] = thread(pause_thread, i);
// 	}
// 	cout << "spawning thread ,now wait for them to join " << endl;
// 	for (auto &thread : threads)
// 		thread.join();
// 	cout << "all threads are joined" << endl;
// 	return 0;
// }

// stl标准库
// int main() {
//	vector<int> vec;
//	cout << "now vec is empty " << vec.size() << endl;
//
//	for (int x = 0; x < 5; x++)
//		vec.push_back(x);
//
//	for (auto y : vec)
//		cout << y << endl;
//	cout << "now vec has " << vec.size() << " elements " << endl;
//}

// 设置字符串格式化
// int main() {
//    double pi = 3.14159;
//
//    // 设置输出精度
//    cout << setprecision(3) << pi << endl;
//
//    // 设置输出宽度和对齐方式
//    cout << setw(10) << left << pi << endl;
//    cout << setw(10) << right << pi << endl;
//    return 0;
//}

// 处理字符串输入
// int main() {
//	string fullname;
//	getline(cin, fullname);
//	cout << fullname << endl;
//}

// 文件操作
// int testfile(fstream& file) {
//	if (!file) {
//		cerr << "cannot open the file ." << endl;
//		return 1;
//	}
//}
//
// int main() {
//	fstream file1;
//	file1.open("testfile.txt", ios::out);
//	testfile(file1);
//	file1 << "this is first line .\n";
//	file1.close();
//
//	fstream file2;
//	file2.open("testfile.txt", ios::app);
//	testfile(file2);
//	file2 << "this is second append line .\n";
//	file2.close();
//
//	fstream file3;
//	file3.open("testfile.txt", ios::in);
//	testfile(file3);
//
//	string line;
//	while (getline(file3, line)) {
//		cout << line << endl;
//	}
//	return 0;
//}

// 字符串处理
// int main() {
//	string data = "10.5,52.3,10,25,99,4.2,105.8";
//	string token;
//	istringstream iss(data);
//	vector<int> integers;
//	vector<double> doubles;
//
//	while (getline(iss, token, ',')) {
//		if (all_of(token.begin(), token.end(), ::isdigit)) {
//			integers.push_back(stoi(token));
//		}
//		else {
//			doubles.push_back(stod(token));
//		}
//	}
//	cout << "integers : ";
//	for (int i : integers)
//		cout << i << " ";
//	cout << "\ndoubles : ";
//	for (int j : doubles)
//		cout << j << " ";
//	return 0;
//}
// 流格式化
// int main() {
// // 设置宽度
// 	double pi = 3.14159;
// 	cout << setw(10) << pi << endl;
// // 设置精度
// 	cout << setprecision(5) << pi << endl;
// // 固定小数点和科学计数法
// 	cout << fixed << pi << endl;
// 	cout << scientific << pi << endl;
// // 设置填充字符
// 	cout << setfill('_') << setw(10) << "hello" << endl;
//  //设置重置格式标志
// 	cout << setiosflags(ios::uppercase) << hex << 255 << "\t" << resetiosflags(ios::uppercase) << 255 << endl;
// }

// array类
// int main()
// {
//     std::array<int, 5> m_array[5]; // 一维数组，每个元素是 std::array<int, 5>

//     // 初始化每个 std::array 中的元素
//     for (int i = 0; i < 5; ++i)
//     {
//         for (int j = 0; j < 5; ++j)
//         {
//             m_array[i][j] = i + j; // 为每个元素赋值
//         }
//     }

//     // 打印每个 std::array 中的元素
//     for (int i = 0; i < 5; ++i)
//     {
//         for (int j = 0; j < 5; ++j)
//         {
//             std::cout << m_array[i][j] << " ";
//         }
//         std::cout << std::endl;
//     }

//     return 0;
// }

// list容器操作
// int main(){
//     std::list<int> my_list;
//     my_list.push_back(10);
//     my_list.push_back(20);
//     my_list.push_back(30);
//     my_list.push_back(40);
//     my_list.push_back(50);

//     for (list<int>::iterator temp_list = my_list.begin(); temp_list != my_list.end();++temp_list)
//         cout << *temp_list << "\t";
// }

// deque容器操作
// int main(){
//     deque<variant<int, string, double>> my_deque;

//     my_deque.push_back("hello world");
//     my_deque.push_back(1234);
//     my_deque.push_back(3.14);

//     for(const auto &x : my_deque){
//         if(holds_alternative<int>(x)){
//             cout << x << " is " << get<int>(x) << endl;
//         }else(holds_alternative<double>(x)){
//             cout << x << " is " << get<double>(x) << endl;
//         }else{
//             cout << x << " is " << get<string>(x) << endl;
//         }
//     }
//     cout << endl;
//     return 0;
// }

// priority_queue容器
// struct compare{
//     bool operator()(int a ,int b){
//         return a > b; // define a minimum heap
//     }
// };

// int main(){
//     priority_queue<int, vector<int>, compare> p_min;
//     p_min.push(1);
//     p_min.push(2);
//     p_min.push(4);
//     p_min.push(34);
//     p_min.push(6);
//     p_min.push(9);
//     p_min.push(17);

//     while (!p_min.empty()){
//     cout << p_min.top() << endl;
//     p_min.pop();
//     }
// }

// map容器
// int main(){
//     map<string, int> employees;
//     employees["alpha"] = 123;
//     employees["beta"] = 456;
//     employees["charlie"] = 789;

//     for (map<string, int>::iterator it = employees.begin(); it != employees.end(); ++it)
//         cout << "key = " << it->first << "\t value = " << it->second << endl;

//     return 0;
// }
//bitset
// int main()
// {
//     // 创建一个大小为8的bitset
//     std::bitset<8> bits("10110010");

//     // 输出bitset的值
//     std::cout << "The value of bits is: " << bits << std::endl;

//     // 访问和修改位
//     std::cout << "The value of the 3rd bit is: " << bits[2] << std::endl; // 输出0
//     bits[2] = 1;// 设置第3位为1
//     std::cout << "The value of bits after setting the 3rd bit is: " << bits << std::endl;
// }

// int main(){
//     bitset<8> bin("00001000");
//     cout << "initialize the bitset : " << bin << endl;

//     cout << "visit specially in 3 position : " << bin[3] << endl;

//     bin[3] = 0;
//     cout << "change 3 position : " << bin << endl;

//     bin.flip();
//     cout << "flip the bitset : " << bin << endl;
// }

// functional
// int add(int a,int b){
//     return a + b;
// }
// int main(){
//     auto add10 = bind(add, 10, placeholders::_1);
//     cout << add10(5) << endl;
// }

// bool compare(int a,int b){
//     return a > b;
// }

// int main(){
//     vector<int> vec = {43, 3, 7, 45, 8, 2, 8};
//     sort(vec.begin(), vec.end(), compare);
//     for (int x : vec)
//         cout << x << " ";

//     cout << endl;
//     sort(vec.begin(), vec.end(), less<int>());
//     for (int x : vec)
//         cout << x << " ";
// }

// accumulate
// int main(){
//     vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
//     int sum = accumulate(vec.begin(), vec.end(), 0);
//     cout << "Sum = " << sum << endl;
// }

// inner_product
// struct CustomAdd{
//     template<typename T>
//     T operator()(const T& a,const T& b)const{
//         return a + b;
//     }
// };
// struct CustomMultiply{
//     template<typename T>
//     T operator()(const T& a,const T& b)const{
//         return a * b;
//     }
// };

// int main(){
//     vector<int> vec1 {1, 2, 3, 4};
//     vector<int> vec2 {4, 3, 2, 1};

//     int mult_then_add = inner_product(vec1.begin(), vec1.end(), vec2.begin(), 0, CustomMultiply(), CustomAdd());
//     int add_then_mult = inner_product(vec1.begin(), vec1.end(), vec2.begin(), 0, CustomAdd(), CustomMultiply());
//     cout << "mult then add = " << mult_then_add << endl;
//     cout << "add then mult = " << add_then_mult << endl;
// }

// partial_sum
// int main(){
//     vector<int> vec1 = {1, 2, 3, 4, 5};
//     // vector<int> vec2;创建一个空的vector没有预留空间，begin迭代器指向未知
//     vector<int> vec2(vec1.size()); // 预留大小

//     partial_sum(vec1.begin(), vec1.end(), vec2.begin());
//     for(int x : vec2)
//         cout << x << "\t";
//     return 0;
// }

//string
// int main(){
//     string greeting = "Hello world";
//     string key_word = "world";
//     string::size_type postion = greeting.find(key_word);
//     int size = key_word.size();

//     if(postion != string::npos){
//         greeting.replace(postion, size, "C++");
//     }
//     cout << greeting << endl;
//     cout << "after replace size = " << greeting.size() << endl;
// }

// int main(){
//     string text = "123-456-7890 and 987-654-3210";
//     regex pattern("\\d{3}-\\d{3}-\\d{4}");
//     smatch matches;
//     while(regex_search(text,matches,pattern)){
//         cout << matches[0] << endl;
//         text = matches.suffix().str();
//     }
// }

// chrono
// void some_function(){
//     this_thread::sleep_for(chrono::seconds(3));
// }
// int main(){
//     auto start_time = chrono::high_resolution_clock::now();
//     some_function();
//     auto end_time = chrono::high_resolution_clock::now();
//     auto duration = chrono::duration_cast<chrono::seconds>(end_time - start_time);
//     cout << "the some_function has taken " << duration.count() << "seconds to execute" << endl;
// }

// int main(){
//     auto now = chrono::system_clock::now();                 // 用chrono得到时间
//     time_t now_c = chrono::system_clock::to_time_t(now);    // 转换为time_t风格(1970开始的）的时间格式
//     cout << "current time is : " << ctime(&now_c);          // 转换为ctime格式，可以使用strtime格式化
// }
// int main(){
//     future<int> result = std::async(
//         launch::async, [](){ 
//             this_thread::sleep_for(chrono::seconds(3)); 
//             return 0; 
//     });
//     int value = result.get();
//     cout << "result = " << value << endl;
// }

// mutex mtx;
// 生产者消费者问题
// condition_variable cv;
// queue<int> product;

// void producer(int id){
//     for (int i; i < 5 ; ++i){
//         unique_lock<mutex> lock(mtx);
//         product.push(id * 100 + i);
//         int product_one = product.back();
//         cout << "producer id : " << id << "produced ： " << product_one << endl;
//     cv.notify_one();
//     lock.unlock();
//     }
// }

// void consumer(int id){
//     unique_lock<mutex> lock(mtx);
//     cv.wait(lock, []{ return !product.empty(); });
//     int consume_one = product.front();
//     while(true){
//         if(!product.empty()){
//             cout << "consumer id ： " << id << "consumed : " << consume_one << endl;
//             product.pop();
//         }
//     }
//     lock.unlock();
// }

// int main(){
//     thread producer[2];
//     thread consumer[2];

//     for (int i = 0; i < 2; i++){
//         producer[i] = thread(producer, i + 1);
//     }
//     for (int i = 0; i < 2; i++){
//         consumer[i] = thread(producer, i + 1);
//     }
// }
//////////////outdata code////////////////
// 传统写法 定义一个Person类型的Person_object对象变量
// struct Person{
//     char name[64];
//     int age;
// };
// typedef struct Person person_object;

// typedef写法
// typedef struct Person{
//     char name[64];
//     int age;
// } person_object;

// // typedef区分数据类型
// void test(){
//     char *p1, p2;
//     cout << "the type of p1 :" << typeid(p1).name() << "\nthe type of p2 :" << typeid(p2).name() << endl;

//     typedef char *pchar;
//     pchar p3, p4;
//     cout << "the type of p3 :" << typeid(p3).name() << "\nthe type of p4 :" << typeid(p4).name() << endl;
// }

// // 提高代码可移植性
// typedef long long My_data_struct;

// My_data_struct var1;
// My_data_struct var2;
// My_data_struct var3;
// My_data_struct var4;
// My_data_struct var5;

// void test(){
//     void *p = NULL;
//     int *intp = NULL;
//     double *doublep = NULL;
//     cout << " the size of p pointer is : " << sizeof(p) << endl;
//     cout << " the size of intp pointer is : " << sizeof(intp) << endl;
//     cout << " the size of doublep pointer is : " << sizeof(doublep) << endl;
//     intp = (int *)doublep;
//     p = intp;
//     // intp = p; // 这一行会报错
// }

// void 的作用
// struct my_struct {
//     int a;      // 0~3
//     char b;     // 4~7(内存对齐)
//     int c;      // 8~11
//     char d;     // 12~15(内存对齐)
// };// 整个结构体占用内存大小为 16

// void test01(){

//     struct my_struct asset = {1, 'a', 2, 'b'};// 创建asset结构体
//     struct my_struct *p = &asset;       // 创建指向my_struct数据类型的指针p

//     // 十进制重载
//     printf("p : %d", p);
//     printf("\np+1 : %d", p+1);

//     // 十六进制重载
//     cout << "\np : " << p << endl;
//     cout << "p+1 : " << p+1 << endl;

//     char *p2 = &asset;       // 创建指向char类型的指针
//     printf("p2 : %d", p2);
//     printf("\np2+1 : %d", *(p2+1));
//     printf("\np2+1 : %d", *(int *)(p2+12));
// }

// void allocateSpace(char ** pp){
//     size_t content = 100;
//     char *temp = (char * )malloc(content);
//     memset(temp, 0, 100);
//     strcpy(temp, "hello world");
//     *pp = temp;
// }

// const全局变量和const局部变量
// void test03(){
//     char * p = NULL;
//     allocateSpace(&p);
//     printf("p : %s", p);
// }
// const int a = 10;

// void test(){
//     int *p = &a;
//     *p = 30;
// }

// void test(){
//     const int a = 10;
//     a = 20;
//     int *p = &a;
//     *p = 30;
// }

// 字符串常量
// void test(){
//     char *p1 = "hello";
//     char *p2 = "hello";
//     char *p3 = "hello";

//     printf("%d \n", p1);
//     printf("%d \n", p2);
//     printf("%d \n", p3);

//     p1[0] = 'w';
//     printf("%d \n", p1); // could be compile but cannot run in C
// }

// 函数调用流程

// 普通函数调用流程
// int func(int a ,int b){
//     int t_a = a;
//     int t_b = b;
//     return t_a + t_b;
// }

// int main(){
//     int result;
//     result = func(1, 2);
//     return EXIT_SUCCESS;
// }

// // 宏函数调用流程
// #define add(x, y) x + y
// int main(){
//     add(1, 2);
// }

// 栈的生长方向和内存存储方式
// void test(){
//     int a = 0;
//     int b = 0;
//     int c = 0;
//     int hex = 0x11223344;// 16进制，每个数字16位，两个数字一个字节

//     printf("a : %d\n", &a);
//     printf("b : %d\n", &b);
//     printf("c : %d\n", &c);

//     char *p = (char *)&hex;
//     printf("hex : %x\n", &hex);// hex变量所占用空间的的第一个内存地址
//     printf("hex : %x\n", *p);
//     printf("hex : %x\n", *(p + 1));// 跳转下一个字节
//     printf("hex : %x\n", *(p + 2));// 跳转下一个字节
//     printf("hex : %x\n", *(p - 1));// 跳转上一个字节，hex右边没定义，报错
// }
// int main(){
//     test();
// }

// 空指针和野指针
// void void_pointer(){
//     char *p = NULL;
//     char *q = (char *)0x12345;
//     // strcpy(q, "1234");
//     // strcpy(p, "1234");
// }

// void wild_pointer(){
//     // situation 1 : uninitialized pointer
//     char *p1;
//     printf("%d\n", *p1);// cant find ident

//     // situation 2 : malloc then free pointer
//     int *p2 = (int *)(malloc(sizeof(int)));
//     *p2 = 100;
//     printf("%d\n", *p2);
//     free(p2);
//     printf("%d\n", *p2);
//     *p2 = 1000;

// }
// // situation 3 : exceed the scope
// int * exceed(){
//     int a = 10;
//     int *p = &a;
//     return p;
// }

// int main(){
//     int *pointer = exceed();
//     printf("pointer : %d \n", *pointer);
//     printf("pointer : %d \n", *pointer);
// }

// 指针步长练习
// struct Person{
//     char a;
//     int b;
//     char buffer[64];
//     int d;
// };
// void test01(){
//     struct Person p = {'a', 10, "hello world", 1000};
// }
// 指针间接赋值

// void indirect_pointer(int * p){
//     *p = 100;
// }
// int main(){
//     int a = 10;
//     indirect_pointer(&a);
//     printf("a : %d\n", a);
//     printf("a : %d\n", &a);
// }

// 输入输出特新
// void stack_memo(char * string_pointer){
//     strcpy(string_pointer, "hello world");
//     printf("content in buffer : %s", string_pointer);
// }

// void heap_memo(){
//     char *string_pointer = (char * )malloc(sizeof(char) * 64);
//     memset(string_pointer, 0, 64);
//     strcpy(string_pointer, "hello world");
//     printf("contend in string pointer : %s\n", string_pointer);

// }
// int main(){
//     char buffer[1024] = {0};
//     // in_and_out(&buffer[1024]);
//     heap_memo();
// }

// c prime plus test

// enum struct practice

// #include "header.h"
// enum class State
// {
//     Idle,
//     Running,
//     Paused,
//     Stopped,
// };
// class Machine{
//     private:
//         State currentState;

//     public:
//     Machine():currentState(State::Idle){}

//     // 开始操作
//     void start() {
//         if (currentState == State::Idle || currentState == State::Stopped) {
//             currentState = State::Running;
//             std::cout << "Machine started." << std::endl;
//         } else {
//             std::cout << "Machine is already running." << std::endl;
//         }
//     }

//     // 暂停操作
//     void pause() {
//         if (currentState == State::Running) {
//             currentState = State::Paused;
//             std::cout << "Machine paused." << std::endl;
//         } else {
//             std::cout << "Machine is not running." << std::endl;
//         }
//     }

//     // 继续操作
//     void resume() {
//         if (currentState == State::Paused) {
//             currentState = State::Running;
//             std::cout << "Machine resumed." << std::endl;
//         } else {
//             std::cout << "Machine is not paused." << std::endl;
//         }
//     }

//     // 停止操作
//     void stop() {
//         if (currentState == State::Running || currentState == State::Paused) {
//             currentState = State::Stopped;
//             std::cout << "Machine stopped." << std::endl;
//         } else {
//             std::cout << "Machine is already stopped." << std::endl;
//         }
//     }

//     State getCurrentState(){
//         return currentState;
//     }
// };

// int main(){
//     Machine machine;
//     machine.start();
//     machine.getCurrentState();
//     machine.pause();
//     machine.getCurrentState();
//     machine.resume();
//     machine.getCurrentState();
//     machine.stop();
//     machine.getCurrentState();

//     int a = 5;
//     State temporal;
//     temporal = State(3);

//     int *pt = (int *) 0xB800000;

//     int *pointer = new int[500];
//     pointer[0] = 30;
//     pointer[1] = 40;
//     pointer[2] = 50;
//     pointer[3] = 60;
//     for (int i = 0; i < 4; i++ ){
//         cout << pointer[i] << "\n";
//     }
//     delete[] pointer;
//     // delete pointer;
//     for (int i = 0; i < 4; i++ ){
//         cout << pointer[i] << "\n";
//     }
// }

///////////////最开始的learning.cpp////////////
// #include<iostream>
// // 全局变量
// int g_a = 10;
// int g_b = 10;

// // 全局常量
// const int c_g_a = 10;
// const int c_g_b = 10;

// int main() 
// {
// using namespace std;

//     // 局部变量
//     int a = 10;
//     int b = 10;

//     // 打印地址
//     cout << "局部变量a地址为： " << (int)&a << endl;
//     cout << "局部变量b地址为： " << (int)&b << endl;

//     cout << "全局变量g_a地址为： " << (int)&g_a << endl;
//     cout << "全局变量g_b地址为： " << (int)&g_b << endl;

//     // 静态变量
//     static int s_a = 10;
//     static int s_b = 10;

//     cout << "静态变量s_a地址为： " << (int)&s_a << endl;
//     cout << "静态变量s_b地址为： " << (int)&s_b << endl;

//     cout << "字符串常量地址为： " << (int)&"hello world" << endl;
//     cout << "字符串常量地址为： " << (int)&"hello world1" << endl;

//     cout << "全局常量c_g_a地址为： " << (int)&c_g_a << endl;
//     cout << "全局常量c_g_b地址为： " << (int)&c_g_b << endl;

//     const int c_l_a = 10;
//     const int c_l_b = 10;
//     cout << "局部常量c_l_a地址为： " << (int)&c_l_a << endl;
//     cout << "局部常量c_l_b地址为： " << (int)&c_l_b << endl;

//     std::system("pause");

//     return 0;
// }

//不要返回局部变量的地址

// #include<iostream>
// using namespace std;
// int* func(){
//     int * p = new int(10);//new int(10) returns an address, p receipt it 
//     return p;
// }
// int main(){
//     int *p = func();//as same ,p is a pointer as func() def
//     cout << *p << endl;
//     cout << *p << endl;
//     cout << *p << endl;
//     cout << *p << endl;//p->address will never be disposed
//     return 0;
// }

//在堆区创建并使用数组
// #include <iostream>
// using namespace std;
// void swap1(int a, int b){
//     // swap but value submission,only change the duplicate of a & b
//     int temp;
//     temp = a;
//     a = b;
//     b = temp;
// }
// void swap2(int &a,int &b){
//     //use quote to arithmetize,directly manipulate memory addr
//     int temp;
//     temp = a;
//     a = b;
//     b = temp;
// }
// void swap3(int *a,int *b){
//     // use duplicate address to arithmetize it's work
//     int temp;
//     temp = *a;
//     //a is a pvar ,storage the addr info of a's value,temp is not a pvar so temp = int content obtained by unquote pointer
//     *a = *b;
//     *b = temp;
// }
// int main(){

//     int a = 10;
//     int b = 20;

//     swap1(a, b);//send the duplicate
//     cout << "a:" << a << " b:" << b << endl;

//     swap2(a, b);//send the quote by &
//     cout << "a:" << a << " b:" << b << endl;

//     swap3(&a, &b);//send the duplicate of addr
//     cout << "a:" << a << " b:" << b << endl;
//     return 0;
// }

//常量引用
// #include <iostream>
// using namespace std;
// void show_value(int &input){//无论&input还是input加const后都不支持修改
//     input = 100;//形参，参数列表中的数据
//     cout << "show value :" << input << endl;
// }
// void show_value2(const int input){
//     //input = 100;使用const表述传入的参数不可在const作用域中修改。这行会报错
//     cout << "show value :" << input << endl;
// }
// int main(){
//     int a = 1000;//a是实参，原数据
//     show_value(a);//没有使用引用传入参数，a传入show_value后变为input被修改
//     show_value2(a);//传入的a不可被修改，显示1000
//     cout << "main show value :" << a << endl;
// }

//长方体类创建
// #include <iostream>
// using namespace std;
// class cube{
//     public:
//         void set_attitudes(){
//             cout << "input length, width, high in sequence :";
//             cin >> length >> width >> high;
//         }
//         float show_volume(){
//             return length*width*high;
//         }//private中的内容可以在
//         float show_surface(){
//             return (length * high + length * width + high * width) * 2;
//         }
//     private :
//         float length, width, high;
// };
// int main(){
//     cube a, b;
//     // a.high;//不可被类的实例直接访问
//     a.set_attitudes();//公共可以被任何代码访问
//     cout << "the surface = "<< a.show_surface()<<endl;//private被类的成员函数访问
//     cout << "the volume = "<< a.show_volume()<<endl;
// }

//自定义析构函数防止深浅拷贝的问题
// #include <iostream>
// using namespace std;
// class Person
// {
// public:
//     // 无参（默认）构造函数
//     Person()
//     {
//         cout << "无参构造函数!" << endl;
//     }
//     // 有参构造函数
//     Person(int age, int height)
//     {
//         cout << "有参构造函数!" << endl;
//         m_age = age;
//         m_height = new int(height);
//     }
//     // 如果不自定义析构函数，编译器自动添加空析构函数，自动添加的析构函数只能完成浅拷贝
//     //---- -- -- -- -- -- -- -- -- -- -- -- -- --
//     Person(const Person &p)
//     {
//         cout << "拷贝构造函数!" << endl;
//         // 如果不利用深拷贝在堆区创建新内存，会导致浅拷贝带来的重复释放堆区问题
//         m_age = p.m_age;
//         m_height = p.m_height;
//         //---- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -
//         // 虚线内是编译器自动添加的析构函数中的内容
//         m_height = new int(*p.m_height); // 自定义析构函数，在堆区创建新的对象，申请新的内存，防止浅拷贝
//     }

//     // 析构函数
//     ~Person()
//     {
//         cout << "析构函数!" << endl;
//         if (m_height != NULL)
//         {
//             delete m_height;
//             m_height = NULL; // 放置野指针出现
//         }
//     }

// public:
//     int m_age;
//     int *m_height;
// };

// void test01()
// {
//     Person p1(18, 180);
//     Person p2(p1);
//     cout << "p1的年龄： " << p1.m_age << " 身高： " << *p1.m_height << endl;
//     cout << "p2的年龄： " << p2.m_age << " 身高： " << *p2.m_height << endl;
// }
// int main()
// {
//     test01();
//     system("pause");
//     return 0;
// }


//静态非静态成员
// class Person
// {
//     // 非静态成员变量占对象空间,属于类的对象上，所有的综合起来和类分配同一块空间
//     int a = 0;
//     int b = 1;
//     // 静态成员变量不占对象空间
//     static int mB;
//     // 函数也不占对象空间，所有函数共享一个函数实例
//     void func()
//     {
//         cout << "a:" << this->a << endl;
//     }
//     // 静态成员函数也不占对象空间
//     static void sfunc()
//     {
//     }
// };
// int main()
// {
//     Person p;
//     cout << "the size = " << sizeof(p) << endl;
//     // 两个非静态成员变量占用4*2 = 8字节
//     return 0;
// }

//this指针概念

// #include<iostream>
// using namespace std;
// class cuboid{
//     private:
//         double length, width, high;
//     public:
//         cuboid& set_cuboid(){
//             cout << "input the index of cuboid :";
//             cin >> this->length >> this->width >> this->high;//加this表示设置的长宽高只允许当前的 长方体对象有
//             return *this;//返回当前的长方体
//         }
//         cuboid& show_volume(){
//             cout << "the volume = " << this->length * this->high * this->width << endl;
//             return *this;
//         }
//         cuboid& make_it_double(){
//             this->high += this->high;
//             this->width += this->width;
//             this->length += this->length;
//             return *this;
//         }
// };
// int main(){
//     cuboid a;
//     a.set_cuboid()        // 创建一个初始长方体
//         .show_volume()    // 初始长方体体积
//         .make_it_double() // 双倍各种属性
//         .show_volume()
//         .make_it_double()
//         .make_it_double()
//         .make_it_double() // 16倍属性
//         .show_volume();
//     return 0;
// }

// class Person
// {
// public:
//     Person(){
//         m_A = 0;
//         m_B = 0;
//     }
//     void ShowPerson() const
//     {
//         this->m_B = 100;
//     }
//     int m_A;
//     int m_B;
// };

//友元函数


// class Building
// {
// public:
//     // constructor
//     Building()
//     {
//         this->m_lobby = "public lobby room";
//         this->m_chamber = "private place";
//     }
//     string m_lobby;

// private:
//     string m_chamber;
//     friend void goodgay(Building *build);
// };
// void goodgay(Building *build)
// {
//     cout << "goodgay is visit public place " << build->m_lobby;
//     cout << "goodgay is visit public place " << build->m_chamber;
// }
// int main()
// {
//     Building build;
//     goodgay(&build);
// }

// #include <iostream>
// #include <string>
// // 本例中所有函数外部定义，内部声明或调用
// using namespace std;
// class Building;//declare before goodgay
// class goodgay
// {
// public:
//     goodgay();
//     void visit();

// private:
//     Building *building;//这里和下面不同，创建的是Building指针
// };
// class Building
// {
//     friend class goodgay; // 使其能够访问goodgay中private内容
// public:
//     Building();
//     string m_public_room;

// private:
//     string m_private_room;
// };

// // 外部定义需要指明作用域
// Building::Building()
// { // 初始化Building有什么房间(使用构造函数)
//     string m_private_room = "bedroom";
//     string m_public_room = "lobby";
// }
// goodgay::goodgay()
// { // 初始化内容属性
//     building = new Building;//创建一个Building对象放在堆中
// }

// void goodgay::visit()
// {
//     std::cout << "you friend is visiting " << building->m_private_room << endl; // if you haven't marked goodgay to a friend this line while raise an error
//     std::cout << "your friend is visiting " << building->m_public_room << endl;
// }
// int main(){
//     Building b;
//     goodgay g;
//     return 0;
// }


// #include<iostream>
// #include<string>
// using namespace std;
// class Building;
// class goodgay{
//     public:
//         goodgay();
//         void visit(); // make visit func visit members belong Building
//         void visit2(); //and visit2 cannot
//     private:
//         Building *building;
// };

// class Building{
//     public:
//         string m_sitting_room;
//         building();

//     private :
//         string m_bedroom;
// };

// Building::building(){

// }


// int main(){
//     return 0;
// }
// #include<iostream>
// #include<string>
// using namespace std;
// ostream& operator<<(ostream& cout,Person& p){
//     cout << "a:" << p.m_A << "b:" << p.m_B;
//     return cout;
// }
// class Person{
//     friend ostream &operator<<(ostream &cout, Person &p);
// public:
//     Person(int a, int b){
//         this->m_A = a;
//         this->m_B = b;
//     }
// private:
//     int m_A;
//     int m_B;
// };

// int main(){

// }

// #include<iostream>
// using namespace std;
// class Base 
// {
// public:
// 	Base()
// 	{
// 		cout << "Base构造函数!" << endl;
// 	}
// 	~Base()
// 	{
// 		cout << "Base析构函数!" << endl;
// 	}
// };

// class Son : public Base
// {
// public:
// 	Son()
// 	{
// 		cout << "Son构造函数!" << endl;
// 	}
// 	~Son()
// 	{
// 		cout << "Son析构函数!" << endl;
// 	}

// };


// void test01()
// {
// 	//继承中 先调用父类构造函数，再调用子类构造函数，析构顺序与构造相反
// 	Son s;
// }

// int main() {

// 	test01();

// 	system("pause");

// 	return 0;
// }

// 多态
// #include <iostream>
// using namespace std;
// class animal{
// 	public:
// 	void virtual speak(){
// 		cout << "there is an animal is speaking " << endl;
// 	}
// };

// class dog:public animal{
// 	public:
// 	void speak(){
// 		cout << "dog barking" << endl;
// 	}
// };
// class cat:public animal{
// 	public:
// 	void speak(){
// 		cout << "cat barking" << endl;
// 	}
// };

// void animal_speak(animal & ani){
// 	ani.speak();
// }

// int main(){
// 	dog d;
// 	cat c;
// 	animal_speak(d);
// 	animal_speak(c);
// }

// 多态计算器普通写法和多态写法
//普通方法
// #include <iostream>
// using namespace std;

// class calculator{
// 	public:
// 		calculator(int x, int y) : a(x), b(y), result(0) {};
// 		int multiply(){
// 			return result = a * b;
// 		}
// 		int add(){
// 			return result =  a + b;
// 		}
// 		int subtract(){
// 			return result =  a - b;
// 		}
// 		double division() { 
// 			if (b != 0) {
// 				return result = static_cast<double>(a) / b; 
// 			} else {
// 				cerr << "Error: Division by zero!" << endl;
// 				return 0; 
// 			}
// 		}
// 	private:
// 		int a;
// 		int b;
// 		double result;
// };

// int main(){
// 	calculator c(5,7);
//     cout << "Addition: " << c.add() << endl;
//     cout << "Subtraction: " << c.subtract() << endl;
//     cout << "Multiplication: " << c.multiply() << endl;
//     cout << "Division: " << c.division() << endl;
// }

//虚函数和纯虚函数
// #include <iostream>
// using namespace std;

// class base{
// 	public :
// 		virtual void pure_virtual_func() = 0;
// 		virtual void virtual_func(){
// 			cout << "it is virtual_func() works !" << endl;
// 		}
// 		virtual void const_virtual_func()const{
// 			cout << "this message will override by subclasses " << endl;
// 		}
// 		virtual ~base() {};// make sure subclasses destruct correctly
// };

// class higher:public base{
// 	public:
// 	void pure_virtual_func(){
// 		cout << "pure virtual funcs must be realize in subclasses " << endl;
// 	}
// 	virtual void const_virtual_func()const override{
// 		cout << "override the base method ." << endl;
// 	}
// 	~higher(){
// 		cout << "destruct correctly .";
// 	}
// };

// int main(){
// 	higher h;
// 	h.const_virtual_func();
// 	h.pure_virtual_func();
// 	h.virtual_func();
// 	h.~higher();
// }

// int main(){
//     // short short_array[10];
//     // cout << short_array << endl;
//     // cout << &short_array << endl;
//     // cout << short_array + 1 << endl;
//     // cout << &short_array + 1 << endl;

//     // char flower[10]{"sunflower"};
//     // cout << flower << "\tsunflower";
//     // char * char_pointer = new char[5];
//     // strcpy(char_pointer, "hello world");
//     // cout << char_pointer << endl;
//     // cout << char_pointer + 1 << endl;

//     char short_sentence[5];
//     // strcpy(short_sentence, "hello world");      // 数组溢出，报错
//     // strncpy(short_sentence, "hello world",4);   // only copy hell\0
//     strncpy(short_sentence, "hello world",5);   // copy hello
//     cout << short_sentence << endl;
//     cout << *(&short_sentence + 1) << endl;     // visit the overflow part memo
// }

// char *getname(void);
// int main(){
//     vector<int> v1 = {1, 2, 3, 4, 6};
//     vector<int> v2 = v1;
// }
// char * getname(void){
//     char name[20];
//     cout << "Enter your name : ";
//     cin >> name;
//     char *pointer = new char[strlen(name) + 1];
//     strcpy(pointer, name);
//     return pointer;
// }

// chapter 4 practice 第四章编程作业

// void int_array(void){
//     int contend;
//     cin >> contend;
//     int *array = new int[contend];
//     cout << "the int array size : " << sizeof(array); // wrong, return the pointer size, 8 in 64 bit OS
//     cout << "\nthe int array size : " << sizeof(*array); // wrong. return the 1st element in array's address, int -> 4
//     cout << "\nthe int array size : " << sizeof(*array) * contend;
// }
// int main(){
    // char actor[30];
    // short betsie[100];
    // float chuck[13];
    // long double dipsea[64];
    // array<char, 30>(actor);
    // array<short, 100>(betsie);
    // array<float, 13>(chuck);
    // array<long double, 64>(dipsea);
    // array<int,5>(m_list) = {1};
    // // int even = m_list.begin() + m_list.end();
    // int even = m_list[0] + m_list[4];
    // enum class Response
    // {
    //     No = 0,
    //     Yes = 1,
    //     Maybe = 2
    // };
//     int_array();
// } 

// simple status machine
// enum class status{
//     running,
//     idle,
//     stopped
// };
// class machine{
//     private:
//         status currentState;
//     public:
//         machine(/* args */) : currentState(status::idle) {};
//         ~machine();
//         void startRun(void){
//             currentState = status::running;
//             cout << "machine is running . " << endl;
//         }
//         void stop(void){
//             currentState = status::stopped;
//             cout << "machine is stopped . " << endl;
//         }
// };

// struct small_fish{
//     int weight = 10;
//     string variety = "golden fish";
// };


// int main(){
//     cout << (int *)"hello world.";
//     small_fish *fish_pointer = new small_fish;
//     cout << fish_pointer->variety << endl;
//     cout << fish_pointer->weight << endl;
// }

// class pizza{
//     private:
//         string company_name;
//         float diameter;
//         float weight;
//     public:
//         pizza(){
//             getline(cin, company_name);
//             cin >> diameter;
//             cin >> weight;
//             cout << "company : " << company_name << "\tdiameter : " << diameter << "\tweight : " << weight << endl;
//         }
// };
// int main(){
//     pizza *pizza_pointer = new pizza;
//     delete pizza_pointer;
//     pizza_pointer = nullptr;
// }

// int main (){
//     int array[8]{1, 1, 1, 1, 0, 1, 1, 1};
//     for (int i = 0; array[i] != 0; i++)    {
//         cout << array[i] << endl;
//     }
//     // for (int i = 0; array[i] = 1; i++)    {
//     //     cout << array[i] << endl;
//     // }
// }

// int main(){
//     char ch;
    // int count = 0;
    // cout << "Enter characters, then input # to quit : ";
    // cin >> ch;
    // while(ch != '#'){
    //     cout << ch;
    //     ++count;
    //     cin >> ch;
    // }
    // cout << endl
    //      << count << " characters read \n";
    // ch = cin.get();
    // cout << ch << endl;
//     return 0;
// }

//chapter 5 practice

// void input_2_numbers(){
//     int first, second, result = 0;
//     cin >> first >> second;
//     for (int i = first; i <= second; i ++){
//         result += i;
//     }
//     cout << "the result : " << result << endl;
// }

// void refactoring_program_5_4(){
//     const int artSize = 100;
//     long double factorials[artSize];
//     factorials[0] = factorials[1] = 1;
//     for (int i = 2; i <= artSize; i++){
//         factorials[i] = factorials[i - 1] * i;
//     }
//     for (int k = 0; k < artSize;k++){
//         cout << k << "! =" << ios::fixed << factorials[k] << endl;
//     }
// }

// void ask_for_input(){
//     int input;
//     int sum = 0;
//     while(true){
//         char flowing_input= ' ';
//         cin >> input;
//         if (cin.fail()){
//             flowing_input = cin.get();
//             cin.clear();
//             cin.ignore(numeric_limits<streamsize>::max(), '\n');
//             if (flowing_input == 'q'){
//                 break;
//             }
//             cerr << "invalid input !" << endl;
//         }else{
//             sum += input;
//             cout << sum << endl;
//         }
//     }
// }
// void get_words(){
//     char input_word[]{};
//     int word_count = 0;
//     while(true){
//         cin >> input_word;
//         if (strcmp(input_word, "done") == 0){
//             cout << "you have inputted : " << word_count << endl;
//             break;
//         }
//         word_count++;
//     }  
// }


// void get_word_string_version(){
//     string input_word;
//     int word_count = 0;
//     while(true){
//         cin >> input_word;
//         if (input_word == "done"){
//             cout << "you have inputted : " << word_count << endl;
//             break;
//         }
//         word_count++;
//     }
// }

// void display_the_asterisk(){
//     int count;
//     cin >> count;
//     for (int row = 4; row > 0; row --){
//         for (int col = 0; col < row; col ++){
//             cout << ".";
//         }
//         for (int col = 0; col < 5 - row;col++)
//             cout << "*";
//         cout << endl;
//     }
// }
// void ask_for_input(){
//     int sum = 0;
//     std::string input;
//     while(true){
//         std::cin >> input;
//         if(input == "q"){
//             break;
//         }
//         try {
//             int num = std::stoi(input);
//             sum += num;
//             std::cout << sum << std::endl;
//         } catch (const std::invalid_argument& e) {
//             std::cout << "Please enter a valid number or 'q' to quit." << std::endl;
//         }
//     }
// }
// int main(){
//     input_2_numbers();
//     refactoring_program_5_4();
//     ask_for_input();
//     get_words();
//     get_word_string_version();
//     display_the_asterisk();
// }

// int main(){
//     char ch;
//     cout << "input : \n";
//     cin.get(ch);
//     while (ch!= '.'){
//         if(ch=='\n')
//             cout << ch;
//         else
//             cout << ch+1 << "\t";
//         cin.get(ch);
//     }
//     cout << "\n plz excuse the slight confusion .";
// }


// program 6.13
// void get_data(){
//     const int max_amount = 5;
//     double total = 0;
//     double avg = 0;
//     array<double, max_amount> weight{0};
//     for (int i = 0; i < max_amount; i++){
//         cout << "input the weight of "<< i << " fish you got : ";
//         while(!(cin >> weight[i])){
//             cout << "Invalid input. Please enter a number." << endl;
//             cin.clear(); // 清除错误标志
//             cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 忽略剩余的输入
//         }
//         total += weight[i];
//     }
//     avg = total / max_amount;
//     if (total == 0)
//         cout << "you ve got no fish ";
//     else
//         cout << "total : " << total << "\tavg : " << avg;
// }

// //二进制写入数据到文件中
// ///////////advance usage of ifstream/ofstream//////////////////////
// struct Record {
//     int id;
//     string name;
//     double value;
// };


// bool writeRecordsToFile(const string& filename, const vector<Record>& records) {
//     ofstream file(filename, ios::out | ios::binary);
//     if (!file) {
//         return false;
//     }
//     for (const auto& iteration_record : records) {
//         file.write(reinterpret_cast<const char*>(&iteration_record.id), sizeof(iteration_record.id));
//         // Write the length of the name
//         size_t nameLength = iteration_record.name.size();
//         file.write(reinterpret_cast<const char*>(&nameLength), sizeof(nameLength));
//         // Write the name characters
//         file.write(iteration_record.name.data(), nameLength);
//         file.write(reinterpret_cast<const char*>(&iteration_record.value), sizeof(iteration_record.value));
//     }
//     file.close();
//     return true;
// }

// bool readRecordsFromFile(const string& filename, vector<Record>& records) {
//     ifstream file(filename, ios::in | ios::binary);
//     if (!file) {
//         return false;
//     }
//     Record record;
//     while (file.read(reinterpret_cast<char*>(&record.id), sizeof(record.id))) {
//         // Read the length of the name
//         size_t nameLength;
//         file.read(reinterpret_cast<char*>(&nameLength), sizeof(nameLength));
//         record.name.resize(nameLength);
//         // Read the name characters
//         file.read(&record.name[0], nameLength);
//         file.read(reinterpret_cast<char*>(&record.value), sizeof(record.value));
//         records.push_back(record);
//     }
//     file.close();
//     return true;
// }

// int main() {
//     vector<Record> records = {
//         {1, "Alice", 23.5},
//         {2, "Bob", 45.6},
//         {3, "Charlie", 67.7}
//     };

//     if (writeRecordsToFile("records.dat", records)) {
//         cout << "Records written to file successfully." << endl;
//     } else {
//         cout << "Failed to write records to file." << endl;
//     }

//     vector<Record> loadedRecords;
//     if (readRecordsFromFile("records.dat", loadedRecords)) {
//         cout << "Records read from file successfully." << endl;
//         for (const auto& iteration_record : loadedRecords) {
//             cout << "ID: " << iteration_record.id << "\tName: " << iteration_record.name << "\tValue: " << iteration_record.value << endl;
//         }
//     } else {
//         cout << "Failed to read records from file." << endl;
//     }

//     return 0;
// }

// struct Record{
//     int id;
//     string name;
//     double value;
// };
// 二进制读写文件
// bool write_to_file(const string &filename,vector<Record> w_record){
//     ofstream file(filename, ios::out | ios::binary);
//     if(!file)
//         return false;
//     for(const auto & single_record : w_record){
//         file.write(reinterpret_cast<const char *>(&single_record.id), sizeof(single_record.id));
//         size_t name_length = single_record.name.size();
//         file.write(reinterpret_cast<const char *>(&name_length), name_length);
//         file.write(single_record.name.data(), name_length);
//         file.write(reinterpret_cast<const char *>(&single_record.value), sizeof(single_record.value));
//     }
//     return true;
// }
// bool read_from_file(const string &filename, vector<Record> r_record){
//     ifstream file(filename, ios::out | ios::binary);
//     if (!file)
//         return false;
//     Record single_record;
//     while(file.read(reinterpret_cast<char *>(&single_record.id),sizeof(single_record.id))){
//         size_t namelength;
//         file.read(reinterpret_cast<char *>(&namelength), sizeof(namelength));
//         single_record.name.resize(namelength);
//         file.read(&single_record.name[0], sizeof(namelength));
//         file.read(reinterpret_cast<char *>(&single_record.value), sizeof(single_record.value));
//         r_record.push_back(single_record);
//     }
//     file.close();
//     return true;
// }

// int main(){
//     vector<Record> specific_data{
//         {1, "Alice", 23.5},
//         {2, "Bob", 45.6},
//         {3, "Charlie", 67.7}
//     };
//     if(write_to_file("record.dat",specific_data))
//         cout << "write to record.dat successfully !"<<endl;
//     else
//         cout << "fail to write .";

//     vector<Record> loaded_data;
//     if(read_from_file("record.dat",loaded_data))
//         cout << "read from record.dat successfully !"<<endl;
//     else
//         cout << "fail to read .";
//     for(const auto& iteration_record : loaded_data){
//         cout << "ID : " << iteration_record.id << "\tname : " << iteration_record.name << "\tvalue : " << iteration_record.value << endl;
//     }
// }


// chapter 6 practice
// void first(){
//     char ch;
//     while((ch = cin.get()) != '@'){
//         if(!isdigit(ch)){
//             if(isupper(ch)){
//                 ch = tolower(ch);
//             }else if(islower(ch)){
//                 ch = toupper(ch);
//             }
//         }
//         cout << ch ;
//     }
//     cout << "done";
// }

// void seventh(){
//     string input;
//     bool status = true;
//     while(status){
//         getline(cin, input);
//         if(input == "q"){
//             status = false;
//         }
//     }
// }

// int main(){
//     first();
// }

// int main() {
//     char ch;
//     std::cout << "请输入字符，输入@结束：" << std::endl;

//     // 循环读取字符直到遇到@符号
//     while ((ch = std::cin.get()) != '@') {
//         // 检查字符是否为数字
//         if (!isdigit(ch)) {
//             // 检查字符是否为大写字母
//             if (isupper(ch)) {
//                 // 将大写字母转换为小写字母
//                 ch = tolower(ch);
//             }
//             // 检查字符是否为小写字母
//             else if (islower(ch)) {
//                 // 将小写字母转换为大写字母
//                 ch = toupper(ch);
//             }
//             // 回显转换后的字符
//             std::cout << ch;
//         }
//     }

//     std::cout << std::endl << "输入结束。" << std::endl;
//     return 0;
// }
