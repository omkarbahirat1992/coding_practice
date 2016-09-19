#include <stdio.h>

int main(void)
{
        int T;
        scanf("%d", &T);
        while(T--) {
                int N;
                scanf("%d", &N);
                int input_arr[N+1], i, K, count;
                for (i = 1; i <= N; i++)
                        scanf("%d", &input_arr[i]);
                scanf("%d", &K);
                
                count = 0;
                for (i = 1; i <= N; i++) {
                        if (input_arr[i] < input_arr[K])
                                count++;
                }
                printf("%d\n", count+1);
        }
        return 0;
}
