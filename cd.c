#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *prev;
    int data;
    struct node *next;
};

struct node *start = NULL;

/* Function Declarations */
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

/* MAIN */
int main() {
    int choice;

    while (1) {
        printf("\n**************MENU***************\n");
        printf("(1) Create DCLL\n");
        printf("(2) Traverse from beginning\n");
        printf("(3) Traverse from end\n");
        printf("(4) Insert at beginning\n");
        printf("(5) Insert at end\n");
        printf("(6) Insert at position\n");
        printf("(7) Delete from beginning\n");
        printf("(8) Delete from end\n");
        printf("(9) Delete from position\n");
        printf("(10) Reverse DCLL\n");
        printf("(11) Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: start = Creation_dcll(start); break;
        case 2: Traversalbeg_dcll(start); break;
        case 3: Traversalback_dcll(start); break;
        case 4: start = Inserbeg_dcll(start); break;
        case 5: start = Inserend_dcll(start); break;
        case 6: start = Inserany_dcll(start); break;
        case 7: start = Deletebeg_dcll(start); break;
        case 8: start = Deletend_dcll(start); break;
        case 9: start = Deleteany_dcll(start); break;
        case 10: start = Reverse_dcll(start); break;
        case 11: exit(0);
        default: printf("Invalid choice\n");
        }

        Display_dcll(start);
    }
}

/* CREATE */
struct node *Creation_dcll(struct node *start) {
    int n, i, val;
    struct node *temp, *end;

    printf("How many nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        temp = (struct node*)malloc(sizeof(struct node));

        printf("Enter value: ");
        scanf("%d", &val);
        temp->data = val;

        if (start == NULL) {
            start = temp;
            temp->next = temp;
            temp->prev = temp;
        } else {
            end = start->prev;
            end->next = temp;
            temp->prev = end;
            temp->next = start;
            start->prev = temp;
        }
    }
    return start;
}

/* DISPLAY */
struct node *Display_dcll(struct node *start) {
    if (start == NULL) {
        printf("List empty\n");
        return start;
    }

    struct node *p = start;
    printf("List: ");
    do {
        printf("%d ", p->data);
        p = p->next;
    } while (p != start);

    printf("\n");
    return start;
}

/* TRAVERSE BEGIN */
struct node *Traversalbeg_dcll(struct node *start) {
    if (!start) { printf("Empty\n"); return start; }

    struct node *p = start;
    do {
        printf("%d ", p->data);
        p = p->next;
    } while (p != start);

    printf("\n");
    return start;
}

/* TRAVERSE END */
struct node *Traversalback_dcll(struct node *start) {
    if (!start) { printf("Empty\n"); return start; }

    struct node *p = start->prev;
    struct node *end = p;

    do {
        printf("%d ", p->data);
        p = p->prev;
    } while (p != end);

    printf("\n");
    return start;
}

/* INSERT BEGIN */
struct node *Inserbeg_dcll(struct node *start) {
    int val;
    printf("Value: ");
    scanf("%d", &val);

    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;

    if (!start) {
        temp->next = temp->prev = temp;
        return temp;
    }

    struct node *end = start->prev;

    temp->next = start;
    temp->prev = end;
    end->next = temp;
    start->prev = temp;

    return temp;
}

/* INSERT END */
struct node *Inserend_dcll(struct node *start) {
    int val;
    printf("Value: ");
    scanf("%d", &val);

    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;

    if (!start) {
        temp->next = temp->prev = temp;
        return temp;
    }

    struct node *end = start->prev;

    temp->next = start;
    temp->prev = end;
    end->next = temp;
    start->prev = temp;

    return start;
}

/* COUNT NODES */
int countNodes(struct node *start) {
    if (!start) return 0;

    int c = 0;
    struct node *p = start;
    do { c++; p = p->next; } while (p != start);

    return c;
}

/* INSERT ANY */
struct node *Inserany_dcll(struct node *start) {
    int pos, val, i;

    printf("Position: ");
    scanf("%d", &pos);

    int c = countNodes(start);

    if (pos < 1 || pos > c+1) {
        printf("Invalid position\n");
        return start;
    }

    if (pos == 1) return Inserbeg_dcll(start);
    if (pos == c+1) return Inserend_dcll(start);

    printf("Value: ");
    scanf("%d", &val);

    struct node *temp = malloc(sizeof(struct node));
    temp->data = val;

    struct node *p = start;
    for (i = 1; i < pos-1; i++) p = p->next;

    temp->next = p->next;
    temp->prev = p;
    p->next->prev = temp;
    p->next = temp;

    return start;
}

/* DELETE BEGIN */
struct node *Deletebeg_dcll(struct node *start) {
    if (!start) return NULL;

    if (start->next == start) {
        free(start);
        return NULL;
    }

    struct node *end = start->prev;
    struct node *temp = start;

    start = start->next;
    start->prev = end;
    end->next = start;

    free(temp);
    return start;
}

/* DELETE END */
struct node *Deletend_dcll(struct node *start) {
    if (!start) return NULL;

    if (start->next == start) {
        free(start);
        return NULL;
    }

    struct node *end = start->prev;
    end->prev->next = start;
    start->prev = end->prev;

    free(end);
    return start;
}

/* DELETE ANY */
struct node *Deleteany_dcll(struct node *start) {
    int pos, i;
    printf("Position: ");
    scanf("%d", &pos);

    int c = countNodes(start);

    if (pos < 1 || pos > c) {
        printf("Invalid position\n");
        return start;
    }

    if (pos == 1) return Deletebeg_dcll(start);
    if (pos == c) return Deletend_dcll(start);

    struct node *p = start;
    for (i = 1; i < pos-1; i++) p = p->next;

    struct node *temp = p->next;
    p->next = temp->next;
    temp->next->prev = p;

    free(temp);
    return start;
}

/* REVERSE */
struct node *Reverse_dcll(struct node *start) {
    if (!start || start->next == start) return start;

    struct node *p = start, *temp;

    do {
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = temp;
    } while (p != start);

    return start->next;
}
