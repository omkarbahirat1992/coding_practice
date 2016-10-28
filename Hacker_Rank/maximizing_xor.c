#include <stdio.h>

unsigned int set_all_bits(unsigned int n)
{
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    return n;
}

unsigned int get_set_MSB_pos(unsigned int n)
{
    unsigned int pos = 0;
    if (n > 0xffff) {
        pos = 16; 
        n >>= 16;
    }
    if (n > 0xff) {
        pos |= 8;
        n >>= 8;
    }
    if (n > 0xf) {
        pos |= 4;
        n >>= 4;
    }
    if (n > 3) {
        pos |= 2;
        n >>= 2;
    }
    if (n > 1) {
        pos |= 1;
    }
    return pos;
}

int main(void)
{
    unsigned int L, R;
    scanf("%u%u", &L, &R);
    if (L == R) {
        printf("0");
    } else {
        unsigned int pos =  get_set_MSB_pos(R);
 //       printf("pos(%d) = %d\n", R, pos);
        unsigned int mask = 1 << pos;
 //       printf("mask = %d\n", mask);
        while (L & mask) {
            pos--;
            mask >>= 1;
        }
//        printf("mask = %d, pos = %d\n", mask, pos);
        printf("%d\n", set_all_bits(mask));
        
    }
    return 0;
}
