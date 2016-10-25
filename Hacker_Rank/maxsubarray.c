#include <stdio.h>
#include <string.h>

int main(void)
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int N, i;
        scanf("%d", &N);
        long long int arr[N], max, cur_max;
        for (i = 0; i < N; i++) {
            scanf("%lld", &arr[i]);
        }

        /* MAX sum of contiguous sub-array */
        max = arr[0];
        /* Need extra phase to handle the case when all the numbers are negative */
        for (i = 0; i < N; i++) {
            if (arr[i] >= 0) {
                max = 0;
                break;
            }
            if (arr[i] > max) {
                max = arr[i];
            }
        }
        if (max == 0) {
            max = arr[0];
            cur_max = 0;
            for (i = 0; i < N; i++) {
                cur_max += arr[i];
                if (cur_max < 0) {
                    cur_max = 0;
                } else if (cur_max > max) {
                    max = cur_max;
                }
            }
        }
        printf("%lld ", max);

        /* MAX sum of non-contiguous sub-array */
        max = arr[0];
        for (i = 1; i < N; i++) {
            if (max + arr[i] > max) {
                max += arr[i];
            } else if (arr[i] > max){
                max = arr[i];
            }
        }
        printf("%lld\n", max);
    }
    return 0;
}
