/*
Problem: Build Graph using Adjacency Matrix

Input:
- First line: n (vertices)
- Second line: m (edges)
- Next m lines: u v

Output:
- n x n adjacency matrix
*/

#include <stdio.h>

int main() {

    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);

    int adj[100][100] = {0};

    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d", adj[i][j]);
            if(j != n-1) printf(" ");
        }
        printf("\n");
    }

    return 0;
}