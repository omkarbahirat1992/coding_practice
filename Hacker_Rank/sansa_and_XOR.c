#include <stdio.h>

unsigned long long int do_xor_of_size(unsigned int size, unsigned long long int *arr, unsigned int N)
{
    unsigned int i, j;
    unsigned long int ans = 0;
    for (i = 0; i <= N - size; i++) {
        for (j = i; j < i + size; j++) {
            ans ^= arr[j];
        }
    }
    return ans;
}

int main(void)
{
    unsigned int T;
    scanf("%d", &T);
    while (T--) {
        unsigned int N, i;
        scanf("%d", &N);
        unsigned long long int arr[N], ans = 0;
        for (i = 0; i < N; i++) {
            scanf("%lld", &arr[i]);
            ans ^= arr[i];
        }
        for (i = 2; i <= N; i++) {
            unsigned long long temp_ans;
            temp_ans = do_xor_of_size(i, arr, N);
            ans ^= temp_ans;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
