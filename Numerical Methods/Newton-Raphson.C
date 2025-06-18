#include<stdio.h>
#include<math.h>  // x3-8x-4

float function(float);
float derivative(float);
int main(){
  int l=0;
  float x0, f0, df0;
  float k, x1=0, xn1=0, hn, delta=1;
  float a, b, i;
  printf("Enter the Lower and Upper bound: ");
  scanf("%f%f", &a,&b);

  // for(i=0,a=-1,b=-1; a==-1 || b==-1; i++){
  //   printf("%f %f", a,b);   //Find root manually
  //   k=function(i);
  //   printf("%f\n",k);
  //   if(k<0){
  //     a=i;
  //   }else{
  //     b=i;
  //   }
  // }

  printf("The root lies between %.2f and %.2f\n", a,b);
  printf("Steps\tx(n)\tf(Xn)\tf`(Xn)\thn=-f(x)/f`(x)\t(xn1)\n\n");

  if(a<b) // storing the lower bound in a variable
    x0=a;
  else
    x0=b;
  while (delta >= 0.0001){
    f0 = function(x0);  // calculating the value of equation
    df0 = derivative(x0); // Calculating the value of the derivative
    hn = -f0/df0;     // Calculating the value of Hn
    x1 = x0 + hn;   // Set the value of X1 adding original value and Hn
    delta = fabs(x1-x0);
    // Printing the values
    printf("%d\t%.4f\t%.4f\t%.4f\t  %.5f\t%.5f\n", l, x0, f0, df0, x1, delta);
    x0 = x1;
    l++;
  }
  printf("\nThe root is x = %.4f\n", x1);
  return 0;
}

float derivative(float x){
  float a;  // value of Function
  a = (3 * x * x) - 8;
  return a;
}

float function(float x){
  float a;  // Value of derivative of the function
  a = (x * x * x) - (8 * x) - 4; //3 and 4
  return a;
}
