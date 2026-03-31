#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int s[MAX],top=-1;

void push(int );
void pop();
void peek();
void display();

int main(){
    int choice,x;
    while(1){
        printf("\n*****MAIN MENU******\n");
        printf("1.Push\n");
        printf("2.pop\n");
        printf("3.peek\n");
        printf("4.display\n");
        printf("5.Exit\n");
        printf("ENter your choice(1-5):");
        scanf("%d",&choice);

        switch(choice){
            case 1:printf("ENter number to be pushed:");
                   scanf("%d",&x);
                   push(x);
                   break;
            case 2:pop();
                    break;
            case 3:peek();
                    break;
            case 4:display();
                    break;
            case 5:exit(0);
                    break;
            default:printf("Invalid choice!");
                    break;
        }
    }
}
void push(int x){
    if(top==MAX-1)
        printf("Stack is Overflow\n");
    else{
        top=top+1;
        s[top]=x;
    }
}

void pop(){
    if(top==-1)
        printf("Stack is Empty!");
    else{
        printf("Deleting Element:%d\n",s[top]);
        top=top-1;
    }
}
void peek(){
    if(top==-1){
        printf("Stack is empty!");
    }
    else{
        printf("The top element is : %d\n",s[top]);
    }
}

void display(){
    if(top==-1){
        printf("Stack is Empty\n");
    }
    else{
        for(int i=top;i>=0;i--){
            printf("%d ",s[i]);
        }
        printf("\n");
    }
}