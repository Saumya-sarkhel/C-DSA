
#include<stdio.h>

void splitarray(int arr[], int size, int oddarr[], int evenarr[], int *odd, int *even){
    int i;
    *odd =0;
    *even =0;
    for(i=0;i<size;i++){
        if(arr[i]%2==0){
            evenarr[*even] = arr[i];
            (*even)++;
        }
        else{
            oddarr[*odd] = arr[i];
            (*odd)++;
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
    int arr1[20], evenarr[20], oddarr[20];
    int size, odd, even, i;
    printf("Enter the maxsize of array: ");
    scanf("%d", &size);
    printf("Enter %d number of elements: ", size);
    for(i=0; i<size; i++){
        scanf("%d", &arr1[i]);
    }
    splitarray(arr1, size, oddarr, evenarr, &odd, &even);
    printf("Original array is: \n");
    printlist(arr1, size);

    printf("Odd array: ");
    printlist(oddarr, odd);

    printf("Even array: ");
    printlist(evenarr, even);
    return 0;
}
