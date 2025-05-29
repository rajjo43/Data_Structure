// Write a C++ program to copy the contents of one text file to another.
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream inputfile("File3.txt");
    ofstream outputfile("File4.txt");

    if(inputfile.is_open() && outputfile.is_open()){
        string line;
        while(getline(inputfile, line)){
            outputfile << line << endl;
        }

        inputfile.close();
        outputfile.close();

        cout << "File copied successfully!";
    }else{
        cout << "Failed to open the file! ";
    }
    return 0;
}