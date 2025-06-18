#include <math.h>
#include <stdio.h> // x3-9x+1

float equation(float);
int main() {
  int l = 1;
  float xn = 0, xn1 = 0;
  float k, delta = 1, a, b, i;
  printf("Enter the Lower and Upper bound: ");
  scanf("%f%f", &a, &b);

  // for(i=0,a=-1,b=-1; a==-1 || b==-1; i++){
  //   printf("%f %f", a,b);   //Find root manually if boundary is not given
  //   k=equation(i);
  //   printf("%f\n",k);
  //   if(k<0){
  //     a=i;
  //   }else{
  //     b=i;
  //   }
  // }

  printf("The root lies between %f and %f\n", a, b);
  printf("Steps\t f(a)<0\t f(b)>0\t xn1=(a+b)/2\t (xn1)\n\n");
  while (delta >= 0.001) {
    xn = xn1;
    xn1 = (a + b) / 2;
    k = equation(xn1);
    printf("%d\t %.3f\t %.3f\t %f\t %.3f\n", l, a, b, xn1, k);
    if (k < 0) {
      a = xn1;
    } else {
      b = xn1;
    }
    delta = fabs(xn1 - xn);
    l++;
  }
  printf("\nThe root is xn1 = %.2f", xn1);
}
float equation(float x) {
  float a;
  a = (x * x * x) - (9 * x) + 1; // 2 and 3
  return a;
}
