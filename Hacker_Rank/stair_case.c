#include <stdio.h>
int main(void)
{
    int i, n;
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        int j;
        for (j = 1; j <= (n - i); j++) {
            printf(" ");
        }
        for ( ; j <= n; j++) {
            printf("#");
        }
        printf("\n");
    }
    return 0;
}
