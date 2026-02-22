#include <iostream>
#include <string>

using namespace std;

// Node Structure for Queue
class Node {
public:
    string customer;
    Node* next;
    
    Node(string customer) {
        this->customer = customer;
        this->next = nullptr;
    }
};

// Bank Queue Class (FIFO - First-In-First-Out)
class QueueIsBank {
private:
    Node* front;
    Node* rear;
    int counter;

public: 
    QueueIsBank() {
        this->rear = nullptr;
        this->front = nullptr;
        this->counter = 0;
    }

    void enqueueInLine(string customer) {
        Node* newNode = new Node(customer);
        
        if (isEmpty()) {
            // If the queue is empty, the new node is both front and rear
            front = rear = newNode;
        } else {
            // If not empty, add to the end and update rear
            rear->next = newNode;
            rear = newNode;
        }
        counter++;
        cout << customer << " is added in line." << endl;
    }

    void dequeueInLine() { 
        // Removes the front element (First in, first out)
        if (isEmpty()) {
            cout << "The line is empty!" << endl;
            return;
        }
        
        Node* temp = front;
        string name = front->customer;
        front = front->next;
        
        if (front == nullptr) { 
            // If the last element is deleted, rear must also be null
            rear = nullptr;
        }
        
        delete temp;
        counter--;
        cout << name << " is served and left the line." << endl;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    int getLineCount() {
        return counter;
    }

    void showCurrentLine() {
        if (isEmpty()) {
            cout << "The line is empty." << endl;
            return;
        }
        
        Node* temp = front;
        cout << "Current Line: ";
        while (temp != nullptr) { // Traverse the list until nullptr
            cout << temp->customer << " -> ";
            temp = temp->next; // Move to the next node
        }
        cout << "END" << endl;
    }
};

int main() {
    QueueIsBank mybankline;
    
    cout << "=== Bank Queue System Starting ===" << endl;
    
    mybankline.enqueueInLine("Alex");
    mybankline.enqueueInLine("Stella");
    mybankline.enqueueInLine("Alexandra");
    mybankline.enqueueInLine("Angelina");
    
    cout << endl;
    mybankline.showCurrentLine();
    cout << "People in line: " << mybankline.getLineCount() << endl;

    cout << "\n--- Processing Line ---\n" << endl;

    while (!mybankline.isEmpty()) {
        mybankline.dequeueInLine();
        mybankline.showCurrentLine();
        cout << "Remaining: " << mybankline.getLineCount() << endl;
        cout << "--------------------" << endl;
    }

    return 0;
}
