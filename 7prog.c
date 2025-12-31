#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

// Create doubly linked list
void createList(int n) {
    struct Node *newNode, *temp;
    int data;

    for (int i = 0; i < n; i++) {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);

        newNode->data = data;
        newNode->prev = NULL;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
        }
    }
}

// Insert node to the left of a given value
void insertLeft(int value, int newData) {
    struct Node *temp = head;
    struct Node *newNode;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    while (temp != NULL && temp->data != value)
        temp = temp->next;

    if (temp == NULL) {
        printf("Value %d not found.\n", value);
        return;
    }

    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->prev = temp->prev;
    newNode->next = temp;

    if (temp->prev != NULL)
        temp->prev->next = newNode;
    else
        head = newNode;

    temp->prev = newNode;

    printf("Node inserted to the left of %d.\n", value);
}

// Delete node based on specific value
void deleteValue(int value) {
    struct Node *temp = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    while (temp != NULL && temp->data != value)
        temp = temp->next;

    if (temp == NULL) {
        printf("Value %d not found.\n", value);
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
    printf("Node with value %d deleted.\n", value);
}

// Display list
void display() {
    struct Node *temp = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    int choice, n, value, newData;

    while (1) {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Create List\n");
        printf("2. Insert Node to Left of Given Value\n");
        printf("3. Delete Node by Value\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of nodes: ");
                scanf("%d", &n);
                createList(n);
                break;

            case 2:
                printf("Enter value to insert left of: ");
                scanf("%d", &value);
                printf("Enter new data: ");
                scanf("%d", &newData);
                insertLeft(value, newData);
                break;

            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteValue(value);
                break;

            case 4:
                display();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
}
