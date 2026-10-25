#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
// Heapify
Node* heapify(Node* root) {
    if (root == nullptr) {
        return root;
    }
    Node* largest = root;
    if (root->left != nullptr &&
        root->left->data > largest->data) {
        largest = root->left;
    }
    if (root->right != nullptr &&
        root->right->data > largest->data) {
        largest = root->right;
    }
    if (largest != root) {
        swap(root->data, largest->data);
        heapify(largest);
    }
    return root;
}
// Build max heap
Node* Build_Heap(Node* root) {
    if (root == nullptr) {
        return root;
    }
    Build_Heap(root->left);
    Build_Heap(root->right);
    return heapify(root);
}
// Create a binary tree level by level
Node* createTree(int n) {
    if (n <= 0) {
        return nullptr;
    }
    int val;
    cout << "Enter root value: ";
    cin >> val;
    Node* root = new Node(val);
    queue<Node*> q;
    q.push(root);
    int count = 1;
    while (!q.empty() && count < n) {
        Node* temp = q.front();
        q.pop();
        cout << "Enter left child of " << temp->data
             << " (-1 for no child): ";
        cin >> val;
        if (val != -1 && count < n) {
            temp->left = new Node(val);
            q.push(temp->left);
            count++;
        }
        if (count >= n) {
            break;
        }
        cout << "Enter right child of " << temp->data
             << " (-1 for no child): ";
        cin >> val;
        if (val != -1 && count < n) {
            temp->right = new Node(val);
            q.push(temp->right);
            count++;
        }
    }
    return root;
}
// Display tree level order
void display(Node* root) {
    if (root == nullptr) {
        cout << "Empty tree\n";
        return;
    }
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if (temp->left != nullptr) {
            q.push(temp->left);
        }
        if (temp->right != nullptr) {
            q.push(temp->right);
        }
    }
    cout << endl;
}
int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;
    if (n <= 0) {
        cout << "Invalid number of nodes\n";
        return 0;
    }
    Node* root = createTree(n);
    cout << "\nBefore building max heap: ";
    display(root);
    root = Build_Heap(root);
    cout << "After building max heap: ";
    display(root);
    return 0;
}
