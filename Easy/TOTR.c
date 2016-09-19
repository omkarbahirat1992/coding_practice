#include <stdio.h>
#include <string.h>

#define MAX_LEN 26

int main(void)
{
        int T;
        char trans_str[MAX_LEN + 1];
        scanf("%d %s", &T, trans_str);
        while (T--) {
                int len, i;
                char str[101];
                scanf("%s", str);
                len = strlen(str);
                for (i = 0; i < len; i++) {
                        int j = 0;
                        if (str[i] >= 'A' && str[i] <= 'Z') {
                                printf("%c", trans_str[str[i] - 'A'] - 32);
                        } else if (str[i] >= 'a' && str[i] <= 'z') {
                                printf("%c", trans_str[str[i] - 'a']);
                        } else if (str[i] == '_') {
                                printf(" ");
                        } else {
                                printf("%c", str[i]);
                        }
                }
                printf("\n");
        }
        return 0;
}
