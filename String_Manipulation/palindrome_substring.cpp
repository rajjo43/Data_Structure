#include <bits/stdc++.h>
using namespace std;

// Function to find all distinct palindrome 
// substrings in a given string
vector<string> palindromicSubstr(string &str) {
    int n = str.length();

    // Create a set to store the result
    unordered_set<string> result;

    // generate all substrings
    for(int i = 0; i < n; i++) {

        // to store the substring
        string cur = "";

        for(int j = i; j < n; j++) {
            cur += str[j];

            // check if cur is palindrome
            int l = 0, r = cur.length() - 1;
            bool isPalindrome = true;
            while(l < r) {
                if(cur[l] != cur[r]) {
                    isPalindrome = false;
                    break;
                }
                l++;
                r--;
            }

            // if cur is palindrome, 
            // insert it into the set
            if(isPalindrome) {
                result.insert(cur);
            }
        }
    }

    // Convert the set to a vector
    vector<string> res(result.begin(), result.end());

    return res;
}

int main() {
    string str = "abaaa";
    vector<string> result = palindromicSubstr(str);
    for(string s : result)
        cout << s << " ";
    return 0;
}