#include <stdio.h>
#include <stdlib.h>

#define KASSERT(x) do { if (!(x)) printf("in if\n");} while(0)

int main(void)
{
        int *ptr = NULL;
        //ptr = (int *)malloc(sizeof(int));
        KASSERT(!ptr);
        KASSERT(ptr == NULL);
        //free(ptr);
        return 0;
}
