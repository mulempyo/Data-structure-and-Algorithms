#include <iostream>
#include <queue>        // priority_queue를 사용하기 위한 헤더
#include <vector>       // 내부 컨테이너로 vector 사용

int main() {
    // 우선순위 큐 생성, 기본적으로 std::vector를 내부 컨테이너로 사용
    std::priority_queue<int> pq;

    // 요소 추가
    pq.push(10);
    pq.push(20);
    pq.push(5);
    pq.push(15);

    // 큐 내부 요소 출력
    std::cout << "Priority Queue contains: ";
    while (!pq.empty()) {
        std::cout << pq.top() << " ";
        pq.pop();  // 가장 큰 원소를 제거
    }
    std::cout << std::endl;

    return 0;
}