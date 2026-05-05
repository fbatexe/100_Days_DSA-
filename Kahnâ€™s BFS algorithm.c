/*
Problem: Topological Sort using Kahn's Algorithm (BFS)

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

int main() {

    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);

    struct Node* adj[100] = {NULL};
    int indegree[100] = {0};

    for(int i = 0; i < m; i++) {

        int u, v;
        scanf("%d %d", &u, &v);

        struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
        newnode->data = v;
        newnode->next = adj[u];
        adj[u] = newnode;

        indegree[v]++;
    }

    int queue[100];
    int front = 0, rear = 0;

    for(int i = 0; i < n; i++) {
        if(indegree[i] == 0)
            queue[rear++] = i;
    }

    while(front < rear) {

        int u = queue[front++];
        printf("%d", u);
        if(front < rear) printf(" ");

        struct Node* temp = adj[u];

        while(temp != NULL) {

            int v = temp->data;
            indegree[v]--;

            if(indegree[v] == 0)
                queue[rear++] = v;

            temp = temp->next;
        }
    }

    return 0;
}