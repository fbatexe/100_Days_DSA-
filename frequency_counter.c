#include <stdio.h>

int main() {

    int n;
    int i, j, count;

    printf("Enter size of array : ");
    scanf("%d", &n);

    int a[n];
    int visited[n];

    printf("Enter array elements : ");

    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        visited[i] = 0;
    }

    for(i = 0; i < n; i++) {

        if(visited[i] == 1)
            continue;

        count = 1;

        for(j = i + 1; j < n; j++) {

            if(a[i] == a[j]) {
                count++;
                visited[j] = 1;
            }

        }

        printf("%d:%d ", a[i], count);
    }

    return 0;
}