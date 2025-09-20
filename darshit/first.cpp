#include <iostream>
using namespace std;

// Stack class definition
class Stack {
private:
    int *arr;
    int top;
    int capacity;

public:
    // Constructor
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
        top = -1;
    }

    // Destructor
    ~Stack() {
        delete[] arr;
    }

    // Push element onto stack
    void push() {
        if (isFull()) {
            cout << "Stack is full. Cannot push more elements." << endl;
        } else {
            int value;
            cout << "Enter value to push: ";
            cin >> value;
            arr[++top] = value;
            cout << value << " pushed to stack." << endl;
        }
    }

    // Pop element from stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Nothing to pop." << endl;
        } else {
            cout << arr[top--] << " popped from stack." << endl;
        }
    }

    // Display top element
    void topElement() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
        } else {
            cout << "Top element: " << arr[top] << endl;
        }
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Check if stack is full
    bool isFull() {
        return top == capacity - 1;
    }
};

// Main function to test the stack
int main() {
    int size;
    cout << "Enter the size of the stack: ";
    cin >> size;

    Stack myStack(size);

    int choice;
    do {
        cout << "\n--- Stack Menu ---\n";
        cout << "1. Push Element\n";
        cout << "2. Pop Element\n";
        cout << "3. Display Top Element\n";
        cout << "4. Check if Stack is Empty\n";
        cout << "5. Check if Stack is Full\n";
        cout << "6. Exit\n";
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        switch (choice) {
            case 1:
                myStack.push();
                break;
            case 2:
                myStack.pop();
                break;
            case 3:
                myStack.topElement();
                break;
            case 4:
                cout << (myStack.isEmpty() ? "Stack is Empty." : "Stack is not Empty.") << endl;
                break;
            case 5:
                cout << (myStack.isFull() ? "Stack is Full." : "Stack is not Full.") << endl;
                break;
            case 6:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 6);

    return 0;
}