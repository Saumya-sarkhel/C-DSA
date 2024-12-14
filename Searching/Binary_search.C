
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *a, n, i, j, t, key, flag = 0, mid;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    a = (int *)malloc(n * sizeof(int));

    int l = 0;
    int u = n - 1;
    for (i = 0; i < n; i++){
        printf("Enter data: ");
        scanf("%d", &a[i]);
    }
    printf("Enter the searching value: ");
    scanf("%d", &key);
    for (i = 0; i < n - 1; i++){ // Bubble Sort
        for (j = 0; j < (n - i - 1); j++){
            if (a[j] > a[j + 1]){
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
    printf("Sorted array is: ");
    for (i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    printf("\n\n");
    while (l <= u){
        mid = (l + u) / 2;
        if (a[mid] == key){
            flag = 1;
            break;
        }
        if (key > a[mid]){
            l = mid + 1;
        }
        else{
            u = mid - 1;
        }
    }
    if (flag == 1){
        printf("%d is found at position %d", key, mid);
    }
    else{
        printf("%d(key) not found.\n", key);
    }
    free(a);
    return 0;
}
