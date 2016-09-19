#include <stdio.h>
#define MAX 100000000

long long int opt[MAX];
long long int calculate_max(long long int val)
{
        long long int sum;
        if (val <= 11) {
                return val;
        }

        if(val < MAX && opt[val] != 0)
                return opt[val];

        sum = calculate_max(val/2) + calculate_max(val/3) + calculate_max(val/4);
        if (val < MAX)
                opt[val] = sum;
        return sum;
}

int main(void)
{
        long long int N;
        while(scanf("%lld", &N) != EOF)
                printf("%lld\n", calculate_max(N));

        return 0;
}
