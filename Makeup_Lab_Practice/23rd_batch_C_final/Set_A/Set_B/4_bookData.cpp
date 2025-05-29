#include <bits/stdc++.h>
using namespace std;

int main()
{
    string course, maxcourse;
    int numBooks, maxBooks = -1;
    ifstream inputfile("Sample_Input_File.txt");
    ofstream outputfile("Sample_Output_File.txt");
    if(!inputfile.is_open()){
        cout << "Error ! Failed to open the file";
    }else{
        while(inputfile >> course >> numBooks){
            if(numBooks > maxBooks){
                maxBooks = numBooks;
                maxcourse = course;
            }
        }

        if(outputfile.is_open()){
            outputfile << maxcourse << " " << maxBooks << endl;
        }else{
            cout << "Failed to open the output file";
        }

        cout << "Output file created successfully";
        inputfile.close();
        outputfile.close();
        return 0;

    }

}