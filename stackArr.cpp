#include <bits/stdc++.h>
using namespace std;
class ArrayStack {
    int *arr;
    int top, capacity;
public:
    ArrayStack(int cap) {
        capacity = cap;
        arr = new int[capacity];
        top = -1;
    }
    ~ArrayStack() {
        delete[] arr;
    }
    void push(int value) {
        if (top == capacity - 1) {
            cout << "Overflow" << endl;
            return;
        }
        top++;
        arr[top] = value;
    }
    void pop() {
        if (top == -1) {
            cout << "Stack underflow" << endl;
            return;
        }
        cout << "Removed: " << arr[top] << endl;
        top--;
    }
    void peek() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Top element: " << arr[top] << endl;
    }
    void display() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main() {
    int cap, choice, data;
    cout << "Enter capacity: ";
    cin >> cap;
    if (cin.fail() || cap <= 0) {
        cout << "Invalid capacity" << endl;
        return 0;
    }
    ArrayStack s(cap);
    do {
        cout << "\n1. Push";
        cout << "\n2. Pop";
        cout << "\n3. Peek";
        cout << "\n4. Display";
        cout << "\n0. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;
        if (cin.fail()) {
            cout << "Invalid input" << endl;
            return 0;
        }
        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> data;
                if (cin.fail()) {
                    cout << "Invalid input" << endl;
                    return 0;
                }
                s.push(data);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.peek();
                break;
            case 4:
                s.display();
                break;
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    } while (choice != 0);
    return 0;
}