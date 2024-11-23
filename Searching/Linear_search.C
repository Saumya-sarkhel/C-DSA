
#include<stdio.h>
#include <stdlib.h>

int main(){

  int n,i,j,key, flag;
  printf("Enter the number of elements: ");
  scanf("%d", &n);
  int *a;
  a = (int *)malloc(n * sizeof(int));

  printf("Enter the searching value: ");
  scanf("%d", &key);

  for(i=0; i<n; i++){
    printf("Enter data: ");
    scanf("%d", &a[i]);
  }
  for(i=0,flag=0; i<n; i++){
    if(a[i]==key){
      flag =1;
      break;
    }
  }
  if(flag==1){
    printf("key is found at position %d", i);
  }
  else printf("Key not found.\n");
}