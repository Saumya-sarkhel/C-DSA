
#include<stdio.h>
#include<stdlib.h>

struct poly {
	int coef, exp;
};

void insert_pol(poly a[], int *n) {
	printf("Enter the number of terms in eq: ");
	scanf("%d", n);
    for (int i=0; i<*n; i++) {
      printf("Enter coefficient %d: ",i+1);
      scanf("%d", &a[i].coef);
      printf("Enter exponent %d: ",i+1);
      scanf("%d", &a[i].exp);
    }
}

void display_pol(poly a[], int n){
    for (int i=0; i<n; i++) {
      printf("%dx^%d", a[i].coef, a[i].exp);
      if (i != n-1) {
        printf(" + ");
      }
    }
    printf("\n");
}


int main(){
	poly a[20], b[20], c[20];
	int n1, n2, n3;

	printf("Enter first polinomial: \n");
	insert_pol(a, &n1);
	printf("Enter second polinomial:\n");
	insert_pol(b, &n2);

	printf("First Polinomial is: \n");
	display_pol(a, n1);
	printf("Second Polinomial is: \n");
	display_pol(b, n2);

	int i, j, k;
	for(i=0; i<n1; i++){
		for(j=0; j<n2; j++){
			int flag=0;
			for(k=0; k<n3; k++){
				if(c[k].exp == a[i].exp + b[j].exp){
					c[k].coef += a[i].coef * b[j].coef;
					flag = 1;
					break;
				}
			}
			if(!flag){
			c[n3].coef = a[i].coef * b[j].coef;
			c[n3].exp = a[i].exp + b[j].exp;
			n3++;
		}
		}
	}
	printf("Result polinomial is: \n");
	display_pol(c, n3);
	return 0;
}





// #include<stdio.h>     // Method 2
// #include<stdlib.h>

// struct Polynomial{
// 	int cof,exp;
// };
// typedef struct Polynomial Pol;

// void getPolynomial(Pol*, int);
// void display(Pol*, int);

// int main(){
// 	Pol a[10],b[10],c[20];
// 	int n,m,i,j,k,flag;
// 	printf("\nEnter the no of term for 1st pol: ");
// 	scanf("%d",&n);
// 	printf("\nEnter the number of term for 2nd pol: ");
// 	scanf("%d",&m);
// 	printf("\nEnter the 1st polynomial:");
// 	getPolynomial(a,n);
// 	printf("\nEnter the 2nd polynomial :");
// 	getPolynomial(b,m);
// 	printf("\n1st Polynomial is : ");
// 	display(a,n);
// 	printf("\n2nd Polynomial is : ");
// 	display(b,m);
// 	k=0;
// 	for(i=0;i<n;i++){
// 		for(j=0;j<m;j++,k++){
// 			c[k].cof=a[i].cof*b[j].cof;
// 			c[k].exp=a[i].exp+b[j].exp;
// 		}
// 	}
// 	printf("\nPolynomial Multiplication is: ");
// 	display(c,k);
// }

// void getPolynomial(Pol a[],int n){
// 	int i;
// 	for(i=0;i<n;i++){
// 		printf("\nEnter coefficient :");
// 		scanf("%d",&a[i].cof);
// 		printf("\nEnter the exponent :");
// 		scanf("%d",&a[i].exp);
// 	}
// }

// void display(Pol a[],int n){
// 	int i;
// 	for(i=0;i<n;i++){
// 		if(a[i].exp==0)
// 			printf("( %d )",a[i].cof);
// 		else if(i==(n-1))
// 			printf("(%d)X^%d  ",a[i].cof,a[i].exp);
// 		else
// 			printf("(%d) X^%d + ",a[i].cof,a[i].exp);
// 	}
// }
