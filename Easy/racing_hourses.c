#include <stdio.h>
#include <stdlib.h>
int compare(const void *a, const void *b)
{
        return (*(int*)a - *(int*)b);
}

int main()
{
        int T, n, i, min_diff;
        scanf("%d", &T);
        while (T--) {
                scanf("%d", &n);
                int input_arr[n];
                for (i = 0; i < n; i++) {
                        scanf("%d", &input_arr[i]);
                }
                qsort(input_arr, n, sizeof(int), compare);
                min_diff = input_arr[1] - input_arr[0];
                for (i = 0; i < n - 1; i++) {
                        if (input_arr[i + 1] - input_arr[i] < min_diff)
                                min_diff = input_arr[i + 1] - input_arr[i];
                }
                printf("%d\n", min_diff);
        }
        return 0;
}
