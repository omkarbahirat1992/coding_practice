/*
   Reverse a doubly linked list, input list may also be empty
   Node is defined as
   struct Node
   {
     int data;
     Node *next;
     Node *prev;
   }
*/
Node* Reverse(Node* head)
{
    // Complete this function
    // Do not write the main method. 
    Node *iter_ptr = head;
   
    if (head) {
        Node *iter_ptr = head->next;
        while (iter_ptr != NULL) {
            head->next = head->prev;
            head->prev = iter_ptr;
            head = iter_ptr;
            iter_ptr = iter_ptr->next;
        }
        head->next = head->prev;
        head->prev = NULL;
    }
    
    iter_ptr = head;
   
    return head;
}

