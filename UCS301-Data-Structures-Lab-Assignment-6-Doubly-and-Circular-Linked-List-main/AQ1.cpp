#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
    Node(int num) {
        data = num;
        prev = next = nullptr;
    }
};

class DoublyLinkedList {
public:
    Node* head;
    DoublyLinkedList() { head = nullptr; }

    void InsertBeg(int num) {
        Node* newNode = new Node(num);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void InsertEnd(int num) {
        Node* newNode = new Node(num);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    void InsertAfter(int key, int data) {
        Node* temp = head;
        while (temp != nullptr && temp->data != key)
            temp = temp->next;
        if (temp == nullptr) {
            cout << "Node not found!\n";
            return;
        }
        Node* newNode = new Node(data);
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != nullptr)
            temp->next->prev = newNode;
        temp->next = newNode;
    }

    void InsertBefore(int key, int data) {
        Node* temp = head;
        while (temp != nullptr && temp->data != key)
            temp = temp->next;
        if (temp == nullptr) {
            cout << "Node not found!\n";
            return;
        }
        Node* newNode = new Node(data);
        newNode->next = temp;
        newNode->prev = temp->prev;
        if (temp->prev != nullptr)
            temp->prev->next = newNode;
        else
            head = newNode;
        temp->prev = newNode;
    }

    void DeleteNode(int key) {
        if (head == nullptr) {
            cout << "List empty\n";
            return;
        }
        Node* temp = head;
        if (temp->data == key) {
            head = temp->next;
            if (head)
                head->prev = nullptr;
            delete temp;
            return;
        }
        while (temp != nullptr && temp->data != key)
            temp = temp->next;
        if (temp == nullptr) {
            cout << "Node not found!\n";
            return;
        }
        if (temp->next)
            temp->next->prev = temp->prev;
        if (temp->prev)
            temp->prev->next = temp->next;
        delete temp;
        cout << "Node " << key << " deleted.\n";
    }

    void Search(int num) {
        Node* temp = head;
        int pos = 1;
        while (temp != nullptr && temp->data != num) {
            temp = temp->next;
            pos++;
        }
        if (temp == nullptr)
            cout << "Node not found!\n";
        else
            cout << "Node " << num << " found at position " << pos << endl;
    }

    void Display() {
        if (head == nullptr) {
            cout << "List empty\n";
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

class CircularDoublyLinkedList {
public:
    Node* head;
    CircularDoublyLinkedList() { head = nullptr; }

    void InsertBeg(int num) {
        Node* newNode = new Node(num);
        if (head == nullptr) {
            head = newNode;
            head->next = head->prev = head;
            return;
        }
        Node* tail = head->prev;
        newNode->next = head;
        newNode->prev = tail;
        tail->next = newNode;
        head->prev = newNode;
        head = newNode;
    }

    void InsertEnd(int num) {
        Node* newNode = new Node(num);
        if (head == nullptr) {
            head = newNode;
            head->next = head->prev = head;
            return;
        }
        Node* tail = head->prev;
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = head;
        head->prev = newNode;
    }

    void InsertAfter(int key, int data) {
        if (head == nullptr) {
            cout << "List empty\n";
            return;
        }
        Node* temp = head;
        do {
            if (temp->data == key) {
                Node* newNode = new Node(data);
                newNode->next = temp->next;
                newNode->prev = temp;
                temp->next->prev = newNode;
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Node not found!\n";
    }

    void InsertBefore(int key, int data) {
        if (head == nullptr) {
            cout << "List empty\n";
            return;
        }
        Node* temp = head;
        do {
            if (temp->data == key) {
                Node* newNode = new Node(data);
                newNode->next = temp;
                newNode->prev = temp->prev;
                temp->prev->next = newNode;
                temp->prev = newNode;
                if (temp == head)
                    head = newNode;
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Node not found!\n";
    }

    void DeleteNode(int key) {
        if (head == nullptr) {
            cout << "List empty\n";
            return;
        }
        Node* temp = head;
        do {
            if (temp->data == key) {
                if (temp->next == temp && temp->prev == temp) { // only one node
                    head = nullptr;
                } else {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    if (temp == head)
                        head = temp->next;
                }
                delete temp;
                cout << "Node " << key << " deleted.\n";
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Node not found!\n";
    }

    void Search(int num) {
        if (head == nullptr) {
            cout << "List empty\n";
            return;
        }
        Node* temp = head;
        int pos = 1;
        do {
            if (temp->data == num) {
                cout << "Node " << num << " found at position " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        } while (temp != head);
        cout << "Node not found!\n";
    }

    void Display() {
        if (head == nullptr) {
            cout << "List empty\n";
            return;
        }
        Node* temp = head;
        cout << "Circular List: ";
        do {
            cout << temp->data << " <-> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(back to head)\n";
    }
};

int main() {
    DoublyLinkedList dll;
    CircularDoublyLinkedList cdll;
    int choice, listType, val, key;

    while (true) {
        cout << "\n=== MAIN MENU ===\n";
        cout << "1. Doubly Linked List\n";
        cout << "2. Circular Doubly Linked List\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> listType;

        if (listType == 3) break;

        while (true) {
            cout << "\n--- OPERATIONS MENU ---\n";
            cout << "1. Insert at Beginning\n";
            cout << "2. Insert at End\n";
            cout << "3. Insert After a Node\n";
            cout << "4. Insert Before a Node\n";
            cout << "5. Delete a Node\n";
            cout << "6. Search a Node\n";
            cout << "7. Display List\n";
            cout << "8. Go Back to Main Menu\n";
            cout << "Enter choice: ";
            cin >> choice;

            if (choice == 8) break;

            switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                (listType == 1) ? dll.InsertBeg(val) : cdll.InsertBeg(val);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> val;
                (listType == 1) ? dll.InsertEnd(val) : cdll.InsertEnd(val);
                break;
            case 3:
                cout << "Enter key and value: ";
                cin >> key >> val;
                (listType == 1) ? dll.InsertAfter(key, val) : cdll.InsertAfter(key, val);
                break;
            case 4:
                cout << "Enter key and value: ";
                cin >> key >> val;
                (listType == 1) ? dll.InsertBefore(key, val) : cdll.InsertBefore(key, val);
                break;
            case 5:
                cout << "Enter value to delete: ";
                cin >> key;
                (listType == 1) ? dll.DeleteNode(key) : cdll.DeleteNode(key);
                break;
            case 6:
                cout << "Enter value to search: ";
                cin >> key;
                (listType == 1) ? dll.Search(key) : cdll.Search(key);
                break;
            case 7:
                (listType == 1) ? dll.Display() : cdll.Display();
                break;
            default:
                cout << "Invalid choice!\n";
            }
        }
    }
    cout << "Program exited successfully.\n";
    return 0;
}
