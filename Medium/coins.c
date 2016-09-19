#include <stdio.h>
#define MAX_VAL 1000000000

#define MAX(i, j) ((i>j)?i:j)

int opt[MAX_VAL];
int main(void)
{
        unsigned int N, i;

        scanf("%d", &N);

        opt[1] = 1;
        opt[2] = 2;
        opt[3] = 3;

        for (i = 4; i <= N; i++) {
                opt[i] = MAX(i, (opt[i/2] + opt[i/3] + opt[i/4]));
        }

        printf("%d = %d\n",N, opt[N]);

        return 0;
}
