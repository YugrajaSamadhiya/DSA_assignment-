/*Problem: Height of Binary Tree

Implement the solution for this problem.

Input:
- Input specifications

Output:
- Output specifications*/
#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create Node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Height Function
int height(struct Node* root) {
    if (root == NULL)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Build Tree (Level-wise input)
struct Node* buildTree() {
    int val;
    printf("Enter root value (-1 for NULL): ");
    scanf("%d", &val);

    if (val == -1)
        return NULL;

    struct Node* root = createNode(val);

    struct Node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        struct Node* current = queue[front++];

        int leftVal, rightVal;

        printf("Enter left child of %d (-1 for NULL): ", current->data);
        scanf("%d", &leftVal);

        if (leftVal != -1) {
            current->left = createNode(leftVal);
            queue[rear++] = current->left;
        }

        printf("Enter right child of %d (-1 for NULL): ", current->data);
        scanf("%d", &rightVal);

        if (rightVal != -1) {
            current->right = createNode(rightVal);
            queue[rear++] = current->right;
        }
    }

    return root;
}

// Main
int main() {
    struct Node* root = buildTree();

    int h = height(root);
    printf("Height of Binary Tree = %d\n", h);

    return 0;
}