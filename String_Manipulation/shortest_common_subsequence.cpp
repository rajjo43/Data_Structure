// c++ program to find the length of
// the shortest superstring of s1 and s2
// Length of SCS = length of s1 + length of s2 - length of LCS
#include <bits/stdc++.h>
using namespace std;

// Returns length of LCS for s1[0..m-1], s2[0..n-1]
int lcs(string &s1, string &s2) {
    int m = s1.size();
    int n = s2.size();

    // Initializing a matrix of size (m+1)*(n+1)
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Building dp[m+1][n+1] in bottom-up fashion
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // dp[m][n] contains length of LCS for s1[0..m-1]
    // and s2[0..n-1]
    return dp[m][n];
}

int shortestCommonSupersequence(string &s1, string &s2) {

    return s1.size() + s2.size() - lcs(s1, s2);
}

int main() {
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";
    cout << shortestCommonSupersequence(s1, s2) << endl;

    return 0;
}