#include <stdio.h>

struct Node_t {
    int data;
    struct Node_t *left;
    struct Node_t *right;
};
typedef struct Node_t Node;

Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));

    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

// tree travel
void printPostOrder(Node* node) {
    if (node == NULL) {
        return;
    }

    printPostOrder(node->left);
    printPostOrder(node->right);

    printf("%d ", node->data);
}

void printPreOrder(Node* node) {
    if (node == NULL) {
        return;
    }

    printf("%d ", node->data);

    printPreOrder(node->left);
    printPreOrder(node->right);
}

void printInnerOrder(Node* node) {
    if (node == NULL) {
        return;
    }

    printInnerOrder(node->left);
    printf("%d ", node->data);
    printInnerOrder(node->right);
}

Node* insert(Node* node, int data) {
    if (node == NULL) {
        return newNode(data);
    } else {
        if (data <= node->data) {
            node->left = insert(node->left, data);
        } else {
            node->right = insert(node->right, data);
        }
        return node;
    }
}

int  main(int argc, char const *argv[])
{
    Node* root = newNode(4);

    insert(root, 2);
    insert(root, 5);
    insert(root, 1);
    insert(root, 3);

    // print
    printf("Post Order: ");
    printPostOrder(root);

    printf("\nPre Order: ");
    printPreOrder(root);

    printf("\nInner Order: ");
    printInnerOrder(root);

    getchar();
    return 0;
}
