#include <stdio.h>

int partition(int *arr, int start, int end, int pivot)
{
    int i = start, j = end;
    while (1) {
        while(arr[i] < pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i >= j) {
            break;
        }
        arr[i] += arr[j];
        arr[j] = arr[i] - arr[j];
        arr[i] = arr[i] - arr[j];
    }
    return i;
}

void quick_sort(int *arr, int start, int end)
{
    if (start < end) {
        int pivot = arr[end];
        int partition_point = partition(arr, start, end, pivot);
        quick_sort(arr, start, partition_point - 1);
        quick_sort(arr, partition_point + 1, end);
    }
    
}

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
        quick_sort(arr, 0, N - 1);

        printf("Sorted elements: \n");
        for (i = 0; i < N; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    return 0;
}
