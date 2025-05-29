#include<bits/stdc++.h> 
using namespace std;

void CountingSort(vector<int> &arr, int k){
    vector<int> c(k+1), b(arr.size());
    for(int i = 0; i < k+1; i++){
        c[i] = 0;
    }

    //storing count of each element of arr in c
    for(int j = 0; j < arr.size(); j++){
        c[arr[j]]++; 
    }

    //change c[i] such that it contains actual postion of these elements in output array
    for(int i = 1; i < k+1; i++){
        c[i] += c[i-1];
    }

    //output array b from c
    for(int j = arr.size()-1; j>=0; j--){
        b[c[arr[j]] - 1] = arr[j];
        c[arr[j]]--;
    }
    
    //copy b to original array
    for(int i = 0; i < arr.size(); i++){
        arr[i] = b[i];
    }
}


int main(){
    vector<int> arr = {77, 42, 35, 12, 101, 5};
    CountingSort(arr, 101);
    for(int a: arr){
        cout << a << " ";
    }
    return 0;
}