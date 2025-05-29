/*
Someone deposits $10,000 in a savings account at a bank yielding 5% per year with interest compounded annually.
How much money will be in the account after 30 years?
Pn = 1.05P(n-1) = (1.05)^(n)P0
*/

#include <iostream>
#include <math.h>
using namespace std;

float savings(int year, int amount){
    int deposits = amount;
    return pow(1.05, year) * deposits;
}

int main()
{
    int year;
    int  deposit_money;
    cout <<"Enter the money you want to deposit: ";
    cin >> deposit_money;
    cout << "Enter the year for how long you want to save: ";
    cin >> year;

    float result = savings(year, deposit_money);
    cout << "Savings after " << year << " years: " << result << endl;
    return 0;

}