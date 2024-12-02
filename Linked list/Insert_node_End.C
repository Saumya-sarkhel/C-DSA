
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
    while(1){
      printf("\n1.Insert at the end\n2.Exit\n\n");
      printf("enter your choice :");
      scanf("%d",&n);
      switch(n){
        case 1: Insert_end(x);
                printlist();
                break;
        case 2: exit(1);
        default: printf("Invalid input.");
      }
    }
  return 0;
}

void Insert_end(int x){
    struct node *temp, *ptr;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &temp->data);
    // temp->data = x; 
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