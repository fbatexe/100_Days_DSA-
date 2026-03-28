/*
Problem: Count Occurrences of an Element in Linked List - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of nodes)
- Second line: n space-separated integers (linked list elements)
- Third line: integer key (element to be counted)

Output:
- Print the number of times the key appears in the linked list

Example:
Input:
6
10 20 30 20 40 20
20

Output:
3

Explanation:
Traverse the linked list from head to end. Each time a node's data matches the given key, increment a counter. After traversal, 
print the final count.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {

    int data;
    struct Node* next;
};

int main() {
    
    int n,i,key;
    int count = 0;

    printf("Enter the size of linekd list : ");
    scanf("%d", &n);

    struct Node* head = NULL;
    struct Node* temp = NULL;
    struct Node* newnode = NULL;

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

    temp = head;

    printf("Enter the key to search : ");
    scanf("%d", &key);

    while (temp != NULL) {

        if (temp->data == key) { 
            count++;
            temp = temp->next;
        }
        else 
            temp = temp->next;    
    }

    printf("Total no. of occurrences of %d = %d", key, count);

    return 0;
}