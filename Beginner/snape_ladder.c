#include <stdio.h>
#include <math.h>

int main(void)
{
 //   printf("\nHello world\n");
    int n;  //number of TCs
    int i, B, LC;
    double val;
    scanf("%d", &n);

   while(n--) {
        scanf("%d%d", &B, &LC);
        printf("%lf %lf\n", sqrt((double)((LC * LC) - (B * B))), sqrt((double)((LC * LC) + (B * B))));
    }

    return 0;
}
