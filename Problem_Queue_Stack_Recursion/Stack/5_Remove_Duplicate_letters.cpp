#include<iostream>
#include<string>
#include<unordered_map>
#include<stack>
#include<unordered_set>
using namespace std;

string removeDuplicateLetters(string s) {
    unordered_map<char, int> frequency;
    unordered_set<char> inStack;  // To check if a character is already in the stack
    stack<char> stk;

    // Count the frequency of each character in the string
    for (char ch : s) {
        frequency[ch]++;
    }

    // Process each character in the string
    for (char ch : s) {
        // Decrease the frequency as we are processing this character
        frequency[ch]--;

        // If the character is already in the stack, we can skip it
        if (inStack.find(ch) != inStack.end()) {
            continue;
        }

        // Pop characters from the stack that are lexicographically greater than the current one
        // and still appear later in the string
        while (!stk.empty() && stk.top() > ch && frequency[stk.top()] > 0) {
            inStack.erase(stk.top());  // Remove from the stack set
            stk.pop();  // Pop the stack
        }

        // Push the current character to the stack and mark it as in the stack
        stk.push(ch);
        inStack.insert(ch);
    }

    // Construct the result string from the stack
    string result = "";
    while (!stk.empty()) {
        result = stk.top() + result;
        stk.pop();
    }

    return result;
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    string result = removeDuplicateLetters(s);
    cout << "Result: " << result << endl;
    return 0;
}
