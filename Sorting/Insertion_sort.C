
#include<stdio.h>
#include <stdlib.h>

int main(){

  int a[20],i,j, n,t,c;
  printf("Enter the number of elements: ");
  scanf("%d", &n);

  for(i=0; i<n; i++){
    printf("Enter data: ");
    scanf("%d", &a[i]);
  }

  for(i=1; i<n; i++){
    t=a[i];
    c = i-1;
    while(c>=0 && a[c]>t){
      a[c+1] = a[c];
      c = c-1;
    }
    a[c+1]=t;
  }
  printf("Sorted data in increasing order: ");
  for (i=0; i<n; i++){
    printf("%d ", a[i]);
  }
  printf("\n");
}
