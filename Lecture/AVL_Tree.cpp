#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Node structure
struct Node{
    int key;
    Node* left;
    Node* right;
    int height;
};

// Get height of a node
int height(Node* node){
    return node ? node->height : 0;
}

// Get balance factor
int getBalance(Node* node){
    return node ? height(node->left) - height(node->right) : 0;
}

// Max of two integers
int max(int a, int b){
    return (a > b) ? a : b;
}

// Create a new node
Node* newNode(int key){
    Node* node = new Node();
    node->key = key;
    node->left = node->right = nullptr;
    node->height = 1;
    return node;
}

// Right rotate
Node* rightRotate(Node* y){
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

// Left rotate
Node* leftRotate(Node* x){
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    
    return y;
}

// Insert a node
Node* insert(Node* node, int key){
    if(!node)
        return newNode(key);
    if(key < node->key)
        node->left = insert(node->left, key);
    else if(key > node->key)
        node->right = insert(node->right, key);
    else
        return node; // Duplicate not allowed

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    // Balancing
    if(balance > 1 && key < node->left->key) // LL
        return rightRotate(node);
    if(balance < -1 && key > node->right->key) // RR
        return leftRotate(node);
    if(balance > 1 && key > node->left->key){ // LR
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if(balance < -1 && key < node->right->key){ // RL
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Get min value node
Node* minValueNode(Node* node){
    Node* current = node;
    while(current->left)
        current = current->left;
    return current;
}

// Delete a node
Node* deleteNode(Node* root, int key){
    if(!root)
        return root;
    if(key < root->key)
        root->left = deleteNode(root->left, key);
    else if(key > root->key)
        root->right = deleteNode(root->right, key);
    else{
        if(!root->left || !root->right){
            Node* temp = root->left ? root->left : root->right;
            if(!temp){
                temp = root;
                root = nullptr;
            }else{
                *root = *temp;
            }
            delete temp;
        }else{
            Node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    if(!root)
        return root;
    
    root->height = max(height(root->left), height(root->right)) + 1;
    int balance = getBalance(root);

    // Balancing
    if(balance > 1 && getBalance(root->left) >= 0){
        return rightRotate(root);
    }
    if(balance > 1 && getBalance(root->left) < 0){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if(balance < -1 && getBalance(root->right) <= 0){
        return leftRotate(root);
    }
    if(balance < -1 && getBalance(root->right) > 0){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// In-order traversal
void inOrder(Node* root){
    if(root){
        inOrder(root->left);
        cout << root->key << " ";
        inOrder(root->right);
    }
}

//  Level Order Traversal Function
void levelOrder(Node* root) {
    if (!root) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();

        while (levelSize--) {
            Node* current = q.front();
            q.pop();

            cout << current->key << " ";

            if (current->left)
                q.push(current->left);
            if (current->right)
                q.push(current->right);
        }
        cout << endl; // New line per level
    }
}


// Main function
int main()
{
    Node* root = nullptr;
    // Initial insertion
    int keys[] = {21, 26, 30, 9, 4, 14, 28, 18, 15, 10, 2, 3, 7};
    for(int key : keys){
        root = insert(root, key);
    }

    cout << "\nIn-order traversal of the AVL tree:\n";
    inOrder(root);
    cout << endl;

    cout << "\nLevel Order Traversal of AVL Tree:\n";
    levelOrder(root);  //  Calling level order function
    // cout << endl;

    // Delete node 30
    root = deleteNode(root, 30);
    cout << "\nDeleted 30\n";
    cout << "In-order traversal after deletion:\n";
    inOrder(root);
    cout << endl;

    // Ask user to insert new key
    char choice;
    cout << "\nDo you want to insert a new key? (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        int newKey;
        cout << "Enter the key to insert: ";
        cin >> newKey;
        root = insert(root, newKey);
        cout << "In-order traversal after inserting " << newKey << ":\n";
        inOrder(root);
        cout << endl;
    } else {
        cout << "No insertion performed.\n";
    }

    return 0;
}