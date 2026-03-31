#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*temp,*p,*front=NULL,*rear=NULL,*queue=NULL;

struct node *enqueue(struct node *queue){
    temp=(struct node*)malloc(sizeof(struct node));
    int x;
    printf("Enter data to be stored: ");
    scanf("%d",&x);

    temp->data=x;
    temp->next=NULL;

    if(front==NULL){
        front=rear=temp;
    }
    else{
        rear->next=temp;
        rear=temp;
    }

    return queue;
}

struct node *dequeue(struct node *queue){
    if(front==NULL){
        printf("Quueu is Empty!\n");
    }
    else if(front->next==NULL){
        temp=front;
        front=rear=NULL;
        free(temp);
        printf("Deleted\n");
    }
    else{
        temp=front;
        front=front->next;
        temp->next=NULL;
        free(temp);
        printf("Deleted\n");
    }

    return queue;

}

struct node *display(struct node *queue){
    if(front==NULL){
        printf("Queue is Empty!\n");
    }
    else{
        for(p=front;p!=NULL;p=p->next){
            printf("%d",p->data);
            if(p->next!=NULL){
                printf("->");
            }
        }
    }

    return queue;
}

int main(){
    int choice,x;
    while(1){
        printf("\n---------------MAIN MENU----------\n");
        printf("1.Inserting an element to queue\n");
        printf("2.deleting an element from queue\n");
        printf("3.Displaying elements of the Queue\n");
        printf("4.Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: queue=enqueue(queue);
                    break;
            case 2: queue=dequeue(queue);
                    break;
            case 3: queue=display(queue);
                    break;
            case 4: printf("Exiting!\n");
                    exit(0);
                    break;
            default: printf("Entered Invalid choice!\n");
                    break;
        }
    }

    return 0;
}
