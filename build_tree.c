/*
Problem: Construct Binary Tree from Preorder and Inorder

Input:
- First line: integer N
- Second line: preorder traversal
- Third line: inorder traversal

Output:
- Print postorder traversal

Example:
5
1 2 4 5 3
4 2 5 1 3

Output:
4 5 2 3 1
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

int search(int inorder[], int start, int end, int val) {
    for(int i = start; i <= end; i++) {
        if(inorder[i] == val)
            return i;
    }
    return -1;
}

struct Node* build(int preorder[], int inorder[], int start, int end, int* preIndex) {

    if(start > end)
        return NULL;

    struct Node* root = (struct Node*)malloc(sizeof(struct Node));
    root->data = preorder[(*preIndex)++];
    root->left = root->right = NULL;

    if(start == end)
        return root;

    int idx = search(inorder, start, end, root->data);

    root->left = build(preorder, inorder, start, idx - 1, preIndex);
    root->right = build(preorder, inorder, idx + 1, end, preIndex);

    return root;
}

void postorder(struct Node* root) {
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {

    int n;
    scanf("%d", &n);

    int preorder[100], inorder[100];

    for(int i = 0; i < n; i++)
        scanf("%d", &preorder[i]);

    for(int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    int preIndex = 0;

    struct Node* root = build(preorder, inorder, 0, n - 1, &preIndex);

    postorder(root);

    return 0;
}