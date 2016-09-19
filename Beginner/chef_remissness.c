#include <stdio.h>
#define MAX(a,b) ((a) > (b)) ? (a) : (b)

int main(void)
{
    int n; //number of TC's
    int A, B;
    scanf("%d", &n);
    while(n--) {
        scanf("%d%d", &A, &B);
        printf("%d %d\n", MAX(A,B), (A + B));
    }
}
