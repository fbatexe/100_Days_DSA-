/*
Problem: Queue using Linked List

Input:
- First line: integer N
- Next N lines: operations (enqueue x, dequeue)

Output:
- Print dequeued elements
- Print -1 if dequeue on empty queue
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {

    int n;
    scanf("%d", &n);

    struct Node *front = NULL, *rear = NULL;

    for(int i = 0; i < n; i++) {

        char op[20];
        scanf("%s", op);

        if(strcmp(op, "enqueue") == 0) {

            int val;
            scanf("%d", &val);

            struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
            newnode->data = val;
            newnode->next = NULL;

            if(rear == NULL) {
                front = rear = newnode;
            } else {
                rear->next = newnode;
                rear = newnode;
            }
        }

        else if(strcmp(op, "dequeue") == 0) {

            if(front == NULL) {
                printf("-1\n");
            } else {
                struct Node* temp = front;
                printf("%d\n", temp->data);
                front = front->next;

                if(front == NULL)
                    rear = NULL;

                free(temp);
            }
        }
    }

    return 0;
}