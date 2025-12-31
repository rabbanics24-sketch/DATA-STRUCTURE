#include <stdio.h>
#include <stdlib.h>

// Node definition
struct Node {
    int data;
    struct Node *next;
};

// Function to create a linked list
struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode;
    int data;

    for (int i = 0; i < n; i++) {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);

        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}

// Display linked list
void display(struct Node *head) {
    struct Node *temp = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Sort linked list (Bubble Sort)
void sortList(struct Node *head) {
    struct Node *i, *j;
    int temp;

    if (head == NULL)
        return;

    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    printf("Linked list sorted.\n");
}

// Reverse linked list
struct Node* reverseList(struct Node *head) {
    struct Node *prev = NULL, *curr = head, *next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    printf("Linked list reversed.\n");
    return prev;
}

// Concatenate two linked lists
struct Node* concatenate(struct Node *head1, struct Node *head2) {
    struct Node *temp;

    if (head1 == NULL)
        return head2;

    temp = head1;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = head2;
    printf("Linked lists concatenated.\n");
    return head1;
}

// Main function
int main() {
    struct Node *list1 = NULL, *list2 = NULL;
    int n1, n2, choice;

    printf("Create first linked list\n");
    printf("Enter number of nodes: ");
    scanf("%d", &n1);
    list1 = createList(n1);

    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Display List\n");
        printf("2. Sort List\n");
        printf("3. Reverse List\n");
        printf("4. Concatenate with another list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display(list1);
                break;

            case 2:
                sortList(list1);
                display(list1);
                break;

            case 3:
                list1 = reverseList(list1);
                display(list1);
                break;

            case 4:
                printf("Create second linked list\n");
                printf("Enter number of nodes: ");
                scanf("%d", &n2);
                list2 = createList(n2);
                list1 = concatenate(list1, list2);
                display(list1);
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
}
