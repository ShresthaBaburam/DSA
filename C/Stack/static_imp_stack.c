#include <stdio.h>
#include <stdbool.h>

#define SIZE 10

int stack[SIZE];
int top = -1;


bool isEmpty(){
    if (top == -1){
        return 1;
    }
    return 0;
}


bool isFull(){
    if (top == SIZE -1){
        return 1;
    }
    return 0;
}


void push(int value) {
    if (isFull() == 1) {
        printf("Stack overflow.\n");
    } else {
        top = top + 1;
        stack[top] = value;
        printf("Data Item '%d' is pushed into Stack", stack[top]);
    }
}


int pop() {
    if (isEmpty() == 1) {
        printf("Stack underflow.\n");
        return -1;
    } else {
        int value = stack[top];
        top = top - 1;
        return value;
    }
}


void traverse(){
    int i;
    if (isEmpty() == 1){
        printf("Stack underflow.\n");
    } else {
        printf("\nThe Element(s) in Stack (top-buttom) is/are:\n");
        for(i=top; i>=0; i--){
            printf ("%d,\t",stack[i]);
        }
    }
}


void peek() {
    if (isEmpty() == 1) {
        printf("Stack underflow.\n");
    } else {
        printf("Data item on the top of Stack:%d\n",stack[top]);
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
    int choice, pushValue;
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &pushValue);
                push(pushValue);
                break;
            case 2:
                int poppedValue = pop();
                if (poppedValue != -1){
                    printf("Data Item(%d) is popped from Stack", poppedValue);
                }
                break;
            case 3:
                traverse();
                break;
            case 4:
                int peekValue = peek();
                if (peekValue != -1) {
                    printf("Data Item on the Top of Stack: %d\n", peekValue);
                }
                break;
            case 5:
                printf("Exting....");
                exit(1);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}