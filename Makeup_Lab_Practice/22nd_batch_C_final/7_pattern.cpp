#include <iostream>
#include <iomanip>  // for setw
using namespace std;

int main() {
    int n;
    cout << "Enter value of n: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j < n - i - 1)
                cout << setw(3) << 1;
            else if (j == n - i - 1)
                cout << setw(3) << 0;
            else
                cout << setw(3) << -1;
        }
        cout << endl;
    }

    return 0;
}
