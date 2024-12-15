

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int d){
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = d;
    n->next = NULL;
    if ((rear == NULL) && (front == NULL)){
        front = rear = n;
        rear->next = front;
    }
    else{
        rear->next = n;
        rear = n;
        n->next = front;
    }
}

void dequeue() {
    struct node *t;
    t = front;
    if ((front == NULL) && (rear == NULL))
        printf("Queue is Empty\n");
    else if (front == rear){
        front = rear = NULL;
        free(t);
    }
    else{
        front = front->next;
        rear->next = front;
        printf("Deleted data is: %d\n", t->data);
        free(t);
    }
}

void display(){
    struct node *t;
    t = front;
    if ((front == NULL) && (rear == NULL))
        printf("\nQueue is Empty");
    else{
        do{
            printf(" %d |", t->data);
            t = t->next;
        } while (t != front);
    }
}

int main(){
    int i, choice, x;
    while (1){
        printf("\n1.Enqueue \n2.Dequeue \n3.Display \n4.Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter number to enqueue: ");
            scanf("%d", &x);
            enqueue(x);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
            break;
        default:
            printf("\nWrong Choice :(\n");
        }
    }
    return 0;
}
