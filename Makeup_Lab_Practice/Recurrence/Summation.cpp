#include <iostream>
using namespace std;

int sum(int k){
    if(k > 0){
        return k + sum(k - 1);
    }else{
        return 0;
    }
}

int main()
{
    int n;
    cout << "Enter how many numbers you want to add : ";
    cin >> n;

    int result = sum(n);
    cout <<"Summation of " << n << " numbers: " << result << endl;
    return 0;
}