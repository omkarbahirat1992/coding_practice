#include <stdio.h>

#define MAX 256
#define LOOKUP_TABLE_SIZE 256

//unsigned int lookup_table[LOOKUP_TABLE_SIZE];
unsigned int lookup_table[] = {
        #define b2(n) n, n+1, n+1, n+2
        #define b4(n) b2(n), b2(n+1), b2(n+1), b2(n+2)
        #define b6(n) b4(n), b4(n+1), b4(n+1), b4(n+2)
        b6(0), b6(1), b6(1), b6(2)
    };

/* Brian Kernighan’s Algorithm */
unsigned int log_time_solution(int n)
{
    unsigned int count = 0;
    while(n) {
        n = n & (n - 1);
        count ++;
    }
    return count;
}

/* lookup table solution O(1)*/
unsigned int constant_time_solution(int v)
{
    unsigned int count = lookup_table[v & 0xff] + 
                            lookup_table[(v >> 8) & 0xff] + 
                            lookup_table[(v >> 16) & 0xff] + 
                            lookup_table[v >> 24];
    return count;
}

int main(void)
{
    int i;
    unsigned int table[] = {0, table[0], table[1]};
    printf("%d %d\n", table[0], table[1]);
    printf("solution by Brian Kernighan's Algorighm [log(n)]\n");
    for (i = 0; i < MAX; i++) {
        unsigned int sol = log_time_solution(i);
        if (sol != lookup_table[i]) {
            printf("issue at lookup_table[%d]\n", lookup_table[i]);
            return -1;
        }
        printf("set_bit_count(%d) = %u\n", i, sol);
    }

    /* lookup table solution */
    /*(
    for (i = 0; i < LOOKUP_TABLE_SIZE; i++) {
        lookup_table[i] = (i & 1) + lookup_table[i / 2]; //Dividing by 2 == Right shift (">>") by 1 bit
    }*/
    printf("\nsolution by lookup table method [log(1)]\n");
    for (i = 0; i < MAX; i++) {
        if (i%4 == 0) {
            printf("\n");
        }
        printf("set_bit_count(%d) = %u\n", i, constant_time_solution(i));
    }
    return 0;
}
