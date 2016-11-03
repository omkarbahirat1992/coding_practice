#include <stdio.h>

#define my_sizeof_v1(var) (size_t)((char*)(&var + 1) - (char*)(&var))
#define my_sizeof_v2(var) (size_t)((typeof(var)*)0 + 1)

int main(void)
{
    int a;
    printf("sizeof int a = %u\n", my_sizeof_v1(a));
    printf("sizeof int a = %u\n", my_sizeof_v2(a));
    printf("sizeof int a = %u\n", (size_t)((typeof(a)*)0 + 1));
    return 0;
}
