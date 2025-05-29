#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function to find the longest common substring between s1 and s2
string longestCommonSubstring(const string& s1, const string& s2) {
    int n = s1.size();
    int m = s2.size();
    int maxLength = 0; // length of longest common substring
    int endingIndex = 0; // ending index of longest common substring in s1

    // Create a 2D table to store lengths of longest common suffixes of substrings
    // dp[i][j] will be length of longest common suffix of s1[0..i-1] and s2[0..j-1]
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Build dp table
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > maxLength) {
                    maxLength = dp[i][j];
                    endingIndex = i - 1;
                }
            }
        }
    }

    // If no common substring found
    if (maxLength == 0) return "";

    // Extract longest common substring from s1 using endingIndex and maxLength
    return s1.substr(endingIndex - maxLength + 1, maxLength);
}

int main() {
    string s1, s2;

    cout << "Enter first string: ";
    getline(cin, s1);
    cout << "Enter second string: ";
    getline(cin, s2);

    string lcs = longestCommonSubstring(s1, s2);

    if (lcs.empty()) {
        cout << "No common substring found." << endl;
    } else {
        cout << "Longest common substring: " << lcs << endl;
    }

    return 0;
}
