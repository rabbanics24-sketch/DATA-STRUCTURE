#include <stdio.h>
#include <ctype.h>

#define MAX 50

char stack[MAX];
int top = -1;

/* Push into stack */
void push(char ch) {
    stack[++top] = ch;
}

/* Pop from stack */
char pop() {
    return stack[top--];
}

/* Operator precedence */
int precedence(char ch) {
    if (ch == '+' || ch == '-')
        return 1;
    if (ch == '*' || ch == '/')
        return 2;
    return 0;
}

int main() {
    char infix[MAX], postfix[MAX];
    int i, j = 0;
    char ch;

    printf("Enter a valid parenthesized infix expression: ");
    scanf("%s", infix);

    for (i = 0; infix[i] != '\0'; i++) {
        ch = infix[i];

        /* If operand, add to postfix */
        if (isalnum(ch)) {
            postfix[j++] = ch;
        }
        /* If '(', push to stack */
        else if (ch == '(') {
            push(ch);
        }
        /* If ')', pop until '(' */
        else if (ch == ')') {
            while (stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop(); // remove '('
        }
        /* If operator */
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(ch)) {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    postfix[j] = '\0';

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
