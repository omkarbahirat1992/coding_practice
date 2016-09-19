#include <stdio.h>
#include <string.h>
#define false 0
#define true 1

int isNumber(char* s) {
    printf("\nlen = %lu\n", strlen(s));
    int flag = false, first_e = true, first_dot = true;
    int i = 0;
    while(s[i] == 32) {
        i++;
    }
    printf("%d\n", first_dot);
    if (s[i] == 'e') return false;
    while (i < strlen(s)) {
        if (s[i] == 32) {
            while (s[i++] == 32);
            if (i == strlen(s) + 1) return true;
            else return false;
        }
        if ((s[i] < 48 || s[i] > 57)) {
            if (s[i] == 'e') {
                if (!first_e) return false;
                if (i == strlen(s) - 1) return false;
                first_e = false;
            } else if (s[i] == '.') {
                if (!first_dot) return false;
                first_dot = false;
            } else return false;
        }
        flag = true;
        i++;
    }
    return flag;

}


int main(void)
{
    char *str = "..2 ";
    printf("0 = %d 9 = %d\n", '0', '9');
    printf("%d\n", isNumber(str));
    return 0;
}
