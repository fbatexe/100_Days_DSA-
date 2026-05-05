/*
Problem: Heap Sort using Max Heap

Input:
- First line: integer n
- Second line: n integers

Output:
- Print sorted array in ascending order

Example:
Input:
5
4 10 3 5 1

Output:
1 3 4 5 10
*/

#include <stdio.h>

void heapify(int arr[], int n, int i) {

    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[left] > arr[largest])
        largest = left;

    if(right < n && arr[right] > arr[largest])
        largest = right;

    if(largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

int main() {

    int n;
    scanf("%d", &n);

    int arr[100];

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for(int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for(int i = n - 1; i > 0; i--) {

        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }

    for(int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if(i != n - 1) printf(" ");
    }

    return 0;
}