#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, m;
    int i;
    struct Node* nodes;
    struct Node* current;
    struct Node* prev;
    int remaining;
    int count;
    
    if (scanf("%d %d", &n, &m) != 2) {
        return 1;
    }
    
    nodes = (struct Node*)malloc(n * sizeof(struct Node));
    if (nodes == NULL) {
        return 1;
    }
    
    for (i = 0; i < n; i++) {
        nodes[i].data = i + 1;
        if (i == n - 1) {
            nodes[i].next = &nodes[0];
        } else {
            nodes[i].next = &nodes[i + 1];
        }
    }
    
    current = &nodes[0];
    prev = &nodes[n - 1];
    remaining = n;
    
    while (remaining > 1) {
        for (count = 1; count < m; count++) {
            prev = current;
            current = current->next;
        }
        
        printf("%d\n", current->data);
        prev->next = current->next;
        current = current->next;
        remaining--;
    }
    
    printf("%d\n", current->data);
    
    free(nodes);
    return 0;
}