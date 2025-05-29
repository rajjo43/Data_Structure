#include <bits/stdc++.h>
using namespace std;

int passwordFunction(string password){
    
    bool hasUpper = false, hasLower = false, hasDigit = false, hasSpecial = false;
    string specialChars = ").,;:<>(";

    for(char ch : password){
        if(isupper(ch)){
            hasUpper = true;
        }else if(islower(ch)){
            hasLower = true;
        }else if(isdigit(ch)){
            hasDigit = true;
        }else if(specialChars.find(ch) != string :: npos){
            hasSpecial = true;
        }
    }

    if(password.length() >= 12 && hasUpper && hasLower && hasDigit && hasSpecial){
        return 1;
    }else{
        return -1;
    }
}

int main() {
    string password;
    cout << "Enter your password: ";
    getline(cin, password);

    if (passwordFunction(password) == 1)
        cout << "Password is strong.\n";
    else
        cout << "Password is weak. Please follow the password rules.\n";

    return 0;
}