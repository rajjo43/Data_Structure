#include<bits/stdc++.h>
using namespace std;

void SelectionSort(vector<int> &arr){
    int temp, min;
    for(int i = 0; i < arr.size(); i++){
        min = i;
        for(int j = i+1; j < arr.size(); j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        if(min != i){
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}


int main(){
    vector<int> arr = {5,3,9,5,2,0,4,1};
    SelectionSort(arr);
    for(int a: arr){
        cout << a << " ";
    }
}