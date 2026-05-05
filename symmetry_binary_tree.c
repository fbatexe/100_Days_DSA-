/*
Problem: Check Symmetric Binary Tree

Input:
- First line: integer N
- Second line: level-order traversal (-1 for NULL)

Output:
- Print YES if symmetric, else NO

Example:
7
1 2 2 3 4 4 3

Output:
YES
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

int isMirror(struct Node* a, struct Node* b) {

    if(a == NULL && b == NULL)
        return 1;

    if(a == NULL || b == NULL)
        return 0;

    if(a->data != b->data)
        return 0;

    return isMirror(a->left, b->right) &&
           isMirror(a->right, b->left);
}

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

    if(isMirror(root, root))
        printf("YES");
    else
        printf("NO");

    return 0;
}