#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

bool is_suitable(std::vector<int>& pos){
    if(pos.size() < 2)
        return false;
    int last = 0;
    std::vector<int> inteval;
    for (const auto& p : pos) {
        inteval.emplace_back(p - last);
        last = p;
    }
    auto pos_3 = std::lower_bound(inteval.begin(), inteval.end(), 3);
    auto pos_5 = std::lower_bound(pos_3, inteval.end(), 5);
    if(pos_3 == inteval.end() || pos_5 == inteval.end()){
        return false;
    }else{
        return true;
    }
}

int main(){
    const int mod = 998244353;
    int length, hour_num, temp;
    std::vector<int> pos;
    std::cin >> length >> hour_num;
    while(std::cin >> temp){
        pos.emplace_back(temp);
    }
    if(is_suitable(pos)){
        int idle = length - hour_num - 8;

    }

}