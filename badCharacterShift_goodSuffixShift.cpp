#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
//나쁜 문자 이동과 착한 접미부 이동 사용해 보이어-무어 알고리즘 구현
// 나쁜 문자 테이블 생성
std::vector<int> buildBadCharTable(const std::string& pattern) {
    std::vector<int> badChar(256, -1);
    for (int i = 0; i < pattern.size(); ++i) {
        badChar[static_cast<int>(pattern[i])] = i;
    }
    return badChar;
}

// 좋은 접미사 테이블 생성
std::vector<int> buildGoodSuffixTable(const std::string& pattern) {
    int m = pattern.size();
    std::vector<int> suffix(m, 0);
    std::vector<int> goodSuffix(m + 1, 0);
    suffix[m - 1] = m;
    int g = m - 1;
    int f = 0;

    for (int i = m - 2; i >= 0; --i) {
        if (i > g && suffix[i + m - 1 - f] < i - g) {
            suffix[i] = suffix[i + m - 1 - f];
        }
        else {
            g = i;
            f = i;
            while (g >= 0 && pattern[g] == pattern[g + m - 1 - f]) {
                --g;
            }
            suffix[i] = f - g;
        }
    }

    for (int i = 0; i < m; ++i) {
        goodSuffix[i] = m;
    }
    for (int i = m - 1, j = 0; i >= 0; --i) {
        if (suffix[i] == i + 1) {
            for (; j < m - 1 - i; ++j) {
                if (goodSuffix[j] == m) {
                    goodSuffix[j] = m - 1 - i;
                }
            }
        }
    }
    for (int i = 0; i <= m - 2; ++i) {
        goodSuffix[m - 1 - suffix[i]] = m - 1 - i;
    }

    return goodSuffix;
}

// 보이어-무어 알고리즘
void boyerMooreSearch(const std::string& text, const std::string& pattern) {
    std::vector<int> badChar = buildBadCharTable(pattern);
    std::vector<int> goodSuffix = buildGoodSuffixTable(pattern);
    int n = text.length();
    int m = pattern.length();
    int s = 0;

    while (s <= (n - m)) {
        int j = m - 1;

        while (j >= 0 && pattern[j] == text[s + j]) {
            --j;
        }

        if (j < 0) {
            std::cout << "Pattern occurs at shift = " << s << std::endl;
            s += goodSuffix[0];  // 좋은 접미사 규칙 사용
        }
        else {
            s += std::max(goodSuffix[j], j - badChar[text[s + j]]);  // 나쁜 문자와 좋은 접미사 중 더 큰 값을 사용
        }
    }
}

int main() {
    std::string text = "ABAAABCD";
    std::string pattern = "ABC";
    boyerMooreSearch(text, pattern);
    return 0;
}
