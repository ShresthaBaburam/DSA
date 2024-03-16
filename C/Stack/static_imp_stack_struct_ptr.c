#include <stdio.h>
#include <stdbool.h>

#define MAXSIZE 15


struct Stack {
    int stack[MAXSIZE];
    int top;
};


bool isEmpty(struct Stack *stack) {
    return stack->top == -1;
}


bool isFull(struct Stack *stack) {
    return stack->top == MAXSIZE - 1;
}


void push(struct Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack Overflow.\n");
    } else {
        stack->stack[++stack->top] = value;
    }
}


int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow.\n");
        return -1;
    } else {
        return stack->stack[stack->top--];
    }
}


void traverse(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is Underflow.\n");
    } else {
        printf("\nThe Element(s) in Stack (top-buttom) is/are:\n");
        for (int i = stack->top; i >= 0; i--) {
            printf ("%d,\t", stack->stack[i]);
        }
    }
}


int peek(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow.\n");
        return -1;
    } else {
        return stack->stack[stack->top];
    }
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
    stack.top = -1;

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
                poppedValue = pop(&stack);
                if (poppedValue != -1){
                    printf("Data Item '%d' is Popped from Stack\n", poppedValue);
                }
                break;
            case 3:
                traverse(&stack);
                break;
            case 4:
                peekValue = peek(&stack);
                if (peekValue != -1) {
                    printf("Data Item on the Top of Stack: %d\n", peekValue);
                }
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
