/*
Problem: Read a string and check if it is a palindrome using two-pointer comparison.

Input:
- Single line: string s

Output:
- Print YES if palindrome, otherwise NO

Example:
Input :
level

Output :
YES

Explanation: String reads same forwards and backwards
*/

#include <stdio.h>

int main() {
    char ch[100];
    int i,len = 0;

    printf("Enter a string (no space) : ");
    scanf("%s", &ch);

    while (ch[len] != '\0')
        len++;

    int left = 0;
    int right = len - 1;
    int flag = 1;

    while (left < right) {
        if (ch[left] != ch[right]) {
            flag = 0;
            break;
        }
        left++;
        right--;
    }

    if (flag)
        printf("YES");
    else
        printf("NO");

    return 0;
}