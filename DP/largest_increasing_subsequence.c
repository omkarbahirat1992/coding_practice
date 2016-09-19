#include <stdio.h>

//#define MAX 9
//int arr[] = {2, 5, 3, 7, 11, 8, 10, 13, 6};

#define MAX 7
int arr[] = {3, 4, -1, 0, 6, 2, 3};

//#define MAX 5
//int arr[] = {2, 5, 1, 8, 3};

void display_solution(int *opt, int sol_val)
{
    int i;
    printf("\n");
    for (i = 0; i < MAX; i++)
        printf("%d ", arr[i]);

    printf("\n");
    for (i = 0; i < MAX; i++)
        printf("%d ", opt[i]);
    printf("\n");
    for (i = MAX - 1 ;i >= 0; i--) {
        if (opt[i] == sol_val) {
            printf("%d ", arr[i]);
            sol_val--;
            if (sol_val == 0)
                break;
        }
    }
    printf("\n");
}

int main(void)
{
    int opt[MAX], max = 0, final_max = -9999;
    int i, j;

    for (i = 0; i < MAX; i++)
        opt[i] = 1;

    for (i = 1; i < MAX; i++) {
        max = 0;
        for (j = i - 1; j >= 0 ; j--) {
            if (arr[j] <= arr[i]) {
                if (max < opt[j])
                    max = opt[j];
            }
        }
        opt[i] += max;
        if (final_max < opt[i])
            final_max = opt[i];
    }
    
    printf("length of LIS = %d\n\n", final_max);
    display_solution(opt, final_max);

    return 0;
}
