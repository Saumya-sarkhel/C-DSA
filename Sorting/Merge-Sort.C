
#include <stdio.h>
void mergesort(int[], int, int);
void merge(int[], int, int, int);

int main() {
  int a[25], i, n, beg = 0, end;
  printf("enter the number n:");
  scanf("%d", &n);
  printf("enter the array element");
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  mergesort(a, 0, n - 1);
  printf("the sorted element are");
  for (i = 0; i < n; i++) {
    printf("\na[%d]=%d", i, a[i]);
  }
}

void mergesort(int a[], int beg, int end) {
  int mid;
  if (beg < end) {
    mid = (beg + end) / 2;
    mergesort(a, beg, mid);
    mergesort(a, mid + 1, end);
    merge(a, beg, mid, end);
  }
}

void merge(int a[], int left, int mid, int right) {
  int temp[20], i, k, j;
  k = left;
  j = mid + 1;
  i = left;
  while ((i <= mid) && (j <= right)) {
    if (a[i] <= a[j]) {
      temp[k] = a[i];
      i++;
    } else {
      temp[k] = a[j];
      j++;
    }
    k++;
  }
  while (i <= mid) {
    temp[k] = a[i];
    k++;
    i++;
  }
  while (j <= right) {
    temp[k] = a[j];
    k++;
    j++;
  }
  for (i = left; i <= right; i++) {
    a[i] = temp[i];
  }
}
