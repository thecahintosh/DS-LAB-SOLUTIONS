#include <iostream>
using namespace std;
const int SIZE = 10;
class Node
{
public:
    int data;
    int freq;
    Node *next;
    Node(int val, int f = 1) : data(val), freq(f), next(nullptr) {}
};
class HashMap
{
private:
    Node *Table[SIZE];
    int hashFunc(int val)
    {
        return val % SIZE;
    }

public:
    HashMap()
    {
        for (int i = 0; i < SIZE; i++)
        {
            Table[i] = nullptr;
        }
    }
    void insert(int val)
    {
        int index = hashFunc(val);
        Node *curr = Table[index];
        while (curr != nullptr)
        {
            if (curr->data == val)
            {
                curr->freq++;
                return;
            }
        }
        Node *newNode = new Node(val);
        newNode->next = Table[index];
        Table[index] = newNode;
    }
    void display()
    {
        for (int i = 0; i < SIZE; i++)
        {
            Node *curr = Table[i];
            while (curr != nullptr)
            {
                cout << curr->data << " ----> " << curr->freq << "times" << endl;
                curr = curr->next;
            }
        }
    }
};
int main()
{
    int nums[] = {2, 3, 2, 4, 3, 2};
    int n = sizeof(nums) / sizeof(nums[0]);

    HashMap map;

    for (int i = 0; i < n; i++)
    {
        map.insert(nums[i]);
    }
    map.display();
    return 0;
}
