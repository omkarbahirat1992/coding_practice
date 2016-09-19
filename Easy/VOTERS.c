#include <stdio.h>

#define MAX 99999999
int output[MAX];
int count;

void accept_n_process(int n)
{
        int i, num;
        for (i = 0; i < n; i++) {
                scanf("%d", &num);
                output[num]++;
                if (output[num] == 2) {
                        count++;
                }              
        }
}

int main(void)
{
        int n1, n2, n3, i;
        scanf("%d%d%d", &n1, &n2, &n3);
        accept_n_process(n1);
        accept_n_process(n2);
        accept_n_process(n3);
        
        printf("%d\n", count);
        for (i = 0; i < MAX; i++) {
                if (output[i] >= 2) {
                        printf("%d\n", i);
                }
        }
        
        return 0;
}
