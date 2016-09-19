#include <stdio.h>

int main(void)
{
        int T;
        scanf("%d", &T);
        while (T--) {
                int N;
                scanf("%d", &N);
                // BOB plays first
                if ((N % 4) == 1) {
                        printf("ALICE\n");
                } else {
                        printf("BOB\n");
                }
        }
        return 0;
}
