#include <stdio.h>
#include <stdlib.h>

// Structure for a queue node
typedef struct QueueNode {
    int data;
    struct QueueNode* next;
} QueueNode;

// Structure for a queue
typedef struct Queue {
    QueueNode *front, *rear;
} Queue;

typedef struct Stack {
    Queue* q1;
    Queue* q2;
} Stack;

void enqueue(Queue*, int);
int dequeue(Queue*);
int peek(Stack*);
int pop(Stack*);
void push(Stack*, int);
int isEmpty(Queue*);
int front(Queue*);
QueueNode* createQueueNode(int);

Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (!queue) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    queue->front = queue->rear = NULL;
    return queue;
}

Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (!stack) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    stack->q1 = createQueue();
    stack->q2 = createQueue();
    return stack;
}

int main() {
    Stack* stack = createStack();

    int choice, value;
    while (1) {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(stack, value);
                printf("%d pushed to stack.\n", value);
                break;

            case 2:
                if (!isEmpty(stack->q1)) {
                    value = pop(stack);
                    printf("%d popped from stack.\n", value);
                }
                else {
                    printf("Stack is empty!\n");
                }
                break;

            case 3:
                if (!isEmpty(stack->q1)) {
                    value = peek(stack);
                    printf("Top element: %d\n", value);
                }
                else {
                    printf("Stack is empty!\n");
                }
                break;

            case 4:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void enqueue(Queue* queue, int data) {
    QueueNode* newNode = createQueueNode(data);
    if (!queue->rear) { // If queue is empty
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

int dequeue(Queue* queue) {
    if (!queue->front) { // If queue is empty
        printf("Queue is empty!\n");
        exit(1);
    }
    QueueNode* temp = queue->front;
    int data = temp->data;
    queue->front = queue->front->next;
    if (!queue->front) { // If queue becomes empty
        queue->rear = NULL;
    }
    free(temp);
    return data;
}

void push(Stack* stack, int data) {
    enqueue(stack->q2, data);

    while (!isEmpty(stack->q1)) {
        enqueue(stack->q2, dequeue(stack->q1));
    }

    Queue* temp = stack->q1;
    stack->q1 = stack->q2;
    stack->q2 = temp;
}

int pop(Stack* stack) {
    if (isEmpty(stack->q1)) {
        printf("Stack is empty!\n");
        exit(1);
    }
    return dequeue(stack->q1);
}

int peek(Stack* stack) {
    if (isEmpty(stack->q1)) {
        printf("Stack is empty!\n");
        exit(1);
    }
    return front(stack->q1);
}

int front(Queue* queue) {
    if (!queue->front) {
        printf("Queue is empty!\n");
        exit(1);
    }
    return queue->front->data;
}

int isEmpty(Queue* queue) {
    return queue->front == NULL;
}

QueueNode* createQueueNode(int data) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
