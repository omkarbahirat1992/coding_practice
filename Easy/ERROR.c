#include <stdio.h>
#include <string.h>


int main(void)
{
        char str[1000002];
        int T;
        scanf("%d", &T);
        while (T--) {
                scanf("%s", str);
                if (strstr(str, "101") || strstr(str, "010"))
                        printf("Good\n");
                else
                        printf("Bad\n");
        }
        return 0;
}
