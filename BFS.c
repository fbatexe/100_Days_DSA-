/*
Problem: BFS Traversal using Queue

Input:
- First line: n (vertices)
- Second line: m (edges)
- Next m lines: u v
- Last line: source s

Output:
- BFS traversal
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

    int visited[100] = {0};
    int queue[100];
    int front = 0, rear = 0;

    queue[rear++] = s;
    visited[s] = 1;

    while(front < rear) {

        int u = queue[front++];
        printf("%d ", u);

        struct Node* temp = adj[u];

        while(temp != NULL) {

            int v = temp->data;

            if(!visited[v]) {
                visited[v] = 1;
                queue[rear++] = v;
            }

            temp = temp->next;
        }
    }

    return 0;
}