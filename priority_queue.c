/*
Problem: Priority Queue using Array

Input:
- First line: integer N
- Next N lines: operations (insert x, delete, peek)

Output:
- Print deleted or peeked element
- Print -1 if empty

Example:
Input:
5
insert 30
insert 10
insert 20
delete
peek

Output:
10
20
*/

#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {

    int n;
    scanf("%d", &n);

    int pq[MAX];
    int size = 0;

    for(int i = 0; i < n; i++) {

        char op[10];
        scanf("%s", op);

        if(strcmp(op, "insert") == 0) {

            int val;
            scanf("%d", &val);

            pq[size++] = val;

            for(int j = size - 1; j > 0; j--) {
                if(pq[j] < pq[j - 1]) {
                    int temp = pq[j];
                    pq[j] = pq[j - 1];
                    pq[j - 1] = temp;
                } else break;
            }
        }

        else if(strcmp(op, "delete") == 0) {

            if(size == 0) {
                printf("-1\n");
            } else {
                printf("%d\n", pq[0]);

                for(int j = 1; j < size; j++) {
                    pq[j - 1] = pq[j];
                }
                size--;
            }
        }

        else if(strcmp(op, "peek") == 0) {

            if(size == 0) {
                printf("-1\n");
            } else {
                printf("%d\n", pq[0]);
            }
        }
    }

    return 0;
}