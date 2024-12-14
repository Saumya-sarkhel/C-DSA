
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coef;
    int exp;
    struct Node* next;
};

void insertNode(Node **, int, int);
void displayPolynomial(Node *, int);


int main() {
    struct Node* head = NULL;
    int n, coef, exp;
    printf("Enter the number of terms in the polynomial: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coef and exp for term %d: ", i + 1);
        scanf("%d %d", &coef, &exp);
        insertNode(&head, coef, exp);
    }
    printf("Polynomial is: ");
    displayPolynomial(head, n);
    return 0;
}


void insertNode(Node** head, int coef, int exp) {
    struct Node* newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("error...\n");
        return;
    }
    newNode->coef = coef;
    newNode->exp = exp;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
    }
    else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void displayPolynomial(Node* head, int n) {
    struct Node* temp = head;
    int i;
    for(i=0; i<n && temp != NULL; i++){
        if(temp->exp == 0){
            printf(" + %d", temp->coef);
        }
        else if(i == 0){
            printf(" %dx^%d", temp->coef, temp->exp);
        }
        else{
            if(temp->coef>0){
                printf("+ %dx^%d", temp->coef, temp->exp);
            }
            else{
                printf(" %dx^%d", temp->coef, temp->exp);
            }
        }
        temp = temp->next;
    }
    printf("\n");
}
