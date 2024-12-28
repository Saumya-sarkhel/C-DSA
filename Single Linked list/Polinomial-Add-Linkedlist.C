
#include<stdio.h>
#include<malloc.h>
struct node {
    int cof,exp;
    struct node *next;
};
typedef struct node pol;

int main(){
    pol *head1=NULL;	// initialize the header node of 1st polynomial with NULL
    pol *head2=NULL;  	 // initialize the header node of 2nd polynomial with NULL
    pol *head3=NULL;	// initialize the header node of resultant polynomial with NULL
    pol *p=head1,*nw1;
    pol *q=head2,*nw2;
    pol *r=head3,*nw3;

    int i=1,j=1,k=1,n,m,f,t,c,e;
    printf("enter the number of term of 1st polynomial : ");
    scanf("%d",&n);
    printf("enter the number of term of 2nd polynomial : ");
    scanf("%d",&m);
    printf("enter the coefficient and exponent  for pol1:\n");

    for(i=1;i<=n;i++) //entering the 1st polynomial expression
    {

        nw1=(pol*)malloc(sizeof(pol));//dynamically creation of NODE
        printf("enter the coefficient value : ");
        scanf("%d",&nw1->cof);
        printf("enter the exponent value : ");
        scanf("%d",&nw1->exp);
        nw1->next=NULL;
        if(head1==NULL)//checking for 1st NODE
        {
            head1=nw1;

        }
        else{
        	p=head1;
        	while(p->next!=NULL)//finding the last NODE
        	{
				 p=p->next;
            }
            p->next=nw1;

        }

    }

    printf("eneter the coefficient and exponent  for pol2:\n");
    for(j=1;j<=m;j++) 	// //entering the 2nd polynomial expression
    {

        nw1=(pol*)malloc(sizeof(pol));//dynamically creation of NODE
        printf("enter the coefficient value : ");
        scanf("%d",&nw1->cof);
        printf("enter the exponent value : ");
        scanf("%d",&nw1->exp);
        nw1->next=NULL;
        if(head2==NULL)//checking for 1st NODE
        {
            head2=nw1;

        }
        else{
        	p=head2;
        	while(p->next!=NULL)//finding the last NODE
        	{
				 p=p->next;
            }
            p->next=nw1;

        }


    }

    printf("\n1st polynomial is : ");
    for(p=head1;p!=NULL;p=p->next)	//displaying the 1st polynomial expression
    {
		if(p->exp==0)
	    	printf(" (%d)",p->cof);
	    else if(p->next==NULL)
	    	printf(" (%dX^%d)",p->cof,p->exp);
		else
			printf(" (%dX^%d )+",p->cof,p->exp);
    }
    printf("\n2nd polynomial is : ");
    for(q=head2;q!=NULL;q=q->next)	//displaying the 2nd polynomial expression
    {
        if(q->exp==0)
	    	printf(" (%d)",q->cof);
	    else if(q->next==NULL)
	    	printf(" (%dX^%d)",q->cof,q->exp);
		else
			printf(" (%dX^%d )+",q->cof,q->exp);
	}
    printf("\n");
    p=head1;
    q=head2;

    while(p!=NULL&&q!=NULL)	// perform the addition between two given polynomial
    {

        if(p->exp==q->exp) //if the exponent values of two polynomial expression is same
        {
            c=p->cof+q->cof;
            e=p->exp;
            p=p->next;
            q=q->next;
        }
        else if(p->exp>q->exp)//if the exponent values of 1st polynomial expression greater than 2nd polynomial expression
        {
            c=p->cof;
            e=p->exp;
            p=p->next;
        }
        else if(p->exp<q->exp)//if the exponent values of 2nd polynomial expression greater than 1st polynomial expression
        {
            c=q->cof;
            e=q->exp;
            q=q->next;
        }
        nw3=(pol*)malloc(sizeof(pol));//dynamically creation of NODE
        nw3->next=NULL;
        nw3->cof=c;
        nw3->exp=e;
        if(head3==NULL)//checking for 1st NODE
        {
            head3=nw3;

        }
        else{
        	r=head3;
        	while(r->next!=NULL)//finding the last NODE
        	{
				 r=r->next;
            }

            r->next=nw3;

        }

    }
    while(p!=NULL) //if number of term in 1st expression remains and the number of term in the 2nd expression finished
    {

        nw3=(pol*)malloc(sizeof(pol));
        nw3->next=NULL;
        nw3->cof=p->cof;
        nw3->exp=p->exp;
        r=head3;
		while(r->next!=NULL)//finding the last NODE
        {
				 r=r->next;
        }
        r->next=nw3;
        p=p->next;
    }
    while(q!=NULL) //if number of term in 2nd expression remains and the number of term in the 1st expression finished
    {
        nw3=(pol*)malloc(sizeof(pol));//dynamically creation of NODE
        nw3->next=NULL;
        nw3->cof=q->cof;
        nw3->exp=q->exp;
        r=head3;
        while(r->next!=NULL)//finding the last NODE
        {
				 r=r->next;
        }
        r->next=nw3;
    	q=q->next;

    }
    printf("\nthe addition of two polynomial is : ");
    for(r=head3;r!=NULL;r=r->next){
		if(r->cof!=0){

			if(r->exp==0)
		    	printf(" (%d)",r->cof);
		    else if(r->next==NULL)
		    	printf(" (%dX^%d)",r->cof,r->exp);
			else
				printf(" (%dX^%d )+",r->cof,r->exp);
		}
    }
    printf("\n");
}
