
#include<stdio.h>

int linearSearch(int*, int, int, int);

int main(){
	int arr[50],n,i,key,flag;
	printf("Enter the total no of elements:");
	scanf("%d",&n);
	if(n>0){
		printf("Enter the data of the array:\n");
		for(i=0;i<n;i++)
			scanf("%d",&arr[i]);

		printf("Enter the value that you want to search:");
		scanf("%d",&key);

		flag=linearSearch(arr,0,n-1,key);

		if(flag==-1)
			printf("Key not found\n");
		else
            printf("Key found at position:%d", flag+1);
	}
	else
		printf("Invalid size of the array!");

	return 0;
}

int linearSearch(int arr[], int l, int u, int key){
	if(l<=u){
		if(arr[l]==key)
			return l;
		else{
			l=l+1;
			return linearSearch(arr,l,u,key);
		}
	}
	else
		return -1;
}
