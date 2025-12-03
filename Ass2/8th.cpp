#include <iostream>

int countDistinct(int arr[], int n) {
    int count = 0;

    for (int i = 0; i < n; i++) {
        bool isDistinct = true;

        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                isDistinct = false;
                break;
            }
        }

        if (isDistinct) {
            count++;
        }
    }

    return count;
}

int main() {
    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    int arr[n];
    std::cout << "---Enter Array--- (" << n << " elements) :\n";
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    int distinctCount = countDistinct(arr, n);
    std::cout << "Total number of distinct elements: " << distinctCount << std::endl;

    return 0;
}
