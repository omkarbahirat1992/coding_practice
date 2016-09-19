#include <stdio.h>

int main(void)
{
        int T, N, cur, min, count;
        scanf("%d", &T);
        while (T--) {
                scanf("%d", &N);
                scanf("%d", &cur);
                min = cur;
                count = 1;
                while (--N) {
                        scanf("%d", &cur);
                        if (cur <= min) {
                                min = cur;
                                count++;
                        }
                }
                printf("%d\n", count);
        }
        return 0;
}
