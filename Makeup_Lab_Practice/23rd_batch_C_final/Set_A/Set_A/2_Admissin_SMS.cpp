#include <iostream>
#include <sstream>
#include <vector>
#include <cctype>

using namespace std;

bool isValidBoard(const string& board) {
    if (board.length() != 3) return false;
    for (int i = 0; i < 3; i++) {
        if (!isupper(board[i]) || !isalpha(board[i])) {
            return false;
        }
    }
    return true;
}

bool isNumber(const string& str) {
    if (str.empty()) return false;
    for (char c : str) {
        if (!isdigit(c)) return false;
    }
    return true;
}

int toInt(const string& str) {
    int num = 0;
    for (char c : str) {
        num = num * 10 + (c - '0');
    }
    return num;
}

int validate(const string& sms) {
    stringstream iss(sms);
    vector<string> parts;
    string word;

    while (iss >> word) {
        parts.push_back(word);
    }

    if (parts.size() != 7) return 0;

    string cu = parts[0];
    string hsc_board = parts[1];
    string hsc_roll = parts[2];
    string hsc_year_str = parts[3];
    string ssc_board = parts[4];
    string ssc_roll = parts[5];
    string ssc_year_str = parts[6];

    if (cu != "CU") return 0;

    if (!isValidBoard(hsc_board) || !isValidBoard(ssc_board)) return 0;

    if (!isNumber(hsc_year_str) || !isNumber(ssc_year_str)) return 0;

    int hsc_year = toInt(hsc_year_str);
    int ssc_year = toInt(ssc_year_str);

    if (hsc_year - ssc_year < 2) return 0;

    return 1;
}

int main() {
    string sms1 = "CU CTG 216754 2018 CTG 206543 2016";
    string sms2 = "CU CTG 216754 2017 CTG 206543 2016";

    cout << validate(sms1) << endl;  // Output: 1
    cout << validate(sms2) << endl;  // Output: 0

    return 0;
}
