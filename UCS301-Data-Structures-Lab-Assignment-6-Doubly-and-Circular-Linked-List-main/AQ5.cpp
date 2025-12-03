#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};


class LinkedList {
public:
    Node* head;
    LinkedList() {
        head = nullptr;
    }

    void insertEnd(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
    }

    void makeCircular() {
        if (head == nullptr) return;
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = head; 
    }

    bool isCircular() {
        if (head == nullptr)
            return false;

        Node* temp = head->next;

        while (temp != nullptr && temp != head)
            temp = temp->next;

        return (temp == head);
    }

    void display() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        int count = 0;
        cout << "List: ";
        while (temp != nullptr && count < 10) {
            cout << temp->data << " -> ";
            temp = temp->next;
            count++;
        }
        cout << "\n";
    }
};

int main() {
    LinkedList list;
    int n, val, choice;

    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter " << n << " values:\n";
    for (int i = 0; i < n; i++) {
        cin >> val;
        list.insertEnd(val);
    }

    cout << endl;
    list.display();

    if (list.isCircular())
        cout << " The linked list is circular.\n";
    else
        cout << " The linked list is NOT circular.\n";


    cout << "making the list circular\n";
    list.makeCircular();

    cout << endl;
    list.display();

    if (list.isCircular())
        cout << " The linked list is circular.\n";
    else
        cout << " The linked list is NOT circular.\n";

    return 0;
}
