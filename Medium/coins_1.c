#include <stdio.h>
#define MAX_VAL 1000000
#define MAX(i, j) ((i>j)?i:j)


long long int a[1000000] = {0},b=0,n;
 
long long int func(long long int m) {
        if(m<12)
                return m;
        if(m == 12)
                return 13;
        if(m < 1000000) {
                if(a[m] != 0)
                        return a[m];
        }
        long long int sum = func(m/2) + func(m/3) + func(m/4);
        if(m < 1000000)
                a[m] = sum;
        return sum;
}

long long int calculate_max(long long int val)
{
        if (val <= 11) {
                return val;
        }
        return calculate_max(val/2) + calculate_max(val/3) + calculate_max(val/4);
}

int main(void)
{
        long long int N;
        long long int val1;
        long long int val2;
        
 //       scanf("%lld", &N);
        for (N = 0; N < MAX_VAL; N++) {
                val1 = calculate_max(N);
                val2 = calculate_max(N);
                        printf("%lld: val1=%lld, val2=%lld\n",N, val1, val2);
                if (val1 != val2) {
                        printf("%lld: val1=%lld, val2=%lld\n",N, val1, val2);
                        break;
                }
        }

        return 0;
}
