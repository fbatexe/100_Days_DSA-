/*
Problem: Circular Queue Using Array

Input:
- First line: integer n
- Second line: n elements
- Third line: m (number of dequeues)

Output:
- Print queue from front to rear after operations

Example:
5
10 20 30 40 50
2

Output:
30 40 50 10 20
*/

#include <stdio.h>

#define MAX 100

int main() {

    int n, m, i;

    printf("Enter number of elements : ");
    scanf("%d", &n);

    int queue[MAX];
    int front = 0, rear = -1, size = 0;

    printf("Enter elements : \n");

    for(i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);

        if(size == MAX) {
        } else {
            rear = (rear + 1) % MAX;
            queue[rear] = val;
            size++;
        }
    }

    printf("Enter number of dequeues : ");
    scanf("%d", &m);

    for(i = 0; i < m; i++) {
        if(size == 0) break;

        front = (front + 1) % MAX;
        size--;
    }

    printf("Output - \n");

    for(i = 0; i < size; i++) {
        int idx = (front + i) % MAX;
        printf("%d", queue[idx]);
        if(i != size - 1) printf(" ");
    }

    return 0;
}