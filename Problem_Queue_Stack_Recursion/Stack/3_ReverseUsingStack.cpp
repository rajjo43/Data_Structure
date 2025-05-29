#include <iostream>
#include <stack>
#include <bits/stdc++.h>
using namespace std;

int main() {
    string p;
    cout << "Enter the line\n";
    getline(cin, p);
    stringstream s(p);
    string eachword;

    stack<string> mystack;
    while (s >> eachword) {
        reverse(eachword.begin(), eachword.end()); // Reverse the word
        mystack.push(eachword);
    }

    while (!mystack.empty()) {
        cout << mystack.top() << " ";
        mystack.pop();
    }

    return 0;
}
