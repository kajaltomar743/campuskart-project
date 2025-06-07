#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define product structure
typedef struct Product {
    int id;
    char name[50];
    float price;
    struct Product* next;
} Product;

Product* head = NULL;

// Function to add a product
void addProduct(int id, char name[], float price) {
    Product* newProduct = (Product*)malloc(sizeof(Product));
    newProduct->id = id;
    strcpy(newProduct->name, name);
    newProduct->price = price;
    newProduct->next = NULL;

    if (head == NULL) {
        head = newProduct;
    } else {
        Product* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newProduct;
    }
}

// Function to view all products
void viewProducts() {
    Product* temp = head;
    if (temp == NULL) {
        printf("No products available.\n");
        return;
    }

    printf("\n--- Product List ---\n");
    while (temp != NULL) {
        printf("ID: %d | Name: %s | Price: %.2f\n", temp->id, temp->name, temp->price);
        temp = temp->next;
    }
    printf("---------------------\n");
}

// Function to search a product by name
void searchProduct(char name[]) {
    Product* temp = head;
    int found = 0;

    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            printf("Found - ID: %d | Name: %s | Price: %.2f\n", temp->id, temp->name, temp->price);
            found = 1;
            break;
        }
        temp = temp->next;
    }

    if (!found) {
        printf("Product not found.\n");
    }
}

// Function to delete a product by ID
void deleteProduct(int id) {
    Product* temp = head;
    Product* prev = NULL;

    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Product with ID %d not found.\n", id);
        return;
    }

    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
    printf("Product with ID %d deleted successfully.\n", id);
}

// Main menu
int InitProduct() {
    int choice, id;
    char name[50];
    float price;

    while (1) {
        printf("\n--- CampusKart Menu ---\n");
        printf("1. Add Product\n");
        printf("2. View Products\n");
        printf("3. Search Product by Name\n");
        printf("4. Delete Product by ID\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Clear input buffer

        switch (choice) {
            case 1:
                printf("Enter Product ID: ");
                scanf("%d", &id);
                getchar();
                printf("Enter Product Name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0'; // Remove newline
                printf("Enter Product Price: ₹");
                scanf("%f", &price);
                addProduct(id, name, price);
                break;
            case 2:
                viewProducts();
                break;
            case 3:
                printf("Enter name to search: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0'; // Remove newline
                searchProduct(name);
                break;
            case 4:
                printf("Enter Product ID to delete: ");
                scanf("%d", &id);
                deleteProduct(id);
                break;
            case 5:
                printf("Exiting CampusKart...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}