#include <iostream>
#include <algorithm>
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
int height(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    return 1 + max(height(root->left), height(root->right));
}
bool isBST(Node* root, long long minVal, long long maxVal) {
    if (root == nullptr) {
        return true;
    }
    if (root->data <= minVal || root->data >= maxVal) {
        return false;
    }
    return isBST(root->left, minVal, root->data) &&
           isBST(root->right, root->data, maxVal);
}
bool isAVL(Node* root) {
    if (root == nullptr) {
        return true;
    }
    int bf = height(root->left) - height(root->right);
    if (bf < -1 || bf > 1) {
        return false;
    }
    return isAVL(root->left) && isAVL(root->right);
}
Node* createTree() {
    int val;
    cout << "Enter node value (-1 for no node): ";
    cin >> val;
    if (val == -1) {
        return nullptr;
    }
    Node* root = new Node(val);
    cout << "Left child of " << val << ":\n";
    root->left = createTree();
    cout << "Right child of " << val << ":\n";
    root->right = createTree();
    return root;
}
int main() {
    cout << "Create the binary tree:\n";
    Node* root = createTree();
    if (isBST(root, LLONG_MIN, LLONG_MAX) && isAVL(root)) {
        cout << "The tree is an AVL tree.";
    } else {
        cout << "The tree is NOT an AVL tree.";
    }
    return 0;
}