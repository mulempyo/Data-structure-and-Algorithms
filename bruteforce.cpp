#include <iostream>
#include <string>

// 고지식 검색 알고리즘 함수
int bruteForceSearch(const std::string& text, const std::string& pattern) {
    int n = text.length();
    int m = pattern.length();

    for (int i = 0; i <= n - m; ++i) {
        int j;
        for (j = 0; j < m; ++j) {
            if (text[i + j] != pattern[j])
                break;
        }
        if (j == m)  // 모든 문자가 일치하는 경우
            return i;  // 일치하는 위치의 인덱스 반환
    }
    return -1;  // 일치하는 패턴이 없는 경우
}

int main() {
    std::string text = "Here is a simple example";
    std::string pattern = "simple";

    int position = bruteForceSearch(text, pattern);

    if (position != -1) {
        std::cout << "Pattern found at position: " << position << std::endl;
    } else {
        std::cout << "Pattern not found" << std::endl;
    }

    return 0;
}