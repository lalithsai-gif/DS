#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int front=-1,rear=-1,DQ[MAX];

void EnqueueRear(int x)
{
    if(rear==MAX-1)
        printf("DEQUE is overflow\n");
    else
    {
        rear=rear+1;
        DQ[rear]=x;
        if(front==-1)
            front=0;
    }
}


void DequeueFront()
{
    if(front==-1)
        printf("DEQUE is underflow i.e; empty\n");
    else
    {
        printf("Deleted value from queue front end: %d\n",DQ[front]);
        if(front==rear)
            front=rear=-1;
        else
            front=front+1;
    }
}



void DequeueRear()
{
    if(front==-1)
        printf("DEQUE is Empty\n");
    else
    {
        printf("Deleted value from queue rear end: %d\n",DQ[rear]);
        if(rear==front)
            front=rear=-1;
        else
            rear=rear-1;
    }

}

void display()
{
    if(front==-1)
        printf("DEQUE is Empty\n");
    else
    {
        for(int i=front;i<=rear;i++)
            printf("%d ",DQ[i]);
        printf("\n");
    }
}

void main()
{
    int choice,x;
    while(1)
    {
        printf("\n********INPUT RESTRICTED DEQUE*******\n");
        printf("1.Insert an element at rear end\n");
        printf("2.Delete an element at front end\n");
        printf("3.Delete an element at rear end\n");
        printf("4.Display DEQUE\n");
        printf("5.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter number to be inserted at rear end:");
                    scanf("%d",&x);
                    EnqueueRear(x);
                    break;
            case 2: DequeueFront();
                    break;
            case 3: DequeueRear();
                    break;
            case 4: display();
                    break;
            case 5: printf("Exiting from i/p restricted DQ\n");
                    exit(0);
                    break;
            default:printf("Entered invalid choice\n");
                    break;
        }
    }
}
