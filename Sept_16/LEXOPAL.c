/*
Problem statement:
Chef likes strings a lot but he likes palindromic strings even more. Today he found an old string s in his garage. The string is so old that some of its characters have faded and are unidentifiable now. Faded characters in the string are represented by '.' whereas other characters are lower case Latin alphabets i.e ['a'-'z'].

Chef being the palindrome lover decided to construct the lexicographically smallest palindrome by filling each of the faded character ('.') with a lower case Latin alphabet. Can you please help him completing the task?

Input

First line of input contains a single integer T denoting the number of test cases. T test cases follow.

First and the only line of each case contains string s denoting the old string that chef has found in his garage.

Output

For each test case, print lexicographically smallest palindrome after filling each faded character - if it possible to construct one. Print -1 otherwise.

Constraints

1 ≤ T ≤ 50
1 ≤ |s| ≤ 12345
String s consists of ['a'-'z'] and '.' only.
Subtasks

Subtask #1 (47 points)
1 ≤ T ≤ 50, 1 ≤ |S| ≤ 123

Subtask #2 (53 points)
1 ≤ T ≤ 50, 1 ≤ |S| ≤ 12345
Example

Input
3
a.ba
cb.bc
a.b

Output
abba
cbabc
-1
Explanation

In example 1, you can create a palindrome by filling the faded character by 'b'.

In example 2, you can replace the faded character by any character from 'a' to 'z'. We fill it by 'a', as it will generate the lexicographically smallest palindrome.

In example 3, it is not possible to make the string s a palindrome.

************************************************************************************************************************************************/

#include <stdio.h>
#include <string.h>

int main(void)
{
        int T, len;
        char str[12347];
        scanf("%d", &T);

        while (T--) {
                int i, j, mid;
                scanf("%s", str);
                len = strlen(str);
                mid = len / 2;
                i = mid - 1;
                j = mid;

                if ((len % 2) == 1) {
                        j = mid + 1;
                        if (str[mid] == '.') {
                                str[mid] = 'a';
                        }
                }
                while (j < len) {
                        if (str[i] == '.' && str[j] == '.') {
                                str[i] = 'a';
                                str[j] = 'a';
                        } else if (str[i] == '.') {
                                str[i] = str[j];
                        } else if (str[j] == '.') {
                                str[j] = str[i];
                        } else if (str[i] != str[j]) {
                                break;
                        }
                        i--;
                        j++;
                }
                if (j == len) {
                        printf("%s\n", str);
                } else {
                        printf("-1\n");
                }
        }
        return 0;
}