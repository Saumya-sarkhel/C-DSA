
#include<stdio.h>
#include<malloc.h>

struct node{
    int data;
    struct node * next;
};
struct node *head = NULL;
void insAtPos(){
    struct node *new1,*p;
    int i,pos;
    new1=(struct node *)malloc(sizeof(struct node ));//dynamical creation of NODE
    printf("enter the data :");
    scanf("%d",&new1->data);
   	new1->next=NULL;
    if(head==NULL)//if no NODE in the list
    {
        //printf("This is the first node..");
        head=new1;
    }
    else
    {
      p = head;
      i=1;
      printf("\nEnter the position:");
      scanf("%d",&pos);
      pos=pos-1;
      if(pos==0){
        new1->next=head;
        head=new1;
      }
		else{
			while(i!=pos&&p->next!=NULL)//finding the position
      {
        p=p->next;
        i++;
      }
      if(p->next==NULL&&i==pos)//if position is the last position
      {
        p->next=new1;
      }
      else if(p->next!=NULL&&i==pos)
      {
        new1->next=p->next;//if position in between fast and last position
        p->next=new1;
        }
        else
        {
          printf("Possition not exists.. ");
        }
		}
        
  }
}

void display(){
	struct node *p;
	if(head==NULL)//if no NODE in the list
	{
		printf("\nempty list");
	}
	else{
    p=head;
    printf("\nThe elements are ::\n");
    for(p=head;p!=NULL;p=p->next)//display the elements
    {
      printf("| %d |->",p->data);
    }
    printf("NULL\n");
  }
}

int main(){
    int n, x, i;
    while(1){
      printf("\n1. Insert at any position\n2.Exit\n\n");
      printf("enter your choice :");
      scanf("%d",&n);
      switch(n){
        case 1: insAtPos();
                display();
                break;
        case 2: exit(1);
        default: printf("Invalid input.");
      }
    }
  return 0;
}