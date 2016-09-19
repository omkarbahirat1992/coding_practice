#include<stdio.h>

#define MAX 101

int main(void)
{
        int T, arr[MAX], N;
        scanf("%d", &T);
        while(T--) {
                int i, j, local_invers, invers;
                scanf("%d", &N);
                scanf("%d", &arr[1]);
                if (N == 1) {
                        printf("YES\n");
                        continue;
                }
                local_invers = 0;
                for (i = 2; i <= N; i++) {
                        scanf("%d", &arr[i]);
                        if (arr[i-1] > arr[i])
                                local_invers++;
                }
                invers = 0;
                for(i = 1; i < N; i++) {
                        for(j = i+1; j <= N; j++) {
                                if (arr[i] > arr[j]) {
                                        invers++;
                                }
                        }
                }
                

                if (local_invers == invers) {
                        printf("YES\n");
                } else {
                        printf("NO\n");
                }
                
        }
        return 0;
}
