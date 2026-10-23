#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node* back;
    Node(int x) {
        data = x;
        next = nullptr;
        back = nullptr;
    }
};
Node* reverseDLL(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    Node* current = head;
    Node* newhead = nullptr;
    while (current != nullptr) {
        swap(current->back, current->next);
        newhead = current;
        current = current->back;
    }
    return newhead;
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
            newnode->back = tail;
            tail = newnode;
        }
    }
    head = reverseDLL(head);
    Node* p = head;
    while (p != nullptr) {
        cout << p->data << " ";
        p = p->next;
    }
    return 0;
}