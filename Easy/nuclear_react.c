#include <stdio.h>
#include <math.h>
#include <string.h>

int main(void)
{
        int A, N, K, given_K, new_val;
        unsigned long int val;

        scanf("%d%d%d", &A, &N, &given_K);
        int output_arr[given_K];

        memset(output_arr, 0, (given_K * sizeof(unsigned int)));
        K = given_K - 1;
        while (K > 0) {
                val = ((N + 1) * pow((N + 1), (K - 1)));
 //                       printf("val = %lu, K= %d, N = %d\n", val, K, N);
                if (val > A) {
                        K--;
                        continue;
                }
                val = N * pow((N + 1), K);
                if (val > A) {
                        output_arr[K] = A - (N * pow((N + 1), (K - 1)));
                        val = (output_arr[K] + N) * (pow((N + 1), (K - 1)));
                } else {
                        output_arr[K] = N;
                }
                A -= val;
                K--;
        }
        if (A == N)
                output_arr[K] = A;
        else 
                output_arr[K] = A % N;

        for (K = 0; K < given_K; K++) {
                printf("%d ", output_arr[K]);
        }
        printf("\n");
        return 0;
}
