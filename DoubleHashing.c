#include<stdio.h>
#include<stdlib.h>
#define PRIME 7
#define SIZE 11
int a[SIZE];

void initialize()
{
    for(int i=0;i<SIZE;i++)
        a[i]=-1;
}

void insertDH(int value)
{
    int i,hkey1,hkey2;
    hkey1=value%SIZE;
    hkey2=PRIME-value%PRIME;
    for(i=0;i<SIZE;i++)
    {
        if(a[(hkey1+i*hkey2)%SIZE]==-1)
        {
            a[(hkey1+i*hkey2)%SIZE]=value;
            break;
        }
    }
    if(i==SIZE)
        printf("Not possible to insert.\n");
}

void deleteDH(int value)
{
    int i,hkey1,hkey2,index;
    hkey1=value%SIZE;
    hkey2=PRIME-value%PRIME;
    for(i=0;i<SIZE;i++)
    {
        index=(hkey1+i*hkey2)%SIZE;
        if(a[index]==value)
        {
            a[index]=-1;
            printf("Value %d deleted succesfully\n",value);
            return;
        }
    }
    printf("Value %d is not found in hash table\n",value);
}

void searchDH(int value)
{
    int i,hkey1,hkey2,index;
    hkey1=value%SIZE;
    hkey2=PRIME-value%PRIME;
    for(i=0;i<SIZE;i++)
    {
        index=(hkey1+i*hkey2)%SIZE;
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
                    insertDH(value);
                    break;
            case 2: printf("Enter value to be deleted:");
                    scanf("%d",&value);
                    deleteDH(value);
                    break;
            case 3: printf("Enter value to search:");
                    scanf("%d",&value);
                    searchDH(value);
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