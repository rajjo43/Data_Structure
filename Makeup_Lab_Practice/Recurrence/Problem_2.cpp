/*
“Currently the fuel oil price in Bangladesh is 135BDT per liter.
Following the last few years, it seems that the price is yielding 51.68% per year.
Estimate the plausible price of oil after 7 years.”
Pn = 1.5168P(n-1) = (1.5168)^(n)P0
*/

#include <iostream>
#include <math.h>
using namespace std;

float price(int year, int amount){
    int price = amount;
    return pow(1.5168, year) * price;
}

int main()
{
    int year;
    int  oil_price;
    cout <<"Enter the price of fuel: ";
    cin >> oil_price;
    cout << "Enter the year: ";
    cin >> year;

    float result = price(year,oil_price );
    cout << "Oil price after " << year << " years: " << result << endl;
    return 0;

}