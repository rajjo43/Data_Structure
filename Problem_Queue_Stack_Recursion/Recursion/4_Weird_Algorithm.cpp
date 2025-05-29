#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
    ll n;
    cin >> n;
    while( n != 1){
        cout << n << " ";
        if(n & 1)  //bitwise operation that checks if it is odd or not
            n = 3ll*n + 1;  //writing 3ll ensures that multiplication will be done in long long int type
        else
            n /= 2ll;
    }
    cout << n << "\n";
    return 0;
}