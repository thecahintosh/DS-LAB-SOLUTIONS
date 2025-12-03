#include<iostream>
using namespace std;
// improved selection sort

void dualSelectionSort(int arr[], int n) {
    int left = 0;
    int right = n - 1;

    while (left < right) {

        int minIndex = left;
        int maxIndex = right;

        for(int i = left; i <= right; i++) {

            if(arr[i] < arr[minIndex])
                minIndex = i;

            if(arr[i] > arr[maxIndex])
                maxIndex = i;
        }

        swap(arr[left], arr[minIndex]);

        if(maxIndex == left)
            maxIndex = minIndex;

        swap(arr[right], arr[maxIndex]);

        left++;
        right--;
    }
}

int main(){
    int arr[5] = {4,8,2,7,6};
    dualSelectionSort(arr,5);
    for(int i = 0;i<5;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}