#include <iostream>
using namespace std;

// Function to compute f(n)
int f(int n) {
    if (n == 0)
        return 1;
    return n * f(n - 1) + n;
}

// Function to check if x is in the series
int Check(int x) {
    int n = 0;
    while (true) {
        int val = f(n);
        if (val == x)
            return 1; // x is in the series
        if (val > x)
            return 0; // x cannot be in the series
        n++;
    }
}

int main() {
    cout << "Check(88): " << Check(88) << endl; // Should print 1
    cout << "Check(50): " << Check(50) << endl; // Should print 0
    return 0;
}
