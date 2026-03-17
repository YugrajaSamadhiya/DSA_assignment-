/*Problem: Deque (Double-Ended Queue)

A Deque is a linear data structure that allows insertion and deletion of elements
 from both the front and the rear. It provides more flexibility than a standard queue 
 or stack.

Common Operations:
1. push_front(value): Insert an element at the front of the deque.
2. push_back(value): Insert an element at the rear of the deque.
3. pop_front(): Remove an element from the front of the deque.
4. pop_back(): Remove an element from the rear of the deque.
5. front(): Return the front element of the deque.
6. back(): Return the rear element of the deque.
7. empty(): Check whether the deque is empty.
8. size(): Return the number of elements in the deque.

Additional Operations:
- clear(): Remove all elements from the deque.
- erase(): Remove one or more elements from the deque.
- swap(): Swap contents of two deques.
- emplace_front(): Insert an element at the front without copying.
- emplace_back(): Insert an element at the rear without copying.
- resize(): Change the size of the deque.
- assign(): Replace elements with new values.
- reverse(): Reverse the order of elements.
- sort(): Sort the elements in ascending order.

Time Complexity:
- push_front, push_back, pop_front, pop_back, front, back, empty, size: O(1)
- clear, erase, resize, assign, reverse: O(n)
- sort: O(n log n)

Input:
- Sequence of deque operations with values (if applicable)

Output:
- Results of operations such as front, back, size, or the final state of the deque after
 all operations*/
 #include <stdio.h>
#include <string.h>

int dq[1000];
int front = -1, rear = -1;

int isEmpty() {
    return front == -1;
}

int size() {
    if (isEmpty()) return 0;
    return rear - front + 1;
}

void push_front(int x) {
    if (isEmpty()) {
        front = rear = 0;
        dq[front] = x;
    } else {
        front--;
        dq[front] = x;
    }
}

void push_back(int x) {
    if (isEmpty()) {
        front = rear = 0;
        dq[rear] = x;
    } else {
        rear++;
        dq[rear] = x;
    }
}

int pop_front() {
    if (isEmpty()) return -1;
    int val = dq[front];
    if (front == rear) front = rear = -1;
    else front++;
    return val;
}

int pop_back() {
    if (isEmpty()) return -1;
    int val = dq[rear];
    if (front == rear) front = rear = -1;
    else rear--;
    return val;
}

int get_front() {
    if (isEmpty()) return -1;
    return dq[front];
}

int get_back() {
    if (isEmpty()) return -1;
    return dq[rear];
}

void clear() {
    front = rear = -1;
}

void reverse() {
    int i = front, j = rear;
    while (i < j) {
        int temp = dq[i];
        dq[i] = dq[j];
        dq[j] = temp;
        i++;
        j--;
    }
}

void sort() {
    for (int i = front; i <= rear; i++) {
        for (int j = i + 1; j <= rear; j++) {
            if (dq[i] > dq[j]) {
                int temp = dq[i];
                dq[i] = dq[j];
                dq[j] = temp;
            }
        }
    }
}

int main() {
    int n, x;
    char op[30];
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", op);

        if (strcmp(op, "push_front") == 0) {
            scanf("%d", &x);
            push_front(x);
        } else if (strcmp(op, "push_back") == 0) {
            scanf("%d", &x);
            push_back(x);
        } else if (strcmp(op, "pop_front") == 0) {
            printf("%d\n", pop_front());
        } else if (strcmp(op, "pop_back") == 0) {
            printf("%d\n", pop_back());
        } else if (strcmp(op, "front") == 0) {
            printf("%d\n", get_front());
        } else if (strcmp(op, "back") == 0) {
            printf("%d\n", get_back());
        } else if (strcmp(op, "empty") == 0) {
            printf("%d\n", isEmpty());
        } else if (strcmp(op, "size") == 0) {
            printf("%d\n", size());
        } else if (strcmp(op, "clear") == 0) {
            clear();
        } else if (strcmp(op, "reverse") == 0) {
            reverse();
        } else if (strcmp(op, "sort") == 0) {
            sort();
        }
    }

    for (int i = front; i <= rear; i++) {
        printf("%d ", dq[i]);
    }

    return 0;
}