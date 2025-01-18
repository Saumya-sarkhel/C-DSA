
#include<stdio.h>
#include<string.h>
#include<math.h>

void push(int *,int);//for pushing elements in the stack
int pop(int *);//for poping elements from the stack
int top=-1;

int main(){
	char a[20],t;
	int k,i,res,m,n,stack[20];
	printf("entering the expression : "); //entering the expression
    scanf("%s",a);
	for(i=0;a[i]!='\0';i++) //checking each characters
	{
		t=a[i];
		if(t>=40&&t<=47||t=='^'||t=='%') //checking for operator
		{
			m=pop(stack);
			n=pop(stack);

			if(t=='+') //if "+" operator is found
				res=n+m;
			else if(t=='*') //if "*" operator is found
				res=n*m;
			else if(t=='/') //if "/" operator is found
				res=n/m;
			else if(t=='-') //if "-" operator is found
				res=n-m;
			else if(t=='^') //if "-" operator is found
				res=pow(n,m);
			else if(t=='%') //if "-" operator is found
				res=n%m;
			push(stack,res);

		}
		else //if operand is found
		{
			push(stack,t-48);

		}

	}
	res=pop(stack);
	printf("\nthe evaluation of the postfix expression %s is : %d ",a,res);//displaying the evaluation result
}

void push(int *stack,int ch){
    top++;//increasing the top pointer of the stack
	stack[top]=ch;
}

int pop(int *stack){
	int c;
	c=stack[top];
	top--;//decreasing the top pointer of the stack
	return(c);
}
