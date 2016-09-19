#include <stdio.h>
#include <string.h>

#define MAX_NUM 100
#define MAX(a, b) (a > b) ? a : b

int main(void)
{
        int T;
        scanf("%d", &T);
        while (T--) {
                int N, K, W[100], i, sum, small_sum, large_sum, key;
                memset(W, 0, MAX_NUM);
                scanf("%d%d", &N, &K);
                sum = 0;
                small_sum = 0;
                large_sum = 0;
                for (i = 0; i < N; i++) {
                        int j;
                        scanf("%d", &key);
                        for (j = i - 1; j >= 0; j--) {
                                if (W[j] >= key) {
                                        W[j+1] = W[j];
                                } else {
                                        j++;
                                        break;
                                }
                        }
                        if (j == -1)
                                j++;
                        W[j] = key;
                        sum += key;
                }
                for (i = 0; i < K; i++) {
                        small_sum += W[i];
                }
                for (i = N - K; i < N; i++) {
                        large_sum += W[i];
                }
                printf("%d\n", MAX(abs(abs(sum - small_sum) - small_sum), abs(large_sum - abs(sum - large_sum))));
        }
        return 0;
}
