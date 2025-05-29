#include<bits/stdc++.h> 
using namespace std;

// Function to traverse and print the array
void traverse(vector<int> &arr){
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";  // Output each element of the array
    } 
}

// InsertionSort function to sort the array using the insertion sort algorithm
void InsertionSort(vector<int> &arr){
    int value = 0, j = 0;
    // Start from the second element (index 1) since the first element is already "sorted"
    for(int i = 1; i < arr.size(); i++){
        value = arr[i];  // Store the current element to be inserted
        j = i - 1;  // Set j to the previous element
        
        // Shift elements to the right to make room for the current element
        // Continue shifting while j is valid and the element at arr[j] is greater than value
        while(j >= 0 && arr[j] > value){
            arr[j + 1] = arr[j];  // Move the larger element one position to the right
            j--;  // Move to the next left element
        }
        
        // Place the value in its correct position in the sorted part of the array
        arr[j + 1] = value;
    }
}

int main(){
    // Example array to sort
    vector<int> arr = {77, 42, 35, 12, 101, 5};
    
    // Call InsertionSort to sort the array
    InsertionSort(arr);
    
    // Print the sorted array using the traverse function
    traverse(arr);
    
    return 0;
}