#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
int a[SIZE];

void initialize()
{
    for(int i=0;i<SIZE;i++)
        a[i]=-1;
}

void insertQP(int value)
{
    int i,hkey;
    hkey=value%SIZE;
    for(i=0;i<SIZE;i++)
    {
        if(a[(hkey+i*i)%SIZE]==-1)
        {
            a[(hkey+i*i)%SIZE]=value;
            break;
        }
    }
    if(i==SIZE)
        printf("Not possible to insert.\n");
}

void deleteQP(int value)
{
    int i,hkey,index;
    hkey=value%SIZE;
    for(i=0;i<SIZE;i++)
    {
        index=(hkey+i*i)%SIZE;
        if(a[index]==value)
        {
            a[index]=-1;
            printf("Value %d deleted succesfully\n",value);
            return;
        }
    }
    printf("Value %d is not found in hash table\n",value);
}

void searchQP(int value)
{
    int i,hkey,index;
    hkey=value%SIZE;
    for(i=0;i<SIZE;i++)
    {
        index=(hkey+i*i)%SIZE;
        if(a[index]==value)
        {
            printf("Value %d found at index %d\n",value,index);
            return;
        }
    }
    printf("Value %d is not found in hash table\n",value);
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
        printf("\n*****MENU*****\n");
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
                    insertQP(value);
                    break;
            case 2: printf("Enter value to be deleted:");
                    scanf("%d",&value);
                    deleteQP(value);
                    break;
            case 3: printf("Enter value to search:");
                    scanf("%d",&value);
                    searchQP(value);
                    break;
            case 4: printf("*****Hash table*****\n");
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

