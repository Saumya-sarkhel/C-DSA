
#include<stdio.h>
struct Polynomial
{
	int coef,exp;
};
typedef struct Polynomial Pol;

void insert_Polynomial(Pol poly[], int *n) {
    for (int i=0; i<*n; i++) {
        printf("Enter coefficient %d: ",i+1);
        scanf("%d", &poly[i].coef);
        printf("Enter exponent %d: ",i+1);
        scanf("%d", &poly[i].exp);
    }
}

void printlist(Pol poly[], int n) {
    for (int i = 0; i < n; i++) {
        if (poly[i].exp == 0){
            printf("%d", poly[i].coef);
        } 
				else if (i==n-1){
            printf("%dX^%d", poly[i].coef, poly[i].exp);
        } 
				else{
            printf("%dX^%d + ", poly[i].coef, poly[i].exp);
        }
    }
    printf("\n");
}

int main(){
	Pol a[10],b[10],c[20];
	int n,m,i,j,k;
	printf("\nenter the no of term for 1st pol: ");
	scanf("%d",&n);
	printf("\nenter the number of term for 2nd pol: ");
	scanf("%d",&m);
	printf("\nenter the 1st polynomial:\n");
	insert_Polynomial(a, &n);

	printf("\nenter the 2nd polynomial :\n");
	insert_Polynomial(b, &m);

	printf("\n1st Polynomial is : \n");
	printlist(a, n);

	printf("\n2nd Polynomial is : \n");
	printlist(b, m);

	i=0;
	j=0;
	k=0;
	while(i<n && j<m){
		if(a[i].exp==b[j].exp){
			c[k].coef=a[i].coef+b[j].coef;
			c[k].exp=a[i].exp;
			i++;
			j++;
		}
		else if(a[i].exp > b[j].exp){
			c[k].coef=a[i].coef;
			c[k].exp=a[i].exp;
			i++;
		} 
		else{
			c[k].coef = b[j].coef;
			c[k].exp=b[j].exp;
			j++;
		}
		k++;
	}
	while(i<n){
		c[k].coef=a[i].coef;
		c[k].exp=a[i].exp;
		i++;
		k++;
	}
	while(j<m){
		c[k].coef=b[j].coef;
		c[k].exp=b[j].exp;
		j++;
		k++;
	}
	printf("\npolynomial addition is: \n");
	for(i=0;i<k;i++){
		if(c[i].exp==0)
			printf("( %d )",c[i].coef);
		else if(i==(k-1))
			printf("( %d )X ^ %d  ",c[i].coef,c[i].exp);
		else
			printf("( %d ) X ^ %d + ",c[i].coef,c[i].exp);
	}
	return 0;
}