#include <iostream>
using namespace std;

// Node Structure
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

// Insert a new value into the BST
Node* insert_BST(Node* root, int value) {
    if (root == NULL) {
        // Tree is empty, create new root
        return new Node(value);
    }

    if (value < root->data) {
        // Insert in the left subtree
        root->left = insert_BST(root->left, value);
    } else if (value > root->data) {
        // Insert in the right subtree
        root->right = insert_BST(root->right, value);
    }

    return root; // Return unchanged root pointer
}

// Find minimum value node in BST (used for deletion)
Node* findMin(Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

// Delete a node from BST
Node* deleteNode(Node* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node found
        // Case 1 and 2: node with 0 or 1 child
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: node with 2 children
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Inorder traversal (sorted order)
void inorder(Node* root) {
    if (root == nullptr) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = nullptr;
    int n, val;

    cout << "Enter number of elements to insert: ";
    cin >> n;

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; ++i) {
        cin >> val;
        root = insert_BST(root, val);
    }

    cout << "BST created successfully.\n";

    cout << "Inorder (sorted): ";
    inorder(root);
    cout << endl;

    int delVal;
    cout << "Enter value to delete: ";
    cin >> delVal;

    root = deleteNode(root, delVal);

    cout << "Inorder after deletion: ";
    inorder(root);
    cout << endl;

    return 0;
}





/*
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Node Structure
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

// Insert a new value into the BST
Node* insert_BST(Node* root, int value) {
    if (root == NULL) {
        // Tree is empty, create new root
        return new Node(value);
    }

    if (value < root->data) {
        // Insert in the left subtree
        root->left = insert_BST(root->left, value);
    } else if (value > root->data) {
        // Insert in the right subtree
        root->right = insert_BST(root->right, value);
    }

    return root; // Return unchanged root pointer
}

// Find minimum value node in BST (used for deletion)
Node* findMin(Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

// Delete a node from BST
Node* deleteNode(Node* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node found
        // Case 1 and 2: node with 0 or 1 child
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: node with 2 children
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Inorder traversal (sorted order)
void inorder(Node* root) {
    if (root == nullptr) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Print BST like an array using level-order traversal
void printBSTasArray(Node* root) {
    if (root == NULL) {
        cout << "BST as array (level-order): []" << endl;
        return;
    }

    queue<Node*> q;
    q.push(root);

    vector<int> bstArray;

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        bstArray.push_back(current->data);

        if (current->left != NULL)
            q.push(current->left);
        if (current->right != NULL)
            q.push(current->right);
    }

    // Print array-like output
    cout << "BST as array (level-order): [";
    for (size_t i = 0; i < bstArray.size(); ++i) {
        cout << bstArray[i];
        if (i != bstArray.size() - 1)
            cout << ", ";
    }
    cout << "]" << endl;
}

// Main function
int main() {
    Node* root = nullptr;
    int n, val;

    cout << "Enter number of elements to insert: ";
    cin >> n;

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; ++i) {
        cin >> val;
        root = insert_BST(root, val);
    }

    cout << "BST created successfully.\n";

    cout << "Inorder (sorted): ";
    inorder(root);
    cout << endl;

    printBSTasArray(root);

    int delVal;
    cout << "Enter value to delete: ";
    cin >> delVal;

    root = deleteNode(root, delVal);

    cout << "Inorder after deletion: ";
    inorder(root);
    cout << endl;

    printBSTasArray(root);

    return 0;
}


*/