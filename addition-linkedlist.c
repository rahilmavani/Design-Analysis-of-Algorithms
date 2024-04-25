#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct Node {
    int val;
    struct Node *next;
};

void add_first(struct Node **head, int val) {
    struct Node *newnode = (struct Node*) malloc(sizeof(struct Node*));
    newnode -> next = NULL;
    newnode -> val = val;

    if(*head == NULL) {
        *head = newnode;
    }
    else{
        newnode -> next = *head;
        *head = newnode;   
    }
}

void make_linked_list(struct Node **head, int data) {
    while(data > 0) {
        add_first(head, data % 10);
        data = data / 10;
    }
}

void traversal(struct Node **head) {
    struct Node *temp = *head;
    while(temp != NULL) {
        printf("%d ", temp -> val);
        temp = temp -> next;
    }
    printf("\n");
}

struct Node *reverse_linked_list(struct Node *head) {
    struct Node *newhead = NULL;
    struct Node *temp = head;
    while(temp != NULL) {
        add_first(&newhead, temp -> val);
        temp = temp -> next;
    }
    return newhead;
}

struct Node *add_linked_list(struct Node *head1, struct Node *head2) {
    
    struct Node *revhead1 = reverse_linked_list(head1);
    struct Node *revhead2 = reverse_linked_list(head2);
    struct Node *temp1 = revhead1;
    struct Node *temp2 = revhead2;
    struct Node *head = NULL;
    int carry = 0;
    int x,y;

    while(temp1 != NULL || temp2 != NULL) {
        if (temp1 == NULL) {
            x = 0;
        }
        else {
            x = temp1 -> val;
            temp1 = temp1 -> next;
        }
        if (temp2 == NULL) {
            y = 0;
        }
        else {
            y = temp2 -> val;
            temp2 = temp2 -> next;
        }

        carry += x + y;
        add_first(&head, carry % 10);
        carry = carry / 10;
    }

    if(carry > 0) {
        add_first(&head, carry);
    }
    return head;
}

void main(){

    int x,y;
    printf("Enter two numbers: \n");
    scanf("%d",&x);
    scanf("%d",&y);

    struct Node *head1 = NULL;
    struct Node *head2 = NULL;
    struct Node *head3 = NULL;

    make_linked_list(&head1, x);
    make_linked_list(&head2, y);
    head3 = add_linked_list(head1, head2);
    traversal(&head3);
}