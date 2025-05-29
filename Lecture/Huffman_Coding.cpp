// #include <bits/stdc++.h>

// using namespace std;

// // Class to represent huffman tree
// class Node{
// public:
//     int data;
//     Node *left, *right;
//     Node(int x){
//         data = x;
//         left = nullptr;
//         right = nullptr;
//     }
// };

// // Custom min heap for Node class
// class Compare{
// public:
//     bool operator() (Node* a, Node* b){
//         return a->data > b->data;
//     }
// };

// // Function to traverse tree in preorder manner and push the huffman representation of each character
// void preorder(Node* root, vector<string> &ans, string curr){
//     if(root == nullptr)
//         return;
//     // Leaf node represents a character
//     if(root->left == nullptr && root->right == nullptr){
//         ans.push_back(curr);
//         return;
//     }

//     preorder(root->left, ans, curr + '0');
//     preorder(root->right, ans, curr + '1');
// }

// vector<string> huffmanCodes(string s, vector<int> freq){
//     int n = s.length();

//     // Min heap for node class
//     priority_queue<Node*, vector<Node*>, Compare> pq;
//     for(int i = 0; i < n; i++){
//         Node* tmp = new Node(freq[i]) ;
//         pq.push(tmp);
//     }

//     // Construct huffman tree
//     while(pq.size() >= 2){

//         // Left node
//         Node* l = pq.top();
//         pq.pop();

//         // Right node
//         Node* r = pq.top();
//         pq.pop();

//         Node* newNode = new Node(l->data + r->data);
//         newNode->left = l;
//         newNode->right = r;

//         pq.push(newNode);
//     }

//     Node* root = pq.top();
// 	vector<string> ans;
// 	preorder(root, ans, "");
// 	return ans;
// }

// int main() {
// 	string s = "abcdef";
// 	vector<int> freq = {5, 9, 12, 13, 16, 45};
// 	vector<string> ans = huffmanCodes(s, freq);
// 	for (int i=0; i< ans.size(); i++) {
// 	    cout << ans[i] << " ";
// 	}
	
// 	return 0;
// }



#include <bits/stdc++.h>
using namespace std;

// Node structure with character and frequency
class Node {
public:
    char ch;
    int data;
    Node *left, *right;

    Node(char c, int x) {
        ch = c;
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

// Comparator for priority queue (min-heap)
class Compare {
public:
    bool operator()(Node* a, Node* b) {
        return a->data > b->data;
    }
};

// Recursive function to generate Huffman codes
void preorder(Node* root, unordered_map<char, string>& codeMap, string curr) {
    if (root == nullptr)
        return;

    if (root->left == nullptr && root->right == nullptr) {
        codeMap[root->ch] = curr;
        return;
    }

    preorder(root->left, codeMap, curr + '0');
    preorder(root->right, codeMap, curr + '1');
}

// Function to compute average code length
double averageCodeLength(unordered_map<char, string>& codeMap, string s, vector<int>& freq) {
    int totalBits = 0, totalFreq = 0;

    for (int i = 0; i < s.length(); i++) {
        totalBits += freq[i] * codeMap[s[i]].length();
        totalFreq += freq[i];
    }

    return (double) totalBits / totalFreq;
}

// Main Huffman coding function
unordered_map<char, string> huffmanCodes(string s, vector<int> freq) {
    int n = s.length();

    priority_queue<Node*, vector<Node*>, Compare> pq;

    for (int i = 0; i < n; i++) {
        Node* tmp = new Node(s[i], freq[i]);
        pq.push(tmp);
    }

    // Build Huffman Tree
    while (pq.size() >= 2) {
        Node* l = pq.top(); pq.pop();
        Node* r = pq.top(); pq.pop();

        Node* newNode = new Node('$', l->data + r->data); // '$' as internal node
        newNode->left = l;
        newNode->right = r;

        pq.push(newNode);
    }

    Node* root = pq.top();
    unordered_map<char, string> codeMap;
    preorder(root, codeMap, "");

    return codeMap;
}

int main() {
    string s = "abcdef";
    vector<int> freq = {5, 9, 12, 13, 16, 45};

    unordered_map<char, string> codeMap = huffmanCodes(s, freq);

    cout << "Huffman Codes:\n";
    for (char c : s) {
        cout << c << ": " << codeMap[c] << "\n";
    }

    double avgLen = averageCodeLength(codeMap, s, freq);
    cout << "\nAverage Code Length: " << avgLen << " bits per character\n";

    return 0;
}
