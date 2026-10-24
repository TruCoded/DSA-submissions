
#include <iostream>
using namespace std;
class queue {
    struct node {
        int data;
        node* next;
        node(int value) {
            data = value;
            next = nullptr;
        }
    };
    node* front;
    node* rear;
    int cap, size;
public:
    queue(int val) {
        front = rear = nullptr;
        cap = val;
        size = 0;
    }
    ~queue() {
        while (front != nullptr) {
            node* temp = front;
            front = front->next;
            delete temp;
        }
    }
    void enqueue(int data) {
        if (size == cap) {
            cout << "Queue is full" << endl;
            return;
        }
        node* newNode = new node(data);
        if (front == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }
    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty" << endl;
            return;
        }
        node* temp = front;
        front = front->next;
        delete temp;
        if (front == nullptr) {
            rear = nullptr;
        }
        size--;
    }
    void display() {
        if (front == nullptr) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue elements: ";
        node* temp = front;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void showFront() {
        if (front == nullptr) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Front element is: " << front->data << endl;
    }
};
int main() {
    int capacity;
    cout << "Enter capacity of queue: ";
    if (!(cin >> capacity) || capacity <= 0) {
        cout << "Invalid capacity" << endl;
        return 0;
    }
    queue q(capacity);
    int choice, val;
    do {
        cout << "\n1. Enqueue";
        cout << "\n2. Dequeue";
        cout << "\n3. Display";
        cout << "\n4. Front";
        cout << "\n0. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                q.enqueue(val);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.display();
                break;
            case 4:
                q.showFront();
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
