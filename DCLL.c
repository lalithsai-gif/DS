#include <stdio.h>
#include <stdlib.h>

struct node *Creation_dcll(struct node *start);
struct node *Display_dcll(struct node *start);
struct node *Traversalbeg_dcll(struct node *start);
struct node *Traversalback_dcll(struct node *start);
struct node *Inserbeg_dcll(struct node *start);
struct node *Inserend_dcll(struct node *start);
struct node *Inserany_dcll(struct node *start);
struct node *Deletebeg_dcll(struct node *start);
struct node *Deletend_dcll(struct node *start);
struct node *Deleteany_dcll(struct node *start);
struct node *Reverse_dcll(struct node *start);

struct node
{
    struct node *prev;
    int data;
    struct node *next;
} *start = NULL, *p, *temp, *end;

int main()
{
    while (1)
    {
        printf("\n**************MENU***************\n");
        printf("(1) Creation of DCLL \n");
        printf("(2) Traversal from begining of DCLL \n");
        printf("(3) Traversal from ending of DCLL \n");
        printf("(4) Insertion at Beginning \n");
        printf("(5) Insertion at ending \n");
        printf("(6) Insertion at position \n");
        printf("(7) Delete from beginning \n");
        printf("(8) Delete from ending \n");
        printf("(9) Delete from position \n");
        printf("(10) Reverse DCLL \n");
        printf("(11) EXIT \n");

        int choice;
        printf("Choose one option from the above:");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1: start = Creation_dcll(start); 
                Display_dcll(start); 
                break;
        case 2: start = Traversalbeg_dcll(start); 
                break;
        case 3: start = Traversalback_dcll(start); 
                break;
        case 4: start = Inserbeg_dcll(start); 
                Display_dcll(start); 
                break;
        case 5: start = Inserend_dcll(start); 
                Display_dcll(start); 
                break;
        case 6: start = Inserany_dcll(start); 
                Display_dcll(start); 
                break;
        case 7: start = Deletebeg_dcll(start); 
                Display_dcll(start); 
                break;
        case 8: start = Deletend_dcll(start); 
                Display_dcll(start); 
                break;
        case 9: start = Deleteany_dcll(start); 
                Display_dcll(start); 
                break;
        case 10: start = Reverse_dcll(start); 
                Display_dcll(start); 
                break;
        case 11: exit(0);
        }
    }
}

struct node *Creation_dcll(struct node *start)
{
    int i, n;
    printf("enter number of values:");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        printf("enter value:");
        scanf("%d", &temp->data);

        if (start == NULL)
        {
            start = temp;
            temp->next = start;
            temp->prev = start;
        }
        else
        {
            end = start->prev;
            end->next = temp;
            temp->prev = end;
            temp->next = start;
            start->prev = temp;
        }
    }
    return start;
}

struct node *Display_dcll(struct node *start)
{
    if (start == NULL)
    {
        printf("List empty\n");
        return start;
    }

    p = start;
    while (p->next != start)
    {
        printf("%d<->", p->data);
        p = p->next;
    }
    printf("%d\n", p->data);
    return start;
}

struct node *Traversalbeg_dcll(struct node *start)
{
    if (start == NULL)
        printf("dcll is empty");
    else
    {
        p = start;
        while (p->next != start)
        {
            printf("%d<->", p->data);
            p = p->next;
        }
        printf("%d", p->data);
    }
    return start;
}

struct node *Traversalback_dcll(struct node *start)
{
    if (start == NULL)
        printf("dcll is empty");
    else
    {
        p = start->prev;
        while (p != start)
        {
            printf("%d<->", p->data);
            p = p->prev;
        }
        printf("%d", p->data);
    }
    return start;
}

struct node *Inserbeg_dcll(struct node *start)
{
    int val;
    temp = (struct node *)malloc(sizeof(struct node));

    printf("enter number:");
    scanf("%d", &val);
    temp->data = val;

    if (start == NULL)
    {
        start = temp;
        temp->next = start;
        temp->prev = start;
    }
    else
    {
        end = start->prev;
        temp->next = start;
        temp->prev = end;
        end->next = temp;
        start->prev = temp;
        start = temp;
    }
    return start;
}

struct node *Inserend_dcll(struct node *start)
{
    int val;
    temp = (struct node *)malloc(sizeof(struct node));

    printf("enter value:");
    scanf("%d", &val);
    temp->data = val;

    if (start == NULL)
    {
        start = temp;
        temp->next = start;
        temp->prev = start;
    }
    else
    {
        end = start->prev;
        temp->next = start;
        temp->prev = end;
        end->next = temp;
        start->prev = temp;
    }
    return start;
}

struct node *Inserany_dcll(struct node *start)
{
    if (start == NULL)
    {
        printf("List empty\n");
        return start;
    }

    int pos, c = 1;
    printf("enter position:");
    scanf("%d", &pos);

    p = start;
    while (p->next != start)
    {
        c++;
        p = p->next;
    }

    if (pos == 1)
        start = Inserbeg_dcll(start);
    else if (pos == c + 1)
        start = Inserend_dcll(start);
    else if (pos > 1 && pos <= c)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        int val, i;
        printf("enter value:");
        scanf("%d", &val);
        temp->data = val;

        p = start;
        for (i = 1; i < pos - 1; i++)
            p = p->next;

        temp->next = p->next;
        p->next->prev = temp;
        p->next = temp;
        temp->prev = p;
    }
    else
        printf("Invalid position");

    return start;
}

struct node *Deletebeg_dcll(struct node *start)
{
    if (start == NULL)
        printf("dcll empty");
    else if (start->next == start)
    {
        free(start);
        start = NULL;
    }
    else
    {
        temp = start;
        end = start->prev;
        start = start->next;
        start->prev = end;
        end->next = start;
        free(temp);
    }
    return start;
}

struct node *Deletend_dcll(struct node *start)
{
    if (start == NULL)
        printf("dcll empty");
    else if (start->next == start)
    {
        free(start);
        start = NULL;
    }
    else
    {
        end = start->prev;
        temp = end;
        end = end->prev;
        end->next = start;
        start->prev = end;
        free(temp);
    }
    return start;
}

struct node *Deleteany_dcll(struct node *start)
{
    if (start == NULL)
        return start;

    int pos, c = 1;
    printf("enter position:");
    scanf("%d", &pos);

    p = start;
    while (p->next != start)
    {
        c++;
        p = p->next;
    }

    if (pos == 1)
        start = Deletebeg_dcll(start);
    else if (pos == c)
        start = Deletend_dcll(start);
    else if (pos > 1 && pos < c)
    {
        p = start;
        for (int i = 1; i < pos - 1; i++)
            p = p->next;

        temp = p->next;
        p->next = temp->next;
        temp->next->prev = p;
        free(temp);
    }

    return start;
}

struct node *Reverse_dcll(struct node *start)
{
    if (start == NULL)
        printf("dcll empty");
    else if (start->next == start)
        printf("only one node");
    else
    {
        p = start;
        while (1)
        {
            temp = p->next;
            p->next = p->prev;
            p->prev = temp;
            p = temp;
            if (p == start)
                break;
        }
        start = start->prev;  
    }
    return start;
}
