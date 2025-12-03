#include<iostream>
using namespace std;

#define MAX 100

class CharStack {
    char arr[MAX];
    int top;

public: 
    CharStack() { top = -1; }

    bool isEmpty() { return top == -1; }
    bool isFull() { return top == MAX - 1; }

    void push(char c) {
        if(isFull()) {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++top] = c;
    }

    char pop() {
        if(isEmpty()) {
            return '\0';
        }
        return arr[top--];
    }

    char peek() {
        if(isEmpty()) {
            return '\0';
        }
        return arr[top];
    }
};

int precedence(char op) {
    if(op == '+' || op == '-') {
        return 1;
    }
    if(op == '*' || op == '/') {
        return 2;
    }
    if(op == '^') {
        return 3;
    }
    return 0;
}

string Infix_To_Postfix(string exp) {
    CharStack s;
    string result = "";

    for(char c : exp) {
        
        if( ( c >= 'a' && c <= 'z' ) || ( c >= 'A' && c <= 'Z' ) || ( c >= '0' && c <= '9' ) ) {
            result += c;
        }

        else if ( c == '(' ) {
            s.push(c);
        }

        else if ( c == ')' ) {
            while( !s.isEmpty() && s.peek() != '(' ) {
                result += s.pop();
            }
            s.pop();
        }
        
        else {
            while ( !s.isEmpty() && precedence(c) <= precedence(s.peek()) ) {
                result += s.pop();
            }
            s.push(c);
        }
    }

    while(!s.isEmpty()) {
        result += s.pop();
    }
    return result;
}

int main() {
    string exp;
    cout << "Enter Infix expression : ";
    cin >> exp;

    cout << "Postfix expression : " << Infix_To_Postfix(exp) << endl;
    return 0;
}