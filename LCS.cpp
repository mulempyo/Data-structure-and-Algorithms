#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
//Dynamic Planning
// LCS 길이 계산
int lcs(const std::string& X, const std::string& Y) {
    int m = X.size();
    int n = Y.size();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1));

    // dp 테이블 구축
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // 결과 LCS 길이 반환
    return dp[m][n];
}

// LCS 문자열 복원
std::string lcs_string(const std::string& X, const std::string& Y) {
    int m = X.size();
    int n = Y.size();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1));

    // dp 테이블 구축
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // LCS 문자열 추적 및 생성
    std::string lcsStr;
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcsStr.push_back(X[i - 1]);
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    
    std::reverse(lcsStr.begin(), lcsStr.end());
    return lcsStr;
}

int main() {
    std::string X = "AGGTAB";
    std::string Y = "GXTXAYB";

    std::cout << "Length of LCS: " << lcs(X, Y) << std::endl;
    std::cout << "LCS of " << X << " and " << Y << " is " << lcs_string(X, Y) << std::endl;

    return 0;
}