/*
 * You are asked to calculate factorials of some small positive integers.
 * Input
 *
 * An integer t, 1<=t<=100, denoting the number of testcases, followed by t lines, each containing a single integer n, 1<=n<=100.
 * Output
 *
 * For each integer n given at input, display a line with the value of n!
 * Example
 *
 * Sample input:
 * 4
 * 1
 * 2
 * 5
 * 3
 * Sample output:
 * 1
 * 2
 * 120
 * 6
 */

#include <stdio.h>
 
/* Indices will be used from factorial_mat[1][0] */
#define ROWS 101
#define COLUMNS 200

int factorial_mat[ROWS][COLUMNS];
 
void multiply_with_previous(int row)
{
    int col = 0;
    while (col < COLUMNS) {
        factorial_mat[row][col] = factorial_mat[row-1][col] * row;
        col++;
    }
}

void do_carry_forward_of_current(int row)
{
    int col = COLUMNS - 1, carry = 0, temp_val;
    while (col >= 0) {
        temp_val = factorial_mat[row][col] + carry;
        factorial_mat[row][col] = temp_val % 10;
        carry = temp_val / 10;
    col--;
    }
}

void explore()
{
    int row = 1, col = 0;
    /* setting up the first row for factorial of 1 */
    while(col < COLUMNS)
        factorial_mat[row][col++] = 0;
    
    factorial_mat[row][COLUMNS - 1] = 1;

    row++;
    while(row < ROWS) {
    multiply_with_previous(row);
    do_carry_forward_of_current(row);
    row++;
    }
}

void display_fact(int n)
{
    int i = 0;	
    while (factorial_mat[n][i] == 0 && i < COLUMNS) {
        i++;
    }
    while (i < COLUMNS) {
        printf ("%d", factorial_mat[n][i]);
        i++;
    }
    printf("\n");
}

int main(void)
{
    int n = 0, t;
    explore();
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        display_fact(n);
    }
    return 0;
} 
