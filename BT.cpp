#include <iostream>
#include <queue>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
};
Node* createNode()
{
    Node* root = new Node;
    root->left = NULL;
    root->right = NULL;
    return root;
}
Node* createBinaryTree()
{
    Node* root = createNode();
    cout << "Enter data: ";
    cin >> root->data;
    int l, r;
    cout << "Left child of " << root->data
         << "? (1 for Yes, 0 for No): ";
    cin >> l;
    if (l == 1)
        root->left = createBinaryTree();
    else
        root->left = NULL;
    cout << "Right child of " << root->data
         << "? (1 for Yes, 0 for No): ";
    cin >> r;
    if (r == 1)
        root->right = createBinaryTree();
    else
        root->right = NULL;
    return root;
}
Node* insertNode(Node* root, int value)
{
    Node* temp = new Node;
    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;
    if (root == NULL)
        return temp;
    queue<Node*> q;
    q.push(root);
    while (!q.empty())
    {
        Node* current = q.front();
        q.pop();
        if (current->left == NULL)
        {
            current->left = temp;
            return root;
        }
        else
            q.push(current->left);

        if (current->right == NULL)
        {
            current->right = temp;
            return root;
        }
        else
            q.push(current->right);
    }
    return root;
}
Node* deleteNode(Node* root, int value)
{
    if (root == NULL)
    {
        cout << "Tree is empty\n";
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    {
        if (root->data == value)
        {
            delete root;
            return NULL;
        }
        cout << "Value not found\n";
        return root;
    }
    queue<Node*> q;
    q.push(root);
    Node* target = NULL;
    Node* last = NULL;
    Node* parentLast = NULL;
    while (!q.empty())
    {
        Node* current = q.front();
        q.pop();
        if (current->data == value && target == NULL)
            target = current;
        if (current->left != NULL)
        {
            parentLast = current;
            last = current->left;
            q.push(current->left);
        }
        if (current->right != NULL)
        {
            parentLast = current;
            last = current->right;
            q.push(current->right);
        }
    }
    if (target == NULL)
    {
        cout << "Value not found\n";
        return root;
    }
    target->data = last->data;
    if (parentLast->right == last)
        parentLast->right = NULL;
    else
        parentLast->left = NULL;

    delete last;
    return root;
}
void inorder(Node* root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void preorder(Node* root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node* root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
void display(Node* root)
{
    if (root == NULL)
    {
        cout << "Tree is empty\n";
        return;
    }
    cout << "\nInorder: ";
    inorder(root);
    cout << "\nPreorder: ";
    preorder(root);
    cout << "\nPostorder: ";
    postorder(root);
    cout << endl;
}
int main()
{
    Node* root = NULL;
    int choice, value;
    do
    {
        cout << "\n1. Create Binary Tree";
        cout << "\n2. Insert Node";
        cout << "\n3. Delete Node";
        cout << "\n4. Display Tree";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;
        switch (choice)
        {
            case 1:
                root = createBinaryTree();
                break;
            case 2:
                cout << "Enter value to insert: ";
                cin >> value;
                root = insertNode(root, value);
                break;
            case 3:
                cout << "Enter value to delete: ";
                cin >> value;
                root = deleteNode(root, value);
                break;
            case 4:
                display(root);
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 5);
    return 0;
}