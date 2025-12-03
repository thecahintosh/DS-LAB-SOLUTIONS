/*Develop a menu driven program demonstrating the following operations on a Stack using array:
(i) push(), (ii) pop(), (iii) isEmpty(), (iv) isFull(), (v) display(), and (vi) peek().*/
#include<iostream>
using namespace std;

#define MAX 5

class stack{
    int arr[MAX];
    int top;
public: 
    stack() { top = -1; }

    bool isEmpty() { return top == -1; }
    bool isFull() { return top == MAX - 1; }

    void push(int x) {
        if (isFull ()) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
        cout << x << " pushed into stack\n";
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return;
        }
        cout << arr[top--] << " popped from Stack\n";
    }

    void peek() {
        if (isEmpty()) cout << "Stack is Empty\n";
        else cout << "Top element is " << arr[top] << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is Empty\n";
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0 ; i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        
    }
};
int main(){
    stack s;
    int choice, val;

    while(true) {
        cout << "\n1.PUSH  2.POP  3.PEEK  4.DISPLAY  5.EXIT\nEnter choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1 : 
            cout << "Enter Value : ";
            cin >> val;
            s.push(val);
            break;
        case 2 :
            s.pop();
            break;
        case 3 :
            s.peek();
            break;
        case 4 :
            s.display();
            break;
        case 5 :
            exit(0);
        default:
            cout << "Invalid Choice\n";
            break;
        }
    }
    
    return 0;
}
