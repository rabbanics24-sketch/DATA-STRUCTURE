#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *next;
};

struct Node *top = NULL;        // For Stack
struct Node *front = NULL;      // For Queue
struct Node *rear = NULL;

// ---------------- STACK FUNCTIONS ----------------

// Push operation
void push(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("Pushed %d into stack.\n", value);
}

// Pop operation
void pop() {
    struct Node *temp;

    if (top == NULL) {
        printf("Stack is empty. Pop not possible.\n");
        return;
    }

    temp = top;
    top = top->next;
    printf("Popped element: %d\n", temp->data);
    free(temp);
}

// Display stack
void displayStack() {
    struct Node *temp = top;

    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack (Top to Bottom): ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// ---------------- QUEUE FUNCTIONS ----------------

// Enqueue operation
void enqueue(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("Enqueued %d into queue.\n", value);
}

// Dequeue operation
void dequeue() {
    struct Node *temp;

    if (front == NULL) {
        printf("Queue is empty. Dequeue not possible.\n");
        return;
    }

    temp = front;
    front = front->next;

    if (front == NULL)
        rear = NULL;

    printf("Dequeued element: %d\n", temp->data);
    free(temp);
}

// Display queue
void displayQueue() {
    struct Node *temp = front;

    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue (Front to Rear): ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// ---------------- MAIN FUNCTION ----------------

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Push (Stack)\n");
        printf("2. Pop (Stack)\n");
        printf("3. Display Stack\n");
        printf("4. Enqueue (Queue)\n");
        printf("5. Dequeue (Queue)\n");
        printf("6. Display Queue\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                displayStack();
                break;

            case 4:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 5:
                dequeue();
                break;

            case 6:
                displayQueue();
                break;

            case 7:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
}
