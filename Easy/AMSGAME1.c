#include <stdio.h>

int GCD(int a, int b)
{
        if (b == 0)
                return a;
        return GCD(b, a%b);
}

int main(void)
{
        int T;
        scanf("%d", &T);
        while (T--) {
                int N, num, result, i;
                scanf("%d", &N);
                scanf("%d", &result);
                for (i = 1; i < N; i++) {
                        scanf("%d", &num);
                        result = GCD(result, num);
                }
                printf("%d\n", result);
        }
        return 0;
}
