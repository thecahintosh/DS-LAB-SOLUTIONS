#include <iostream>
using namespace std;

class PriorityQueue {
private:
    int heap[100];
    int heapSize;
    

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    void maxHeapify(int i) {
        int l = left(i);
        int r = right(i);
        int largest = i;

        if (l < heapSize && heap[l] > heap[largest])
            largest = l;
        if (r < heapSize && heap[r] > heap[largest])
            largest = r;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            maxHeapify(largest);
        }
    }

public:
    PriorityQueue() { heapSize = 0; }

    bool isEmpty() { return heapSize == 0; }

    int getMax() {
        if (heapSize == 0) {
            cout << "Queue empty\n";
            return -1;
        }
        return heap[0];
    }

    void insert(int key) {
        heapSize++;
        int i = heapSize - 1;
        heap[i] = key;

        while (i != 0 && heap[parent(i)] < heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    int extractMax() {
        if (heapSize == 0) {
            cout << "Queue empty\n";
            return -1;
        }
        if (heapSize == 1) {
            heapSize--;
            return heap[0];
        }

        int maxVal = heap[0];
        heap[0] = heap[heapSize - 1];
        heapSize--;

        maxHeapify(0);

        return maxVal;
    }

    void increaseKey(int i, int newVal) {
        if (newVal < heap[i]) {
            cout << "New value smaller than current.\n";
            return;
        }
        heap[i] = newVal;

        while (i != 0 && heap[parent(i)] < heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    void print() {
        for (int i = 0; i < heapSize; i++)
            cout << heap[i] << " ";
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;

    pq.insert(10);
    pq.insert(40);
    pq.insert(15);
    pq.insert(50);
    pq.insert(30);

    cout << "Current PQ: ";
    pq.print();

    cout << "Max = " << pq.getMax() << endl;

    cout << "Extracted max = " << pq.extractMax() << endl;

    cout << "After extract: ";
    pq.print();

    pq.increaseKey(2, 60);
    cout << "After increaseKey: ";
    pq.print();

    return 0;
}
