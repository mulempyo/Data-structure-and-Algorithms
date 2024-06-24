#include <iostream>
#include <vector>
#include <algorithm> //binary_search()

bool binarySearch(const std::vector<int>& data, int target) {
    return std::binary_search(data.begin(), data.end(), target);
}

int sequentialSearch(const std::vector<int>& data, int target) {
    for (size_t i = 0; i < data.size(); ++i) {
        if (data[i] == target) {
            return i;  // 타겟이 발견된 위치 반환
        }
    }
    return -1;  // 타겟이 리스트에 없으면 -1 반환
}

int main() {
    std::vector<int> data = { 10, 20, 30, 40, 50 };
    int target = 30;
    int index = binarySearch(data, target); //or sequentialSearch()
    if (index != -1) {
        std::cout << "Element found at index: " << index << std::endl;
    }
    else {
        std::cout << "Element not found." << std::endl;
    }
    return 0;
}