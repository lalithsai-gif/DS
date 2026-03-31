#include <stdio.h>
#include <stdlib.h>
struct node *Creation_scll(struct node *start);
struct node *Display_scll(struct node *start);
struct node *Traversal_scll(struct node *start);
struct node *Inserbeg_scll(struct node *start);
struct node *Inserend_scll(struct node *start);
struct node *Inserany_scll(struct node *start);
struct node *Deletebeg_scll(struct node *start);
struct node *Deletend_scll(struct node *start);
struct node *Deleteany_scll(struct node *start);
struct node *Reverse_scll(struct node *start);
struct node 
{
    int data;
    struct node *next;
} *start = NULL, *p, *temp, *p1, *p2, *p3;
int main()
{
    while (1)
    {
        printf("**************MENU***************\n");
        printf("(1) Creation of SCLL \n");
        printf("(2) Traversal from begining of SCLL \n");
        printf("(3) Insertion a new node at Begining of SCLL \n");
        printf("(4) Insertion a new node at ending  of SCLL \n");
        printf("(5) Insertion  of new node at specified position of SCLL \n");
        printf("(6) Deleting a node at begining of SCLL \n");
        printf("(7) Deleting a node at ending  of SCLL \n");
        printf("(8) Deleting a node at any specified position of SCLL \n");
        printf("(9) Reverse  of SCLL \n");
        printf("(10) Tap to EXIT \n");
        int choice;
        printf("choose the number from above list:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            start = Creation_scll(start);
            break;
        case 2:
            Traversal_scll(start);
            break;
        case 3:
            start = Inserbeg_scll(start);
            Display_scll(start);
            break;
        case 4:
            start = Inserend_scll(start);
            Display_scll(start);
            break;
        case 5:
            start = Inserany_scll(start);
            Display_scll(start);
            break;
        case 6:
            start = Deletebeg_scll(start);
            Display_scll(start);
            break;
        case 7:
            start = Deletend_scll(start);
            Display_scll(start);
            break;
        case 8:
            start = Deleteany_scll(start);
            Display_scll(start);
            break;
        case 9:
            start = Reverse_scll(start);
            Display_scll(start);
            break;
        case 10:
            exit(0);
            break;
        }
    }
}
struct node *Creation_scll(struct node *start)
{
    int n, i;
    printf("enter number of values:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        printf("enter number:");
        scanf("%d", &temp->data);
        temp->next = NULL;
        if (start == NULL)
        {
            start = temp;
            p = temp;
            start->next = start;
        }
        else
        {
            p->next = temp;
            temp->next = start;
            p = temp;
        }
    }
    return start;
}
struct node *Display_scll(struct node *start)
{
    p = start;
    while (p->next != start)
    {
        printf("%d->", p->data);
        p = p->next;
    }
    printf("%d\n", p->data);
    return start;
}
struct node *Traversal_scll(struct node *start)
{
    if (start == NULL)
    {
        printf("SCLL is empty");
    }
    else
    {
        p = start;
        while (p->next != start)
        {
            printf("%d->", p->data);
            p = p->next;
        }
        printf("%d\n", p->data);
    }
    return start;
}
struct node *Inserbeg_scll(struct node *start)
{
    temp = (struct node *)malloc(sizeof(struct node));
    int val;
    printf("enter number to insert:");
    scanf("%d", &val);
    temp->data = val;
    temp->next = NULL;

    if (start == NULL)
    {
        temp->next = temp;
        start = temp;
    }
    else
    {
        p = start;
        while (p->next != start)
        {
            p = p->next;
        }
        p->next = temp;
        temp->next = start;
        start = temp;
    }
    return start;
}
struct node *Inserend_scll(struct node *start)
{
    int val;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("etner value to be inserted:");
    scanf("%d", &val);
    temp->data = val;
    temp->next = NULL;
    if (start == NULL)
    {
        temp->next = temp;
        start = temp;
    }
    else
    {
        p = start;
        while (p->next != start)
        {
            p = p->next;
        }
        p->next = temp;
        temp->next = start;
    }
    return start;
}
struct node *Inserany_scll(struct node *start)
{
    int pos;
    printf("enter position you want to be inserted");
    scanf("%d", &pos);
    p = start;
    int c = 0;
    while (p->next != start)
    {
        c = c + 1;
        p = p->next;
    }
    printf("%d", c);
    if (start == NULL)
    {
        temp->next = temp;
        start = temp;
    }
    else if (pos == 1)
    {
        start = Inserbeg_scll(start);
    }
    else if (pos == c + 1)
    {
        start = Inserend_scll(start);
    }
    else if (pos > 1 && pos <= c)
    {
        int val, i;
        temp = (struct node *)malloc(sizeof(struct node));
        printf("Enter value to be inserted:");
        scanf("%d", &val);
        temp->data = val;
        temp->next = NULL;
        p = start;
        for (i = 1; i < pos - 1; i++)
        {
            p = p->next;
        }
        temp->next = p->next;
        p->next = temp;
        return start;
    }
    else
    {
        printf("Entered invalid position");
    }
}
struct node *Deletebeg_scll(struct node *start)
{
    temp = (struct node *)malloc(sizeof(struct node));
    if (start == NULL)
    {
        printf("Given scll is empty:");
    }
    else if (start->next == start)
    {
        temp = start;
        temp->next = NULL;
        free(temp);
    }
    else
    {
        p = start;
        while (p->next != start)
        {
            p = p->next;
        }
        p->next = start->next;
        temp = start;
        start = start->next;
        free(temp);
    }
    return start;
}
struct node *Deletend_scll(struct node *start)
{
    if (start == NULL)
    {
        printf("scll is empty ");
    }
    else if (start->next == start)
    {
        temp = start;
        start = start->next;
        free(temp);
    }
    else
    {
        p = start;
        while (p->next->next != start)
        {
            p = p->next;
        }
        temp = p->next;
        p->next = start;
        temp->next = NULL;
        free(temp);
    }
    return start;
}
struct node *Deleteany_scll(struct node *start)
{
    if (start == NULL)
    {
        printf("scll is empty:");
    }
    else if (start->next == start)
    {
        temp = start;
        temp->next = NULL;
        free(temp);
    }
    else
    {
        int pos, count = 0;
        printf("enter position you want to delete:");
        scanf("%d", &pos);
        p = start;
        while (p->next != start)
        {
            p = p->next;
            count = count + 1;
        }
        if (pos == 1)
        {
            start = Deletebeg_scll(start);
            Display_scll(start);
        }
        else if (pos == count)
        {
            start = Deletend_scll(start);
            Display_scll(start);
        }
        else if (pos > 1 && pos < count)
        {
            p = start;
            for (int i = 1; i < pos - 1; i++)
            {
                p = p->next;
            }
            temp = p->next;
            p->next = temp->next;
            temp->next = NULL;
            free(temp);
        }
        else
        {
            printf("Entered invalid position:");
        }
        return start;
    }
}
struct node *Reverse_scll(struct node *start)
{
    if (start == NULL)
    {
        printf("scll is empty");
    }
    else if (start->next == start)
    {
        printf("scll has only one node");
    }
    else
    {
        p1 = start;
        p2 = start->next;
        p3 = NULL;
        while (p2 != start)
        {
            p3 = p2->next;
            p2->next = p1;
            p1 = p2;
            p2 = p3;
        }
        start->next = p1;
        start = p1;
        return start;
    }
}


