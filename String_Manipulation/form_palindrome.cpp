// C++ approach to find Minimum 
// insertions to form a palindrome
#include<bits/stdc++.h>
using namespace std;

// Recursive function to find  
// minimum number of insertions
int minRecur(string &s, int l, int h) {
  
  	// Base case
    if (l >= h) return 0;
  
  	// if first and last char are same 
  	// then no need to insert element
  	if(s[l] == s[h]) {
      	return minRecur(s, l + 1, h - 1);
    }
  
  	// Insert at begining or insert at end
  	return min(minRecur(s, l + 1, h), 
               minRecur(s, l, h - 1)) + 1;
}

int findMinInsertions(string &s) {
 	return minRecur(s, 0, s.size() - 1);
}

int main() {
    string s = "geeks";
    cout << findMinInsertions(s);
    return 0;
}