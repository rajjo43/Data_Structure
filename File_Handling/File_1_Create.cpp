// Write a C++ program to create a new text file and write some text into it. 
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream file1("File1.txt"); // Open or create a file for writing

    if(file1.is_open()){
        file1 << "This is the first file1 for the file handling" << endl;
        file1 << "Wishing you best for your learning of  file handling" << endl;
        file1 << "Fighting !";

        file1.close();
        cout << "Text has been written to the file !";
    }else{
        cout << "Failed to create the file" << endl;
    }

    return 0;
}