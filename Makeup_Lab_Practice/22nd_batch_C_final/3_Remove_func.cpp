#include <iostream>
using namespace std;

// Function to remove the last occurrence of V
void remove(int A[], int N, int V) {
    int index = -1;

    // Find the last occurrence of V
    for (int i = 0; i < N; i++) {
        if (A[i] == V) {
            index = i;
        }
    }

    // If V is not found, do nothing
    if (index == -1) {
        cout << "Value " << V << " not found in the array." << endl;
        return;
    }

    // Shift elements to the left starting from the found index
    for (int i = index; i < N - 1; i++) {
        A[i] = A[i + 1];
    }

    // Set last element to 0
    A[N - 1] = 0;
}

int main() {
    int A[] = {4, 2, 5, 2, 9, 2, 7};
    int N = sizeof(A) / sizeof(A[0]);
    int V = 2;

    cout << "Original array: ";
    for (int i = 0; i < N; i++)
        cout << A[i] << " ";
    cout << endl;

    remove(A, N, V);

    cout << "Modified array: ";
    for (int i = 0; i < N; i++)
        cout << A[i] << " ";
    cout << endl;

    return 0;
}
