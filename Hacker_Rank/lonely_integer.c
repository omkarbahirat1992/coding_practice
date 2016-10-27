#include <stdio.h>

int main(void)
{
    int n, num = 0, ans = 0;
    scanf("%d", &n);

    while (n--) {
        scanf("%d", &num);
        ans ^= num;
    }  
    printf("%d\n", ans);
    
    return 0;
}
