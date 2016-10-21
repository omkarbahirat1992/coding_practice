#include <stdio.h>


struct Queue_tag {
    node *node_ptr;
    struct Queue_tag *next;
};
struct Queue_tag *Q_head = NULL, *Q_last = NULL;

void enqueue(struct node *node_ptr)
{
    struct Queue_tag *temp_Q_ptr = NULL;
    if (node_ptr != NULL) {
        temp_Q_ptr = (struct Queue_tag *)malloc(sizeof(struct Queue_tag));
        temp_Q_ptr->node_ptr = node_ptr;
        temp_Q_ptr->next = NULL;
        if (Q_head == NULL) {
            Q_head = temp_Q_ptr;
        } else {
            Q_last->next = temp_Q_ptr;
        }
        Q_last = temp_Q_ptr;
    }
}

struct node *dequeue(void)
{
    struct Queue_tag *temp_Q_ptr = Q_head;
    node *node_ptr = temp_Q_ptr->node_ptr;
    Q_head = Q_head->next;
    free(temp_Q_ptr);
    return node_ptr;
}

void LevelOrder(node * root)
{
    node *node_ptr = NULL;
    enqueue(root);
    while(Q_head != NULL) {
        node_ptr = dequeue();
        printf("%d ", node_ptr->data);
        enqueue(node_ptr->left);
        enqueue(node_ptr->right);
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
