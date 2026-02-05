// Problem: A system receives two separate logs of user arrival times from two different servers. Each log is already sorted in ascending order. 
// Your task is to create a single chronological log that preserves the correct order of arrivals.

#include <stdio.h>

int main() {
    int p, q;

    printf("Enter size of first log : ");
    scanf("%d", &p);

    int arr[p];

    printf("Enter elements of first log in ascending order - \n");
    for (int i = 0; i < p; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter size of second log : ");
    scanf("%d", &q);

    int brr[q], result[p + q];

    printf("Enter elements of second log in ascending order - \n");
    for (int j = 0; j < q; j++) {
        scanf("%d", &brr[j]);
    }

    int i = 0, j = 0, k = 0;
      
    for (; i < p && j < q; ) {
        if (arr[i] <= brr[j])
            result[k++] = arr[i++];
        else
            result[k++] = brr[j++];
    }

    for (; i < p; )
        result[k++] = arr[i++];

    for (; j < q; )
        result[k++] = brr[j++];

    printf("Output : \n");
    for (i = 0; i < p + q; i++) {
        printf("%d ", result[i]);
    }

    return 0;
}
