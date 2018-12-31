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

int  main(int argc, char const *argv[])
{
    Node* root = newNode(4);

    root->left = newNode(2);
    root->right = newNode(5);

    root->left->left = newNode(1);
    root->left->right = newNode(3);

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
