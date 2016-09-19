/*
Problem statement

Chef has created a special dividing machine that supports the below given operations on an array of positive integers.

There are two operations that Chef implemented on the machine.

Type 0 Operation

Update(L,R):
	for i = L to R:
		a[i] = a[i] / LeastPrimeDivisor(a[i])
Type 1 Operation

Get(L,R):
	result = 1
	for i = L to R:
		result = max(result, LeastPrimeDivisor(a[i]))
	return result;
The function LeastPrimeDivisor(x) finds the smallest prime divisor of a number. If the number does not have any prime divisors, then it returns 1.

Chef has provided you an array of size N, on which you have to apply M operations using the special machine. Each operation will be one of the above given two types. Your task is to implement the special dividing machine operations designed by Chef. Chef finds this task quite easy using his machine, do you too?

Input

The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.

The first line of each test case contains two space-separated integers N, M, denoting the size of array A and the number of queries correspondingly.
The second line of each test case contains N space-separated integers A1, A2, ..., AN denoting the initial array for dividing machine.

Each of following M lines contain three space-separated integers type, L, R - the type of operation (0 - Update operation, 1 - Get operation), and the arguments of function, respectively

Output

For each test case, output answer of each query of type 1 (Get query) separated by space. Each test case from the same file should start from the new line.

Constraints

1 ≤ T ≤ 100
1 ≤ Ai ≤ 106
1 ≤ L ≤ R ≤ N
0 ≤ type ≤ 1
Sum of M over all test cases in a single test file does not exceed 106
Subtasks

Subtask #1: (10 points)

1 ≤ N, M ≤ 103

Subtask #2: (25 points)

1 ≤ N, M ≤ 105
Ai is a prime number.

Subtask #3: (65 points)

1 ≤ N, M ≤ 105
Example

Input:
2
6 7
2 5 8 10 3 44
1 2 6
0 2 3
1 2 6
0 4 6
1 1 6
0 1 6
1 4 6
2 2
1 3
0 2 2
1 1 2

Output:
5 3 5 11
1
Explanation

Example case 1.The states of array A after each Update-operation:

A: = [2 1 4 10 3 44]
A: = [2 1 4 5 1 22]
A: = [1 1 2 1 1 11]

***************************************************************************************************************************************/

#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1000002

#define UPDATE 0
#define GET 1

#define max(a, b) ((a > b) ? a : b)

int LPD_arr[MAX_SIZE];

void prepare_LPD_arr()
{
        int i;
        memset(LPD_arr, 0, MAX_SIZE * sizeof(int));

        for (i = 2; i < MAX_SIZE; i++) {
                if (LPD_arr[i] == 0) {
                        int j = i;
                        while (j < MAX_SIZE) {
                                if (LPD_arr[j] == 0) {
                                        LPD_arr[j] = i;
                                }
                                j += i;
                        }
                }
        }
}

int main(void)
{
        int T, M, N;
        prepare_LPD_arr();
        scanf("%d" ,&T);

        while (T--) {
                scanf("%d%d", &N, &M);
                int input_arr[N + 1], i;
                for (i = 1; i <= N; i++) {
                        scanf("%d", &input_arr[i]);
                }
                while (M--) {
                        int type, L, R, result;
                        scanf("%d%d%d", &type, &L, &R);
                        switch (type) {
                                case UPDATE:
                                        for (i = L; i <= R; i++) {
                                                if (LPD_arr[input_arr[i]] == 0) {
                                                        input_arr[i] = 1;
                                                } else {
                                                        input_arr[i] = input_arr[i] / LPD_arr[input_arr[i]];
                                                }
                                        }
                                        break;
                                case GET:
                                        result = 1;
                                        for (i = L; i <= R; i++) {
                                                result = max(result, LPD_arr[input_arr[i]]);
                                        }
                                        printf("%d ", result);
                        }
                }
                printf("\n");
        }
        return 0;
}
