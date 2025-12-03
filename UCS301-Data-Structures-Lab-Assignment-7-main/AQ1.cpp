#include<iostream>
using namespace std;

const int max_size = 10;

void InputArr(int arr[],int size){
    if(size > max_size){
        return;
    }
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }
}

void DisplayArr(int arr[],int size){
    cout << "------------------------------\n";
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << "\n------------------------------\n";
}


void SelectionSort(int arr[],int size){
    for(int i = 0; i < size-1; i++){
        int min = i;
        for(int j = i+1; j < size; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        if(min != i){
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }

    }
}

void InsertionSort(int arr[],int size){
    for(int i = 1; i < size; i++){
        int key = arr[i];
        int j = i-1;
        while (j>=0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void BubbleSort(int arr[],int size){
    for(int i = 0; i < size ; i++){
        bool swapped = false;
        for(int j = 0; j < size - i -1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = true;
            }
        }
        if(!swapped) break;
    }
}

void Merge(int arr[],int left,int mid,int right){
    int i = left;
    int j = mid+1;
    int k = 0;
    int temp[max_size];
    while(i<=mid && j<=right){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }
        else{
            temp[k++] = arr[j++];
        }
    }
    while(i<=mid){
        temp[k++] = arr[i++];
    }
    while(j<=right){
        temp[k++] = arr[j++];
    }
    for(int x = 0; x < k; x++){
        arr[left+x] = temp[x];
    }
}

void MergeSortRecursive(int arr[],int left,int right){
//recursive approach
    if(left >= right) return ;
    int mid = (left+right)/2;
    MergeSortRecursive(arr,left,mid);
    MergeSortRecursive(arr,mid+1,right);
    Merge(arr,left,mid,right);
}

int Partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low - 1;
    int j = high + 1;

    while (true) {

        do {
            i++;
        } while (arr[i] < pivot);

        do {
            j--;
        } while (arr[j] > pivot);

        if (i >= j)
            return j;

        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void QuickSort(int arr[], int low, int high) {
    if (low < high) {
        int p = Partition(arr, low, high);
        QuickSort(arr, low, p);
        QuickSort(arr, p + 1, high);
    }
}


int main(){
    int size;
    cout << "Enter size of array : ";
    cin >> size;


    int arr1[max_size],arr2[max_size],arr3[max_size],arr4[max_size],arr5[max_size];

    cout << "Enter Array 1" << endl;
    InputArr(arr1,size);
    cout << "Enter Array 2" << endl;
    InputArr(arr2,size);
    cout << "Enter Array 3" << endl;
    InputArr(arr3,size);
    cout << "Enter Array 4" << endl;
    InputArr(arr4,size);
    cout << "Enter Array 5" << endl;
    InputArr(arr5,size);
    
    SelectionSort(arr1,size);
    cout << "SELECTION SORT\n";
    DisplayArr(arr1,size);

    InsertionSort(arr2,size);
    cout << "INSERTION SORT\n";
    DisplayArr(arr2,size);

    BubbleSort(arr3,size);
    cout << "BUBBLE SORT\n";
    DisplayArr(arr3,size);

    MergeSortRecursive(arr4,0,size-1);
    cout << "MERGE SORT\n";
    DisplayArr(arr4,size);

    QuickSort(arr5,0,size-1);
    cout << "QUICK SORT\n";
    DisplayArr(arr5,size);

    return 0;
}