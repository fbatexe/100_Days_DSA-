// Problem: Given a sorted array of n integers, remove duplicates in-place. 
// Print only unique elements in order.


#include <stdio.h>

int main() {
    int n;

    printf("Enter the size of array : ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements - \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original Array - \n");
    for (int i = 0; i < n; i++) {
        printf("%d " , arr[i]);
    }
    printf("\n");

    for (int i = 0; i < n; i++) {
        if (arr[i] == arr[i+1]) {
            for (int j = i; j < n; j++) {
                arr[j] = arr[j+1];
            }
            n--;
            i--;
        }
    }

    printf("Updated Array after removing duplicates - \n");
    for (int i = 0; i < n; i++) {
        printf("%d " , arr[i]);
    }
    
    return 0;
}
