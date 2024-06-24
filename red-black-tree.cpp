//레드 블랙 트리는 std::set, std::map이 내부적으로 사용합니다.

#include <iostream>
#include <set>

int main() {
    std::set<int> rb_tree = { 10, 20, 30, 40, 50 };
    int target = 30;
    auto it = rb_tree.find(target);
    if (it != rb_tree.end()) {
        std::cout << "Element found: " << *it << std::endl;
    }
    else {
        std::cout << "Element not found." << std::endl;
    }
    return 0;
}