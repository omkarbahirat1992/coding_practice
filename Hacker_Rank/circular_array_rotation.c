#include <stdio.h>

int main(void)
{
    int N, K, Q, i, q;
    scanf("%d%d%d", &N, &K, &Q);
    K = K % N;
    int arr[N];
    for (i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    while(Q--) {
        scanf("%d", &q);
        if ((q - K) < 0) {
            printf("%d\n", arr[q - K + N]);
        } else {
            printf("%d\n", arr[q - K]);
        }
    }
    return 0;
}
