#include <iostream>
using namespace std;

void decimal_To_binary(int n){
    int remainder = 0;
    if (n == 0) {
        return;
    } else {
        remainder = n % 2;
        decimal_To_binary(n / 2);
        cout << remainder;
    }
}

int main()
{
    int n;
    cout <<"Enter a decimal number: ";
    cin >> n;

    if (n == 0)
        cout << 0;
    else
        decimal_To_binary(n);

    cout << endl;
    return 0;
}
