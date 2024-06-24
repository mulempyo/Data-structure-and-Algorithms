#include <iostream>
#include <vector>
#include <queue>
#include <utility> // for std::pair

const int INF = 1e9; // Define "infinity" as large enough value.

void primAlgorithm(const std::vector<std::vector<std::pair<int, int>>>& adjList, int start) {
    int n = adjList.size();
    std::vector<bool> inMST(n, false);
    std::vector<int> minWeight(n, INF);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;

    minWeight[start] = 0;
    pq.push({ 0, start });

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (inMST[u]) continue;
        inMST[u] = true;

        for (const auto& [v, weight] : adjList[u]) {
            if (!inMST[v] && weight < minWeight[v]) {
                minWeight[v] = weight;
                pq.push({ weight, v });
            }
        }
    }

    int mstCost = 0;
    for (int weight : minWeight) {
        if (weight < INF) {
            mstCost += weight;
        }
    }

    std::cout << "Total cost of MST using Prim's Algorithm: " << mstCost << std::endl;
}

int main() {
    int n = 4;
    std::vector<std::vector<std::pair<int, int>>> adjList(n);
    // Edges: (0-1:10), (0-2:6), (0-3:5), (1-3:15), (2-3:4)
    adjList[0].emplace_back(1, 10);
    adjList[0].emplace_back(2, 6);
    adjList[0].emplace_back(3, 5);
    adjList[1].emplace_back(3, 15);
    adjList[2].emplace_back(3, 4);

    primAlgorithm(adjList, 0); // Start Prim's algorithm from vertex 0
}
