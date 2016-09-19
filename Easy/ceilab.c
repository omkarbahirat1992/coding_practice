
#include <stdio.h>
 
int main(void)
{   
    int a, b;
    scanf("%d%d", &a, &b);
    printf ("Original (a-b) = %d\n", a-b);
    if (((a-b) & 1) == 1) {
        printf("%d\n", (a-b) & (~1));
    } else{
        printf("%d\n", (a-b) | 1);
    }
    return 0;
}  
