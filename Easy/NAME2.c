#include <stdio.h>
#include <string.h>

#define MAX_LEN 25002

int find_nested_match(char *str1, char *str2, int len1, int len2)
{
        int i, j = 0;
        for (i = 0; i < len1; i++) {
                while (str2[j] != str1[i] && j < len2) {
                        j++;
                }
                if (j == len2) {
                        return 0;
                }
                j++;
        }
        return 1;
}

int main(void)
{
        int T;
        scanf("%d", &T);
        while (T--) {
                char men[MAX_LEN], women[MAX_LEN];
                int ret, m_len, w_len;

                scanf("%s %s", men, women);
                m_len = strlen(men);
                w_len = strlen(women);
                if (m_len <= w_len) {
                        ret = find_nested_match(men, women, m_len, w_len);
                } else {
                        ret = find_nested_match(women, men, w_len, m_len);
                }
                if (ret == 1) {
                        printf("YES\n");
                } else {
                        printf("NO\n");
                }
        }
}
