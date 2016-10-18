#include <stdio.h>

#define MAX_STR_LEN 22

int main(void)
{
    unsigned short int N, Q;
    scanf("%hu", &N);
    char string_list[N][MAX_STR_LEN], query[MAX_STR_LEN];
    int i;
    for (i = 0; i < N; i++) {
        scanf("%s", string_list[i]);
    }

    scanf("%hu", &Q);

    while (Q--) {
        unsigned short count = 0;
        scanf("%s", query);
        for (i = 0; i < N; i++) {
            if (strcmp(string_list[i], query) == 0)
                count++;
        }
        printf("%d\n", count);
    }

    return 0;
}
