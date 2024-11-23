#include<stdio.h>
#include<stdlib.h>

int push(int *,int,int);
int pop(int *,int);
void display(int *,int);

int main(){
	int stack[10], maxSize, top=-1, choice;
	printf("Enter the Max Size:");
	scanf("%d",&maxSize);

	while(1){
		printf("\n\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n");
		printf("\nEnter your choice:");
		scanf("%d",&choice);

		switch(choice){
			case 1: top=push(stack,maxSize,top);
					break;
			case 2: top=pop(stack,top);
					break;
			case 3: display(stack,top);
					break;
			case 4: exit(1);
					break;	
			default: printf("\nWrong Choice :(\n");
		}
		
	}
}
int push(int *stack,int maxSize,int top){
	if(top==(maxSize-1)){
		printf("\nStack is Full..");
	}
	else{
		top=top+1;
		printf("\nEnter the Data:");
		scanf("%d",&stack[top]);
	}
	return top;
}

int pop(int *stack,int top){
	int data;
	if(top==-1){
		printf("\nStack is empty..");
	}
	else{
		data=stack[top];
		top=top-1;
		printf("\nDeleted elements is :%d",data);
	}
	return top;
}

void display(int *stack,int top){
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
