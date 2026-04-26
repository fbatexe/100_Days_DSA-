/*
Problem: Implement push and pop operations on a stack

Input:
- First line: integer n
- Second line: n integers to push
- Third line: integer m (number of pops)

Output:
- Print remaining stack elements from top to bottom

Example:
Input:
5
10 20 30 40 50
2

Output:
30 20 10
*/

#include <stdio.h>

#define MAX 100

int main() {

    int n, i, m;

    printf("Enter number of elements : ");
    scanf("%d", &n);

    int stack[MAX];
    int top = -1;

    printf("Enter elements : \n");

    for(i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);

        if(top == MAX - 1) {
            // optional overflow handling
        }
        else {
            stack[++top] = val;
        }
    }

    printf("Enter number of pops : ");
    scanf("%d", &m);

    for(i = 0; i < m; i++) {
        if(top == -1) {
            break;
        }
        top--;
    }

    printf("Output - \n");

    for(i = top; i >= 0; i--) {
        printf("%d", stack[i]);
        if(i != 0) printf(" ");
    }

    return 0;
}