#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};
Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    while (current != nullptr) {
        Node* nextnode = current->next;
        current->next = prev;
        prev = current;
        current = nextnode;
    }
    return prev;
}
int main() {
    int n, x;
    cin >> n;
    Node* head = nullptr;
    Node* tail = nullptr;
    for (int i = 0; i < n; i++) {
        cin >> x;
        Node* newnode = new Node(x);
        if (head == nullptr) {
            head = tail = newnode;
        }
        else {
            tail->next = newnode;
            tail = newnode;
        }
    }
    head = reverseList(head);
    Node* p = head;
    while (p != nullptr) {
        cout << p->data << " ";
        p = p->next;
    }
    return 0;
}