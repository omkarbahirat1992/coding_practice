#include <stdio.h>

#define MAX 50

void display_reduced_version(int *ingrad, int N, int GCD)
{
    int i;
    for (i = 0; i < N; i++)
        printf("%d ", ingrad[i]/GCD);
    printf("\n");
}

unsigned int gcd(unsigned int u, unsigned int v)
{
    int shift;
    if (u == 0) return v;
    if (v == 0) return u;
    shift = __builtin_ctz(u | v);
    u >>= __builtin_ctz(u);
    do {
        v >>= __builtin_ctz(v);
        if (u > v) {
            unsigned int t = v;
            v = u;
            u = t;
        }  
        v = v - u;
    } while (v != 0);
    return u << shift;
}

int find_GCD(int *ingrad, int N)
{
    int i, val;
    val = gcd(ingrad[0], ingrad[1]);
    for (i = 2; i < N; i++) {
        val = gcd(val, ingrad[i]); 
    }
    return val;
}

int main(void)
{
    int T, i;
    int N;  //Number of ingregient
    int ingrad[MAX];
    
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &N);
        for (i = 0; i < N; i++)
            scanf("%d", &ingrad[i]);

        display_reduced_version(ingrad, N, find_GCD(ingrad, N));
    }
    return 0;
}
