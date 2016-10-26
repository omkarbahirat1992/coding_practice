#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

#define INT_SIZE 32
void test_switch(void)
{
        int type_count = -7, cur_score = 0;
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
        printf("cur_score = %d\n", cur_score);
}

void test_path(const char *path)
{
        int count = 0;
        char *ch_ptr = NULL, *prev_ptr = NULL;
        printf("Given = %s\n", path);
        count = 0;
        prev_ptr = strchr(path, '/');
        while((ch_ptr = strchr(prev_ptr, '/')) != NULL) {
                (*ch_ptr) = 0; 
                count++;
                printf("after: %s: count = %d\n", prev_ptr, count);
                prev_ptr = ++ch_ptr;
        }
        printf("after: %s: count = %d\n", prev_ptr, count);
}
void test_strlen()
{
        char a[10];
        char *ptr = NULL;
        //a[0] = NULL;
        printf("len = %u\n", strlen(a));
        ptr = (char*)malloc(1);
        
        free(ptr);
}

test_fun(void *addr)
{
        printf("val = %d\n", (int)addr);
}
void test_strange_ptr()
{
        int a = 10;
        int *ptr = &a;
        int *strange_ptr = (int*)a;

/*        printf("a = %d\n", a);
        printf("(*ptr) = %d\n", (*ptr));
        printf("(*strange_ptr) = %d\n", (strange_ptr));
*/        test_fun((void*)a);
}

#if 0
void test_fork(void)
{
        int a = 1;
        if (fork() == 0) {
                a = a + 5;
                printf("parent u = %d v = %d\n", a, &a);
        }  else {
                a = a - 5;
                printf("child x = %d y = %d\n", a, &a);
        }
}
#endif

void test_if(void)
{
        int a = 0, b = 0;
        if (a == b == 0)
                printf("all One\n");
        else 
                printf("all NOT One\n");
}

/*
Find an unique element, when all other elements occur exactly twice
*/
void test_unique_array_elem()
{
    int arr[] = {5, 5, 4, 3, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
 
    // Initialize result
    int result = 0, i;
 
    // Iterate through every bit
    for (i = 0; i < n; i++)
    {
        result ^= arr[i];
    }
    printf("The element with single occurrence is %d \n", result);
}
 
void test_if_continue()
{
    if (1) {
        printf("before continue\n");
  //      break;
        printf("after continue\n");
    }
}

void test_unbit_macro()
{
/* #define unbit1(ans, value) \
        (value & 1) ? ans : \
        #ifndef unbit  \
        #define unbit(ans, value) \
            (value & 1) ? ans : unbit1(ans+1, value >> 1)
        #endif

#ifndef unbit
#define unbit(ans, value) \
        (value & 1) ? ans : unbit(ans+1, value >> 1)
#endif

    printf("unbit(%d,%d) = %d\n", 0, 4, unbit(0, 4));
*/
}

void check_typeof()
{
    int a;
    void *ptr = &a;
    printf("a = %u\n", sizeof(typeof(a)));
    printf("ptr = %u\n", sizeof(typeof(*ptr)));
}
int main(void)
{
        char str[MAX];
        //char const * str_ptr = str;
//        const char* str_ptr = str;

//        str_ptr[1] = 'a';
//        str[0] = 'a';
//        str[1] = 'a';

/*        while(1) {
                printf("\nEnter path: \n");
                scanf("%s", str);
                test_path(str);
        }
        test_strlen();
        test_strange_ptr();
       
        test_fork();
        test_if();
        test_switch();
        test_unique_array_elem();
      test_if_continue();
      test_unbit_macro();
*/
    check_typeof();
         return 0;
}
