#include <bits/stdc++.h>
using namespace std;
class Queue {
    int *arr;
    int front, rear, cap;
public:
    Queue(int val) {
        cap = val;
        arr = new int[cap];
        front = rear = -1;
    }
    ~Queue() {
        delete[] arr;
    }
    void queueEnqueue(int data) {
        if ((rear + 1) % cap == front) {
            cout << "Queue is full" << endl;
            return;
        }
        if (front == -1) {
            front = rear = 0;
        }
        else {
            rear = (rear + 1) % cap;
        }
        arr[rear] = data;
    }
    void queueDequeue() {
        if (front == -1) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Removed: " << arr[front] << endl;
        if (front == rear) {
            front = rear = -1;
        }
        else {
            front = (front + 1) % cap;
        }
    }
    void queueDisplay() {
        if (front == -1) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) {
                break;
            }
            i = (i + 1) % cap;
        }
        cout << endl;
    }
    void queuefront() {
        if (front == -1) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Front element: " << arr[front] << endl;
    }
};
int main() {
  int cap, choice, data;
    cout << "Enter capacity: ";
    if (!(cin >> cap) || cap <= 0) {
        cout << "Invalid capacity";
        return 0;
    }
    Queue q(cap);
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
                cout << "Enter data: ";
                cin >> data;
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