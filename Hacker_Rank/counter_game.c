#include <stdio.h>

unsigned int find_set_bit_pos(unsigned long long int N)
{
    unsigned int pos = 0;
    if (N > 0xffffffff) {
        N >>= 32;
        pos = 32;
    }
    if (N > 0xffff) {
        N >>= 16;
        pos |= 16;
    }
    if (N > 0xff) {
        N >>= 8;
        pos |= 8;
    }
    if (N > 0xf) {
        N >>= 4;
        pos |= 4;
    }
    if (N > 3) {
        N >>= 2;
        pos |= 2;
    }
    if (N > 1) {
        pos |= 1;
    }
    return pos;
}

unsigned long long int get_largest_powerof_two_less_than_N(unsigned long long int N)
{
    N |= N >> 1;
    N |= N >> 2;
    N |= N >> 4;
    N |= N >> 8;
    N |= N >> 16;
    N |= N >> 32;

    N = N ^ (N >> 1);
    return N;
}

int main(void)
{
    unsigned short int T;
    unsigned long long int N;
    scanf("%hu", &T);
    while (T--) {
        scanf("%llu", &N);
        unsigned int pos;
        if (N == 1) {
            printf("Richard\n");
        } else if ((N & (N-1)) == 0) {
            pos = find_set_bit_pos(N);
            if (pos & 1) {
                printf("Louise\n");
            } else {
                printf("Richard\n");
            }
        } else {
            N = N - get_largest_powerof_two_less_than_N(N);
            //N >>= 1;
            pos = find_set_bit_pos(N);
            if (pos & 1) {
                printf("Richard\n");
            } else {
                printf("Louise\n");
            }
        }
    }
    
    return 0;
}
