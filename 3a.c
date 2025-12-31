#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

/* Insert operation */
void insert() {
    int value;
    if (rear == MAX - 1) {
        printf("Queue Overflow! Cannot insert.\n");
    } else {
        if (front == -1)
            front = 0;
        printf("Enter value to insert: ");
        scanf("%d", &value);
        rear++;
        queue[rear] = value;
        printf("Inserted %d into queue.\n", value);
    }
}

/* Delete operation */
void delete() {
    if (front == -1 || front > rear) {
        printf("Queue Empty! Cannot delete.\n");
    } else {
        printf("Deleted element: %d\n", queue[front]);
        front++;
    }
}

/* Display operation */
void display() {
    int i;
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements:\n");
        for (i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Linear Queue Menu ---\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: display(); break;
            case 4: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}
