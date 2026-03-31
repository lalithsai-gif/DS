#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int Q[MAX];
int front=-1;
int rear=-1;
void Enqueue(int );
void Dequeue();
void traversal();
int main(){
    while(1){
        int choice;
        printf("\n******MAIN MENU********\n");
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.traversal\n");
        printf("4.Exit\n");
        printf("Enter your choice(1-4):");
        scanf("%d",&choice);
        switch(choice){
            case 1: {int x;
                    printf("Enter the element ton be inserted:");
                    scanf("%d",&x);
                    Enqueue(x);
                    break;
                    }
            case 2:Dequeue();
                    break;
            case 3:traversal();
                    break;
            case 4:exit(0);
            default:printf("Entered Invalid Choice!");
                    break;
        }

    }
    return 0;
}

void Enqueue(int x)
{
    if(rear==MAX-1){
        printf("Queue is Overflow!");
    }
    else{
        rear=rear+1;
        Q[rear]=x;
        if(front==-1){
            front=0;
        }
    }
}

void Dequeue()
{
    if(front==-1){
        printf("Queue is Empty!");
    }
    else{
        printf("Deleting element is %d\n",Q[front]);
        if(front==rear){
            front=-1;
            rear=-1;
        }
        else
            front=front+1;
    }
} 

void traversal()
{
    if(front==-1)
        printf("Queue is Empty!");
    else{
        for(int i=front;i<=rear;i++){
            printf("%d ",Q[i]);
        }
    }
}