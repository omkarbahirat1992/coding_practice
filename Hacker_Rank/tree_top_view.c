#include <stdio.h>


void top_view(node * root)
{
    static int count, flag;
    if (root != NULL) {
        if (flag == 0) {
            count++;
            top_view(root->left);
            printf("%d ", root->data);
            count--;
            if (count < 0) {
                flag = 1;
                top_view(root->right);
            }
        } else {
            printf("%d ", root->data);
            top_view(root->right);
        }
    } else if (flag == 0){
        count--;
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
