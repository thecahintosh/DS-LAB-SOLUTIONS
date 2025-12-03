/*Write a program to find first non-repeating character in a string using Queue.
Sample I/P: a a b c Sample O/P: a -1 b b*/
#include <iostream>
using namespace std;

const int MAX_CHAR = 26;

class Queue { // linear

    char arr[MAX_CHAR];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return rear == MAX_CHAR - 1;
    }

    void enqueue(char x) {
        if (isFull()) {
            cout << "Queue is full\n";
            return;
        }
        if (isEmpty()) front = 0;
        arr[++rear] = x;
    }

    char dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        char val = arr[front];
        front++;
        if (front > rear) front = rear = -1;
        return val;
    }

    char peek() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[front];
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

void firstnonrepeating(char str[])
{
    Queue q;
    int charCount[MAX_CHAR] = { 0 };

    for (int i = 0; str[i]; i++) {

        q.enqueue(str[i]);

        charCount[str[i] - 'a']++;

        while (!q.isEmpty()) {
            if (charCount[q.peek() - 'a'] > 1)
                q.dequeue();
            else {
                cout << q.peek() << " ";
                break;
            }
        }

        if (q.isEmpty())
            cout << -1 << " ";
    }
    cout << endl;
}

int main()
{
    char str[] = "aabc";
    firstnonrepeating(str);
    return 0;
}
