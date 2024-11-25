
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * next;
};
struct node *head = NULL;
void Insert_end(int);
void printlist();


int main(){
    int n, x, i;
    printf("Enter how many numbers: ");
    scanf("%d", &n);

    for(i=0; i<n; i++){
      printf("Enter the number: ");
      scanf("%d", &x);
      Insert_end(x);
      printlist();
    }
  return 0;
}

void Insert_end(int x){
    struct node *temp, *ptr;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = x; 
    temp->next = NULL;
    if(head == NULL){
      head = temp;
    }
    else{
      ptr = head;
      while(ptr->next != NULL){
        ptr = ptr->next;
      }
      ptr->next = temp;
    }
}

void printlist(){
    struct node *p = head;
    printf("list is: \n");
    while(p != NULL){
        printf("| %d |->", p->data);
        p = p->next;
    }
    printf("NULL\n");
}