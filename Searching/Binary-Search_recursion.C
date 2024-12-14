
#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int a[], int n) {
    if (n == 1)
        return;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
            swap(&a[i], &a[i + 1]);
        }
    }
    bubbleSort(a, n - 1);
}

int binarySearch(int *a, int l, int u, int key){
    if(l>u){
        return -1;
    }
    else {
        int mid =(l+u)/2;
        if(a[mid]==key){
            return mid;
        }
        else if(key > a[mid]){
            return (binarySearch(a, mid+1, u, key));
        }
        else {
            return (binarySearch(a, l, mid-1, key));
        }
    }
}

int main() {
    int n, key;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    bubbleSort(a, n);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\nEnter the key to search: ");
    scanf("%d", &key);
    int result = binarySearch(a, 0, n - 1, key);
    if (result == -1) {
        printf("Key not found.");
    } else {
        printf("Key found at position %d.", result + 1);
    }
    return 0;
}
