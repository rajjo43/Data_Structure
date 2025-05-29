#include <iostream>
using namespace std;

 void traverse(int *arr, int len){
    for(int i = 0; i < len; i++){
        cout << arr[i] << " ";
    }
 }

 void bubbleSort(int *arr, int n){
    int k, ptr, temp;
    for(k = 1; k <= n -1; k++){
        ptr = 0;
        while (ptr <= n - k -1)
        {
            if(arr[ptr] > arr[ptr + 1]){
                temp = arr[ptr + 1];
                arr[ptr + 1] = arr[ptr];
                arr[ptr] = temp;
            }
            ptr++;
        }
        
    }
 }

 int main(){
    int arr[] = {20,1,134,5,22,98,56,74,83,44};
    int n = sizeof(arr)/ sizeof(arr[0]);
    bubbleSort(arr, n);
    traverse(arr, n);
    return 0;
 }