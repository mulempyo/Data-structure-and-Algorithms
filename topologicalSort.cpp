#include <iostream>
#include <vector>
#include <queue>
#include <list>
/*
위상 정렬(Topological Sorting)은 방향 그래프에서 각 정점을 방향성에 거스르지 않도록 순서대로 나열하는 알고리즘입니다. 
이 정렬은 일반적으로 순환을 포함하지 않는 방향 그래프(DAG, Directed Acyclic Graph)에 대해서만 수행할 수 있습니다.

위상 정렬을 구현하는 한 가지 방법은 Kahn의 알고리즘을 사용하는 것입니다. 
이 알고리즘은 각 정점의 진입 차수를 계산하여, 진입 차수가 0인 정점을 큐에 넣고, 그 정점과 연결된 간선을 제거하면서 진행합니다. 
이 과정을 모든 정점이 큐에 들어갈 때까지 반복합니다.
*/
// 위상 정렬 함수
void topologicalSort(const std::vector<std::list<int>>& adjList) {
    int n = adjList.size();
    std::vector<int> inDegree(n, 0);
    std::queue<int> zeroIndegree;
    std::vector<int> topoOrder;

    // 모든 정점에 대해 진입 차수 계산
    for (int i = 0; i < n; ++i) {
        for (int neighbor : adjList[i]) {
            inDegree[neighbor]++;
        }
    }

    // 진입 차수가 0인 정점을 큐에 추가
    for (int i = 0; i < n; ++i) {
        if (inDegree[i] == 0) {
            zeroIndegree.push(i);
        }
    }

    // 위상 정렬 수행
    while (!zeroIndegree.empty()) {
        int v = zeroIndegree.front();
        zeroIndegree.pop();
        topoOrder.push_back(v);

        for (int neighbor : adjList[v]) {
            if (--inDegree[neighbor] == 0) {
                zeroIndegree.push(neighbor);
            }
        }
    }

    // 위상 정렬 결과 출력
    if (topoOrder.size() != n) {
        std::cout << "There is a cycle in the graph." << std::endl;
    } else {
        std::cout << "Topological Sorting: ";
        for (int v : topoOrder) {
            std::cout << v << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    // 그래프 생성: 정점은 0부터 시작
    int n = 6;
    std::vector<std::list<int>> adjList(n);
    adjList[5].push_back(0);
    adjList[5].push_back(2);
    adjList[4].push_back(0);
    adjList[4].push_back(1);
    adjList[2].push_back(3);
    adjList[3].push_back(1);

    // 위상 정렬 실행
    topologicalSort(adjList);

    return 0;
}