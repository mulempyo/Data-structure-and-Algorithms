#include <iostream>
#include <vector>
#include <list>

int main() {
    int n = 4; // 정점의 수
    std::vector<std::list<int>> adjList(n);

    // 간선 추가 예: 정점 1과 정점 2 연결
    adjList[1].push_back(2);
    adjList[2].push_back(1); // 무방향 그래프의 경우

    // 그래프 출력
    std::cout << "Adjacency List:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << "Vertex " << i << ":";
        for (int j : adjList[i]) {
            std::cout << " " << j;
        }
        std::cout << std::endl;
    }

    return 0;
} //인접 리스트는 공간을 절약할 수 있고, 연결된 간선의 수에 비례하는 공간만을 사용하지만, 두 정점 간의 연결 여부를 확인하는데는 𝑂(𝑉)의 시간이 걸릴 수 있습니다.