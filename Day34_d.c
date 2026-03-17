/*Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory
allocation.

Input:
- Postfix expression with operands and operators

Output:
- Print the integer result

Example:
Input:
2 3 1 * + 9 -

Output:
-4

Explanation:
Use stack to store operands, apply operators by popping operands, push result back.
Final stack top is result.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = top;
    top = temp;
}

int pop() {
    if (top == NULL) return 0;
    struct Node* temp = top;
    int x = temp->data;
    top = top->next;
    free(temp);
    return x;
}

int main() {
    char exp[1000];
    fgets(exp, sizeof(exp), stdin);

    char *token = strtok(exp, " \n");

    while (token != NULL) {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            push(atoi(token));
        } else {
            int b = pop();
            int a = pop();
            switch (token[0]) {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': push(a / b); break;
            }
        }
        token = strtok(NULL, " \n");
    }

    printf("%d", pop());
    return 0;
}