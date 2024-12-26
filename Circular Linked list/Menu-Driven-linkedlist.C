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
void reverse();
int findMax();
int findMin();
int linearSearch();

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
        printf("6. Insert at Position\n");
        printf("7. Insert after Position\n");
        printf("8. Insert before Position\n");
        printf("9. Delete from Position\n");
        printf("10. Count Nodes\n");
        printf("11. Reverse List\n");
        printf("12. Find Maximum\n");
        printf("13. Find Minimum\n");
        printf("14. Linear Search\n");
        printf("15. Exit\n");
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
            case 11: reverse();
            break;
            case 12:
                if (head != NULL) printf("Maximum value: %d\n", findMax());
                break;
            case 13:
                if (head != NULL) printf("Minimum value: %d\n", findMin());
                break;
            case 14: linearSearch();
            break;
            case 15: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}


void insbeg() {
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
        head = temp;
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
        printf("%d -> ", p->data);
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
        } else {
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
        } else {
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
        delbeg();
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

void reverse() {
    if (head == NULL || head->next == head) return;

    struct Node *prev = NULL, *curr = head, *next;
    struct Node *last = head;
    while (last->next != head) last = last->next;

    do {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    } while (curr != head);

    head->next = prev;
    head = prev;
    last->next = head;
}

int findMax() {
    if (head == NULL) {
        printf("List is empty\n");
        return INT_MIN;
    }

    int max = head->data;
    struct Node *p = head->next;
    while (p != head) {
        if (p->data > max) max = p->data;
        p = p->next;
    }
    return max;
}

int findMin() {
    if (head == NULL) {
        printf("List is empty\n");
        return INT_MAX;
    }

    int min = head->data;
    struct Node *p = head->next;
    while (p != head) {
        if (p->data < min) min = p->data;
        p = p->next;
    }
    return min;
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
