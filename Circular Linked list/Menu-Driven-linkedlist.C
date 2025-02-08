#include <stdio.h>
#include <stdlib.h> //Circular linked list

struct Node {
    int data;
    struct Node *next;
};

void insbeg();
void insend();
void display();
void delbeg();
void delend();
void insertAtPosition();
void insertAfterPosition();
void insertBeforePosition();
void deleteAtPosition();
int countNodes();
void reverce();
void findMax();
void findMin();
int linearSearch();
void sort();

struct Node *head = NULL;

int main() {
    int choice;
    while (1) {
        printf("\nCircular Linked List Operations:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Display List\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Insert at any Position\n");
        printf("7. Insert after Position\n");
        printf("8. Insert before Position\n");
        printf("9. Delete from any Position\n");
        printf("10. Count Nodes\n");
        printf("11. Reverse List\n");
        printf("12. Find Maximum\n");
        printf("13. Find Minimum\n");
        printf("14. Linear Search\n");
        printf("15. Sort the List\n");
        printf("16. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insbeg();
            break;
            case 2: insend();
            break;
            case 3: display();
            break;
            case 4: delbeg();
            break;
            case 5: delend();
            break;
            case 6: insertAtPosition();
            break;
            case 7: insertAfterPosition();
            break;
            case 8: insertBeforePosition();
            break;
            case 9: deleteAtPosition();
            break;
            case 10: printf("Total nodes: %d\n", countNodes());
            break;
            case 11: reverce();
            break;
            case 12: findMax();
            break;
            case 13: findMin();
            break;
            case 14: linearSearch();
            break;
            case 15:
                sort();
                display();
                break;
            case 16: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}


void insbeg() {
    struct Node *new1 = (struct Node *)malloc(sizeof(struct Node));
    if (new1 == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    printf("Enter data: ");
    scanf("%d", &new1->data);


    if (head == NULL) {
        head = new1;
        head->next = head;
    } else {
        struct Node *p = head;
        while (p->next != head) {
            p = p->next;
        }
        new1->next = head;
        p->next = new1;
        head = new1;
    }
}

void insend() {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    printf("Enter the data: ");
    scanf("%d", &temp->data);

    if (head == NULL) {
        head = temp;
        temp->next = head;
    } else {
        struct Node *p = head;
        while (p->next != head) {
            p = p->next;
        }
        temp->next = head;
        p->next = temp;
    }
}

void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("List elements: ");
    struct Node *p = head;
    do {
        printf("<- %d -> ", p->data);
        p = p->next;
    } while (p != head);
    printf("HEAD\n");
}

void delbeg() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (head->next == head) {
        printf("Deleted element: %d\n", head->data);
        free(head);
        head = NULL;
        return;
    }
    struct Node *p = head;
    while (p->next != head) {
        p = p->next;
    }
    struct Node *temp = head;
    head = head->next;
    p->next = head;
    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

void delend() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (head->next == head) {
        printf("Deleted element: %d\n", head->data);
        free(head);
        head = NULL;
        return;
    }
    struct Node *p = head, *q = NULL;
    while (p->next != head) {
        q = p;
        p = p->next;
    }
    q->next = head;
    printf("Deleted element: %d\n", p->data);
    free(p);
}

void insertAtPosition() {
    int pos;
    printf("Enter position: ");
    scanf("%d", &pos);
    if (pos < 1) {
        printf("Invalid position\n");
        return;
    }
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    printf("Enter data: ");
    scanf("%d", &temp->data);
    if (pos == 1) {
        if (head == NULL) {
            head = temp;
            temp->next = head;
        }
        else {
            struct Node *p = head;
            while (p->next != head) {
                p = p->next;
            }
            temp->next = head;
            p->next = temp;
            head = temp;
        }
        return;
    }
    struct Node *p = head;
    for (int i = 1; i < pos - 1 && p->next != head; i++) {
        p = p->next;
    }
    if (p->next == head && pos > 2) {
        printf("Position exceeds list length\n");
        free(temp);
        return;
    }
    temp->next = p->next;
    p->next = temp;
}

void insertAfterPosition() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    int pos;
    printf("Enter position after which to insert: ");
    scanf("%d", &pos);
    if (pos < 1) {
        printf("Invalid position\n");
        return;
    }
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    if (temp == NULL) {
        printf("Error.\n");
        return;
    }
    printf("Enter data: ");
    scanf("%d", &temp->data);
    struct Node *p = head;
    for (int i = 1; i < pos && p->next != head; i++) {
        p = p->next;
    }
    if (p->next == head && pos > 1) {
        printf("Error.\n");
        free(temp);
        return;
    }
    temp->next = p->next;
    p->next = temp;
}

