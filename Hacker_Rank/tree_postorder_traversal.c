#include <stdio.h>


void preOrder(node *root)
{
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

#if 0
struct node {
    int data;
    struct node *left;
    struct node *right;
};

int main(void)
{
    return 0;
}
#endif
