/*Write a program interleave the first half of the queue with second half.
Sample I/P: 4 7 11 20 5 9 Sample O/P: 4 20 7 5 11 9*/
#include<iostream>
using namespace std;

#define MAX 10

class queue {
    int start;
    int end;
    int queueArr[MAX];
    int currsize;

public:
    queue() {
        start = -1;
        end = -1;
        currsize = 0;
    }

    int enqueue(int ele) {
        if (currsize == MAX) {
            cout << "Queue is full" << endl;
            return -1;
        }
        if (currsize == 0) {
            start = end = 0;
            queueArr[end] = ele;
        }
        else {
            queueArr[++end] = ele;
        }
        currsize++;
        return queueArr[end];
    }

    int dequeue() {
        if (currsize == 0) {
            cout << "Queue is empty\n";
            return -1;
        }
        int val = queueArr[start++];
        currsize--;

        if (currsize == 0) {
            start = -1;
            end = -1;
        }

        return val;
    }

    void display() {
        if (currsize == 0) {
            cout << "Queue is empty\n";
        }
        else {
            for (int i = start; i <= end; i++) {
                cout << queueArr[i] << " ";
            }
            cout << endl;
        }
    }

    void interleave() {
        if (currsize == 0) {
            cout << "Queue is empty - nothing to interleave\n";
            return;
        }

        if (currsize % 2 != 0) {
            cout << "Queue size must be even to interleave\n";
            return;
        }

        int middle = currsize / 2;
        int firstHalf[middle];
        int secondHalf[middle];

        for (int i = 0; i < middle; i++) {
            firstHalf[i] = dequeue();
        }

        for (int i = 0; i < middle; i++) {
            secondHalf[i] = dequeue();
        }

        for (int i = 0; i < middle; i++) {
            enqueue(firstHalf[i]);
            enqueue(secondHalf[i]);
        }
    }

};

int main() {
    int n;
    cout << "Enter the number of elements in queue (even number, MAX " << MAX << "): ";
    cin >> n;

    if (n > MAX || n % 2 != 0) {
        cout << "Invalid input. Number must be <= " << MAX << " and even.\n";
        return 0;
    }

    cout << "Enter elements:\n";
    int ele;
    queue q;
    for (int i = 0; i < n; i++) {
        cin >> ele;
        q.enqueue(ele);
    }

    cout << "Initially: ";
    q.display();

    q.interleave();

    cout << "After interleaving: ";
    q.display();

    return 0;
}
