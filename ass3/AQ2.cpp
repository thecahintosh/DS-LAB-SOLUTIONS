#include<iostream>
using namespace std;

#define MAX 100

class CharStack{
    char arr[MAX];
    int top;

public: 
    CharStack() { top = -1; }

    bool isEmpty() { return top == -1; }
    bool isFull() { return top == MAX - 1; }

    void push(char ch){
        if(isFull()){
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++top] = ch;
    }

    char pop(){
        if(isEmpty()){
            cout << "Stack Underflow" << endl;
            return '\0';
        }
        return arr[top--];
    }
};

string reverseString(string str){
    CharStack s;

    for(int i = 0 ; i < str.length(); i++){
        s.push(str[i]);
    }

    string rev = "";
    while(!s.isEmpty()){
        rev += s.pop();
    }
    return rev;
}

int main(){
    string input = "Datastructure";
    cout << "Original: " << input << endl;
    cout << "Reversed: " << reverseString(input) << endl;
    return 0;
}