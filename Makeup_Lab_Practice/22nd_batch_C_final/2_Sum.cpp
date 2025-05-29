#include <iostream>
using namespace std;

int main() {
    int a, n, sum = 0;

    // Input values
    cout << "Enter value for a: ";
    cin >> a;

    cout << "Enter value for n: ";
    cin >> n;

    // Loop through 0 to n
    for (int i = 0; i <= n; i++) {
        int term = (a - i) * (a - i); // (a - i)^2

        if (i % 2 == 0) {
            sum += term;
        } else {
            sum -= term;
        }
    }

    // Output result
    cout << "The result of the series is: " << sum << endl;

    return 0;
}
