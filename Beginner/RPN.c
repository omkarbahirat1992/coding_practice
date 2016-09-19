/************************************************************************************

Reverse Polish Notation (RPN) is a mathematical notation where every operator follows all of its operands. For instance, to add three and four, one would write "3 4 +" rather than "3 + 4". If there are multiple operations, the operator is given immediately after its second operand; so the expression written "3 − 4 + 5" would be written "3 4 − 5 +" first subtract 4 from 3, then add 5 to that.
Transform the algebraic expression with brackets into RPN form.
You can assume that for the test cases below only single letters will be used, brackets [] will not be used and each expression has only one RPN form (no expressions like a*b*c)
Input

The first line contains t, the number of test cases (less then 100).
Followed by t lines, containing an expression to be translated to RPN form, where the length of the expression is less then 400.
Output

The expressions in RPN form, one per line.
Example

Input:
3
(a+(b*c))
((a+b)*(z+x))
((a+t)*((b+(a+c))^(c+d)))

Output:
abc*+
ab+zx+*
at+bac++cd+^*

************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 400


void push(char *stack, int *top, char key)
{
    if (*top < MAX)
        stack[(*top)++] = key;
    else
        exit(1);
}

char pop(char *stack, int *top)
{
    if (*top < 0)
        exit(1);
    (*top)--;
    return stack[*top];
}

void RPN(char *input, int len)
{
    int i;
    char stack[MAX], ch;
    int top = 0;
    for(i = 0; i < len; i++) {
        if ((input[i] == '(') || (input[i] == '+') ||
            (input[i] == '-') || (input[i] == '*') ||
            (input[i] == '/') || (input[i] == '^') ) {

            push(stack, &top, input[i]);

        } else if (input[i] == ')') {
            while (1) { 
                ch = pop(stack, &top);
                if (ch == '(')
                    break;
                printf("%c", ch);
            }
        } else {
                printf("%c", input[i]);
        }
    }
    while (top > 0) {
        ch = pop(stack, &top);
        if (ch == '(')
            continue;
        printf("%c", ch);
    }
    printf("\n");
}

int main(void)
{
    int T;      // # of TCs
    char input[MAX];

    scanf("%d", &T);
    while (T--) {
        scanf("%s", input);
        RPN(input, strlen(input));
    }
    return 0;
}
