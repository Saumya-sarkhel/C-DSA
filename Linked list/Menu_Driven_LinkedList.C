#include<stdio.h>
#include<stdlib.h>
struct node//structure of NODE
{
	int data;
	struct node * next;
};
struct node * head=NULL;

void insBeg();
void display();
void insEnd();
void insAtPos();
void delEnd();
void delBeg();
void insAfterPos();
void insAfterValue();
void insBeforePos();
void Insert_Before_Any_Position();

int main(){
    int n;
    while(1){
        printf("\n\n1.Insert At Beg\n2.Insert At End\n3.Insert after AnyPos\n4.Display\n5.Delete From End\n6.Delete From Beg\n7.Insert after AnyValue\n8.Insert at AnyPos\n9.Insert Before AnyPos\n10.Insert before any position\n11.Exit\n");//menu
        printf("enter your choice :");
        scanf("%d",&n);
        switch(n){
            case 1: insBeg();
                    break;
	    case 2:  insEnd();
                    break;
            case 3: insAfterPos();
                    break;
            case 4: display();
                    break;
            case 5: delEnd();
                    break;
            case 6: delBeg();
                    break;
            case 7: insAfterValue();
                    break;
            case 8: insAtPos();
                    break;
            case 9: insBeforePos();
                    break;
            case 10: Insert_Before_Any_Position();
                    break;
            case 11: exit(1);
            default:
                    printf("Wrong choice..plz re-enter..! ");
        }
    }
}

void insBeg(){
    struct node *new1;
    new1=(struct node *)malloc(sizeof(struct node ));//dynamical creation of NODE
    printf("enter the data :");
    scanf("%d",&new1->data);
   	new1->next=NULL;
    if(head==NULL)//if no NODE in the list
    {
        head=new1;
        
    }
    else
    {
        new1->next=head;
        head=new1;
    }

}

void insEnd(){
    struct node *new1,*p;
    new1=(struct node *)malloc(sizeof(struct node ));//dynamical creation of NODE
    printf("enter the data :");
    scanf("%d",&new1->data);
   	new1->next=NULL;
    if(head==NULL)//if no NODE in the list
    {
        head=new1; 
    }
    else
    {
        p=head;
        while(p->next!=NULL)//finding last NODE
        {
            p=p->next;
        }
        p->next=new1;
    }
}

void insAfterPos(){
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
        p=head;
        i=1;
        printf("\nEnter the position:");
        scanf("%d",&pos);
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

void insAfterValue(){
    struct node *new1,*p;
    int key;
    new1=(struct node *)malloc(sizeof(struct node ));//dynamical creation of NODE
    printf("enter the data :");
    scanf("%d",&new1->data);
   	new1->next=NULL;
    if(head==NULL)//if no NODE in the list
    {
        //printf("This is the first node..");
        head=new1;
    }
    else{
        p=head;
        printf("\nEnter the Value:");
        scanf("%d",&key);
        while(p->data!=key&&p->next!=NULL)//finding the position
        {
          p=p->next;
        }
        if(p->next==NULL&&p->data==key)//if position is the last position
        {
          p->next=new1;
        }
        else if(p->next!=NULL&&p->data==key){
          new1->next=p->next;//if position in between fast and last position
          p->next=new1;
        }
        else{
          printf("Value not exists.. ");
        }
     }
}

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
      p=head;
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

void insBeforePos(){
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
    else{
        p=head;
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
          else if(p->next!=NULL&&i==pos){
            new1->next=p->next;//if position in between fast and last position
            p->next=new1;
          }
          else{
            printf("Possition not exists.. ");
          }
		}
  }
}

void delBeg(){
    if(head==NULL)//if no NODE in the list
    {
        printf("\nempty list..");
    }
    else
    {
      struct node *p=head;
      head=head->next;
      p->next=NULL;
      printf("Deleted data is:%d",p->data);
    }
}

void delEnd(){
	struct node *p,*q;
	if(head==NULL)//if no NODE in the list
	{
		printf("\nempty list");
	}
	else
	{
	  p=head;
	  q=head;
    while(p->next!=NULL)//finding the last node
    {
      q=p;
      p=p->next;
    }
    q->next=NULL;
    p->next=NULL;
    printf("Deleted data is:%d",p->data);
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
    printf("NULL");
  }
}

void Insert_Before_Any_Position(){
	struct node *temp, *p;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d",&temp->data);
    temp->next=NULL;
    if (head == NULL) {
      head = temp;
    }
    else {
        int i,pos;
        printf("Enter the position: ");
        scanf("%d",&pos);
        pos=pos-1;
        i=1;
        p = head;
        if(pos==0){
          temp->next=head;
          head=temp;	
        }
        else{
          while(i!=pos&&p->next!=NULL){
            i++;
            p=p->next;
          }
          if (i==pos && p->next!=NULL) {
            temp->next = p->next;
            p->next = temp;
            }
          else if(i==pos&&p->next==NULL) {
            p->next=temp;
          }
          else{
            printf("Position not found\n");
          }
    }
	}
} 
