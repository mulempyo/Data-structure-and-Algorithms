#include <iostream>
#include <string>
#include <unordered_map>
int main() {
    // std::unordered_map 생성
    std::unordered_map<std::string, int> map;

    // 데이터 삽입
    map["apple"] = 3;
    map["banana"] = 5;
    map["cherry"] = 2;

    // 요소에 접근
    std::cout << "The count of apples is " << map["apple"] << std::endl;

    // 요소 수정
    map["banana"] = 6;

    // 요소 검색
    if (map.find("banana") != map.end()) {
        std::cout << "Banana found with count " << map["banana"] << std::endl;
    }

    // 요소 삭제
    map.erase("cherry");

    // 전체 요소 출력
    std::cout << "Current elements in the map:" << std::endl;
    for (const auto& pair : map) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}