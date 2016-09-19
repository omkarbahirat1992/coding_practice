#include <stdio.h>
#include <stdlib.h>

struct TagData {
        int data;
        struct TagData *next;
};

int main(void)
{
        int T;
        scanf("%d", &T);
        while (T--) {
                int N, i, shift;
                scanf("%d", &N);
                struct TagData *head = NULL, *obj_ptr = NULL, *temp_ptr;
                for (i = 1; i <= N; i++) {
                        scanf("%d", &shift);
                        obj_ptr = (struct TagData *)malloc(sizeof(struct TagData));
                        obj_ptr->data = i;
                        obj_ptr->next = NULL;
                        if (head == NULL) {
                                head = obj_ptr;
                        } else {
                                temp_ptr = head;
                                shift = (i - 1) - shift - 1;
                                if (shift == -1) {
                                        obj_ptr->next = head;
                                        head = obj_ptr;
                                } else {
                                        while (shift--) {
                                                temp_ptr = temp_ptr->next;
                                        }
                                        obj_ptr->next = temp_ptr->next;
                                        temp_ptr->next = obj_ptr;
                                }
                        }
                }
                while (head != NULL) {
                        printf("%d ", head->data);
                        temp_ptr = head;
                        head = head->next;
                        free(temp_ptr);
                }
                printf("\n");
        }
        return 0;
}
