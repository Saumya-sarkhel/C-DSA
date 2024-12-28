
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
typedef struct node node;
int main(){
	int i,n,m,x;
	node *head1,*head2,*head3,*p,*q,*r,*k;
	head1=NULL;
	head2=NULL;
	head3=NULL;
	printf("Enter the number of nodes in the first list:");
	scanf("%d",&n);
	printf("\nEnter the data in sorted order :\n\n");
	for(i=1;i<=n;i++){
		p=(node*)malloc(sizeof(node));
		printf("\nEnter the data:");
		scanf("%d",&p->data);
		p->next=NULL;
		if(head1==NULL){
			head1=p;
		}
		else{
			q=head1;
			while(q->next!=NULL){
				q=q->next;
			}
			q->next=p;
		}
	}
	printf("\nThe first list is:\n");
	for(q=head1;q!=NULL;q=q->next){
		printf("|%d|->",q->data);
	}
	printf("NULL");
	printf("\n\nEnter the number of nodes in the second list:");
	scanf("%d",&m);
	printf("\nEnter the data in sorted order :\n\n");

	for(i=1;i<=m;i++){
		p=(node*)malloc(sizeof(node));
		printf("\nEnter the data:");
		scanf("%d",&p->data);
		p->next=NULL;
		if(head2==NULL){
			head2=p;
		}
		else{
			q=head2;
			while(q->next!=NULL){
				q=q->next;
			}
			q->next=p;

		}
	}
	printf("\nThe second list is:\n");
	for(q=head2;q!=NULL;q=q->next){
		printf("|%d|->",q->data);
	}
	printf("NULL");
	p=head1;
	q=head2;
	while(p!=NULL&&q!=NULL){
	    r=(node*)malloc(sizeof(node));
	    r->next=NULL;
		if(p->data<q->data){
			r->data=p->data;
			p=p->next;
		}
		else{
			r->data=q->data;
			q=q->next;
		}
		if(head3==NULL){
			head3=r;
		}
		else{
			k=head3;
			while(k->next!=NULL){
				k=k->next;
			}
			k->next=r;

		}


	}
	while(p!=NULL){
	    r=(node*)malloc(sizeof(node));
	    r->next=NULL;
		r->data=p->data;
		p=p->next;
		k=head3;
        while(k->next!=NULL){
				k=k->next;
        }
        k->next=r;
	}
	while(q!=NULL){
		r=(node*)malloc(sizeof(node));
		r->next=NULL;
		r->data=q->data;
		q=q->next;
		k=head3;
        while(k->next!=NULL){
				k=k->next;
        }
        k->next=r;

	}
	printf("\n\nThe merged list is:\n");
	for(q=head3;q!=NULL;q=q->next){
		printf("|%d|->",q->data);
	}
	printf("NULL");
}
