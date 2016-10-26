/*
Problem statement
Chef has a number D containing only digits 0's and 1's. He wants to make the number to have all the digits same. For that, he will change exactly one digit, i.e. from 0 to 1 or from 1 to 0. If it is possible to make all digits equal (either all 0's or all 1's) by flipping exactly 1 digit then output "Yes", else print "No" (quotes for clarity)

Input

The first line will contain an integer T representing the number of test cases.

Each test case contain a number made of only digits 1's and 0's on newline

Output

Print T lines with a "Yes" or a "No", depending on whether its possible to make it all 0s or 1s or not. 

Constraints

Subtask #1: (40 points)
1 ≤ T ≤ 50
1 ≤ Length of the number D ≤ 50

Subtask #2: (60 points)
1 ≤ T ≤ 10
1 ≤ Length of the number D ≤ 105
Example

Input:
2
101
11
Output:
Yes
No
Explanation

Example case 1. In 101, the 0 can be flipped to make it all 1..

Example case 2. No matter whichever digit you flip, you will not get the desired string.
********************************************************************************************************************************/

#include <stdio.h>
#include <string.h>


int main(void)
{
        int T;
        char str[1000003];
        scanf("%d", &T);
        while (T--) {
                unsigned long i;
                short z_count = 0, o_count = 0;
                scanf("%s", str);
                for (i = 0; str[i] != '\0'; i++) {
                        if (str[i] == '0') {
                                z_count++;
                        } else {
                                o_count++;
                        }
                        if (z_count > 1 && o_count > 1) {
                                break;
                        }
                }
                if (z_count == 1 || o_count == 1) {
                        //printf("%s : Yes\n", str);
                        printf("Yes\n");
                } else {
                        //printf("%s : No\n", str);
                        printf("No\n");
                }
        }
        return 0;
}