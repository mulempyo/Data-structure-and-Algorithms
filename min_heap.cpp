#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>  // std::greater 사용을 위한 헤더

int main() {
    std::vector<int> minHeap = {10, 20, 30, 5, 15};

    // 벡터를 최소 힙으로 변환
    std::make_heap(minHeap.begin(), minHeap.end(), std::greater<>{});

    // 힙에 새로운 요소 추가
    minHeap.push_back(2);
    std::push_heap(minHeap.begin(), minHeap.end(), std::greater<>{}); // 힙 속성 유지

    // 힙에서 최소 요소 제거
    std::pop_heap(minHeap.begin(), minHeap.end(), std::greater<>{});  // 최소 요소를 벡터의 끝으로 이동
    minHeap.pop_back();  // 벡터의 끝에서 요소 제거

    // 힙 출력
    std::cout << "Min Heap: ";
    for (int i : minHeap) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}