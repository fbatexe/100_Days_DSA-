/*
Problem: Tree Traversals (Inorder, Preorder, Postorder)

Input:
- First line: integer N
- Second line: level-order traversal (-1 for NULL)

Output:
- Print inorder
- Print preorder
- Print postorder

Example:
7
1 2 3 4 5 6 7

Output:
4 2 5 1 6 3 7
1 2 4 5 3 6 7
4 5 2 6 7 3 1
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

void inorder(struct Node* root) {
    if(root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(struct Node* root) {
    if(root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
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

    inorder(root);
    printf("\n");

    preorder(root);
    printf("\n");

    postorder(root);

    return 0;
}