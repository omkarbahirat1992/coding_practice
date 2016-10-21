#include <stdio.h>


int height(Node* root) {
    if (root != NULL) {
        int left_height = height(root->left) + 1;
        int right_height = height(root->right) + 1;
        return (left_height > right_height ? left_height : right_height);
    } 
    return -1;      
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
