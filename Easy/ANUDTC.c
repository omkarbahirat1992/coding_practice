#include <stdio.h>

#define VAL 360

int main(void)
{
        int T;
        scanf("%d", &T);
        while (T--) {
                int N;
                scanf("%d", &N);
                if ((VAL % N) == 0) {
                        printf("y ");
                } else {
                        printf("n ");
                }

                if (N <= VAL) {
                        printf("y ");
                } else {
                        printf("n ");
                }
                if (N * (N + 1) <= (VAL * 2)) {
                        printf("y\n");
                } else {
                        printf("n\n");
                }
        }
}
