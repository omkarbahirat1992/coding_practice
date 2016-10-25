#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))


/* both start and end are inclusive */
long long int calculate_split_score(long long int *arr, int start, int end, long long int sum)
{
    int i, flag = 0;
    long long int cur_sum = 0;
    //printf("s: %d, e: %d sum: %lld\n", start, end, sum);
    if (start == end || (sum & 1)) {
        //printf("returning zero\n");
        return 0;
    }
    sum /= 2;
    for (i = start; i < end; i++) {
        cur_sum += arr[i];
        if (cur_sum == sum) {
            flag = 1;
            break;
        }
    }
    if (flag == 1) {
        int left_val = calculate_split_score(arr, start, i, cur_sum);
        int right_val = calculate_split_score(arr, i + 1, end, cur_sum);
        //printf("returning 1 + MAX(%d, %d)\n", left_val, right_val);
        return (1 + MAX(left_val, right_val));
    }
    //printf("returning 0\n");
    return 0;
}

int main(void)
{
    unsigned int T;
    scanf("%d", &T);

    while(T--) {
        unsigned int N, i;
        scanf("%d", &N);
        long long arr[N], sum = 0;
        for (i = 0; i < N; i++) {
            scanf("%lld", &arr[i]);
            sum += arr[i];
        }
        printf("%lld\n", calculate_split_score(arr, 0, (N - 1), sum));
    }
    
    return 0;
}
