#include <stdio.h>

int main(void)
{
        printf("int = %u\n", sizeof(int));
        printf("long int = %u\n", sizeof(long int));
        printf("long long int = %u\n", sizeof(long long int));

        printf("unsigned int = %u\n", sizeof(unsigned int));
        printf("long unsigned int = %u\n", sizeof(long unsigned int));
        printf("long long unsigned int = %u\n", sizeof(long long unsigned int));

        printf("float = %u\n", sizeof(float));
        printf("double = %u\n", sizeof(double));
        printf("long double = %u\n", sizeof(long double));
 //       printf("long long double = %u\n", sizeof(long long double));
        return 0;
}
