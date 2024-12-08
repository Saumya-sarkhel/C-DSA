
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
