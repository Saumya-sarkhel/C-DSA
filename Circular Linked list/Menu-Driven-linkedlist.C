
#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node *temp, *next;
    int data;
};
struct Node *head = NULL;

void insbeg();
void insend();
void display();
void delbeg();
void delend();
void insertAtPosition();

int main(){
    int n;
    while (1){
        printf("\n1. Insert at Begining\n2. Insert at End\n3. Display\n4. Delete from begining\n5. Delete from End\n");
        printf("6. Insert at any position\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            insbeg();
            break;
        case 2:
            insend();
            break;
        case 3:
            display();
            break;
        case 4:
            delbeg();
            break;
        case 5:
            delend();
            break;
        case 6:
            insertAtPosition();
            break;
        case 7:
            exit(1);
        default:
            printf("Wrong choice\n");
        }
    }
}

void insbeg(){
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    if (temp == NULL){
        printf("Memory error\n");
        return;
    }
    printf("Enter the data: ");
    scanf("%d", &temp->data);
    if (head == NULL){
        head = temp;
        temp->next = head;
    }
    else{
        struct Node *p = head;
        while (p->next != head){
            p = p->next;
        }
        temp->next = head;
        p->next = temp;
        head = temp;
    }
}

void insend(){
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    if (temp == NULL){
        printf("Memory error\n");
        return;
    }
    printf("Enter the data: ");
    scanf("%d", &temp->data);
    if (head == NULL){
        head = temp;
        temp->next = head;
    }
    else{
        struct Node *p = head;
        while (p->next != head){
            p = p->next;
        }
        temp->next = head;
        p->next = temp;
    }
}

void delbeg(){
    if (head == NULL){
        printf("List is empty\n");
        return;
    }
    if (head->next == head){
        printf("Deleted data is: %d\n", head->data);
        free(head);
        head = NULL;
    }
    else{
        struct Node *p = head;
        while (p->next != head){
            p = p->next;
        }
        struct Node *temp = head;
        p->next = head->next;
        head = head->next;
        printf("Deleted data is: %d\n", temp->data);
        free(temp);
    }
}

void display(){
    struct Node *p;
    if (head == NULL){
        printf("List is empty\n");
    }
    else{
        printf("List are: \n");
        p = head;
        do{
            printf("| %d |->", p->data);
            p = p->next;
        } while (p != head);
        printf("HEAD\n");
    }
}

void delend(){
    if (head == NULL){
        printf("Empty list\n");
        return;
    }
    else{
        struct Node *p, *q;
        q = head;
        p = head;
        while (p->next != head){
            q = p;
            p = p->next;
        }
        q->next = head;
        p->next = NULL;
        printf("Deleted data is %d\n", p->data);
    }
}

void insertAtPosition(){
    int pos;
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter data: ");
    scanf("%d", &temp->data);
    printf("Enter position: ");
    scanf("%d", &pos);
    if (pos < 1){
        printf("Invalid position\n");
        return;
    }
    if (temp == NULL){
        printf("No List present.\n");
        return;
    }
    if (head == NULL){
        temp->next = temp;
        head = temp;
        return;
    }
    if (pos == 1){
        temp->next = head;
        struct Node *last = head;
        while (last->next != head){
            last = last->next;
        }
        last->next = temp;
        head = temp;
        return;
    }
    struct Node *prev = head;
    for (int i = 1; i < pos - 1; i++){
        if (prev->next == head){
            printf("Position exceeds the list length\n");
            free(temp);
            return;
        }
        prev = prev->next;
    }
    temp->next = prev->next;
    prev->next = temp;
}
