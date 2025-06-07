#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Product structure
typedef struct Product {
    int id;
    char name[50];
    float price;
    struct Product* next;
} Product;

Product* head = NULL;

// Add 6 predefined products
void addSampleProducts() {
    Product* p1 = (Product*)malloc(sizeof(Product));
    p1->id = 101; strcpy(p1->name, "Laptop"); p1->price = 45000; p1->next = NULL;
    head = p1;

    Product* p2 = (Product*)malloc(sizeof(Product));
    p2->id = 102; strcpy(p2->name, "Mouse"); p2->price = 500; p2->next = NULL;
    p1->next = p2;

    Product* p3 = (Product*)malloc(sizeof(Product));
    p3->id = 103; strcpy(p3->name, "Notebook"); p3->price = 60; p3->next = NULL;
    p2->next = p3;

    Product* p4 = (Product*)malloc(sizeof(Product));
    p4->id = 104; strcpy(p4->name, "DSA Book"); p4->price = 250; p4->next = NULL;
    p3->next = p4;

    Product* p5 = (Product*)malloc(sizeof(Product));
    p5->id = 105; strcpy(p5->name, "Water Bottle"); p5->price = 150; p5->next = NULL;
    p4->next = p5;

    Product* p6 = (Product*)malloc(sizeof(Product));
    p6->id = 106; strcpy(p6->name, "Scientific Calculator"); p6->price = 900; p6->next = NULL;
    p5->next = p6;
}

// View all products
void viewProducts() {
    Product* temp = head;

    if (temp == NULL) {
        printf("\nNo products available.\n");
        return;
    }

    printf("\nAvailable Products:\n");
    while (temp != NULL) {
        printf("ID: %d | Name: %s | Price: %.2f\n", temp->id, temp->name, temp->price);
        temp = temp->next;
    }
}

// Delete product by name
void deleteProductByName(char deleteName[]) {
    Product* temp = head;
    Product* prev = NULL;

    while (temp != NULL) {
        if (strcasecmp(temp->name, deleteName) == 0) {
            if (prev == NULL) {
                // Deleting head
                head = temp->next;
            } else {
                prev->next = temp->next;
            }
            printf("\nProduct '%s' deleted successfully.\n", temp->name);
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    printf("\nProduct '%s' not found in the list.\n", deleteName);
}

// Main
int main() {
    char name[50];
    int choice;

    addSampleProducts();

    while (1) {
        printf("\n--- CampusKart Menu ---\n");
        printf("1. View Products\n");
        printf("2. Delete Product by Name\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // to consume newline character

        switch (choice) {
            case 1:
                viewProducts();
                break;
            case 2:
                printf("Enter product name to delete: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0'; // remove trailing newline
                deleteProductByName(name);
                break;
            case 3:
                printf("Exiting CampusKart.\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}