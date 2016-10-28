#include <stdio.h>

int get_set_MBS_pos1(unsigned long long val)
{
    unsigned int k = 0;
    if (val > 0x0000FFFFu) { val >>= 16; k  = 16; }
    if (val > 0x000000FFu) { val >>= 8;  k |= 8;  }
    if (val > 0x0000000Fu) { val >>= 4;  k |= 4;  }
    if (val > 0x00000003u) { val >>= 2;  k |= 2;  }
    k |= (val & 2) >> 1;
    return k;
}

int get_set_MBS_pos2(unsigned long long v)
{
    double ff=(double)(v|1);
    //return ((*(1+(unsigned long *)&ff))>>20)-1023;
    return ((*(1+(unsigned long *)&ff))>>20)-1023;
}


int main(void)
{
    printf("method1: pos of set MSB of %d is: %d\n", 32, get_set_MBS_pos1(32));
    printf("method2: pos of set MSB of %d is: %d\n", 32, get_set_MBS_pos2(32));
    return 0;
}
