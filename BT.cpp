
#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

// Create a node
Node* createNode(int value) {
    Node* temp = new Node;
    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// Create Binary Tree
Node* createTree() {
    int value, l, r;

    cout << "Enter data: ";
    cin >> value;

    Node* root = createNode(value);

    cout << "Left child of " << value << "? (1/0): ";
    cin >> l;
    if (l == 1)
        root->left = createTree();

    cout << "Right child of " << value << "? (1/0): ";
    cin >> r;
    if (r == 1)
        root->right = createTree();

    return root;
}

// Insert using BFS
Node* insertNode(Node* root, int value) {
    Node* temp = createNode(value);

    if (root == NULL)
        return temp;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        if (curr->left == NULL) {
            curr->left = temp;
            return root;
        }
        q.push(curr->left);

        if (curr->right == NULL) {
            curr->right = temp;
            return root;
        }
        q.push(curr->right);
    }

    return root;
}

// Delete using deepest rightmost node
Node* deleteNode(Node* root, int value) {
    if (root == NULL) {
        cout << "Tree is empty";
        return NULL;
    }

    queue<Node*> q;
    q.push(root);

    Node* target = NULL;
    Node* last = NULL;
    Node* parent = NULL;

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        if (curr->data == value && target == NULL)
            target = curr;

        if (curr->left != NULL) {
            parent = curr;
            last = curr->left;
            q.push(curr->left);
        }

        if (curr->right != NULL) {
            parent = curr;
            last = curr->right;
            q.push(curr->right);
        }
    }

    if (target == NULL) {
        cout << "Value not found";
        return root;
    }

    // Only one node
    if (last == NULL) {
        delete root;
        return NULL;
    }

    target->data = last->data;

    if (parent->left == last)
        parent->left = NULL;
    else
        parent->right = NULL;

    delete last;
    return root;
}

// Inorder: Left Root Right
void inorder(Node* root) {
    if (root == NULL) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Preorder: Root Left Right
void preorder(Node* root) {
    if (root == NULL) return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Postorder: Left Right Root
void postorder(Node* root) {
    if (root == NULL) return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = NULL;
    int choice, value;

    do {
        cout << "\n1. Create Tree";
        cout << "\n2. Insert";
        cout << "\n3. Delete";
        cout << "\n4. Display";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                root = createTree();
                break;

            case 2:
                cout << "Enter value: ";
                cin >> value;
                root = insertNode(root, value);
                break;

            case 3:
                cout << "Enter value: ";
                cin >> value;
                root = deleteNode(root, value);
                break;

            case 4:
                cout << "Inorder: ";
                inorder(root);

                cout << "\nPreorder: ";
                preorder(root);

                cout << "\nPostorder: ";
                postorder(root);
                break;

            case 5:
                cout << "Exiting...";
                break;

            default:
                cout << "Invalid choice";
        }

    } while (choice != 5);

    return 0;
}
