/*
number od occurrencse of given key and delete them.
*/
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int new_data) {
        data = new_data;
        next = nullptr;
    }
};

Node* deleteOccurrences(Node* head, int key) {

    Node *curr = head, *prev = nullptr;

    while (curr != nullptr) {

        if (curr->data == key) {

            if (prev == nullptr) {
                head = curr->next;
            } 
          
            else {
                prev->next = curr->next;
            }

            curr = curr->next;

        } 
        
        else {
          
            prev = curr;
            curr = curr->next;
        }
    }

    return head;
}

void printList(Node* curr) {
    while (curr != nullptr) {
        cout << " " << curr->data;
        curr = curr->next;
    }
}

int main() {

    // 2 -> 2 -> 1 -> 8 -> 2 -> NULL
    Node* head = new Node(2);
    head->next = new Node(2);
    head->next->next = new Node(1);
    head->next->next->next = new Node(8);
    head->next->next->next->next = new Node(2);

    int key = 2;
    head = deleteOccurrences(head, key);
    printList(head);
    return 0;
}
