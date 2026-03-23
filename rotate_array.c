/*
Problem: Given an array of integers, rotate the array to the right by k positions.

Input:
- First line: integer n
- Second line: n integers
- Third line: integer k

Output:
- Print the rotated array

Example:
Input:
5
1 2 3 4 5
2

Output:
4 5 1 2 3
*/

#include <stdio.h>

int main() {

    int n, k;
    int i;

    printf("Enter size of array : ");
    scanf("%d", &n);

    int a[n];

    printf("Enter array elements : ");
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter k : ");
    scanf("%d", &k);

    k = k % n;

    int temp[n];

    for(i = 0; i < k; i++) {
        temp[i] = a[n - k + i];
    }

    for(i = 0; i < n - k; i++) {
        temp[k + i] = a[i];
    }

    for(i = 0; i < n; i++) {
        printf("%d ", temp[i]);
    }

    return 0;
}