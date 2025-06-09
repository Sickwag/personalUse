// PTA团体程序设计天梯赛-练习题
#include<bits/stdc++.h>

// L1-100 四项全能
// 2024年12月18日21:27:51
// int main(){
//     int sum, items, a, b, c, d, count = 0;
//     cin >> sum >> items;
//     cin.ignore();
//     cin >> a >> b >> c >> d;
//     vector<int> line(sum, 0);
//     for (int i = 0; i < a+b+c+d;i++){
//         line[i%sum] += 1;
//     }
//         for (int k = 0; k < sum; k++){
//             if (line[k] == items)
//                 count++;
//         }
//     cout << count;
// }
// L1-087 机工士姆斯塔迪奥
// 2024年12月18日21:07:23
// 2024年12月18日21:22:47
// int main(){
//     int m, n, q, y, count = 0;
//     bool x;
//     cin >> n >> m >> q;
//     vector<vector<bool>> matrix(n, vector<bool>(m, true));// matrix[n][m]
//     for (int i = 0; i < q;i++){
//         cin >> x >> y;
//         if(!x){// make a line to false
//             for (int j = 0; j < m;j++){
//                 matrix[y-1][j] = false;
//             }
//         }else{// make a column to false
//             for (int j = 0; j < n;j++){
//                 matrix[j][y-1] = false;
//             }
//         }
//     }
//     for (int x = 0; x < n;x++){
//         for (int y = 0; y < m;y++){
//             if(matrix[x][y])
//                 count++;
//         }
//     }
//     cout << count;
// }
// L1-075 强迫症
// 2024年12月18日21:03:05
// 十分钟
// int main(){
//     string input;
//     getline(cin, input);
//     if(input.length()==6){
//         cout << input.substr(0, 4) << "-" << input.substr(4, 2);
//     }else{
//         if(stoi(input.substr(0,2))<22){
//             cout << "20" << input.substr(0, 2) << "-" << input.substr(2, 2);
//         }else{
//             cout << "19" << input.substr(0, 2) << "-" << input.substr(2, 2);
//         }
//     }
// }
// L1-049 天    梯赛座位分配
// 2024年12月18日15:24:25
// 2024年12月18日15:41:48解不出来，知识不够

// L1-095 分寝室
// 2024年12月18日14:36:56
// 2024年12月18日15:24:06部分正确
// int main(){
//     int n0, n1, n,temp,min_difference = INT_MAX;
//     cin >> n0 >> n1 >> n;
//     if(n0 == 0){
//         for (int i = 2; i < n1 / n;i++){
//             if(n1%i==0){
//                 cout << "0 " << i ;
//                 return 0;
//             }
//         }
//     }
//     if(n1 == 0){
//         for (int i = 2; i < n0 / n;i++){
//             if(n0%i==0){
//                 cout << i << " 0" ;
//                 return 0;
//             }
//         }
//     }

//     for (int x = 2; x < n;x++){
//         if (n0 % x == 0&&n1%(n-x)==0){
//             if(min_difference>abs(n-x-x)){
//                 temp = x;
//                 min_difference = n - x - x;
//             }
//         }
//     }
//     if(min_difference == INT_MAX){
//         cout << "No Solution";
//     }else{
//         cout << temp <<" "<< n - temp;
//     }
// }
// L1-058 6翻了
// 2024年12月13日10:27:14
// 2024年12月13日10:52:51
// #include <iostream>
// #include <string>
// #include <regex>
// using namespace std;
// 使用多个正则表达式规则
// int main(){
//     string input;
//     getline(cin, input);
//     regex pattern1("6{4,9}");
//     regex pattern2("6{10,}");
//     string result = regex_replace(input, pattern2, "27");
//     result = regex_replace(result, pattern1, "9");
//     cout << result;
// }
// 使用一个正则表达式规则和分支条件判断语句
// int main(){
//     string input;
//     getline(cin, input);
//     regex pattern("6+");
//     string result = regex_replace(input, pattern, [](const smatch& match) -> string {
//         int len = match.str().length();
//         if (len >= 10) {
//             return "27";
//         } else if (len >= 4) {
//             return "9";
//         } else {
//             return match.str();
//         }
//     });
// }
// 正常实现需要很多if else和嵌套循环统计6的词数并
// 部分正确方法，因为默认两个单词之间只有一个空格
// int main(){
//     string input,temp,result;
//     getline(cin, input);
//     stringstream ss(input);
//     while(ss>>temp){
//         if (temp.length() > 3 && temp.length() <= 9 && temp[0] == '6'){
//             result += "9 ";
//         }else if(temp.length()>9&&temp[0]=='6'){
//                 result += "27 ";
//         }else{
//             result += temp + ' ';
//         }
//     }
//     if(result[result.length()-1]==' ')
//         result.erase(result.end()-1);
//     cout << result;
// }

