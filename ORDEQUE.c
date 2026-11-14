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
        printf("DEQUE is underflow\n");
    else
    {
        printf("Deleted value from queue front end: %d\n",DQ[front]);
        if(front==rear)
            front=rear=-1;
        else
            front=front+1;
    }
}


void EnqueueFront(int x)
{
    if(front<=0)
        printf("Not possible to insert an element\n");
    else
    {
        front=front-1;
        DQ[front]=x;
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
        printf("\n******OUTPUT RESTRICTED DEQUE******\n");
        printf("1.Insert an element at rear end\n");
        printf("2.Insert an element at front end\n");
        printf("3.Delete an element at front end\n");
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
            case 2: printf("Enter number to be inserted front end:");
                    scanf("%d",&x);
                    EnqueueFront(x);
                    break;
            case 3: DequeueFront();
                    break;
            case 4: display();
                    break;
            case 5: printf("Exiting from o/p restricted DQ\n");
                    exit(0);
                    break;
            default:printf("Entered invalid choice\n");
                    break;
        }
    }
}

