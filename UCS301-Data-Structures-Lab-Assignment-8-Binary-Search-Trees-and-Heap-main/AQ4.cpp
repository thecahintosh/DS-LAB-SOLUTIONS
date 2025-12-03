#include<iostream>
#include<climits>
using namespace std;
class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node* parent;
        Node(int val){
            data = val;
            left = right = parent = nullptr;
        }
};


bool checkBST(Node* node, int minVal, int maxVal){
    if(!node) return true;

    if(node->data <= minVal || node->data >= maxVal)
        return false;

    return checkBST(node->left, minVal, node->data) &&
           checkBST(node->right, node->data, maxVal);
}
bool isBST(Node* node){
    return checkBST(node, INT_MIN, INT_MAX);
}
int main(){
    cout << "_________________________________\n" << endl;
    cout << "Tree 1 : "<< endl;
    cout << "  8\n";
    cout << " / \\" << endl;
    cout << "3   10\n";
    cout << "    / \\"<< endl;
    cout << "   2   12\n";

    Node* root1 = new Node(8);
    root1->left = new Node(3);
    root1->right = new Node(10);
    root1->right->left = new Node(2); 
    root1->right->right = new Node(12);

    cout << "BST ? ";
    if(isBST(root1)){cout << "yes" << endl;}
    else{cout << "no" << endl;}

    cout << "_________________________________\n" << endl;
    cout << "Tree 2 : "<< endl;
    cout << "  8\n";
    cout << " / \\" << endl;
    cout << "3   10\n";
    cout << "      \\"<< endl;
    cout << "       12\n";

    Node* root2 = new Node(8);
    root2->left = new Node(3);
    root2->right = new Node(10);
    root2->right->right = new Node(12);
    
    cout << "BST ? ";
    if(isBST(root2)){cout << "yes" << endl;}
    else{cout << "no" << endl;}

    cout << "_________________________________\n" << endl;

    return 0;
}