// L1-042 日期格式化
// 2024年12月13日09:09:19
// 2024年12月13日09:12:53
// int main(){
//     string input;
//     cin >> input;
//     cout << input.substr(6, 4) <<"-"<< input.substr(0, 2) <<"-"<< input.substr(3, 2);
// }
// L1-041 寻找250
// 2024年12月13日08:37:44
// 2024年12月13日08:48:37
// int main(){
//     string input;
//     int count = 1;
//     while(cin >> input){
//         if(input !="250"){
//             count++;
//         }else{
//             break;
//         }
//     }
//     cout << count;
// }
// L1-040 最佳情侣身高差
// 2024年12月12日18:34:13
// float calc(string info){
//     string result;
//     float out = stof(info.substr(2));
//     if(info[0]=='F'){
//         return 1.09*out;
//     }else{
//         return out/1.09;
//     }
// }
// int main(){
//     int count = 0;
//     cin >> count;
//     cin.ignore();
//     string input;
//     vector<float> results;
//     for (int i = 0; i < count;i++){
//         getline(cin, input);
//         results.push_back(calc(input));
//     }
//     for(float x : results){
//         cout << fixed << setprecision(2) << x << endl;       
//     }
// }

// L1-039 古风排版
// 2024年12月12日18:33:19
// void init(){
//     string input_line;
//     int m, k = 0;
//     getline(cin, input_line);
//     int n = stoi(input_line);
//     string input;
//     getline(cin, input);
//     if(input.length()%n!=0){
//         m = input.length() / n + 1;
//     }else{
//         m = input.length() / n;
//     }
//     for (int i = 0; i < m - input.length() % m;i++){
//         input.push_back(' ');
//     }
//     vector<vector<char>> matrix(n,vector<char>(m));
//     for (int i = 0; i < m; i++){
//         for (int j = 0; j < n;j++){
//             matrix[j][i] = input[k++];
//         }
//     }
//     for (int l = 0; l < n;l++){
//         reverse(matrix[l].begin(), matrix[l].end());
//     }
//     for (int i = 0; i < n;i++){
//         for (int j = 0; j < m;j++){
//             cout << matrix[i][j];
//         }
//         cout << endl;
//     }
// }
// int main(){
//     init();
// }


// vector<int> init(string input =""){
//     cin >> input;
//     int gcount = 0, pcount = 0, lcount = 0, tcount = 0;
//     for (int i = 0; i < input.length();i++){
//         input[i] = tolower(input[i]);
//         switch (input[i]){
//         case 'g':
//             gcount++;
//             break;
//         case 'p':
//             pcount++;
//             break;
//         case 'l':
//             lcount++;
//             break;
//         case 't':
//             tcount++;
//             break;
//         default:
//             input.erase(input.begin() + i);
//             i--;
//             break;
//         }
//     }
//     return {gcount, pcount, lcount, tcount};
// }

// void show_results(vector<int> counts){
//     counts = init();
//     while (counts[0] > 0 || counts[1] > 0 || counts[2] > 0 || counts[3] > 0) {
//     for (int i = 0; i < 4; i++) {
//         if (counts[i] > 0) {
//             if (i == 0) cout << 'G';
//             else if (i == 1) cout << 'P';
//             else if (i == 2) cout << 'L';
//             else if (i == 3) cout << 'T';
//             counts[i]--;
//             }
//         }
//     }
// }
// int main(){
//     vector<int> vec(4, 0);
//     show_results(vec);
// }


