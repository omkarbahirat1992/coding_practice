#include <stdio.h>

int main(void)
{
    int N, i, j, k;
    scanf("%d", &N);
    int arr[N], key;
    for (i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    for (k = 1; k < N; k++) {
        key = arr[k];
        
        i = k - 1;
        while (arr[i] > key) {
            arr[i+1] = arr[i];
            i--;
            if (i < 0) {
                break;
            }
        }
        arr[i + 1] = key;
        for (j = 0; j < N; j++) {
            printf("%d ", arr[j]);
        }
        printf("\n");
    }
    return 0;
}
