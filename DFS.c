/*
Problem: DFS Traversal using Recursion

Input:
- First line: n (vertices)
- Second line: m (edges)
- Next m lines: u v
- Last line: starting vertex s

Output:
- DFS traversal
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int visited[100];

void dfs(int u, struct Node* adj[]) {

    visited[u] = 1;
    printf("%d ", u);

    struct Node* temp = adj[u];

    while(temp != NULL) {
        if(!visited[temp->data])
            dfs(temp->data, adj);
        temp = temp->next;
    }
}

int main() {

    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);

    struct Node* adj[100] = {NULL};

    for(int i = 0; i < m; i++) {

        int u, v;
        scanf("%d %d", &u, &v);

        struct Node* new1 = (struct Node*)malloc(sizeof(struct Node));
        new1->data = v;
        new1->next = adj[u];
        adj[u] = new1;

        struct Node* new2 = (struct Node*)malloc(sizeof(struct Node));
        new2->data = u;
        new2->next = adj[v];
        adj[v] = new2;
    }

    int s;
    scanf("%d", &s);

    for(int i = 0; i < n; i++)
        visited[i] = 0;

    dfs(s, adj);

    return 0;
}