#include <stdio.h>

#define MAX 1001

int get_next_start(int arr[MAX], int N, int i)
{
        for ( ; i <= N; i++) {
                if (arr[i] != 0) {
                        return i;
                }
        }
        return -1;
}
int main(void)
{
        int arr[MAX], output_arr[MAX], N, i, count = 0;
        scanf("%d", &N);
        for (i = 1; i <= N; i++) {
                scanf("%d", &arr[i]);
                output_arr[i] = arr[i];
        }

        i = 1;
        while((i = get_next_start(arr, N, i)) != -1) {
                int j = i, prev_j;
                do {
                        prev_j = j;
                        j = arr[j];
                        arr[prev_j] = 0;
                } while (j != i);
                count ++;
        }
        printf("%d\n", count);

        i = 1;
        while((i = get_next_start(output_arr, N, i)) != -1) {
                int j = i, prev_j;
                do {
                        printf("%d ", j);
                        prev_j = j;
                        j = output_arr[j];
                        output_arr[prev_j] = 0;
                } while (j != i);
                printf("%d\n", j);
        }
        
        return 0;
}
