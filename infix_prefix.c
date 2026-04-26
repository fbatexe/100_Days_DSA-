/*
Problem: Convert Infix to Postfix

Input:
- Single line infix expression (single char operands)

Output:
- Postfix expression

Example:
A+B*C → ABC*+
*/

#include <stdio.h>
#include <ctype.h>

#define MAX 100

int precedence(char op) {
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    return 0;
}

int main() {

    char infix[MAX], stack[MAX], postfix[MAX];
    int top = -1, k = 0;

    printf("Enter infix expression : ");
    scanf("%s", infix);

    for(int i = 0; infix[i] != '\0'; i++) {

        char ch = infix[i];

        if(isalnum(ch)) {
            postfix[k++] = ch;
        }
        else if(ch == '(') {
            stack[++top] = ch;
        }
        else if(ch == ')') {
            while(top != -1 && stack[top] != '(') {
                postfix[k++] = stack[top--];
            }
            top--; // remove '('
        }
        else {
            while(top != -1 && precedence(stack[top]) >= precedence(ch)) {
                postfix[k++] = stack[top--];
            }
            stack[++top] = ch;
        }
    }

    while(top != -1) {
        postfix[k++] = stack[top--];
    }

    postfix[k] = '\0';

    printf("Postfix: %s", postfix);

    return 0;
}