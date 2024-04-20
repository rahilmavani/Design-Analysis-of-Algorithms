#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

char name[50][50];
int x[50];
int y[50];
int size = 0;

void display() {
    for(int i = 0; i < size; i++) {
        printf("%s (%d, %d)\n", name[i], x[i], y[i]);
    }
}

void display_index(int index) {
    printf("%s (%d, %d) \n", name[index], x[index], y[index]);
}

void insert(char given_name[50], int given_x, int given_y) {
    strcpy(name[size], given_name);
    x[size] = given_x;
    y[size] = given_y;
    size++;
}

int search_by_name(char given_name[50]) {
    for(int i = 0; i < size; i++) {
        if(!strcmp(given_name, name[i])) {
            display_index(i);
            return i;
        }
    }
    printf("City not found.");
    return -1;
}

int search_by_coordinate(int given_x, int given_y) {
    for(int i = 0; i < size; i++) {
        if(x[i] == given_x && y[i] == given_y) {
            display_index(i);
            return i;
        }
    }
    printf("City not found.");
    return -1;
}

void delete_by_coordinate(int given_x, int given_y) {
    int index = search_by_coordinate(given_x, given_y);
    if(index == -1) {
        return;
    }
    else {
        for(int i = index; i < size - 1; i++) {
            strcpy(name[i], name[i+1]);
            x[i] = x[i+1];
            y[i] = y[i+1];
        }
        size--;
    }
}

void delete_by_name(char given_name[50]) {
    int index = search_by_name(given_name);
    if(index == -1) {
        return;
    }
    else{
        for(int i = index;i < size - 1; i++){
            strcpy(name[i], name[i+1]);
            x[i] = x[i+1];
            y[i] = y[i+1];
        }
        size--;
    }
}

void search_within_radius(int given_x, int given_y, int dist) {
    int count = 0;
    for(int i = 0; i < size; i++) {
        double nearby = sqrt(pow(x[i] - given_x, 2) + pow(y[i] - given_y, 2));
        if (nearby <= dist) {
            display_index(i);
            count++;
        }
    }
    if(count == 0) {
        printf("No city found in range.");
    }
}

int main() {
    int choice;
    char name_input[50];
    int x_input, y_input;
    int radius;
    int scanf_result; // to store the result of scanf

    do {
        printf("\nMenu:\n");
        printf("1. Display all cities\n");
        printf("2. Search for a city by name\n");
        printf("3. Search for a city by coordinates\n");
        printf("4. Insert a new city\n");
        printf("5. Delete a city by name\n");
        printf("6. Search within a radius\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf_result = scanf("%d", &choice);
        getchar();
        

        switch(choice) {
            case 1:
                printf("Displaying all cities:\n");
                display();
                break;
            case 2:
                printf("Enter the name of the city: ");
                scanf("%s", name_input);
                search_by_name(name_input);
                break;
            case 3:
                printf("Enter the coordinates (x y) of the city: ");
                scanf("%d %d", &x_input, &y_input);
                search_by_coordinate(x_input, y_input);
                break;
            case 4:
                printf("Enter the name, x coordinate, and y coordinate of the city: ");
                scanf("%s %d %d", name_input, &x_input, &y_input);
                insert(name_input, x_input, y_input);
                break;
            case 5:
                printf("Enter the name of the city to delete: ");
                scanf("%s", name_input);
                delete_by_name(name_input);
                break;
            case 6:
                printf("Enter the coordinates (x y) and radius of the search area: ");
                scanf("%d %d %d", &x_input, &y_input, &radius);
                search_within_radius(x_input, y_input, radius);
                break;
            case 7:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 7.\n");
        }
    } while(choice != 7);

    return 0;
}
