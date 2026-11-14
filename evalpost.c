#include <stdio.h>
#include <math.h>

#define MAX 50

int stack[MAX];
int top = -1;

void push(int x)
{
    stack[++top] = x;
}

int pop()
{
    return stack[top--];
}

int applyOperator(char op, int a, int b)
{
    switch (op)
    {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/': return a / b;
    case '%': return a % b;
    case '^': return pow(a, b);
    }
    return 0;
}

int evaluatePostfix(char postfix[])
{
    int i = 0;
    char ch;
    int op1, op2, result;

    while ((ch = postfix[i++]) != '\0')
    {
        if (ch >= '0' && ch <= '9')
        {
            push(ch - '0');
        }
        else
        {
            op2 = pop();   
            op1 = pop();   
            result = applyOperator(ch, op1, op2);
            push(result);
        }
    }
    return pop();
}

int main()
{
    char postfix[MAX];
    int result;

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    result = evaluatePostfix(postfix);

    printf("Result of postfix evaluation: %d\n", result);

    return 0;
}