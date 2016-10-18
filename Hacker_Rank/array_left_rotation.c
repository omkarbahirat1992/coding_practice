#include <stdio.h>

int main(void)
{
    unsigned int N, d;
    scanf("%d%d", &N, &d);
    unsigned int arr[N], i;

    for (i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    d =  d % N;
    for (i = d; i < N; i++) {
        printf("%d ", arr[i]);
    }
    for (i = 0; i < d; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
