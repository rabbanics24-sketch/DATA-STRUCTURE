#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Employee {
    int key;        // 4-digit key
    int emp_id;
    char name[30];
};

struct Employee hashTable[MAX];
int m;

/* Initialize hash table */
void init() {
    for (int i = 0; i < m; i++) {
        hashTable[i].key = -1;   // -1 indicates empty slot
    }
}

/* Hash function */
int hashFunction(int key) {
    return key % m;
}

/* Insert record using Linear Probing */
void insert() {
    struct Employee emp;
    int index, i;

    printf("Enter 4-digit Key: ");
    scanf("%d", &emp.key);

    printf("Enter Employee ID: ");
    scanf("%d", &emp.emp_id);

    printf("Enter Employee Name: ");
    scanf("%s", emp.name);

    index = hashFunction(emp.key);

    /* Linear Probing */
    for (i = 0; i < m; i++) {
        int probeIndex = (index + i) % m;

        if (hashTable[probeIndex].key == -1) {
            hashTable[probeIndex] = emp;
            printf("Record inserted at address %d\n", probeIndex);
            return;
        }
    }

    printf("Hash Table Overflow! Cannot insert record.\n");
}

/* Search record */
void search() {
    int key, index, i;

    printf("Enter Key to search: ");
    scanf("%d", &key);

    index = hashFunction(key);

    for (i = 0; i < m; i++) {
        int probeIndex = (index + i) % m;

        if (hashTable[probeIndex].key == key) {
            printf("Record Found at address %d\n", probeIndex);
            printf("Employee ID: %d\n", hashTable[probeIndex].emp_id);
            printf("Name: %s\n", hashTable[probeIndex].name);
            return;
        }

        if (hashTable[probeIndex].key == -1)
            break;
    }

    printf("Record not found!\n");
}

/* Display hash table */
void display() {
    printf("\nHash Table Contents:\n");
    printf("Address\tKey\tEmpID\tName\n");
    for (int i = 0; i < m; i++) {
        if (hashTable[i].key != -1)
            printf("%d\t%d\t%d\t%s\n", i,
                   hashTable[i].key,
                   hashTable[i].emp_id,
                   hashTable[i].name);
        else
            printf("%d\t---\n", i);
    }
}

int main() {
    int choice;

    printf("Enter size of Hash Table (m): ");
    scanf("%d", &m);

    init();

    while (1) {
        printf("\n--- Hashing with Linear Probing ---\n");
        printf("1. Insert Employee Record\n");
        printf("2. Search Employee Record\n");
        printf("3. Display Hash Table\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert();
                    break;
            case 2: search();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
}
