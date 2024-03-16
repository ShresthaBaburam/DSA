#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 5

int queue[MAX_SIZE];
int front = -1;
int rear = -1;


bool isEmpty() {
    return front == -1;
}


bool isFull() {
    return (rear == MAX_SIZE - 1 && front == 0) || (rear + 1 == front);
}


void enqueue(int value) {
    if (isFull()) {
        printf("Queue Overflow\n");
    } else {
        if (isEmpty()) {
            front = 0;
        }
        rear = (rear + 1) % MAX_SIZE;
        queue[rear] = value;
        printf("Data Item '%d' Added to Queue.\n", value);
    }
}


int dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow.\n");
        return -1;
    } else {
        int dequeuedValue = queue[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }
        return dequeuedValue;
    }
}


void traverse() {
    if (isEmpty()) {
        printf("Queue is empty\n");
    } else {
        printf("Elements of the circular queue (front-> rear):");
        int i = front;
        do {
            printf("%d ", queue[i]);
            i = (i + 1) % MAX_SIZE;
        } while (i != (rear + 1) % MAX_SIZE);
        printf("\n");
    }
}

int peek(char *frontRear) {
    if (isEmpty()) {
        printf("Queue Underflow.\n");
        return -1;
    } else {
        if (frontRear == "f"){
            return queue[front];
        } else{
            return queue[rear];
        }
    }
}



void displayMenu() {
    printf("\n1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Traverse\n");
    printf("4. Front\n");
    printf("5. Rear\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}


int main() {
    int choice, value;
    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to Queue:");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                int dequeuedValue = dequeue();
                if (dequeuedValue != -1){
                    printf("Data Item '%d' is Dequeued from Queue", dequeuedValue);
                }
                break;
            case 3:
                traverse();
                break;
            case 4:
                int frontValue = peek("f");
                if (frontValue != -1){
                    printf("Data Item in front of Queue: %d", frontValue);
                }
                break;
            case 5:
                int rearValue = peek("r");
                if (rearValue != -1){
                    printf("Data Item in rear of Queue: %d", rearValue);
                }
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}