/*
   Find merge point of two linked lists
   Node is defined as
   struct Node
   {
       int data;
       Node* next;
   }
*/
int FindMergeNode(Node *headA, Node *headB)
{
    // Complete this function
    // Do not write the main method. 
    struct Node *temp_A = headA, *temp_B = headB;
    int count_A = 0, count_B = 0, ret = 0;
    
    while (temp_A != NULL) {
        count_A++;
        temp_A = temp_A->next;
    }
    
    while(temp_B != NULL) {
        count_B++;
        temp_B = temp_B->next;
    }
    
    temp_A = headA;
    temp_B = headB;
    while (count_A > count_B) {
        temp_A = temp_A->next;
        count_A--;
    }
    while(count_B > count_A) {
        temp_B = temp_B->next;
        count_B--;
    }
    
    while (temp_A != NULL) {
        if (temp_A == temp_B) {
            ret = temp_B->data;
            break;
        }
        temp_A = temp_A->next;
        temp_B = temp_B->next;
    }
    return ret;
}

