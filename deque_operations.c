/*
Problem: Deque (Double-Ended Queue)

Input:
- Sequence of operations:
  push_front x
  push_back x
  pop_front
  pop_back
  front
  back
  empty
  size

Output:
- Print results of front, back, pop operations
*/

#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {

    int deque[MAX];
    int front = -1, rear = -1;
    int n;

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {

        char op[20];
        scanf("%s", op);

        if(strcmp(op, "push_front") == 0) {

            int val;
            scanf("%d", &val);

            if(front == -1) {
                front = rear = 0;
                deque[front] = val;
            } else if(front > 0) {
                deque[--front] = val;
            }
        }

        else if(strcmp(op, "push_back") == 0) {

            int val;
            scanf("%d", &val);

            if(front == -1) {
                front = rear = 0;
                deque[rear] = val;
            } else if(rear < MAX - 1) {
                deque[++rear] = val;
            }
        }

        else if(strcmp(op, "pop_front") == 0) {

            if(front == -1) {
                printf("-1\n");
            } else {
                printf("%d\n", deque[front]);
                if(front == rear)
                    front = rear = -1;
                else
                    front++;
            }
        }

        else if(strcmp(op, "pop_back") == 0) {

            if(front == -1) {
                printf("-1\n");
            } else {
                printf("%d\n", deque[rear]);
                if(front == rear)
                    front = rear = -1;
                else
                    rear--;
            }
        }

        else if(strcmp(op, "front") == 0) {

            if(front == -1)
                printf("-1\n");
            else
                printf("%d\n", deque[front]);
        }

        else if(strcmp(op, "back") == 0) {

            if(front == -1)
                printf("-1\n");
            else
                printf("%d\n", deque[rear]);
        }

        else if(strcmp(op, "empty") == 0) {

            if(front == -1)
                printf("1\n");
            else
                printf("0\n");
        }

        else if(strcmp(op, "size") == 0) {

            if(front == -1)
                printf("0\n");
            else
                printf("%d\n", rear - front + 1);
        }
    }

    return 0;
}