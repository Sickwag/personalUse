#include <list>
#include <algorithm>
int main() {
    std::list<int> l = { 1, 2, 3 };
    std::sort(l.begin(), l.end());
    return 0;
}