Is output input correct:-
#include <bits/stdc++.h>
using namespace std;
struct Node {
int data;
Node* next;
Node(int x) {
data = x;
next = NULL;
}
};
Node* partition(Node* low, Node* high) {
int pivot = high->data;
Node* i = low;
for (Node* j = low; j != high; j = j->next) {
if (j->data <= pivot) {
swap(i->data, j->data);
i = i->next;
}
}
swap(i->data, high->data);
return i;
}
int getpos(Node* head, Node* node) {
int pos = 0;
while (head != node) {
head = head->next;
pos++;
}
return pos;
}
void selectk(Node* head, int k) {
if (head == NULL || k < 0) {
return;
}
Node* low = head;
Node* high = head;
while (high->next != NULL) {
high = high->next;
}
while (low != NULL && high != NULL) {
Node* pivotNode = partition(low, high);
int pivotpos = getpos(head, pivotNode);
if (pivotpos == k) {    
    return;    
}    
else if (pivotpos < k) {    
    low = pivotNode->next;    
}    
else {    
    Node* temp = low;    

    while (temp->next != pivotNode) {    
        temp = temp->next;    
    }    
    high = temp;    
}
}
}
int main() {
int n, x, k;
cin >> n;
Node* head = NULL;
Node* tail = NULL;
for (int i = 0; i < n; i++) {
cin >> x;
Node* newNode = new Node(x);
if (head == NULL) {    
    head = tail = newNode;    
}    
else {    
    tail->next = newNode;    
    tail = newNode;    
}
}
cin >> k;
if (k < 1 || k > n) {
cout << "Invalid k";
return 0;
}
selectk(head, k - 1);
cout << k << "th/rd smallest element: ";
Node* temp = head;
for (int i = 0; i < k - 1 ; i++) {
temp = temp->next;
}
cout << temp->data;
return 0;
}