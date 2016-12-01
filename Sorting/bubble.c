#include <stdio.h>

int main(void)
{
    while (1) {
        int N, i, j;
        printf("Enter total count: ");
        scanf("%d", &N);
        int arr[N];
        for (i = 0; i < N; i++) {
            scanf("%d", &arr[i]);
        }
        printf("Given elements: \n");
        for (i = 0; i < N; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        for (i = 0; i < N; i++) {
            for (j = 0; j < N - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    arr[j] += arr[j + 1];
                    arr[j + 1] = arr[j] - arr[j + 1];
                    arr[j] = arr[j] - arr[j + 1];
                }
            }
        }
        printf("Sorted elements: \n");
        for (i = 0; i < N; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    return 0;
}
