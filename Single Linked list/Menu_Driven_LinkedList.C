
#include<stdio.h>
#include<stdlib.h>

struct node{
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
void DelAnypos();
void count();
void selection_sort();
void reverce();
void LinearSearch();
void Findmin();
void Findmax();

int main(){
<<<<<<< HEAD:Single Linked list/Menu_Driven_LinkedList.C
=======
  int n;
  while(1){
    printf("\n\n1. Insert At Beg\n2. Insert At End\n3. Insert after Any Position\n4. Display\n5. Delete From End\n6. Delete From Begining\n7. Insert after Any Value\n8. Insert at Any Position\n9. Insert Before Any Position\n10. Delete from any position\n11. Count node\n12. Sort the node\n");
    printf("13. Reverce list\n14. Linear Search\n15. Finf Minimun\n16. Find Maximum\n17. Exit\n");
    printf("enter your choice :");
    scanf("%d",&n);
>>>>>>> b19f68edc4b1cde061acff2bbd6b8548c7b34623:Linked list/Menu_Driven_LinkedList.C
    int n;
    while(1){
        printf("\n\n1.Insert At Beg\n2.Insert At End\n3.Insert after Any Position\n4.Display\n5.Delete From End\n6.Delete From Begining\n7.Insert after Any Value\n8.Insert at Any Position\n9.Insert Before Any Position\n10.Delete from any position\n11.Count node\n12.Sort the node\n");
        printf("13.Reverce list\n14.Linear Search\n15.Exit\n");
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
            case 10: DelAnypos();
                    break;
            case 11: count();
                    break;
            case 12: selection_sort();
                    display();
                    break;
            case 13: reverce();
                    break;
            case 14: LinearSearch();
                    break;
            case 15: exit(1);
            default:  printf("Wrong choice..plz re-enter..! ");
        }
  }
}

void insBeg(){
    struct node *new1;
    new1=(struct node *)malloc(sizeof(struct node ));//dynamical creation of NODE
    printf("enter the data :");
    scanf("%d",&new1->data);
   	new1->next=NULL;
    if(head==NULL){
      head=new1;
    }
    else{
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
    if(head==NULL){
      head=new1; 
    }
    else{
      p=head;
      while(p->next!=NULL){
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
    if(head==NULL){
      head=new1;
    }
    else{
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
        else{
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
    if(head==NULL){
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
    if(head==NULL){
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
            printf("Possition not exists..\n");
          }
		}
  }
}

void delBeg(){
    if(head==NULL)//if no NODE in the list
    {
      printf("\nempty list..");
    }
    else{
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
		printf("\nempty list..\n");
	}
	else{
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
		printf("\nempty list..\n");
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

void DelAnypos(){
	struct node *p, *q;
	if(head == NULL){
		printf("List is empty..\n");
	}
	else{
		int pos, i;
		printf("Enter the position: ");
		scanf("%d", &pos);
		if(pos == i && head->next == NULL){
			printf("deleted data is: %d", head->data);
		}
		else if(pos == i){
			p = head;
			head = head->next;
			p->next = NULL;
			printf("Deleted data is: %d", p->data);
		}
		else{
			p = head;
			q = head;
			i=1;
			while(p->next != NULL && i != pos){
				q = p;
				p = p->next;
				i++;
			}
			if(pos == i && p->next == NULL){
				q->next = NULL;
				printf("Deleted data is: %d", p->data);
			}
			else if(pos == i && p->next != NULL){
				q->next =p->next;
				p->next = NULL;
				printf("Deletde data is: %d", p->data);
			}
			else //(p->next != NULL && i != pos)
			{
				printf("position Not found.\n");
			}
		}
	}
}

void count(){
	struct node *p, *q;
	if(head == NULL){
		printf("List is empty..\n");
	}
	else{
		int count = 0;
		for(p=head; p!=NULL; p=p->next){
			count++;
		}
		printf("Number of node is %d\n", count);
	}
}

void selection_sort(){
	struct node *p,*q,*r,*k1,*k;
	int t;
	if(head==NULL){
		printf("Empty list..\n");
	}
	else{
		p=head;
		k1=NULL;
		while(p->next!=NULL){
			q=head;
			r=q;
			while(q!=k1){
				if(q->data>r->data){
					r=q;
				}
				k=q;
				q=q->next;
			}
			if(r!=k){
				t=r->data;
				r->data=k->data;
				k->data=t;
			}
			q=head;
			while(q!=k){
				q=q->next;
			}
			k1=q;
			p=p->next;
		}
	}
}

void reverce(){
	struct node *p,*q,*r,*l;
	int i=1;
	if(head==NULL){
		printf("Empty list.\n");
	}
	else{
		p=head;
		while(p->next!=NULL){
			q=head;
			while(q->next!=NULL){
				r=q;
				q=q->next;
			}
			if(i==1){
				q->next=head;
				r->next=NULL;
				head=q;
				l=q;
			}
			else if(p->next!=NULL){
				q->next=l->next;
				l->next=q;
				r->next=NULL;
			}
			i++;
		}
	}
  display();
}

void LinearSearch(){
	struct node *p;
	p=head;
	if(head==NULL){
		printf("Empty list..\n");
	}
	else{
		int key,flag=0;
		printf("Enter the value you want to search:");
		scanf("%d",&key);
		for(p=head;p!=NULL;p=p->next){
			if(p->data==key){
				flag=1;
				break;
			}
		}
		if(flag==1){
			printf("%d is founded");
		}
		else
		printf("Not founded");
	}
}
<<<<<<< HEAD


void Findmin(){
	struct node *p;
	int max;
	if(head==NULL){
		printf("Empty list");
	}
	else{
		p=head;
		max=p->data;
		for(;p!=NULL;p=p->next){
			if(max>p->data){
				max=p->data;
			}
			
		}
		printf("%d is maximam in list.\n",max);
	}
}

void Findmax(){
	struct node *p;
	int max;
	if(head==NULL){
		printf("Empty list");
	}
	else{
		p=head;
		max=p->data;
		for(;p!=NULL;p=p->next){
			if(max<p->data){
				max=p->data;
			}
		}
		printf("%d is maximam in list.\n",max);
	}
}
