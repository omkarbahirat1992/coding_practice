#include <stdio.h>

int main(void)
{
    int n = 14;
    switch (n%3) {
        case 0: do {printf("case 0: n = %d\n", n);
        case 1: printf("case 1: n = %d\n", n);
        case 2: printf("case 2: n = %d\n", n);
        default: printf("default : n = %d\n", n);
                } while(--n > 0);
    }
    return 0;
}
