#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX 5

int itemcount = 0;
int PQ[MAX];

bool isFull() {
    return itemcount == MAX;
}

void priorityQueue(int data) {
    int i;

    if (!isFull()) {
        if (itemcount == 0) {
            PQ[itemcount++] = data;
        } else {
            for (i = itemcount - 1; i >= 0; i--) {
                if (data < PQ[i]) {
                    PQ[i + 1] = PQ[i];
                } else {
                    break;
                }
            }
            PQ[i + 1] = data;
            itemcount++;
        }
    } else {
        printf("Priority Queue is Full!\n");
    }
}

int RemoveData() {
        return PQ[--itemcount];
}

int main() {

    int choice, x;

    while (1) {
        printf("\n1. Add element to Priority Queue\n");
        printf("2. Serve the Queue\n");
        printf("3. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter data to be inserted: ");
                scanf("%d", &x);
                priorityQueue(x);
                break;

            case 2: {
                int store = RemoveData();
                printf("Served: %d\n", store);
                break;
            }

            case 3:
                printf("Exiting!");
                exit(0);

            default:
                printf("Invalid Choice!\n");
        }
    }

    return 0;
}