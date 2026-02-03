// Problem: Write a C program to delete the element at a given 1-based position pos from an array of n integers.
// Shift remaining elements to the left.

#include <stdio.h>

int main() {
    int n;

    printf("Enter the size of the array : ");
    scanf("%d" , &n);

    int arr[n];
    printf("Enter the elements in the array - \n");
    for (int i = 0; i < n; i++) {
        scanf("%d" , &arr[i]);
    }

    printf("Original Array - \n");
    for (int i = 0; i < n; i++) {
        printf("%d " , arr[i]);
    }
    printf("\n");

    int pos;

    printf("Enter the position to delete : ");
    scanf("%d" , &pos);

    for (int i = pos - 1; i < n; i++) {
        arr[i] = arr[i+1];
    }

    n--;

    printf("Updated Array after deletion - \n");
    for (int i = 0; i < n; i++) {
        printf("%d " , arr[i]);
    }
    return 0;
}