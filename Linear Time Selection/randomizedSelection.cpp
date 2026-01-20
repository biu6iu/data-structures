#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[low];
    int left = low + 1;
    int right = high;

    while (true) {
        while (left <= right && arr[left] < pivot) left++;
        while (left <= right && arr[right] > pivot) right--;

        if (left <= right) {
            swap(arr[left], arr[right]);
        } else {
            break;
        }
    }

    swap(arr[low], arr[right]);
    return right;
}

int randomizedSelection(vector<int>& arr, int low, int high, int k) {
    if (low == high) {
        return arr[low];
    }

    int pivotIdx = partition(arr, low, high);

    if (pivotIdx == k) {
        return arr[pivotIdx];
    } 
    else if (pivotIdx > k) {
        return randomizedSelection(arr, low, pivotIdx - 1, k);
    } 
    else {
        return randomizedSelection(arr, pivotIdx + 1, high, k);
    }
}

int main() {
    srand(time(0));

    vector<int> arr = {8, 2, 4, 9, 3, 7, 1, 6};
    int k = 3;

    int result = randomizedSelection(arr, 0, arr.size() - 1, k - 1);
    cout << "The " << k << "th smallest element is: " << result << endl;

    return 0;
}