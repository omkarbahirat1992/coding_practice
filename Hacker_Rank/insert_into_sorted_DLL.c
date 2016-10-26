/*
    Insert Node in a doubly sorted linked list 
    After each insertion, the list should be sorted
   Node is defined as
   struct Node
   {
     int data;
     Node *next;
     Node *prev;
   }
*/
Node* SortedInsert(Node *head,int data)
{
    // Complete this function
   // Do not write the main method. 
    Node *iter_ptr = head, *new_node = NULL;
    
    iter_ptr = head;
    new_node = (Node*)malloc(sizeof(Node));
    if (new_node) {
        new_node->data = data;
        new_node->next = NULL;
        new_node->prev = NULL;
        if (head == NULL) {
            head = new_node;
            return head;
        }
        if (head->data > new_node->data) {
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
            return head;
        }
        while (iter_ptr->data < new_node->data) {
            if (iter_ptr->next == NULL) {
                iter_ptr->next = new_node;
                new_node->prev = iter_ptr;
                return head;
            }
            iter_ptr = iter_ptr->next;
        }
        new_node->prev = iter_ptr->prev;
        new_node->next = iter_ptr;
        iter_ptr->prev->next = new_node;
        iter_ptr->prev = new_node;
    }
    return head;
}

