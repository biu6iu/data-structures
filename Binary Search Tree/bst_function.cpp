#include <iostream>

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    int leftSize;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr), leftSize(0) {}
};

class BinarySearchTree {
private:
    TreeNode* root;

public:
    BinarySearchTree() : root(nullptr) {}

    // Helper function to insert a value into the BST
    void insert(int val) {
        root = insertRecursive(root, val);
    }

    // Recursive function to insert a value into the BST
    TreeNode* insertRecursive(TreeNode* node, int val) {
        if (node == nullptr) {
            return new TreeNode(val);
        }

        if (val < node->data) {
            node->left = insertRecursive(node->left, val);
            node->leftSize++;
        } else if (val > node->data) {
            node->right = insertRecursive(node->right, val);
        }

        return node;
    }

    // Function to find the predecessor of a given value in the BST
    TreeNode* findPredecessor(int val) {
        return findPredecessorRecursive(root, val, nullptr);
    }

    TreeNode* findPredecessorRecursive(TreeNode* node, int val, TreeNode* predecessor) {
        if (node == nullptr) {
            return predecessor;
        }

        if (node->data == val) {
            if (node->left != nullptr) {
                return findMax(node->left);
            } else {
                return predecessor;
            }
        } else if (val < node->data) {
            return findPredecessorRecursive(node->left, val, predecessor);
        } else {
            return findPredecessorRecursive(node->right, val, node);
        }
    }

    // Function to find the successor of a given value in the BST
    TreeNode* findSuccessor(int val) {
        return findSuccessorRecursive(root, val, nullptr);
    }

    TreeNode* findSuccessorRecursive(TreeNode* node, int val, TreeNode* successor) {
        if (node == nullptr) {
            return successor;
        }

        if (node->data == val) {
            if (node->right != nullptr) {
                return findMin(node->right);
            } else {
                return successor;
            }
        } else if (val < node->data) {
            return findSuccessorRecursive(node->left, val, node);
        } else {
            return findSuccessorRecursive(node->right, val, successor);
        }
    }

    // Function to find the minimum value node in the BST
    TreeNode* findMin(TreeNode* node) {
        if (node == nullptr) {
            return nullptr;
        }

        while (node->left != nullptr) {
            node = node->left;
        }

        return node;
    }

    // Function to find the maximum value node in the BST
    TreeNode* findMax(TreeNode* node) {
        if (node == nullptr) {
            return nullptr;
        }

        while (node->right != nullptr) {
            node = node->right;
        }

        return node;
    }

    // Function to perform rank search (finding the kth smallest element) in the BST
    TreeNode* rankSearch(TreeNode* node, int rank) {
        if (node == nullptr) {
            return nullptr;
        }

        if (rank == node->leftSize) {
            return node;
        } else if (rank < node->leftSize) {
            return rankSearch(node->left, rank);
        } else {
            return rankSearch(node->right, rank - 1 - node->leftSize);
        }
    }

    // Public wrapper for rankSearch
    int rankSearch(int k) {
        TreeNode* result = rankSearch(root, k - 1); // Subtract 1 as the rank starts from 1
        return (result != nullptr) ? result->data : -1; // Return -1 if not found
    }

    // Function to perform range search (finding elements in a given range) in the BST
    void rangeSearch(int low, int high) {
        rangeSearchRecursive(root, low, high);
    }

    void rangeSearchRecursive(TreeNode* node, int low, int high) {
        if (node == nullptr) {
            return;
        }

        if (node->data > low) {
            rangeSearchRecursive(node->left, low, high);
        }

        if (node->data >= low && node->data <= high) {
            std::cout << node->data << " ";
        }

        if (node->data < high) {
            rangeSearchRecursive(node->right, low, high);
        }
    }
};

int main() {
    BinarySearchTree bst;

    // Insert values into the BST
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);
    bst.insert(10);
    bst.insert(25);
    bst.insert(35);
    bst.insert(45);
    bst.insert(55);
    bst.insert(65);

    // Test the implemented functions
    std::cout << "Predecessor of 40: " << bst.findPredecessor(40)->data << std::endl;
    std::cout << "Predecessor of 60: " << bst.findPredecessor(60)->data << std::endl;
    std::cout << "Predecessor of 80: " << bst.findPredecessor(80)->data << std::endl;
    
    std::cout << "Successor of 40: " << bst.findSuccessor(40)->data << std::endl;
    std::cout << "Successor of 60: " << bst.findSuccessor(60)->data << std::endl;
    std::cout << "Successor of 80: " << bst.findSuccessor(70)->data << std::endl;
    
    std::cout << "Rank 4: " << bst.rankSearch(4) << std::endl;
    std::cout << "Rank 6: " << bst.rankSearch(6) << std::endl;
    std::cout << "Rank 12: " << bst.rankSearch(12) << std::endl;
    
    std::cout << "Range search (30 to 70): ";
    bst.rangeSearch(30, 70);
    std::cout << std::endl;

    return 0;
}

