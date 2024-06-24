#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <functional>

struct Node {
    int y, x;  // Node의 위치 (y, x)
    int gCost; // 시작 노드로부터의 비용
    int hCost; // 휴리스틱 비용 (목표 노드까지의 추정 비용)
    int fCost; // gCost + hCost

    Node(int y, int x, int g, int h) : y(y), x(x), gCost(g), hCost(h), fCost(g + h) {}

    // Priority Queue를 위한 비교 연산자 오버로딩
    bool operator>(const Node& other) const {
        return this->fCost > other.fCost;
    }
};

// 휴리스틱 함수 (여기서는 유클리드 거리 사용)
int heuristic(int x1, int y1, int x2, int y2) {
    return static_cast<int>(sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)) * 10);
}

// A* 알고리즘
void aStarSearch(const std::vector<std::vector<int>>& grid, Node start, Node goal) {
    std::priority_queue<Node, std::vector<Node>, std::greater<Node>> openSet;
    start.hCost = heuristic(start.x, start.y, goal.x, goal.y);
    start.fCost = start.gCost + start.hCost;
    openSet.push(start);

    std::vector<std::vector<bool>> closedSet(grid.size(), std::vector<bool>(grid[0].size(), false));

    while (!openSet.empty()) {
        Node current = openSet.top();
        openSet.pop();

        if (current.x == goal.x && current.y == goal.y) {
            std::cout << "Reached goal! Cost: " << current.gCost << std::endl;
            return;
        }

        closedSet[current.y][current.x] = true;

        // Neighbors 검사 (4 방향)
        std::vector<std::pair<int, int>> directions{ {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
        for (auto& dir : directions) {
            int ny = current.y + dir.first;
            int nx = current.x + dir.second;

            if (ny >= 0 && ny < grid.size() && nx >= 0 && nx < grid[0].size() && !closedSet[ny][nx] && grid[ny][nx] == 0) {
                int newCost = current.gCost + 10; // 모든 이동 비용은 10으로 가정
                Node neighbor(ny, nx, newCost, heuristic(nx, ny, goal.x, goal.y));
                openSet.push(neighbor);
            }
        }
    }

    std::cout << "No path found!" << std::endl;
}

int main() {
    std::vector<std::vector<int>> grid{
        {0, 0, 0, 0, 1},
        {0, 1, 1, 0, 1},
        {0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0}
    };

    Node start(0, 0, 0, 0);  // 시작 노드 (0,0)
    Node goal(3, 4, 0, 0);   // 목표 노드 (3,4)

    aStarSearch(grid, start, goal);

    return 0;
}
