#include<stdio.h>
#include<stdlib.h>

void insert_rear(int*, int);
void insert_front(int*, int);
void delete_rear(int*, int);
void delete_front(int*, int);
void display(int*, int);

int front=-1;
int rear=-1;

int main(){
    int ch, max, DQ[20];
    printf("Enter max size of the Queue: ");
    scanf("%d", &max);
    while(1){
        printf("\n1. Insert at Rear\n2. Insert at Front\n3. Delete from Front\n4. Delete from Rear\n5. Exit\n6. Display\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 1: insert_rear(DQ, max); break;
            case 2: insert_front(DQ, max); break;
            case 3: delete_front(DQ, max); break;
            case 4: delete_rear(DQ, max); break;
            case 5: exit(1);
            case 6: display(DQ, max); break;
            default: printf("\nWrong Choice.\n");
        }
    }
}

void insert_rear(int *DQ, int max){
    int item;
    printf("Enter the item to be inserted: ");
    scanf("%d", &item);
    if((rear==max-1 && front == 0) || rear == front-1){
        printf("\nQueue is full.\n");
    }
    else{
        if(front==-1 && rear==-1){
            rear = 0;
            front = 0;
            DQ[rear] = item;
            printf("\n%d inserted in the Queue.\n", item);
        }
        else if(rear == max-1){
            rear = 0;
            DQ[rear] = item;
            printf("\n%d inserted in the Queue.\n", item);
        }
        else{
            rear=rear+1;
        }
        DQ[rear] = item;
        printf("\n%d inserted in the Queue.\n", item);
    }
}

void insert_front(int *DQ, int max){
    if(rear == max-1 && front == 0){
        printf("Queue is full\n");
    }
    else{
        int item;
        printf("Enter data to insert: ");
        scanf("%d",&item);
        if(rear == -1 && front == -1){
            rear = 0;
            front = 0;
            DQ[front] = item;
            printf("\n%d inserted in the Queue.\n", item);
        }
        else if(front == 0){
            front = max-1;
            DQ[front] = item;
            printf("\n%d inserted in the Queue.\n", item);
        }
        else{
            front = front-1;
        }
        DQ[front] = item;
        printf("\n%d inserted in the Queue.\n", item);
    }
}

void delete_front(int *DQ,int max){
    if(rear == -1 && front == -1){
        printf("\nQueue is empty\n");
    }
    else{
        int data = DQ[front];
        if(rear == front){
            rear = -1;
            front = -1;
        }
        else if(front == max-1){
            front = 0;
        }
        else{
            front = front+1;
        }
        printf("Deleted data is: %d\n", data);
    }
}

void delete_rear(int *DQ,int max){
    if(rear == -1 && front == -1){
        printf("\nQueue is Empty\n");
    }
    else{
        int data = DQ[rear];
        if(rear == front){
            rear = -1;
            front = -1;
        }
        else if(rear == 0){
            rear = max-1;
        }
        else{
            rear = rear-1;
        }
        printf("Deleted data is %d\n", data);
    }
}

void display(int *queue,int max){
	int i, j;
	if(rear==-1 && front==-1){
		printf("Queue is empty...\n");
    }
	else{
        printf("Queue elements: ");
		if(front<=rear){
			i=front;
			while(i<=rear){
				printf(" %d |",queue[i]);
				i++;
			}
		}
		else{
			for(int i = front; i < max; i++){
                printf("%d |", queue[i]);
            }
            for(int i = 0; i <= rear; i++){
                printf("%d |", queue[i]);
            }
		}
	}
}