// L1-002 打印沙漏
// 2024年12月7日17:03:06
// 2024年12月7日17:43:12
// int main(){
//     int input ;
//     char c ;
//     cin >> input >> c;
//     int remain = 0;
//     int layer = 0;
//     for (int i = 0;; i++)
//     {
//         int left = 2 * pow(i, 2) - 1;
//         int right = 2 * pow(i+1, 2) - 1;
//         if(left <= input && input < right){
//             remain = input - left;
//             layer = i;
//             break;
//         }
//     }
//     for (int i = layer; i > 0;i--){
//         for (int j = 0; j < layer - i; j++){
//             cout << " ";
//         }
//         for (int k = 0; k < 2 * i - 1;k++){
//             cout << c;
//         }
//         cout << endl;
//     }
//     for (int i = 2; i <= layer; i++){
//         for (int j = 0; j < layer - i;j++){
//             cout << " ";
//         }
//         for (int k = 0; k < 2 * i - 1;k++){
//             cout << c;
//         }
//         cout << endl;
//     }
//     cout << remain;
// }


// L1-003 个位数统计
// 2024年12月7日17:43:38
// 2024年12月7日17:59:17

// int main(){
//     string s;
//     cin >> s;
//     vector<int> count(10, 0);
//     for (int i = 0; i < s.length();i++){
//         switch (s[i])
//         {
//         case '0' :
//             count[0]++;
//             break;
//         case '1' :
//             count[1]++;
//             break;
//         case '2' :
//             count[2]++;
//             break;
//         case '3' :
//             count[3]++;
//             break;
//         case '4' :
//             count[4]++;
//             break;
//         case '5' :
//             count[5]++;
//             break;
//         case '6' :
//             count[6]++;
//             break;
//         case '7' :
//             count[7]++;
//             break;
//         case '8' :
//             count[8]++;
//             break;
//         case '9' :
//             count[9]++;
//             break;
//         default:
//             break;
//         }
//     }
//     for (int i = 0; i < 10;i++){
//         if(count[i]){
//             cout << i << ":" << count[i] << endl;
//         }
//     }
// }

// L1-004 计算摄氏温度
// 2024年12月7日18:00:41
// 2024年12月7日18:02:44
// int main(){
//     int f = 0;
//     cin >> f;
//     cout << "Celsius = " << 5 * (f - 32) / 9;
// }

// L1-005 考试座位号
// 2024年12月7日18:10:19
// 2024年12月7日18:33:56
// int main(){
//     int number;
//     string set_number;
//     int test_number;
//     int real;
//     cin >> number;
//     map<int, pair<string, int>> all_info;
//     for (int i = 0; i < number;i++){
//         cin >> set_number >> test_number >> real;
//         all_info[test_number] = make_pair(set_number, real);
//     }
//     int check_number;
//     cin >> check_number;
//     vector<int> check_list(check_number);

//     for (int j = 0; j < check_number;j++){
//         cin >> check_list[j];
//     }
//     for (int k = 0; k < check_number;k++){
//         cout << all_info.find(check_list[k])->second.first << " " <<all_info.find(check_list[k])->second.second;
//         cout << endl;
//     }
// }
// L1-007 念数字
// #include<bits/stdc++.h>
// int main(){
//     vector<pair<int, string>> info;
//     info[0] = make_pair(0, "ling");
//     info[1] = make_pair(1, "yi");
//     info[2] = make_pair(2, "er");
//     info[3] = make_pair(3, "san");
//     info[4] = make_pair(4, "si");
//     info[5] = make_pair(5, "wu");
//     info[6] = make_pair(6, "liu");
//     info[7] = make_pair(7, "qi");
//     info[8] = make_pair(8, "ba");
//     info[9] = make_pair(9, "jiu");
//     int input;
//     cin >> input;
//     if(input <0){
//         cout << "fu";
//     }
//     do{
//         switch (input % 10){
//         case 0:
//             cout << info[0].second;
//             break;
//         case 1:
//             cout << info[1].second;
//             break;
//         case 2:
//             cout << info[2].second;
//             break;
//         case 3:
//             cout << info[3].second;
//             break;
//         case 4:
//             cout << info[4].second;
//             break;
//         case 5:
//             cout << info[5].second;
//             break;
//         case 6:
//             cout << info[6].second;
//             break;
//         case 7:
//             cout << info[7].second;
//             break;
//         case 8:
//             cout << info[8].second;
//             break;
//         case 9:
//             cout << info[9].second;
//             break;
//         default:
//             break;
//         }
//         if(input){
//             cout << " ";
//         }
//     } while (input /= 10);
// }

