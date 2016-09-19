#include <stdio.h>

int main(void)
{
        int N, count = 0;
        scanf("%d", &N);
        while (N--) {
                int x1, x2, x3, y1, y2, y3;
                int t1, t2, t3;
                scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);
                t1 = ((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1));
                t2 = ((x3 - x1) * (x3 - x1)) + ((y3 - y1) * (y3 - y1));
                t3 = ((x3 - x2) * (x3 - x2)) + ((y3 - y2) * (y3 - y2));
                if ((t1 + t2) == t3 || (t1 + t3) == t2 || (t2 + t3) == t1) {
                        count++;
                }
        }
        printf("%d\n", count);
        return 0;
}
