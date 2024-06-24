#include <iostream>
#include <vector>

int main() {
    int n = 4; // 정점의 수
    std::vector<std::vector<int>> adjMatrix(n, std::vector<int>(n, 0));

    // 간선 추가 예: 정점 1과 정점 2 연결
    adjMatrix[1][2] = 1;
    adjMatrix[2][1] = 1; // 무방향 그래프의 경우

    // 그래프 출력
    std::cout << "Adjacency Matrix:" << std::endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << adjMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
} //인접 행렬은 정점 간의 연결을 확인하는데 𝑂(1)O(1)의 시간 복잡도를 가지지만, 모든 가능한 정점 쌍에 대한 공간을 소비합니다.