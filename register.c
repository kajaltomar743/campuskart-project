#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// User node structure
typedef struct User {
    char username[50];
    char password[50];
    struct User* next;
} User;

User* head = NULL;  // Head of linked list

// Function to create a new user node
User* createUser(char* username, char* password) {
    User* newUser = (User*)malloc(sizeof(User));
    strcpy(newUser->username, username);
    strcpy(newUser->password, password);
    newUser->next = NULL;
    return newUser;
}

// Function to check if username already exists
int usernameExists(char* username) {
    User* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->username, username) == 0) {
            return 1;  // Exists
        }
        temp = temp->next;
    }
    return 0;  // Does not exist
}

// Function to add user to linked list (register)
void addUser(char* username, char* password) {
    User* newUser = createUser(username, password);
    if (head == NULL) {
        head = newUser;
    } else {
        User* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newUser;
    }
    printf("Registration successful! You can now login.\n");
}

void displayUsers() {
    User* temp = head;
    printf("\nRegistered Users:\n");
    while (temp != NULL) {
        printf(" - %s\n", temp->username);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    char username[50], password[50], password2[50];
    char choice;

    printf("=== CampusKart Registration ===\n");
    
    do {
        printf("Enter username: ");
        scanf("%s", username);

        if (usernameExists(username)) {
            printf("Username already taken. Try another.\n");
            continue;
        }

        printf("Enter password: ");
        scanf("%s", password);

        printf("Confirm password: ");
        scanf("%s", password2);

        if (strcmp(password, password2) != 0) {
            printf("Passwords do not match. Try again.\n");
            continue;
        }

        addUser(username, password);

        printf("Register another user? (y/n): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    displayUsers();

    return 0;
}