/*
Problem: Delete First Occurrence of a keyey - Implement using linkeyed list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer keyey

Output:
- Print the linkeyed list elements after deletion, space-separated

Example:
Input:
5
10 20 30 40 50
30

Output:
10 20 40 50

Explanation:
Traverse list, find first node with keyey, remove it by adjusting previous node's next pointer.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {

    int data;
    struct Node* next;
};

int main() {
    
    int n,key,i;

    printf("Enter the size of linked list : ");
    scanf("%d", &n);

    struct Node *head = NULL;
    struct Node *temp = NULL;
    struct Node *newnode = NULL;

    printf("Enter the nodes - \n");
    for (i = 0; i < n; i++) {
        
        int value;
        scanf("%d", &value);

        newnode = (struct Node*)malloc(sizeof(struct Node));
        newnode->data = value;
        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
            temp = newnode;
        }
        else {
            temp->next = newnode;
            temp = newnode;
        }
    }

    printf("Enter the key : ");
    scanf("%d", &key);

    struct Node* dummy = (struct Node*)malloc(sizeof(struct Node));
    dummy->next = head;

    struct Node* prev = dummy;
    struct Node* curr = head;

    while (curr != NULL) {

        if (curr->data == key) {
            prev->next = curr->next;
            free(curr);
            break;
        }

        prev = curr;
        curr = curr->next;
    }

    head = dummy->next;
    free(dummy);

    temp = head;

    printf("Updated Linked List - \n");

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL");

    return 0;
}