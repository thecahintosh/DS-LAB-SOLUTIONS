#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
class BST
{
private:
    Node *root;

public:
    BST() { root = nullptr; }
    Node *getRoot() { return root; }
    void Insert(int val)
    {
        Node *newNode = new Node(val);
        if (root == nullptr)
        {
            root = newNode;
            return;
        }
        Node *curr = root;
        Node *prev = nullptr;

        while (curr != nullptr)
        {
            prev = curr;
            if (val < curr->data)
            {
                curr = curr->left;
            }
            else
            {
                curr = curr->right;
            }
        }

        if (val < prev->data)
        {
            prev->left = newNode;
        }
        else
        {
            prev->right = newNode;
        }
        return;
    }

    void Preorder(Node *curr)
    {
        if (!curr)
            return;
        cout << curr->data << " ";
        Preorder(curr->left);
        Preorder(curr->right);
    }
    void Inorder(Node *curr)
    {
        if (!curr)
            return;
        Inorder(curr->left);
        cout << curr->data << " ";
        Inorder(curr->right);
    }
    void Postorder(Node *curr)
    {
        if (!curr)
            return;
        Postorder(curr->left);
        Postorder(curr->right);
        cout << curr->data << " ";
    }
};
int main()
{
    BST tree;
    int size;
    cout << "Enter number of Elements : ";
    cin >> size;
    cout << "Enter your Elements\n";

    for (int i = 0; i < size; i++)
    {
        int n;
        cin >> n;
        tree.Insert(n);
    }
    cout << "\n----------------------\n"
         << endl;
    cout << "Inorder\n";
    tree.Inorder(tree.getRoot());
    cout << "\n\nPreorder\n";
    tree.Preorder(tree.getRoot());
    cout << "\n\nPostorder\n";
    tree.Postorder(tree.getRoot());
    cout << "\n\n----------------------\n"
         << endl;
         

    return 0;
}