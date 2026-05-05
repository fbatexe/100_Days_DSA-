/*
Problem: Right View of Binary Tree

Input:
- First line: integer N
- Second line: level-order traversal (-1 for NULL)

Output:
- Print right view nodes

Example:
7
1 2 3 4 5 -1 6

Output:
1 3 6
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

    struct Node* queue[100];
    int front = 0, rear = 0;

    if(root != NULL)
        queue[rear++] = root;

    while(front < rear) {

        int size = rear - front;

        for(int i = 0; i < size; i++) {

            struct Node* curr = queue[front++];

            if(i == size - 1)
                printf("%d", curr->data);

            if(curr->left != NULL)
                queue[rear++] = curr->left;

            if(curr->right != NULL)
                queue[rear++] = curr->right;
        }

        if(front < rear)
            printf(" ");
    }

    return 0;
}