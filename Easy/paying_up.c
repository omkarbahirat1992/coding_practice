#include <stdio.h>
#define true 1
#define false 0

int main(void)
{
        int T, sum, n;
        scanf("%d", &T);
        while(T--) {
                scanf("%d%d", &n, &sum);
                int opt[sum + 1][n + 1], set[n], i, j;

                for (i = 0; i <= n; i++)
                        opt[0][i] = true;
                
                for (i = 1; i <= sum; i++)
                        opt[i][0] = false;

                for (i = 0; i < n; i++)
                        scanf("%d", &set[i]);

                for (i = 1; i <= sum; i++) {
                        for (j = 1; j <= n; j++) {
                                opt[i][j] = opt[i][j-1];                       
                                if (i >= set[j - 1])
                                        opt[i][j] = opt[i][j-1] || opt[i - set[j - 1]][j - 1];
                        }
                }
                if (opt[sum][n] == true) 
                        printf("Yes\n");
                else
                        printf("No\n");
        }
        return 0;
}
