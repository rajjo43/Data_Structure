#include <iostream>
using namespace std;

int main() {
    char str[26];  // max 25 chars + 1 for null terminator
    char c;

    // Input: string and character separated by space
    cin >> str >> c;

    int i = 0, j = 0;
    // Loop through str, copy only chars that are NOT equal to c
    while (str[i] != '\0') {
        if (str[i] != c) {
            str[j] = str[i];
            j++;
        }
        i++;
    }
    // Null terminate the new string
    str[j] = '\0';

    cout << str << endl;

    return 0;
}
