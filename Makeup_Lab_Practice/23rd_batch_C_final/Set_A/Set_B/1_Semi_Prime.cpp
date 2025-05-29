#include <iostream>
using namespace std;

bool isPrime(int num) {
    if(num <= 1) 
        return false;
    for(int i = 2; i*i <= num; i++) {
        if(num % i == 0) 
            return false;
    }
    return true;
}

bool isSemiPrime(int num) {
    for(int i = 2; i <= num/2; ++i) {
        if(num % i == 0) {
            int j = num / i;
            if(isPrime(i) && isPrime(j)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    if(isSemiPrime(n)){
        cout << n <<" is a semiprime" << endl;
    }else{
        cout << n << " is not a semiprime" << endl;
    }
}
