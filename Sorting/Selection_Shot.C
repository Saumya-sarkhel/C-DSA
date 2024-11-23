
// #include <stdio.h>   //Selection sort Increasing Order

// int main() {
//     int a[20], i, j, n;

//     printf("Enter the number of data: ");
//     scanf("%d", &n);

//     for (i=0; i<n; i++) {
//         printf("Enter data: ");
//         scanf("%d", &a[i]);
//     }

//     for (i=0; i<n-1; i++) {
//         int max = 0; 

//         for (j=0; j<n-i; j++) {
//             if (a[j] > a[max]) { 
//                 max = j; 
//             }
//         }

//         if (max != j-1) {
//             int t = a[max];
//             a[max] = a[j-1];
//             a[j-1] = t;
//         }
//     }

//     printf("Sorted data in increasing order: ");
//     for (i=0; i<n; i++) {
//         printf("%d ", a[i]);
//     }
//     printf("\n");

//     return 0;
// }


//--------------------




// #include <stdio.h>   //Selection sort Decreasing Order

// int main() {
//     int a[20], i, j, n;

//     printf("Enter the number of data: ");
//     scanf("%d", &n);

//     for (i=0; i<n; i++) {
//         printf("Enter data: ");
//         scanf("%d", &a[i]);
//     }

//     for (i=0; i<n-1; i++) {
//         int min = 0; 

//         for (j=0; j<n-i; j++) {
//             if (a[j] < a[min]) { 
//                 min = j; 
//             }
//         }

//         if (min != j-1) {
//             int t = a[min];
//             a[min] = a[j-1];
//             a[j-1] = t;
//         }
//     }

//     printf("Sorted data in Decreasing order: ");
//     for (i=0; i<n; i++) {
//         printf("%d ", a[i]);
//     }
//     printf("\n");

//     return 0;
// }


//---------------------------------------------




#include <stdio.h>  //Mathod 2 using Functionand Malloc
#include <stdlib.h>


void printArray(int arr[], int);
void selectionSort(int arr[], int);


int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original array: \n");
    printArray(arr, n);

    selectionSort(arr, n);

    printf("Sorted array: \n");
    printArray(arr, n);
    free(arr);
    
    return 0;
}

void selectionSort(int arr[], int n) {
    int i, j, mid, temp;

    for (i=0; i<n-1; i++) {
        mid = i;
        for (j=i+1; j<n; j++) {
            if (arr[j] < arr[mid]) {
                mid = j;
            }
        }
        temp = arr[mid];
        arr[mid] = arr[i];
        arr[i] = temp;
    }
}


void printArray(int arr[], int size) {
    int i;
    for (i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}