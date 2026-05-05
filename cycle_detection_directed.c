/*
Problem: Detect Cycle in Directed Graph using DFS

Input:
- First line: n (vertices)
- Second line: m (edges)
- Next m lines: u v (directed edge u -> v)

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
int recStack[100];

int dfs(int u, struct Node* adj[]) {

    visited[u] = 1;
    recStack[u] = 1;

    struct Node* temp = adj[u];

    while(temp != NULL) {

        int v = temp->data;

        if(!visited[v]) {
            if(dfs(v, adj))
                return 1;
        }
        else if(recStack[v]) {
            return 1;
        }

        temp = temp->next;
    }

    recStack[u] = 0;
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

        struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
        newnode->data = v;
        newnode->next = adj[u];
        adj[u] = newnode;
    }

    for(int i = 0; i < n; i++) {
        visited[i] = 0;
        recStack[i] = 0;
    }

    int hascycle = 0;

    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            if(dfs(i, adj)) {
                hascycle = 1;
                break;
            }
        }
    }

    if(hascycle)
        printf("YES");
    else
        printf("NO");

    return 0;
}