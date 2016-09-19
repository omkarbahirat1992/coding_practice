#include <stdio.h>

int main(void)
{
        int T;
        scanf("%d", &T);
        while (T--) {
                int N, i, count;
                char str[1001];
                scanf("%d", &N);
                count = N;
                scanf("%s", str);
                for (i = 0; i < N; i++) {
                        if (str[i] == '1') {
                                str[i] = '2';
                                count --;
                                
                                if ((i > 0) && str[i - 1] == '0') {
                                        str[i - 1] = '2';
                                        count --;
                                }
                                if (str[i + 1] == '1') {
                                        continue;
                                }
                                i++;
                                if ((i < N) && str[i] == '0') { 
                                        str[i] = '2';
                                        count --;
                                }
                }
                }
                printf ("%d\n", count);
        }
}