// L1-009 N个数求和
// 2024年12月8日10:04:10
// 2024年12月8日11:18:55 --undone

// 暴力法求解最小公倍数
// int get_mcm(int a,int b){
//     while(1){
//         int m = max(a, b);//a,b中的较大值
//         while(1){
//             if(m % a == 0 && m % b == 0){
//                 return m;
//                 break;
//             }
//             m++;//从较大的数开始,一个数一个数往后判断
//         }
//     }
// }
// 最大公因数和最小公倍数配合求解
// int get_gcb(int a ,int b){
//     int c = 0;
//     while(c=a%b){
//         a = b;
//         b = c;
//     }
//     return b;
// }
// int get_mcm(int a ,int b){
//     return a * b / get_gcb(a, b);
// }
// void get_seg(string number){
//     string::iterator it = find(number.begin(), number.end(), "\\");
//     cout << it - number.begin();
// }

// int main(){
//     string s = "12/34";
//     get_seg(s);
// }


// L1-010 比较大小
// 2024年12月8日11:19:21
// 2024年12月8日11:25:36
// 偷懒方法
// void sort_3_numbers(){
//     int x, y, z;
//     cin >> x >> y >> z;
//     vector<int> numbers = {x, y, z};
//     sort(numbers.begin(), numbers.end());
//     cout << numbers[0] << "->" << numbers[1] << "->" << numbers[2];
// }
// int main(){
//     sort_3_numbers();
// }

// L1-011 A-B
// 2024年12月8日11:31:13
// 2024年12月8日12:13:41
// 部分正确方法
// int main(){
//     string input, compair, result;
//     getline(cin, input);
//     getline(cin, compair);
//     for (int i = 0; i < compair.length();i++){
//         for (int j = 0; j < input.length();j++){
//             if(compair[i]==input[j]){
//                 input.erase(input.begin()+j); //这里有个不容易看出来的错误，一旦匹配上，删除该位置（下标为index）的字符，该位置的下一个字符的填充上，下标变为index，下次循环从j++（也就是index+1）开始会导致漏掉一个。所以这个算法不能处理有连续的compair中的字符的字符
//             }
//         }
//     }
//     cout << input;
// }

// 使用unordered_set方法
// int main(){
//     string input, compair, result;
//     getline(cin, input);
//     getline(cin, compair);
//     unordered_set<char> charset(compair.begin(), compair.end());
//     for (int i = 0; i < input.length();){
//         if(charset.find(input[i])!=charset.end()){
//             input.erase(i, 1);
//         }else{
//             i++;
//         }
//     }
//     cout <<input;
//     return 0;
// }
// L1-012
// #include<iostream>
// using namespace std;
// int main(){
//     int i;
//     cin >> i;
//     int result=1;
//     for(int k =0;k<i;k++){
//         result*=2;
//     }
//     cout << 2<<"^"<<i<<" = "<< result;
// }

// L1-013 计算阶乘和
// 2024年12月8日14:44:57
// 2024年12月8日14:52:23
// int get_factorial(int n){
//     int temp = 1;
//     int sum = 0;
//     for (int i = 1; i <= n;i++){
//         temp *= i;
//         sum += temp;
//     }
//     return sum;
// }
// int main(){
//     int n;
//     cin >> n;
//     cout << get_factorial(n);
// }

