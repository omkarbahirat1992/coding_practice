/*
Problem statement:
One of the cherished customs of my childhood was choosing up sides for a cricket game. We did it this way: The two bullies of our gully would appoint themselves captains of the opposing teams, and then they would take turns picking other players. On each round, a captain would choose the most capable (or, towards the end, the least inept) player from the pool of remaining candidates, until everyone present had been assigned to one side or the other. The aim of this ritual was to produce two evenly matched teams and, along the way, to remind each of us of our precise ranking in the neighbourhood pecking order.

We all believed this was the fairest process, but does it ensure the fairest selection of players with evenly matched teams? We believed so, but then there were times when, as the game progressed we realized that the other team was stronger than ours and may be an exchange of a couple of players between the teams would have made them balanced. That scope of improvement seemed to be there...

Here, we need to find a way to create two evenly balanced teams for any game(or as evenly balanced as possible considering the strength of each player). A set of players must be divided into two teams. Each player must be on one team or the other; the number of player on the two teams must not differ by more than 1; each player will have a skill-point associated with him. The total skill-points of the players on each team should be as nearly equal as possible.(The absolute difference of the sum of skill-points of players in each team should be the least).

Input

The first line of input will contain the number of test cases 'T'(1<=T<=100). This is followed by 'T' test cases. Each test case starts with a blank line, followed by N, the total number of players. N lines will follow with the first line giving the skill-point of person 1; the second line, the skill-point of person 2; and so on. Each skill-point shall be an integer between 1 and 450. There shall be at most 100 players in all(1<=N<=100).

Output

Your output should be exactly '2T-1' lines. The output for each test case should be followed by a blank line, except the output for the last test case. Each odd numbered line should contain 2 numbers: the total skill-points of the players on one team, and the total skill-points of the players on the other team. Print the smaller sum first.

Example

Input:
4

3
90
200
100

10
2
3
10
5
8
9
7
3
5
2

10
1
1
1
1
1
1
1
1
1
9

8
87
100
28
67
68
41
67
1

Output:
190 200

27 27

5 13

229 230
************************************************************************************************************************/



#include <stdio.h> 
#include <stdlib.h>

unsigned int total_sum;
unsigned int max_team_len1;
unsigned int max_team_len2;
unsigned int val1;
unsigned int val2;
unsigned int min_diff;
unsigned int N;

#if 1
/* This solution takes O(2^n) */
void do_team_selection(int *skill_arr, unsigned int i, unsigned int cur_sum, unsigned int count)
{
    unsigned int diff;
    if ((i == 0)) { 
        if (count == max_team_len1 || count == max_team_len2) {
            diff = abs((total_sum - cur_sum) - cur_sum);
            if (min_diff > diff) {
                min_diff = diff;
                val1 = cur_sum;
                val2 = abs((total_sum - cur_sum));
            }
        } 

    } else {
        do_team_selection(skill_arr, i - 1, cur_sum + skill_arr[i - 1], count++);
        do_team_selection(skill_arr, i - 1, cur_sum, count);
    }
}
#endif

#if 0
void do_team_selection(int *skill_arr, unsigned int k, unsigned int cur_sum, unsigned int count)
{
    unsigned int opt[N][total_sum], i, j;
    int diff;
    for (i = 0; i < N; i++) {
            opt[i][0] = 0;
    }
    for (i = 0; i < total_sum; i++) {
            opt[0][i] = -1;
    }

    for (i = 1; i < N; i++) {
        for (j = 1; j < total_sum; j++) {

            opt[i][j] = opt[i - 1][j];  // if "i" is not included
            if ((j - skill_arr[i - 1]) >= 0) {
                opt[i][j] = 1 + opt[i - 1] [j - skill_arr[i - 1]];
            }
        }
    }
    for (j = 0; j < total_sum; j++) {
            if (opt[N - 1][j] == max_team_len1 || opt[N - 1][j] == max_team_len2) {
                    diff = abs((total_sum - j) - j);
                    if (min_diff > diff) {
                            printf("diff = %d j = %d\n", diff, j);
                            min_diff = diff;
                            val1 = j;
                            val2 = abs((total_sum - j));
                    }
            }
    }
}
#endif

int main(void)
{
    int T, i;

    scanf("%d", &T);

    while(T--) {
        scanf("%d", &N);
        int skill_arr[N];
        total_sum = 0;
        for (i = 0; i < N; i++) {
            scanf("%d", &skill_arr[i]);
            total_sum += skill_arr[i];
        }
        max_team_len1 = N >> 1;
        max_team_len2 = N >> 1;
        if (N & 1) {
            max_team_len2 ++;
        }

        min_diff = total_sum;
        val1 = 0;
        val2 = 0;

        do_team_selection(skill_arr, N, 0, 0);
        if (val1 < val2) {
            printf("%d %d\n", val1, val2);
        } else {
            printf("%d %d\n", val2, val1);
        }
        if (T)
            printf("\n");
    }
    return 0;
}
