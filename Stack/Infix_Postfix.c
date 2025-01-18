#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void push(char *, char); // for pushing elements in the stack
char pop(char *);        // for poping elements from the stack
int precedence(char);    // finding the precedence of the characters
int top = -1;

void main()
{
    char a[20], c[20], stack[20], t, k;
    int i;
    printf("Entering the infix expression : ");
    scanf("%s", &a);
    printf("\nThe postfix expression of corresponding %s infix expression : ", a);

    for (i = 0; a[i] != '\0'; i++) // checking each characters
    {
        t = a[i];
        if (t >= 40 && t <= 47 || t == '^' || t == '%') // checking for operator
        {
            if (t == '(') // if open parenthesis encounter
            {
                push(stack, t);
            }
            else if (t == ')') // if close parenthesis encounter
            {
                while ((k = pop(stack)) != '(') // poping elements until open parenthesis encounter
                {
                    printf("%c", k);
                }
            }
            else
            {
                if (top == -1) // if the stack is empty
                {
                    push(stack, t);
                }
                else
                {
                    while (precedence(t) < precedence(stack[top])) // checking the precedence
                    {
                        k = pop(stack);
                        printf("%c", k);
                        if (top == -1) // if the stack is empty
                            break;
                    }
                    push(stack, t);
                }
            }
        }

        else
            printf("%c", t);
    }
    while (top != -1) // poping operator until stack is empty
    {
        k = pop(stack);
        printf("%c", k);
    }
}

int precedence(char t) // finding the precedence of the characters
{
    if (t == '(')
        return (0);
    if (t == '-' || t == '+')
        return (1);
    if (t == '/' || t == '%' || t == '*')
        return (2);
    if (t == '^')
        return (3);
}

void push(char *stack, char ch)
{
    top++; // increasing the top pointer of the stack
    stack[top] = ch;
}

char pop(char *stack)
{
    char c;
    c = stack[top];
    top--; // decreasing the top pointer of the stack
    return (c);
}
