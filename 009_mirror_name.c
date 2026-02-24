/*
Problem: A secret system stores code names in forward order. To display them in mirror format, you must transform the given code name so that its characters appear in the opposite order.

Input:
- Single line: a lowercase string containing only alphabetic characters (no spaces)

Output:
- Print the transformed code name after applying the mirror operation

Example:
Input:
hello

Output:
olleh

Explanation: The first character moves to the last position, the second to the second-last, and so on until the entire string is mirrored
*/

#include <stdio.h>

int main() {
    char ch[100];
    int i,len = 0;

    printf("Enter a string (no space): ");
    scanf("%s", &ch);

    char temp[100] = ch;

    for (i = 0; ch[i] != '\0'; i++) {
        len++;
    }


    printf("Mirror format of the string - ");
    for (i = len-1; i >= 0; i--) {
        printf("%c" , ch[i]);
    }
    return 0;
}
