#include <stdio.h>

int main() {

    int m, n;
    int i, j;
    int sum = 0;

    printf("Enter rows and columns : ");
    scanf("%d %d", &m, &n);

    int a[m][n];

    printf("Enter matrix elements :\n");

    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {

            if(i == j) {
                sum = sum + a[i][j];
            }

        }
    }

    printf("%d", sum);

    return 0;
}