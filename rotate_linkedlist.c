/*
Problem: Rotate Linked List Right by k Places

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer k

Output:
- Print the linked list elements after rotation, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
40 50 10 20 30
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {

    int n, i, k;

    printf("Enter size of linked list : ");
    scanf("%d", &n);

    struct Node *head = NULL;
    struct Node *temp = NULL;
    struct Node *newnode = NULL;

    printf("Enter nodes : \n");

    for(i = 0; i < n; i++) {

        int value;
        scanf("%d", &value);

        newnode = (struct Node*)malloc(sizeof(struct Node));
        newnode->data = value;
        newnode->next = NULL;

        if(head == NULL) {
            head = newnode;
            temp = newnode;
        }
        else {
            temp->next = newnode;
            temp = newnode;
        }
    }

    printf("Enter k : ");
    scanf("%d", &k);

    if(head == NULL || head->next == NULL) {
        temp = head;
        while(temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        return 0;
    }

    int len = 1;
    temp = head;

    while(temp->next != NULL) {
        temp = temp->next;
        len++;
    }

    temp->next = head;

    k = k % len;

    int steps = len - k;

    struct Node *curr = head;

    for(i = 1; i < steps; i++) {
        curr = curr->next;
    }

    head = curr->next;

    curr->next = NULL;

    printf("Output - \n");

    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}