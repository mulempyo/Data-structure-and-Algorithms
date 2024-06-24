#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> maxHeap = {10, 20, 30, 5, 15};

    // 벡터를 최대 힙으로 변환
    std::make_heap(maxHeap.begin(), maxHeap.end());

    // 힙에 새로운 요소 추가
    maxHeap.push_back(40);
    std::push_heap(maxHeap.begin(), maxHeap.end()); // 힙 속성 유지

    // 힙에서 최대 요소 제거
    std::pop_heap(maxHeap.begin(), maxHeap.end());  // 최대 요소를 벡터의 끝으로 이동
    maxHeap.pop_back();  // 벡터의 끝에서 요소 제거

    // 힙 출력
    std::cout << "Max Heap: ";
    for (int i : maxHeap) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}