#include <iostream>
using namespace std;

#define MAX 100

class Stack {
    int top;
    int arr[MAX];
public:
    Stack() { top = -1; }
    bool isEmpty() { return top == -1; }
    bool isFull() { return top == MAX - 1; }
    void push(int x) {
        if (!isFull()) arr[++top] = x;
    }
    int pop() {
        if (!isEmpty()) return arr[top--];
        return -1;
    }
};

int evaluatePostfix(char exp[]) {
    Stack s;
    for (int i = 0; exp[i] != '\0'; i++) {
        char c = exp[i];

        if (c >= '0' && c <= '9') {
            s.push(c - '0');
        }
        else {
            int val2 = s.pop();
            int val1 = s.pop();
            switch (c) {
                case '+': s.push(val1 + val2); break;
                case '-': s.push(val1 - val2); break;
                case '*': s.push(val1 * val2); break;
                case '/': s.push(val1 / val2); break;
            }
        }
    }
    return s.pop();
}

int main() {
    char exp[] = "53+2*";
    cout << "Postfix Evaluation: " << evaluatePostfix(exp) << endl;
    return 0;
}
