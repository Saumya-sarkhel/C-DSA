#include<stdio.h>
#include<stdlib.h>

void Enqueue(int *,int);
void Dequeue(int *);
void display(int *);
int rear = -1;
int front = -1;


int main(){
	int queue[10], max, choice;
	printf("Enter the Max Size:");
	scanf("%d",&max);
	while(1){
		printf("\n\n1.ENQUEUE \n2.DEQUEUE \n3.DISPLAY \n4.EXIT\n");
		printf("\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice){
			case 1: Enqueue(queue,max);
					break;
			case 2: Dequeue(queue);
					break;
			case 3: display(queue);
					break;
			case 4: exit(1);
					break;	
			default: printf("\nWrong Choice :(\n");
		}
		
	}
}

void Enqueue(int *queue, int max){
    if(rear==(max-1)){
        printf("\nQueue is full...");
    }
    else {
        rear++;
        printf("Enter the data: ");
        scanf("%d", &queue[rear]);
        if(rear==0){
            front=0;
        }
    }
}

void Dequeue(int *queue){
    int data;
    if(rear == -1 && front == -1){
        printf("\nQueue is Empty...");
    }
    else{
        data = queue[front];
        if(rear == front){
            rear=-1;
            front=-1;
        }
        else{
            front++;
        }
        printf("Deleted data is: %d", data);
    }
    
}

void display(int *queue){
    int i;
    if(rear == -1 && front == -1){
        printf("Queue is empty...");
    }
    else{
        i= front;
        printf("Queue elements are:\n");
        while(i<=rear){
            printf("| %d |",queue[i]);
            i++;
        }
    }
}