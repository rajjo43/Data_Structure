//Infix to Prefix
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
    stack<char> t,s;
    cin >> s1;

    //Reverse the given expression
    for(char c: s1){
        if(c == '('){
            t.push(')');
        }
        else if(c == ')'){
            t.push('(');
        }
        else{
            t.push(c);
        }
    }
    vector<char> v;
    while(!t.empty()){
        v.push_back(t.top());
        t.pop();
    }

    //Covert the reverse expression to postfix
    for(char c: v){
        if(operand(c)){
            t.push(c);
        }
        else if(s.empty() || s.top() == '('){
            s.push(c);
        }
        else if(c == '('){
            s.push(c);
        }
        else if(c == ')'){
            while(s.top() != '('){
                t.push(s.top());
                s.pop();
            }
            s.pop();
        }
        else if(precedence(c) >= precedence(s.top())){
            s.push(c);
        }
        else if(precedence(c) < precedence(s.top())){
            while(!s.empty() && s.top()!= '(' && precedence(c) < precedence(s.top()) && s.top()!= '('){
                t.push(s.top());
                s.pop();
            }
            s.push(c);
        }
    }

    //Reverse the postfix notation
    while(!s.empty()){
        if(s.top() != '('){
            t.push(s.top());
            s.pop();
        }
        else{
            s.pop();
        }
        
    }
    while(!t.empty()){
        cout << t.top();
        t.pop();
    }
    cout << endl;
    return 0;
}