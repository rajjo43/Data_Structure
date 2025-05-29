#include<bits/stdc++.h>
using namespace std;

// Function to perform Selection Sort on the array
void SelectionSort(vector<int> &arr){
    int temp, min;
    
    // Outer loop to traverse through the entire array
    for(int i = 0; i < arr.size(); i++){
        min = i;  // Assume the minimum element is at the current index
        
        // Inner loop to find the index of the smallest element in the unsorted part
        for(int j = i + 1; j < arr.size(); j++){
            if(arr[j] < arr[min]){
                min = j;  // Update the minimum index if a smaller element is found
            }
        }
        
        // If the minimum element is not already in the correct position, swap it
        if(min != i){
            temp = arr[i];  // Temporarily store the element at index i
            arr[i] = arr[min];  // Place the smallest element at index i
            arr[min] = temp;  // Place the previously stored element at index min
        }
    }
}

int main(){
    // Example array to sort
    vector<int> arr = {5, 3, 9, 5, 2, 0, 4, 1};
    
    // Call SelectionSort to sort the array
    SelectionSort(arr);
    
    // Print the sorted array
    for(int a: arr){
        cout << a << " ";  // Output each element of the sorted array
    }
    
    return 0;
}