// L1-015 跟奥巴马一起画方块
// 2024年12月8日14:54:27
// 2024年12月8日14:57:02
// int main(){
    // float side;
    // char c;
    // cin >> side >> c;
    // for (int i = 0; i < round(side/2);i++){
    //     for (int i = 0; i < side;i++){
    //         cout << c;
    //     }
    //     cout << "\n";
    // }
// }


// L1-016 查验身份证
// 2024年12月8日20:38:10
// 2024年12月9日09:53:19
// void init(unordered_map<int,char>& mapping,vector<int>& weight){
//     vector<int> z = {0,1,2,3,4,5,6,7,8,9,10};
//     vector<char> m = {'1','0','X','9','8','7','6','5','4','3','2'};
//     weight ={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
//     for (int i = 0; i < 10;i++){
//         mapping[z[i]] = m[i];
//     }
// }
// bool is_number(const string& s){
//     return !s.empty() && all_of(s.begin(), s.end(), ::isdigit);
// }
// bool get_check_num(string id,vector<int> weight,unordered_map<int,char> mapping){
//     if(id.length() != 18){
//         return false;
//     }
//     char the_last = id[17];
//     id.erase(id.end() - 1);
//     if(is_number(id)){
//         int result = 0;
//         for (int i = 0; i < id.length();i++){
//             result += weight[i] * (id[i]-'0');
//         }
//         auto it = mapping.find(result % 11);
//         if (it != mapping.end() && it->second == the_last){
//             return true;
//         }else{
//             return false;
//         }
//     }else{
//         return false;
//     }
// }
// int main(){
//     int N;
//     cin >> N;
//     vector<string> ids(N);
//     for (int i = 0; i < N; i++) {
//         cin >> ids[i];
//     }
//     unordered_map<int, char> mapping;
//     vector<int> weight;
//     init(mapping, weight);
//     bool allPassed = true;
//     for (auto& id : ids) {
//         if (!get_check_num(id, weight, mapping)) {
//             cout << id << endl;  // 输出有问题的身份证号
//             allPassed = false;
//         }
//     }
//     if (allPassed) {
//         cout << "All passed" << endl;  // 如果没有问题的身份证号，输出 "All passed"
//     }
//     return 0;
// }


// const int ID_LENGTH = 18;  // 身份证长度
// const int CHECKSUM_MOD = 11;  // 校验码模值
// const vector<int> WEIGHT = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};  // 权重
// const vector<char> CHECK_CODES = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};  // 校验码字符


// bool is_number(const string& s) {
//     return !s.empty() && all_of(s.begin(), s.end(), ::isdigit);
// }

// // 计算身份证号的校验码是否正确
// bool get_check_num(string id) {
//     char expected_check_code = id[17];  // 取最后一位校验码
//     id.erase(id.end() - 1);  // 删除最后一位，剩下17位
//     if (id.length() != ID_LENGTH||!is_number(id)) {
//         return false;  // 长度不为18位
//     }
//     int sum = 0;
//     for (int i = 0; i < 17; ++i) {
//         sum += (id[i] - '0') * WEIGHT[i];  // 根据权重计算加权和
//     }
    
//     int checksum_index = sum % CHECKSUM_MOD;  // 对11取模得到校验码的索引
//     char actual_check_code = CHECK_CODES[checksum_index];  // 计算得到的校验码
    
//     return expected_check_code == actual_check_code;  // 比较计算结果与身份证最后一位是否一致
// }

// int main() {
//     int N;
//     cin >> N;  // 输入身份证号码个数
    
//     vector<string> ids(N);
//     for (int i = 0; i < N; ++i) {
//         cin >> ids[i];  // 输入每个身份证号码
//     }
    
//     bool allPassed = true;  // 是否所有身份证都合法
//     for (const string& id : ids) {
//         if (!get_check_num(id)) {
//             cout << id << endl;  // 输出校验失败的身份证号码
//             allPassed = false;
//         }
//     }
//     if (allPassed) {
//         cout << "All passed" << endl;  // 如果所有身份证号码校验通过
//     }
    
