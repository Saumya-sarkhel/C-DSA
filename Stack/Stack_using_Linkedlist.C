
#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};

struct Node *top = NULL;

void push(int x) {
    struct Node* temp = (struct Node *)malloc(sizeof(struct Node *));
    temp->data = x;
    temp->next = top;
    top = temp;
}


void pop() {
    if (top == NULL) {
      printf("Stack is empty\n");
      return;
    }
    struct Node* temp = top;
    top = top->next;
    printf("Deleted data is %d\n", temp->data);
    free(temp);
}


void display() {
    if (top == NULL) {
      printf("Stack is empty\n");
      return;
    }
    struct Node* temp = top;
    printf("Stack elements are:\n");
    while (temp != NULL) {
        printf("|%d|\n", temp->data);
        temp = temp->next;
    }
}


int main() {
    int choice, x;
    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: printf("Enter the element to push: ");
                    scanf("%d", &x);
                    push(x);
                    break;
            case 2: pop();
                    break;
            case 3: display();
                    break;
            case 4: exit(1);
                    break;
            default: printf("Wrong choice\n");
        }
    }
  return 0;
}