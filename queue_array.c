/*
Problem: Queue Using Array

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print queue elements from front to rear

Example:
5
10 20 30 40 50

Output:
10 20 30 40 50
*/

#include <stdio.h>

#define MAX 100

int main() {

    int n, i;

    printf("Enter number of elements : ");
    scanf("%d", &n);

    int queue[MAX];
    int front = 0, rear = -1;

    printf("Enter elements : \n");

    for(i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);

        if(rear == MAX - 1) {
            // optional overflow handling
        } else {
            queue[++rear] = val;
        }
    }

    printf("Output - \n");

    for(i = front; i <= rear; i++) {
        printf("%d", queue[i]);
        if(i != rear) printf(" ");
    }

    return 0;
}