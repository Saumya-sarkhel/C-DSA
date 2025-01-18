#include<stdio.h>
#include<stdlib.h>
struct node//structure of node
{
    int data;
    struct node * next;
};
typedef struct node stack;

void push(int);//for pushing elements in the stack
void pop();//for poping elements in the stack
void display();//displaying the stack's elements
stack *head=NULL;//top position of the stack

int main(){
    int ch,top=-1,max,data;
    printf("Enter the maxsize :");
    scanf("%d",&max);
    while(1){
       printf("\n1.for push\n");
       printf("2.for pop\n");
       printf("3.for display\n");
       printf("4.exit\n");
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
                    pop();
                    top--;
                }
                break;
        case 3: display();
                break;
        case 4: exit(1);
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
    printf("the deleted element is=%d\n",data);

}

void display(){
    stack *p;
    p=head;
    if(head==NULL){
        printf("\nstack is Empty\n");
    }
    else{
        printf("\nElements in the stack is\n");
        while(p!=NULL){
            printf("%d\n",p->data);
            p=p->next;
        }
    }

}
