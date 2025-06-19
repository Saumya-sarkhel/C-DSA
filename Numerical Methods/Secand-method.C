#include<stdio.h>
#include<math.h>

float function(float);

int main(){
  int l=0;
  float a, b, k;
  float xn=0, xn1=0, delta=1;
  float fxn, fxn1;
  float i;

  printf("Enter the Lower and Upper bound: ");
  scanf("%f%f", &a, &b);

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

  for(i=0; a==-1||b==-1; i++){
    k=function(i);
    if(k<0){
      a=i;
    }
    else if(k>0){
      b=i;
    }
  }
  printf("So the root lies between %.2f and %.2f\n", a, b);
  printf("Steps\tXn-1\t\tXn\t\tF(Xn-1)\t\tF(Xn)\t\t Xn+1\n\n");

  xn1=a; // xn
  xn=b; // xn-1
  while(delta >= 0.001){
    fxn1 = function(xn1); // xn
    fxn = function(xn); // xn-1
    float temp = xn1;
    xn1 = xn1 - (fxn1 * (xn1 - xn))/(fxn1 - fxn);
    printf("%d\t%.3f\t\t%.3f\t\t%.3f\t\t%.3f\t\t%.3f\n", l, xn, temp, fxn, fxn1, xn1);
    delta=fabs(xn1-xn);
    xn = temp;
    l++;
  }
  printf("\nThe root is approximately x = %.3f\n", xn1);
  return 0;
}

float function(float x){
  float a;
  a = x * exp(x) - 1; // 0 and 1
  return a;
}
