#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool isValid(string s) {
            stack<char> stk;
            for(int i = 0; i < s.size(); i++){
                if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                    stk.push(s[i]);
                }
                else{
                    if(stk.empty()) return false; // No opening bracket to match the current closing bracket
                    if((stk.top() == '(' && s[i] == ')') || (stk.top() == '{' && s[i] == '}') || (stk.top() == '[' && s[i] == ']')){
                        stk.pop(); // If it matches, pop the opening bracket
                    }
                    else{
                        return false; // Mismatched bracket, return false immediately
                    }
                }
            }
            return stk.empty(); // If stack is empty, all brackets were matched, otherwise return false
        }
};

int main(){
    string s;
    cin >> s;
    Solution sol;
    if(sol.isValid(s)){
        cout << "True";
    }
    else{
        cout << "False";
    }
}
