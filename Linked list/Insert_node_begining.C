
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * next;
};
struct node *head = NULL;
void Insert_beg(int);
void printlist();


int main(){
    int n, x, i;
    while(1){
      printf("\n1. Insert at the beginingn\n2.Exit\n\n");
      printf("enter your choice :");
      scanf("%d",&n);
      switch(n){
        case 1: Insert_beg(x);
                printlist();
                break;
        case 2: exit(1);
        default: printf("Invalid input.");
      }
    }
}

void Insert_beg(int x){
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    if(head == NULL){
        head = temp;
    }
    else{
        temp->next = head;
        head = temp;
    }
    // temp->data = x;
    // temp->next = head;
    // head = temp;
}

void printlist(){
    struct node *p = head;
    printf("list is: \n");
    while(p != NULL){
        printf("| %d |->", p->data);
        p = p->next;
    }
    printf("NULL");
    printf("\n");
}