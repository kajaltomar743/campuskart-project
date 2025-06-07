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

// Function to add your 6 products
void addSampleProducts() {
    Product* p1 = (Product*)malloc(sizeof(Product));
    if (!p1) { perror("malloc failed"); exit(1); }
    p1->id = 101;
    strcpy(p1->name, "Laptop");
    p1->price = 45000;
    p1->next = NULL;
    head = p1;

    Product* p2 = (Product*)malloc(sizeof(Product));
    if (!p2) { perror("malloc failed"); exit(1); }
    p2->id = 102;
    strcpy(p2->name, "Mouse");
    p2->price = 500;
    p2->next = NULL;
    p1->next = p2;

    Product* p3 = (Product*)malloc(sizeof(Product));
    if (!p3) { perror("malloc failed"); exit(1); }
    p3->id = 103;
    strcpy(p3->name, "Notebook");
    p3->price = 60;
    p3->next = NULL;
    p2->next = p3;

    Product* p4 = (Product*)malloc(sizeof(Product));
    if (!p4) { perror("malloc failed"); exit(1); }
    p4->id = 104;
    strcpy(p4->name, "DSA Book");
    p4->price = 250;
    p4->next = NULL;
    p3->next = p4;

    Product* p5 = (Product*)malloc(sizeof(Product));
    if (!p5) { perror("malloc failed"); exit(1); }
    p5->id = 105;
    strcpy(p5->name, "Water Bottle");
    p5->price = 150;
    p5->next = NULL;
    p4->next = p5;

    Product* p6 = (Product*)malloc(sizeof(Product));
    if (!p6) { perror("malloc failed"); exit(1); }
    p6->id = 106;
    strcpy(p6->name, "Scientific Calculator");
    p6->price = 900;
    p6->next = NULL;
    p5->next = p6;
}

// Search product by name (case insensitive)
void searchProductByName(char searchName[]) {
    if (head == NULL) {
        printf("\nNo products available.\n");
        return;
    }

    Product* temp = head;
    int found = 0;

    while (temp != NULL) {
        // strcasecmp is POSIX, Windows may require _stricmp
        #ifdef _WIN32
            if (_stricmp(temp->name, searchName) == 0) {
        #else
            if (strcasecmp(temp->name, searchName) == 0) {
        #endif
            printf("\nProduct Found:\n");
            printf("ID: %d\nName: %s\nPrice: %.2f\n", temp->id, temp->name, temp->price);
            found = 1;
            break;
        }
        temp = temp->next;
    }

    if (!found) {
        printf("\nProduct '%s' not found in the list.\n", searchName);
    }
}

// Free all allocated products
void freeProducts() {
    Product* temp = head;
    while (temp != NULL) {
        Product* next = temp->next;
        free(temp);
        temp = next;
    }
}

int main() {
    char name[50];
    char choice;

    addSampleProducts();

    do {
        printf("\nEnter product name to search: ");
        // Using fgets instead of scanf for safer input
        if (fgets(name, sizeof(name), stdin) != NULL) {
            // Remove trailing newline if present
            size_t len = strlen(name);
            if (len > 0 && name[len - 1] == '\n') {
                name[len - 1] = '\0';
            }
        }

        searchProductByName(name);

        printf("\nDo you want to search another product? (y/n): ");
        choice = getchar();
        while (getchar() != '\n'); // Clear input buffer
    } while (choice == 'y' || choice == 'Y');

    freeProducts();

    return 0;
}
