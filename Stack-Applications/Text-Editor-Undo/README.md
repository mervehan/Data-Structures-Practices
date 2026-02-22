# Stack-Based Text Editor (Undo Feature)

This project is a simple C++ implementation demonstrating how a **Stack** data structure (using Linked Lists) operates in a real-world scenario: the "Undo" feature of a text editor.

## 📌 Features
* **Custom Node Structure:** Implements a linked-list based memory dynamically.
* **LIFO (Last-In-First-Out) Principle:** Words are pushed to the stack and the most recent word is popped when "Undo" is called.
* **Real-time State Tracking:** A custom print function visualizes the current memory state of the text editor.

## 💻 How It Works
The program simulates writing words into a text editor. Every written word is pushed onto the stack. When the `undo()` method is triggered, the last written word is permanently removed from the memory, mimicking the `Ctrl + Z` behavior.

