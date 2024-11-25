
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
    printf("Enter how many numbers: ");
    scanf("%d", &n);

    for(i=0; i<n; i++){
        printf("Enter the number: ");
        scanf("%d", &x);
        Insert_beg(x);
        printlist();
    }
}

void Insert_beg(int x){
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = head;
    head = temp;
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