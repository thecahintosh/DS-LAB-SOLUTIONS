#include <iostream>
using namespace std;

const int MAX = 1000; 
class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* hashTable[MAX] = { nullptr };

int getHashIndex(Node* ptr) {
    return reinterpret_cast<long long>(ptr) % MAX;
}

bool detectLoop(Node* head) {
    Node* temp = head;

    while (temp != nullptr) {
        int idx = getHashIndex(temp);

        if (hashTable[idx] == temp) {
            return true;
        }

        hashTable[idx] = temp;

        temp = temp->next;
    }
    return false;  
}

Node* newNode(int data) {
    return new Node(data);
}

int main() {
    
    Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);

    head->next->next->next->next = head->next;

    if (detectLoop(head))
        cout << "true";
    else
        cout << "false";

    return 0;
}
