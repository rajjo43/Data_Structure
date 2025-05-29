#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> subsets;

void generate(vector<int>& subset, int i, vector<int>& nums) {
    if(i == nums.size()) {
        subsets.push_back(subset);
        return;
    }

    // Do not include the ith element in the subset
    generate(subset, i+1, nums);

    // Include the ith element in the subset
    subset.push_back(nums[i]);
    generate(subset, i+1, nums);
    subset.pop_back(); // Backtrack
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> empty;
    generate(empty, 0, nums);

    // Output all the subsets
    for(auto subset : subsets) {
        for(auto ele : subset) {
            cout << ele << " ";
        }
        cout << endl;
    }

    return 0;
}
