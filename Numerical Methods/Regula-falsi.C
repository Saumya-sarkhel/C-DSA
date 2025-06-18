#include <math.h>
#include <stdio.h>

float function(float);

int main() {
  int l = 0;
  float xn = 0, xn1 = 0, hn, f2;
  float delta = 1;  // Start with delta > 0.001 to enter loop
  float fa, fb;
  float a, b, k;
  float i;

  printf("Enter Lower and Upper bound: ");
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

  for(i=0; a==-1 || b==-1; i++){
    k=function(i);
    if(k<0 && a==-1){
      a=i;
    }
    else if(k>0 && b==-1){
      b=i;
    }
  }

  printf("So the root lies between %.2f and %.2f\n", a, b);
  printf("Steps\t a(n)\t b(n)\t f(a)\t f(b)\t h(n)\t xn1\t f(xn1)\n\n");

  while (delta >= 0.001) {
    xn = xn1;
    fa = function(a);
    fb = function(b);
    hn = (fabs(fa) * fabs(b - a)) / (fabs(fa) + fabs(fb));
    xn1 = a + hn;
    f2 = function(xn1);
    printf("%d\t %.3f\t %.3f\t %.3f\t %.3f\t %.3f\t %.3f\t %.3f\n", l, a, b, fa, fb, hn, xn1, f2);
    if(f2 < 0){
      a = xn1;
    } else {
      b = xn1;
    }
    delta = fabs(xn1 - xn);
    l++;
  }

  printf("\nThe root is approximately x = %.3f\n", xn1);
  return 0;
}

float function(float x) {
  float a;
  a = (x * x * x) + (2 * x) - 2; // 0 and 1
  return a;
}
