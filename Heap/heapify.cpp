#include <iostream>
#include <vector>
using namespace std;

class MinHeap {
private:
    vector<int> heap;

    void percolateDown(int index) {
        // write your own function
        int size = heap.size();
        int j;
        // start from left child node (index * 2)
        for (j = index * 2 + 1;j < size;j = index * 2 + 1) {
            // check if right child exists and if so, if it's smaller than left child
            if (j + 1 < size && heap[j] > heap[j + 1]) {
                j++;
            }
            
            // check if current node is already smaller than its children
            if (heap[index] <= heap[j]) {
                break;
            }

            // if not then swap with the smaller child
            swap(heap[index], heap[j]);
            index = j;
        }
    }

public:
    MinHeap(const vector<int>& arr) : heap(arr) {
        for (int i = (heap.size() / 2) - 1; i >= 0; i--) {
            percolateDown(i);
        }
    }

    void enqueue(int value) {
        heap.push_back(value);
        int index = heap.size() - 1;
        while (index > 0 && heap[(index - 1) / 2] > heap[index]) {
            swap(heap[(index - 1) / 2], heap[index]);
            index = (index - 1) / 2;
        }
    }

    int dequeueMin() {
        int minVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        percolateDown(0);
        return minVal;
    }

    void display() {
        for (int val : heap) {
            cout << val << " ";
        }
        cout << endl;
    }
};

int main() {
    vector<int> data = {0,3,7,2,5,8,4,6,0,1};

    MinHeap minHeap(data);

    cout << "Heap after heapifying: ";
    minHeap.display();

    cout << "Dequeuing all elements to verify heap property:\n";
    while (!data.empty()) {
        cout << minHeap.dequeueMin() << " ";
        data.pop_back();  // To emulate the heap getting emptied
    }
    cout << endl;

    return 0;
}
