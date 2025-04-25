
#include<stdio.h>
struct Polynomial{
	int cof,exp;
};
int main()
{
	struct Polynomial p[10];
	int n,i;
	printf("Enter the Number of Term in Polynomial: \n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the coefficient part of term %d:",(i+1));
		scanf("%d",&p[i].cof);
		printf("Enter the exponent part of term %d:",(i+1));
		scanf("%d",&p[i].exp);
	}
	printf("\nPolynomial is: ");
	for(i=0;i<n;i++)
	{
		if(p[i].exp==0)
			printf("( %d )",p[i].cof);
		else if(i==(n-1))
			printf("(%d)X^%d  ",p[i].cof,p[i].exp);
		else
			printf("(%d)X^%d + ",p[i].cof,p[i].exp);
	}
}
