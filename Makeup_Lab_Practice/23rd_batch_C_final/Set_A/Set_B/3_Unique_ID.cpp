// #include <bits/stdc++.h>
// using namespace std;

// string Student_ID(string id){
//     if(id.length() != 9 ){
//         return "Invalid ID length.";
//     }

//     string result = "Batch: ";
//     result += id.substr(0,2); // First 2 digits

//     string dept_code = id.substr(3,2); //4th and 5th digits
//     if (dept_code == "01") result += ", Department: MPE";
//     else if (dept_code == "02") result += ", Department: EEE";
//     else if (dept_code == "03") result += ", Department: WEI";
//     else if (dept_code == "04") result += ", Department: CSEI";
//     else if (dept_code == "05") result += ", Department: CSE";
//     else if (dept_code == "06") result += ", Department: BTM";
//     else result += ", Department: Unknown";

//     result += ", Section: ";
//     result += id[id.length() - 3]; // 3rd digit from the end

//     return result;
// }

// int main()
// {
//     string stdId;
//     cout << "Enter 9 digit student id: ";
//     cin >> stdId;
//     string result = Student_ID(stdId);
//     cout << result << endl;
// }

#include <iostream>
#include <map>
using namespace std;

int main() {
    string id;
    cout << "Enter 9 digit student ID: ";
    cin >> id;

    map<string, string> deptMap = {
        {"01", "MPE"}, {"02", "EEE"}, {"03", "WEI"},
        {"04", "CSEI"}, {"05", "CSE"}, {"06", "BTM"}
    };

    string batch = id.substr(0, 2);
    string dept_code = id.substr(3, 2);
    string section = string(1, id[6]);

    cout << "Batch: " << batch
         << ", Department: " << (deptMap.count(dept_code) ? deptMap[dept_code] : "Unknown")
         << ", Section: " << section << endl;

    return 0;
}
