/*
Problem: Topological Sort using DFS

Input:
- First line: n (vertices)
- Second line: m (edges)
- Next m lines: u v (directed edge u -> v)

Output:
- Print topological order
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int visited[100];
int stack[100];
int top = -1;

void dfs(int u, struct Node* adj[]) {

    visited[u] = 1;

    struct Node* temp = adj[u];

    while(temp != NULL) {

        int v = temp->data;

        if(!visited[v])
            dfs(v, adj);

        temp = temp->next;
    }

    stack[++top] = u;
}

int main() {

    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);

    struct Node* adj[100] = {NULL};

    for(int i = 0; i < m; i++) {

        int u, v;
        scanf("%d %d", &u, &v);

        struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
        newnode->data = v;
        newnode->next = adj[u];
        adj[u] = newnode;
    }

    for(int i = 0; i < n; i++)
        visited[i] = 0;

    for(int i = 0; i < n; i++) {
        if(!visited[i])
            dfs(i, adj);
    }

    while(top >= 0) {
        printf("%d", stack[top--]);
        if(top >= 0) printf(" ");
    }

    return 0;
}