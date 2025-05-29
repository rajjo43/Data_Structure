// Write a C++ program to merge multiple text files into a single file.
#include <iostream>
#include <bits/stdc++.h>
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

int main()
{
    vector <string> inputfiles = {
        "File1.txt",
        "File2.txt",
        "File3.txt"
    };

    cout << "Content of File 1, 2, 3 : " << endl;
    displayContent("File1.txt");
    displayContent("File2.txt");
    displayContent("File3.txt");

    ofstream outputfile("File8.txt");

    if(outputfile.is_open()){
        for(const auto & inputfile : inputfiles){
            ifstream inputfileStream(inputfile);

            if(inputfileStream.is_open()){
                string line;
                while(getline(inputfileStream, line)){
                    outputfile << line << endl;
                }
                inputfileStream.close();
            }else{
                cout << "Failed to open the file" << inputfile << endl;
            }
        }

        outputfile.close();
        cout << "Files merged successfully." << endl;
        cout << "Content of the merged file: " << endl;
        displayContent("File8.txt");
    }else{
        cout << "Failed to open the output file";
    }
    return 0;
}