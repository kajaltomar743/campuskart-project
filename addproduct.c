#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define product structure
typedef struct Product {
    int id;
    char name[50];
    float price;
    char image[100];
    struct Product* next;
} Product;

// Head pointer for linked list
Product* head = NULL;

// Function prototypes
void addSampleProducts();
void addProductManually();
void viewProducts();
void showMenu();

int main() {
    int choice;
    addSampleProducts();  // Add 15 sample products

    while (1) {
        showMenu();
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf(" Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // clear input buffer
            continue;
        }
        getchar(); // clear newline from input buffer

        switch (choice) {
            case 1:
                viewProducts();
                break;
            case 2:
                addProductManually();
                break;
            case 3:
                printf(" Exiting CampusKart. Thank you!\n");
                exit(0);
            default:
                printf(" Invalid choice. Try again.\n");
        }
    }

    return 0;
}

// Menu display
void showMenu() {
    printf("\n==========  CampusKart Menu ==========\n");
    printf("1. View All Products\n");
    printf("2. Add New Product\n");
    printf("3. Exit\n");
    printf("========================================\n");
}

// Add product to the linked list
void addProduct(int id, const char* name, float price, const char* imagePath) {
    Product* newProduct = (Product*)malloc(sizeof(Product));
    if (!newProduct) {
        printf(" Memory allocation failed.\n");
        return;
    }

    newProduct->id = id;
    strncpy(newProduct->name, name, sizeof(newProduct->name) - 1);
    newProduct->name[sizeof(newProduct->name) - 1] = '\0';
    newProduct->price = price;
    strncpy(newProduct->image, imagePath, sizeof(newProduct->image) - 1);
    newProduct->image[sizeof(newProduct->image) - 1] = '\0';
    newProduct->next = head;
    head = newProduct;
}

// Add 6 sample products
void addSampleProducts() {
    addProduct(101, "Laptop", 45000, "images/laptop.jpg");
    addProduct(102, "Mouse", 500, "images/mouse.jpg");
    addProduct(103, "Notebook", 60,"images/notebook.jpg");
    addProduct(104, "DSA Book", 250,"images/DSA book.jpg");
    addProduct(105, "Water Bottle", 150,"images/water bottle.jpg");
    addProduct(106, "Scientific Calculator", 900,"images/scientific calcutor");
    
}

// Add product manually by user
void addProductManually() {
    Product* newProduct = (Product*)malloc(sizeof(Product));
    if (!newProduct) {
        printf(" Memory allocation failed.\n");
        return;
    }

    printf(" Enter Product ID: ");
    scanf("%d", &newProduct->id);
    getchar();

    printf(" Enter Product Name: ");
    fgets(newProduct->name, sizeof(newProduct->name), stdin);
    newProduct->name[strcspn(newProduct->name, "\n")] = '\0'; // Remove newline

    printf(" Enter Product Price: ");
    scanf("%f", &newProduct->price);
    getchar();

    printf("  Enter Image Path (e.g., images/item.jpg): ");
    fgets(newProduct->image, sizeof(newProduct->image), stdin);
    newProduct->image[strcspn(newProduct->image, "\n")] = '\0'; // Remove newline

    newProduct->next = head;
    head = newProduct;

    printf(" Product added successfully!\n");
}

// View all products
void viewProducts() {
    if (head == NULL) {
        printf("\n No products available.\n");
        return;
    }

    Product* temp = head;
    printf(" Product List:\n");
    printf("--------------------------------------------------\n");

    while (temp != NULL) {
        printf("  ID      : %d\n", temp->id);
        printf(" Name    : %s\n", temp->name);
        printf(" Price   : %.2f\n", temp->price);
        printf("  Image   : %s\n", temp->image);
        printf("--------------------------------------------------\n");
        temp = temp->next;
    }
}
