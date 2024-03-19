#include <iostream>
#include <cstdlib>
using namespace std;

#define SIZE 10

struct StackElement {
    int value;
    StackElement* next;
};

class Stack {
private:
    StackElement* top;

public:
    Stack() {
        top = nullptr;
    }

    bool isEmpty() {
        return (top == nullptr);
    }

    void push(int value) {
        StackElement* newElement = new StackElement;
        newElement->value = value;
        newElement->next = top;
        top = newElement;
        cout << "Data Item '" << value << "' is Pushed into Stack" << endl;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow." << endl;
            return -1;
        } else {
            int value = top->value;
            StackElement* temp = top;
            top = top->next;
            delete temp;
            return value;
        }
    }

    void traverse() {
        if (isEmpty()) {
            cout << "Stack underflow." << endl;
        } else {
            cout << "\nThe Element(s) in Stack (top-bottom) is/are:" << endl;
            StackElement* current = top;
            while (current != nullptr) {
                cout << current->value << ",\t";
                current = current->next;
            }
            cout << endl;
        }
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack underflow." << endl;
            return -1;
        } else {
            return top->value;
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
    int poppedValue, peekValue;
    while (true) {
        menu();
        cin >> choice;
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
