#include<algorithm>
#include <iostream>
#include <string>

template <typename T>
class MyVector {
   public:
    class iterator {
        T* ptr_ = nullptr;

       public:
        iterator() = default;
        explicit iterator(T* ptr) : ptr_(ptr) {};
        T& operator*() const { return *ptr_; }  // 必须，迭代器需要解引用
        T* operator->() const { return ptr_; }  // 可选
        iterator& operator++() {                // 必须
            ++ptr_;
            return *this;
        }
        iterator operator++(int) {  // 后置自增，可选，因为迭代使用前置
            iterator tmp{ptr_};
            ++ptr_;
            return tmp;
        }
        friend bool operator==(const iterator& a, const iterator& b)  { return a.ptr_ == b.ptr_; }  // 必须
        friend bool operator!=(const iterator& a, const iterator& b) { return a.ptr_ != b.ptr_; }  // 必须
        // 可以将这两个函数作为成员函数，实现为：
        // bool operator==(const iterator& mv) const {
        //     return this->ptr_ == mv.ptr_;
        // }
        // bool operator!=(const iterator& mv) const {
        //     return this->ptr_ != mv.ptr_;
        //     return !(*this == other); // 复用==函数
        // }
    };
    MyVector() : data_(nullptr), size_(0), capacity_(0) {}
    ~MyVector() noexcept { delete[] data_; }

    void reserve(size_t new_cap) {
        if (new_cap <= capacity_)
            return;
        T* new_data = new T[new_cap];
        for (size_t i = 0; i < size_; i++) {
            new_data[i] = data_[i];
        }
        delete[] data_;
        data_ = new_data;
        capacity_ = new_cap;
    }

    void push_back(const T& value) {
        if (size_ == capacity_) {
            reserve(capacity_ ? capacity_ * 2 : 4);
        }
        data_[size_++] = value;
    }
    // 添加移动语义，右值插入操作，可选
    void push_back(T&& value) {
        if (size_ == capacity_) {
            reserve(capacity_ ? capacity_ * 2 : 4);
        }
        data_[size_++] = std::move(value);
    }
    iterator begin() noexcept { return iterator(data_); }        // 必须
    iterator end() noexcept { return iterator(data_ + size_); }  // 必须

    using const_iterator = const T*;  // 实现const版，可选
    const_iterator cbegin() const noexcept { return data_; }
    const_iterator cend() const noexcept { return data_ + size_; }

    // 下标访问，可选
    T& operator[](size_t index) {
        if (index >= size_)
            throw std::out_of_range("index out of range.");
        return data_[index];
    }
    // const版本，可选
    const T& operator[](size_t index) const {
        if (index >= size_)
            throw std::out_of_range("index out of range.");
        return data_[index];
    }
    size_t size() const noexcept { return size_; }

    // 拷贝构造函数，可选，实现MyVector mv1(mv2);
    MyVector(const MyVector& other) : data_(new T[other.capacity_]), size_(other.size_), capacity_(other.capacity_){
        for (size_t i = 0; i < capacity_; i++){
            data_[i] = other.data_[i];
        }
    }
    // 拷贝赋值运算符重载，可选，实现MyVector mv1 = mv2;
    MyVector& operator=(const MyVector& other){
        if(this != &other){
            delete[] data_;
            data_ = new T[other.size_];
            capacity_ = other.capacity_;
            size_ = other.size_;
            for (size_t i = 0; i < capacity_; i++){
                data_[i] = other.data_[i];
            }
        }
        return *this;
    }

    // 实现移动语义，提高性能，拷贝移动语义
    MyVector(MyVector&& other): data_(other.data_), size_(other.size_), capacity_(other.capacity_){
        other.data_ = nullptr;
        other.capacity_ = 0;
        other.size_ = 0;
    }
    // 赋值移动语义
    MyVector& operator=(MyVector&& other) noexcept{
        if(this != &other){
            delete[] data_;
            data_ = other.data_;
            size_ = other.size_;
            capacity_ = other.capacity_;
            delete[] other.data_;
            other.data_ = nullptr;
            other.size_ = 0;
            other.capacity_ = 0;
        }
        // 或者将上面if语句中全部内容替换为swap(*this, other);
        return *this;
    }

   private:
    T* data_;
    size_t size_;
    size_t capacity_;
};

int main() {
    MyVector<int> mv;
    mv.push_back(10);
    mv.push_back(20);
    mv.push_back(30);
    mv.push_back(30);
    mv.push_back(30);
    mv.push_back(30);
    mv.push_back(30);
    mv.push_back(30);
    mv.push_back(30);
    mv.push_back(30);
    std::cout << mv[1] << std::endl;
    for(const auto& x : mv){
        std::cout << x << std::endl;
    }
    MyVector<int> mv2 = mv;
    for(const auto& y : mv2){
        std::cout << y << std::endl;
    }
    MyVector<int> mv3(mv2);
    for(const auto& z : mv3){
        std::cout << z << std::endl;
    }
    auto minone = std::min_element(mv.begin(), mv.end());
    std::sort()
    std::cout << "min one element is: " << *minone << std::endl;
}