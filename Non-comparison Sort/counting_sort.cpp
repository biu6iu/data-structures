#include <iostream>
#include <vector>

using namespace std;

// Function to perform counting sort
void countingSort(vector<int>& arr) {
    int n = arr.size();
    // Find the maximum element in the array
    int k = *max_element(arr.begin(), arr.end());

    // Create a count array to store the count of each element
    vector<int> count(k + 1, 0);

    // Count the occurrences of each element in the input array
    for (int i = 0;i < n;i++) {
        count[arr[i]]++;
    }

    // cumulative sum
    for (int i = 1;i <= k;i++) {
        count[i] += count[i - 1];
    }

    // Reconstruct the sorted array from the count array
    vector<int> output(n);
    for (int i = n - 1;i >= 0;i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (int i = 0;i < n;i++) {
        arr[i] = output[i];
    }
}

int main() {
    // Input array
    vector<int> arr = {4, 2, 2, 8, 3, 3, 1};

    // Display the original array
    cout << "Original Array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // Perform counting sort
    countingSort(arr);

    // Display the sorted array
    cout << "Sorted Array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
