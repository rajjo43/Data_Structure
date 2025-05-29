#include <iostream>
using namespace std;

// Function to check if x is k-smooth
int kSmooth(int x, int k) {
    if (x == 1) return 1;

    // Divide x by all prime factors
    for (int i = 2; i <= x; i++) {
        // Check if i is a factor of x
        if (x % i == 0) {
            // Check if i is prime
            bool isPrime = true;
            for (int j = 2; j * j <= i; j++) {
                if (i % j == 0) {
                    isPrime = false;
                    break;
                }
            }
            // If i is a prime and greater than k, x is not k-smooth
            if (isPrime && i > k) {
                return 0;
            }
        }
    }

    return 1; // x is k-smooth
}

int main() {
    int x, k;

    cout << "Enter number x: ";
    cin >> x;
    cout << "Enter maximum prime factor k: ";
    cin >> k;

    if (kSmooth(x, k))
        cout << x << " is " << k << "-smooth." << endl;
    else
        cout << x << " is NOT " << k << "-smooth." << endl;

    return 0;
}
