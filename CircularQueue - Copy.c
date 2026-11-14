#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int front=-1,rear=-1,CQ[MAX];

void enqueue(int x)
{
    if((rear+1)%MAX==front)
        printf("Circular Queue is overflow\n");
    else
    {
        rear=(rear+1)%MAX;
        CQ[rear]=x;
        if(front==-1){
            front=0;
        }
    }
}

void dequeue()
{
    if(front==-1)
        printf("Circular Queue is empty\n");
    else
    {
        printf("Deleted value from circular queue : %d\n",CQ[front]);
        if(front==rear)
            front=rear=-1;
        else
            front=(front+1)%MAX;
    }
}

void display()
{
    if(front==-1)
        printf("Queue is empty\n");
    else if(front<=rear)
    {
        for(int i=front;i<=rear;i++)
            printf("%d ",CQ[i]);
        printf("\n");
    }
    else
    {
        for(int i=front;i<MAX;i++)
            printf("%d ",CQ[i]);
        for(int i=0;i<=rear;i++)
            printf("%d ",CQ[i]);
        printf("\n");
    }
}

void main()
{
    int choice,x;
    while(1)
    {
        printf("\n*******MAIN MENU******\n");
        printf("1.Insert an element\n");
        printf("2.Delete an element\n");
        printf("3.Display circular queue\n");
        printf("4.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter number to be inserted:");
                    scanf("%d",&x);
                    enqueue(x);
                    break;
            case 2: dequeue();
                    break;
            case 3: display();
                    break;
            case 4: printf("Exiting\n");
                    exit(0);
                    break;
            default:printf("Entered invalid choice\n");
                    break;
        }
    }
}