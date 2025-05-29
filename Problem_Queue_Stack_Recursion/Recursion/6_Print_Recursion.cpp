#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void printRecursion(int n){
    if(n == 0)
        return;
    cout <<" I love Recursion\n";

    printRecursion(n - 1);
}

int main(){
    int n ;
    cin >> n;

    printRecursion(n);
    return 0;
}
