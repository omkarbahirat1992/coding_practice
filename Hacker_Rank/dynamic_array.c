#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

struct Vector_Tag {
    int total_use;
    int capacity;
    int *list;
};


void display_list(int idx, int *list, int count)
{
    int i;
    printf("content at list #%d: \n", idx);
    for (i = 0; i < count; i++) {
        printf("%d ", list[i]);
    }
    printf("\n\n");

}
int main(void)
{
    int N, Q, last_ans = 0, i;
    scanf("%d%d", &N, &Q);
    struct Vector_Tag list_seq[N];

    for (i = 0; i < N; i++) {
        list_seq[i].total_use = 0;
        list_seq[i].capacity = SIZE;
        list_seq[i].list = NULL;
    }

    while(Q--) {
        int query;
        unsigned long long x, y;
        scanf("%d %llu %llu", &query, &x, &y);
//        printf("%d %llu %llu\n", query, x, y);
        switch(query) {
            int idx, val_idx;
            case 1:
                    idx = (x ^ last_ans) % N;
//                    printf("idx = %d\n", idx);
                    if (list_seq[idx].list == NULL) {
                        list_seq[idx].list = (int *) malloc(list_seq[idx].capacity * sizeof(int));
                        
                    } else if (list_seq[idx].total_use == list_seq[idx].capacity) {
                        list_seq[idx].capacity += SIZE;
                        list_seq[idx].list = (int *)realloc(list_seq[idx].list, list_seq[idx].capacity * sizeof(int));
                    }
                    list_seq[idx].list[list_seq[idx].total_use] = y;
                    list_seq[idx].total_use++;
//                    display_list(idx, list_seq[idx].list, list_seq[idx].total_use);
                break;

            case 2:
 //                   printf("case2:\n");
                    idx = (x ^ last_ans) % N;
 //                   printf("idx = %d total_use = %d\n", idx, list_seq[idx].total_use);
                    val_idx = y % (list_seq[idx].total_use);
 //                   printf("val_idx = %d\n", val_idx);
                    last_ans = list_seq[idx].list[val_idx];
                    printf("%d\n", last_ans);
        }
    }
    for (i = 0; i < N; i++) {
        free(list_seq[i].list);
    }
    return 0;
}
