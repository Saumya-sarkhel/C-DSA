
#include<stdio.h>
void mergesort(int [],int,int);
void merge(int [],int,int,int);

int main(){
	int a[25],i,n,beg=0,end;
	printf("enter the number n:");
	scanf("%d",&n);
	printf("enter the array element");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	mergesort(a,0,n-1);
	printf("the sorted element are");
	for(i=0;i<n;i++){
		printf("\na[%d]=%d",i,a[i]);
	}

}

void mergesort(int a[],int beg,int end){
	int mid;
	if(beg<end){
		mid=(beg+end)/2;
		mergesort(a,beg,mid);
		mergesort(a,mid+1,end);
		merge(a,beg,mid,end);
	}
}

void merge(int a[],int top,int mid,int bottom){
	int temp[20],i,k,j;
	k=top;
	j=mid+1;
	i=top;
	while((i<=mid)&&(j<=bottom)){
		if(a[i]<=a[j]){
			temp[k]=a[i];
			i++;
		}
		else{
			temp[k]=a[j];
			j++;
		}
		k++;
	}
	while(i<=mid){
		temp[k]=a[i];
		k++;
		i++;
	}
	while(j<=bottom){
		temp[k]=a[j];
		k++;
		j++;
	}
	for(i=top;i<=bottom;i++){
		a[i]=temp[i];
	}
}
