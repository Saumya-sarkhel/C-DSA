#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * next;
};
typedef struct node stack;

int top = -1;
void push(int);//for pushing elements in the stack
void pop();//for poping elements in the stack
void display();//displaying the stack's elements
int peek();
stack *head=NULL;//top position of the stack

int main(){
    int ch,max,data;
    printf("Enter the maxsize :");
    scanf("%d",&max);
    while(1){
       printf("\n1.Push\n");
       printf("2.Pop\n");
       printf("3.Display\n");
       printf("4.Exit\n");
       printf("5.peek\n");

       printf("\nEnter your Choice :");
       scanf("%d",&ch);
       switch(ch){
        case 1: if(top==max-1){
                    printf("\nStack is Full\n");
           		}
                else{
                    printf("Enter the data :");
                    scanf("%d",&data);
                    top++;
                    push(data);//s[top]=data
                }
                break;
        case 2: if(top==-1){
                    printf("\nStack is Empty\n");
                }
                else{
                    pop(); //pop the element
                    top--;
                }
                break;
        case 3: display();
                break;
        case 4: exit(1);
                break;
        case 5:if (top == -1){
                printf("\nStack is Empty\n");
            }else{
                printf("The top element is: %d\n", peek());
            }
            break;
        default: printf("wrong choice\n");
        }
    }
}

void push(int data){
    stack *new1;
    new1=(stack*)malloc(sizeof(stack));//dynamical creation of NODE
    new1->data=data;
    new1->next=NULL;
    if(head==NULL){
        head=new1;
    }
    else{
        new1->next=head;
        head=new1;
    }
}

void pop(){
    stack *p=head;
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
    free(p);
    printf("the deleted element is=%d\n",data);
}

int peek() {
    if (head == NULL) {
        printf("Stack is empty, cannot peek.\n");
        return -1;
    }
    return head->data;
}

void display(){
	stack *p = head;
	int i;
	if(head == NULL)
		printf("Stack is empty...\n");
	else {
        printf("\nElements in the stack are:\n");
        while(p!=NULL){
            printf("|%d|",p->data);
            p=p->next;
        }
        printf("\n");
	}
}
