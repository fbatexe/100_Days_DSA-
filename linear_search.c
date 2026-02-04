// Problem: Implement linear search to find key k in an array. 
// Count and display the number of comparisons performed.

#include <stdio.h>

int main() {
    int num;
    int k, found = 0;
    int index, count = 0;

    printf("Enter the string size : ");
    scanf("%d" , &num);

    int arr[num];

    printf("Enter the elements in the array - \n");
    for (int i = 0; i < num; i++) {
        scanf("%d" , &arr[i]);
    }
    printf("Enter the element to search : ");
    scanf("%d" , &k);

    for (int i = 0; i < num; i++) {
        if (k == arr[i]) {
            found = 1;
            index = i;
            break;
        }
        count++;
    }

    if (found == 1) {
        printf("Found at index %d \n", index);
        printf("Comparions = %d", count);
    }
    else 
        printf("Not Found");
        printf("Comparions = %d", count);

    return 0;
}