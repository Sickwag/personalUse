#include<bits/stdc++.h>
// /*
//     地址传递
// */

// 题目一：利用线性结构，编写程序实现两个有序表合并为一个有序表
// void initial(vector<int>& input1,vector<int>& input2){
//     string s, m, single;
//     cout << "input ordered array1 : ";
//     getline(cin, s);
//     stringstream numberstream1(s);
//     while(numberstream1>>single){
//         input1.push_back(stoi(single));
//     }
//     cout << "input ordered array2 : ";
//     getline(cin, m);
//     stringstream numberstream2(m);
//     while(numberstream2>>single){
//         input2.push_back(stoi(single));
//     }
// }
// vector<int> sort_and_merge(vector<int>& input1,vector<int>& input2){
//     input1.insert(input1.end(), input2.begin(), input2.end());
//     sort(input1.begin(), input1.end(), [](const int x, const int y)
//          { return x > y; });
//     return input1;
// }
// int main(){
//     vector<int> input1;
//     vector<int> input2;
//     initial(input1, input2);
//     cout << "sorted array : ";
//         for(int x : sort_and_merge(input1, input2)){
//             cout << x << " ";
//         }
// }

// 题目二：利用线性结构，编写程序实现两个一元多项式相加
// typedef vector<pair<int, int>> poly; // first:coeff  second:exp
// class poly_operations{
//     public:
//     void add_poly(poly& p, int coeff, int exp){ // coefficient,exponential
//         if (coeff == 0)
//             return;
//         for (auto it = p.begin(); it != p.end(); it++){
//             if(it->second == exp){
//                 it->first += coeff;
//                 if(it->first == 0){
//                     p.erase(it);
//                 }
//                 return;
//             }
//         }
//         p.push_back(make_pair(coeff, exp));
//     }

//     void print_poly(poly& p){
//         // need modify(sort) the poly ,cannot constraint
//         sort(p.begin(), p.end(), [](const pair<int, int> &a, const pair<int, int> &b)
//             { return a.second > b.second; });
//         for (size_t i = 0; i < p.size(); i++){
//             if(p[i].first > 0 && i != 0){
//                 cout << " + ";
//             }
//             cout << p[i].first;
//             if((p[i].second != 0)){
//                 cout << "x";
//                 if(p[i].second != 1){
//                     cout << "^" << p[i].second;
//                 }
//             }
//         }
//         cout << endl;
//     }

//     poly get_sum_poly(const poly& p1, const poly& p2){
//         poly result = p1;
//         for(const auto temp : p2){
//             add_poly(result, temp.first, temp.second);
//         }
//         return result;
//     }

//     void show_info(poly& p1, poly& p2){
//         cout << "poly 1: ";
//         print_poly(p1);
//         cout << "poly 2: ";
//         print_poly(p2);
//         poly sum = get_sum_poly(p1, p2);
//         cout << "the sum: ";
//         print_poly(sum);
//     }
// };

// int main() {
//     poly_operations po;
//     poly p1 = { {3, 2}, {2, 1}, {1, 0} }; // 3x^2 + 2x + 1
//     poly p2 = { {4, 3}, {5, 1}, {2, 0} }; // 4x^3 + 5x + 2
//     po.show_info(p1, p2);
//     po.add_poly(p1, 3, 3); // 3x^3 + 3x^2 + 2x + 1
//     po.show_info(p1, p2);
//     po.add_poly(p1, 3, 3); // 6x^3 + 3x^2 + 2x + 1
//     po.show_info(p1, p2);
//     return 0;
// }

// 题目三：利用线性结构实现两个复数相加
// template<typename T>
// ostream& operator<<(ostream& os,const complex<T>& c){
//     T real_part = c.real();
//     T imag_part = c.imag();
//     os << real_part;
//     if (imag_part >= 0){
//         os << " + " << imag_part << "i";
//     }else{
//         os << imag_part << "i";
//     }
//     return os;
// }
// template<typename T>
// void input_complexs(complex<T>& c){
//     T real_part, imag_part;
//     cout << "input the plural (real first, then imaginary, separate with space): ";
//     cin >> real_part >> imag_part;
//     c = complex<T>(real_part, imag_part);
// }
// int main(){
//     complex<double> n1, n2;
//     complex<int> n3, n4;
//     input_complexs(n1);
//     input_complexs(n2);
//     input_complexs(n3);
//     input_complexs(n4);
//     cout << (n1 + n2) << endl;
//     cout << (n3 + n4) << endl;
// }

