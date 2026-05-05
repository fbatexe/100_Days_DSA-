/*
Problem: Construct Binary Tree from Level Order

Input:
- First line: integer N
- Second line: N integers (-1 for NULL)

Output:
- Print inorder traversal

Example:
7
1 2 3 4 5 -1 6

Output:
4 2 5 1 3 6
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

int main() {

    int n;
    scanf("%d", &n);

    int arr[100];

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* nodes[100];

    for(int i = 0; i < n; i++) {

        if(arr[i] == -1)
            nodes[i] = NULL;
        else {
            nodes[i] = (struct Node*)malloc(sizeof(struct Node));
            nodes[i]->data = arr[i];
            nodes[i]->left = NULL;
            nodes[i]->right = NULL;
        }
    }

    for(int i = 0; i < n; i++) {

        if(nodes[i] != NULL) {

            int left = 2*i + 1;
            int right = 2*i + 2;

            if(left < n)
                nodes[i]->left = nodes[left];

            if(right < n)
                nodes[i]->right = nodes[right];
        }
    }

    struct Node* root = nodes[0];

    struct Node* stack[100];
    int top = -1;

    struct Node* curr = root;

    while(curr != NULL || top >= 0) {

        while(curr != NULL) {
            stack[++top] = curr;
            curr = curr->left;
        }

        curr = stack[top--];
        printf("%d", curr->data);

        if(curr->right != NULL || top >= 0)
            printf(" ");

        curr = curr->right;
    }

    return 0;
}