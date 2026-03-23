/*
Problem: Given an array of integers, find two elements whose sum is closest to zero.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the pair of elements whose sum is closest to zero

Example:
Input:
5
1 60 -10 70 -80

Output:
-10 1
*/

#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {

    int n, i;

    printf("Enter size of array : ");
    scanf("%d", &n);

    int a[n];

    printf("Enter array elements : ");
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    qsort(a, n, sizeof(int), compare);

    int left = 0;
    int right = n - 1;

    int minSum = 1000000;
    int x = 0, y = 0;

    while(left < right) {

        int sum = a[left] + a[right];

        if(abs(sum) < abs(minSum)) {
            minSum = sum;
            x = a[left];
            y = a[right];
        }

        if(sum < 0)
            left++;
        else
            right--;
    }

    printf("%d %d", x, y);

    return 0;
}