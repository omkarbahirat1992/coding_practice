#include <stdio.h>
#include <math.h>

unsigned long long int get_max_val(unsigned long long val) 
{
    val |= val >> 16;
    val |= val >> 8;
    val |= val >> 4;
    val |= val >> 2;
    val |= val >> 1;
    return val;
}

int main(void)
{
    unsigned long long n, i, count = 0, limit;
    scanf("%llu", &n);
    
    limit = get_max_val(n) - n;
    for (i = 0; i <= limit;i++) {
        if ((i + n) == (i ^ n)) {
            count++;
        }
    }
    printf("%llu\n", count);
    return 0;
}
