#include <iostream>
using namespace std;

void traverse(int *arr, int len){
    for(int i = 0; i < len; i++){
        cout << arr[i] << " ";
    }
}

int main(){
    int arr[] = {1,3,5,6,2,7,8,9,4};
    int len = sizeof(arr) / sizeof(arr[0]);
    traverse(arr, len);

    return 0;
}