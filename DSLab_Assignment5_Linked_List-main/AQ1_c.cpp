/*
(c) Insertion in between (before or after a node having a specific value, say 'Insert a
new Node 35 before/after the Node 30').
*/
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

void insertAfter(Node* head, int target, int data) {
    Node* temp = head;
    while (temp != NULL && temp->data != target)
        temp = temp->next;

    if (temp == NULL) {
        cout << target << " not found!\n";
        return;
    }

    Node* new_node = new Node();
    new_node->data = data;
    new_node->next = temp->next;
    temp->next = new_node;
    cout << "Inserted " << data << " after " << target << endl;
}

void insertBefore(Node** head, int target, int data) {
    Node* new_node = new Node();
    new_node->data = data;

    if (*head == NULL) return;

    if ((*head)->data == target) {
        new_node->next = *head;
        *head = new_node;
        cout << "Inserted " << data << " before " << target << endl;
        return;
    }

    Node* temp = *head;
    while (temp->next != NULL && temp->next->data != target)
        temp = temp->next;

    if (temp->next == NULL) {
        cout << target << " not found!\n";
        return;
    }

    new_node->next = temp->next;
    temp->next = new_node;
    cout << "Inserted " << data << " before " << target << endl;
}

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
    head->data = 10; head->next = NULL;

    insertAfter(head, 10, 15);
    insertBefore(&head, 10, 5);
    printList(head);
    return 0;
}
