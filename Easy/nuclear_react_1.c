#include <stdio.h>
#include <string.h>

int main(void)
{
        int A, N, given_K, i = 0;

        scanf("%d%d%d", &A, &N, &given_K);
        int output_arr[given_K];

        memset(output_arr, 0, (given_K * sizeof(unsigned int)));
        while (A) {
                if (i ==  given_K)
                        break;
                output_arr[i] = A % (N + 1);
                A = A / (N + 1);
                i++;
        }

        for (i = 0; i < given_K; i++) {
                printf("%d ", output_arr[i]);
        }
        printf("\n");
        return 0;
}