void insertBeforePosition() {
    int pos;
    printf("Enter position before which to insert: ");
    scanf("%d", &pos);
    if (pos < 1) {
        printf("Invalid position\n");
        return;
    }
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    if (temp == NULL) {
        printf("Error\n");
        return;
    }
    printf("Enter data: ");
    scanf("%d", &temp->data);
    if (pos == 1) {
        if (head == NULL) {
            head = temp;
            temp->next = head;
        }
        else {
            struct Node *p = head;
            while (p->next != head) {
                p = p->next;
            }
            temp->next = head;
            p->next = temp;
            head = temp;
        }
        return;
    }
    struct Node *p = head, *prev = NULL;
    for (int i = 1; i < pos && p->next != head; i++) {
        prev = p;
        p = p->next;
    }
    if (p->next == head && pos > 2) {
        printf("Error.\n");
        free(temp);
        return;
    }
    temp->next = p;
    prev->next = temp;
}


void deleteAtPosition() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    int pos;
    printf("Enter position to delete: ");
    scanf("%d", &pos);
    if (pos < 1) {
        printf("Invalid position\n");
        return;
    }
    if (pos == 1) {
        if (head->next == head) {
            printf("Deleted element: %d\n", head->data);
            free(head);
            head = NULL;
            return;
        }
        struct Node *p = head;
        while (p->next != head) {
            p = p->next;
        }
        struct Node *temp = head;
        head = head->next;
        p->next = head;
        printf("Deleted element: %d\n", temp->data);
        free(temp);
        return;
    }
    struct Node *p = head, *prev = NULL;
    for (int i = 1; i < pos && p->next != head; i++) {
        prev = p;
        p = p->next;
    }
    if (p->next == head && pos > 2) {
        printf("Error.\n");
        return;
    }
    prev->next = p->next;
    printf("Deleted element: %d\n", p->data);
    free(p);
}


int countNodes() {
    if (head == NULL) return 0;
    int count = 1;
    struct Node *p = head->next;
    while (p != head) {
        count++;
        p = p->next;
    }
    return count;
}


void reverce() {
    if (head == NULL) {
        printf("Empty list\n");
        return;
    }

    struct Node* curr = head;
    struct Node* prev = NULL;
    struct Node* nextptr;

    do {
        nextptr = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextptr;
    } while (curr != head);

    head->next = prev;
    head = prev;
}

void findMax() {
    if (head == NULL) {
        printf("Empty list\n");
    }
    int max = head->data;
    struct Node* p = head;
    do {
        if (p->data > max) {
            max = p->data;
        }
        p = p->next;
    } while (p != head);
    printf("Maximum number is: %d\n", max);
}

void findMin() {
    if (head == NULL) {
        printf("Empty list\n");
        return;
    }
    int min = head->data;
    struct Node* p = head;
    do {
        if (p->data < min) {
            min = p->data;
        }
        p = p->next;
    } while (p != head);
    printf("Minimum number is: %d\n", min);
}

int linearSearch() {
    if (head == NULL) {
        printf("List is empty\n");
        return -1;
    }
    int key, pos = 1;
    printf("Enter element to search: ");
    scanf("%d", &key);
    struct Node *p = head;
    do {
        if (p->data == key) {
            printf("Element found at position %d\n", pos);
            return pos;
        }
        pos++;
        p = p->next;
    } while (p != head);
    printf("Element not found\n");
    return -1;
}


void sort() {
    if (head == NULL) {
        printf("Empty list\n");
        return;
    }
    int swapped;
    do {
        swapped = 0;
        struct Node* curr = head;
        do {
            struct Node* next = curr->next;
            if (curr->data > next->data) {
                int temp = curr->data;
                curr->data = next->data;
                next->data = temp;
                swapped = 1;
            }
            curr = curr->next;
        } while (curr->next != head);
    } while (swapped);
}
