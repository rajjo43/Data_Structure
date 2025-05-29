// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     string word1 = "WINKLER";
//     string word2 = "WELFARE";
//     int s1 = word1.length();
//     int s2 = word2.length();
//     int m = max(s1, s2) / 2 - 1;
//     string a[20];
//     int n = 0;

//     for(int i = 0; i < word1.length(); i++){
//         for(int j = 0; j < word2.length(); j++){
//             if(a[i] == a[j]){
//                 n++;
//             }
//         }
//     }
// }

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Function to calculate Jaro Similarity
double jaroSimilarity(const string& s1, const string& s2) {
    int len1 = s1.length();
    int len2 = s2.length();

    if (len1 == 0 && len2 == 0) return 1.0;
    if (len1 == 0 || len2 == 0) return 0.0;

    int match_distance = max(len1, len2) / 2 - 1;
    vector<bool> s1_matches(len1, false);
    vector<bool> s2_matches(len2, false);

    int matches = 0;
    for (int i = 0; i < len1; ++i) {
        int start = max(0, i - match_distance);
        int end = min(i + match_distance + 1, len2);

        for (int j = start; j < end; ++j) {
            if (s2_matches[j]) continue;
            if (s1[i] != s2[j]) continue;
            s1_matches[i] = true;
            s2_matches[j] = true;
            matches++;
            break;
        }
    }

    if (matches == 0) return 0.0;

    int transpositions = 0;
    int k = 0;
    for (int i = 0; i < len1; ++i) {
        if (s1_matches[i]) {
            while (!s2_matches[k]) k++;
            if (s1[i] != s2[k]) transpositions++;
            k++;
        }
    }

    double m = matches;
    return (1.0 / 3.0) * (m / len1 + m / len2 + (m - transpositions / 2.0) / m);
}

int main() {
    string s1 = "WINKLER";
    string s2 = "WELFARE";

    double similarity = jaroSimilarity(s1, s2);
    cout << "Jaro Similarity between \"" << s1 << "\" and \"" << s2 << "\" is: " << similarity << endl;

    return 0;
}
