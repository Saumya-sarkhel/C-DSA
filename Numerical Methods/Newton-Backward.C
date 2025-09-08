#include <stdio.h>

int main(){
    int n, i, j;
    float x;
    printf("Enter the number of points: ");
    scanf("%d", &n);

    float a[100][100];
    printf("Enter the values of X column:\n");
    for (i = 0; i < n; i++)
    {
        printf("X[%d] = ", i);
        scanf("%f", &a[i][0]);
    }

    printf("Enter the values of Y column:\n");
    for (i = 0; i < n; i++)
    {
        printf("Y[%d] = ", i);
        scanf("%f", &a[i][1]);
    }

    printf("Enter the value of x to find: ");
    scanf("%f", &x);

    // Construct backward difference table
    for (j = 2; j <= n; j++)
{
        for (i = n - 1; i >= j - 1; i--)
        {
            a[i][j] = a[i][j - 1] - a[i - 1][j - 1];
        }
    }

    // Newton Backward Interpolation
    float u = (x - a[n - 1][0]) / (a[1][0] - a[0][0]);
    float y = a[n - 1][1];
    float u1 = u;
    float fact = 1.0;
    j = 2;

    for (i = n - 2; i >= 0; i--){
        y = y + (u1 * a[i][j]) / fact;
        fact = fact * j;
        u1 = u1 * (u + (j - 1));
        j++;
    }

    printf("The final result of f(%.2f) = %.4f\n", x, y);
    return 0;
}
