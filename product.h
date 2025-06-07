// product.h
#ifndef PRODUCT_H
#define PRODUCT_H

typedef struct Product {
    int id;
    char name[50];
    float price;
    struct Product* next;
} Product;

extern Product* head;

void addProduct(int id, const char* name, float price);
void viewProducts();
void deleteProduct(int id);
void searchProduct(const char* name);
void sortProducts();

#endif
