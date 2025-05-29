#include <iostream>
#include <math.h>
using namespace std;

int binary_To_decimal(string binary){
    int decimal = 0;
    int power = 0;

    for(int i = binary.length() - 1; i >= 0; i--){
        if(binary[i] == '1'){
            decimal += pow(2, power);
        }
        power++;
    }
    return decimal;
}

int main()
{
    string binary;
    cout << "Enter the binary number: ";
    cin >> binary;
    int result = binary_To_decimal(binary); // store result
    cout << "Decimal: " << result << endl;  
    return 0;
}