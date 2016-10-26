#include <stdio.h>
#include <stdlib.h>


int compare(const void *a, const void *b)
{
    return (*((long long int*)a) - (*((long long int*)b)));
}

int main(void)
{
    unsigned int T;
    scanf("%u", &T);
    while (T--) {
        unsigned int N, S;
        scanf("%u", &N);
        long long int arr[N], cur_E = 0, max_E = 0;
        int i;
        for (i = 0; i < N; i++) {
            scanf("%lld", &arr[i]);
            max_E += arr[i];
        }

        qsort(arr, N, sizeof(long long int), compare);
    
        cur_E = max_E;
        S = 2;
        for (i = 0; i < N; i++) {
            cur_E = ((cur_E / (S - 1)) - arr[i]) * S;
            if (cur_E > max_E) {
                max_E = cur_E;
            }
            S++;
        }
        printf("%lld\n", max_E);
    }
    return 0;
}
