#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// A utility function to find the maximum element in an array
int getMax(vector<int>& arr) {
    int max = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to perform Bucket Sort
void bucketSort(vector<int>& arr, int exp) {
    int n = arr.size();
    const int radix = 10; // Radix of decimal system (0-9)
    vector<vector<int>> buckets(radix);
    int divisor = static_cast<int>(pow(10, exp - 1));

    // Place elements into buckets based on the current digit (exp)
    for (int i = 0; i < n; i++) {
        int digit = (arr[i] / divisor) % radix;
        buckets[digit].push_back(arr[i]);
    }

    // Sort each bucket using a simple sorting algorithm (e.g., insertion sort)
    for (int i = 0; i < radix; i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    // Concatenate the sorted buckets to update the original array
    int index = 0;
    for (int i = 0; i < radix; i++) {
        for (int num : buckets[i]) {
            arr[index++] = num;
        }
    }
}

// Function to perform LSD Radix Sort using Bucket Sort
void lsdRadixSort(vector<int>& arr) {
    int max = getMax(arr);
    int numDigits = static_cast<int>(log10(max)) + 1;

    for (int exp = 1;exp <= numDigits;exp++) {
        bucketSort(arr, exp);
    }
}

int main() {
    // Input array of integers
    vector<int> arr = {170, 4532, 754, 9045, 8021, 240, 222, 6666};

    // Display the original array
    cout << "Original Array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // Perform LSD Radix Sort using Bucket Sort within each iteration
    lsdRadixSort(arr);

    // Display the sorted array
    cout << "Sorted Array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
