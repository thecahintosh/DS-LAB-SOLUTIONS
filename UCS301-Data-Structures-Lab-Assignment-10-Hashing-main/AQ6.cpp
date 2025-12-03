#include <iostream>
using namespace std;

#define MAX 1000

bool hashTable[MAX] = {false};

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

bool hasDuplicateHash(Node* root) {
    if (root == nullptr)
        return false;

    if (hashTable[root->data])
        return true;

    hashTable[root->data] = true;

    return hasDuplicateHash(root->left) || hasDuplicateHash(root->right);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(2); 

    if (hasDuplicateHash(root))
        cout << "Duplicates Found\n";
    else
        cout << "No Duplicates\n";

    return 0;
}
