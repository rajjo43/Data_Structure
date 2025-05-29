// Write a C++ program to find and replace a specific word in a text file.
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
    ifstream inputfile("File4.txt");
    ofstream outputfile("File5.txt");

    if(inputfile.is_open() && outputfile.is_open()){
        string line;
        string searchWord = "bruhhhhh";
        string replaceWord = "bro";

        cout << "Search Word: " << searchWord << endl;
        cout << "Replace Word: " << replaceWord << endl;

        cout << "Before find and Replace: "<< endl;
        displayContent("File4.txt");

        while(getline(inputfile, line)){
            size_t position = line.find(searchWord); // Or auto position = line.find(searchWord);

            while(position != string :: npos){
                line.replace(position, searchWord.length(), replaceWord);
                position = line.find(searchWord, position + replaceWord.length());
            }
            outputfile << line << endl;
        }
        inputfile.close();
        outputfile.close();

        cout << "After find and replace: " << endl;
        displayContent("File5.txt");

        cout << "Word Replaced Successfully!" << endl;
    }else{
        cout << "Failed to open the file! ";
    }
    return 0;
}