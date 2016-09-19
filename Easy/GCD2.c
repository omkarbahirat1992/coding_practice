#include <stdio.h>
#include <string.h>

int mod(int a, char b[300])
{
        int i, len, r;
        len = strlen(b);
        printf("len = %d\n", len);
        r = 0;
        for (i = 0; i < len; i++) {
                r = ((r*10) + (b[i] - '0'));  
                r = r % a;
        }
        return r;
}

int GCD2(int a, int b)
{
        if (b == 0) {
                return a;
        }
        return GCD2(b, (a % b));
}

int main(void)
{
        int T;
        scanf("%d", &T);
        while (T--) {
                int a;
                char b[300];
                scanf("%d %s", &a, b);
                printf("%d\n", GCD2(a, mod(a, b)));
        }
        return 0;
}
