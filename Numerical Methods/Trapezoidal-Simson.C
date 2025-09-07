#include <stdio.h> // Lower=0,Upper=1,Intervals=4
#include <math.h>

float equation(float x);

int main(){
  int i, n;
  float y0 = 0, y1 = 0, y2 = 0;
  float a, b, h, x, Is, It;

  printf("Enter the lower bound: ");
  scanf("%f", &a);
  printf("Enter the upper bound: ");
  scanf("%f", &b);
  printf("Enter the intervals: ");
  scanf("%d", &n);

  h = (b-a) / n;
  x = a;
  printf("Interval Width(h): %.3f\n",h);

  printf("\n\tXi\t\tYi=f(Xi)\t\tY0\t\tY1\t\tY2\n");
  for (i = 0; i <= n; i++, x += h){
    float t = equation(x);

    if (i == 0 || i == n){  // Addition of first and Last
      y0 = y0 + t;
      printf("x[%d]=%.3f\t\ty[%d]=%.3f\t\t%.3f\t\t--\t\t--\n", i, x, i, t, t);
    }
    else if (i % 2 == 0){   // Addition of Odds
      y2 = y2 + t;
      printf("x[%d]=%.3f\t\ty[%d]=%.3f\t\t--\t\t--\t\t%.3f\n", i, x, i, t, t);
    }
    else{  // Addition of Evens
      y1 = y1 + t;
      printf("x[%d]=%.3f\t\ty[%d]=%.3f\t\t--\t\t%.3f\t\t--\n", i, x, i, t, t);
    }
  }

  // Simpson's 1/3 Rule
  Is = (h / 3) * (y0 + 4 * y1 + 2 * y2);
  printf("\nThe integral using Simpson 1/3 method is = %.3f", Is);

  // Trapezoidal Rule
  It = (h / 2) * (y0 + 2 * (y1 + y2));
  printf("\nThe integral using Trapezoidal method is = %.3f\n", It);

  return 0;
}

float equation(float x){
  return (4 * x) - (3 * x * x);
}
