/*
Problem: Min Heap using Array

Input:
- First line: integer N
- Next N lines: operations (insert x, extractMin, peek)

Output:
- Print results of extractMin and peek
- Print -1 if operation cannot be performed

Example:
Input:
6
insert 40
insert 10
insert 30
peek
extractMin
peek

Output:
10
10
30
*/

#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {

    int n;
    scanf("%d", &n);

    int heap[MAX];
    int size = 0;

    for(int i = 0; i < n; i++) {

        char op[20];
        scanf("%s", op);

        if(strcmp(op, "insert") == 0) {

            int val;
            scanf("%d", &val);

            heap[size] = val;
            int j = size;
            size++;

            while(j > 0) {
                int parent = (j - 1) / 2;
                if(heap[parent] <= heap[j])
                    break;

                int temp = heap[parent];
                heap[parent] = heap[j];
                heap[j] = temp;

                j = parent;
            }
        }

        else if(strcmp(op, "extractMin") == 0) {

            if(size == 0) {
                printf("-1\n");
            } else {
                printf("%d\n", heap[0]);

                heap[0] = heap[size - 1];
                size--;

                int j = 0;

                while(1) {
                    int left = 2*j + 1;
                    int right = 2*j + 2;
                    int smallest = j;

                    if(left < size && heap[left] < heap[smallest])
                        smallest = left;

                    if(right < size && heap[right] < heap[smallest])
                        smallest = right;

                    if(smallest == j)
                        break;

                    int temp = heap[j];
                    heap[j] = heap[smallest];
                    heap[smallest] = temp;

                    j = smallest;
                }
            }
        }

        else if(strcmp(op, "peek") == 0) {

            if(size == 0)
                printf("-1\n");
            else
                printf("%d\n", heap[0]);
        }
    }

    return 0;
}