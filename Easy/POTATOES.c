#include <stdio.h>
#include <string.h>

#define MAX_PRIME_COUNT 2004

int main(void)
{
        int T, prime_arr[MAX_PRIME_COUNT];
        int i;
        memset(prime_arr, 0, MAX_PRIME_COUNT * sizeof(int));
        for (i = 2; i < MAX_PRIME_COUNT; i++) {
                if (prime_arr[i] != 1) {
                        int j = i + i;
                        while (j < MAX_PRIME_COUNT) {
                                prime_arr[j] = 1;
                                j += i;
                        }
                }
        }
        scanf("%d", &T);
        while (T--) {
                int a, b, j;
                scanf("%d%d", &a, &b);
                j = a + b + 1;
                while (prime_arr[j] != 0) {
                        j++;
                }
                printf("%d\n", j - (a + b));

        }
        return 0;
}
