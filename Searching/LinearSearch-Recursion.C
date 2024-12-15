
#include<stdio.h>
#include <stdlib.h>

int linearsearch(int a[], int n, int key){
    if(n==0){
        return -1;
    }
    else{
        if(a[n-1]==key){
            return n-1;
        }
        else{
            return linearsearch(a, n-1, key);
        }
    }
}

int main(){
    int i, j, n, key, index;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int a[20];
    for(i=0; i<n; i++){
        printf("Enter data: ");
        scanf("%d", &a[i]);
    }
    printf("Enter the searching value: ");
    scanf("%d", &key);
    index = linearsearch(a, n, key);
    if(index!=-1){
        printf("Element found at index %d\n", index);
    }
    else{
        printf("Element not found\n");
    }
}
