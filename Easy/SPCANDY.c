#include <stdio.h>

int main(void)
{
        int T;
        scanf("%d", &T);
        while (T--) {
                long long int N, K;
                scanf("%lld %lld", &N, &K);
                if (K == 0) {
                        printf("%lld %lld\n", K, N);
                } else {
                        printf("%lld %lld\n", N/K, N%K);
                }
        }
        return 0;
}
