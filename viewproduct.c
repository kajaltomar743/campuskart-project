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

// Function to add a product
void addProduct(int id, const char* name, float price) {
    Product* newProduct = (Product*)malloc(sizeof(Product));
    newProduct->id = id;
    strcpy(newProduct->name, name);
    newProduct->price = price;
    newProduct->next = head;
    head = newProduct;
}

// Function to view all products
void viewProducts() {
    Product* temp = head;
    if (!temp) {
        printf("No products available.\n");
        return;
    }

    printf("\n--- Product List ---\n");
    while (temp != NULL) {
        printf("ID: %d | Name: %s | Price: %.2f\n", temp->id, temp->name, temp->price);
        temp = temp->next;
    }
}

// Main function for demo
int main() {
    // Adding 6 sample products
    addProduct(101, "Laptop", 45000);
    addProduct(102, "Mouse", 500);
    addProduct(103, "Notebook", 60);
    addProduct(104, "DSA Book", 250);
    addProduct(105, "Water Bottle", 150);
    addProduct(106, "Scientific Calculator", 900);
    

    // View all products
    viewProducts();

    return 0;
}
