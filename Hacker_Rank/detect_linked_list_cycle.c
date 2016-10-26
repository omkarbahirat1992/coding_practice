/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as: 
    struct Node {
        int data;
        struct Node* next;
    }
*/

bool has_cycle(Node* head) {
    // Complete this function
    // Do not write the main method
    Node *slow_ptr = head, *fast_ptr = head;
    while (1) {
        if (slow_ptr == NULL || fast_ptr == NULL || fast_ptr->next == NULL) {
            return false;
        }
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
        if (slow_ptr == fast_ptr) {
            break;
        }
    }
    return true;
}

