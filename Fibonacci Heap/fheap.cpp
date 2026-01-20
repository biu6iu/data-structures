#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

struct FibonacciNode {
    int key;
    FibonacciNode* parent;
    FibonacciNode* child;
    FibonacciNode* left;
    FibonacciNode* right;
    bool marked;
    int degree;

    FibonacciNode(int k) : key(k), parent(nullptr), child(nullptr),
                            left(this), right(this), marked(false), degree(0) {}
};

class FibonacciHeap {
public:
    FibonacciHeap() : minNode(nullptr), numNodes(0) {}

    void insert(int key) {
        // Exercise 1: write your insert function;
    }

    int findMin() {
        if (!minNode) {
            std::cerr << "Fibonacci Heap is empty." << std::endl;
            return std::numeric_limits<int>::max();
        }
        return minNode->key;
    }

    FibonacciNode* getMinNode() {
        return minNode;
    }

    void extractMin() {
        // Exercise 2: write your extractMin function;
    }

    void decreaseKey(FibonacciNode* node, int newKey) {
        // Exercise 3: write your decreaseKey function;
    }

private:
    FibonacciNode* minNode;
    int numNodes;

    void consolidate() {
        // Exercise 2: write your consolidate function;
    }

    void unionNodes(FibonacciNode* smaller, FibonacciNode* larger) {
        smaller->right->left = smaller->left;
        smaller->left->right = smaller->right;
        smaller->right = smaller->left = smaller;
        smaller->parent = larger;
        if (!larger->child) {
            larger->child = smaller;
        } else {
            smaller->right = larger->child;
            smaller->left = larger->child->left;
            larger->child->left = smaller;
            smaller->right->left = smaller;
        }
        larger->degree++;
        smaller->marked = false;
    }

    void cut(FibonacciNode* child, FibonacciNode* parent) {
        // Exercise 3: write your cut function;
    }

    void cascadingCut(FibonacciNode* node) {
        // Exercise 3: write your cascadingCut function;
    }
};

int main() {
    FibonacciHeap fibHeap;

    // Insert nodes
    fibHeap.insert(4);
    fibHeap.insert(2);
    fibHeap.insert(8);
    fibHeap.insert(6);

    std::cout << "Minimum: " << fibHeap.findMin() << std::endl;

    return 0; // Stopped here for the Exercise 1; Remove this line after Exercise 3;
    


    fibHeap.extractMin();
    std::cout << "Minimum after extraction: " << fibHeap.findMin() << std::endl;


    return 0; // Stopped here for the Exercise 2; Remove this line after Exercise 2;

    // Decrease the key of a node
    FibonacciNode* nodeToDecrease = fibHeap.getMinNode()->right; // Decrease the second smallest node
    fibHeap.decreaseKey(nodeToDecrease, 1);
    std::cout << "Minimum after decreaseKey: " << fibHeap.findMin() << std::endl;

    // Add more nodes and test decreaseKey
    fibHeap.insert(10);
    fibHeap.insert(3);
    FibonacciNode* nodeToDecrease2 = fibHeap.getMinNode()->right; // Decrease the second smallest node again
    fibHeap.decreaseKey(nodeToDecrease2, 2);
    std::cout << "Minimum after another decreaseKey: " << fibHeap.findMin() << std::endl;

    // Add nodes with equal keys and test decreaseKey
    fibHeap.insert(2); // Insert a node with the same key as an existing node
    std::cout << "Minimum before decreaseKey with equal keys: " << fibHeap.findMin() << std::endl;
    FibonacciNode* nodeToDecrease3 = fibHeap.getMinNode()->right; // Decrease the second smallest node with equal keys
    fibHeap.decreaseKey(nodeToDecrease3, 1);
    std::cout << "Minimum after decreaseKey with equal keys: " << fibHeap.findMin() << std::endl;

    return 0;
}
