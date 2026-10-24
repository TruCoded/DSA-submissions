#include <bits/stdc++.h>
using namespace std;
class LinkedStack {
    struct Node {
        int data;
        Node* next;
        Node(int value) {
            data = value;
            next = nullptr;
        }
    };
    Node* top;
public:
    LinkedStack() {
        top = nullptr;
    }
    ~LinkedStack() {
        while (top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }
    void pop() {
        if (top == nullptr) {
            cout << "Stack underflow" << endl;
            return;
        }
        Node* temp = top;
        cout << "Removed: " << temp->data << endl;
        top = top->next;
        delete temp;
    }
    void peek() {
        if (top == nullptr) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Top element: " << top->data << endl;
    }
    void display() {
        if (top == nullptr) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Stack elements: ";
        Node* temp = top;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main() {
    int choice, data;
    LinkedStack s;
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