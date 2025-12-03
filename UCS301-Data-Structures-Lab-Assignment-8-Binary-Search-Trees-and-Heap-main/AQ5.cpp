#include <iostream>
using namespace std;

void maxHeapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void buildMaxHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);
}

void heapsortIncreasing(int arr[], int n) {
    buildMaxHeap(arr, n);

    for (int i = n - 1; i >= 1; i--) {
        swap(arr[0], arr[i]);
        maxHeapify(arr, i, 0);
    }
}

void minHeapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

void buildMinHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);
}

void heapsortDecreasing(int arr[], int n) {
    buildMinHeap(arr, n);

    for (int i = n - 1; i >= 1; i--) {
        swap(arr[0], arr[i]);
        minHeapify(arr, i, 0);
    }
}


int main() {
    int arr1[] = {12, 3, 17, 8, 34, 25};
    int n1 = 6;

    int arr2[] = {12, 3, 17, 8, 34, 25};
    int n2 = 6;

    heapsortIncreasing(arr1, n1);
    heapsortDecreasing(arr2, n2);

    cout << "Increasing order: ";
    for (int x : arr1) cout << x << " ";
    cout << endl;

    cout << "Decreasing order: ";
    for (int x : arr2) cout << x << " ";
    cout << endl;

    return 0;
}
