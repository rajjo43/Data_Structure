// Write a C++ program to sort the lines of a text file in alphabetical order.
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

// Function to display the content of a file
void displayContent(const string &filename) {
    ifstream inputfile(filename);
    string line;

    if (inputfile.is_open()) {
        cout << "File content (" << filename << "):" << endl;
        while (getline(inputfile, line)) {
            cout << line << endl;
        }
        inputfile.close();
    } else {
        cout << "Failed to open the file: " << filename << endl;
    }
}

int main() {
    // Display original content
    displayContent("File7.txt");

    // Open files
    ifstream inputfile("File7.txt");
    ofstream outputfile("File7_sort.txt");

    if (inputfile.is_open() && outputfile.is_open()) {
        vector<string> lines;
        string line;

        // Read lines into vector
        while (getline(inputfile, line)) {
            lines.push_back(line);
        }

        // Case-insensitive alphabetical sort
        sort(lines.begin(), lines.end(), [](const string &a, const string &b) {
            string a_lower = a, b_lower = b;
            transform(a_lower.begin(), a_lower.end(), a_lower.begin(), ::tolower);
            transform(b_lower.begin(), b_lower.end(), b_lower.begin(), ::tolower);
            return a_lower < b_lower;
        });

        // Write sorted lines to output file
        copy(lines.begin(), lines.end(), ostream_iterator<string>(outputfile, "\n"));

        inputfile.close();
        outputfile.close();

        cout << "Lines sorted successfully!" << endl;

        // Display sorted content
        displayContent("File7_sort.txt");
    } else {
        cout << "Failed to open input/output file!" << endl;
    }

    return 0;
}
