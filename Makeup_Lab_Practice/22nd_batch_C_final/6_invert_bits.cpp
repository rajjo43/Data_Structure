#include <iostream>
#include <vector>
using namespace std;

// Function to swap consecutive bits
unsigned int swap_consecutive_bits(unsigned int x) {
    unsigned int even_bits = x & 0xAAAAAAAA; // mask even bits
    unsigned int odd_bits  = x & 0x55555555; // mask odd bits
    
    even_bits >>= 1; // shift even bits right
    odd_bits <<= 1;  // shift odd bits left
    
    return (even_bits | odd_bits);
}

// Helper to print 32-bit number in spaced 4-bit groups
void print_binary_32(unsigned int x) {
    for (int i = 31; i >= 0; i--) {
        cout << ((x >> i) & 1);
        if (i % 4 == 0) cout << " ";
    }
    cout << endl;
}

int main() {
    cout << "Enter 32 bits (space or no space):" << endl;
    string bits;
    cin >> bits;
    
    // Convert string bits to unsigned int
    if (bits.length() != 32) {
        cout << "Please enter exactly 32 bits." << endl;
        return 1;
    }
    
    unsigned int x = 0;
    for (char c : bits) {
        if (c != '0' && c != '1') {
            cout << "Invalid bit detected." << endl;
            return 1;
        }
        x = (x << 1) | (c - '0');
    }
    
    cout << "Original: ";
    print_binary_32(x);
    
    unsigned int swapped = swap_consecutive_bits(x);
    
    cout << "Swapped : ";
    print_binary_32(swapped);
    
    return 0;
}
