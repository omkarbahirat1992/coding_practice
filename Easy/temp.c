#include <stdio.h>


int find_max_profit(int *arr, int N)
{
    int total_sum = 0, i, j, max_profit = 0;
    for (i = 0; i < N; i++)
        total_sum += arr[i];

    for(i = 0; i < N; i++) {
        for(j = i + 1; j < N; j++)
            arr[j] += arr[i];
    }
    for (i = 0; i < N; i++)
        not_included = total_sum - arr[i];
        
}
int main(void)
{
    int T, N, *arr;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &N);
        arr = NULL;
        arr = (int*)malloc(N * sizeof(int));
        if (arr == NULL)
            return -1;
        print("%d\n", find_max_profit(arr, N));
        free(arr)
    }
    
    return 0;
}

