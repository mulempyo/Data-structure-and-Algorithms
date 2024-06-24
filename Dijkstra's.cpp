#include <iostream>
#include <vector>
#include <queue>
#include <limits>

void dijkstraAlgorithm(const std::vector<std::vector<std::pair<int, int>>>& adjList, int start) {
    int n = adjList.size();
    std::vector<int> dist(n, std::numeric_limits<int>::max());
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;

    dist[start] = 0;
    pq.push({ 0, start });

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue;

        for (const auto& [v, weight] : adjList[u]) {
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({ dist[v], v });
            }
        }
    }

    std::cout << "Shortest distances from vertex " << start << ":\n";
    for (int i = 0; i < n; ++i) {
        std::cout << "To " << i << ": " << dist[i] << std::endl;
    }
}

int main() {
    std::vector<std::vector<std::pair<int, int>>> adjList = {
        {{1, 10}, {2, 6}, {3, 5}},  // Adjacency list for vertex 0
        {{3, 15}},                 // Adjacency list for vertex 1
        {{3, 4}},                  // Adjacency list for vertex 2
        {}                         // Adjacency list for vertex 3
    };
    int start = 0; // Starting vertex

    dijkstraAlgorithm(adjList, start);
}