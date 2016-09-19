#include <stdio.h>
#include <string.h>

int main(void)
{
        int T, h1, h2, len, mid, found_flag, i;
        char str[1010];

        scanf("%d", &T);
        while (T--) {
                scanf("%s", str);
                len = strlen(str);
                h1 = 0;
                mid = len / 2;
                h2 = mid;
                if ((h2 * 2) != len)
                        h2++;
                while (h1 < mid) {
                        found_flag = 0;
                        for (i = h2; i < len; i++) {
                                if (str[h1] == str[i]) {
                                        found_flag = 1;
                                        str[i] = 0;
                                        break;
                                }
                        }
                        if (found_flag == 0)
                                break;
                        h1++;
                }
                if (found_flag == 1)
                        printf("YES\n");
                else
                        printf("NO\n");
        }
        return 0;
}
