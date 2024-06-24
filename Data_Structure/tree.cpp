#include <iostream>
#include <set>

int main() {
    std::set<int> tree;

    // 요소 추가
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(18);

    // 요소 출력
    std::cout << "Tree elements in sorted order: ";
    for (int element : tree) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    // 요소 찾기
    auto search = tree.find(7);
    if (search != tree.end()) {
        std::cout << "Element '7' found in the tree." << std::endl;
    }
    else {
        std::cout << "Element '7' not found." << std::endl;
    }

    // 요소 삭제
    tree.erase(7);
    std::cout << "Tree elements after erasing '7': ";
    for (int element : tree) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}