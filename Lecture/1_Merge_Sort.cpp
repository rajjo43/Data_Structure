#include<bits/stdc++.h>
using namespace std;

// Merge function to merge two sorted subarrays into one sorted array
void Merge(vector<int> &arr, int low, int mid, int high){
    int h = low, i = 0, j = mid + 1;  // h is for left subarray, j is for right subarray, i is for the merged array

    vector<int> b(high - low + 1);  // temporary array to store merged result

    // Merge elements from both subarrays into the temporary array
    while((h <= mid) && (j <= high)){
        if(arr[h] <= arr[j]){
            b[i] = arr[h];  // copy element from left subarray
            h++;  // move to the next element in the left subarray
        }
        else{
            b[i] = arr[j];  // copy element from right subarray
            j++;  // move to the next element in the right subarray
        }
        i++;  // move to the next position in the temporary array
    }
    
    // If there are remaining elements in the left subarray, copy them
    if(h > mid){
        for(int k = j; k <= high; k++){
            b[i] = arr[k];
            i++;
        }
    }
    // If there are remaining elements in the right subarray, copy them
    else{
        for(int k = h; k <= mid; k++){
            b[i] = arr[k];
            i++;
        }
    }
    
    // Copy the sorted elements from the temporary array back to the original array
    for(int k = low, x = 0; k <= high; k++, x++){
        arr[k] = b[x];
    }
}

// MergeSort function to divide the array and call merge
void MergeSort(vector<int> &arr, int low, int high){
    if(low < high){
        int mid = floor((low + high) / 2);  // find middle index to divide the array
        MergeSort(arr, low, mid);  // recursively sort the left half
        MergeSort(arr, mid + 1, high);  // recursively sort the right half
        Merge(arr, low, mid, high);  // merge the two sorted halves
    }
}

int main(){
    // Example array to sort
    vector<int> arr = {5, 3, 9, 5, 2, 0, 4, 1};
    
    // Call MergeSort to sort the entire array
    MergeSort(arr, 0, arr.size() - 1);
    
    // Output the sorted array
    for(int a : arr){
        cout << a << " ";  // print each sorted element
    }
    return 0;
}