/*
(d) Deletion from the beginning.
*/
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

void deleteBeginning(Node** head) {
    if (*head == NULL) return;

    Node* temp = *head;
    *head = (*head)->next;
    cout << "Deleted from Beginning: " << temp->data << endl;
    delete temp;
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
    head->data = 10; head->next = new Node();
    head->next->data = 20; head->next->next = NULL;

    deleteBeginning(&head);
    printList(head);
    return 0;
}
