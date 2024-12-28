
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


//---------------------------------------------------


// #include<stdio.h>
// int binarySearch(int *,int ,int,int);

// int main(){
// 	int arr[50],n,key,i,j,t,index,u,l,mid,flag;
// 	printf("Enter the total no of elements:");
// 	scanf("%d",&n);
// 	if(n>0){
// 		printf("Enter the data of the array:\n");
// 		for(i=0;i<n;i++)
// 			scanf("%d",&arr[i]);

// 		for(i=0;i<(n-1);i++){
// 			flag=0;
// 			for(j=0;j<(n-i-1);j++){
// 				if(arr[j]>arr[j+1]){
// 					t=arr[j];
// 					arr[j]=arr[j+1];
// 					arr[j+1]=t;
// 					flag=1;
// 				}
// 			}
// 			if(flag==0)
// 				break;
// 		}
// 		printf("\nSorted data are: \n");
// 		for(i=0;i<n;i++)
// 			printf("%d\n",arr[i]);
// 		printf("Enter the value that you want to search:");
// 		scanf("%d",&key);
// 		index=binarySearch(arr,0,n-1,key);
// 		if(index!=-1)
// 			printf("%d is found at position:%d",key,index);
// 		else
// 			printf("%d not found",key);
// 	}
// 	else
// 		printf("Invalid size of the array!\n");
// 	return 0;
// }

// int binarySearch(int *a,int l,int u,int key){
// 	if(l>u){
// 		return -1;
// 	}
// 	else{
// 		int mid=(l+u)/2;
// 		if(a[mid]==key){
// 			return mid;
// 		}
// 		else if(key>a[mid]){
// 			return (binarySearch(a,mid+1,u,key));
// 		}
// 		else{
// 			return (binarySearch(a,l,mid-1,key));
// 		}
// 	}
// }
