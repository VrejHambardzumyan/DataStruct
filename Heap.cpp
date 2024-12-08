#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
private:
    vector<int> heap;

 
    int parent(int i) { return (i - 1) / 2; }

    
    int leftChild(int i) { return 2 * i + 1; }

  
    int rightChild(int i) { return 2 * i + 2; }

    void heapifyUp(int index) {
        while (index > 0 && heap[parent(index)] < heap[index]) {
            swap(heap[parent(index)], heap[index]);
            index = parent(index);
        }
    }

    
    void heapifyDown(int index) {
        int largest = index;
        int left = leftChild(index);
        int right = rightChild(index);

        if (left < heap.size() && heap[left] > heap[largest])
            largest = left;

        if (right < heap.size() && heap[right] > heap[largest])
            largest = right;

        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

   
    int extractMax() {
        if (heap.empty()) {
            throw runtime_error("Heap is empty");
        }

        int maxValue = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);

        return maxValue;
    }

   
    int getMax() {
        if (heap.empty()) {
            throw runtime_error("Heap is empty");
        }
        return heap[0];
    }

    
    void printHeap() {
        for (int val : heap) {
            cout << val << " ";
        }
        cout << endl;
    }
};

int main() {
    MaxHeap heap;

    heap.insert(10);
    heap.insert(20);
    heap.insert(5);
    heap.insert(30);

    cout << "Heap elements: ";
    heap.printHeap();

    cout << "Max element: " << heap.getMax() << endl;

    cout << "Extracted max: " << heap.extractMax() << endl;
    cout << "Heap after extraction: ";
    heap.printHeap();

    return 0;
}
