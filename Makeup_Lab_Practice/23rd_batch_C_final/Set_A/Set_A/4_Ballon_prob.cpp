#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
    set<string> balloonColors;
    string color;
    int totalBalloons;

    cout << "Enter number of balloons received: ";
    cin >> totalBalloons;

    for (int i = 0; i < totalBalloons; ++i) {
        cout << "Enter color of balloon " << (i + 1) << ": ";
        cin >> color;
        balloonColors.insert(color);  // Stores only unique colors
    }

    cout << "\nYou have balloons of " << balloonColors.size() << " different colors.\n";

    cout << "Colors collected:\n";
    for (const auto& c : balloonColors) {
        cout << "- " << c << "\n";
    }

    return 0;
}
