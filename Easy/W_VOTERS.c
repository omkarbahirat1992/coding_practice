#include <stdio.h>

#define MAX 50000

int accept_list(int *arr, int n)
{
        int i;
        for (i = 0; i < n; i++) {
                scanf("%d", &arr[i]);
        }
}
void count_common(int *arr1, int *arr2, int *output, int N1, int N2, int *count)
{
        int i, j, k;
        k = (*count);
        for (i = 0, j = 0; i < N1 && j < N2; ) {
                if (arr1[i] < arr2[j]) {
                        i++;
                } else if (arr2[j] < arr1[i]) {
                        j++;
                } else {
                        i++;
                        j++;
                        k++;
                }
        }
        (*count) = k;
}

int main(void)
{
        int N1, N2, N3, i, j, k, count;
        int arr1[MAX], arr2[MAX], arr3[MAX], output[MAX];
        scanf("%d%d%d", &N1, &N2, &N3);
        accept_list(arr1, N1);
        accept_list(arr2, N2);
        accept_list(arr3, N3);
        i = 0;
        j = 0;
        k = 0;
        count = 0;
        while(1) {
                if (i >= N1) {
                        count_common(&arr2[j], &arr3[k], &output[count], N2, N3, &count);
                        break;
                }
                if (j >= N2 ) {
                        count_common(&arr1[i], &arr3[k], &output[count], N1, N3, &count);
                        break;
                }
                if (k >= N3) {
                        count_common(&arr1[i], &arr2[j], &output[count], N1, N2, &count);
                        break;
                }
                if (arr1[i] == arr2[j]) {
                        output[count++] = arr1[i];
                        while (arr3[k] <= arr1[i]) {
                                k++;
                        }
                        i++;
                        j++;
                        continue;
                }
                if (arr1[i] == arr3[k]) {
                        output[count++] = arr1[i];
                        while (arr2[j] <= arr1[i]) {
                                j++;
                        }
                        i++;
                        k++;
                        continue;
                }
                if (arr2[j] == arr3[k]) {
                        output[count++] = arr2[j];
                        while (arr1[i] <= arr2[j]) {
                                i++;
                        }
                        j++;
                        k++;
                        continue;
                }
                if (arr1[i] < arr2[j] && arr1[i] < arr3[k]) {
                        i++;
                } else if (arr2[j] < arr1[i] && arr2[j] < arr3[k]) {
                        j++; 
                } else {
                        k++;
                }
        }

        printf("%d\n", count);
        for(i = 0; i < count; i++) {
                printf("%d\n", output[i]);
        }
        return 0;
}
