# Stack Practice: Array & Linked List Comparison

This project is a personal study to understand the core differences between the two main ways of implementing a **Stack** in C++. I've implemented both versions to see how memory management (static vs. dynamic) works in practice.

## 📊 Quick Comparison
* **Array-Based:** Uses a fixed-size array. It’s very fast and simple but has a limit on how many items it can hold.
* **Linked List-Based:** Uses nodes and pointers. It is flexible because it can grow as much as the memory allows, but it uses a bit more memory because of the pointers.

## 🛠️ What I Focused On
* **Object-Oriented Logic:** I used classes to keep the code organized and easy to read.
* **Memory Safety:** In the Linked List version, I made sure to use a **Destructor** to clean up the memory and prevent leaks.
* **Simple Interface:** Both versions use the same basic methods: `push`, `pop`, and `showTop`.

## 🌍 Where are these used in real life?



### 📍 Array-Based (Fixed Size)
* **Simple Undo Features:** Used when you only need to remember a certain number of steps (like the last 50 actions in a small app).
* **Embedded Systems:** Used in devices with very small memory (like a digital watch or a microwave) where you know exactly how much space you have.

### 📍 Linked List-Based (Flexible Size)
* **Browser History:** Used in web browsers since we don't know how many pages a user will visit in one session.
* **Banking Systems:** Good for handling customer transaction requests that can suddenly increase in volume.
* **Smartphone Apps:** Most modern apps use dynamic structures like this to avoid "Stack Overflow" errors when dealing with varying amounts of data.

## 💻 How to Run
1. Open your terminal or IDE.
2. Compile the code: `g++ main.cpp -o my_stack`
3. Run it: `./my_stack`
