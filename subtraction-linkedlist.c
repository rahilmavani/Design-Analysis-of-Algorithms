#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int val;
    struct Node *next;
    int size;
};

void add_first(struct Node **head, int val)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node *));
    newnode->next = NULL;
    newnode->val = val;

    if (*head == NULL)
    {
        *head = newnode;
    }
    else
    {
        newnode->next = *head;
        *head = newnode;
    }
}

void make_linked_list(struct Node **head, int data)
{
    while (data > 0)
    {
        add_first(head, data % 10);
        data = data / 10;
    }
}

void traversal(struct Node **head)
{
    struct Node *temp = *head;
    while (temp != NULL)
    {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

struct Node *reverse_linked_list(struct Node *head)
{
    struct Node *newhead = NULL;
    struct Node *temp = head;
    while (temp != NULL)
    {
        add_first(&newhead, temp->val);
        temp = temp->next;
    }
    return newhead;
}

struct Node *subtraction(struct Node *head1, struct Node *head2)
{
    struct Node *revhead1 = reverse_linked_list(head1);
    struct Node *revhead2 = reverse_linked_list(head2);
    struct Node *head = NULL;

    int x = 0;
    int y = 0;

    struct Node *temp3 = revhead1;
    struct Node *temp4 = revhead2;
    int borrow = 0;

    while (temp3 != NULL)
    {
        x = temp3->val + borrow;
        temp3 = temp3->next;

        if (temp4 == NULL)
        {
            y = 0;
        }
        else
        {
            y = temp4->val;
            temp4 = temp4->next;
        }

        if (x >= y)
        {
            add_first(&head, (x - y));
            borrow = 0;
        }
        else
        {
            borrow = -1;
            add_first(&head, (10 + x - y));
        }
    }
    return head;
}

struct Node *removezero(struct Node *head)
{
    while (head->val == 0)
    {
        head = head->next;
    }
    return head;
}

int size(struct Node *head)
{
    int count = 0;
    struct Node *temp1 = head;
    while (temp1 != NULL)
    {
        count++;
        temp1 = temp1 -> next;
    }
    return count;
}

struct Node *subtract_linked_list(struct Node *head1, struct Node *head2)
{
    struct Node *head = NULL;
    head1 = removezero(head1);
    head2 = removezero(head2);
    int size1 = size(head1);
    int size2 = size(head2);
    int x = 0, y = 0, borrow = 0;
    struct Node *temp1 = head1;
    struct Node *temp2 = head2;

    if (size1 > size2)
    {
        head = subtraction(head1, head2);
        head = removezero(head);
        return head;
    }
    else if (size2 > size1)
    {

        head = subtraction(head2, head1);
        head = removezero(head);
        return head;
    }
    else
    {
        temp1 = head1;
        temp2 = head2;
        while (temp1 != NULL)
        {
            if (temp1->val > temp2->val)
            {
                head = subtraction(head1, head2);
                head = removezero(head);
                return head;
            }
            else if (temp2->val > temp1->val)
            {
                head = subtraction(head2, head1);
                head = removezero(head);
                return head;
            }
            else
            {
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
        }
        add_first(&head, 0);
        return head;
    }
}

void main()
{
    int x, y;
    printf("Enter two numbers: \n");
    scanf("%d", &x);
    scanf("%d", &y);

    struct Node *head1 = NULL;
    struct Node *head2 = NULL;
    struct Node *head3 = NULL;

    make_linked_list(&head1, x);
    make_linked_list(&head2, y);
    head3 = subtract_linked_list(head1, head2);
    traversal(&head3);
}