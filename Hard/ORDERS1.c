#include <stdio.h>


int main(void)
{
        int T;
        scanf("%d", &T);
        while (T--) {
                int N, i, j, shift;
                scanf("%d", &N);
                int arr[N];
                for (i = 1; i <= N; i++) {
                        scanf("%d", &shift);
                        j = i;
                        while (shift--) {
                                arr[j] = arr[j - 1];
                                j--;
                        }
                        arr[j] = i;
                }
                for (i = 1; i <= N; i++) {
                        printf("%d ", arr[i]);
                }
                
                printf("\n");
        }
        return 0;
}
