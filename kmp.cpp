#include <iostream>
#include <vector>
#include <string>

// 부분 일치 테이블 생성 함수
std::vector<int> computeKMPTable(const std::string& pattern) {
    int m = pattern.length();
    std::vector<int> lps(m, 0); // Longest Prefix Suffix
    int len = 0; // length of the previous longest prefix suffix
    int i = 1;

    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else { // (pattern[i] != pattern[len])
            if (len != 0) {
                len = lps[len - 1];
            } else { // if (len == 0)
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

// KMP 알고리즘을 이용한 문자열 검색 함수
void KMPSearch(const std::string& text, const std::string& pattern) {
    int n = text.length();
    int m = pattern.length();
    std::vector<int> lps = computeKMPTable(pattern);

    int i = 0; // index for text
    int j = 0; // index for pattern
    while (i < n) {
        if (pattern[j] == text[i]) {
            j++;
            i++;
        }

        if (j == m) {
            std::cout << "Found pattern at index " << i - j << std::endl;
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
}

int main() {
    std::string text = "ABABDABACDABABCABAB";
    std::string pattern = "ABABCABAB";
    KMPSearch(text, pattern);
    return 0;
}
