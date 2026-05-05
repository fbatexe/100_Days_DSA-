/*
Problem: Check Min Heap Property

Input:
- First line: integer N
- Second line: level-order traversal

Output:
- Print YES if Min Heap, else NO

Example:
7
1 3 5 7 9 8 10

Output:
YES
*/

#include <stdio.h>

int main() {

    int n;
    scanf("%d", &n);

    int arr[100];

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int isHeap = 1;

    for(int i = 0; i <= (n/2 - 1); i++) {

        int left = 2*i + 1;
        int right = 2*i + 2;

        if(left < n && arr[i] > arr[left])
            isHeap = 0;

        if(right < n && arr[i] > arr[right])
            isHeap = 0;
    }

    if(isHeap)
        printf("YES");
    else
        printf("NO");

    return 0;
}