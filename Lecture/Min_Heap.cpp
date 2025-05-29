#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class MinHeap{
private:
    vector<int> heap;

    // Move the element at index 'index' up to restore min heap property
    void heapify_Up(int index){
        while (index != 0 && heap[parent(index)] > heap[index]){
            swap(heap[parent(index)], heap[index]);
            index = parent(index);
        }
    }

    // Move the element at index 'index' down to restore min heap property
    void heapify_Down(int index){
        int smallest = index;
        int leftChild = left(index);
        int rightChild = right(index);

        // Check if left child is larger
        if(leftChild < heap.size() && heap[leftChild] < heap[smallest]){
            smallest = leftChild;
        }

        // Check if right child is larger
        if(rightChild < heap.size() && heap[rightChild] < heap[smallest]){
            smallest = rightChild;
        }

        // If largest is not current index, swap and continue heapifying down
        if(smallest != index){
            swap(heap[index], heap[smallest]);
            heapify_Down(smallest);
        }
    }

    // Return parent index of element at i
    int parent(int i){
        return (i - 1) / 2; // For 1-based indexing i/2
    }

    // Return left child index of element at i
    int left(int i){
        return 2 * i + 1;  // For 1-based indexing 2*i
    }

    // Return right child index of element at i
    int right(int i){
        return 2 * i + 2;  // For 1-based indexing 2*i+1
    }

public: 
    // Insert a new element into the heap
    void insertion(int value){
        heap.push_back(value);        // add element at the end
        heapify_Up(heap.size() - 1);  // restore heap property by moving up
    }

    // Delete the maximum element (root) from the heap
    void deletion(){
        if(heap.empty()){
            cout << "Heap is empty" << endl;
            return;
        }
        cout << "Deleted min: " << heap[0] << endl;
        heap[0] = heap.back();       // Move last element to root
        heap.pop_back();             // Remove last element
        heapify_Down(0);             // Restore heap property by moving down
    }

    // Display the elements in the heap
    void display(){
        if(heap.empty()){
            cout << "Heap is empty\n";
            return;
        }
        cout << "Min Heap: \n";
        for(int value : heap){
            cout << value << " ";
        }
        cout << endl;
    }

    // Check if heap is empty
    bool isEmpty(){
        return heap.empty();
    }
};

int main()
{
    MinHeap h;
    int n, value;
    char choice;

    cout << "Enter the no of elements you want to insert: ";
    cin >> n;

    cout << "Enter " << n << " elements: \n";
    for(int i = 0; i < n; i++){
        cin >> value;
        h.insertion(value);
    }

    h.display();

    // Loop to interactively delete max and insert elements
    while(true){
        cout << "\nDo you want to delete the min element? (y/n): ";
        cin >> choice;
        if(choice == 'y' ||  choice == 'Y'){
            h.deletion();
            h.display();
        }else{
            cout << "Skipping deletion.\n";
        }

        cout << "\nDo you want to insert a new element? (y/n): ";
        cin >> choice;
        if(choice == 'y' || choice == 'Y'){
            cout << "Enter the value to insert: ";
            cin >> value;
            h.insertion(value);
            h.display();
        }else{
            cout << "Skipping insertion.\n";
        }

        cout << "\nDo you want to continue? (y/n): ";
        cin >> choice;
        if (!(choice == 'y' || choice == 'Y'))
            break;    

    }
    cout << "\nProgram Ended!";

}