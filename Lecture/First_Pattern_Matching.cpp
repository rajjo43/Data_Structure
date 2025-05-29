
#include <iostream>
#include <string>
using namespace std;

int First_Pattern_Matching(const string &P, const string &T) {
    int R = P.length();
    int S = T.length();
    int MAX = S - R + 1;
    int K = 1, INDEX = -1;  // Start K from 1 for 1-based indexing

    while (K <= MAX) {  // Loop with 1-based indexing
        int count = 0;
        for (int L = 0; L < R; L++) {  // Use 0-based indexing for P
            if (P[L] != T[K + L - 1]) {  // Adjust indexing for 1-based K
                break;
            }
            count++;
        }

        if (count == R) {
            INDEX = K;  // Return 1-based index
            return INDEX;  // Successful match found
        }
        K++;  // Move to the next character in T
    }
    return INDEX;  // Return -1 if pattern not found
}

int main() {
    string P, T;
    cout << "Enter the string T: ";
    getline(cin, T);
    cout << "Enter the pattern you want to match P: ";
    getline(cin, P);

    int index = First_Pattern_Matching(P, T);

    if (index != -1) {
        cout << "Pattern matched at index " << index << endl;
    } else {
        cout << "Pattern not found" << endl;
    }

    return 0;
}
