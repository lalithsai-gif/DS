#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
struct node
{
    int data;
    struct node *next;
}*temp,*p,*a[SIZE];

void initialize()
{
    for(int i=0;i<SIZE;i++)
        a[i]=NULL;
}

void insert(int value)
{
    int key;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=value;
    temp->next=NULL;
    key=value%SIZE;
    if(a[key]==NULL)
        a[key]=temp;
    else
    {
        p=a[key];
        while(p->next!=NULL)
            p=p->next;
        p->next=temp;
    }
}

void delete(int value)
{
    int key,found=0;
    key=value%SIZE;
    p=a[key];
    if(p!=NULL)
    {
        if(p->data==value)
        {
            temp=p;
            p=p->next;
            temp->next=NULL;
            free(temp);
            printf("Deleted value:%d\n",value);
            a[key]=p;
        }
        else
        {
            while(p->next!=NULL)
            {
                if(p->next->data==value)
                {
                    temp=p->next;
                    p->next=temp->next;
                    temp->next=NULL;
                    free(temp);
                    printf("Deleted value:%d\n",value);
                    found=1;
                    break;
                }
                p=p->next;
            }
            if(found==0)
                printf("Value %d is not available in hash table\n",value);
        }
    }
    else
        printf("Value %d is not available in hash table\n",value);
}

void search(int value)
{
    int key;
    key=value%SIZE;
    p=a[key];
    while(p!=NULL)
    {
        if(p->data==value)
        {
            printf("Value %d is found in index %d chain\n",value,key);
            return;
        }
        p=p->next;
    }
    printf("Value %d is not found in hash table\n",value);
}

void traversal()
{
    for(int i=0;i<SIZE;i++)
    {
        p=a[i];
        printf("Index %d : ",i);
        while(p!=NULL)
        {
            printf("%d -> ",p->data);
            p=p->next;
        }
        printf("NULL\n");
    }
}

void main()
{
    int choice,value;
    initialize();
    while(1)
    {
        printf("\n******MENU******\n");
        printf("1.Insertion\n");
        printf("2.Deletion\n");
        printf("3.Searching\n");
        printf("4.Display hash table\n");
        printf("5.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter value to be insert:");
                    scanf("%d",&value);
                    insert(value);
                    break;
            case 2: printf("Enter value to be deleted:");
                    scanf("%d",&value);
                    delete(value);
                    break;
            case 3: printf("Enter value to search:");
                    scanf("%d",&value);
                    search(value);
                    break;
            case 4: printf("******Hash table******\n");
                    traversal();
                    break;
            case 5: printf("Exit\n");
                    exit(0);
                    break;
            default:printf("Entered invalid choice\n");
                    break;
        }
    }
}
