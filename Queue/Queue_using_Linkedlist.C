#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node Queue;
Queue *head=NULL;

void enqueue(int);
void dequeue();
void display();

int main(){
	int i,max,ch,front=-1,rear=-1,data;
	char c;
	printf("Enter the max size of the queue : ");
	scanf("%d",&max);
	while(1){
		printf("\n1.Enqueue.\n");
		printf("2.Dequeue.\n");
		printf("3.Display.\n");
		printf("4.Exit\n");
		printf("Enter your choice : ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
					if(rear==max-1){
						printf("Queue is full.");
					}
					else{
						printf("\nEnter the data :");
                    	scanf("%d",&data);
						rear++;
						if(rear==0)
							front=0;
						enqueue(data);//q[rear]=data
					}
					break;
			case 2:
					if(rear==-1&&front==-1){
						printf("Queue is empty.");
					}
					else{
						dequeue();
						if(rear==front){
							front=-1;
							rear=-1;
						}
						else
							front++;
					}
					break;
			case 3:
					display();
					break;
			case 4: exit(1);
		   	default:
			   printf("Wrong choice.");
		}

	}
}

void enqueue(int data){
	Queue *new1,*q;
	new1=(Queue*)malloc(sizeof(Queue));
	new1->data=data;
	new1->next=NULL;
	if(head==NULL){
		head=new1;

	}
	else{
		q=head;
		while(q->next!=NULL)
		{
			q=q->next;
		}
		q->next=new1;
	}
}

void dequeue(){
	Queue *p=head;
	int data;
	if(head->next==NULL){
            data=head->data;
            head=NULL;
    }
    else{
            head=head->next;
            data=p->data;
            p->next=NULL;
    }
    printf("the deleted element is=%d\n",data);
}

void display(){
	Queue *p=head;
	if(head==NULL){
		printf("Queue is empty..");
	}
	else{
		printf("Queue elements are :");
		while(p!=NULL){
			printf("|%d|",p->data);
			p=p->next;
		}
	}
}
