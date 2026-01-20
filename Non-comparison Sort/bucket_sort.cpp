#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to perform Quick Sort
void quickSort(vector<float>& arr, int low, int high) {
    if (low < high) {
        float pivot = arr[high]; // Choose the last element as the pivot
        int i = low - 1; // Index of smaller element

        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }

        swap(arr[i + 1], arr[high]);

        int pivotIndex = i + 1;

        // Recursively sort elements before and after the pivot
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

// Function to perform bucket sort
void bucketSort(vector<float>& arr) {
    int n = arr.size();
    
    vector<vector<float>> buckets(n);

    for (int i = 0;i < n;++i) {
        int bucketIdx = n * arr[i];
        buckets[bucketIdx].push_back(arr[i]);
    }

    for (int i =0;i < n;++i) {
        quickSort(buckets[i], 0, buckets[i].size() - 1);
    }

    int index = 0;
    for (int i = 0;i < n;++i) {
        for (float num : buckets[i]) {
            arr[index] = num;
            index++;
        }
    }
}

int main() {
    // Input array (floating-point numbers between 0 and 1)
    vector<float> arr = {0.32, 0.15, 0.82, 0.74, 0.46, 0.21, 0.63};

    // Display the original array
    cout << "Original Array: ";
    for (float num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // Perform bucket sort using Quick Sort
    bucketSort(arr);

    // Display the sorted array
    cout << "Sorted Array: ";
    for (float num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
