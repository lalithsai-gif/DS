#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
int a[SIZE];

void initialize()
{
    for(int i=0;i<SIZE;i++)
        a[i]=-1;
}

void insertLP(int value)
{
    int i,hkey;
    hkey=value%SIZE;
    for(i=0;i<SIZE;i++)
    {
        if(a[(hkey+i)%SIZE]==-1)
        {
            a[(hkey+i)%SIZE]=value;
            break;
        }
    }
    if(i==SIZE)
        printf("Not possible to insert\n");
}

void deleteLP(int value)
{
    int i,hkey;
    hkey=value%SIZE;
    for(i=0;i<SIZE;i++)
    {
        if(a[(hkey+i)%SIZE]==value)
        {
            a[(hkey+i)%SIZE]=-1;
            printf("Value %d deleted succesfully\n",value);
            break;
        }
    }
    if(i==SIZE)
        printf("Value %d is not found in hash table\n",value);
}

void search(int value)
{
    for(int i=0;i<SIZE;i++)
    {
        if(a[i]==value)
        {
            printf("Searching is successful\n");
            printf("Value %d is found at index %d\n",value,i);
            return;
        }
    }
    printf("Value %d not found.\n",value);
}

void traversal()
{
    for(int i=0;i<SIZE;i++)
    {
        if(a[i]==-1)
            printf("Index %d : Empty\n",i);
        else
            printf("Index %d : %d\n",i,a[i]);
    }
}

void main()
{
    int choice,value;
    initialize();
    while(1)
    {
        printf("\n******MENU*****\n");
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
                    insertLP(value);
                    break;
            case 2: printf("Enter value to be deleted:");
                    scanf("%d",&value);
                    deleteLP(value);
                    break;
            case 3: printf("Enter value to search:");
                    scanf("%d",&value);
                    search(value);
                    break;
            case 4: printf("******Hash table*****\n");
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

