#include <stdio.h>
#include <stdlib.h>

typedef struct tagNode {
        int data;
        struct tagNode *next;
        struct tagNode *prev;
}Node;

typedef struct tagList {
        Node head;
}List;

int list_empty(List *list)
{
        return (list->head.next == &list->head && list->head.prev == &list->head);
}
void list_init(List *list)
{
        list->head.next = &list->head;
        list->head.prev = &list->head;
}

void display_list(List *list)
{
        Node *obj = list->head.next;
        printf("Contents of the list are: \n");
        while (obj != &list->head) {
                printf("%d\t", obj->data);
                obj = obj->next;
        }
        printf("\n");
}

void insert_head(List *list, Node *obj)
{
        obj->prev = &list->head;
        obj->next = list->head.next;
        list->head.next->prev = obj;
        list->head.next = obj;
}

void insert_last(List *list, Node *obj)
{
        obj->next = &list->head;
        obj->prev = list->head.prev;
        list->head.prev->next = obj;
        list->head.prev = obj;
}

void insert_after(Node *after_this_obj, Node *obj)
{
        obj->next = after_this_obj->next;
        obj->prev = after_this_obj;
        after_this_obj->next->prev = obj;
        after_this_obj->next = obj;

}

void insert_before(Node *before_this_obj, Node *obj)
{
        obj->next = before_this_obj;
        obj->prev = before_this_obj->prev;
        before_this_obj->prev->next = obj;
        before_this_obj->prev = obj;

}

void remove_node(Node *obj)
{
        Node *prev_obj = obj->prev;

        prev_obj->next = obj->next;
        obj->next->prev = prev_obj;

}
void delete_node(Node *obj)
{
        remove_node(obj);
        free(obj);
}

void free_list(List *list)
{
        Node *obj = list->head.next;
        Node *next_obj;

        while(!list_empty(list)) {
                next_obj = obj->next;       
                delete_node(obj);
                obj = next_obj;
        }
}


void accept_list(List *list, int n)
{
        Node *obj = NULL;
        while (n--) {
                obj = (Node*)malloc(sizeof(Node));
                if (obj == NULL) {
                        printf("Unable to allocate memory");
                        free_list(list);
                        exit(-1);
                }
                scanf("%d", &obj->data);
                insert_last(list, obj);
                //insert_before(&list->head, obj);
        }
}

void swap_node(Node *obj1, Node *obj2)
{
        remove_node(obj1);
        insert_after(obj2, obj1);
}

void quick_sort_ascending(List *list, Node *pivot, Node *last_node)
{
        Node *cur = pivot->next;
        Node *temp_cur;

        if (pivot == last_node) {
                return;
        }
        if (pivot == &list->head || last_node == &list->head)
                return;

        if (pivot->next == last_node) {
                if (pivot->data > last_node->data)
                        swap_node(pivot, last_node);
        } else {
                while (cur != last_node->next) {
                        if (pivot->data > cur->data) {
                                temp_cur = cur->next;
                                remove_node(cur);
                                insert_before(pivot, cur);
                                cur = temp_cur;
                                if (last_node->next == pivot) {
                                        break;
                                }
                                continue;
                        }
                        cur = cur->next;
                }
                //display_list(list);
                quick_sort_ascending(list, list->head.next, pivot->prev);
//                quick_sort_ascending(list, pivot->next, list->head.prev);
        }

}
int main(void)
{
        List sort_list;
        int n;
        printf("Enter number of elements: ");
        scanf("%d", &n);
        list_init(&sort_list);
        accept_list(&sort_list, n);
        display_list(&sort_list);
        quick_sort_ascending(&sort_list, sort_list.head.next, sort_list.head.prev);
        display_list(&sort_list);
        free_list(&sort_list);
        
}
