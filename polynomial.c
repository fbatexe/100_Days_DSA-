/*
Problem: Polynomial Using Linked List

Input:
- First line: integer n
- Next n lines: coefficient and exponent

Output:
- Print polynomial in standard form

Example:
Input:
5
10 4
20 3
30 2
40 1
50 0

Output:
10x^4 + 20x^3 + 30x^2 + 40x + 50
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

int main() {

    int n, i;

    printf("Enter number of terms : ");
    scanf("%d", &n);

    struct Node *head = NULL;
    struct Node *temp = NULL;
    struct Node *newnode = NULL;

    printf("Enter coefficient and exponent :\n");

    for(i = 0; i < n; i++) {

        int c, e;
        scanf("%d %d", &c, &e);

        newnode = (struct Node*)malloc(sizeof(struct Node));
        newnode->coeff = c;
        newnode->exp = e;
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

    temp = head;

    printf("Output - \n");

    while(temp != NULL) {

        if(temp->exp == 0)
            printf("%d", temp->coeff);

        else if(temp->exp == 1)
            printf("%dx", temp->coeff);

        else
            printf("%dx^%d", temp->coeff, temp->exp);

        if(temp->next != NULL)
            printf(" + ");

        temp = temp->next;
    }

    return 0;
}