/*Problem: Level Order Traversal

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

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Queue Node
struct QNode {
    struct Node* treeNode;
    struct QNode* next;
};

// Queue
struct Queue {
    struct QNode *front, *rear;
};

// Create Queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Enqueue
void enqueue(struct Queue* q, struct Node* node) {
    struct QNode* temp = (struct QNode*)malloc(sizeof(struct QNode));
    temp->treeNode = node;
    temp->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }

    q->rear->next = temp;
    q->rear = temp;
}

// Dequeue
struct Node* dequeue(struct Queue* q) {
    if (q->front == NULL)
        return NULL;

    struct QNode* temp = q->front;
    struct Node* node = temp->treeNode;

    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
    return node;
}

// Level Order Traversal
void levelOrder(struct Node* root) {
    if (root == NULL)
        return;

    struct Queue* q = createQueue();
    enqueue(q, root);

    while (q->front != NULL) {
        struct Node* current = dequeue(q);
        printf("%d ", current->data);

        if (current->left != NULL)
            enqueue(q, current->left);

        if (current->right != NULL)
            enqueue(q, current->right);
    }
}

// Build Tree (Level-wise input)
// Enter -1 for NULL
struct Node* buildTree() {
    int val;
    printf("Enter root value (-1 for NULL): ");
    scanf("%d", &val);

    if (val == -1)
        return NULL;

    struct Node* root = createNode(val);
    struct Queue* q = createQueue();
    enqueue(q, root);

    while (q->front != NULL) {
        struct Node* current = dequeue(q);

        int leftVal, rightVal;

        printf("Enter left child of %d (-1 for NULL): ", current->data);
        scanf("%d", &leftVal);
        if (leftVal != -1) {
            current->left = createNode(leftVal);
            enqueue(q, current->left);
        }

        printf("Enter right child of %d (-1 for NULL): ", current->data);
        scanf("%d", &rightVal);
        if (rightVal != -1) {
            current->right = createNode(rightVal);
            enqueue(q, current->right);
        }
    }

    return root;
}

// Main
int main() {
    struct Node* root = buildTree();

    printf("Level Order Traversal: ");
    levelOrder(root);

    return 0;
}