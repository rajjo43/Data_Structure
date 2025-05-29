// Write a C++ program to open an existing text file and display its contents on the console
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream inputfile("File2.txt"); // Opening the already existing file
    if(inputfile.is_open()){
        string line;
        while(getline(inputfile, line)){
            cout << line << endl;
        }

        inputfile.close();
    }else{
        cout << "Failed to open the file! ";
    }
    return 0;
}