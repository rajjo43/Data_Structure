// /* Following program is a C++ implementation of Rabin Karp
// Algorithm given in the CLRS book */
// /*
//     Input:  T[] = "THIS IS A TEST TEXT", P[] = "TEST"
//     Output: Pattern found at index 10

//     Input:  T[] =  "AABAACAADAABAABA", P[] =  "AABA"
//     Output: Pattern found at index 0
//                   Pattern found at index 9
//                   Pattern found at index 12
// */
// #include <bits/stdc++.h>
// using namespace std;

// // Search the pat string in the txt string 
// void search(string pat, string txt, int q)
// {
//     int M = pat.size();
//     int N = txt.size();
//     int i, j;
//     int p = 0; // hash value for pattern
//     int t = 0; // hash value for txt
//     int h = 1;
//     int d = 256; // d is the number of characters in the input alphabet 
//     // The value of h would be "pow(d, M-1)%q"
//     for (i = 0; i < M - 1; i++)
//         h = (h * d) % q;

//     // Calculate the hash value of pattern and first
//     // window of text
//     for (i = 0; i < M; i++) {
//         p = (d * p + pat[i]) % q;
//         t = (d * t + txt[i]) % q;
//     }

//     // Slide the pattern over text one by one
//     for (i = 0; i <= N - M; i++) {

//         // Check the hash values of current window of text
//         // and pattern. If the hash values match then only
//         // check for characters one by one
//         if (p == t) {
//             /* Check for characters one by one */
//             for (j = 0; j < M; j++) {
//                 if (txt[i + j] != pat[j]) {
//                     break;
//                 }
//             }

//             // if p == t and pat[0...M-1] = txt[i, i+1,
//             // ...i+M-1]

//             if (j == M)
//                 cout << "Pattern found at index " << i
//                      << endl;
//         }

//         // Calculate hash value for next window of text:
//         // Remove leading digit, add trailing digit
//         if (i < N - M) {
//             t = (d * (t - txt[i] * h) + txt[i + M]) % q;

//             // We might get negative value of t, converting
//             // it to positive
//             if (t < 0)
//                 t = (t + q);
//         }
//     }
// }

// /* Driver code */
// int main()
// {
//     string txt = "GEEKS FOR GEEKS";
//     string pat = "GEEK";

//     // we mod to avoid overflowing of value but we should
//     // take as big q as possible to avoid the collison
//     int q = INT_MAX;
//     // Function Call
//     search(pat, txt, q);
//     return 0;
// }



#include <iostream>
#include <sstream>
#include <string>
using namespace std;

void searchWordWithStringStream(string text, string pattern) {
    stringstream ss(text);
    string word;
    int index = 0;

    while (ss >> word) {
        if (word == pattern) {
            cout << "Pattern found at word index: " << index << endl;
        }
        index++;
    }
}

int main() {
    string text = "THIS IS A TEST TEXT";
    string pattern = "TEST";
    searchWordWithStringStream(text, pattern);
    return 0;
}
