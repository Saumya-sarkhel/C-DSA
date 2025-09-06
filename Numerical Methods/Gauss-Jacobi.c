#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void display(float **, int);
void diagonallydominent(float **, int);
int isDiagonallyDominant(float **, int);
void GaussJacobi(float **, float *, int);

int main() {
    int n, i, j;
    float **a, *x;
    printf("Enter the number of equation: ");
    scanf("%d", &n);

    a = (float **)malloc(n * sizeof(float *));
    for (i = 0; i < n; i++) {
        a[i] = (float *)malloc((n + 1) * sizeof(float));
    }
    x = (float *)calloc(n, sizeof(float));

    printf("Enter the augmented matrix :\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n + 1; j++) {
            printf("a[%d][%d]= ", i, j);
            scanf("%f", &a[i][j]);
        }
    }
    printf("\nInitial Matrix\n");
    display(a, n);

    if (isDiagonallyDominant(a, n)) {
        printf("The matrix is already diagonally dominant\n");
    } else {
        diagonallydominent(a, n);
        printf("After making the matrix diagonally dominant:\n");
        display(a, n);
    }
    GaussJacobi(a, x, n);
    for (i = 0; i < n; i++)
        free(a[i]);
    free(a);
    free(x);
    return 0;
}

void diagonallydominent(float **x, int n) {
    int i, j, k;
    for (i = 0; i < n; i++) {
        int max = i;
        float maxVal = fabs(x[i][i]);
        for (j = i + 1; j < n; j++) {
            if (fabs(x[j][i]) > maxVal) {
                maxVal = fabs(x[j][i]);
                max = j;
            }
        }
        if (max != i) {
            float *temp = x[i];
            x[i] = x[max];
            x[max] = temp;
        }
    }
}

int isDiagonallyDominant(float **x, int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        float sum = 0.0;
        for (j = 0; j < n; j++) {
            if (i != j)
                sum += fabs(x[i][j]);
        }
        if (fabs(x[i][i]) < sum)
            return 0;
    }
    return 1;
}

void GaussJacobi(float **a, float *x, int n) {
    float *prev = (float *)malloc(n * sizeof(float));
    int i, j, iter = 0;
    float diff, final;

    for (i = 0; i < n; i++)
        x[i] = 0.0;

    while (1) {
        iter++;
        for (i = 0; i < n; i++)
            prev[i] = x[i];

        for (i = 0; i < n; i++) {
            float sum = a[i][n];
            for (j = 0; j < n; j++) {
                if (j != i)
                    sum -= a[i][j] * prev[j];
            }
            x[i] = sum / a[i][i];
        }

        final = 0.0;
        for (i = 0; i < n; i++) {
            diff = fabs(x[i] - prev[i]);
            if (diff > final)
                final = diff;
        }
        if (final <= 0.001)
            break;
    }
    printf("\nSolution after %d iterations:\n", iter);
    for (i = 0; i < n; i++)
        printf("x%d = %.4f\n", i + 1, x[i]);

    free(prev);
}

void display(float **a, int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j <= n; j++) {
            printf("%.2f\t", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
