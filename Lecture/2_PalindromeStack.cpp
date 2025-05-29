#include<bits/stdc++.h>
using namespace std;

int main(){
    string s1 = "mmadam";
    vector<char> v1, v2;
    stack<char> s;
    for(char c: s1){
        s.push(c);
        v1.push_back(c);
    }
    while(!s.empty()){
        v2.push_back(s.top());
        s.pop();
    }

    if(v1 == v2){
        cout << "Palindorome\n";
    }
    else{
        cout << "Not a Palindrome\n";
    }

    return 0;
}