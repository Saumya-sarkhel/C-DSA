#include<stdio.h>
#include<stdlib.h>

void enqueue(int *,int);
void dequeue(int *,int);
void display(int *,int);
int rear=-1;
int front=-1;

int main(){
	int queue[10], max, choice;
	printf("Enter the max size:");
	scanf("%d",&max);

	while(1){
		printf("\n1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.EXIT\n");
		printf("\nEnter your choise:");
		scanf("%d",&choice);
		switch(choice){
			case 1:	enqueue(queue,max);
				break;
			case 2:	dequeue(queue,max);
				break;
			case 3:	display(queue,max);
				break;
			case 4:	exit(1);
				break;
			default:printf("\nEnter a valid choice.");
		}
	}
}

void enqueue(int *queue,int max){
	if((rear==max-1 && front==0)||(front==rear+1))
		printf("Queue is full...\n");
	else{
		rear=(rear+1)%max;
		printf("Enter the data:");
		scanf("%d",&queue[rear]);
		if(rear==0 && front==-1) front=0;
	}
}


void dequeue(int *queue,int max){
	int data;
	if(rear==-1 && front==-1)
		printf("Queue is empty...\n");

	else{
		data=queue[front];
		if(rear==front){
			rear=-1;
			front=-1;
		}
		else{
			front=(front+1)% max;
    }
		printf("Deleted element is:%d\n",data);
	}
}

void display(int *queue,int max){
	int i, j;
	if(rear==-1 && front==-1){
		printf("Queue is empty...\n");
  }

	else{
		if(front<=rear){
			i=front;
			while(i<=rear){
				printf(" %d |",queue[i]);
				i++;
			}
		}

		else if(rear<front){
			i=0;
			while(i<=rear){
				printf(" %d |",queue[i]);
				i++;
			}
			j=front;
			while(j<=(max-1)){
				printf("| %d |\n",queue[j]);
				j++;
			}
		}
	}
}
