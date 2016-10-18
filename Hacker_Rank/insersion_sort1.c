#include <stdio.h>

int main(void)
{
    int N, i, flag;
    scanf("%d", &N);
    int arr[N], key;
    for (i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    key = arr[N-1];
    flag = 0;
    for (i = N-2; i >= 0; i--) {
        int j;
        if (arr[i] > key) {
            arr[i + 1] = arr[i];
        } else {
            arr[i + 1] = key;
            flag = 1;
            break;
        }
        for (j = 0; j < N; j++) {
            printf("%d ", arr[j]);
        }
        printf("\n");
    }
    if (flag == 0) {
        arr[0] = key;
    }
    for (i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
