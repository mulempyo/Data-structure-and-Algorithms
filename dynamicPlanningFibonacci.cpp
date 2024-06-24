#include <iostream>
#include <vector>

// n번째 피보나치 수를 반환하는 함수 (동적 계획법)
long long fibonacciDP(int n) {
    std::vector<long long> fib(n + 1, 0);
    fib[1] = 1;

    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    return fib[n];
}

int main() {
    int n = 10;
    std::cout << n << "th Fibonacci number is " << fibonacciDP(n) << std::endl;
    return 0;
}