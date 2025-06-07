#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "C:\Users\Kajal\OneDrive\Desktop\campuskart\DSsetup.c"

// User node structure
typedef struct User {
    char username[50];
    char password[50];
    struct User* next;
} User;

User* UserHead = NULL; // UserHead of linked list

// Function to create a new user node
User* createUser(char* username, char* password) {
    User* newUser = (User*)malloc(sizeof(User));
    strcpy(newUser->username, username);
    strcpy(newUser->password, password);
    newUser->next = NULL;
    return newUser;
}

// Function to add user to linked list (Registration simulation)
void addUser(char* username, char* password) {
    User* newUser = createUser(username, password);
    if (UserHead == NULL) {
        UserHead = newUser;
    } else {
        User* temp = UserHead;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newUser;
    }
}

// Function to validate login credentials
int login(char* username, char* password) {
    User* temp = UserHead;
    while (temp != NULL) {
        if (strcmp(temp->username, username) == 0 &&
            strcmp(temp->password, password) == 0) {
            return 1; // Login success
        }
        temp = temp->next;
    }
    return 0; // Login failed
}

// Demo: Add some registered users
void loadUsers() {
    addUser("user1", "pass123");
    addUser("kajal", "campus2025");
    addUser("student99", "mypassword");
}

int main() {
    char username[50], password[50];
    int attempts = 3;
    loadUsers(); // Load predefined users

    printf("=== CampusKart Login ===\n");
    while (attempts > 0) {
        printf("Enter username: ");
        scanf("%s", username);
        printf("Enter password: ");
        scanf("%s", password);

        if (login(username, password)) {
            printf("Login successful! Welcome, %s\n", username);
            InitProduct();
            break;
        } else {
            attempts--;
            printf("Invalid credentials. Attempts left: %d\n", attempts);
        }
    }

    if (attempts == 0) {
        printf("Too many failed attempts. Exiting...\n");
    }

    return 0;
}