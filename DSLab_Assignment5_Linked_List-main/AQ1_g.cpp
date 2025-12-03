/*
(g) Search for a node and display its position from head.
*/
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

void searchNode(Node* head, int target) {
    Node* temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == target) {
            cout << "Node " << target << " found at position " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << target << " not found!\n";
}

int main() {
    Node* head = new Node();
    head->data = 10; head->next = new Node();
    head->next->data = 20; head->next->next = new Node();
    head->next->next->data = 30; head->next->next->next = NULL;

    searchNode(head, 20);
    searchNode(head, 100);
    return 0;
}
