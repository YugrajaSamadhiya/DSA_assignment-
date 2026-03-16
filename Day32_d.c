/*Problem: Implement push and pop operations on a stack and verify stack operations.

Input:
- First line: integer n
- Second line: n integers to push
- Third line: integer m (number of pops)

Output:
- Print remaining stack elements from top to bottom

Example:
Input:
5
10 20 30 40 50
2

Output:
30 20 10*/
#include <stdio.h>

int stack[100];
int top = -1;

void push(int x){
    stack[++top] = x;
}

void pop(){
    if(top != -1)
        top--;
}

int main(){
    int n,m,x,i;

    scanf("%d",&n);

    for(i=0;i<n;i++){
        scanf("%d",&x);
        push(x);
    }

    scanf("%d",&m);

    for(i=0;i<m;i++)
        pop();

    for(i=top;i>=0;i--){
        printf("%d",stack[i]);
        if(i!=0) printf(" ");
    }

    return 0;
}