#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
//나쁜 문자 이동만 사용해 보이어-무어 알고리즘 구현
//접두부: 문자열의 머리부분, 접미부: 문자열의 꼬리부분
// 나쁜 문자 테이블 생성 함수
std::vector<int> buildBadCharTable(const std::string& pattern) {
    std::vector<int> badChar(256, -1);  // ASCII 문자에 대한 테이블
    for (int i = 0; i < pattern.size(); ++i) {
        badChar[static_cast<int>(pattern[i])] = i;
    }
    return badChar;
}

// 보이어-무어 문자열 검색 함수
void boyerMooreSearch(const std::string& text, const std::string& pattern) {
    std::vector<int> badChar = buildBadCharTable(pattern);
    int n = text.size();
    int m = pattern.size();
    int s = 0;  // s는 text에서 pattern과 비교를 시작하는 위치

    while (s <= (n - m)) {
        int j = m - 1;

        // 패턴의 오른쪽부터 왼쪽으로 문자를 비교
        while (j >= 0 && pattern[j] == text[s + j]) {
            j--;
        }

        if (j < 0) {
            std::cout << "Pattern occurs at shift = " << s << std::endl;

            // 패턴이 텍스트 끝에서 찾아지지 않은 경우
            s += (s + m < n) ? m - badChar[text[s + m]] : 1;
        }
        else {
            // 나쁜 문자 규칙 적용
            s += std::max(1, j - badChar[text[s + j]]);
        }
    }
}

int main() {
    std::string text = "ABAAABCD";
    std::string pattern = "ABC";
    boyerMooreSearch(text, pattern);
    return 0;
}
