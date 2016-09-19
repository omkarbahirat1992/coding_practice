/*
Every Friday Chef and his N - 1 friends go for a party. At these parties, they play board games. This Friday, they are playing a game named "Boats! Boats! Boats!". In this game players have to transport cookies between Venice and Constantinople. Each player has a personal storage. The players are numbered from 1 to N, Chef is numbered 1. Rules for determining a winner are very difficult, therefore Chef asks you to write a program, which will determine who is a winner.

There are 6 types of cookies. For each cookie in the storage player gets 1 point. Also player gets additional points if he packs his cookies in some boxes as follows:

A box containing 4 different types of cookies fetches 1 additional point.
A box containing 5 different types of cookies fetches 2 additional points.
A box containing 6 different types of cookies fetches 4 additional points.
Obviously a cookie can be put into a single box.
For each player, you know the number of cookies in his storage (denoted by c[i]), also the types of cookies in the storage given denoted by type[i][j].

Your task is to determine the winner of this game. Output "tie" if there are two or more players with same maximum score, "chef" if only Chef has a maximum score, winner's index in all other cases.

Input

The first line of input contains a single integer T denoting the number of test cases. This will be followed by T test cases.

The first line of each test case contains an integer N denoting the number of players.

The second line of each test case contains an integer c[i] denoting the number of cookies in the i-th storage, followed by c[i] space-separated integers type[i][j] which denote the type if j-th cookie in the storage i-th.

Output

For each test case, output a single line containing the answer as specified in the statement.

Constraints and Subtasks

Subtask #1 : (20 points) 
1 ≤ T ≤ 10
1 ≤ N ≤ 100
1 ≤ c[i] ≤ 100
1 ≤ type[i][j] ≤ 3

Subtask #2 : (80 points) 
1 ≤ T ≤ 10
1 ≤ N ≤ 100
1 ≤ c[i] ≤ 100
1 ≤ type[i][j] ≤ 6
Example

Input:
3
2
6 1 2 3 4 5 6
9 3 3 3 4 4 4 5 5 5
2
5 2 3 4 5 6
7 1 1 2 2 3 3 4
3
4 1 1 2 3
4 1 2 2 3
4 1 2 3 3

Output:
chef
2
tie
Explanation

Example case 1.

Chef has total 6 cookie, so he gets 6 points for that. Also, he can put all his cookies (as they are all distinct) in a bag of size 6. It will fetch him additional 4 points. So, Chef's total points will be 10.

The second player has 9 cookies, he gets 9 points for that. Other than this, he can't create a bag with either 4, 5 or 6 distinct cookies. So, his final score is 9.

10 > 9 - Chef wins.

Example case 2.

Chef has 5 + 2 (a bag with 5 different cookies) = 7.

The second player has 7 + 1(a bag with 4 different cookies) = 8.

7 < 8 - the second player wins.

Example case 3.

Every player has 4 cookies and can't create any bag of sweets. So, it's a tie.
****************************************************************************************************************************/

#include <stdio.h>
#include <string.h>

#define MAX_TYPES 7

int main(void)
{
        int T, N, type_arr[MAX_TYPES], max_id, max_score;
        scanf("%d", &T);
        while (T--) {
                int i, C, tie_flag = 0;
                max_id = -1;
                max_score = -1;

                scanf("%d", &N);
                for (i = 1; i <= N; i++) {
                        int type_count = 0, cur_score, cur_type, j;

                        scanf("%d", &C);
                        cur_score = C;

                        memset(type_arr, 0, MAX_TYPES * sizeof(int));
                        while (C--) {
                                scanf("%d", &cur_type);
                                type_arr[cur_type]++;
                        }
                        do {
                                type_count = 0;
                                for (j = 1; j < MAX_TYPES; j++) {
                                        if (type_arr[j] > 0) {
                                                type_arr[j]--;
                                                type_count++;
                                        }
                                }
                                switch (type_count) {
                                        case 4:
                                                cur_score += 1;
                                                break;
                                        case 5:
                                                cur_score += 2;
                                                break;
                                        case 6:
                                                cur_score += 4;
                                                break;
                                }
                        } while (type_count >= 4);

                        if (cur_score > max_score) {
                                max_score = cur_score;
                                max_id = i;
                                tie_flag = 0;
                        } else if (cur_score == max_score) {
                                tie_flag = 1;
                        }
                }
                if (tie_flag == 1) {
                        printf("tie\n");
                } else if (max_id == 1) {
                        printf("chef\n");
                } else {
                        printf("%d\n", max_id);
                }
                
        }
        return 0;
}
