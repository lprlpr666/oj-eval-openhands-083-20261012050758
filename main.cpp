#include <iostream>

using namespace std;

// Node structure for singly circular linked list
struct Node {
    int data;
    Node* next;
    
    Node(int val) : data(val), next(nullptr) {}
};

class CircularLinkedList {
private:
    Node* head;
    int size;
    
public:
    CircularLinkedList() : head(nullptr), size(0) {}
    
    // Build circular linked list with n nodes (1 to n)
    void buildList(int n) {
        if (n <= 0) return;
        
        head = new Node(1);
        Node* current = head;
        
        for (int i = 2; i <= n; i++) {
            current->next = new Node(i);
            current = current->next;
        }
        
        // Make it circular
        current->next = head;
        size = n;
    }
    
    // Josephus ring simulation
    void josephusSimulation(int m) {
        if (head == nullptr || size == 0) return;
        
        Node* current = head;
        Node* prev = nullptr;
        
        // Find the node before head (last node)
        while (prev == nullptr || prev->next != head) {
            if (prev == nullptr) {
                prev = head;
                while (prev->next != head) {
                    prev = prev->next;
                }
            } else {
                break;
            }
        }
        
        while (size > 1) {
            // Move (m-1) steps to find the m-th node
            for (int i = 1; i < m; i++) {
                prev = current;
                current = current->next;
            }
            
            // Remove current node
            cout << current->data << endl;
            prev->next = current->next;
            
            Node* toDelete = current;
            current = current->next;
            
            // Update head if necessary
            if (toDelete == head) {
                head = current;
            }
            
            delete toDelete;
            size--;
        }
        
        // Output the last remaining node
        if (current != nullptr) {
            cout << current->data << endl;
            delete current;
            head = nullptr;
            size = 0;
        }
    }
    
    ~CircularLinkedList() {
        if (head == nullptr) return;
        
        Node* current = head;
        Node* nextNode = nullptr;
        
        // Break the circular reference first
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = nullptr;
        
        // Delete all nodes
        while (current != nullptr) {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    
    CircularLinkedList list;
    list.buildList(n);
    list.josephusSimulation(m);
    
    return 0;
}