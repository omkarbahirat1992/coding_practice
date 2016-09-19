#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

void free_list(struct node *head)
{
    struct node *temp;
    while(temp != NULL) {
        temp = head->next;
        free(head);
        head = temp;
    }
}

struct node *accept_list(int n)
{
    struct node *temp, *head = NULL, *last;
    if (n <= 0)
        return NULL;
    head = (struct node*)malloc(sizeof(struct node));
    if(head == NULL)
        return NULL;
    scanf("%d", &head->data);
    last = head;
    while (--n) {
        temp = NULL;
        temp = (struct node*)malloc(sizeof(struct node));
        if (temp == NULL) {
            free_list(head);
            break;
        }
        scanf("%d", &temp->data);
        last->next = temp;
        last = temp;
        last->next = NULL;
    }
    return head;
}

void display_list(struct node *head)
{
    struct node *temp;
    if (head == NULL)
        return;
    while (head != NULL) {
        printf("%d\t", head->data);
        head = head->next;
    }
    printf("\n");
}

struct node *bubble_sort(struct node *head, int n)
{
    int i;
    struct node *temp, *prev;
    if (head == NULL)
        return NULL;
    for (i = 0; i < n; i++) {
        temp = head;
        prev = temp;
        while (temp->next != NULL) {
            if(temp->data > temp->next->data) {
                if (temp == head) {
                    head = head->next;
                    temp->next = head->next;
                    head->next = temp;
                    prev = head;
                } else {
                    prev->next = temp->next;
                    temp->next = temp->next->next;
                    prev->next->next = temp;
                    prev = prev->next;
                }
                continue;
            }
            prev = temp;
            temp = temp->next;
        }
    }
    return head;
}

int main(void)
{
    int n;
    struct node* list_head = NULL;
    printf("Enter the number of elements:");   
    scanf("%d", &n);
    list_head = accept_list(n);
    if (list_head == NULL)
        return -1;
    printf("\n Given list is: \n");
    display_list(list_head);
    list_head = bubble_sort(list_head, n);
    printf("\n sorted list is: \n");
    display_list(list_head);
    free_list(list_head);
    return 0;
}
