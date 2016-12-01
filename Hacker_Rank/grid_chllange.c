#include <stdio.h>

#define TYPE char

int compare(void *a, void *b)
{
    return (*((TYPE*)a) - *((TYPE*)b));
}

int main(void)
{
    int T;
    scanf("%d", &T);

NEXT:
    while(T--) {

        int N;
        scanf("%d", &N);
        char mat[N + 2][N + 2], i, j;

        for (i = 0; i < N; i++) {
            scanf("%s", mat[i]);
        }
        for (i = 0; i < N; i++) {
            qsort(mat[i], N, sizeof(TYPE), compare);
        }
        for (j = 0; j < N; j++) {
            for (i = 0; i < (N - 1); i++) {
                if (mat[i][j] > mat[i + 1][j]) {
                    printf("NO\n");
                    goto NEXT;
                }
            }
        }
        printf("YES\n");
    }
    return 0;
}
