/*Problem: Find Intersection Point of Two Linked Lists - Implement using linked list 
with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print value of intersection node or 'No Intersection'

Example:
Input:
5
10 20 30 40 50
4
15 25 30 40 50

Output:
30

Explanation:
Calculate lengths, advance pointer in longer list, traverse both simultaneously.
First common node is intersection.*/
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int length(struct Node *head)
{
    int count = 0;
    while(head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

int main()
{
    int n, m;
    struct Node *head1 = NULL, *head2 = NULL;
    struct Node *temp = NULL, *newNode;

    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d",&newNode->data);
        newNode->next = NULL;

        if(head1 == NULL)
        {
            head1 = newNode;
            temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }

    scanf("%d",&m);

    for(int i=0;i<m;i++)
    {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d",&newNode->data);
        newNode->next = NULL;

        if(head2 == NULL)
        {
            head2 = newNode;
            temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }

    int len1 = length(head1);
    int len2 = length(head2);

    struct Node *p = head1;
    struct Node *q = head2;

    int diff = abs(len1 - len2);

    if(len1 > len2)
        for(int i=0;i<diff;i++) p = p->next;
    else
        for(int i=0;i<diff;i++) q = q->next;

    while(p != NULL && q != NULL)
    {
        if(p->data == q->data)
        {
            printf("%d", p->data);
            return 0;
        }

        p = p->next;
        q = q->next;
    }

    printf("No Intersection");

    return 0;
}