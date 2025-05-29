#include <iostream>
#include <math.h>
using namespace std;

int Hanoi(int n){
    if(n==1){
        return 1;
    }
    else{
        return 2*Hanoi(n-1)+1;
    }
}

int main(){
    int n;
    cout << "Number of Disks: ";
    cin >> n;
    cout << "Number of Moves: " << Hanoi(n) << endl;
    cout << "Number of Moves: " << pow(2, n) - 1;
}