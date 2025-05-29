// #include <iostream>
// #include <vector>

// using namespace std;

// int main() {
//     int n;
//     cin >> n;
//     vector<int> arr(n);

//     for(int i = 0; i < n; i++)
//         cin >> arr[i];


//     //Check first half with 2nd half
//     for(int i = 0; i < n / 2; i++) {
//         if(arr[i] != arr[n - i - 1]) {
//             cout << "No" << endl;
//             return 0;
//         }
//     }

//     cout << "Yes" << endl;
//     return 0;
// }

#include <iostream>
#include <vector>
using namespace std;

bool isPalindrome(vector<int> &arr, int left, int right) {
    // Base case: if left index crosses right, it's a palindrome
    if (left >= right) 
        return true;
    
    // If mismatch found, return false
    if (arr[left] != arr[right]) 
        return false;

    // Recursive call to check the inner subarray
    return isPalindrome(arr, left + 1, right - 1);
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) 
        cin >> arr[i];

    if (isPalindrome(arr, 0, n - 1))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
