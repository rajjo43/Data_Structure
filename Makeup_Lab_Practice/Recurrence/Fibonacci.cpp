#include <iostream>
using namespace std;

int fibonacci(int k){
    if(k == 0){
        return 0;
    }else if(k == 1){
        return 1;
    }else{
        return fibonacci(k - 1) + fibonacci(k -2);
    }
}

int main()
{
    int n;
    cout << "Enter n : ";
    cin >> n;
    for(int i = 0; i < n; i++){
        cout << fibonacci(i) << endl;
    }
    return 0;
}