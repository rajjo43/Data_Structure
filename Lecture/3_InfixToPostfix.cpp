//Infix to Postfix
#include<bits/stdc++.h>
using namespace std;

bool operand(char c){
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
        return true;
    }
    else return false;
}

int precedence(char c){
    if( c == '^') return 3;
    else if(c == '*' || c == '/' || c == '%') return 2;
    else if(c == '+' || c == '-') return 1;
    return -1;
}


int main(){
    string s1;
    stack<char> s;
    cin >> s1;
    for(char c: s1){
        if(operand(c)){
            cout << c;
        }
        else if(s.empty() || s.top() == '('){
            s.push(c);
        }
        else if(c == '('){
            s.push(c);
        }
        else if(c == ')'){
            while(s.top() != '('){
                cout << s.top();
                s.pop();
            }
            s.pop();
        }
        else if(precedence(c) >= precedence(s.top())){
            s.push(c);
        }
        else if(precedence(c) < precedence(s.top())){
            while(!s.empty() && s.top()!= '(' && precedence(c) < precedence(s.top()) && s.top()!= '('){
                cout << s.top();
                s.pop();
            }
            s.push(c);
        }
    }
    while(!s.empty()){
        if(s.top() != '('){
            cout << s.top();
            s.pop();
        }
        else{
            s.pop();
        }
        
    }
    return 0;
}