
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node Queue;
Queue *head=NULL,*temp;
int front=-1,rear=-1;
void enqueue(int);
void dequeue();
void display();
int main(){
	int i,max,ch,data;
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
					if((rear==max-1&&front==0) || rear==front-1){
						printf("Queue is full.");
					}
					else{
						printf("\nEnter the data :");
                    	scanf("%d",&data);
						rear=(rear+1)%max;
						if(rear==0&&front==-1)
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
						if(rear==front)
						{
							front=-1;
							rear=-1;
						}
						else
							front=(front+1)%max;
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
		if(front<=rear){
			q=head;
			while(q->next!=NULL){
				q=q->next;
			}
			q->next=new1;
		}
		else{
			if(rear==0){
				new1->next=head;
				head=new1;
				temp=head;
			}
			else{
				new1->next=temp->next;
				temp->next=new1;
				temp=temp->next;

			}

		}
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
    	if(front<=rear){

            head=head->next;
            data=p->data;
            p->next=NULL;
        }
        else{
        	while(p!=temp->next)
        		p=p->next;
        	temp->next=p->next;
        	p->next=NULL;
        	data=p->data;

		}
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






// #include <stdio.h>
// #include <stdlib.h>

// struct node{
//     int data;
//     struct node *next;
// };
// struct node *front = NULL;
// struct node *rear = NULL;

// void enqueue(int d){
//     struct node *n;
//     n = (struct node *)malloc(sizeof(struct node));
//     n->data = d;
//     n->next = NULL;
//     if ((rear == NULL) && (front == NULL)){
//         front = rear = n;
//         rear->next = front;
//     }
//     else{
//         rear->next = n;
//         rear = n;
//         n->next = front;
//     }
// }

// void dequeue() {
//     struct node *t;
//     t = front;
//     if ((front == NULL) && (rear == NULL))
//         printf("Queue is Empty\n");
//     else if (front == rear){
//         front = rear = NULL;
//         free(t);
//     }
//     else{
//         front = front->next;
//         rear->next = front;
//         printf("Deleted data is: %d\n", t->data);
//         free(t);
//     }
// }

// void display(){
//     struct node *t;
//     t = front;
//     if ((front == NULL) && (rear == NULL))
//         printf("\nQueue is Empty");
//     else{
//         do{
//             printf(" %d |", t->data);
//             t = t->next;
//         } while (t != front);
//     }
// }

// int main(){
//     int i, choice, x;
//     while (1){
//         printf("\n1.Enqueue \n2.Dequeue \n3.Display \n4.Exit\n");
//         printf("\nEnter your choice: ");
//         scanf("%d", &choice);
//         switch (choice)
//         {
//         case 1:
//             printf("Enter number to enqueue: ");
//             scanf("%d", &x);
//             enqueue(x);
//             break;
//         case 2:
//             dequeue();
//             break;
//         case 3:
//             display();
//             break;
//         case 4:
//             exit(1);
//             break;
//         default:
//             printf("\nWrong Choice :(\n");
//         }
//     }
//     return 0;
// }
