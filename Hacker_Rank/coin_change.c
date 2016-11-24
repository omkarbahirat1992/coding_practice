#include <stdio.h>

int main(void)
{
    int N, total_coins;
    scanf("%d%d", &N, &total_coins);

    long long int opt[N+1][total_coins], input[total_coins], i, j;
    for (i = 0; i < total_coins; i++) {
        scanf("%lld", &input[i]);
    }
    for (i = 0; i < total_coins; i++) {
        opt[0][i] = 1;
    }

    for (i = 1; i <= N; i++) {
        for (j = 0; j < total_coins; j++) {
            // including j'th element
            long long int including_cnt = (i - input[j] >= 0) ? opt[i - input[j]][j] : 0;

            // excluding j'th element
            long long int excluding_cnt = (j >= 1) ? opt[i][j - 1] : 0;
            opt[i][j] = including_cnt + excluding_cnt;
        }
    }
    printf("%lld\n", opt[N][total_coins - 1]);
    return 0;
}
