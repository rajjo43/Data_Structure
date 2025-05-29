#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int Josephus(int n){
    if(n==1){
        return 1;
    }
    else if(n%2==0){
        return 2*Josephus(n/2)-1;
    }
    else{
        return 2*Josephus((n-1)/2)+1;
    }
}

string bin(int n){
    if (n == 0) { 
        return "0000";  // Return a 4-bit "0000" for zero
    }

    string binNum = "";  // To store the binary representation

    // Recur for smaller bits
    while (n > 0) {
        binNum = to_string(n % 2) + binNum;
        n /= 2;
    }

    // Pad the string with leading zeros to ensure it's 4 bits
    while (binNum.size() < 4) {
        binNum = "0" + binNum;
    }

    // Only return the last 4 bits if the size exceeds 4
    if (binNum.size() > 4) {
        binNum = binNum.substr(binNum.size() - 4);
    }

    return binNum;
}

int dec(string n){

    string num = n;
    int dec_value = 0;

    int base = 1;

    int len = num.length();
    for (int i = len - 1; i >= 0; i--) {
        if (num[i] == '1'){
            dec_value += base;
        }
        base = base * 2;
    }
    
    return dec_value;
}

int J2(int n){
    string binNum = bin(n);
    int temp;
    for(int i = 1; i < sizeof(binNum); i++){
        temp = binNum[i-1];
        binNum[i-1] = binNum[i];
        binNum[i] = temp;
    }
    return dec(binNum);
}

int main(){
    int n;
    cout << "Number of Peaople: ";
    cin >> n;
    cout << "Survives: " << Josephus(n) << "(Recursive System)" << endl;
    cout << "Survives: " << J2(n) << "(Binary System)" << endl;
}