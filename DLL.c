#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
}*start=NULL,*temp,*p,*end;
struct node *create_dll(struct node *);
struct node *display_forward(struct node *);
struct node *display_backward(struct node *);
struct node *insert_begDLL(struct node *);
struct node *insert_endDLL(struct node *);
struct node *insert_posDLL(struct node *);
struct node *delete_begDLL(struct node *);
struct node *delete_endDLL(struct node *);
struct node *delete_posDLL(struct node *);
struct node *reverse_dll(struct node *);
void main()
{
    while(1)
    {
        int choice;
        printf("\n*****MAIN NENU*****\n");
        printf("1.Create double linked list\n");
        printf("2.Display double linked list\n");
        printf("3.Insert a node at beginning of DLL\n");
        printf("4.Insert a node at end of DLL\n");
        printf("5.Insert a node at specified position\n");
        printf("6.Delete a node at beginning of DLL\n");
        printf("7.Delete a node at end of DLL\n");
        printf("8.Delete a node at specified position\n");
        printf("9.Reverse a double linked list\n");
        printf("10.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: start=create_dll(start);
                    break;
            case 2: printf("\nDisplaying DLL in forward direction\n");
                    start=display_forward(start);
                    printf("\nDisplaying DLL in backward direction\n");
                    display_backward(start);
                    break;
            case 3: start=insert_begDLL(start);
                    printf("\nLinked list after inserting node at beginning\n");
                    display_forward(start);
                    break;
            case 4: start=insert_endDLL(start);
                    printf("\nLinked list after inserting node at end\n");
                    display_forward(start);
                    break;
            case 5: start=insert_posDLL(start);
                    printf("\nLinked list after inserting node at given position\n");
                    display_forward(start);
                    break;
            case 6: start=delete_begDLL(start);
                    printf("\nLinked list after deleting node at beginning\n");
                    display_forward(start);
                    break;
            case 7: start=delete_endDLL(start);
                    printf("\nLinked list after deleting node at end\n");
                    display_forward(start);
                    break;
            case 8: start=delete_posDLL(start);
                    printf("\nLinked list after deleting node at given position\n");
                    display_forward(start);
                    break;
            case 9: start=reverse_dll(start);
                    printf("\nReversed linked list\n");
                    display_forward(start);
                    break;
            case 10:exit(0);
                    break;
            default:
                    printf("Enter valid choice(1-13)\n");
                    break;
        }
    }
}
struct node *create_dll(struct node *start)
{
    int x,n,i;
    printf("Enter no.of nodes u want create in DLL:");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        temp=(struct node*)malloc(sizeof(struct node));
        printf("Enter data to store:");
        scanf("%d",&x);
        temp->prev=NULL;
        temp->data=x;
        temp->next=NULL;
        if(start==NULL)
        {
            start=temp;
            end=temp;
        }
        else
        {
            end->next=temp;
            temp->prev=end;
            end=temp;
        }
    }
    return start;
}
struct node *display_forward(struct node *start)
{
    if(start==NULL)
        printf("Linked list is empty\n");
    else
    {
        p=start;
        while(p!=NULL)
        {
            printf("%d",p->data);
            if(p->next!=NULL)
                printf(" -> ");
            p=p->next;
        }
    }
    return start;
}
struct node *display_backward(struct node *start)
{
    if(start==NULL)
        printf("Linked list is empty\n");
    else
    {
        p=end;
        while(p!=NULL)
        {
            printf("%d",p->data);
            if(p->prev!=NULL)
                printf(" -> ");
            p=p->prev;
        }
    }
    return start;
}
struct node *insert_begDLL(struct node *start)
{
    int x;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter data to store:");
    scanf("%d",&x);
    temp->prev=NULL;
    temp->data=x;
    temp->next=NULL;
    if(start==NULL)
        start=temp;
    else
        temp->next=start;
        start->prev=temp;
        start=temp;
    return start;
}
struct node *insert_endDLL(struct node *start)
{
    int x;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter data to store:");
    scanf("%d",&x);
    temp->prev=NULL;
    temp->data=x;
    temp->next=NULL;
    if(start==NULL)
        start=temp;
    else
        end->next=temp;
        temp->prev=end;
        end=temp;
    return start;
}
struct node *insert_posDLL(struct node *start)
{
    int pos;
    printf("\nEnter position of node to be inserted:");
    scanf("%d",&pos);
    int count=0;
    p=start;
    while(p!=NULL)
    {
        count=count+1;
        p=p->next;
    }
    if(pos==1)
        start=insert_begDLL(start);
    else if(pos==count+1)
        start=insert_endDLL(start);
    else if(pos>1 && pos<=count)
    {
        temp=(struct node*)malloc(sizeof(struct node));
        int x;
        printf("\nEnter data to store:");
        scanf("%d",&x);
        temp->data=x;
        temp->prev=NULL;
        temp->next=NULL;
        p=start;
        for(int k=1;k<pos-1;k++)
        {
            p=p->next;
        }
        temp->next=p->next;
        p->next->prev=temp;
        p->next=temp;
        temp->prev=p;
    }
    else
        printf("Entered invalid position\n");
    return start;
}
struct node *delete_begDLL(struct node *start)
{
    if(start==NULL)
        printf("Linked list is empty\n");
    else if(start->next==NULL)
    {
        temp=start;
        start=NULL;
        end=NULL;
        free(temp);
    }
    else
    {
        temp=start;
        start=start->next;
        start->prev=NULL;
        temp->next=NULL;
        free(temp);
    }
    return start;
}
struct node *delete_endDLL(struct node *start)
{
    if(start==NULL)
        printf("Linked list is empty\n");
    else if(start->next==NULL)
    {
        temp=start;
        start=NULL;
        end=NULL;
        free(temp);
    }
    else
    {
        temp=end;
        end=end->prev;
        end->next=temp->prev=NULL;
        free(temp);
    }
    return start;
}
struct node *delete_posDLL(struct node *start)
{
    if(start==NULL)
        printf("Linked list is empty\n");
    else
    {
        int pos;
        printf("\nEnter position of node to be deleted:");
        scanf("%d",&pos);
        int count=0;
        p=start;
        while(p!=NULL)
        {
            count=count+1;
            p=p->next;
        }
        if(pos==1)
            start=delete_begDLL(start);
        else if(pos==count)
            start=delete_endDLL(start);
        else if(pos>1 && pos<count)
        {
            p=start;
            for(int k=1;k<pos-1;k++)
            {
                p=p->next;
            }
            temp=p->next;
            p->next=temp->next;
            temp->next->prev=p;
            temp->next=temp->prev=NULL;
            free(temp);
        }
        else
            printf("Entered invalid position\n");
    }
    return start;
}
struct node *reverse_dll(struct node *p)
{
    if(p==NULL)
        return NULL;
    temp=p->prev;
    p->prev=p->next;
    p->next=temp;
    if(p->prev==NULL)
        return p;
    return reverse_dll(p->prev);
}

