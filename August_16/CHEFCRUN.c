/*
Problem statement:
Chef likes to play with graphs a lot. Today he created a graph in the following way. He first lays down N nodes in a circle. The nodes nodes are numbered from 1 to N, in the clockwise order, i.e. the node 2 is followed by 1, 3 is followed by 2, and 1 is followed by N. Two vertices are said to be adjacent if they don't have an intermediate vertex placed between them. There is an edge between each adjacent pair of vertices, so there are total N such edges. Each edge has an integer associated with it (may be negative).

Chef wants to find a walk from node start to node end using the above described edges. Chef has to pay cost for each edge in the walk equal to the integer associated with the edge. He wants to minimize the total cost he will incur. Also, Chef does not like to move through an edge more than twice. Find out minimum cost that Chef has to pay.

Note that a walk from a node u to v can contain repeated vertices in it. Please refer to link for a formal definition.

Input

The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.

The first line of each test case contains a single integer N denoting the number of nodes.

The second line contains N space-separated integers R1, R2, ..., RN denoting the integer of the rib from node i to node (i % N) + 1. Note that RN is an integer on a rib from node N to node 1.

The third line contains two integers start and end denoting the first and the last node of the walk.

Output

For each test case, output a single line containing the minimal possible cost Chef need to pay.

Constraints

-106 ≤ Ri ≤ 106
1 ≤ start < end ≤ N
Subtasks

Subtask #1 (20 points): 1 ≤ sum of N ≤ 20; 1 ≤ N ≤ 8
Subtask #2 (30 points): 1 ≤ sum of all N ≤ 103; 1 ≤ N ≤ 200
Subtask #3 (50 points): 1 ≤ sum of all N ≤ 106; 1 ≤ N ≤ 2 × 105
Example

Input:
2
4
1 2 1 1
1 3
5
-5 100 100 100 2
1 5

Output:
2
-8
Explanation

Example case 1. Chef's walk starts with node 1. He goes to node 4 by incurring a cost of 1. Then from node 4, he goes to node 3 by incurring a cost of 1 more. Total cost incurred is 2.

Example case 2. Chef goes from 1 to 2 by incurring a cost of -5. Then from 2 to 1 using the edge second time and incurring cost of -5 again. Now, he can not use the edge between 1 and 2 again, as he has traversed the edge already twice. Now he will go from node 1 to node 4 by paying a cost of 2. Total sum of costs incurred is -5 + -5 + 2 = -8. This is the minimum possible cost that Chef can have.
***************************************************************************************************************************************************/

#include <stdio.h>
#include <string.h>

#define MIN(x, y) ((x < y) ? x : y)
#define MAX 200001

int arr[MAX];
int opt[MAX];
int visited[MAX];

int main(void)
{
        int T;
        scanf("%d", &T);
        while (T--) {
                int N, start, end, i, len = 0;
                memset(opt, 0, MAX);
                memset(visited, 0, MAX);
                scanf("%d", &N);
                for (i = 0; i < N; i++) {
                        scanf("%d", &arr[i]);
                }
                scanf("%d%d", &start, &end);
                start--;
                end--;
 /*               
                 0  1   2   3  4
                 1  2   1   1
                1 3

                -5 100 100 100 2                      
*/
                for (i = start; i != end; ) {
                        int prev, next;
                        prev = (i - 1) < 0 ? (N - 1) : (i - 1);
                        next = (i + 1) % N;

                        if (arr[prev] < arr[next]) {
                                visited[prev] = 1;
                                len += arr[prev];
                                i = prev;
                        } else {
                                visited[next] = 1;
                                len += arr[next];
                                i = next;
                        }
                        
                }
                printf("%d\n", len);
        }
        return 0;
}
