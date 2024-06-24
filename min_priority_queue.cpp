#include <iostream>
#include <queue>          // priority_queue를 사용하기 위한 헤더
#include <vector>         // 내부 컨테이너로 vector 사용
#include <functional>     // std::greater를 사용하기 위한 헤더

int main() {
    // 최소 힙 구현을 위한 우선순위 큐
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_pq;

    // 요소 추가
    min_pq.push(10);
    min_pq.push(20);
    min_pq.push(5);
    min_pq.push(15);

    // 큐 내부 요소 출력
    std::cout << "Min Priority Queue contains: ";
    while (!min_pq.empty()) {
        std::cout << min_pq.top() << " ";
        min_pq.pop();  // 가장 작은 원소를 제거
    }
    std::cout << std::endl;

    return 0;
}