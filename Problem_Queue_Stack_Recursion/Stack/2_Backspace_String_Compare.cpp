/*Given two strings s1 and s2, let us assume that while typing the strings there were some backspaces
encountered which are represented by #. The task is to determine whether the resultant strings after processing the
backspace character would be equal or not.

Input: s1= geee#e#ks, s2 = gee##eeks
Output: True
Input: s1 = equ#ual, s2 = ee#quaal#
Output: False*/
#include<iostream>
#include<stack>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s1,s2;
    printf("Enter s1:\n");
    cin>>s1;
    printf("Enter s2:\n");
    cin>>s2;
    stack<char>st1;
    stack<char>st2;

    for(char c:s1)
    {
        if(c=='#'){
            st1.pop();}
            else{
                st1.push(c);
            }
        }

    for(char c:s2)
    {
        if(c=='#'){
            st2.pop();}
            else{
                st2.push(c);
            }
    }

    bool flag=true;
      while (!st1.empty() && !st2.empty()) {
        if (st1.top() != st2.top()) {
            flag= false;
        }
        st1.pop();
        st2.pop();
    }

    if(flag==true)
    {
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }
}