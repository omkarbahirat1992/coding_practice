#include <stdio.h>
#include <math.h>

int main(void)
{
        int T;
        scanf("%d", &T);
        while (T--) {
                int N, i, limit, min;
                scanf("%d", &N);
                limit = N;
                min = 999999999;
                for (i = 1; i <= sqrt(N); i++) {
                        limit = N / i;
                        if ((N%i) == 0) {
                                if (abs(limit - i) < min) {
                                        min = abs(limit - i);
                                }
                        }
                }
                printf("%d\n", min);
        }
        return 0;
}
