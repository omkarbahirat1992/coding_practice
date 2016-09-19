#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void free_list(struct node* head)
{
    struct node *temp;
    while(head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
struct node *accept_list(int n)
{
    struct node *head = NULL, *temp, *last;
    if (n <= 0)
        return NULL;
    head = (struct node*)malloc(sizeof(struct node));
    if (head == NULL)
        return NULL;
    scanf("%d", &head->data);
    last = head;
    last->next = NULL;

    while(--n) {
        temp = NULL;
        temp = (struct node*)malloc(sizeof(struct node));
        if (temp == NULL) {
            free_list(head);
            return NULL;
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
    while (head != NULL) {
        printf("%d\t", head->data);
        head = head->next;
    }
    printf("\n");
}

struct node *selection_sort(struct node* head, int n)
{
    struct node *cur_head, *temp, *min_temp, *prev_to_min_temp = NULL, *prev_to_cur_head = NULL, *prev;
    if (head == NULL)
        return NULL;
    cur_head = head;
    while(cur_head->next != NULL) {
        prev = cur_head;
        temp = cur_head->next;
        min_temp = cur_head;
        while (temp != NULL) {
            if (temp->data < min_temp->data) {
                min_temp = temp;
                prev_to_min_temp = prev;
            }
            prev = temp;
            temp = temp->next;
        }
        if (min_temp == cur_head) {
            prev_to_cur_head = cur_head;
            cur_head = cur_head->next;
            continue;
        }

        if (cur_head == head) {
            if (head->next == min_temp) {
                head->next = min_temp->next;
                min_temp->next = head;
            } else {
                temp = head->next;
                head->next = min_temp->next;
                prev_to_min_temp->next = head;
                min_temp->next = temp;
            }
            head = min_temp;
            cur_head = head->next;
            prev_to_cur_head = head;
        } else {
            if (cur_head->next == min_temp) {
                cur_head->next = min_temp->next;
                min_temp->next = cur_head;
                prev_to_cur_head->next = min_temp;
                prev_to_cur_head = min_temp;
            } else {
                display_list(head);
                temp = cur_head->next;
                cur_head->next = min_temp->next;
                prev_to_min_temp->next = cur_head;
                min_temp->next = temp;
                prev_to_cur_head->next = min_temp;
                cur_head = temp;
                prev_to_cur_head = min_temp;
            }
        }
    }
    return head;
}

int main(void)
{
    int n;
    struct node *list_head = NULL;
    printf("Enter the total number of elements: \n");
    scanf("%d", &n);
    list_head = accept_list(n);
    if (list_head == NULL)
        return -1;
    printf("\nGiven list is:\n");
    display_list(list_head);
    list_head = selection_sort(list_head, n);
    printf("\nSorted list is: \n");
    display_list(list_head);

    free_list(list_head);
    
    return 0;
}
