#include <stdio.h>
#define MAX_LEN 12

int main(void)
{
    char input[MAX_LEN];
    int hh;
    scanf("%s", input);
    if (input[8] == 'A') {
        if (input[0] == '1' && input[1] == '2') {
            input[0] = '0';
            input[1] = '0';
        }
    } else {
        hh = ((input[0] - 48) * 10) + (input[1] - 48);
        hh = 12 + (hh % 12);
        input[0] = (hh / 10) + 48;
        input[1] = (hh % 10) + 48;
    }
    input[8] = '\0';
    printf("%s\n", input);
    return 0;
}