// 题目四：稀疏矩阵的操作
// struct Triple {
//     int row;
//     int col;
//     int value;
// };

// class sparse_matrix {
// private:
//     int m, n;
//     vector<Triple> data;

// public:
//     sparse_matrix(int m, int n) : m(m), n(n) {}
//     void insert(int row, int col, int value) {
//         if (value == 0) return;
//         data.push_back({row, col, value});
//     }

//     void remove(int row, int col) {
//         for (auto it = data.begin(); it != data.end(); ++it) {
//             if (it->row == row && it->col == col) {
//                 data.erase(it);
//                 return;
//             }
//         }
//     }

//     sparse_matrix transpose() const {
//         sparse_matrix transposed(n, m);
//         for (const auto& t : data) {
//             transposed.insert(t.col, t.row, t.value);
//         }
//         return transposed;
//     }
//     sparse_matrix add(const sparse_matrix& other) const {
//         if (m != other.m || n != other.n) {
//             throw invalid_argument("matrix dimensions must match for addition.");
//         }

//         sparse_matrix result(m, n);
//         int i = 0, j = 0;
//         while (i < data.size() || j < other.data.size()) {
//             if (i >= data.size()) {
//                 result.insert(other.data[j].row, other.data[j].col, other.data[j].value);
//                 j++;
//             } else if (j >= other.data.size()) {
//                 result.insert(data[i].row, data[i].col, data[i].value);
//                 i++;
//             } else {
//                 if (data[i].row == other.data[j].row && data[i].col == other.data[j].col) {
//                     result.insert(data[i].row, data[i].col, data[i].value + other.data[j].value);
//                     i++;
//                     j++;
//                 } else if (data[i].row < other.data[j].row || 
//                            (data[i].row == other.data[j].row && data[i].col < other.data[j].col)) {
//                     result.insert(data[i].row, data[i].col, data[i].value);
//                     i++;
//                 } else {
//                     result.insert(other.data[j].row, other.data[j].col, other.data[j].value);
//                     j++;
//                 }
//             }
//         }
//         return result;
//     }
//     void print() const {
//         vector<vector<int>> matrix(m, vector<int>(n, 0));
//         if (data.empty()) {
//             cout << "matrix is empty." << endl;
//             return;
//         }
//         for (const auto& t : data) {
//             matrix[t.row - 1][t.col - 1] = t.value; 
//         }
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 cout << matrix[i][j] << " ";
//             }
//             cout << endl;
//         }
//     }
// };

// int main() {
//     sparse_matrix mat(3, 3);
//     mat.insert(1, 1, 5);
//     mat.insert(1, 3, 8);
//     mat.insert(2, 2, 3);
//     mat.insert(2, 3, 9);

//     cout << "Original matrix:" << endl;
//     mat.print(); 

//     mat.insert(1, 2, 4);
//     cout << "\nAfter inserting element at (1, 2):" << endl;
//     mat.print();

//     mat.remove(1, 3);
//     cout << "\nAfter removing element at (1, 3):" << endl;
//     mat.print();

//     sparse_matrix transposed = mat.transpose();
//     cout << "\nTranspose of the matrix:" << endl;
//     transposed.print();

//     sparse_matrix mat2(3, 3);
//     mat2.insert(1, 1, 1);
//     mat2.insert(2, 2, 2);
//     mat2.insert(3, 3, 3);
//     mat2.print();
//     sparse_matrix result = mat.add(mat2);
//     cout << "\nmatrix after addition:" << endl;
//     result.print();

//     return 0;
// }

