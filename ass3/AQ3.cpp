#include<iostream>
using namespace std;

#define MAX 100

class CharStack {
    char arr[MAX];
    int top;

public: 
    CharStack () { top = -1; }

    bool isEmpty() { return top == -1; }
    bool isFull() { return top == MAX - 1; }

    void push(char ch) {
        if(isFull()) {
            cout << "Stack Overfully" << endl;
            return;
        }
        arr[++top] = ch;
    }

    char pop() {
        if(isEmpty()) {
            cout << "Stack Underflow" << endl;
            return '\0';
        }
        return arr[top--];
    }

    char peek() {
        if(isEmpty()) {
            cout << "Stack Underflow" << endl;
            return '\0';
        }
        return arr[top];
    }

};

bool isMatching(char open, char close){
    return  (open == '(' && close == ')') ||
            (open == '{' && close == '}') ||
            (open == '[' && close == ']');
}

bool isBalanced(string exp) {
    CharStack s;
    for( char c : exp ) {
        if( c == '(' || c == '{' || c == '[' ) {
            s.push(c);
        }

        else if(c == ')' || c == '}' || c == ']' ){
            if(s.isEmpty()) {
                return false;
            }
            char top = s.pop();
            if (!isMatching(top,c)){
                return false;
            }
        }
    }
    return s.isEmpty();
}

int main() {
    string exp;
    cout << "Enter expression: ";
    cin >> exp;

    if (isBalanced(exp))
        cout << "Balanced\n";
    else
        cout << "Not Balanced\n";

    return 0;
}
