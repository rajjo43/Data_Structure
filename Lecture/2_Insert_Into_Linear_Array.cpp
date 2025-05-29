
#include <iostream>
using namespace std;

// Traverse function 
void traverse(int *arr, int len){
    for(int i = 0; i < len; i++){
        cout << arr[i] << " ";
    }
}

// Insertion function (for 1-based indexing)
void insert(int *arr, int &N, int pos, int ITEM){
    if (N >= 10) {
        cout << "Array is full, cannot insert!" << endl;
        return;
    }

    // Convert 1-based position to 0-based index for the array
    int j = N - 1;

    // Shift elements to the right to make space for the new item
    while (j >= pos - 1) {  // pos - 1 converts to 0-based index
        arr[j + 1] = arr[j];
        j--;
    }

    arr[pos - 1] = ITEM;  // pos - 1 to set the item at the correct index
    N = N + 1;  // Increase the size of the array
}

int main(){
    int N, pos, ITEM;
    int arr[10] = {1, 2, 3, 4, 5, 7, 8, 9, 10};  // Size of 10 with 9 elements

    N = 9;  // Number of elements in the array initially
    pos = 6;  // Inserting at position 6 (1-based index)
    ITEM = 6;  // Item to be inserted

    insert(arr, N, pos, ITEM);  // Insert ITEM at position pos
    traverse(arr, N);  // Display the updated array

    return 0;
}
