/*
Problem statement:
Shridhar wants to generate some prime numbers for his cryptosystem. Help him! Your task is to generate all prime numbers between two given numbers.

Input

The first line contains t, the number of test cases (less then or equal to 10). Followed by t lines which contain two numbers m and n (1 <= m <= n <= 1000000000, n-m<=100000) separated by a space.

Output

For every test case print all prime numbers p such that m <= p <= n, one number per line. Separate the answers for each test case by an empty line.

Example

Input:
2
1 10
3 5

Output:
2
3
5
7

3
5
****************************************************************************************************/







#include <stdio.h>
#include <math.h>

int main(void)
{
    int T, S, E;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &S, &E);
        while(S <= E) {
            if (S == 2) {
                printf("%d\n", S);
            } else if ((S % 2) != 0 && S != 1) {
                int flag = 0;
                int i, j = sqrt(S);
                for (i = 3; i <= j; i++) {
                    if( (S % i) == 0) {
                        flag = 1;
                        break;
                    }
                }
                if (flag != 1) {
                    printf("%d\n", S);
                }
            }
            S++;
        }
        printf("\n");
    }
    return 0;
}
