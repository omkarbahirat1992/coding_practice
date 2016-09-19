#include <stdio.h> 
#include <stdlib.h>

void do_team_selection(int *arr, int n)
{
    int t1_skill = 0, t2_skill = 0, available_skill, half_skill;
    int *opt = NULL;
    int i;
    
    opt = (int*) malloc(n * sizeof(int));
    
    for (i = 0; i < n; i++)
        available_skill += arr[i];

    half_skill = available_skill / 2;

    for (i = 0; i < n; i++) {
        opt[i] = min()
    }

    free(opt);
}
int main(void)
{
    int T, n, *skill_arr = NULL, i;

    scanf("%d", &T);

    while(T--) {
        scanf("%d", &n);

        skill_arr = (int*) malloc(n * sizeof(int));
        if (skill_arr == NULL) 
            return -1;

        for (i = 0; i < n; i++)
            scanf("%d", &skill_arr[i]);

        do_team_selection(skill_arr, n);

        free(skill_arr);
    }
    return 0;
}
