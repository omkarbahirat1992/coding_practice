/* This code is throwing some runtime error(RTE): may be dynamic memory handling problem */

#include <stdio.h>
#include <stdlib.h>

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

void free_triangle(int **triangle, int rows)
{
    int i;
    for (i = 0; i < rows; i++) {
        free(triangle[i]);
    }
    free(triangle);
}

/*
 * Nth row contain N + 1 columns
    start: path contains the value from next row which is exactly below or one step right to current
            so, start gives the starting index on next row
 */
int find_max_triangle_old_n_slow(int **triangle, int start, int columns, int rows, int temp_sum)
{
    static int max_sum;
    int cur_sum, i;
    if (columns == rows) {
        return temp_sum;
    }

    for (i = start; i < columns + 1 && i < start + 2; i++) {     // Nth column contain (N+1) elements
        cur_sum = find_max_triangle(triangle, i, columns + 1, rows, temp_sum + triangle[columns][i]);
        if (max_sum < cur_sum)
            max_sum = cur_sum;
    }
    return max_sum;
}


 // Nth row contain N + 1 columns
int find_max_triangle(int **triangle, int row)
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
    int **triangle = NULL;
    int n, rows, i, j;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &rows);
        triangle = (int **)malloc(rows * sizeof(int*));
        for (i = 0; i < rows; i++) {
            triangle[i] = (int*)malloc((i + 1) * sizeof(int));
            for (j = 0; j < (i+1); j++)
                scanf("%d", &triangle[i][j]);
        }
       printf("%d\n", find_max_triangle(triangle, rows));
      //  printf("\ngiven triangle is\n");
      //  display_triangle(triangle, rows);
        free_triangle(triangle, rows);
    }
    return 0;
}
