/*
Problem: Stack using Array (push, pop, display)

Input:
- First line: integer n (number of operations)
- Next n lines:
  1 x -> push x
  2   -> pop
  3   -> display (top to bottom)

Output:
- display: print elements from top to bottom
- pop: print popped element or "Stack Underflow"

Example:
5
1 10
1 20
3
2
3

Output:
20 10
20
10
*/

#include <stdio.h>

#define MAX 100

int main() {

    int n;
    scanf("%d", &n);

    int stack[MAX];
    int top = -1;

    for(int i = 0; i < n; i++) {

        int op;
        scanf("%d", &op);

        if(op == 1) {

            int val;
            scanf("%d", &val);

            if(top == MAX - 1) {
            } 
            else {
                stack[++top] = val;
            }
        }

        else if(op == 2) {

            if(top == -1) {
                printf("Stack Underflow\n");
            } else {
                printf("%d\n", stack[top--]);
            }
        }

        else if(op == 3) {

            if(top == -1) {
                printf("\n");
            } 
            else {
                for(int j = top; j >= 0; j--) {
                    printf("%d", stack[j]);
                    if(j != 0) printf(" ");
                }
                printf("\n");
            }
        }
    }

    return 0;
}