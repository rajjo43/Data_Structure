#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x, y;
    string commands;
    cout << "Enter x & y: ";
    cin >> x >> y;
    cout << "Enter commands: ";
    cin >> commands;

    for(char c : commands){
        if(c == 'U'){
            y++;
        }else if(c == 'D'){
            y--;
        }else if(c == 'R'){
            x++;
        }else if(c == 'L'){
            x--;
        }
    }

    cout << x << " " << y << endl;

}
