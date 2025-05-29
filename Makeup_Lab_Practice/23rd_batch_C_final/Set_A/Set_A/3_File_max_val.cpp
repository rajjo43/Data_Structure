#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream file("Input.txt");
    string line;

    if (!file.is_open()) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    while (getline(file, line)) {
        stringstream ss(line);
        string number;
        int maxNum = INT_MIN;

        while (getline(ss, number, ',')) {
            int num = stoi(number);
            maxNum = max(maxNum, num);
        }

        cout << maxNum << endl;
    }

    file.close();
    return 0;
}