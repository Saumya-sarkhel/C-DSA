#include <stdio.h>
#include <stdlib.h>

void guasselimination(float **, int, float *);
void display(float **, int);

int main() {
  int n, i, j;
  float **a, *x;
  // Input the number of equations
  printf("Enter the number of equations: ");
  scanf("%d", &n);
  // Dynamic memory allocation for augmented matrix and solution vector
  a = (float **)malloc(n * sizeof(float *));

  for (i = 0; i < n; i++) {
    a[i] = (float *)malloc((n + 1) * sizeof(float));
  }
  x = (float *)malloc(n * sizeof(float));

  // Input the augmented matrix
  printf("Enter the matrix elements:\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n + 1; j++) {
      printf("a[%d][%d]= ", i, j);
      scanf("%f", &a[i][j]);
      // Check for zero diagonal element during input
      if (i == j) {
        if (a[i][j] == 0) {
          printf("\nError: The diagonal element must be non-zero\n");
          exit(1);
        }
      }
    }
  }
  // Print the initial matrix
  printf("\nInitial Matrix\n");
  display(a, n);

  // Forward elimination to convert matrix to upper triangular form
  int k;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (j > i) {
        // Calculate the multiplier for current row
        float c = a[j][i] / a[i][i];
        for (k = 0; k < n + 1; k++) {
          a[j][k] = a[j][k] - c * a[i][k];
        }
      }
    }
  }
  printf("After row operations(Upper Triangular matrix):\n");
  display(a, n);

  // Back substitution to find the solution vector
  guasselimination(a, n, x);

  // Display the solution
  printf("Solution\n");
  for (i = 0; i < n; i++) {
    // printf("x%d=%.3f\n",i+1,x[i]);
    printf("\n%c = %.2f", i + 120, x[i]); // x y z
  }

  // Free allocated memory
  for (i = 0; i < n; i++)
    free(a[i]);
  free(a);
  free(x);
  return 0;
}

// Function to perform back substitution after forward elimination
void guasselimination(float **a, int n, float *x) {
  int i, j;
  x[n - 1] = a[n - 1][n] / a[n - 1][n - 1];

  for (i = n - 2; i >= 0; i--) {
    float sum = 0.0;
    for (j = i + 1; j < n; j++) { // Calculate the sum of known variables
      sum += a[i][j] * x[j];
    }
    // Calculate the value of the current variable
    x[i] = (a[i][n] - sum) / a[i][i];
  }
}
// Function to display the matrix
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
