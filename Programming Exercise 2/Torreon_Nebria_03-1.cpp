/* Program by: Quennie A. Nebria
               Ericka Gwynne S. Torreon
*/

// Standard libraries used in the program
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Define a structure for stack node
struct Node {
    char data[50];
    struct Node* next;
};

// Function to create a new node
struct Node* newNode(char* data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    if (node == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    strcpy(node->data, data);
    node->next = NULL;
    return node;
}

// Function to check if stack is empty
bool isEmpty(struct Node* root) {
    return !root;
}

// Function to push an item to stack
void push(struct Node** root, char* data, int* itemCount) {
    if (*itemCount >= 5) {
        printf("The STACK is FULL. Cannot add more kitchenware.\n");
        return;
    }
    struct Node* node = newNode(data);
    node->next = *root;
    *root = node;
    (*itemCount)++;
    printf("%s is added to the stack.\n", data);
}

// Function to pop an item from stack
char* pop(struct Node** root, int* itemCount) {
    if (isEmpty(*root)) {
        printf("The STACK is EMPTY. No more kitchenware to wash.\n");
        return NULL;
    }
    struct Node* temp = *root;
    *root = (*root)->next;
    char* popped = malloc(strlen(temp->data) + 1);
    if (popped == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    strcpy(popped, temp->data); // Copy the data
    free(temp);
    (*itemCount)--;
    return popped;
}

// Function to return the top item from stack
char* top(struct Node* root) {
    if (isEmpty(root)) {
        printf("The STACK is EMPTY. No kitchenware to wash.\n");
        return NULL;
    }
    return root->data;
}

// Function to display all items in the stack
void displayStack(struct Node* root) {
    struct Node* temp = root;
    while (temp != NULL) {
        printf("%s\n", temp->data);
        temp = temp->next;
    }
}

// Function to empty the stack
void makeNull(struct Node** root, int* itemCount) {
    struct Node* current = *root;
    struct Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *root = NULL;
    *itemCount = 0; // Reset the item count
}

int main() {
    struct Node* stack = NULL;
    int itemCount = 0;

    int choice;
    char kitchenware[50];

    do {
        printf("\nKitchenware Washing Machine\n");
        printf("[1] Add kitchenware\n");
        printf("[2] Wash kitchenware\n");
        printf("[3] Top kitchenware\n");
        printf("[4] Wash all\n");
        printf("[0] Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter kitchenware to be washed: ");
                scanf("%s", kitchenware);
                if (!isEmpty(stack)) {
                    if (strlen(kitchenware) + strlen(top(stack)) + 4 > 50) {
                        printf("The STACK is FULL. Cannot add kitchenware.\n");
                        break;
                    }
                }
                push(&stack, kitchenware, &itemCount);
                break;
            case 2:
                if (!isEmpty(stack)) {
                    printf("%s is being washed.\n", pop(&stack, &itemCount));
                } else {
                    printf("The STACK is EMPTY. No more kitchenware to wash.\n");
                }
                break;
            case 3:
                if (!isEmpty(stack)) {
                    printf("%s is next to be washed.\n", top(stack));
                } else {
                    printf("The STACK is EMPTY. No kitchenware to wash.\n");
                }
                break;
            case 4:
                if (!isEmpty(stack)) {
                    printf("Washing all kitchenware:\n");
                    while (!isEmpty(stack)) {
                        printf("%s is being washed.\n", pop(&stack, &itemCount));
                    }
                    printf("All kitchenware has been washed.\n");
                } else {
                    printf("The STACK is EMPTY. No kitchenware to wash.\n");
                }
                break;
            case 0:
                printf("Exiting... Washing machine process has been terminated.\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 0 and 4.\n");
        }
    } while (choice != 0);

    makeNull(&stack, &itemCount); // Free memory before exiting
    return 0;
}
