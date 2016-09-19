#include <stdio.h>
#include <string.h>

int main(void)
{
        int A, N, given_K, i, flag = 0;

        scanf("%d%d%d", &A, &N, &given_K);
        int output_arr[given_K];

        memset(output_arr, 0, (given_K * sizeof(unsigned int)));
        while (A--) {
                output_arr[0]++;

                i = 0;
                if (output_arr[i] > N) {
                        while (output_arr[i] > N && i < given_K) {
                                output_arr[i] = 0;
                                i++;
                                if (i < given_K) {
                                        output_arr[i]++;
                                }
                        }
                }
        }

        for (i = 0; i < given_K; i++) {
                printf("%d ", output_arr[i]);
        }
        printf("\n");
        return 0;
}
