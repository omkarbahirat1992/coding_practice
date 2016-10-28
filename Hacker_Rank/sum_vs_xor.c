#include <stdio.h>
#include <math.h>

unsigned long long int get_all_one_after_set_MSB_mask(unsigned long long val) 
{
    val |= val >> 32;
    val |= val >> 16;
    val |= val >> 8;
    val |= val >> 4;
    val |= val >> 2;
    val |= val >> 1;
    return val;
}

unsigned int total_set_bits(unsigned long long n)
{
    unsigned int count = 0;
    unsigned int lookuptable[256] = {
        #define b2(n) n, n+1, n+1, n+2
        #define b4(n) b2(n), b2(n+1), b2(n+1), b2(n+2)
        #define b6(n) b4(n), b4(n+1), b4(n+1), b4(n+2)
        b6(0), b6(1), b6(1), b6(2)
    };
    count += lookuptable[n & 0xff];
    count += lookuptable[n >> 8 & 0xff];
    count += lookuptable[n >> 16 & 0xff];
    count += lookuptable[n >> 24 & 0xff];
    count += lookuptable[n >> 32 & 0xff];
    count += lookuptable[n >> 40 & 0xff];
    count += lookuptable[n >> 48 & 0xff];
    count += lookuptable[n >> 56];
    return count;
}

/*
Flip all the bits including and after first set MSB.
Now count number of set bits.
*/
unsigned int total_zeros_after_set_MSB(unsigned long long n)
{
    n = n ^ get_all_one_after_set_MSB_mask(n);  //Flipping all the bits including and after first set MSB
    return(total_set_bits(n));  
}

int main(void)
{
    unsigned long long n, i, count = 0, limit;
    scanf("%llu", &n);
    printf("%u\n", 1 << total_zeros_after_set_MSB(n));
    return 0;
}
