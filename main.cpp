#include <iostream>

using namespace std;

// Node structure for singly circular linked list
struct Node {
    int data;
    Node* next;
};

Node* createNode(int val) {
    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = nullptr;
    return newNode;
}

Node* buildCircularList(int n) {
    if (n <= 0) return nullptr;
    
    Node* head = createNode(1);
    Node* current = head;
    
    for (int i = 2; i <= n; i++) {
        current->next = createNode(i);
        current = current->next;
    }
    
    // Make it circular
    current->next = head;
    return head;
}

void josephusSimulation(Node* head, int n, int m) {
    if (head == nullptr || n == 0) return;
    
    Node* current = head;
    Node* prev = nullptr;
    
    // Find the node before head (last node)
    prev = head;
    while (prev->next != head) {
        prev = prev->next;
    }
    
    int remaining = n;
    while (remaining > 1) {
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
        
        delete toDelete;
        remaining--;
    }
    
    // Output the last remaining node
    if (current != nullptr) {
        cout << current->data << endl;
        delete current;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    Node* head = buildCircularList(n);
    josephusSimulation(head, n, m);
    
    return 0;
}