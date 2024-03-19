#include <iostream>
#include <cstdlib>
using namespace std;
#define SIZE 10

class Stack {
    private:
        int stack[SIZE];
        int top;

    public:
        Stack() {
            top = -1;
        }

        bool isEmpty() {
            return (top == -1);
        }

        bool isFull() {
            return (top == SIZE - 1);
        }

        void push(int value) {
            if (isFull()) {
                cout << "Stack overflow." << endl;
            } else {
                top++;
                stack[top] = value;
                cout << "Data Item '" << stack[top] << "' is Pushed into Stack" << endl;
            }
        }

        int pop() {
            if (isEmpty()) {
                cout << "Stack underflow." << endl;
                return -1;
            } else {
                int value = stack[top];
                top--;
                return value;
            }
        }

        void traverse() {
            if (isEmpty()) {
                cout << "Stack underflow." << endl;
            } else {
                cout << "\nThe Element(s) in Stack (top-bottom) is/are:" << endl;
                for (int i = top; i >= 0; i--) {
                    cout << stack[i] << ",\t";
                }
                cout << endl;
            }
        }

        int peek() {
            if (isEmpty()) {
                cout << "Stack underflow." << endl;
                return -1;
            } else {
                return stack[top];
            }
    }
};

void menu(){
    cout << "\n1. Push\n";
    cout << "2. Pop\n";
    cout << "3. Traverse\n";
    cout << "4. Peek\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    Stack stack;
    int choice, pushValue;
    
    while (true) {
        menu();
        cin >> choice;
        int poppedValue;
        int peekValue;
        switch (choice) {
            case 1:
                cout << "Enter the value to Push: ";
                cin >> pushValue;
                stack.push(pushValue);
                break;
            case 2:
                poppedValue = stack.pop();
                if (poppedValue != -1) {
                    cout << "Data Item(" << poppedValue << ") is Popped from Stack" << endl;
                }
                break;
            case 3:
                stack.traverse();
                break;
            case 4:
                peekValue = stack.peek();
                if (peekValue != -1) {
                    cout << "Data Item on the Top of Stack: " << peekValue << endl;
                }
                break;
            case 5:
                cout << "Exiting the program." << endl;
                exit(0);
            default:
                cout << "Invalid choice" << endl;
        }
    }
    return 0;
}
