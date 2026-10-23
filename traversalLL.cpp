#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};
Node* convertArrToLL(vector<int>& arr) {
    if (arr.empty()) {
        return NULL;
    }
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
// Print linked list
void printLL(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
// Length of linked list
int lengthofLL(Node* head) {
    int cnt = 0;
    Node* temp = head;
    while (temp != NULL) {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}
int main() {
    vector<int> arr = {12, 5, 8, 7};
    Node* head = convertArrToLL(arr);
    printLL(head);
    cout << "Length of linked list: " << lengthofLL(head);
    return 0;
}
