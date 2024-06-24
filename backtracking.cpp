#include <iostream>
#include <vector>
#include <string>
//백트래킹은 여러 후보해 중에서 특정 조건을 충족시키는 모든 해를 찾는 알고리즘이다.
// 체스판을 출력하는 함수
void printBoard(const std::vector<std::string>& board) {
    for (const auto& row : board) {
        std::cout << row << "\n";
    }
    std::cout << "\n";
}

// 퀸을 놓을 수 있는지 확인하는 함수
bool isValid(const std::vector<std::string>& board, int row, int col, int n) {
    // 같은 열 검사
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 'Q') {
            return false;
        }
    }

    // 왼쪽 대각선 검사
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }

    // 오른쪽 대각선 검사
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }

    return true;
}

// 백트래킹을 사용하여 N-Queens 문제를 해결하는 함수
void solveNQueensUtil(std::vector<std::string>& board, int row, int n, int& solutions) {
    if (row == n) {
        printBoard(board);
        solutions++;
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isValid(board, row, col, n)) {
            board[row][col] = 'Q';  // 퀸 배치
            solveNQueensUtil(board, row + 1, n, solutions);
            board[row][col] = '.';  // 백트래킹
        }
    }
}

// N-Queens 문제를 해결하고 해결책의 수를 반환하는 함수
int solveNQueens(int n) {
    std::vector<std::string> board(n, std::string(n, '.'));
    int solutions = 0;
    solveNQueensUtil(board, 0, n, solutions);
    return solutions;
}

int main() {
    int n = 8;  // N-Queens 문제의 크기 (예: 8)
    std::cout << "Number of solutions for " << n << "-Queens problem: " << solveNQueens(n) << "\n";
    return 0;
}
