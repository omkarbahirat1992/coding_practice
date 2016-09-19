#include <stdio.h>

int count_set_bits(unsigned int key)
{
        unsigned int count = 0;
        while (key) {
                key &= (key - 1);
                count++;
        }
        return count;
}

int main(void)
{
        unsigned int T, max_bits = sizeof(unsigned int) * 8;
        scanf("%u", &T);
        while (T--) {
                unsigned int N, a, b, total_setbits, max_val = 0;
                unsigned int bit_mask = 0, i;

                scanf("%u %u%u", &N, &a, &b);
                total_setbits = count_set_bits(a) + count_set_bits(b);
                if (total_setbits > N) {
                        bit_mask = ~0UL >> max_bits - (total_setbits - N);
                        total_setbits = N;
                }
                i = N - 1;
                while(total_setbits) {
                        max_val |= 1 << i;
                        i--;
                        total_setbits--;
                }

                max_val ^= bit_mask;
                printf("%u\n", max_val);
        }
        return 0;
}
