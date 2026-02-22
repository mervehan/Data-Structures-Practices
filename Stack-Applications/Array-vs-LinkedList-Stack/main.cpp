#include <iostream>
#include <string>

using namespace std;

/**
 * 1. STACK IMPLEMENTATION USING LINKED LIST (Dynamic)
 * Ideal for unknown or growing data sizes.
 */
class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedListStack {
private:
    Node* top;
    int counter;

public:
    LinkedListStack() {
        top = nullptr;
        counter = 0;
    }

    bool isEmpty() {
        return (top == nullptr);
    }

    void push(int data) {
        Node* newNode = new Node(data);
        newNode->next = top;
        top = newNode;
        counter++;
        cout << "[Linked List Stack] Pushed: " << data << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "[Linked List Stack] Error: Stack is empty.\n";
            return;
        }
        Node* temp = top;
        int poppedData = top->data;
        top = top->next;
        delete temp;
        counter--;
        cout << "[Linked List Stack] Popped: " << poppedData << endl;
    }

    void showTop() {
        if (isEmpty()) {
            cout << "[Linked List Stack] Stack is empty.\n";
        } else {
            cout << "[Linked List Stack] Top element: " << top->data << endl;
        }
    }

    // Destructor to free memory
    ~LinkedListStack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

/**
 * 2. STACK IMPLEMENTATION USING ARRAY (Static)
 * Ideal for fixed sizes and better performance due to memory locality.
 */
const int MAX_SIZE = 5;

class ArrayStack {
private:
    int arr[MAX_SIZE];
    int top;

public:
    ArrayStack() {
        top = -1;
    }

    bool isEmpty() {
        return (top == -1);
    }

    bool isFull() {
        return (top == MAX_SIZE - 1);
    }

    void push(int element) {
        if (!isFull()) {
            top++;
            arr[top] = element;
            cout << "[Array Stack] Pushed: " << element << endl;
        } else {
            cout << "[Array Stack] Error: Stack is full. Cannot push " << element << ".\n";
        }
    }

    void pop() {
        if (!isEmpty()) {
            int poppedElement = arr[top];
            top--;
            cout << "[Array Stack] Popped: " << poppedElement << endl;
        } else {
            cout << "[Array Stack] Error: Stack is empty.\n";
        }
    }

    void showTop() {
        if (!isEmpty()) {
            cout << "[Array Stack] Top element: " << arr[top] << endl;
        } else {
            cout << "[Array Stack] Stack is empty.\n";
        }
    }
};

int main() {
    cout << "=== Testing Array-Based Stack ===" << endl;
    ArrayStack aStack;
    aStack.push(10);
    aStack.push(20);
    aStack.showTop();
    aStack.pop();
    aStack.pop();
    aStack.pop(); // Should show error

    cout << "\n=== Testing Linked List-Based Stack ===" << endl;
    LinkedListStack lStack;
    lStack.push(100);
    lStack.push(200);
    lStack.showTop();
    lStack.pop();
    lStack.showTop();

    return 0;
}
