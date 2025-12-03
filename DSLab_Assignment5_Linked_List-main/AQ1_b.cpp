/*
(b) Insertion at the end.
*/
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

void insertEnd(Node** head, int data) {
    Node* new_node = new Node();
    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        cout << "Inserted at End: " << data << endl;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = new_node;
    cout << "Inserted at End: " << data << endl;
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
    Node* head = NULL;
    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    printList(head);
    return 0;
}
