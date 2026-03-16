#include <stdio.h>

int main() {

    int n;
    int i, j;
    int flag = 1;

    printf("Enter size of matrix : ");
    scanf("%d", &n);

    int a[n][n];

    printf("Enter matrix elements : \n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {

            if (i == j) {
                if (a[i][j] != 1) {
                    flag = 0;
                    break;
                }
            }
            else {
                if (a[i][j] != 0) {
                    flag = 0;
                    break;
                }
            }
        }
    }

    if (flag)
        printf("Identity Matrix");
    else
        printf("Not an Identity Matrix");

    return 0;
}
