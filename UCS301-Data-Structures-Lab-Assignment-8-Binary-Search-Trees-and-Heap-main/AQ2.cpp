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

    void InorderFill(Node *node, int arr[], int &i)
    {
        if (!node)
            return;
        InorderFill(node->left, arr, i);
        arr[i++] = node->data;
        InorderFill(node->right, arr, i);
    }

public:
    BST() { root = nullptr; }

    Node *getRoot() { return root; }

    int countNodes(Node *node)
    {
        if (!node)
            return 0;
        return 1 + countNodes(node->left) + countNodes(node->right);
    }

    int *InorderArr(int &n)
    {
        n = countNodes(root);
        int *arr = new int[n];
        int idx = 0;
        InorderFill(root, arr, idx);
        return arr;
    }

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
        } // curr points to newnode parent;
        if (val < prev->data)
        {
            prev->left = newNode;
        }
        else
        {
            prev->right = newNode;
        }
    }

    Node *SearchNonRecursive(int key)
    {
        if (root == nullptr)
        {
            cout << "Tree is empty\n";
            return nullptr;
        }

        Node *curr = root;

        while (curr != nullptr && curr->data != key)
        {
            if (key < curr->data)
            {
                curr = curr->left;
            }
            else
            {
                curr = curr->right;
            }
        }

        if (curr == nullptr)
        {
            cout << "Not found\n";
            return nullptr;
        }
        else
        {
            cout << "Found!\n";
            return curr;
        }
    }
    Node *SearchRecursive(Node *curr, int key)
    {
        if (curr == nullptr)
        {
            cout << "Not found\n";
            return nullptr;
        }
        if (curr->data == key)
        {
            cout << "Found!\n";
            return curr;
        }
        if (key < curr->data)
        {
            return SearchRecursive(curr->left, key);
        }
        else
        {
            return SearchRecursive(curr->right, key);
        }
    }

    int minimum(Node *node)
    { // get Tree max or subtree max both;
        if (node == nullptr)
            return 0;
        while (node->left != nullptr)
        {
            node = node->left;
        }
        return node->data;
    }
    int maximum(Node *node)
    {
        if (!node)
        {
            return 0;
        }
        while (node->right != nullptr)
        {
            node = node->right;
        }
        return node->data;
    }

    void inorderSuccessor(int key)
    {
        int n;
        int *arr = InorderArr(n);

        for (int i = 0; i < n; i++)
        {
            if (arr[i] == key)
            {
                if (i == n - 1)
                {
                    cout << "No successor\n";
                    return;
                }
                cout << arr[i + 1] << endl;
                return;
            }
        }

        cout << "Key not found\n";
        return;
    }
    void inorderPredecessor(int key)
    {
        int n;
        int *arr = InorderArr(n);

        for (int i = 0; i < n; i++)
        {
            if (arr[i] == key)
            {
                if (i == 0)
                {
                    cout << "No predecessor\n";
                    return;
                }
                cout << arr[i - 1] << endl;
                return;
            }
        }

        cout << "Key not found\n";
        return;
    }
};
int main()
{
    BST tree;

    tree.Insert(40);
    tree.Insert(20);
    tree.Insert(60);
    tree.Insert(10);
    tree.Insert(30);
    tree.Insert(50);
    tree.Insert(70);

    int x;
    cout << "Enter element to search : ";
    cin >> x;

    cout << "\n__________________________________________________________________\n\n";

    cout << "Searching " << x << " and then " << x + 10 << endl;
    cout << "\nRecursive Search\n";
    tree.SearchRecursive(tree.getRoot(), x);

    cout << "\nIterative Search\n";
    tree.SearchNonRecursive(x + 10);

    cout << "__________________________________________________________________\n\n";

    cout << "The Maximum element : " << tree.maximum(tree.getRoot()) << endl;
    cout << "The Minimum element : " << tree.minimum(tree.getRoot()) << endl;

    cout << "__________________________________________________________________\n\n";

    cout << "Successor and predecessor of " << x << endl;
    cout << "The Inorder Successor : ";
    tree.inorderSuccessor(x);
    cout << "The Inorder Predecessor : ";
    tree.inorderPredecessor(x);

    cout << "__________________________________________________________________\n\n";

    return 0;
}