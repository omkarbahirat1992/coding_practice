/*
Problem statement

Chef has n × n array A of non-negative integers. He wants to divide this array by p-1 horizontal dividers and p-1 vertical dividers into p2 blocks such that maximum sum of elements of each block will be the smallest.

More formally, Chef want to choose p-1 horizontal dividers 0 = h0 < h1 < ... < hp = n and p-1 vertical dividers 0 = v0 < v1 < ... < vp = n to minimize the next value:

formula
Input

The first line of each test file contains two space-separated integers n and p denoting the size of array A and the number of horizontal and vertical dividers.
Each of next n lines contains n space-separated integers Ai, 1, Ai, 2, ..., Ai, n denoting the ith row of the array A.
Output

The first line of output should contain p-1 space-separated integers h1, h2, ... hp-1 denoting the horizontal dividers.
The second line of output should contain p-1 space-separated integers v1, v2, ... vp-1 denoting the vertical dividers.
Scoring

Your score for each test case will be calculated by formula described above. Your goal is to minimize this score.

Your total score for the problem will be the sum of scores on all the test cases.

Your solution will be tested only on 20% of the test files during the contest and will be rejudged against 100% after the end of competition.

Constraints

2 ≤ p ≤ n ≤ 500
1 ≤ Ai, j ≤ 109
Example

Input:
4 3
1 1 2 2
2 1 2 2
3 1 4 2
4 4 2 2

Output:
2 3
1 3
Explanation

As you can see at the picture below, this array is divided into p2 = 9 blocks by p-1 horizontal(red lines) and p-1 vertical(green lines) dividers. Also there are two vertical (v0 = 0 and v3 = 4) dividers and two horizontal (h0 = 0 and h3 = 4) for better understanding of this division.

example
Your score for this test case will be 6 / (4 / 3)2 (there are two blocks with sum of elements 6).

This test case won't be in the test data because n ∉ [450..500]. It just for let you understand how scoring works. Also there are another ways to divide this array into 9 parts. All of them will be accepted, but with different scores.

Test data generation

There will be 20 test files.

For each test file the number n is chosen from the range [450..500] with equal probability. All elements of A are also chosen randomly. For each test case p will be manually selected.

***************************************************************************************************************************************************/

#include <stdio.h>

int min;

void divide(int h_start, int v_start, int vp, int hp, int n, int max, int arr[][n + 1])
{
        int sum = 0;
        if (hp > 0 ) {
                int i, j;
                for (i = h_start; i <= (n - hp); i++) {
                        for (j = v_start; j <= (n - vp); j++) {
                                sum += arr[i][j];
                                printf("i,j:%d,%d hp:%d vp:%d sum:%d\n", i, j, hp, vp, sum);
                                max = (max < sum) ? sum : max;
                               // printf("i,j:%d,%d hp:%d vp:%d sum:%d, max:%d\n", i, j, hp, vp, sum, max);
                                divide(i + 1, j + 1, hp - 1, vp - 1, n, max, arr);
 //                               printf("aftr i,j:%d,%d hp:%d vp:%d sum:%d\n", i, j, hp, vp, sum);
                        }
                }
        } else {
                int sum1 = 0, i, j;
                for (i = h_start; i <= n; i++) {
                        for (j = v_start; j <= n; j++) {
                                sum1 += arr[i][j];
                        }
                }
                printf("h_s,v_s:%d,%d sum1 = %d\n\n", h_start, v_start, sum1);
                max = (max < sum1) ? sum1 : max;
                min = (min > max) ? max : min;
        }
}

int main(void)
{
        int n, p, i, j;
        scanf("%d%d", &n, &p);
        if (n > 0) {
                int arr[n + 1][n + 1];
                for (i = 1; i <= n; i++) {
                        for (j = 1; j <= n; j++) {
                                scanf("%d", &arr[i][j]);
                        }
                }
                min = 99999999;
                divide(1, 1, p - 1, p - 1, n, -1, arr);
        }
        printf("%d\n", min);
        return 0;
}
