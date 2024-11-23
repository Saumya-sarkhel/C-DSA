#include<stdio.h>
#include<stdlib.h>

void push(int *,int);
void pop(int *);
void display(int *);
int top=-1;

int main(){
	int stack[10],maxSize,choice;
	printf("Enter the Max Size:");
	scanf("%d",&maxSize);

	while(1){
		printf("\n\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n");
		printf("\nEnter your choice:");
		scanf("%d",&choice);
		
		switch(choice){
			case 1: push(stack,maxSize);
					break;
			case 2: pop(stack);
					break;
			case 3: display(stack);
					break;
			case 4: exit(1);
					break;	
			default: printf("\nWrong Choice :(\n");
		}
		
	}
}

void push(int *stack,int maxSize){
	if(top==(maxSize-1)){
		printf("\nStack is Full..");
	}
	else{
		top=top+1;
		printf("\nEnter the Data:");
		scanf("%d",&stack[top]);
		
	}
}

void pop(int *stack){
	int data;
	if(top==-1){
		printf("\nStack is empty..");
	}
	else{
		data=stack[top];
		top=top-1;
		printf("\nDeleted elements is :%d",data);
	}
}


void display(int *stack){
	int i;
	if(top==-1){
		printf("\nStack is empty..");
	}
	else{
		printf("\nStack elements are:\n");
		i=top;
		while(i>=0){
			printf("|\t%d\t|\n",stack[i]);
			i=i-1;
		}
	}
}
