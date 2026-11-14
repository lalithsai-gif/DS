#include <stdio.h>
#include <string.h>
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
    if (top == -1)
        return -1;
    return stack[top--];
}

int precedence(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
    case '%':
        return 2;
    case '^':
        return 3;
    }
    return 0;
}

void reverse(char exp[])
{
    int i, j;
    char temp;
    for (i = 0, j = strlen(exp) - 1; i < j; i++, j--)
    {
        temp = exp[i];
        exp[i] = exp[j];
        exp[j] = temp;
    }
}

void infixToPrefix(char infix[], char prefix[])
{
    int i = 0, k = 0;
    char ch;

    reverse(infix);

    while ((ch = infix[i++]) != '\0')
    {
        if (isalnum(ch))
        {
            prefix[k++] = ch;
        }
        else if (ch == ')')
        {
            push(ch);
        }
        else if (ch == '(')
        {
            while (top != -1 && stack[top] != ')')
                prefix[k++] = pop();
            pop(); 
        }
        else
        {
            while (top != -1 && precedence(stack[top]) > precedence(ch))
                prefix[k++] = pop();
            push(ch);
        }
    }

    while (top != -1)
        prefix[k++] = pop();

    prefix[k] = '\0';
    reverse(prefix);
}

int main()
{
    char infix[MAX], prefix[MAX];

    printf("Enter infix expression: ");
    gets(infix);

    infixToPrefix(infix, prefix);
    printf("Prefix expression: %s\n", prefix);

    return 0;
}