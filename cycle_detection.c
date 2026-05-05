/*
Problem: Detect Cycle in Undirected Graph using DFS

Input:
- First line: n (vertices)
- Second line: m (edges)
- Next m lines: u v

Output:
- YES if cycle exists, else NO
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int visited[100];

int dfs(int u, int parent, struct Node* adj[]) {

    visited[u] = 1;

    struct Node* temp = adj[u];

    while(temp != NULL) {

        int v = temp->data;

        if(!visited[v]) {
            if(dfs(v, u, adj))
                return 1;
        }
        else if(v != parent) {
            return 1;
        }

        temp = temp->next;
    }

    return 0;
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

    for(int i = 0; i < n; i++)
        visited[i] = 0;

    int hasCycle = 0;

    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            if(dfs(i, -1, adj)) {
                hasCycle = 1;
                break;
            }
        }
    }

    if(hasCycle)
        printf("YES");
    else
        printf("NO");

    return 0;
}