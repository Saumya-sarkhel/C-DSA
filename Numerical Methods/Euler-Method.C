#include <stdio.h>
#include <math.h>
// Euler Method

// Function for dy/dx = f(x,y)
float equation(float x, float y) {
    return (y - x) / (y + x);
}

int main() {
    // Given x=0, y=2, h=0.2, q=0.8
    float x, y, h, q;

    printf("Enter the value of x: ");
    scanf("%f", &x);

    printf("Enter the value of y: ");
    scanf("%f", &y);

    printf("Enter the step length (h): ");
    scanf("%f", &h);

    printf("Enter the finding value q: ");
    scanf("%f", &q);

	/* Now x = 0.8000000000000002, q = 0.8, q - 1e-6 = 0.799999.
    Condition:
	0.8000000000000002 < 0.799999 ? False ? Loop stops.?
    Even though x is slightly above 0.8, tolerance makes sure we stop correctly at the target. ?
	small tolerance to avoid floating error */

    while (x < q - 1e-6){
        y = y + h * equation(x, y);
        x = x + h;
    }

    printf("The value of y(%.2f) = %.6f\n", q, y);
    return 0;
}
