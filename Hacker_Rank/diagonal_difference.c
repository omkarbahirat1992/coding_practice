#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int N;
    scanf("%d", &N);
    int mat[N][N], i, j, sum1 = 0, sum2 = 0;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            scanf("%d", &mat[i][j]);
            if (i == j) {
                sum1 += mat[i][j];
            }
        }
    }
    for (i = 0, j = N - 1; (i < N && j >= 0); i++, j--) {
        sum2 += mat[i][j];
    }
    printf("%d\n", abs(sum1 - sum2));
    return 0;
}
