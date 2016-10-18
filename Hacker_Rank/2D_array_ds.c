#include <stdio.h>
#define SIZE 6

int main(void)
{
    int mat[SIZE][SIZE], i, j;
    int max = -999999;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
    for (i = 0; i < SIZE - 2; i++) {
        for (j = 0; j < SIZE - 2; j++) {
            int sum;
            sum = mat[i][j] + mat[i][j + 1] + mat[i][j + 2];
            sum += mat[i + 1][j + 1];
            sum += mat[i + 2][j] + mat[i + 2][j + 1] + mat[i + 2][j + 2];
            if (sum > max) {
                max = sum;
            }
        }
    }
    printf("%d\n", max);
    return 0;
}
