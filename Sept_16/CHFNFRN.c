/*
Problem statement
Chef invited N of his friends in his birthday party. All the friends are numbered from 1 to N. Some of the friends might know each other. You are given this information by M pairs each of form (ai, bi), denoting that the persons ai and bi know each other.

Chef wants all of his guests to seat at the two tables set up for dinner. He wants that all the people sitting at a table must know each other, otherwise they will feel awkward with mutual eating habits. Chef is okay if a table is not occupied by any person. Chef is worried whether all the guests can seat at the dinner tables in the desired way.

Please help Chef fast to identify whether his worry is real or not!! The delicacies at the table are getting cold.

Input

The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.

The first line of each test case contains two space-separated integers N and M, denoting the number of Chef's friends and the number of pairs representing information whether two person know each other or not.

The next M lines contain two space-separated integers ai and bi, denoting that persons ai and bi know each other.

Output

For each test case, output a single line containing word "YES" (without quotes) if Chef can divide all of his friends into two groups that in each group all the people know each other and "NO" (without quotes) otherwise.

Constraints

1 ≤ T ≤ 103
1 ≤ N ≤ 103
0 ≤ M ≤ 106
1 ≤ ai, bi ≤ N
The sum of N over all test cases in a single test file does not exceed 104
The sum of M over all test cases in a single test file does not exceed 106
Subtasks

Subtask #1 (30 pts)
1 ≤ N ≤ 10

Subtask #2 (70 pts)
Original constraints
Example

Input:
3
3 2
1 2
2 3
4 3
1 2
2 3
2 4
6 7
1 2
1 3
2 3
2 4
4 5
4 6
5 6

Output:
YES
NO
YES
Explanation

Example case 1.

Table 1: Person 1. Table 2: Persons 2 and 3.

explanation
Example case 2.

All guests can't have a seat according to the rule.

explanation
Example case 3.

Table 1: Persons 1, 2, 3. Table 2: Persons 4, 5, 6.

explanation

*****************************************************************************************************************************/

#include <stdio.h>
#include <string.h>

int main(void)
{
        unsigned int T;
        scanf("%d", &T);
        while (T--) {
                unsigned int N, M, i, j, a, b;
                scanf("%d%d", &N, &M);
                unsigned short table1[N + 1], table2[N + 1];
                unsigned short graph[N+1][N+1];
                memset(table1, 0, ((N + 1) * sizeof(unsigned short)));
                memset(table2, 0, ((N + 1) * sizeof(unsigned short)));
                for (i = 1; i <= N; i++) {
                        for (j = 1; j <= N; j++) {
                                graph[i][j] = 0;
                        }
                }

                for (i = 0; i < M; i++) {
                        scanf("%u%u", &a, &b);
                        graph[a][b] = 1;
                        graph[b][a] = 1;
                }
        }
        return 0;
}
