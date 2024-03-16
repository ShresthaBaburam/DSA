#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct Node {
    int data;
    struct Node* next;
};


struct Stack {
    struct Node* top;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory Allocation Failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


void initialize(struct Stack* stack) {
    stack->top = NULL;
}


bool isEmpty(struct Stack* stack) {
    return stack->top == NULL;
}


void push(struct Stack* stack, int value) {
    struct Node* newNode = createNode(value);
    newNode->next = stack->top;
    stack->top = newNode;
    printf("Data Item '%d' is Pushed into stack.\n", value);
}


int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow.\n");
        return -1;
    }
    struct Node* temp = stack->top;
    int poppedValue = temp->data;
    stack->top = temp->next;
    free(temp);
    return poppedValue;
}

void traverse(struct Stack* stack){
    if (isEmpty(stack)) {
        printf("Stack Underflow.\n");
    } else {
        printf("\nThe Element(s) in Stack (top-buttom) is/are:\n");
        struct Node* current = stack->top;
        while (current != NULL) {
            printf("%d,\t", current->data);
            current = current->next;
        }
        printf("\n");
    }
}


int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow.\n");
        return -1;
    }
    return stack->top->data;
}


void displayMenu() {
    printf("\n1. Push\n");
    printf("2. Pop\n");
    printf("3. Traverse\n");
    printf("4. Peek\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}


int main() {
    struct Stack stack;
    initialize(&stack);

    int choice, pushValue;
    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &pushValue);
                push(&stack, pushValue);
                break;
            case 2:
                int poppedValue = pop(&stack);
                if (poppedValue != -1){
                    printf("Data Item '%d' is Popped from Stack", poppedValue);
                }
                break;
            case 3:
                traverse(&stack);
                break;
            case 4:
                int peekValue = peek(&stack);
                if (peekValue != -1){
                    printf("Data item on the top of Stack: %d \n", peekValue);
                }
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
