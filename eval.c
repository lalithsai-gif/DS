#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX 50

int stack[MAX];
int top = -1;

void push(int x)
{
    if(top < MAX-1)
        stack[++top] = x;
}

int pop()
{
    if(top >= 0)
        return stack[top--];
    return 0;
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
        case '^': return (int)pow(a, b);
    }
    return 0;
}

void reverse(char str[])
{
    int i, j;
    char temp;
    for(i=0, j=strlen(str)-1; i<j; i++, j--)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

int evaluatePrefix(char prefix[])
{
    int i = 0;
    char ch;
    int op1, op2;

    reverse(prefix);   

    while((ch = prefix[i++]) != '\0')
    {
        if(ch >= '0' && ch <= '9')
        {
            push(ch - '0');
        }
        else
        {
            op1 = pop();
            op2 = pop();
            push(applyOperator(ch, op1, op2));
        }
    }

    return pop();
}

int main()
{
    char prefix[MAX];

    printf("Enter prefix expression: ");
    scanf("%s", prefix);

    printf("Result = %d\n", evaluatePrefix(prefix));
    return 0;
}
