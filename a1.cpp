//first question
/*#include <iostream>
using namespace std;

const int SIZE = 100;
int arr[SIZE], n = 0;

void create() {
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}

void display() {
    cout << "Array elements: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void insert() {
    int pos, val;
    cout << "Enter position and value to insert: ";
    cin >> pos >> val;
    if (pos > n || pos < 0) {
        cout << "Invalid position\n";
        return;
    }
    for (int i = n; i > pos; i--)
        arr[i] = arr[i - 1];
    arr[pos] = val;
    n++;
}

void deleteElement() {
    int pos;
    cout << "Enter position to delete: ";
    cin >> pos;
    if (pos >= n || pos < 0) {
        cout << "Invalid position\n";
        return;
    }
    for (int i = pos; i < n - 1; i++)
        arr[i] = arr[i + 1];
    n--;
}

void linearSearch() {
    int key;
    cout << "Enter element to search: ";
    cin >> key;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            cout << "Element found at position " << i << endl;
            return;
        }
    }
    cout << "Element not found\n";
}

int main() {
    int choice;
    do {
        cout << "\n-----MENU-----\n";
        cout << "1.CREATE\n2.DISPLAY\n3.INSERT\n4.DELETE\n5.LINEAR SEARCH\n6.EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: create(); break;
            case 2: display(); break;
            case 3: insert(); break;
            case 4: deleteElement(); break;
            case 5: linearSearch(); break;
            case 6: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice\n";
        }
    } while (choice != 6);
    return 0;
}*/

//second question

/*#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 2, 3, 4, 4, 5};
    int n = 7;

    cout << "Original Array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";

    int newSize = 0;
    for (int i = 0; i < n; i++) {
        bool isDuplicate = false;
        for (int j = 0; j < newSize; j++) {
            if (arr[i] == arr[j]) {
                isDuplicate = true;
                break;
            }
        }
        if (!isDuplicate) {
            arr[newSize++] = arr[i];
        }
    }

    cout << "\nArray after removing duplicates: ";
    for (int i = 0; i < newSize; i++) cout << arr[i] << " ";
    return 0;
}
*/

//third question

//10000

//fourth question

//first part

/*
#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    for (int i = 0, j = n - 1; i < j; i++, j--) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    cout << "\nReversed array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}

*/

//second part

/*
#include <iostream>
using namespace std;

int main() {
    int a[2][2] = {{1, 2}, {3, 4}};
    int b[2][2] = {{2, 0}, {1, 2}};
    int c[2][2] = {};

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
                c[i][j] += a[i][k] * b[k][j];

    cout << "Result:\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++)
            cout << c[i][j] << " ";
        cout << endl;
    }
    return 0;
}

*/

//third part

/*
#include <iostream>
using namespace std;

int main() {
    int a[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int trans[3][2];

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 3; j++)
            trans[j][i] = a[i][j];

    cout << "Transpose:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++)
            cout << trans[i][j] << " ";
        cout << endl;
    }
    return 0;
}

*/

//fifth question

/*
#include <iostream>
using namespace std;

int main() {
    int a[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    for (int i = 0; i < 3; i++) {
        int sum = 0;
        for (int j = 0; j < 3; j++)
            sum += a[i][j];
        cout << "Sum of row " << i << ": " << sum << endl;
    }

    for (int j = 0; j < 3; j++) {
        int sum = 0;
        for (int i = 0; i < 3; i++)
            sum += a[i][j];
        cout << "Sum of column " << j << ": " << sum << endl;
    }

    return 0;
}

*/
