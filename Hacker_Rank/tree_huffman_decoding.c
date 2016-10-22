/* 
The structure of the node is

typedef struct node
{
    int freq;
    char data;
    node * left;
    node * right;
    
}node;

*/


void decode_huff(node * root, string s)
{
    int len = s.length();
    int i = 0;
    node * iter_node = root;
    while(i < len) {
        while(iter_node->left != NULL || iter_node->right != NULL) {
            if (s[i] == '0') {
                iter_node = iter_node->left;
            } else {
                iter_node = iter_node->right;
            }
            i++;
        }
        printf("%c", iter_node->data);
        iter_node = root;
    }
    printf("\n");
}

