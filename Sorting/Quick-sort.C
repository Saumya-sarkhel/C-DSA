
#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], int size);
void Quicksort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void swap(int *a, int *b);

int main() {
    int n, *arr;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    printf("Enter %d integers:\n", n);
    for (int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Original array is: \n");
    printArray(arr, n);
    Quicksort(arr, 0, n - 1);
    printf("Sorted array is: \n");
    printArray(arr, n);
    free(arr);

    return 0;
}

void Quicksort(int arr[], int low, int high) {
    if (low < high) {
        int q = partition(arr, low, high);
        Quicksort(arr, low, q - 1);
        Quicksort(arr, q + 1, high);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j) {
        while (arr[i] <= pivot && i <= high - 1) {
            i++;
        }
        while (arr[j] > pivot && j >= low + 1) {
            j--;
        }
        if (i < j) {
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[low], &arr[j]);
    return j;
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