// 题目五：排序算法实现
// class sorting_algorithms{
//     private:
//         vector<int> inside_class_unordered;
//     public:
//     sorting_algorithms(vector<int> input):inside_class_unordered(input){}
//     vector<int> getter(){
//         return inside_class_unordered;
//     }
//     void insert_sort(vector<int> unordered){
//         for (int i = 1; i < unordered.size(); i++) {
//             int key = unordered[i];
//             int j = i - 1;
//             while (j >= 0 && unordered[j] > key) {
//                 unordered[j + 1] = unordered[j];
//                 j--;
//             }
//             unordered[j + 1] = key;
//         }
//         print_result(unordered);
//     }
//     void select_sort(vector<int> unordered){
//         for (int i = 0; i < unordered.size() - 1; i++) {
//         int minIdx = i;
//         for (int j = i + 1; j < unordered.size(); j++) {
//             if (unordered[j] < unordered[minIdx]) {
//                 minIdx = j;
//             }
//         }
//         swap(unordered[i], unordered[minIdx]);
//         }
//         print_result(unordered);
//     }
//     // must use in the end
//     int partition(vector<int>& unordered, int low, int high) {
//         int pivot = unordered[high];
//         int i = low - 1;
//         for (int j = low; j < high; j++) {
//             if (unordered[j] < pivot) {
//                 i++;
//                 swap(unordered[i], unordered[j]);
//             }
//         }
//         swap(unordered[i + 1], unordered[high]);
//         return i + 1;
//     }
//     vector<int> quickSort(vector<int>& unordered, int low, int high) {
//         if (low < high) {
//             int pi = partition(unordered, low, high);
//             quickSort(unordered, low, pi - 1);
//             quickSort(unordered, pi + 1, high);
//         }
//         inside_class_unordered = unordered;
//         return inside_class_unordered;
//     }
//     void print_result(const vector<int>& unordered){
//         for(int x : unordered){
//             cout << x << " ";
//         }
//         cout << endl;
//     }
// };

// int main(){
//     vector<int> unordered = {23, 5, 63, 1, 6, 74, 68, 43, 2, 8, 98, 7};
//     sorting_algorithms sa(unordered);
//     cout << "insert sort : ";
//     sa.insert_sort(unordered);
//     cout << "select sort : ";
//     sa.select_sort(unordered);
//     cout << "quick sort : ";
//     sa.quickSort(unordered,0,unordered.size());
//     sa.print_result(sa.getter());
// }


// 题目十：电子小字典
// class Dictionary {
// private:
//     map<string, string> dict;// first : keyword , seconde : meaning
// public:
//     Dictionary(map<string, string> init_dict) { dict = init_dict; }
//     void insert_Word(const string& word, const string& meaning) {
//         dict[word] = meaning;
//         cout << "insert : \n"
//              << word << " -> " << meaning << "\ninsert word successfully" << endl;
//     }
//     void find_Word(const string& word) {
//         auto it = dict.find(word);
//         if (it != dict.end()) {
//             cout << "found it : " << word << " -> " << it->second << endl;
//         } else {
//             cout << "no matches " << word << endl;
//         }
//     }
//     void delete_Word(const string& word) {
//         auto it = dict.find(word);
//         if (it != dict.end()) {
//             dict.erase(it);
//             cout << "erase : " << word << " successfully" << endl;
//         } else {
//             cout << "no matches : " << word << endl;
//         }
//     }
//     void display() {
//         if (dict.empty()) {
//             cout << "empty dictionary " << endl;
//             return;
//         }
//         cout << "content : " << endl;
//         for (const auto& entry : dict) {
//             cout << entry.first << " -> " << entry.second << endl;
//         }
//     }
// };

// int main() {
//     map<string, string> init_dict = {
//         {"apple", "A fruit that is typically round and red, green, or yellow."},
//         {"banana", "A long curved fruit that grows in clusters."},
//         {"cat", "A small domesticated carnivorous mammal with soft fur."}
//     };
//     Dictionary d(init_dict);
//     d.insert_Word("dog", "a common animal with four legs ,especially kept by people as a pet or hunt or guard things.");
//     // d.find_Word("dog");
//     d.delete_Word("apple");
//     d.find_Word("banana");
//     d.find_Word("not_exist");
//     d.display();
//     return 0;
// }
