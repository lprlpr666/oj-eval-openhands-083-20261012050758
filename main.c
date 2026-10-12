#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    // Create circular linked list
    struct Node* nodes = (struct Node*)malloc(n * sizeof(struct Node));
    for (int i = 0; i < n; i++) {
        nodes[i].data = i + 1;
        if (i == n - 1) {
            nodes[i].next = &nodes[0];
        } else {
            nodes[i].next = &nodes[i + 1];
        }
    }
    
    struct Node* current = &nodes[0];
    struct Node* prev = &nodes[n - 1];
    
    int remaining = n;
    while (remaining > 1) {
        // Move (m-1) steps
        for (int i = 1; i < m; i++) {
            prev = current;
            current = current->next;
        }
        
        // Remove current node
        printf("%d\n", current->data);
        prev->next = current->next;
        current = current->next;
        remaining--;
    }
    
    // Print last remaining
    printf("%d\n", current->data);
    
    free(nodes);
    return 0;
}