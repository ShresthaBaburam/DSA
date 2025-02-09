#include <stdio.h>
#define MAXSIZE 10

struct List {
    int list[MAXSIZE];
    int size;
} L;

int isEmpty() {
    if(L.size == 0){
        printf("List Underflow.\n");
        return 1;
    }    
    return 0;
}

int isFull() {
    if(L.size == MAXSIZE-1){
        printf("List Overflow.\n");
        return 1;
    }    
    return 0;
}

void insertAtBeginning(int x){
    if (isFull()==0) {
        for (int i = L.size; i > 0; i--) {
            L.list[i] = L.list[i - 1];
        }
    }
    L.list[0] = x;
    printf("%d is Inserted at Beginning\n", x);
    L.size++;
}

void insertAtPosition(int x, int pos) {
    if (isFull()==0){ 
        if (pos < 0 || pos > L.size) {
            printf("Invalid Position.\n");
            return;
        }
        for (int i = L.size; i > pos; i--) {
            L.list[i] = L.list[i - 1];
        }
        L.list[pos] = x;
        printf("%d is Inserted at %d Position\n", x, pos);
        L.size++;
    }
}

void insertAtEnd(int x) {
    if (isFull()==0){
        L.list[L.size] = x;
        printf("%d is Inserted at End\n", x);
        L.size++;
    }
}


void deleteFromBeginning() {
    if (isEmpty()==0) {
        int y = L.list[0];
        printf("%d is Deleted From Beginning\n", y);
        for (int i = 0; i < L.size - 1; i++) {
            L.list[i] = L.list[i + 1];
        }
        L.size--;
    }
}

void deleteFromPosition(int pos) {
    if (isEmpty()==0) {
        if (pos < 0 || pos >= L.size) {
            printf("Invalid position.\n");
            return;
        }
        else{
            int y = L.list[pos];
            printf("%d is Deleted From  %d Position\n", y, pos);
            for (int i = pos; i < L.size - 1; i++) {
                L.list[i] = L.list[i + 1];
            }
            L.size--;
        }
    }
}

void deleteFromEnd() {
    if (isEmpty()==0) {
        int y = L.list[L.size];
        printf("%d is Deleted From End\n", y);
        L.size--;
    }
}

void traverse() {
    if (isEmpty()==0) {
        printf("\nList elements: ");
        for (int i = 0; i < L.size; i++) {
            printf("%d ", L.list[i]);
        }
        printf("\n");
    }
}

void displayMenu() {
    printf("\n1. Insert at Beginning\n");
    printf("2. Insert at End\n");
    printf("3. Insert at Position\n");
    printf("4. Delete from Beginning\n");
    printf("5. Delete from End\n");
    printf("6. Delete from Position\n");
    printf("7. Traverse\n");
    printf("8. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    L.size = 0;

    int choice, value, pos;
    
    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 3:
                printf("Enter value and position to insert: ");
                scanf("%d %d", &value, &pos);
                insertAtPosition(value, pos);
                break;
            case 4:
                deleteFromBeginning();
                printf("Deleted from beginning.\n");
                break;
            case 5:
                deleteFromEnd();
                printf("Deleted from end.\n");
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deleteFromPosition(pos);
                break;
            case 7:
                traverse();
                break;
            case 8:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
