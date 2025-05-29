#include <iostream>
using namespace std;

int Lines(int n){
    if(n==0){
        return 1;
    }
    else{
        return Lines(n-1)+n;
    }
}

int main(){
    int n;
    cout << "Number of Lines: ";
    cin >> n;
    cout << "Number of Pieces: " << Lines(n) << endl;
    cout << "Number of Pieces: " << (n*(n+1)/2) + 1;
}