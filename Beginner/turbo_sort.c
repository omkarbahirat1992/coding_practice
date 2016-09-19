/* Sorting give set of an integer array in non-decreasing order */

/*I am using merge_sort to solve it*/

/**********************************************************************

Input:

t – the number of numbers in list, then t lines follow [t <= 10^6]. 
Each line contains one integer: N [0 <= N <= 10^6]
Output

Output given numbers in non decreasing order.
Example

Input:
5
5
3
6
7
1
Output:
1
3
5
6
7

************************************************************/

#include <stdio.h>
#include <stdlib.h>

void display(int *arr, unsigned int n)
{
    unsigned int i = 0;
    while (i < n) {
        printf("%d\n", arr[i]);
        i++;
    }
}

int* accept(unsigned int n)
{
    unsigned int i = 0;
    int *arr = NULL;
    arr = (int*)malloc(sizeof(int) * n);
    while (i < n) {
        scanf("%d", &arr[i]);
        i++;
    }
    return arr;
}

void merge(int *arr, int *L_arr, int L_end, int *R_arr, int R_end)
{
    int i = 0, j = 0, k = 0;
    
    while (i < L_end && j < R_end) {
        if (L_arr[i] < R_arr[j])
            arr[k++] = L_arr[i++];
        else
            arr[k++] = R_arr[j++];
    }
    
    while (i < L_end) {
        arr[k++] = L_arr[i++];
    }
    
    while (j < R_end) {
        arr[k++] = R_arr[j++];
    }
}

void merge_sort(int *arr, unsigned int end)
{
    unsigned int *L_arr, *R_arr, mid;
    unsigned int i;
    if (end < 2)
        return;
        
    mid = end /2;

    L_arr = (int*) malloc(sizeof(int) * mid);
    i = 0;
    while (i < mid) {
        L_arr[i] = arr[i];
        i++;
    }
    
    R_arr = (int*) malloc(sizeof(int) * (end - mid));
    i = mid;
    while (i < end) {
        R_arr[i - mid] = arr[i];
        i++;
    }

    merge_sort(L_arr, mid);
    merge_sort(R_arr, end - mid);
    
    merge(arr, L_arr, mid, R_arr, end - mid);
    free(L_arr);
    free(R_arr);
}

int main(void)
{
    unsigned int n;
    int *arr = NULL;
    
    scanf("%u", &n);
    if (n == 0)
        return 0;

    arr = accept(n);
//    printf("\nGiven elements are: \n");
//    display(arr, n);
    
    merge_sort(arr, n);
//    printf("\nSorted elements are: \n");
    display(arr, n);
    free(arr);
    return 0;
}
