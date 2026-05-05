/*
Problem: Lowest Common Ancestor in Binary Tree

Input:
- First line: integer N
- Second line: level-order traversal (-1 for NULL)
- Third line: two node values

Output:
- Print LCA

Example:
7
1 2 3 4 5 6 7
4 5

Output:
2
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* LCA(struct Node* root, int a, int b) {

    if(root == NULL)
        return NULL;

    if(root->data == a || root->data == b)
        return root;

    struct Node* left = LCA(root->left, a, b);
    struct Node* right = LCA(root->right, a, b);

    if(left != NULL && right != NULL)
        return root;

    return left != NULL ? left : right;
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

    int a, b;
    scanf("%d %d", &a, &b);

    struct Node* ans = LCA(root, a, b);

    if(ans != NULL)
        printf("%d", ans->data);

    return 0;
}