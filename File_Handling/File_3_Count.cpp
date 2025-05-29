// Write a C++ program to count the number of lines and words in a text file.
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    ifstream inputfile("File3.txt");
    if(inputfile.is_open()){
        string line;
        int linecount = 0;
        int wordcount = 0;
        while(getline(inputfile, line)){
            cout << line << endl;
            linecount++;

            stringstream ss(line);
            string word;

            while(ss >> word){
                wordcount++;
            }
        }

        inputfile.close();

        cout << "Number of lines in the file: " << linecount << endl;
        cout << "Number of words in the said file: " << wordcount << endl;
    }else{
        cout << "Failed to open the file!";
    }
    return 0;
}