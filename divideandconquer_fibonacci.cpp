#include <iostream>
#include <vector>

// 2x2 행렬 곱셈 함수
void multiply(std::vector<std::vector<long long>>& A, std::vector<std::vector<long long>>& B) {
    long long x = A[0][0] * B[0][0] + A[0][1] * B[1][0];
    long long y = A[0][0] * B[0][1] + A[0][1] * B[1][1];
    long long z = A[1][0] * B[0][0] + A[1][1] * B[1][0];
    long long w = A[1][0] * B[0][1] + A[1][1] * B[1][1];

    A[0][0] = x;
    A[0][1] = y;
    A[1][0] = z;
    A[1][1] = w;
}

// 행렬 거듭제곱 함수
void matrixPower(std::vector<std::vector<long long>>& A, int n) {
    if (n == 1 || n == 0)
        return;

    std::vector<std::vector<long long>> M = {{1, 1}, {1, 0}};

    matrixPower(A, n / 2);
    multiply(A, A);

    if (n % 2 != 0)
        multiply(A, M);
}

// n번째 피보나치 수를 반환하는 함수
long long fibonacci(int n) {
    std::vector<std::vector<long long>> A = {{1, 1}, {1, 0}};
    if (n == 0)
        return 0;
    matrixPower(A, n - 1);
    return A[0][0];
}

int main() {
    int n = 10;
    std::cout << n << "th Fibonacci number is " << fibonacci(n) << std::endl;
    return 0;
}