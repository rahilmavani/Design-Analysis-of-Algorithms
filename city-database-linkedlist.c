#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct Node {
    char name[50];
    int x;
    int y;
    struct Node *next;
} node;

void insert(struct Node **head, char given_name[50], int given_x, int given_y) {
    struct Node *newnode = (node *)(malloc(sizeof(node *)));
    strcpy(newnode -> name, given_name);
    newnode -> next = NULL;
    newnode -> x = given_x;
    newnode -> y = given_y;
    if (*head == NULL) {
        *head = newnode;
        return;
    }
    newnode -> next = *head;
    *head = newnode;
}

void display(node *temp) {
    while(temp != NULL) {
        printf("City: %s (%d, %d)", temp -> name, temp -> x, temp -> y);
        temp = temp -> next;
    }
}


void search_by_name(node **head, char given_name[50]) {
    node *temp = *head;
    while(temp != NULL) {
        if(!strcmp(temp -> name, given_name)) {
            printf("City: %s (%d, %d)", temp -> name, temp -> x, temp -> y);
            return;    
        }
        temp = temp -> next;
    }
    printf("%s not found.\n", given_name);
}

void search_by_coordinate(node **head, int given_x, int given_y) {
    node *temp = *head;
    while(temp != NULL) {
         if(temp -> x == given_x && temp -> y == given_y) {
            printf("City: %s (%d, %d)", temp -> name, temp -> x, temp -> y);
            return;    
        }
        temp = temp -> next;
    }
    printf("City with coordinates (%d, %d) not found.\n", given_x, given_y);
}

void delete_by_name(node **head, char given_name[50]) {
    node *temp = *head;
    node *prev = NULL;

    if (temp != NULL && !strcmp(temp->name, given_name)) {
        *head = temp->next;
        free(temp);
        return;
    }
    
    while (temp != NULL && strcmp(temp->name, given_name)) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("%s not found.\n", given_name);
        return;
    }

    prev->next = temp->next;
    free(temp);
}

void delete_by_coordinate(node **head, int given_x, int given_y) {
    node *temp = *head;
    node *prev = NULL;
    while (temp != NULL) {
        if(temp -> x == given_x && temp -> y == given_y) {
            if (prev == NULL) {
                *head = temp->next;
            } 
            else {
                prev->next = temp->next;
            }
            free(temp);
            return;
        }
        prev = temp;
        temp = temp -> next;
    }
    printf("City with coordinates (%d, %d) not found.\n", given_x, given_y);
}

void search_within_radius(node **head, int given_x, int given_y, int rad) {
    node *temp = *head;
    while(temp != NULL) {
        int x1 = temp -> x;
        int y1 = temp -> y;
        double distance = sqrt(pow(given_x - x1, 2) + pow(given_y - y1, 2));
        if(distance <= rad) {
            printf("City: %s (%d, %d)\n", temp -> name, temp -> x, temp -> y);
        }
        temp = temp -> next;
    }
}


int main() {
    int choice;
    char name_input[50];
    int x_input, y_input;
    int radius;
    node *head = NULL;

    do {
        printf("\nMenu:\n");
        printf("1. Display all cities\n");
        printf("2. Search for a city by name\n");
        printf("3. Search for a city by coordinates\n");
        printf("4. Insert a new city\n");
        printf("5. Delete a city by name\n");
        printf("6. Delete a city by coordinates\n");
        printf("7. Search within a radius\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 
        
        switch(choice) {
            case 1:
                printf("Displaying all cities:\n");
                display(head);
                break;
            case 2:
                printf("Enter the name of the city: ");
                scanf("%s", name_input);
                search_by_name(&head, name_input);
                break;
            case 3:
                printf("Enter the coordinates (x y) of the city: ");
                scanf("%d %d", &x_input, &y_input);
                search_by_coordinate(&head, x_input, y_input);
                break;
            case 4:
                printf("Enter the name, x coordinate, and y coordinate of the city: ");
                scanf("%s %d %d", name_input, &x_input, &y_input);
                insert(&head, name_input, x_input, y_input);
                break;
            case 5:
                printf("Enter the name of the city to delete: ");
                scanf("%s", name_input);
                delete_by_name(&head, name_input);
                break;
            case 6:
                printf("Enter the coordinates (x y) of the city to delete: ");
                scanf("%d %d", &x_input, &y_input);
                delete_by_coordinate(&head, x_input, y_input);
                break;
            case 7:
                printf("Enter the coordinates (x y) and radius of the search area: ");
                scanf("%d %d %d", &x_input, &y_input, &radius);
                search_within_radius(&head, x_input, y_input, radius);
                break;
            case 8:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 8.\n");
        }
    } while(choice != 8);

    return 0;
}
