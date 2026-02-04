// Problem: Given an array of n integers, reverse the array in-place using two-pointer approach.

#include <stdio.h>

int main() {
    int n;

    printf("Enter the size of array : ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the array elements - \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original Array - \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    for (int i = 0; i < n/2; i++) {
        int left = arr[i];
        int right = arr[n-i-1];

        left = left + right;             // Swapping
        right = left - right;
        left = left - right;

        arr[i] = left;                  // Assigning the values to array
        arr[n-i-1] = right;
    }

    printf("\n");

    printf("Reversed Array - \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}