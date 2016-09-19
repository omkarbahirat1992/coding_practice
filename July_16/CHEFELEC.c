/*
Problem statement:
here are n villages in a Chefland. Some of the villages have electricity facilities, other doesn't. You can consider the villages arranged in line in the order 1 to n from left to right. i-th of village can be considered at xi coordinates.

Chef decided that electricity should be provided to all the villages. So, he decides to buy some amount of electric wires to connect the villeges without electricity to some villages with electricity. As Chef does not want to spend too much amount of money on wires, can you find out minimum amount of length of wire Chef should buy.

Input

First line of the input contains an integer T denoting the number of test cases. T test cases follow.

First line of each test case contains an integer n denoting number of villages in Chefland.

Second line will contain a string of length n containing '0' or '1's only. If i-th character of the string is '1', then it denotes that i-th village has electricity.

Next line contains n space separated integers denoting the x coordinates of the villages in the order from village 1 to n

Output

For each test case, output a single line containing a integer corresponding to the minimum length of wire Chef needs to buy.

Constraints

1 ≤ T ≤ 10
It is guaranteed that there will be at least one village which will have electricity.
1 ≤ x1 < x2 < ... < xn ≤ 109
Subtasks

Subtask #1 : 30 points

1 ≤ N ≤ 1000
Subtask #2 : 70 points

1 ≤ N ≤ 105
Example

Input
2
2
01
1 2
3
100
1 5 6
Output:
1
5
Explanation

In the first example, first village does not have electricity. If we put a wire between village 1 and 2 of length 1, then both the villages will have electricity.

In the second example,
We can a draw a wire from first village to third village, passing through second village. Its total length will be 5. Now all the villages will have electricity. This is the minimum length of wire you will require.

********************************************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100000


int main(void)
{
        unsigned int i, j, T, N, val, len, set_bits;
        char bit_string[MAX];
        int bitmap[MAX], coord[MAX];

        scanf("%d", &T);
        while (T--) {
                scanf("%d", &N);
                scanf("%s", bit_string);
                j = 0;
                for (i = 0; i < strlen(bit_string); i++) {
                        if (bit_string[i] == '1') {
                                bitmap[j++] = i;
                        }
                }
                set_bits = j;
                for (i = 0; i < N; i++) {
                        scanf("%d", &coord[i]);
                }

                i = bitmap[0];
                len = coord[i] - coord[0];
                i++;

                j = 0;
                while (j < (set_bits - 1) && (i < N)){
                        val = coord[bitmap[j]];
                        while ( (coord[i] - val) < (coord[bitmap[j+1]] - coord[i]) && (++i < N));
                        len += coord[i - 1] - val;
                        len += coord[bitmap[j+1]] - coord[i];
                        j++;
                printf("%d\n", len);
                }
                if (i < N) {
                        len += coord[N - 1] - coord[bitmap[set_bits - 1]];
                }
                printf("%d\n", len);
        }
        return 0;
}
