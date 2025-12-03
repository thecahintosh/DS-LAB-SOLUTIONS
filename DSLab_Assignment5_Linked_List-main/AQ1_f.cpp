/*
(f) Deletion of a specific node
*/
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

void deleteNode(Node** head, int target) {
    if (*head == NULL) return;

    if ((*head)->data == target) {
        Node* temp = *head;
        *head = (*head)->next;
        delete temp;
        cout << "Deleted Node " << target << endl;
        return;
    }

    Node* temp = *head;
    while (temp->next != NULL && temp->next->data != target)
        temp = temp->next;

    if (temp->next == NULL) {
        cout << target << " not found!\n";
        return;
    }

    Node* del = temp->next;
    temp->next = temp->next->next;
    delete del;
    cout << "Deleted Node " << target << endl;
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
    head->next->data = 20; head->next->next = new Node();
    head->next->next->data = 30; head->next->next->next = NULL;

    deleteNode(&head, 20);
    printList(head);
    return 0;
}
