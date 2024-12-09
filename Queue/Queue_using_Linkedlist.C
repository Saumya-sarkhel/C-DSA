#include<stdio.h>
#include<stdlib.h>

struct Node{
  int data;
  struct Node *next;
};
struct Node *head = NULL;

void enqueue(int x){
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    p->data = x;
    p->next = NULL;
    if (head == NULL){
      head = p;
    }
    else{
      struct Node *temp = head;
      while(temp->next != NULL){
        temp = temp->next;
      }
      temp->next = p;
    }
}

void dequeue(){
    if (head == NULL){
      printf("Empty Queue\n");
    }
    else{
      struct Node *ptr = head;
      head = ptr->next;
      printf("Deleted data is %d\n", ptr->data);
      free(ptr);
    }
}

void display(){
	if(head==NULL){
		printf("Queue is empty\n");
		return;
	}
	struct Node *ptr = head;
	printf("Queue elements are:\n");
	while (ptr != NULL){
      printf("|%d|\n", ptr->data);
      ptr = ptr->next;
    }
}
int main(){
	int x, choice;
	while(1){
		printf("\n1.Enqueue \n2.Dequeue \n3.Display \n4.Exit\n");
		printf("\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice){
			case 1:	printf("Enter number to enqueue: ");
							scanf("%d",&x);
							enqueue(x);
							break;
			case 2: dequeue();
							break;
			case 3: display();
							break;
			case 4: exit(1);
							break;	
			default: printf("\nWrong Choice :(\n");
		}
		
	}
	return 0;
}