#include <stdio.h>
#include <string.h>

#define MAX 101

int main(void)
{
        int T;
        char jewel[MAX], stone[MAX];
        scanf("%d", &T);
        while(T--) {
                int jewel_len, stone_len, count, i, j;
                scanf("%s", jewel);
                scanf("%s", stone);
                jewel_len = strlen(jewel);
                stone_len = strlen(stone);
                count = 0;
                for (i = 0; i < stone_len; i++) {
                        for(j = 0; j < jewel_len; j++) {
                                if (stone[i] == jewel[j]) {
                                        count++;
                                        break;
                                }
                        }
                }
                printf("%d\n", count);

        }
        return 0;
}
