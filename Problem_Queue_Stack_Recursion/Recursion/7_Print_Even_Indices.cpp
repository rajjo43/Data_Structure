#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n;
int arr[1000];

void PrintIndices(int i){
    if(i >= n)
        return;
    PrintIndices(i + 2);
    cout << arr[i] << " ";
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    PrintIndices(0);
    return 0;
}