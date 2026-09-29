#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch)
{
    stack[++top] = ch;
}

char pop()
{
    return stack[top--];
}

int precedence(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/')
        return 2;
    else
        return 0;
}

int main()
{
    char infix[MAX], postfix[MAX];
    int i, j = 0;
    char ch;
    int invalid = 0;

    printf("Enter a valid infix expression: ");
    scanf("%s", infix);

    for (i = 0; infix[i] != '\0'; i++)
    {
        ch = infix[i];

        if (isalnum(ch))
        {
            postfix[j++] = ch;
        }
        else if (ch == '(')
        {
            push(ch);
        }
        else if (ch == ')')
        {
            while (top != -1 && stack[top] != '(')
            {
                postfix[j++] = pop();
            }

            if (top == -1)
            {
                invalid = 1;
                break;
            }

            pop();
        }
        else
        {
            while (top != -1 &&
                   stack[top] != '(' &&
                   precedence(stack[top]) >= precedence(ch))
            {
                postfix[j++] = pop();
            }

            push(ch);
        }
    }

    if (!invalid)
    {
        while (top != -1)
        {
            if (stack[top] == '(')
            {
                invalid = 1;
                break;
            }

            postfix[j++] = pop();
        }
    }

    if (invalid)
    {
        printf("Invalid expression\n");
    }
    else
    {
        postfix[j] = '\0';
        printf("Postfix expression: %s\n", postfix);
    }

    return 0;
}