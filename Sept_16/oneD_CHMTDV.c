#include <stdio.h>

int min;

void divide(int start, int p, int n, int max, int *arr)
{
        int sum = 0;
        if (p > 0) {
                int i;
                for (i = start; i <= (n - p); i++) {
                        sum += arr[i];
                        printf("i:%d p:%d sum:%d\n", i, p, sum);
                        max = (max < sum) ? sum : max;
                        printf("i:%d p:%d sum:%d, max:%d\n", i, p, sum, max);
                        divide(i + 1, p - 1, n, max, arr);
                      //  printf("after i:%d p:%d sum:%d\n", i, p, sum);
                }
        } else {
                int sum1 = 0, j;
                for (j = start; j <= n; j++) {
                        sum1 += arr[j];
                }
                printf("p:%d sum1:%d\n", p, sum1);
                max = (max < sum1) ? sum1 : max;
                min = (min > max) ? max : min;
                printf("p:%d sum1:%d, max:%d\n", p, sum1, max);
                printf("p:%d sum1:%d, min:%d\n", p, sum1, min);
        }
}

int main(void)
{
        int n, p, i;
        scanf("%d%d", &n, &p);
        if (n > 0) {
                int arr[n + 1];
                for (i = 1; i <= n; i++) {
                        scanf("%d", &arr[i]);
                }
                min = 99999999;
                divide(1, p, n, -1, arr);
        }
        printf("%d\n", min);
        return 0;
}
