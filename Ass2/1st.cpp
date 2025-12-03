#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int ele) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == ele) { 
            return mid;
        }
        else if (arr[mid] < ele) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    int n, ele;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements in sorted order:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter element to search: ";
    cin >> ele;

    int result = binarySearch(arr, n, ele);

    if (result != -1) {
        cout << "Element found at position " << result + 1 << endl;
    } else {
        cout << "Element not found in the array.\n";
    }

    return 0;
}
