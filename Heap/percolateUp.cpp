#include <iostream>
#include <vector>
using namespace std;

class MinHeap {
private:
    vector<int> heap;

    void percolateUp(int index) {
        // write your own function
        while (index > 0 && heap[index] < heap[index / 2]) {
            swap(heap[index], heap[index / 2]);
            index = index / 2;
        }
    }


public:
    MinHeap() {}

    void enqueue(int value) {
        heap.push_back(value);
        percolateUp(heap.size() - 1);
    }


    int getMin() {
        if (isEmpty()) {
            throw runtime_error("Heap is empty!");
        }
        return heap[0];
    }

    bool isEmpty() {
        return heap.empty();
    }

    int size() {
        return heap.size();
    }

    void display() {
        for (int val : heap) {
            cout << val << " ";
        }
        cout << endl;
    }
};

int main() {
    MinHeap minHeap;
    
    minHeap.enqueue(3);
    cout << "Heap after enqueueing 3: ";
    minHeap.display();
    
    minHeap.enqueue(5);
    cout << "Heap after enqueueing 5: ";
    minHeap.display();

    minHeap.enqueue(2);
    cout << "Heap after enqueueing 2: ";
    minHeap.display();

    minHeap.enqueue(8);
    cout << "Heap after enqueueing 8: ";
    minHeap.display();

    minHeap.enqueue(4);
    cout << "Heap after enqueueing 4: ";
    minHeap.display();

    cout << "Min value using getMin: " << minHeap.getMin() << endl;


    return 0;
}
