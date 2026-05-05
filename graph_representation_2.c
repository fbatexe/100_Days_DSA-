/*
Problem: Build Graph using Adjacency List

Input:
- First line: n (vertices)
- Second line: m (edges)
- Next m lines: u v

Output:
- Adjacency list of each vertex
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {

    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);

    struct Node* adj[100] = {NULL};

    for(int i = 0; i < m; i++) {

        int u, v;
        scanf("%d %d", &u, &v);

        struct Node* newnode1 = (struct Node*)malloc(sizeof(struct Node));
        newnode1->data = v;
        newnode1->next = adj[u];
        adj[u] = newnode1;

        struct Node* newnode2 = (struct Node*)malloc(sizeof(struct Node));
        newnode2->data = u;
        newnode2->next = adj[v];
        adj[v] = newnode2;
    }

    for(int i = 0; i < n; i++) {

        printf("%d -> ", i);

        struct Node* temp = adj[i];

        while(temp != NULL) {
            printf("%d", temp->data);
            if(temp->next != NULL) printf(" ");
            temp = temp->next;
        }

        printf("\n");
    }

    return 0;
}