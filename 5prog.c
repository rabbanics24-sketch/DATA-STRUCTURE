#include <stdio.h>
#include <stdlib.h>

// Definition of node
struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Create linked list
void createList(int n) {
    struct Node *newNode, *temp;
    int data;

    for (int i = 0; i < n; i++) {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);

        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }
}

// Delete first node
void deleteFirst() {
    struct Node *temp;

    if (head == NULL) {
        printf("List is empty. Deletion not possible.\n");
        return;
    }

    temp = head;
    head = head->next;
    free(temp);
    printf("First node deleted.\n");
}

// Delete last node
void deleteLast() {
    struct Node *temp, *prev;

    if (head == NULL) {
        printf("List is empty. Deletion not possible.\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        printf("Last node deleted.\n");
        return;
    }

    temp = head;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
    printf("Last node deleted.\n");
}

// Delete specified element
void deleteSpecified(int key) {
    struct Node *temp, *prev;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->data == key) {
        temp = head;
        head = head->next;
        free(temp);
        printf("Node with value %d deleted.\n", key);
        return;
    }

    temp = head;
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element not found.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Node with value %d deleted.\n", key);
}

// Display list
void display() {
    struct Node *temp;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    int choice, n, key;

    while (1) {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Create Linked List\n");
        printf("2. Delete First Element\n");
        printf("3. Delete Specified Element\n");
        printf("4. Delete Last Element\n");
        printf("5. Display List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of nodes: ");
                scanf("%d", &n);
                createList(n);
                break;

            case 2:
                deleteFirst();
                break;

            case 3:
                printf("Enter element to delete: ");
                scanf("%d", &key);
                deleteSpecified(key);
                break;

            case 4:
                deleteLast();
                break;

            case 5:
                display();
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
}
