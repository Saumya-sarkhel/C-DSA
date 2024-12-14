
#include<stdio.h>
void merge(int n1, int n2, int arr1[], int arr2[], int c[]){
    int i=0, j=0, k=0;
    int merged_array[n1 + n2];


    for(i=0; i<n1+n2; i++){
        while (i < n1 && j < n2) {
            if (arr1[i] < arr2[j]) {
                c[k] = arr1[i];
                k++;
                i++;
            }
            else {
                c[k] = arr2[j];
                k++;
                j++;
            }
        }
        while (i < n1) {
            c[k] = arr1[i];
            i++;
            k++;
        }
        while (j < n2) {
            c[k] = arr2[j];
            k++;
            j++;
        }
    }
}

void printlist(int arr[], int size){
    int i;
    for(i=0;i<size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int n1, n2, arr1[20], arr2[20], c[20];
    printf("Enter the number of elements in first array: ");
    scanf("%d", &n1);
    printf("Enter %d elements in first array(sorted array): \n", n1);
    for(int i=0; i<n1; i++){
        scanf("%d", &arr1[i]);
    }
    printf("Enter the number of elements in second array(sorted array): ");
    scanf("%d", &n2);
    printf("Enter %d elements in second array: \n", n2);
    for(int i=0; i<n2; i++){
        scanf("%d", &arr2[i]);
    }
    printf("First sorted array is: \n");
    printlist(arr1, n1);
    printf("second sorted array is: \n");
    printlist(arr2, n2);
    merge(n1, n2, arr1, arr2, c);
    printf("Merged array is: \n");
    printlist(c, n1+n2);
}
