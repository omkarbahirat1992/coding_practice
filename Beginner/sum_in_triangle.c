/**************************************************************************************************************

All submissions for this problem are available.

Let's consider a triangle of numbers in which a number appears in the first line, two numbers appear in the second line, three in the third line, etc. Develop a program which will compute the largest of the sums of numbers that appear on the paths starting from the top towards the base, so that:
on each path the next number is located on the row below, more precisely either directly below or below and one place to the right;
the number of rows is strictly positive, but less than 100
all numbers are positive integers between O and 99.
Input

In the first line integer n - the number of test cases (equal to about 1000). Then n test cases follow. Each test case starts with the number of lines which is followed by their content.
Output

For each test case write the determined value in a separate line.
Example

Input:
2
3
1
2 1
1 2 3
4 
1 
1 2 
4 1 2
2 3 1 1 

Output:
5
9

Warning: large Input/Output data, be careful with certain languages


**************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100
void display_triangle(int **triangle, int rows)
{
    int i, j;
    for (i = 0; i < rows; i++) {
        printf("\n");
        for (j = 0; j < i + 1; j++) {
            printf("%d\t", triangle[i][j]);
        }
    }
}


 // Nth row contain N + 1 columns
int find_max_triangle(int triangle[][MAX], int row)
{
    int i,j;
    for (i = row-1; i > 0; i--) {
        for(j = 0; j < row; j++) {
            triangle[i-1][j] += (triangle[i][j] > triangle[i][j+1]) ? triangle[i][j]:triangle[i][j+1];
        }
    }
    return triangle[0][0];
}
int main(void)
{
    int triangle[MAX][MAX];
    int n, rows, i, j;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &rows);
        for (i = 0; i < rows; i++) {
            for (j = 0; j < (i+1); j++)
                scanf("%d", &triangle[i][j]);
        }
       printf("%d\n", find_max_triangle(triangle, rows));
      //  printf("\ngiven triangle is\n");
      //  display_triangle(triangle, rows);
    }
    return 0;
}
