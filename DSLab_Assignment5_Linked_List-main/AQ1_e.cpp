/*
(e) Deletion from the end.
*/
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

void deleteEnd(Node** head) {
    if (*head == NULL) return;

    if ((*head)->next == NULL) {
        cout << "Deleted from End: " << (*head)->data << endl;
        delete *head;
        *head = NULL;
        return;
    }

    Node* temp = *head;
    while (temp->next->next != NULL)
        temp = temp->next;

    cout << "Deleted from End: " << temp->next->data << endl;
    delete temp->next;
    temp->next = NULL;
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

    deleteEnd(&head);
    printList(head);
    return 0;
}
