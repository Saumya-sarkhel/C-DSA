
#include <stdio.h> //Bubble Sort Increasing order
                    // Best Time complexity - O(n) // Avg & worst - O(n^2)
int main() {

  int a[20], i, j, flag, n;
  printf("Enter the number of data: ");
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    printf("Enter data: ");
    scanf("%d", &a[i]);
  }
  for (i = 0; i < n - 1; i++) {
    int flag = 0;
    for (j = 0; j < (n - i - 1); j++) {
      if (a[j] > a[j + 1]) {
        int t;
        t = a[j];
        a[j] = a[j + 1];
        a[j + 1] = t;
        flag = 1;
      }
    }
    if (flag == 0) {
      break;
    }
  }
  printf("Sorted data in increasing order: ");
  for (i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
  return 0;
}

//-----------------------------------------

// #include<stdio.h>  //Bubble Sort  Decresing order

// int main(){

//   int a[20],i,j, flag, n;
//   printf("Enter the number of data: ");
//   scanf("%d", &n);
//   for(i=0; i<n; i++){
//     printf("Enter data: ");
//     scanf("%d", &a[i]);
//   }

//   for(i=0; i<n-1; i++){
//     int flag=0;

//     for(j=0; j<(n-i-1); j++){
//       if(a[j] < a[j+1]){
//         int t;
//         t = a[j];
//         a[j] = a[j+1];
//         a[j+1] = t;
//         flag = 1;
//       }
//     }

//     if(flag == 0){
//       break;
//     }
//   }
//     printf("Sorted data in Decreasing order: ");
//     for (i=0; i<n; i++){
//         printf("%d ", a[i]);
//     }
//   printf("\n");
//   return 0;
// }

//----------------------------------------------

#include <stdio.h> //Mathod 2 using Functionand Malloc
#include <stdlib.h>

void printArray(int arr[], int);
void bubblesort(int arr[], int);

int main() {
  int n, *arr;
  printf("Enter the number of elements: ");
  scanf("%d", &n);

  arr = (int *)malloc(n * sizeof(int));

  printf("Enter %d integers:\n", n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  printf("Original array: \n");
  printArray(arr, n);

  bubblesort(arr, n);

  printf("Sorted array: \n");
  printArray(arr, n);
  free(arr);

  return 0;
}

void printArray(int arr[], int size) {
  int i;
  for (i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void bubblesort(int arr[], int n) {
  int i, j, mid, temp;
  for (i = 0; i < n - 1; i++) {
    int flag = 0;

    for (j = 0; j < (n - i - 1); j++) {
      if (arr[j] > arr[j + 1]) {
        int t;
        t = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = t;
        flag = 1;
      }
    }
  }
}
