#include <iostream>
#include <vector>
using namespace std;

class MyHashMap {
private:
    struct Node {
        int key;
        int value;
        Node* next;
        Node(int k, int v) : key(k), value(v), next(nullptr) {}
    };

    vector<Node*> buckets;
    static const int numBuckets = 10;

public:
    MyHashMap() {
        buckets = vector<Node*>(numBuckets, nullptr);
    }

    void put(int key, int value) {
        int index = key % numBuckets;

        cout << "Adding key " << key << " with value " << value << " to bucket " << index << endl;

        if (buckets[index] == nullptr) {
            buckets[index] = new Node(key, value);
        } else {
             // Traverse the linked list in the bucket
            Node* curr = buckets[index];
            while (curr) {
                if (curr->key == key) {
                    curr->value = value;
                    return;
                }
                if (curr->next == nullptr) break;
                curr = curr->next;
            }
            curr->next = new Node(key, value);
        }
    }

    int get(int key) {
        int index = key % numBuckets;
        Node* curr = buckets[index];

        while (curr) {
            if (curr->key == key) {
                return curr->value;
            }
            curr = curr->next;
        }
        return -1; 
    }

    void print() {
        cout << "\nHash Map Structure:\n";
        for (int i = 0; i < numBuckets; i++) {
            cout << "Bucket " << i << ": ";
            Node* curr = buckets[i];
            while (curr) {
                cout << "(" << curr->key << ", " << get(curr->key) << ") -> ";
                curr = curr->next;
            }
            cout << "NULL\n";
        }
    }
};
int main() {
    MyHashMap hashMap;

    hashMap.put(2, 20);  
    hashMap.put(12, 120); 
    hashMap.put(7, 70); 
    hashMap.put(17, 170); 
    hashMap.put(5, 50); 

    hashMap.print();
}