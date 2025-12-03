#include<iostream>
using namespace std;
const int max_size = 10;
class Node {
    public:
        int data;
        Node* next;
        Node(int val) : data(val),next(nullptr) {}
};
class HashSet {
    private:
        Node* Table[max_size];
        int hashFunc(int val){
            return val % max_size;
        }
    public:
        HashSet() {
            for(int i = 0; i < max_size; i++){
                Table[i] = nullptr;
            }
        }
        bool exists(int val) {
            int key = hashFunc(val);
            Node* curr = Table[key];
                while(curr != nullptr){
                    if(curr->data == val){
                        return true;
                    }
                    curr = curr->next;
                }
            return false;
        }
        bool insert(int val){
            if(exists(val)) return true;
            int key = hashFunc(val);
            Node* newNode = new Node(val);
            newNode->next = Table[key];
            Table[key] = newNode;
            return false;
        }
};
void sameEle(int A[],int sizeA,int B[],int sizeB){
    HashSet set;
    for(int i = 0; i < sizeA; i++){
        set.insert(A[i]);
    }
    for(int i = 0; i < sizeB; i++){
        if(set.exists(B[i])){
            cout << B[i] << " ";
        }

    }
}
int main(){
    int A[] = {1,2,3,4};
    int B[] = {3,4,5,6};
    int a = sizeof(A)/sizeof(A[0]);
    int b = sizeof(B)/sizeof(B[0]);
    cout << "common elements : ";
    sameEle(A,a,B,b);
    return 0;
}