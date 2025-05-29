#include<iostream>
using namespace std;

void traverse(int *arr, int len){
    for(int i = 0; i < len; i++){
        cout << arr[i] << " ";    
    } 
}

void Delete(int *arr, int &n, int k){
    for(int i = k; i < n - 1; i++){
        arr[i] = arr[i + 1];
    }
    n--; // Decrease the size of the array
}

int main(){
    int n, k;
    int arr[12] = {1,2,3,4,5,6,7,8,9,10,11,12};

    n = sizeof(arr) / sizeof(arr[0]);
    k = 5;  // Position to delete (1-based index, so it corresponds to the 6th element in the array)

    Delete(arr, n, k - 1); // Deleting at index k-1 (0-based indexing)
    traverse(arr, n); // Display the array after deletion

    return 0;
}
