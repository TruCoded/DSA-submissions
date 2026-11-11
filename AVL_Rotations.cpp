
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};

// Get height
int getHeight(struct Node *n) {
    if(n == NULL)
        return 0;
    return n->height;
}

// Maximum of two values
int max(int a, int b) {
    return a > b ? a : b;
}

// Create new node
struct Node *createNode(int key) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));

    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;

    return node;
}

// Calculate balance factor
int getBalanceFactor(struct Node *n) {
    if(n == NULL)
        return 0;

    return getHeight(n->left) - getHeight(n->right);
}

// Right Rotation
struct Node *rightRotate(struct Node *y) {
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + max(getHeight(y->left),
                        getHeight(y->right));

    x->height = 1 + max(getHeight(x->left),
                        getHeight(x->right));

    return x;
}

// Left Rotation
struct Node *leftRotate(struct Node *x) {
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + max(getHeight(x->left),
                        getHeight(x->right));

    y->height = 1 + max(getHeight(y->left),
                        getHeight(y->right));

    return y;
}

// INSERTION
struct Node *insert(struct Node *node, int key) {

    if(node == NULL)
        return createNode(key);

    if(key < node->key)
        node->left = insert(node->left, key);

    else if(key > node->key)
        node->right = insert(node->right, key);

    else
        return node;

    // Update height
    node->height = 1 + max(getHeight(node->left),
                           getHeight(node->right));

    int bf = getBalanceFactor(node);

    // LL Case
    if(bf > 1 && key < node->left->key)
        return rightRotate(node);

    // RR Case
    if(bf < -1 && key > node->right->key)
        return leftRotate(node);

    // LR Case
    if(bf > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // RL Case
    if(bf < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Find minimum value node
struct Node *minValueNode(struct Node *node) {

    struct Node *current = node;

    while(current->left != NULL)
        current = current->left;

    return current;
}

// DELETION
struct Node *deleteNode(struct Node *root, int key) {

    if(root == NULL)
        return root;

    // Search for the node
    if(key < root->key)
        root->left = deleteNode(root->left, key);

    else if(key > root->key)
        root->right = deleteNode(root->right, key);

    else {

        // Case 1: No child (leaf node)
        if(root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }

        // Case 2: Only right child
        else if(root->left == NULL) {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }

        // Case 2: Only left child
        else if(root->right == NULL) {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }

        // Case 3: Two children
        else {
            struct Node *temp = minValueNode(root->right);

            root->key = temp->key;

            root->right = deleteNode(root->right, temp->key);
        }
    }

    // Update height
    root->height = 1 + max(getHeight(root->left),
                           getHeight(root->right));

    int bf = getBalanceFactor(root);

    // LL Case
    if(bf > 1 && getBalanceFactor(root->left) >= 0)
        return rightRotate(root);

    // LR Case
    if(bf > 1 && getBalanceFactor(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RR Case
    if(bf < -1 && getBalanceFactor(root->right) <= 0)
        return leftRotate(root);

    // RL Case
    if(bf < -1 && getBalanceFactor(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// SEARCH
struct Node *search(struct Node *root, int key) {

    if(root == NULL || root->key == key)
        return root;

    if(key < root->key)
        return search(root->left, key);

    return search(root->right, key);
}

// INORDER: Left Root Right
void inOrder(struct Node *root) {
    if(root != NULL) {
        inOrder(root->left);
        printf("%d ", root->key);
        inOrder(root->right);
    }
}

// PREORDER: Root Left Right
void preOrder(struct Node *root) {
    if(root != NULL) {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// MAIN
int main() {

    struct Node *root = NULL;
    int choice, key;

    while(1) {

        printf("\n\n--- AVL TREE MENU ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Inorder Traversal\n");
        printf("5. Preorder Traversal\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &key);

                root = insert(root, key);
                printf("Insertion completed.");
                break;

            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &key);

                if(search(root, key) == NULL)
                    printf("Value not found.");
                else {
                    root = deleteNode(root, key);
                    printf("Deletion completed.");
                }
                break;

            case 3:
                printf("Enter value to search: ");
                scanf("%d", &key);

                if(search(root, key) != NULL)
                    printf("Value found.");
                else
                    printf("Value not found.");
                break;

            case 4:
                printf("Inorder: ");
                inOrder(root);
                break;

            case 5:
                printf("Preorder: ");
                preOrder(root);
                break;

            case 6:
                printf("Exiting...");
                return 0;

            default:
                printf("Invalid choice.");
        }
    }

    return 0;
}
