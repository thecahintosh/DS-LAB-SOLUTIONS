#include<iostream>
using namespace std;

void diagonal(){
    int n;
    cout << "Enter size of square matrix: ";
    cin >> n;

    int arr[100];

    cout << "Enter diagonal elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "\nDiagonal Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) cout << arr[i] << " ";
            else cout << "0 ";
        }
        cout << endl;
    }
}

void Tri(){
    int n;
    cout << "Enter size of square matrix: ";
    cin >> n;

    int a[100], b[100], c[100];

    cout << "Enter main diagonal elements (a):\n";
    for (int i = 0; i < n; i++) cin >> a[i];

    cout << "Enter upper diagonal elements (b):\n";
    for (int i = 0; i < n-1; i++) cin >> b[i];

    cout << "Enter lower diagonal elements (c):\n";
    for (int i = 0; i < n-1; i++) cin >> c[i];

    cout << "\nTri-Diagonal Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) cout << a[i] << " ";         // main diagonal
            else if (j == i+1) cout << b[i] << " ";  // upper diagonal
            else if (j == i-1) cout << c[j] << " ";  // lower diagonal
            else cout << "0 ";
        }
        cout << endl;
    }
}

void Low(){
    int n;
    cout << "Enter size of square matrix: ";
    cin >> n;

    int size = n*(n+1)/2;   // number of non-zero elements
    int arr[size];

    cout << "Enter lower triangular matrix elements:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) { // only lower part
            int index = (i*(i+1))/2 + j;
            cin >> arr[index];
        }
    }

    cout << "\nThe Lower Triangular Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= j) {
                int index = (i*(i+1))/2 + j;
                cout << arr[index] << " ";
            } else {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}
void Upp(){ 
    int n;
    cout << "Enter size of square matrix: ";
    cin >> n;

    int size = n*(n+1)/2;   // number of non-zero elements
    int arr[size];

    cout << "Enter upper triangular matrix elements:\n";
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) { // only upper part
            int index = (i*n - (i*(i-1))/2) + (j - i);
            cin >> arr[index];
        }
    }

    cout << "\nThe Upper Triangular Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i <= j) {
                int index = (i*n - (i*(i-1))/2) + (j - i);
                cout << arr[index] << " ";
            } else {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

void Symm(){
    int n;
    cout << "Enter size of square matrix: ";
    cin >> n;

    int size = n*(n+1)/2;// space required
    int arr[size];

    cout << "Enter symmetric matrix elements:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {  // only lower triangle
            int index = (i*(i+1))/2 + j;
            cin >> arr[index];
        }
    }

    cout << "\nThe Symmetric Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= j) {
                int index = (i*(i+1))/2 + j;
                cout << arr[index] << " ";
            } else {
                int index = (j*(j+1))/2 + i;  // mirror value
                cout << arr[index] << " ";
            }
        }
        cout << endl;
    }
}

int main(){
    Symm();
    return 0;
}