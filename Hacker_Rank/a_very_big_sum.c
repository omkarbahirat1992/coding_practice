#include <stdio.h>
#include <string.h>
#define MAX  20
#define MAX_STRING_LEN 12

int main(void)
{
    short int arr[MAX], max_idx = 0;
    int len, n, i, j, sum, carry;
    char input[MAX_STRING_LEN];
    scanf("%d", &n);
    memset(arr, 0, MAX * sizeof(short int));
    while (n--) {
        scanf("%s", input);
        len = strlen(input) - 1;
        i = 0;
        while (len >= 0) {
            sum = input[len] - 48;
            sum += arr[i];
            arr[i] = sum % 10;
            carry = sum / 10;
            j = i;
            i++;
            while (carry != 0) {
                j++;
                if (j == MAX) {
                    break;
                }
                sum = carry + arr[j];
                arr[j] = sum % 10;
                carry = sum / 10;
            }
            if (j > max_idx) {
                max_idx = j;
            }
            len--;
        }
    }
    while (max_idx >= 0) {
        printf("%d", arr[max_idx]);
        max_idx--;
    }
    printf("\n");
    return 0;
}
