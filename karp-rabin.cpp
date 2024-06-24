#include <iostream>
#include <string>
#include <cmath>

// 해시 함수로 사용할 기본값들
const int prime = 101; // 소수로 더 나은 해시 충돌 방지

// 문자열 해시 함수
unsigned long hashFunction(const std::string& str, int end, int start = 0) {
    unsigned long hash = 0;
    for (int i = start; i <= end; i++) {
        hash += str[i] * static_cast<unsigned long>(pow(prime, i - start));
    }
    return hash;
}

// Rabin-Karp 알고리즘 함수
void rabinKarpSearch(const std::string& text, const std::string& pattern) {
    int m = pattern.length();
    int n = text.length();
    unsigned long patternHash = hashFunction(pattern, m - 1);
    unsigned long textHash = hashFunction(text, m - 1);

    for (int i = 0; i <= n - m; i++) {
        // 해시 값이 일치하면 추가 확인
        if (patternHash == textHash) {
            bool flag = true;
            for (int j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                std::cout << "Pattern found at index: " << i << std::endl;
            }
        }
        // 다음 텍스트 해시 값을 계산
        if (i < n - m) {
            textHash = (textHash - text[i] * static_cast<unsigned long>(pow(prime, 0))) * prime + text[i + m] * static_cast<unsigned long>(pow(prime, m - 1));
        }
    }
}

int main() {
    std::string text = "test text here";
    std::string pattern = "text";
    rabinKarpSearch(text, pattern);
    return 0;
}