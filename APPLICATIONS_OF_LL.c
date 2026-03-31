#include<stdio.h>
#include<stdlib.h>
struct node
{
    int coef;
    int exp;
    struct node *next;
}*start=NULL,*temp,*p,*p1,*p2,*p3;
struct node *polynom_creation(struct node *);
struct node *polynom_display(struct node *);
struct node *polynom_add(struct node *,struct node *);

void main()
{
    while(1)
    {
        int choice;
        printf("\n*****MAIN NENU*****\n");
        printf("1.Create polynomial\n");
        printf("2.Display polynomial\n");
        printf("3.Adding two polynomials\n");
        printf("4.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: start=polynom_creation(start);
                    break;
            case 2: start=polynom_display(start);
                    break;
            case 3: p1=polynom_creation(p1);
                    printf("\nFirst Polynomial:");
                    polynom_display(p1);
                    p2=polynom_creation(p2);
                    printf("\nSecond Polynomial:");
                    polynom_display(p2);
                    p3=polynom_add(p1,p2);
                    printf("\nResult polynomial\n");
                    polynom_display(p3);
                    break;
            case 4: exit(0);
                    break;
            default: printf("Entered invalid choice\n");
                    break;
        }
    }
}
struct node *polynom_creation(struct node *start)
{
    int n,i,co,ex;
    printf("\nEnter no.of terms in polynomial:");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        temp=(struct node*)malloc(sizeof(struct node));
        printf("Enter coefficient & it's exponent:");
        scanf("%d %d",&co,&ex);
        temp->coef=co;
        temp->exp=ex;
        temp->next=NULL;
        if(start==NULL || ex>(start->exp)) 
        {
            temp->next=start;
            start=temp;
        }
        else
        {
            p=start;
            while(p->next!=NULL && (p->next->exp)>ex)
                p=p->next;
            temp->next=p->next;
            p->next=temp;
        }
    }
    return start;
}
struct node *polynom_display(struct node *start)
{
    if(start==NULL)
        printf("Polynomial has no terms\n");
    else
    {
        p=start;
        while(p!=NULL)
        {
            if(p->exp == 0)
                printf("%d",p->coef);
            else if(p->exp == 1)
                printf("%dx",p->coef);
            else
                printf("%dx^%d",p->coef,p->exp);
            if(p->next!=NULL)
                printf(" + ");
            p=p->next;
        }
    }
    return start;
}
struct node *polynom_add(struct node *p1,struct node *p2)
{   struct node *start3=NULL;

    while(p1!=NULL && p2!=NULL)
    {
    temp=(struct node *)malloc(sizeof(struct node));
    temp->next=NULL;
        if((p1->exp)>(p2->exp))
        {
            temp->coef=p1->coef;
            temp->exp=p1->exp;
            p1=p1->next;
        }
        else if((p1->exp)<(p2->exp))
        {
            temp->coef=p2->coef;
            temp->exp=p2->exp;
            p2=p2->next;
        }
        else if((p1->exp)==(p2->exp))
        {
            temp->coef=p1->coef+p2->coef;
            temp->exp=p1->exp;
            p1=p1->next;
            p2=p2->next;
        }
        if(start3==NULL){
            start3=temp;
            p3=temp;
        }
        else{
            p3->next=temp;
            p3=temp;
        }
    }
    while(p1!=NULL)
    {
        temp=(struct node*)malloc(sizeof(struct node));
        temp->coef=p1->coef;
        temp->exp=p1->exp;
        temp->next=NULL;
        if(start3==NULL){
            start3=temp;
            p3=temp;
        }
        else{
            p3->next=temp;
            p3=temp;
        }
            p1=p1->next;
    }
    while(p2!=NULL)
    {
        temp=(struct node*)malloc(sizeof(struct node));
        temp->coef=p2->coef;
        temp->exp=p2->exp;
        temp->next=NULL;
        if(start3==NULL){
            start3=temp;
            p3=temp;
        }
        else{
            p3->next=temp;
            p3=temp;
        }
            p2=p2->next;
    }
    return start3;
}
