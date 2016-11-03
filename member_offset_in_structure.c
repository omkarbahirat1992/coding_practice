#include  <stdio.h>

#define offset_of_member(structure, member)  (size_t)(&(((structure *)0))->member)

struct node {
    double a;
    int b;
    char c;
    char d;
};


int main(void)
{
    struct node node_var;
    printf("offset of a = %u\n", offset_of_member(struct node, a));
    printf("offset of a = %u\n", (size_t)(&(((struct node*)0))->a));
    printf("offset of b = %u\n", (unsigned int)(&(((struct node*)0))->b));
    printf("offset of c = %u\n", (size_t)(&(((struct node*)0))->c));
    printf("offset of d = %u\n", (size_t)(&(((struct node*)0))->d));
    return 0;
}
