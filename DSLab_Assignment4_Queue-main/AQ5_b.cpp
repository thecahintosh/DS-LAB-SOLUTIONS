/*
Write a program to implement a stack using One Queue.
*/
#include <iostream>
using namespace std;

#define MAX 100

class Queue {
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
        if (isEmpty()) {
            front = 0;
        }
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
        if (currSize == 0){
            front = rear = -1;
        }
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
};

class myStack {
    Queue q;

public:
    void push(int x) {
        int sz = q.size();
        q.enqueue(x);

        for (int i = 0; i < sz; i++) {
            int temp = q.dequeue();
            q.enqueue(temp);
        }
    }

    void pop() {
        if (!q.isEmpty())
            q.dequeue();
    }

    int top() {
        if (q.isEmpty())
            return -1;
        return q.peek();
    }

    int size() {
        return q.size();
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