//     return 0;
// }
// 判断字符串是不是由数字组成
// bool turn_to_num(string s){
// 	bool flag = false;
// 	for(char c : s){
// 		int a = c-'0';
// 		if(!(a>=0&&a<9)){
//             return flag;
//         }
// 	}
// 	return !flag;
// }
// int main(){
//     string s = "78f";
//     cout << turn_to_num(s);
// }

// L1-017 到底有多二
// 2024年12月9日10:57:15
// 2024年12月9日11:19:29
// float count_2(string s){
//     float count = 0;
//     for(char c : s){
//         if(c == '2')
//             count++;
//     }
//     return count;
// }
// int main(){
//     string s;
//     cin >> s;
//     float mag = 1;
//     int i = 1;
//     if(s[0] == '-'){
//         s.erase(s.begin());
//         mag = 1.5;
//     }
//     int length = s.length();
//     if(s[length-1] % 2 == 0){
//         i = 2;
//     }
//     float result = 100 *count_2(s) / length * mag * i;
//     cout << fixed << setprecision(2) << result<<"%";
//     return 0;
// }

// L1-018 大笨钟
// 2024年12月9日11:51:48
// 2024年12月9日12:18:48
// 笨方法
// pair<int,int> get_time(string s){
//     int hour = stoi(s.substr(0, 2));
//     int minute = stoi(s.substr(3, 2));
//     return make_pair(hour, minute);
// }
// bool is_too_early(pair<int,int> time){
//     return time.first < 12||(time.first==12 && time.second!=0);
// }
// int main(){
//     string s ;
//     cin >> s;
//     pair<int, int> time = get_time(s);
//     int count = time.first;
//     if(!is_too_early(time)&&time.second != 0){
//         count++;
//     }
//     if(is_too_early(time)){
//         cout << "Only " << s << ".  Too early to Dang.";
//     }else{
//         for (int i = 0; i < count % 12;i++){
//             cout << "Dang";
//         }
//     }
// }

// 数学总是这么朴实无华
// int get_time(string s){
//     int hour = stoi(s.substr(0, 2));
//     int minute ++++++++++
// += stoi(s.substr(3, 2));
//     return hour * 60 + minute;
// }
// int main(){
//     string s ;
//     cin >> s;
//     int result = get_time(s);
//     int count = result / 60 - 12;
//     if(result<=720){
//         cout << "Only " << s << ".  Too early to Dang.";
//     }else if(result % 60 != 0){
//         count++;
//     }
//     for (int i = 0; i < count;i++){
//         cout << "Dang";
//     }
// }

// L1-019 谁先倒
// 2024年12月11日14:16:29
// 2024年12月11日15:03:47
// bool who_wins(int& max_a,int& max_b,const int temp_a,const int temp_b){
//     if(!max_a){
//         cout << "A\n"
//              << temp_b - max_b;
//         return true;
//     }
//     if(!max_b){
//         cout << "B\n"
//              << temp_a - max_a;
//         return true;
//     }
//     return false;
// }

// bool is_fall(int A_bark, int A_out, int B_bark, int B_out,int& max_a,int& max_b,const int temp_a,const int temp_b){
//     int sum = A_bark + B_bark;
//     if(sum == A_out && sum == B_out){
        
//     }else if(sum ==B_out){
//         max_b--;
//     }else if(sum ==A_out){
//         max_a--;
//     }
//     return who_wins(max_a, max_b,temp_a,temp_b);
// }

// int main(){
//     int max_A, max_B,rounds;
//     int A_bark, A_out, B_bark, B_out;
//     cin >> max_A >> max_B;
//     max_A++;
//     max_B++;
//     int temp_a = max_A;
//     int temp_b = max_B;
//     cin >> rounds;
//     while(rounds--){
//         cin >> A_bark >> A_out >> B_bark >> B_out;
//         if(is_fall(A_bark, A_out, B_bark, B_out,max_A,max_B,temp_a,temp_b)){
//             return 0;
//         }
//     }
//     return 0;
// }

