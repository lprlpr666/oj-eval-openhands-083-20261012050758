#include <stdio.h>
#include <stdlib.h>

// Node structure for singly circular linked list
struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

struct Node* buildCircularList(int n) {
    if (n <= 0) return NULL;
    
    struct Node* head = createNode(1);
    struct Node* current = head;
    
    for (int i = 2; i <= n; i++) {
        current->next = createNode(i);
        current = current->next;
    }
    
    // Make it circular
    current->next = head;
    return head;
}

void josephusSimulation(struct Node* head, int n, int m) {
    if (head == NULL || n == 0) return;
    
    struct Node* current = head;
    struct Node* prev = NULL;
    
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
        printf("%d\n", current->data);
        prev->next = current->next;
        
        struct Node* toDelete = current;
        current = current->next;
        
        free(toDelete);
        remaining--;
    }
    
    // Output the last remaining node
    if (current != NULL) {
        printf("%d\n", current->data);
        free(current);
    }
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) {
        return 1;
    }
    
    struct Node* head = buildCircularList(n);
    josephusSimulation(head, n, m);
    
    return 0;
}