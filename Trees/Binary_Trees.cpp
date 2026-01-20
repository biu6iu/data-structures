#include <iostream>
#include <iomanip>
#include <queue>

// Define a struct for a BinaryTreeNode
struct BinaryTreeNode {
    int data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(int value)
        : data(value), left(nullptr), right(nullptr) {}
};

// Function to display the binary tree structure (left to right)
void display(BinaryTreeNode* root, int level = 0) {
    if (root == nullptr) {
        return;
    }

    const int spacing = 4;

    // Print the right subtree
    display(root->right, level + 1);

    // Print the current node
    std::cout << std::setw(level * spacing) << " ";
    std::cout << root->data << std::endl;

    // Print the left subtree
    display(root->left, level + 1);
}

// Function to insert a value into a binary tree
BinaryTreeNode* insert(BinaryTreeNode* root, int value) {
    // if root doesn't exist, set this value as root
    if (root == nullptr) {
        return new BinaryTreeNode(value); 
    }

    std::queue<BinaryTreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        BinaryTreeNode* curr = q.front();
        q.pop();

        if (curr->left == nullptr) {
            curr->left = new BinaryTreeNode(value);
            return root;
        }
        else {
            q.push(curr->left);
        }

        if (curr->right == nullptr) {
            curr->right = new BinaryTreeNode(value);
            return root;
        }
        else {
            q.push(curr->right);
        }
    }
    return root;
}

// Function to find a value in a binary tree
bool find(BinaryTreeNode* root, int value) {
    if (root == nullptr) {
        return false;
    }
    
    if (root->data == value) {
        return true;
    }
    
    if (root->data > value) {
        return find(root->left, value);
    }
    else {
        return find(root->right, value);
    }
}

void free(BinaryTreeNode* root) {
    // Base case: if the node is null, nothing to delete
    if (root == nullptr) {
        return;
    }
    
    // Recursively delete left subtree
    free(root->left);
    
    // Recursively delete right subtree
    free(root->right);
    
    // Delete the current node (post-order deletion)
    delete root;
}

int main() {
    BinaryTreeNode* root = new BinaryTreeNode(1);

    root->left = new BinaryTreeNode(2);
    root->right = new BinaryTreeNode(3);

    root->left->left = new BinaryTreeNode(4);
    root->left->right = new BinaryTreeNode(5);

    root->right->left = new BinaryTreeNode(6);
    root->right->right = new BinaryTreeNode(7);

    // Display the binary tree structure (left to right)
    std::cout << "Binary Tree Structure:" << std::endl;
    display(root);

    // Insert a new value into the tree
    int insertValue = 8;
    insert(root, insertValue);
    std::cout << "After inserting value " << insertValue << ":" << std::endl;
    display(root);

    // Find and print a value in the tree
    int searchValue = 5;
    if (find(root, searchValue)) {
        std::cout << "Found value " << searchValue << " in the tree." << std::endl;
    } else {
        std::cout << "Value " << searchValue << " not found in the tree." << std::endl;
    }

    free(root);
    return 0;
}
