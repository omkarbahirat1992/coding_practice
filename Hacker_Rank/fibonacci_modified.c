#include <stdio.h>
#include <string.h>

#define MAX 200

char sqr_str[MAX];

/*
* pass the number to be squared in a reverse string form.
* e.g. to compute square(25) make a call do_big_sqr("52");
*/
void do_big_sqr(char str[MAX])
{
    char sqr_mat[MAX][MAX];
    int i, j, k, sum = 0, n = strlen(str), max_col = 0;

    memset(sqr_str, 0, MAX * sizeof(char));
    for (i = 0; i < n; i++) {
        memset(sqr_mat[i], '0', MAX * sizeof(char));
    }
    sum = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < i; j++) {
            sqr_mat[i][j] = '0';
        }
        for (k = 0; k < n; k++) {
            sum += ((str[i] - 48) * (str[k] - 48));
            sqr_mat[i][j] = (sum % 10) + 48;
            sum = sum / 10;
            j++;
        }
        while (sum) {
            sqr_mat[i][j] = (sum % 10) + 48;
            sum = sum / 10;
            j++;
        }
        if (j > max_col)
            max_col = j;
    }
#if 0
    for (i = 0; i < n; i++) {
        for (j = 0; j < 10; j++) {
            printf("%c ", sqr_mat[i][j]);
        }
        printf("\n");
    }
#endif
    sum = 0;
    for (j = 0; j < max_col; j++) {
        for (i = 0; i < n; i++) {
            sum += sqr_mat[i][j] - 48; 
        }
        sqr_str[j] = (sum % 10) + 48;
        sum = sum / 10;
    }
    while(sum) {
        sqr_str[j] = (sum % 10) + 48;
        sum = sum / 10;
        j++;
    }
    sqr_str[j] = '\0';
}

int main(void)
{
    int n, i, t1, t2;
    char fib_mat[21][MAX];

    for (i = 0; i < 21; i++) {
        memset(fib_mat[i], '0', MAX * sizeof(char));
    }
    scanf("%d%d%d", &t1, &t2, &n);
#if 0
    do_big_sqr("52");
    for (i = strlen(sqr_str); i >= 0; i--)
        printf("%c", sqr_str[i]);
    printf("\n");
#endif
#if 1
    fib_mat[1][0] = t1 + 48;
    fib_mat[1][1] = '\0';
    fib_mat[2][0] = t2 + 48;
    fib_mat[2][1] = '\0';
    for (i = 3; i <= n; i++) {
        int len, sum, j;
        do_big_sqr(fib_mat[i-1]);
        if (strlen(sqr_str) > strlen(fib_mat[i-2])){
            len = strlen(sqr_str);
        } else {
            len = strlen(fib_mat[i-2]);
        }
        j = 0;
        sum = 0;
        while (j < len) {
            if (fib_mat[i-2][j] == '\0') {
                sum += (sqr_str[j] - 48);
            } else if (sqr_str[j] == '\0') {
                sum += (fib_mat[i-2][j] - 48);
            } else {
                sum += (sqr_str[j] - 48) + (fib_mat[i-2][j] - 48);
            }
        fib_mat[i][j] = (sum % 10) + 48;
            sum = sum / 10;
            j++;
        }
        while(sum) {
            fib_mat[i][j] = (sum % 10) + 48;
            j++;
            sum = sum / 10;
        }
        fib_mat[i][j] = '\0';
  //      printf("fib[%d] = %s\n\n", i, fib_mat[i]);
    }
    for (i = strlen(fib_mat[n]) - 1; i >= 0; i--)
        printf("%c", fib_mat[n][i]);
#endif
    printf("\n");
    return 0;
}
