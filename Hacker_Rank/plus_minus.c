#include <stdio.h>

int main(void)
{
    int i; 
    float N, p_cnt = 0, n_cnt = 0, z_cnt = 0, num;
    scanf("%f", &N);
    i = N;
    while (i--) {
        scanf("%f", &num);
        if (num > 0) {
            p_cnt++;
        } else if (num < 0) {
            n_cnt++;
        } else {
            z_cnt++;
        }
    }
    printf("%.6f\n", (p_cnt / N));
    printf("%.6f\n", (n_cnt / N));
    printf("%.6f\n", (z_cnt / N));
    return 0;
}
