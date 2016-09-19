#include <stdio.h>

int main(void)
{
        int N, num, total = 0, key;
        scanf("%d", &N);
        key = N * (N + 1);
        while (N--) {
                scanf("%d", &num);
                total += num;
        }
        if (key == (total * 2)) {
                printf("YES\n");
        } else {
                printf("NO\n");
        }
        return 0;
}
