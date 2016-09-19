#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CHEF 1
#define ASSIS 2
#define MASK 3
#define NONE 4

void display_output(int *input_ptr, int n)
{
        int i;
        for (i = 1; i <= n; i++) {
                if (input_ptr[i] == CHEF)
                        printf("%d ", i);
        }
        printf("\n");
        for (i = 1; i <= n; i++) {
                if (input_ptr[i] == ASSIS)
                        printf("%d ", i);
        }
        printf("\n");
}
int main(void)
{
        int *input_ptr = NULL;
        int m, n, T, done_idx, i, person;
        scanf("%d", &T);
        while (T--) {
                scanf("%d%d", &n, &m);
                input_ptr = (int *)malloc((n + 1) * sizeof(int));
                memset(input_ptr, 0, (n + 1) * sizeof(int));
                while(m--) {
                        scanf("%d", &done_idx);
                        input_ptr[done_idx] = NONE;
                }
                person = CHEF;
                for (i = 1; i <= n; i++) {
                        if (input_ptr[i] != NONE) {
                                input_ptr[i] = person;
                                person = person ^ MASK;
                        }
                }
                display_output(input_ptr, n);
                free(input_ptr);
        }
        return 0;

}
