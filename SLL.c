#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*start=NULL,*temp,*p,*s1=NULL,*s2=NULL;
struct node *create_ll(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *insert_pos(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_pos(struct node *);
struct node *reverse(struct node *);
struct node *concate(struct node *);
struct node *search(struct node *);
struct node *sort(struct node *);
struct node *merge_sll(struct node *,struct node *);
void main()
{
    while(1)
    {
        int choice;
        printf("\n*****MAIN NENU*****\n");
        printf("1.Create single linked list\n");
        printf("2.Display single linked list\n");
        printf("3.Insert a node at beginning of SLL\n");
        printf("4.Insert a node at end of SLL\n");
        printf("5.Insert a node at specified position\n");
        printf("6.Delete a node at beginning of SLL\n");
        printf("7.Delete a node at end of SLL\n");
        printf("8.Delete a node at specified position\n");
        printf("9.Reverse a single linked list\n");
        printf("10.Concatenation of two SLL's\n");
        printf("11.Search the data in SLL\n");
        printf("12.Sort the single linked list\n");
        printf("13.Merging of two sorted Linked Lists\n");
        printf("14.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: start=create_ll(start);
                    break;
            case 2: start=display(start);
                    break;
            case 3: start=insert_beg(start);
                    printf("\nLinked list after inserting node at beginning\n");
                    display(start);
                    break;
            case 4: start=insert_end(start);
                    printf("\nLinked list after inserting node at end\n");
                    display(start);
                    break;
            case 5: start=insert_pos(start);
                    printf("\nLinked list after inserting node at given position\n");
                    display(start);
                    break;
            case 6: start=delete_beg(start);
                    printf("\nLinked list after deleting node at beginning\n");
                    display(start);
                    break;
            case 7: start=delete_end(start);
                    printf("\nLinked list after deleting node at end\n");
                    display(start);
                    break;
            case 8: start=delete_pos(start);
                    printf("\nLinked list after deleting node at given position\n");
                    display(start);
                    break;
            case 9: start=reverse(start);
                    printf("\nReversed linked list\n");
                    display(start);
                    break;
            case 10:start=concate(start);
                    break;
            case 11:search(start);
                    break;
            case 12:start=sort(start);
                    printf("\nSorted linked list\n");
                    display(start);
                    break;
            case 13:display( merge_sll(sort(s1=create_ll(s1)),sort(s2=create_ll(s2))));
                    break;
            case 14:exit(0);
            default:
                    printf("Enter valid choice(1-13)\n");
                    break;
        }
    }
}
struct node *create_ll(struct node *start)
{
    int x,n,i;
    printf("Enter no.of nodes u want create in SLL:");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("Enter the data:");
        scanf("%d",&x);
        temp=(struct node*)malloc(sizeof(struct node));
        temp->data=x;
        temp->next=NULL;
        if(start==NULL)
        {
            start=temp;
            p=temp;
        }
        else
        {
            p->next=temp;
            p=temp;
        }
    }
    return start;
}

struct node *display(struct node *start)
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
struct node *insert_beg(struct node *start)
{
    temp=(struct node*)malloc(sizeof(struct node));
    int x;
    printf("\nEnter the data:");
    scanf("%d",&x);
    temp->data=x;
    temp->next=NULL;
    if(start==NULL)
        start=temp;
    else
    {
        temp->next=start;
        start=temp;
    }
    return start;
}
struct node *insert_end(struct node *start)
{
    temp=(struct node*)malloc(sizeof(struct node));
    int x;
    printf("\nEnter the data:");
    scanf("%d",&x);
    temp->data=x;
    temp->next=NULL;
    if(start==NULL)
        start=temp;
    else
    {
        p=start;
        while(p->next!=NULL)
            p=p->next;
        p->next=temp;
    }
    return start;
}
struct node *insert_pos(struct node *start)
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
        insert_beg(start);
    else if(pos==count+1)
        insert_end(start);
    else if(pos>1 && pos<=count)
    {
        temp=(struct node*)malloc(sizeof(struct node));
        int x;
        printf("\nEnter data to store:");
        scanf("%d",&x);
        temp->data=x;
        temp->next=NULL;
        p=start;
        for(int k=1;k<pos-1;k++)
        {
            p=p->next;
        }
        temp->next=p->next;
        p->next=temp;
    }
    else
        printf("Entered invalid position\n");
    return start;
}
struct node *delete_beg(struct node *start)
{
    if(start==NULL)
        printf("Linked list is empty\n");
    else
    {
        temp=start;
        start=start->next;
        temp->next=NULL;
        free(temp);
    }
    return start;
}
struct node *delete_end(struct node *start)
{
    if(start==NULL)
        printf("Linked list is empty\n");
    else if(start->next==NULL)
    {
        temp=start;
        start=NULL;
        free(temp);
    }
    else
    {
        p=start;
        while(p->next->next!=NULL)
        {
            p=p->next;
        }
        temp=p->next;
        p->next=NULL;
        free(temp);
    }
    return start;
}
struct node *delete_pos(struct node *start)
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
            delete_beg(start);
        else if(pos==count)
            delete_end(start);
        else if(pos>1 && pos<count)
        {
            p=start;
            for(int k=1;k<pos-1;k++)
            {
                p=p->next;
            }
            temp=p->next;
            p->next=temp->next;
            temp->next=NULL;
            free(temp);
        }
        else
            printf("Entered invalid position\n");
    }
    return start;
}
struct node *reverse(struct node *start)
{
    struct node *p1,*p2,*p3;
    if(start==NULL)
        printf("Linked list is empty\n");
    else if(start->next==NULL)
        printf("Linked list consist of single node\n");
    else
    {
        p1=start;
        p2=p1->next;
        p3=p2->next;
        p1->next=NULL;
        p2->next=p1;
        while(p3!=NULL)
        {
            p1=p2;
            p2=p3;
            p3=p2->next;
            p2->next=p1;
        }
        start=p2;
    }
    return start;
}
struct node *concate(struct node *start)
{
    struct node *start1=NULL,*start2=NULL;
    start1=create_ll(start1);
    start2=create_ll(start2);
    p=start1;
    while(p->next!=NULL)
        p=p->next;
    p->next=start2;
    printf("\nConcatenation of 2 SLL's:\n");
    display(start1);
    return start;
}
struct node *search(struct node *start)
{
    if(start==NULL)
        printf("Display Linked List is empty\n");
    else
    {
        int x,flag=0;
        printf("\nEnter an element to search in SLL:");
        scanf("%d",&x);
        p=start;
        while(p!=NULL)
        {
            if(p->data==x)
            {
                flag=1;
                break;
            }
            else
                p=p->next;
        }
        if(flag==1)
            printf("Element %d is found in SLL\n",x);
        else
            printf("Element %d is not found in SLL\n",x);
    }
}
struct node *sort(struct node *start)
{
    if(start==NULL)
        printf("Linked list is empty\n");
    else if(start->next==NULL)
        printf("Linked list consist of single node\n");
    else
    {
        struct node *p1,*p2;
        int x;
        for(p1=start;p1!=NULL;p1=p1->next)
        {
            for(p2=p1->next;p2!=NULL;p2=p2->next)
            {
                if(p1->data>p2->data)
                {
                    x=p1->data;
                    p1->data=p2->data;
                    p2->data=x;
                }
            }
        }
    }
    return start;
}

struct node *merge_sll(struct node* start1, struct node* start2)
{
    if(start1==NULL) return start2;
    if(start2==NULL) return start1;

    if(start1->data < start2->data)
    {
        start1->next = merge_sll(start1->next, start2);
        return start1;
    }
    else
    {
        start2->next = merge_sll(start1, start2->next);
        return start2;
    }
}
