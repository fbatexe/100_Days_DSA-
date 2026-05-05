/*
Problem: Reverse a Queue using Stack

Input:
- First line: integer N
- Second line: N integers

Output:
- Print reversed queue

Example:
5
10 20 30 40 50

Output:
50 40 30 20 10
*/

#include <stdio.h>

#define MAX 100

int main() {

    int n;
    scanf("%d", &n);

    int queue[MAX];
    int stack[MAX];

    int front = 0, rear = -1;
    int top = -1;

    for(int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        queue[++rear] = val;
    }

    while(front <= rear) {
        stack[++top] = queue[front++];
    }

    front = 0;
    rear = -1;

    while(top >= 0) {
        queue[++rear] = stack[top--];
    }

    for(int i = front; i <= rear; i++) {
        printf("%d", queue[i]);
        if(i != rear) printf(" ");
    }

    return 0;
}