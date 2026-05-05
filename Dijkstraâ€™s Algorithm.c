/*
Problem: Shortest Path using Priority Queue (Dijkstra)

Input:
- First line: n (vertices)
- Second line: m (edges)
- Next m lines: u v w
- Last line: source s

Output:
- Shortest distance from source to all vertices
*/

#include <stdio.h>
#include <stdlib.h>

#define INF 1000000000

struct Node {
    int v, w;
    struct Node* next;
};

int dist[100];
int visited[100];

int main() {

    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);

    struct Node* adj[100] = {NULL};

    for(int i = 0; i < m; i++) {

        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        struct Node* new1 = (struct Node*)malloc(sizeof(struct Node));
        new1->v = v;
        new1->w = w;
        new1->next = adj[u];
        adj[u] = new1;

        struct Node* new2 = (struct Node*)malloc(sizeof(struct Node));
        new2->v = u;
        new2->w = w;
        new2->next = adj[v];
        adj[v] = new2;
    }

    int s;
    scanf("%d", &s);

    for(int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[s] = 0;

    for(int i = 0; i < n; i++) {

        int u = -1, mindist = INF;

        for(int j = 0; j < n; j++) {
            if(!visited[j] && dist[j] < mindist) {
                mindist = dist[j];
                u = j;
            }
        }

        if(u == -1) break;

        visited[u] = 1;

        struct Node* temp = adj[u];

        while(temp != NULL) {

            int v = temp->v;
            int w = temp->w;

            if(dist[u] + w < dist[v])
                dist[v] = dist[u] + w;

            temp = temp->next;
        }
    }

    for(int i = 0; i < n; i++) {
        printf("%d", dist[i]);
        if(i != n-1) printf(" ");
    }

    return 0;
}