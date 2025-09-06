#include <stdio.h>
#include <math.h>

float f(float x, float y) {
    return (x * x) - y;
}

int main() {
    float x, y, q, h;
    float k1, k2, k3, k4;

    printf("Enter initial values for x and y: ");
    scanf("%f %f", &x, &y);
    printf("Enter the value of x for which y is required (q): ");
    scanf("%f", &q);
    printf("Enter the step size h: ");
    scanf("%f", &h);

    printf("\nSteps:\n");
    printf("x\t\ty\n");

    while (x < q) {
        printf("%.4f\t%.4f\n", x, y);

        k1 = h * f(x, y);
        k2 = h * f(x + h / 2.0f, y + k1 / 2.0f);
        k3 = h * f(x + h / 2.0f, y + k2 / 2.0f);
        k4 = h * f(x + h, y + k3);

        y = y + (1.0f / 6.0f) * (k1 + 2 * k2 + 2 * k3 + k4);

        x = x + h;
    }

    printf("%.4f\t%.4f\n", x, y);

    printf("\nFinal approximate solution at x = %.2f is y = %.4f\n", q, y);

    return 0;
}
