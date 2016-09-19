#include <stdio.h>
#include <math.h>

#define MAX 1000000000
short int prime_map[MAX];

void make_prime_map(void)
{
        int i, j, n = sqrt(MAX);
        for (i = 2; i <= n; i++) {
                if (prime_map[i] == 0) {
                        j = i;
                        while(j < MAX) {
                                j += i;
                                prime_map[j] = 1;
                        }
                }
        }
}

int main(void)
{
        int T, S, E;
        make_prime_map();
        scanf("%d", &T);
        while (T--) {
                scanf("%d%d", &S, &E);
                while(S <= E) {
                        if (prime_map[S] == 0) {
                                printf("%d\n", S);
                        }
                        S++;
                }
                printf("\n");
        }
        return 0;
}
