/*
middle of linked list.
*/
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
  
    Node(int x) {
        this->data = x;
        this->next = nullptr;
    }
};

int getLength(Node* head) {

    int length = 0;

    while (head) {
        length++;
        head = head->next;
    }

    return length;
}

int getMiddle(Node* head) {

    int length = getLength(head);

    // traverse till we reached half of length
    int midIndex = length / 2;
    while (midIndex--) {
        head = head->next;
    }

    return head->data;
}

int main() {

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << getMiddle(head);

    return 0;
}
