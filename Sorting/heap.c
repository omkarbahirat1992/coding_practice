#include <stdio.h>

void max_heapify(int *arr, int N, int root_idx)
{
    int max_idx = root_idx;
    int left_idx = (root_idx * 2) + 1;
    int right_idx = (root_idx * 2) + 2;

    if (left_idx < N && arr[left_idx] > arr[max_idx]) {
        max_idx = left_idx;
    }
    if (right_idx < N && arr[right_idx] > arr[max_idx]) {
        max_idx = right_idx;
    }
    if (max_idx != root_idx) {
        arr[root_idx] += arr[max_idx];
        arr[max_idx] = arr[root_idx] - arr[max_idx];
        arr[root_idx] = arr[root_idx] - arr[max_idx];
        max_heapify(arr, N, max_idx);
    }
}

void heap_sort(int *arr, int N)
{
    int i;
    for (i = (N / 2 - 1); i >= 0; i--) {
        max_heapify(arr, N, i);
    }
    for (i = N - 1 ; i > 0; i--) {
        arr[i] += arr[0];
        arr[0] = arr[i] - arr[0];
        arr[i] = arr[i] - arr[0];

        max_heapify(arr, i, 0);
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
        heap_sort(arr, N);
        printf("Sorted elements: \n");
        for (i = 0; i < N; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    return 0;
}
