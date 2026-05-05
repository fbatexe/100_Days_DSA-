/*
Problem: Binary Search (Iterative)

Input:
- First line: n
- Second line: n sorted integers
- Third line: key

Output:
- Index of key or -1

Example:
5
12 22 25 34 64
25

Output:
2
*/

#include <stdio.h>

int main() {

    int n;
    scanf("%d", &n);

    int arr[100];

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int key;
    scanf("%d", &key);

    int low = 0, high = n - 1;

    while(low <= high) {

        int mid = (low + high) / 2;

        if(arr[mid] == key) {
            printf("%d", mid);
            return 0;
        }
        else if(arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    printf("-1");

    return 0;
}