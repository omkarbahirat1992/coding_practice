#include <stdio.h>

int main(void)
{
    int N, i;
    scanf("%d", &N);
    int arr[N];
    for (i = N - 1; i >= 0; i--) {
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
