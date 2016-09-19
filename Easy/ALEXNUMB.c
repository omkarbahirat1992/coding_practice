#include <stdio.h>

#define MAX_COUNT 100000

int main(void)
{
        int T;
        scanf("%d", &T);
        while (T--) {
                long long int N, val, i;
                scanf("%lld", &N);
                for (i = 0; i < N; i++) {
                        scanf("%lld", &val);
                }
                printf("%lld\n", N * (N - 1) / 2);
        }
        return 0;
}
