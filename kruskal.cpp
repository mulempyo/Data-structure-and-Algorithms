#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // for std::iota

struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

struct UnionFind {
    std::vector<int> parent, rank;
    UnionFind(int n) : parent(n), rank(n, 0) {
        std::iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            }
            else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            }
            else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

void kruskalAlgorithm(std::vector<Edge>& edges, int n) {
    std::sort(edges.begin(), edges.end());
    UnionFind uf(n);
    int mstCost = 0;

    for (const auto& e : edges) {
        if (uf.find(e.u) != uf.find(e.v)) {
            uf.unionSets(e.u, e.v);
            mstCost += e.weight;
            std::cout << "Edge (" << e.u << "-" << e.v << ") with weight " << e.weight << " added to MST\n";
        }
    }

    std::cout << "Total cost of MST using Kruskal's Algorithm: " << mstCost << std::endl;
}

int main() {
    std::vector<Edge> edges = {
        {0, 1, 10}, {0, 2, 6}, {0, 3, 5},
        {1, 3, 15}, {2, 3, 4}
    };
    int n = 4; // Number of vertices

    kruskalAlgorithm(edges, n);
}