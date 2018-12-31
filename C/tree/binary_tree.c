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

int  main(int argc, char const *argv[])
{
    Node* root = newNode(1);

    root->left = newNode(2);
    root->right = newNode(3);

    getchar();
    return 0;
}
