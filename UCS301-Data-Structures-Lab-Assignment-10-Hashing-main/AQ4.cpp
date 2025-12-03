#include <iostream>
using namespace std;
const int TABLE_SIZE = 10;
class Node {
public:
    int key;
    int freq;
    Node* next;
    Node(int k) : key(k), freq(1), next(nullptr) {}
};
class HashMap {
private:
    Node* table[TABLE_SIZE];
    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }
public:
    HashMap() {
        for (int i = 0; i < TABLE_SIZE; i++)
            table[i] = nullptr;
    }
    void insert(int key) {
        int index = hashFunction(key);
        Node* curr = table[index];
        while (curr != nullptr) {
            if (curr->key == key) {
                curr->freq++;
                return;
            }
            curr = curr->next;
        }
        Node* newNode = new Node(key);
        newNode->next = table[index];
        table[index] = newNode;
    }
    int getFreq(int key) {
        int index = hashFunction(key);
        Node* curr = table[index];
        while (curr != nullptr) {
            if (curr->key == key)
                return curr->freq;
            curr = curr->next;
        }
        return 0;
    }
};

int main() {
    int arr[] = {4, 5, 1, 2, 0, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    HashMap map;

    for (int i = 0; i < n; i++)
        map.insert(arr[i]);

    for (int i = 0; i < n; i++) {
        if (map.getFreq(arr[i]) == 1) {
            cout << arr[i];
            return 0;
        }
    }

    cout << "No non-repeating element";
    return 0;
}
