
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node {
    int key;
    struct Node *left, *right;
};

// Create node
struct Node* createNode(int key) {

    struct Node *node = malloc(sizeof(struct Node));

    node->key = key;
    node->left = NULL;
    node->right = NULL;

    return node;
}

// Maximum of two values
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Insert node in BST
struct Node* insert(struct Node* root, int key) {

    if (root == NULL)
        return createNode(key);

    if (key < root->key)
        root->left = insert(root->left, key);

    else if (key > root->key)
        root->right = insert(root->right, key);

    return root;
}

// Check BST property
int checkBST(struct Node* root, long min, long maxValue) {

    if (root == NULL)
        return 1;

    if (root->key <= min || root->key >= maxValue)
        return 0;

    return checkBST(root->left, min, root->key) &&
           checkBST(root->right, root->key, maxValue);
}

// Check AVL balance and calculate height
int checkAVL(struct Node* root) {

    if (root == NULL)
        return 0;

    int lh = checkAVL(root->left);

    if (lh == -1)
        return -1;

    int rh = checkAVL(root->right);

    if (rh == -1)
        return -1;

    if (abs(lh - rh) > 1)
        return -1;

    return 1 + max(lh, rh);
}

int main() {

    struct Node *root = NULL;
    int n, key;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter values:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &key);
        root = insert(root, key);
    }

    if (checkBST(root, LONG_MIN, LONG_MAX) &&
        checkAVL(root) != -1)

        printf("Tree is AVL Tree");

    else
        printf("Tree is NOT an AVL Tree");

    return 0;
}
