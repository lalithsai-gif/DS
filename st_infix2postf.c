#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>

#define MAX 60
int top=-1;
char s[MAX];

void push(char x);
char pop();
int priority(char x);

int main(){
    char infix[60],postfix[60],ch;
    int i=0,j=0;
    printf("Enter the infix Expression: ");
    scanf("%s",infix);
    while((ch=infix[i++])!='\0'){
        if(ch=='(')
            push(ch);
        else if(isalnum(ch))
            postfix[j++]=ch;
        else if(ch==')'){
            while(top!=-1 && s[top]!='(')
                postfix[j++]=pop();
            pop();
        }
        else{
            while(top!=-1 && priority(s[top])>=priority(ch))
                postfix[j++]=pop();
            push(ch);
        }
    }
    while(top!=-1){
        postfix[j++]=pop();
    }
    postfix[j]='\0';
    printf("The postfix of the given infix expression is: %s\n",postfix);
    return 0;
}

void push(char x)
{
    if(top==MAX-1){
        printf("Stack is Overflow\n");
    }
    else{
        top=top+1;
        s[top]=x;
    }
}
char pop()
{
    char ch;
    if(top==-1){
        printf("Stack is Empty\n");
        return '\0';
    }
    else{
        ch=s[top];
        top=top-1;
    }
    return ch;
}

int priority(char x)
{
    if(x=='(' || x==')') 
        return 0;
    if(x=='+' || x=='-')
        return 1;
    if(x=='/' || x=='*')
        return 2;
    return -1;
}
 

