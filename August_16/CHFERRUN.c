/*
Problem statement:
Chef cooks nice receipes in the cafeteria of his company. The cafe contains N boxes with food enumerated from 1 to N and are placed in a circle in clocwise order (boxes 1 and N are adjacent). Each box has unlimited amount of food with a tastyness level of Ai. Chef invented a definition of a magic box!

Chef picks a box i and stays in front of it.
Now Chef eats food from box i and skips next Ai boxes.
Now Chef is staying at some other (probably even the same!) box and repeats.
Box i is a magic box if at some point of such game started from box i, Chef will find himself staying in front of it again.
When Chef came home, Chef's dog Tommy asked him about how many magic boxes were in the cafe? Help Chef to in finding that!

Input

The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.

The first line of each test case contains a single integer N denoting the number of boxes.

The second line contains N space-separated integers A1, A2, ..., AN denoting the tastyness levels of each box.

Output

For each test case, output a single line containing number of magical boxes.

Constraints

1 ≤ sum of all N over all the test cases in a single test file ≤ 106
0 ≤ Ai ≤ 109
Subtasks

Subtask #1 (30 points): 1 ≤ sum of all N over all the test cases ≤ 104; 1 ≤ N ≤ 1000
Subtask #2 (70 points): 1 ≤ sum of all N over all the test cases ≤ 106; 1 ≤ N ≤ 105
Example

Input:
3
4
1 1 1 1
4
3 0 0 0
4
0 0 0 2
Output:
4
1
2
Explanation

Example case 1.

Here are Chef's paths if he starting from each the box:
1->3->1
2->4->2
3->1->3
4->2->4
As you see, all 4 boxes are magical.
Example case 2.

Here are Chef's paths if he starts from each box appropriately:
1->1
2->3->4->1->1
3->4->1->1
4->1->1
AS you see, only box 1 is magical.

***************************************************************************************************************************************************/

#include <stdio.h>
#define MAX 1000001

int work[MAX];

int main(void)
{
        int T, N;
        scanf("%d", &T);
        while (T--) {
                int i, count = 0;
                scanf("%d", &N);
                for (i = 0; i < N; i++) {
                        int val;
                        scanf("%d", &val);
                        work[i] = (i + (val + 1)) % N;
                }
                for (i = 0; i < N; i++) {
                        int j, prev_j;
                        j = work[i];
                        prev_j = j - 1;
                        while (j > prev_j) {
                                if (j == i) {
                                        count++;
                                        goto next;
                                }
                                if (j == work[j]) {
                                        break;
                                }
                                prev_j = j;
                                j = work[j];
                        }
                        if (j == i) {
                                count++;
                        }
next:
                        while (j < i) {
                                if (j == i) {
                                        count++;
                                        break;
                                }
                                if (j == work[j]) {
                                        break;
                                }
                                j = work[j];
                        }
                }
                printf("%d\n", count);
        }
        return 0;
}
