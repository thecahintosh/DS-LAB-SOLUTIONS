#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node *parent;
    Node(int val) : data(val), left(nullptr), right(nullptr), parent(nullptr) {}
};
class BST
{
private:
    Node *root;

public:
    BST() { root = nullptr; }

    Node *getRoot() { return root; }

    Node *SearchNonRecursive(int key)
    {
        if (root == nullptr)
        {
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
            return nullptr;
        }
        else
        {
            return curr;
        }
    }


    void Insert(int val)
    {
        Node *newNode = new Node(val);

        if (!root)
        {
            root = newNode;
            return;
        }

        Node *curr = root;
        Node *prev = nullptr;

        while (curr != nullptr)
        {
            prev = curr;

            if (val == curr->data)
            {
                delete newNode;
                return;
            }
            else if (val < curr->data)
            {
                curr = curr->left;
            }
            else
            {
                curr = curr->right;
            }
        }

        newNode->parent = prev;

        if (val < prev->data)
            prev->left = newNode;
        else
            prev->right = newNode;
    }

    void Delete(int key)
    {
        Node *node = SearchNonRecursive(key);
        if (!node)
            return;

        Node *parent = node->parent;

        // 1. no child
        if (!node->left && !node->right)
        {
            if (node == root)
            {
                root = nullptr;
            }
            else
            {
                if (parent->left == node)
                {
                    parent->left = nullptr;
                }
                else
                {
                    parent->right = nullptr;
                }
            }
            delete node;
            return;
        }

        // 2. one child
        if (!node->left || !node->right)
        {
            Node *child = node->left ? node->left : node->right; // whichever is not nullpts becomes "child".
            if (node == root)
            {
                root = child;
                child->parent = nullptr;
            }
            else
            {
                if (parent->left == node)
                {
                    parent->left = child;
                }
                else
                {
                    parent->right = child;
                }

                child->parent = parent;
            }
            delete node;
            return;
        }

        // 3. two children
       
        Node* successor = node->right;
        while (successor->left)
            successor = successor->left;

        int temp = successor->data;
        successor->data = node->data;
        node->data = temp;

        if (!successor->left && !successor->right) {
            if (successor->parent->left == successor)
                successor->parent->left = nullptr;
            else
                successor->parent->right = nullptr;

            delete successor;
        }
        else {
            Node* child = successor->left ? successor->left : successor->right;

            if (successor->parent->left == successor)
                successor->parent->left = child;
            else
                successor->parent->right = child;

            child->parent = successor->parent;

            delete successor;
        }

    }

    int MaxDepthBST(Node* node){
        if(!node) return 0;
        int leftDepth = MaxDepthBST(node->left);
        int rightDepth = MaxDepthBST(node->right);
        return 1+max(leftDepth,rightDepth);
    }

    
    int MinDepthBST(Node* node){
        if(!node) return 0;
        if(!node->left) return 1 + MinDepthBST(node->right);
        if(!node->right) return 1 + MinDepthBST(node->right);
        return 1 + min(MinDepthBST(node->left),MinDepthBST(node->right));
    }

    void Inorder(Node *curr)
    {
        if (!curr)
            return;
        Inorder(curr->left);
        cout << curr->data << " ";
        Inorder(curr->right);
    }
};
int main()
{
    BST tree;
    tree.Insert(10);
    tree.Insert(5);
    tree.Insert(15);
    tree.Insert(1);
    tree.Insert(6);
    tree.Insert(15);
    tree.Inorder(tree.getRoot());

    cout << "\nMinimum depth of tree : " << tree.MinDepthBST(tree.getRoot()) << endl;
    cout << "Maximum depth of tree : " << tree.MaxDepthBST(tree.getRoot()) << endl;

    cout << "deleting...\n";
    tree.Delete(6);
    cout << "after deletion\n";
    tree.Inorder(tree.getRoot());
    return 0;
}