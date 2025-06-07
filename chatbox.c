#include <stdio.h>
#include <string.h>

void buyerChat() {
    char message[100];
    printf("\n[Buyer]: Hi, I'm interested in the product. Is it still available?\n");
    printf("[You]:yes! tell me the product you want? ");
    printf("\n[buyer]:myself aditya i wanna buy laptop.can you please tell me the price?\n");
    printf("[you]:the price is 45000 ");
    fgets(message, sizeof(message), stdin);
    printf("[Buyer]: Got it! Thanks for the info.\n");
}

void sellerChat() {
    char message[100];
    printf("\n[Seller]: Hello! I saw your interest in the product. Do you have any questions?\n");
    printf("[You]: i want to know about product qualities.");
    fgets(message, sizeof(message), stdin);
    printf("[Seller]: Great! Let me know if you need anything else.if you wanna know the quality must see the reviews first.\n");
}

int main() {
    int choice;
    printf("===== CampusKart Chatbox =====\n");
    printf("1. Chat as Buyer\n");
    printf("2. Chat as Seller\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar(); // clear newline

    switch (choice) {
        case 1:
            buyerChat();
            break;
        case 2:
            sellerChat();
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}
