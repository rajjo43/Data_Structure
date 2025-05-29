
#include <iostream>
using namespace std;

// Length function
int getLength(const string &str) {
    return str.length();
}

// Substring function
string getSubstring(const string &str, int initial, int len) {
    if (initial < 1 || initial > str.length()) return "";
    return str.substr(initial - 1, len);
}

// Index function
int getIndex(const string &str1, const string &str2) {
    size_t found = str1.find(str2);
    return (found != string::npos) ? found + 1 : -1; // Return 1-based index
}

// Concatenation function
string getConcatenation(const string &str1, const string &str2) {
    return str1 + str2;
}

// Insertion function
string getInsertion(const string &str1, int pos, const string &str2) {
    if (pos < 1 || pos > getLength(str1) + 1) return str1;
    return str1.substr(0, pos - 1) + str2 + str1.substr(pos - 1);
}

// Deletion function
string getDelete(const string &str1, int pos, int len) {
    if (pos < 1 || pos > str1.length()) return str1;
    return str1.substr(0, pos - 1) + str1.substr(pos - 1 + len);
}

// Replacement function
string getReplace(string str, const string &pattern1, const string &pattern2) {
    size_t pos = str.find(pattern1);
    while (pos != string::npos) {
        str.replace(pos, pattern1.length(), pattern2);
        pos = str.find(pattern1, pos + pattern2.length());
    }
    return str;
}

int main() {
    cout << "String Operations--------->" << endl;
    cout << "Enter String:" << endl;
    string str;
    getline(cin, str);

    string str1 = "He is wearing black shirt";
    string str2 = "ing";

    cout <<"str1 = " << str1 << endl << " str2 =" << str2 << endl;
    cout << "1) Length: " << getLength(str) << endl;
    cout << "2) Substring(str, 2, 3): " << getSubstring(str, 2, 3) << endl;
    cout << "3) Indexing(str1, str2): " << getIndex(str1, str2) << endl;
    cout << "4) Concatenation(str1, str2): " << getConcatenation(str1, str2) << endl;
    cout << "5) Insertion(Herld, 3, llo Wo): " << getInsertion("Herld", 3, "llo Wo") << endl;
    cout << "6) Deletion(ABCDEF, 1, 4): " << getDelete("ABCDEF", 1, 4) << endl;
    cout << "7) Replacement(Hello World, World, Rajjo): " << getReplace("Hello World", "World", "Rajjo") << endl;

    return 0;
}
