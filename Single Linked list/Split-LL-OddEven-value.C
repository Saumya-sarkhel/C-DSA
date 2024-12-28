
#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node NODE;

int main(){
    int i, n;
    NODE *head, *head1, *head2, *p, *q, *r;
    head = NULL;
    head1 = NULL;
    head2 = NULL;
    printf("Enter the n number of nodes: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++){
        p = (NODE *)malloc(sizeof(NODE));
        printf("Enter the data: ");
        scanf("%d", &p->data);
        p->next = NULL;
        if (head == NULL){
            head = p;
        }
        else{
            q = head;
            while (q->next != NULL){
                q = q->next;
            }
            q->next = p;
        }
    }
    for (r = head; r != NULL; r = r->next){
        p = (NODE *)malloc(sizeof(NODE));
        p->data = r->data;
        p->next = NULL;
        if (r->data % 2 == 0) // r->data>=0   // i%2==0
        {
            if (head2 == NULL){
                head2 = p;
            }
            else{
                q = head2;
                while (q->next != NULL)
                    q = q->next;

                q->next = p;
                p->next = NULL;
            }
        }
        else{
            if (head1 == NULL){
                head1 = p;
            }
            else{
                q = head1;
                while (q->next != NULL)
                    q = q->next;

                q->next = p;
            }
        }
    }

    printf("\nThe original list is: ");
    for (q = head; q != NULL; q = q->next)
        printf("|%d|->", q->data);
    printf("NULL");

    printf("\nThe even element list is: ");
    for (q = head2; q != NULL; q = q->next)
        printf("|%d|->", q->data);
    printf("NULL");

    printf("\nThe odd element list is: ");
    for (q = head1; q != NULL; q = q->next)
        printf("|%d|->", q->data);
    printf("NULL");
}
