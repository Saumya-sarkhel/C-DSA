
//Split elements in odd and even with respect to array index position
#include <stdio.h>

void print_odd_even_positions(int arr[], int n){
    printf("Odd positions: ");
    for (int i = 0; i < n; i += 2) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Even positions: ");
    for (int i = 1; i < n; i += 2) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    print_odd_even_positions(arr, n);
    return 0;
}
