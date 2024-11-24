
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j, count=0, t;
    int *a;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    a = (int *)malloc(n * sizeof(int));
    printf("Enter the data:\n");
    for (i = 0; i < n; i++) {
        printf("\ndata for a[%d]: ", i);
        scanf("%d", &a[i]);
    }

    for(i=0; i<n-1; i++){ //Sort the array
    for(j=0; j<(n-i-1); j++){ 
      if(a[j] > a[j+1]){
        t = a[j];
        a[j] = a[j+1];
        a[j+1] = t;
      }
    }
  }

    for(i=0; i<n; i++){
        count = 1;
        while(a[i] == a[i + 1]) {
            count++;
            i++;
        }
        printf("%d occurred %d times\n", a[i], count);
      }
    free(a);
    return 0;
}