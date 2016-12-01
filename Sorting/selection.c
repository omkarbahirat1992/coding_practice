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
            int min_idx = i;
            for (j = i; j < N; j++) {
                if (arr[j] < arr[min_idx]) {
                    min_idx = j;
                }
            }
            if (i != min_idx) {
                arr[i] += arr[min_idx];
                arr[min_idx] = arr[i] - arr[min_idx]; 
                arr[i] = arr[i] - arr[min_idx];
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
