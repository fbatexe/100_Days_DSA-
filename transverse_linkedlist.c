// Problem: Create and Traverse Singly Linked List

// Input:
// - First line: integer n
// - Second line: n space-separated integers

// Output:
// - Print the result

// Example:
// Input:
// 5
// 10 20 30 40 50

// Output:
// 10 20 30 40 50


#include <stdio.h>
#include <stdlib.h>

struct Node {

    int data;
    struct Node* next;

};

int main() {
    
    int n;
    printf("Enter the no. of nodes : ");
    scanf("%d", &n);

    struct Node* head = NULL;
    struct Node* temp = NULL;
    struct Node* newnode = NULL;

    printf("Enter the node - \n");

    for (int i = 0; i < n; i++) {

        int value;

        scanf("%d" , &value);

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

    printf("Output - \n");
    
    while (temp != NULL) {

        printf("%d ", temp->data);
        temp = temp->next;

    }

    return 0;
}