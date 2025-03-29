//Single Ended-Queue Using Linked-list:

#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};
struct node *head=NULL;
void enqueue(int);
void dequeue();
void display();
int rear=-1;
int front=-1;

int main(){
	int maxSize,choice;
	printf("Enter the max size:");
	scanf("%d",&maxSize);
	while(1){
		printf("\n1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.EXIT\n");
		printf("\nEnter your choise:");
		scanf("%d",&choice);
		switch(choice){
			case 1:	enqueue(maxSize);
					break;
			case 2:	dequeue();
					break;
			case 3:	display();
					break;
			case 4:	exit(1);
					break;
			default:printf("\nEnter a valid choice:");
		}
	}
}
void enqueue(int maxSize){
	if(rear==(maxSize-1))
		printf("Queue is full...\n");
	else{
		struct node *new1,*p;
		new1=(struct node*)malloc(sizeof(struct node));
		printf("Enter the data:");
		scanf("%d",&new1->data);
		new1->next=NULL;
		if(head==NULL)
			head=new1;
		else{
			p=head;
			while(p->next!=NULL){
				p=p->next;
			}
			p->next=new1;
		}
		rear++;
		if(rear==0)
			front=0;
	}
}

void dequeue(){
	int data;
	if(rear==-1 && front==-1)
		printf("Queue is empty...\n");
	else{
		struct node *p;
		p=head;
		head=head->next;
		p->next=NULL;
		printf("Deleted data is :%d",p->data);
	}
	if(rear==front){
		rear=-1;
		front=-1;
	}
	else
		front++;
}

void display(){
	struct node *p;
	if(rear==-1 && front==-1)
		printf("Queue is empty...\n");
	else{
		printf("Queue is:");
		for(p=head;p!=NULL;p=p->next){
			printf("%d|",p->data);
		}
	}
}
