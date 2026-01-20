#include <iostream>
#include <vector>

// Function to partition the array into two subarrays based on a pivot element
// Elements smaller than the pivot are on the left, and elements greater than
// the pivot are on the right.
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Choose the rightmost element as the pivot
    int i = (low - 1); // Index of the smaller element

    for (int j = low; j <= high - 1; j++) {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) {
            i++;
            // Swap arr[i] and arr[j]
            std::swap(arr[i], arr[j]);
        }
    }

    // Swap arr[i+1] and arr[high] (or the pivot)
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// Function to perform Quick Sort
void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        // Partition the array into two subarrays
        int pi = partition(arr, low, high);

        // Recursively sort the subarrays
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to print an array
void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> arr = {10, 7, 8, 9, 1, 5};
    int n = arr.size();

    std::cout << "Original Array: ";
    printArray(arr);

    quickSort(arr, 0, n - 1);

    std::cout << "Sorted Array: ";
    printArray(arr);

    return 0;
}
