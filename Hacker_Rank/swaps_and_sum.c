#include <stdio.h>

int main(void)
{
    unsigned int N, Q;
    scanf("%u %u", &N, &Q);
    unsigned int arr[N + 1], sum_arr[N + 1], i;

    sum_arr[0] = 0;
    for (i = 1; i <= N; i++) {
        scanf("%u", &arr[i]);
        sum_arr[i] =  sum_arr[i - 1] + arr[i];
    }

    while(Q--) {
        unsigned int query, l, r, sum = 0;
        scanf("%u %u %u", &query, &l, &r);
        switch (query) {
            case 1:
                    for (i = l + 1; i <= r; i = i + 2) {
                        // Swapping
                        arr[i] = arr[i] + arr[i - 1];
                        arr[i - 1] = arr[i] - arr[i - 1];
                        arr[i] = arr[i] - arr[i - 1];

                        // Updating sum_arr[]
                        sum_arr[i - 1] -= arr[i];
                        sum_arr[i - 1] += arr[i - 1];
                    }
 /*                   for (i = 1; i <= N; i++) {
                        printf("%d ", arr[i]);
                    }
                    printf("\n");
                    for (i = 1; i <= N; i++) {
                        printf("%d ", sum_arr[i]);
                    }
                    printf("\n");
*/                break;
            case 2:
            /*        for (i = l; i <= r; i++) {
                        sum += arr[i];
                    }
            */        printf("%d\n", sum_arr[r] - sum_arr[l - 1]);
        }
    }
    return 0;
}
