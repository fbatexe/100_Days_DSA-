/*
Problem: Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print the merged linked list elements, space-separated

Example:
Input:
5
10 20 30 40 50
4
15 25 35 45

Output:
10 15 20 25 30 35 40 45 50

Explanation:
Compare nodes of both lists, append smaller to result, continue until all nodes are merged.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {

    int data;
    struct Node* next;
};


int main() {

    int n,m,i;
    
    struct Node* head1 = NULL, *head2 = NULL;
    struct Node* temp1 = NULL, *temp2 = NULL, *newnode = NULL;  

    printf("Enter size of first linked list : ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        
        int val;

        scanf("%d", &val);

        newnode = (struct Node*)malloc(sizeof(struct Node));
        newnode->data = val;
        newnode->next = NULL;

        if (head1 == NULL) {
            head1 = newnode;
            temp1 = newnode;
        }
        else {
            temp1->next = newnode;
            temp1 = newnode;
        }
    }

    printf("Enter size of second linked list : ");
    scanf("%d", &m);

    for (i = 0; i < m; i++) {
        
        int val;

        scanf("%d", &val);

        newnode = (struct Node*)malloc(sizeof(struct Node));
        newnode->data = val;
        newnode->next = NULL;

        if (head2 == NULL) {
            head2 = newnode;
            temp2 = newnode;
        }
        else {
            temp2->next = newnode;
            temp2 = newnode;
        }
    }

    struct Node *p1 = head1;
    struct Node *p2 = head2;
    struct Node *merged = NULL, *temp = NULL;

    while (p1 != NULL && p2 != NULL) {

        struct Node *node = (struct Node*)malloc(sizeof(struct Node));

        if (p1->data < p2->data) {
            node->data = p1->data;
            p1 = p1->next;
        }
        else {
            node->data = p2->data;
            p2 = p2->next;
        }

        if (merged == NULL) {
            merged = node;
            temp = node;
        }
        else {
            temp->next = node;
            temp = node;
        }
    }

    while (p1 != NULL) {
        
        struct Node* node = (struct Node*)malloc(sizeof(struct Node));
        node->data = p1->data;
        node->next = NULL;

        temp->next = node;
        temp = node;

        p1 = p1->next;
    }

    while (p2 != NULL) {

        struct Node* node = (struct Node*)malloc(sizeof(struct Node));
        node->data = p1->data;
        node->next = NULL;
        
        temp->next = node;
        temp = node;

        p2 = p2->next;
    }

    temp = merged;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL");

    return 0;
}