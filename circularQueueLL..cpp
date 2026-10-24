#include <bits/stdc++.h>
using namespace std;
class Queue {
    struct Node {
        int data;
        Node* next;
        Node(int value) {
            data = value;
            next = nullptr;
        }
    };
    Node* front;
    Node* rear;
public:
    Queue() {
        front = rear = nullptr;
    }
    ~Queue() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }
    void queueEnqueue(int data) {
        Node* newNode = new Node(data);
        if (front == nullptr) {
            front = rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
    }
    void queueDequeue() {
        if (front == nullptr) {
            cout << "Queue is empty" << endl;
            return;
        }
        Node* temp = front;
        cout << "Removed: " << temp->data << endl;
        front = front->next;
        delete temp;
        if (front == nullptr) {
            rear = nullptr;
        }
    }
    void queueDisplay() {
        if (front == nullptr) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue elements: ";
        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void queuefront() {
        if (front == nullptr) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Front element: " << front->data << endl;
    }
};
int main() {
    int choice, data;
    Queue q;
    do {
        cout << "\n1. Enqueue";
        cout << "\n2. Dequeue";
        cout << "\n3. Display";
        cout << "\n4. Front element";
        cout << "\n0. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;
        if (cin.fail()) {
            cout << "Invalid input" << endl;
            return 0;
        }
        switch (choice) {
            case 1:
                cout << "Enter data: ";
                cin >> data;
                if (cin.fail()) {
                    cout << "Invalid input" << endl;
                    return 0;
                }
                q.queueEnqueue(data);
                break;
            case 2:
                q.queueDequeue();
                break;
            case 3:
                q.queueDisplay();
                break;
            case 4:
                q.queuefront();
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