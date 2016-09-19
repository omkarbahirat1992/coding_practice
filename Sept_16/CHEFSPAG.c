/*
Problem statement
Chef is tending a really large spaghetti garden. This garden consists of many spaghetti trees. Specifically, there is a spaghetti tree planted for each lattice point location (x, y) with x, y ≥ 0. (Yes, there are an infinite number of trees in Chef's garden!)

It's the 1st of April, so it's harvest time for Chef. Chef plans to harvest all spaghetti strands within a certain region today. In case you didn't know, a spaghetti tree bears spaghetti strands as its fruits.

Specifically, Chef plans to harvest all spaghetti strands hanging from every spaghetti tree whose location (x, y) is within the interior or boundary of a certain polygon with N vertices. Also, the spaghetti tree located at (x, y) currently bears exactly Fx+y fruits, where Fk satisfies the following fourth-order recurrence:

Fk = a·Fk-1 + b·Fk-2 + c·Fk-3 + d·Fk-4

How many strands of spaghetti will Chef be able to harvest today? Since this number can be very large, output it modulo 109 + 9. (Note: this is slightly different from the usual mod.)

Input

The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.

The first line of each test case contains nine space separated integers N, a, b, c, d, F0, F1, F2, and F3.

After that, N lines follow. The ith line contains two integers xi and yi, denoting that (xi, yi) is the ith vertex of the polygon in counterclockwise order.

Output

For each test case, output a single line containing the integer: the answer for that test case.

Constraints

0 ≤ a, b, c, d, F0, F1, F2 F3 < 109 + 9
The polygon is simple and non-degenerate.
1 ≤ T ≤ 2000
3 ≤ N ≤ 16
The sum of the N in a single test file is ≤ 6000
Subtasks

Subtask #1 (10 points):
0 ≤ xi, yi ≤ 100
Subtask #2 (30 points):
0 ≤ xi, yi ≤ 104
Subtask #3 (60 points):
0 ≤ xi, yi ≤ 109
Example

Input:
2
4 1 2 3 4 0 1 2 3
1 1
2 1
2 2
1 2
4 1 2 3 4 0 1 2 3
1 1
3 1
3 3
1 3

Output:
18
153

Explanation

In both test cases, we have Fk = k for 0 ≤ k ≤ 3 and Fk = Fk-1 + 2·Fk-2 + 3·Fk-3 + 4·Fk-4. So you can check that F4 = 10, F5 = 26 and F6 = 63

In the first test case, Chef will harvest all spaghetti strands in the locations (1, 1), (1, 2), (2, 1), (2, 2). The total number is F1+1 + F1+2 + F2+1 + F2+2 = F2 + F3 + F3 + F4 = 18
In the second test case, Chef will harvest all spaghetti strands in the locations (1, 1), (1, 2), (1, 3), (2, 1), (2, 2), (2, 3), (3, 1), (3, 2), (3, 3). The total number is F1+1 + F1+2 + F1+3 + F2+1 + F2+2 + F2+3 + F3+1 + F3+2 + F3+3 = F2 + F3 + F4 + F3 + F4 + F5 + F4 + F5 + F6 = 153

*******************************************************************************************************/

#include <stdio.h>

#define MAX 1000000
#define LIMIT 1000000009

unsigned int F[MAX];
unsigned int a, b, c, d;

int is_inside(unsigned int x, unsigned int y, unsigned int N, unsigned int x_arr[17], unsigned int y_arr[17])
{
        int i, count = 0;
        for (i = 0; i < N; i++) {
                if ((x_arr[i] == x && y_arr[i] == y) ||
                        (x_arr[i + 1] == x && y_arr[i + 1] == y) ) {
                        return 1;
                } else if ((x_arr[i] >= x || x_arr[i + 1] >= x) &&
                        ((y_arr[i] < y && y_arr[i + 1] > y) ||
                                (y_arr[i] > y && y_arr[i + 1] < y)) ) {
                        if (x_arr[i] == x_arr[i + 1]) {
                                return 1;
                        }
                        if (y_arr[i] == y_arr[i + 1]) {
                                return 1;
                        }
                        count++;
                } else {
                        int y_diff = y_arr[i + 1] - y_arr[i];
                        int x_diff = x_arr[i + 1] - x_arr[i];
//                        int C = y_arr[i] - (y_diff / x_diff) * x_arr[i];
                        if ((x_diff * y) == ((y_diff * x) + (y_arr[i] * x_diff) - (y_diff * x_arr[i]))) {
                                return 1;
                        }
                }
        }
        return (count % 2);
}

unsigned long long int calculate_strands(unsigned int val)
{
        if (val < MAX) {
                return F[val];
        }
        return ((a * calculate_strands(val - 1)) + (b * calculate_strands(val - 2)) + (c * calculate_strands(val - 3)) + (d * calculate_strands(val - 4)));
}

int main(void)
{
        int T;
        scanf("%d", &T);
        while (T--) {
                unsigned int N, i, j, x_arr[17], y_arr[17];
                unsigned int sx = LIMIT, sy = LIMIT, lx = 0, ly = 0;
                unsigned long long count = 0;

                scanf("%d%d%d%d%d%d%d%d%d", &N, &a, &b, &c, &d, &F[0], &F[1], &F[2], &F[3]);
                for (i = 0; i < N; i++) {
                        scanf("%d%d", &x_arr[i], &y_arr[i]);
                        if (sx > x_arr[i]) {
                                sx = x_arr[i];
                        }
                        if (sy > y_arr[i]) {
                                sy = y_arr[i];
                        }
                        if (lx < x_arr[i]) {
                                lx = x_arr[i];
                        }
                        if (ly < y_arr[i]) {
                                ly = y_arr[i];
                        }
                }
                x_arr[N] = x_arr[0];
                y_arr[N] = y_arr[0];
                for (i = 4; i < MAX; i++) {
                        F[i] = (a * F[i - 1]) + (b * F [i - 2]) + (c * F[i - 3]) + (d * F[i - 4]);
//                        printf("F[%d] = %d\n", i, F[i]);
                }
                for (i = sx; i <= lx; i++) {
                        for (j = sy; j <= ly; j++) {
                                if (is_inside(i, j, N, x_arr, y_arr) == 1) {
                                        count += calculate_strands(i + j);
                                }
                        }
                }        
                printf("%llu\n", count % LIMIT);
        }
        return 0;
}
