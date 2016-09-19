#include <stdio.h>

int main(void)
{
        long long unsigned N;
        scanf("%lld", &N);
        if (N % 6 == 0 ||
                (N - 1) % 6 == 0 ||
                        (N - 3) % 6 == 0) {
                printf("yes\n");
        } else {
                printf("no\n");
        }
        return 0;
}
