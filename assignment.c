#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Product {
    int id;
    char name[50];
    int quantity;
    float price;
    struct Product *next;
};
void addProduct(struct Product **head);
void displayProducts(struct Product *head);
void searchProduct(struct Product *head);
void deleteProduct(struct Product **head);
int main() {
    struct Product *head = NULL;
    int choice;

    do {
        printf("\n--- Inventory Management System ---\n");
        printf("1. Add Product\n");
        printf("2. Display Products\n");
        printf("3. Search Product\n");
        printf("4. Delete Product\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct(&head);
                break;
            case 2:
                displayProducts(head);
                break;
            case 3:
                searchProduct(head);
                break;
            case 4:
                deleteProduct(&head);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void addProduct(struct Product **head) {
    struct Product *newProduct = (struct Product *)malloc(sizeof(struct Product));
    if (newProduct == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter product ID: ");
    scanf("%d", &newProduct->id);
    printf("Enter product name: ");
    scanf(" %[^\n]", newProduct->name); 
    printf("Enter product quantity: ");
    scanf("%d", &newProduct->quantity);
    printf("Enter product price: ");
    scanf("%f", &newProduct->price);

    newProduct->next = *head;
    *head = newProduct;

    printf("Product added successfully!\n");
}

void displayProducts(struct Product *head) {
    if (head == NULL) {
        printf("No products in the inventory.\n");
        return;
    }

    printf("\n--- Product List ---\n");
    while (head != NULL) {
        printf("ID: %d, Name: %s, Quantity: %d, Price: %.2f\n", 
               head->id, head->name, head->quantity, head->price);
        head = head->next;
    }
}

void searchProduct(struct Product *head) {
    int id;
    printf("Enter product ID to search: ");
    scanf("%d", &id);

    while (head != NULL) {
        if (head->id == id) {
            printf("Product Found: ID: %d, Name: %s, Quantity: %d, Price: %.2f\n", 
                   head->id, head->name, head->quantity, head->price);
            return;
        }
        head = head->next;
    }

    printf("Product not found.\n");
}

void deleteProduct(struct Product **head) {
    int id;
    printf("Enter product ID to delete: ");
    scanf("%d", &id);

    struct Product *current = *head, *prev = NULL;

    while (current != NULL && current->id != id) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Product not found.\n");
        return;
    }

    if (prev == NULL) {
        *head = current->next; 
    } else {
        prev->next = current->next; 
    }

    free(current);
    printf("Product deleted successfully!\n");
}
