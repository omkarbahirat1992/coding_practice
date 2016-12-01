#include <stdio.h>

struct contest_tag {
    int L;
    int r;
};

/* sorting in descending order */
int compare(void *a, void *b)
{
    return ((*((struct contest_tag*)b)).L - (*((struct contest_tag*)a)).L);
}

int main(void)
{
    int N, k, i, count = 0;
    scanf("%d%d", &N, &k);
    struct contest_tag contest[N];

    for (i = 0; i < N; i++) {
        scanf("%d%d", &contest[i].L, &contest[i].r);
    }

    qsort(contest, N, sizeof(struct contest_tag), compare);

    for (i = 0; i < N; i++) {
        if (contest[i].r == 0) {
            count += contest[i].L;
        } else if (k) {
            count += contest[i].L;
            k--;
        } else {
            count -= contest[i].L;
        }
    }
    printf("%d\n", count);

    return 0;
}
