#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

// Function to write averages to file
void writeReport(const string &filename, const vector<double> &data, const vector<int> &dayCounts, int districtCount)
{
    ofstream outfile(filename);
    if (!outfile)
    {
        cerr << "Error opening output file: " << filename << "\n";
        return;
    }
    outfile << fixed << setprecision(2);
    for (int i = 0; i < districtCount; i++)
    {
        double avg = dayCounts[i] ? data[i] / dayCounts[i] : 0.0;
        outfile << (i + 1) << " " << avg << "\n";
    }
    outfile.close();
}

int main()
{
    const int districtCount = 64;
    const int daysInYear = 365;

    vector<double> temperatureData(districtCount, 0.0);
    vector<double> humidityData(districtCount, 0.0);
    vector<double> rainData(districtCount, 0.0);
    vector<int> dayCounts(districtCount, 0);

    ifstream infile("data.txt");
    if (!infile)
    {
        cerr << "Error opening input file.\n";
        return 1;
    }

    int districtId, dayOfYear;
    double temperature, humidity, rain;

    while (infile >> districtId >> dayOfYear >> temperature >> humidity >> rain)
    {
        int idx = districtId - 1; // zero-based index
        temperatureData[idx] += temperature;
        humidityData[idx] += humidity;
        rainData[idx] += rain;
        dayCounts[idx]++;
    }
    infile.close();

    // Check if all districts have 365 days of data
    // for (int i = 0; i < districtCount; i++)
    // {
    //     if (dayCounts[i] != daysInYear)
    //     {
    //         cerr << "Warning: District " << (i + 1) << " has " << dayCounts[i] << " days of data, expected " << daysInYear << ".\n";
    //     }
    // }

    writeReport("temperature.txt", temperatureData, dayCounts, districtCount);
    writeReport("humidity.txt", humidityData, dayCounts, districtCount);
    writeReport("rain.txt", rainData, dayCounts, districtCount);

    cout << "Reports generated successfully.\n";

    return 0;
}
