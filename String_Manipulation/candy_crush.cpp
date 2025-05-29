/*
Input: K = 2, str = "geeksforgeeks" 
Output: gksforgks 
Explanation: After removal of both occurrences of the substring "ee", the string reduces to "gksforgks".

Input: K = 3, str = "qddxxxd" 
Output: q 
Explanation: Removal of "xxx" modifies the string to "qddd". Again, removal of "ddd" modifies the string to "q".
*/
#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

string removeKChar(int k, string str) {
    if (k == 1) return "";

    string ans = "";
    stack<pair<char, int>> stk;

    for (int i = 0; i < str.size(); i++) {
        if (stk.empty()) {
            stk.push(make_pair(str[i], 1));
        } else {
            if (str[i] == stk.top().first) {
                pair<char, int> p = stk.top();
                stk.pop();
                p.second++;
                if (p.second < k) stk.push(p);
            } else {
                stk.push(make_pair(str[i], 1));
            }
        }
    }

    while (!stk.empty()) {
        if (stk.top().second > 1) {
            int count = stk.top().second;
            while (count--) ans += stk.top().first;
        } else {
            ans += stk.top().first;
        }
        stk.pop();
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    string s = "geeksforgeeks";
    int k = 2;
    cout << removeKChar(k, s) << "\n";
    return 0;
}