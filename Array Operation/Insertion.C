
#include <stdio.h>
#include <stdlib.h> //Insert elements in any position

int main(){
	int n, i, value;
    int *arr, index;
    printf("Enter number of element: ");
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));
	  printf("Enter your data: \n");
	  for(i=0; i<n; i++){
      scanf("%d", &arr[i]);
    }
    printf("Enter index value: ");
    scanf("%d", &index);
	  printf("Enter value to insert: ");
	  scanf("%d", &value);
    for (i= n-1; i>=index; i--){
      arr[i+1] = arr[i];
    }
    arr[index] = value;
    n++;
    for(i=0; i<n; i++){
      printf("%d ", arr[i]);
    }
    free(arr);
}