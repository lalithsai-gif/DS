#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*top=NULL,*temp,*p;

struct node *push(struct node *top);
struct node *pop(struct node *top);
void peek(struct node *top);
struct node *display(struct node *top);

int main(){
    int choice;
    while(1)
    {
        printf("\n******MAIN MENU******\n");
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.peek\n");
        printf("4.display\n");
        printf("5.Exit\n");

        printf("Enter your choice (1-5):");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:top=push(top);
                    break;
            case 2:top=pop(top);
                    break;
            case 3:peek(top);
                    break;
            case 4:top=display(top);
                    break;
            case 5:exit(0);
                    break;
            default:printf("Entered Invalid Choice\n");
                    break;
        }
    }
}

struct node *push(struct node *top)
{
    int n;
    printf("ENter no. of nodes you want to  stack:");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        temp=(struct node*)malloc(sizeof(struct node));
        int x;
        printf("Enter data to push into the stack:");
        scanf("%d",&x);
        temp->data=x;
        temp->next=NULL;
        if(top==NULL){
            top=temp;
        }
        else{
            temp->next=top;
            top=temp;
        }
    }
    return top; 
}

struct node *pop(struct node *top)
{
    if(top==NULL){
        printf("Stack is Empty\n");
    }
    else if(top->next==NULL){
        temp=top;
        top=temp->next;
        free(temp);
    }
    else{
        temp=top;
        top=temp->next;
        free(temp);
    }
    return top;
}

void peek(struct node *top)
{
    if(top==NULL){
        printf("Stack is Empty\n");
    }
    else{
        printf("the top element is : %d\n",top->data);
        }
}

struct node *display(struct node *top)
{
    if(top==NULL){
        printf("Stack LL is Empty\n");
    }
    else{
        p=top;
        while(p!=NULL){
            printf("%d",p->data);
            if(p->next!=NULL){
                printf("->");
            }
            p=p->next;
        }
    }
    return top;
}