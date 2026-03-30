/*
Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print value of intersection node or 'No Intersection'

Example:
Input:
5
10 20 30 40 50
4
15 25 30 40 50

Output:
30

Explanation:
Calculate lengths, advance pointer in longer list, traverse both simultaneously. First common node is intersection.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{

    int data;
    struct Node *next;
};

int main()
{

    int m, n, i;

    printf("Enter the size of the linked lists respectively : ");
    scanf("%d %d", &n, &m);

    struct Node *head1 = NULL, *head2 = NULL;
    struct Node *temp1 = NULL, *temp2 = NULL;
    struct Node *newnode = NULL;

    printf("Enter the nodes of first list - \n");

    for (i = 0; i < n; i++)
    {

        int value;
        scanf("%d", &value);

        newnode = (struct Node *)malloc(sizeof(struct Node));
        newnode->data = value;
        newnode->next = NULL;

        if (head1 == NULL)
        {
            head1 = newnode;
            temp1 = newnode;
        }

        else
        {
            temp1->next = temp1;
            temp1 = newnode;
        }
    }

    printf("Enter the nodes of second list - \n");

    for (i = 0; i < m; i++)
    {

        int value;
        scanf("%d", &value);

        newnode = (struct Node *)malloc(sizeof(struct Node));
        newnode->data = value;
        newnode->next = NULL;

        if (head2 == NULL)
        {
            head2 = newnode;
            temp2 = newnode;
        }

        else
        {
            temp2->next = newnode;
            temp2 = newnode;
        }
    }

    struct Node *p1 = head1;

    while (p1 != NULL)
    {

        struct Node *p2 = head2;

        while (p2 != NULL)
        {

            if (p1->data == p2->data)
            {

                printf("%d", p1->data);
                return 0;
            }
            p2 = p2->next;
        }
        p1 = p1->next;
    }

    printf("No Intersection");

    return 0;
}