// Write a C++ program to append new data to an existing text file.
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function to display the content of a file
void displayContent(const string & filename){
    ifstream inputfile(filename);
    string line;

    if(inputfile.is_open()){
        cout << "File content : "<< endl;
        while(getline(inputfile, line)){
            cout << line << endl;
        }
        inputfile.close();
    }else{
        cout << "Failed to open the file!";
    }
}

int main()
{
    displayContent("File6.txt");
    cout << endl;

    ofstream outputfile;
    outputfile.open("File6.txt", ios :: app);// outputfile.open("File6.txt");---> it will overwrites the file

    if(outputfile.is_open()){
        string newData;

        cout << "Enter the data to append: ";
        getline(cin, newData);

        // Append the new data to the file
        outputfile << newData << endl;
        outputfile.close();

        cout << "Data appended successfully!" << endl;
        displayContent("File6.txt");
        cout << endl;
    }else{
        cout << "Failed to open the file! ";
    }
    return 0;
}