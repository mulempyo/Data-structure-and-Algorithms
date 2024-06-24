#include <iostream>
#include <unordered_set>

//만약 데이터의 집합을 관리하고 싶다면, std::unordered_set을 사용할 수 있습니다. 이 컨테이너는 중복을 허용하지 않고, 요소들을 해시 테이블에 저장합니다

int main() {
    // std::unordered_set 생성
    std::unordered_set<std::string> set;

    // 데이터 삽입
    set.insert("apple");
    set.insert("banana");
    set.insert("cherry");
    set.insert("apple"); // 중복 삽입 시도 (무시됨)

    // 요소 검색
    if (set.find("banana") != set.end()) {
        std::cout << "Banana found" << std::endl;
    }

    // 요소 삭제
    set.erase("cherry");

    // 전체 요소 출력
    std::cout << "Current elements in the set:" << std::endl;
    for (const std::string& element : set) {
        std::cout << element << std::endl;
    }

    return 0;
}