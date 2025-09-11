#include<stdio.h>
#include<conio.h>
#include<math.h>
// Euler Modified Method
float eqsn(float x,float y){
    float s;
    s=x+y;
    return(s);
}

int main(){
    int i,c;
    float b,d,x,y,h,q,delta;
    printf("Enter the step length : ");
    scanf("%f",&h);
    printf("\nEnter the starting value of x : ");
    scanf("%f",&x);
    printf("\nEnter the starting value of y : ");
    scanf("%f",&y);
    printf("\nEnter the value of x that to be find : ");
    scanf("%f",&q);

    for(;x<q;x=x+h){
        d=y+(h * eqsn(x,y));
        printf("y(%f)(0) = %.4f",x+h,d);
        for(i=1,c=0;c==0;i++){
            b=y+((h/2) * (eqsn(x,y) + eqsn(x+h,d)));

            printf("\ny(%f)(%d) = %.4f",x+h,i,b);
            delta=fabs(b-d);
            if(delta<(0.0001))
                c=1;
            else
                d=b;
        }
        y=b;
        printf("\ny(%f)(%d)=%.4f\n\n",x+h,i,y);
    }
}
