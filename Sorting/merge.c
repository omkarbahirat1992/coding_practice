#include <stdio.h>
#define MAX 100
int arr[MAX];

void merge(int *arr, int start, int mid, int end)
{
    int i = start, j = mid + 1, k = 0;
    int temp_arr[end - start + 1];
    while (i <= mid && j <= end) {
        if (arr[i] < arr[j]) {
            temp_arr[k] = arr[i];
            i++;
        } else {
            temp_arr[k] = arr[j];
            j++;
        }
        k++;
    }
    while (i <= mid) {
        temp_arr[k] = arr[i];
        i++;
        k++;
    }
    while (j <= end) {
        temp_arr[k] = arr[j];
        j++;
        k++;
    }
    k = 0;
    for (i = start; i <= end; i++) {
        arr[i] = temp_arr[k];
        k++;
    }
    
}


void merge_sort(int *arr, int start, int end)
{
    if ((start + 1) ==  end) {
        if (arr[start] > arr[end]) {
            arr[start] += arr[end];
            arr[end] = arr[start] - arr[end];
            arr[start] = arr[start] - arr[end];
        }

    } else if (start < end){
        int mid = (start + end) / 2;
        merge_sort(arr, start, mid);
        merge_sort(arr, (mid + 1), end);
        merge(arr, start, mid, end);
    }
}

int main(void)
{
    while (1) {
        int N, i, j;
        printf("Enter total count: ");
        scanf("%d", &N);
        for (i = 0; i < N; i++) {
            scanf("%d", &arr[i]);
        }
        printf("Given elements: \n");
        for (i = 0; i < N; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        merge_sort(arr, 0, N-1);
        printf("Sorted elements: \n");
        for (i = 0; i < N; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    return 0;
}
