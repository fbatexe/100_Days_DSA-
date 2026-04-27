/*
Problem: Evaluate Postfix Expression using Linked List Stack

Input:
- Postfix expression (space separated)

Output:
- Print result

Example:
2 3 1 * + 9 -
Output: -4
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** top, int val) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = val;
    newnode->next = *top;
    *top = newnode;
}

int pop(struct Node** top) {
    if(*top == NULL)
        return 0;

    struct Node* temp = *top;
    int val = temp->data;
    *top = temp->next;
    free(temp);
    return val;
}

int main() {

    char input[100];
    printf("Enter postfix expression: ");
    fgets(input, sizeof(input), stdin);

    struct Node* stack = NULL;

    char* token = strtok(input, " \n");

    while(token != NULL) {

        if(isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            push(&stack, atoi(token));
        }
        else {
            int b = pop(&stack);
            int a = pop(&stack);

            if(token[0] == '+') push(&stack, a + b);
            else if(token[0] == '-') push(&stack, a - b);
            else if(token[0] == '*') push(&stack, a * b);
            else if(token[0] == '/') push(&stack, a / b);
        }

        token = strtok(NULL, " \n");
    }

    printf("Result = %d", pop(&stack));

    return 0;
}