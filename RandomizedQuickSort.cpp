#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivotIndex = low + rand() % (high - low + 1);
    int pivotValue = arr[pivotIndex];

    swap(arr[pivotIndex], arr[high]);

    int i = low;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivotValue) {
            swap(arr[i], arr[j]);
            i++;
        }
    }

    swap(arr[i], arr[high]);
    return i;
}

void randomizedQuickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        randomizedQuickSort(arr, low, pivotIndex - 1);
        randomizedQuickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    srand(time(0)); 

    vector<int> arr = {9, 7, 5, 11, 12, 2, 14, 3, 10, 6};

    cout << "Original Array:" << endl;
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    randomizedQuickSort(arr, 0, arr.size() - 1);

    cout << "Sorted Array:" << endl;
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
