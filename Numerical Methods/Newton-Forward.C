// sample input
// x=1891,1901,1911,1921,1931
// y=46,66,81,93,101
// find 1895?

#include <stdio.h>
int main(){
    int n;
    float x;
    printf("Enter the nuber of N:");
    scanf("%d", &n);
    float a[50][50];
    int i;
    printf("Enter the value of X Column:\n");
    for (i=0; i<n; i++)
    {
        printf("X[%d]=", i);
        scanf("%f", &a[i][0]);
    }
    printf("Enter the value of Y Column:\n");
    for (i=0; i<n; i++)
    {
        printf("Y[%d]=", i);
        scanf("%f", &a[i][1]);
    }
    printf("Value at X=");
    scanf("%f", &x);
    // calculate te difference table
    int j;
    for (j=2; j<n+1; j++)
    {
        for (i=0; i<n-j+1; i++)
        {
            a[i][j] = a[i+1][j-1] - a[i][j-1];
        }
    }

    // calculate the inistial value of u,y,and fact to use in the formula
    float u = (x - a[0][0]) / (a[1][0] - a[0][0]);
    float u1 = u;
    float fact = 1.0;
    float y = a[0][1];
    for (i=2; i<n+1; i++)
    {
        y = y + ((u1 * a[0][i]) / fact);
        fact = fact * i;
        u1 = u1 * (u - (i - 1));
    }
    printf("Value at X=(%.2f)=%.4f", x, y);
}
