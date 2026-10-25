#include <iostream>
using namespace std;
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
    Node(int val) {
        this->val = val;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }
};

Node* insert(Node* root, int value) {
    // Case 1: Empty tree
    if (root == nullptr) {
        return new Node(value);
    }

    // Case 2: Insert in left subtree
    if (value < root->val) {
        if (root->left == nullptr) {
            Node* temp = new Node(value);
            root->left = temp;
            temp->parent = root;
        }
        else {
            insert(root->left, value);
        }
    }

    // Case 3: Insert in right subtree
    else if (value > root->val) {
        if (root->right == nullptr) {
            Node* temp = new Node(value);
            root->right = temp;
            temp->parent = root;
        }
        else {
            insert(root->right, value);
        }
    }

    // Case 4: Duplicate value
    else {
        cout << "Duplicate value not allowed\n";
    }

    return root;
}

// CREATE BST
Node* createBST() {
    Node* root = nullptr;
    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter value: ";
        cin >> value;
        root = insert(root, value);
    }

    return root;
}

// SEARCH
Node* search(Node* root, int value) {
    if (root == nullptr || root->val == value)
        return root;

    if (value < root->val)
        return search(root->left, value);

    return search(root->right, value);
}

// FIND MAXIMUM NODE
Node* maxNode(Node* temp) {
    while (temp->right != nullptr)
        temp = temp->right;

    return temp;
}

// DELETE
Node* Delete(Node* root, int value) {
    Node* target = search(root, value);

    if (target == nullptr) {
        cout << "Value not found\n";
        return root;
    }

    // Case 1: No children
    if (target->left == nullptr &&
        target->right == nullptr) {

        if (target->parent == nullptr) {
            delete target;
            return nullptr;
        }

        if (target->parent->left == target)
            target->parent->left = nullptr;
        else
            target->parent->right = nullptr;

        delete target;
    }

    // Case 2: One child
    else if (target->left == nullptr ||
             target->right == nullptr) {

        Node* child;

        if (target->left != nullptr)
            child = target->left;
        else
            child = target->right;

        if (target->parent == nullptr) {
            child->parent = nullptr;
            delete target;
            return child;
        }

        if (target->parent->left == target)
            target->parent->left = child;
        else
            target->parent->right = child;

        child->parent = target->parent;
        delete target;
    }

    // Case 3: Two children
    else {
        Node* temp = maxNode(target->left);

        target->val = temp->val;

        if (temp->parent->right == temp)
            temp->parent->right = temp->left;
        else
            temp->parent->left = temp->left;

        if (temp->left != nullptr)
            temp->left->parent = temp->parent;

        delete temp;
    }

    return root;
}

// DISPLAY (INORDER)
void display(Node* root) {
    if (root == nullptr)
        return;

    display(root->left);
    cout << root->val << " ";
    display(root->right);
}

int main() {
    Node* root = createBST();

    cout << "\nBST: ";
    display(root);

    int choice, value;

    do {
        cout << "\n\n1. Insert";
        cout << "\n2. Search";
        cout << "\n3. Delete";
        cout << "\n4. Display";
        cout << "\n0. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            root = insert(root, value);
            break;

        case 2:
            cout << "Enter value to search: ";
            cin >> value;

            if (search(root, value) != nullptr)
                cout << "Value found";
            else
                cout << "Value not found";
            break;

        case 3:
            cout << "Enter value to delete: ";
            cin >> value;
            root = Delete(root, value);
            break;

        case 4:
            cout << "BST: ";
            display(root);
            break;

        case 0:
            cout << "Exiting...";
            break;

        default:
            cout << "Invalid choice";
        }

    } while (choice != 0);

    return 0;
}