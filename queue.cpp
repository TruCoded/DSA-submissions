#include <bits/stdc++.h>
using namespace std;
class Queue {
public:
    int front, rear, capacity;
    int *queue;
    Queue(int val) {
        front = rear = 0;
        capacity = val;
        queue = new int[capacity];
    }
    ~Queue() {
        delete[] queue;
    }
    // Add at end
    void queueEnqueue(int val) {
        if (rear == capacity) {
            cout << "Queue is full" << endl;
            return;
        }
        queue[rear++] = val;
    }
    // Remove first element
    void queueDequeue() {
        if (front == rear) {
            cout << "Queue is empty" << endl;
            return;
        }
        for (int i = front; i < rear - 1; i++) {
            queue[i] = queue[i + 1];
        }
        rear--;
    }
    // Display all elements
    void queueDisplay() {
        if (front == rear) {
            cout << "Queue is empty" << endl;
            return;
        }
        for (int i = front; i < rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
    // Print first element
    void queuefront() {
        if (front == rear) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Front element is: " << queue[front] << endl;
    }
};
int main() {
    int capacity;
    cout << "Enter capacity of queue: ";
    if (!(cin >> capacity) || capacity <= 0) {
        cout << "Invalid capacity" << endl;
        return 0;
    }
    Queue q(capacity);
    int choice, val;
    do {
        cout << "\n1. Enqueue";
        cout << "\n2. Dequeue";
        cout << "\n3. Display";
        cout << "\n4. Front element";
        cout << "\n0. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                q.queueEnqueue(val);
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