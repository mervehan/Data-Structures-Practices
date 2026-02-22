#include <iostream>
#include <string>

using namespace std;

// Node Structure
struct Node {
    string node;  
    Node* next;  

    Node(string node) { // Node's constructor
        this->node = node;
        this->next = nullptr;
    }
};

// Stack Class
class Stack {
private:
    Node* top; // The element that is on top of the stack

public:
    Stack() {
        top = nullptr;
    }

    void push(string node) {
        Node* newNode = new Node(node);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (top == nullptr) return;
        Node* deletedNode = top;
        top = top->next;
        delete deletedNode;
    }

    string topElement() {
        if (top == nullptr) return "";
        return top->node;
    }

    bool isEmpty() {
        return top == nullptr;
    }
    
    void printStack() {
        if (top == nullptr) {
            cout << "[ EMPTY ]" << endl;
            return;
        }

        Node* temp = top; // We use a copy pointer (temp) to avoid losing 'top'.
        cout << "Current Memory (LIFO): ";
        while (temp != nullptr) {
            cout << temp->node << " ";
            temp = temp->next; // Move to the next node
            
        }
        
    }
};

// Scenario Class (Text Editor)
class TextEditor {
private:
    Stack kelimeGecmisi;

public:
    void writeWord(string node) {
        cout << "Written: " << node << endl;
        kelimeGecmisi.push(node); 
        // We can show the state automatically after each operation or call it manually.
    }

    void undo() {
        if (kelimeGecmisi.isEmpty()) {
            cout << "Nothing to undo!" << endl;
        } else {
            string deletedNode = kelimeGecmisi.topElement();
            kelimeGecmisi.pop(); 
            cout << "UNDO : '" << deletedNode << "' deleted." << endl;
        }
    }

    
    // We write this function because the user cannot directly access the Stack object.
    void showCurrentState() {
        cout << "--- EDITOR STATE ---" << endl;
        kelimeGecmisi.printStack(); // Calls the print method of the Stack.
        cout<<endl;
    }
};

int main() {
    TextEditor myEditor; // Our object to access the TextEditor's functions

    cout << "=== Text Editor Starting ===" << endl;
    
    myEditor.writeWord("Hello");
    myEditor.writeWord("World");
    myEditor.writeWord("C++");
    
    // Current state
    myEditor.showCurrentState(); 

    
    myEditor.undo(); // The last word will be removed
    
    // After the removal from the stack
    myEditor.showCurrentState();

    cout << "\n=== Adding new words ===" << endl;
    myEditor.writeWord("Linked");
    myEditor.writeWord("List");
    
    myEditor.showCurrentState();

    return 0;
}
