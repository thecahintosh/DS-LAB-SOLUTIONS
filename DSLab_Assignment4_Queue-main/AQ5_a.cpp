/*
Write a program to implement a stack using Two queues.
*/
#include <iostream>
#define MAX 100

using namespace std;

class Queue { // linear
    int arr[MAX];
    int front, rear;
    int currSize;

public:
    Queue() {
        front = -1;
        rear = -1;
        currSize = 0;
    }

    bool isEmpty() {
        return currSize == 0;
    }

    bool isFull() {
        return rear == MAX - 1;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue is full\n";
            return;
        }
        if (isEmpty()) front = 0;
        arr[++rear] = x;
        currSize++;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        int val = arr[front];
        front++;
        currSize--;
        if (currSize == 0)
            front = rear = -1;
        return val;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[front];
    }

    int size() {
        return currSize;
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

class myStack {
    Queue q1, q2;

    private:
    void swapQueues() {
        Queue temp = q1;
        q1 = q2;
        q2 = temp;
    }

public:
    void push(int x) {
        q2.enqueue(x);

        while (!q1.isEmpty()) {
            q2.enqueue(q1.dequeue());
        }

        swapQueues();
    }

    void pop() {
        if (!q1.isEmpty())
            q1.dequeue();
    }

    int top() {
        if (q1.isEmpty())
            return -1;
        return q1.peek();
    }

    int size() {
        return q1.size();
    }

};

int main() {
    myStack st;
    st.push(1);
    st.push(2);
    st.push(3);

    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;

    cout << st.size() << endl;

    return 0;
}
