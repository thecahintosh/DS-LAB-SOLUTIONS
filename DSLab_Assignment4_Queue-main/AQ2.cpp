/*Develop a menu driven program demonstrating the following operations on Circular Queues:
enqueue(), dequeue(), isEmpty(), isFull(), display(), and peek().*/
#include <iostream>
using namespace std;

#define size 5

class queue
{ // circular
    int front, end;
    int queueArr[size];
    int currsize;

public:
    queue()
    {
        front = -1;
        end = -1;
        currsize = 0;
    }

    int enqueue(int n)
    {
        if (currsize == size)
        {
            cout << "Queue is full\n";
            return -1;
        }

        // First element
        if (currsize == 0)
        {
            front = 0;
            end = 0;
            queueArr[end] = n;
        }
        else
        {
            end = (end + 1) % size;
            queueArr[end] = n;
        }

        currsize++;
        return n;
    }

    int dequeue()
    {
        if (currsize == 0)
        {
            cout << "Queue is empty\n";
            return -1;
        }

        int val = queueArr[front];
        front = (front + 1) % size;
        currsize--;

        // Reset pointers if queue becomes empty
        if (currsize == 0)
        {
            front = -1;
            end = -1;
        }

        return val;
    }

    int Queuesize()
    {
        return currsize;
    }

    int peek()
    {
        if (currsize == 0)
        {
            cout << "Queue is empty\n";
            return -1;
        }
        return queueArr[front];
    }

    void display()
    {
        if (currsize == 0)
        {
            cout << "Queue is empty\n";
            return;
        }

        int i = front;
        for (int count = 0; count < currsize; count++)
        {
            cout << queueArr[i] << " ";
            i = (i + 1) % size;
        }
        cout << endl;
    }
};

int main()
{
    queue q;
    cout << q.enqueue(7) << " added\n";
    cout << q.enqueue(1) << " added\n";
    cout << q.enqueue(3) << " added\n";
    cout << q.enqueue(8) << " added\n";
    cout << q.enqueue(9) << " added\n";
    cout << q.enqueue(6) << " added\n";

    q.display();

    cout << q.dequeue() << " removed\n";
    q.display();

    cout << q.enqueue(4) << " added\n";
    cout << q.peek() << " is the first element\n";
    cout << q.Queuesize() << " is the current size of the queue\nQueue: ";
    
    q.display();

    return 0;
}
