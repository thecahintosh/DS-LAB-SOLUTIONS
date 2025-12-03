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
        bool insertAtBeg(int val){
            int key = hashFunc(val);
            Node* curr = Table[key];
            while(curr != nullptr){
                if(curr->data == val){
                    return true;
                }
                curr = curr->next;
            }
            Node* newNode = new Node(val);
            newNode->next = Table[key];
            Table[key] = newNode;
            return false;
        }
};
bool HasDuplicate(int nums[],int n) {
    HashSet set;
    for(int i = 0; i < n; i++){
        if(set.insertAtBeg(nums[i])) {
            return true;
        }
    }
    return false;
}
int main(){
    int nums[] = {1,2,3,1};
    int n = sizeof(nums)/sizeof(nums[0]);
    cout << "Has Duplicate : ";
    if(HasDuplicate(nums,n)){
        cout << "true";
    }
    else{cout << "false";}
    return 0;
}
