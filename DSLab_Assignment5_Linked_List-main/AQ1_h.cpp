/*
Display all the nodes values.
*/
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

void printList(Node* head) {
    Node* temp = head;
    cout << "Linked List: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node();
    head->data = 10; head->next = new Node();
    head->next->data = 20; head->next->next = new Node();
    head->next->next->data = 30; head->next->next->next = NULL;

    printList(head);
    return 0;
}
