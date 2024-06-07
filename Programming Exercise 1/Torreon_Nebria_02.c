/*  Program by: Quennie A. Nebria
                Ericka Gwynne S. Torreon
    Program Description: This program allows the user to add, delete, display, and clear the list based on their choices. 
    The input may include the following variable types: int, char, string.
*/

// Standard libraries used in the program
#include <stdio.h>
#include <stdlib.h>

// Defines a structure 'Node'
struct Node {
    char data[100]; // Array to store the item
    struct Node* next; // Pointer to the next node 
};

// Function prototypes
void addItem(struct Node** headPtr);
void deleteItem(struct Node** headPtr);
void displayList(struct Node* head);
void deleteList(struct Node** headPtr);

int main() {
    struct Node* head = NULL; // Initializes head pointer to 'NULL'
    int choice;

    // Menu-driven loop to interact with the linked list
    do {
        printf("\nList MENU\n");
        printf("[1] Add Item\n");
        printf("[2] Delete Item\n");
        printf("[3] Display List\n");
        printf("[4] Delete List\n");
        printf("[0] Exit Program\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        getchar(); // Clears input buffer

        switch (choice) {
            case 1:
                addItem(&head); // Calls function to add item
                break;
            case 2:
                deleteItem(&head); // Calls function to delete item
                break;
            case 3:
                displayList(head); // Calls function to display list
                break;
            case 4:
                deleteList(&head); // Calls function to delete entire list
                break;
            case 0:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}

// Function to add an item to the list
void addItem(struct Node** headPtr) {
    char item[100];
    int choice, i;
    printf("\nPlease enter the item to be added: ");
    fgets(item, sizeof(item), stdin); // Reads item from user input

	// Removes newline character from the input
    if (strlen(item) > 0 && item[strlen(item) - 1] == '\n') {
        item[strlen(item) - 1] = '\0';
    }
    
    // Prompts user to choose where to add the item
    printf("Where to add the item?\n");
    printf("[1] Start of the list\n");
    printf("[2] End of the list\n");
    printf("[3] Specific position\n");
    printf("[0] Cancel\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    // Allocates memory for new node (temporary holder for new item)
    struct Node* holder = (struct Node*)malloc(sizeof(struct Node)); 
    strcpy(holder->data, item); // Copy item to node's data
    holder->next = NULL;

    // Adds new node (temporary item holder) to the list based on user choice
    if (choice == 1) {
        holder->next = *headPtr;
        *headPtr = holder;
    } else if (choice == 2) {
        if (*headPtr == NULL) {
            *headPtr = holder;
        } else {
            struct Node* temp = *headPtr;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = holder;
        }
    } else if (choice == 3) {
	    int pos;
	    printf("Enter the position to add the item: ");
	    scanf("%d", &pos);
	    if (pos <= 0) {
	        printf("Invalid position. Item will be added to the end of the list.\n");
	        choice = 2;
	    } else if (pos == 1) {
	        holder->next = *headPtr;
	        *headPtr = holder;
	    } else {
	        struct Node* temp = *headPtr;
	        for (i = 1; i < pos - 1 && temp != NULL; i++) {
	            temp = temp->next;
	        }
	        if (temp == NULL) {
	            printf("Position exceeds the size of the list. Item will be added to the end.\n");
	            struct Node* lastNode = *headPtr;
			    // Traverse the list to find the last node
			    while (lastNode->next != NULL) {
			        lastNode = lastNode->next;
			    }
			    // Add the item after the last node
			    lastNode->next = holder;
			} else {
			    holder->next = temp->next;
			    temp->next = holder;
			}
		}
	}

    if (choice == 0)
        printf("Add operation cancelled.\n");
    else
        printf("Item %s added successfully.\n", item);
}

// Function to delete an item from the list
void deleteItem(struct Node** headPtr) {
    if (*headPtr == NULL) {
        printf("The list is empty.\n"); 
        return;
    }

    char item[100];
    printf("Enter the item to be deleted: ");
    fgets(item, sizeof(item), stdin);
    
    // Remove newline character, if present
    if (strlen(item) > 0 && item[strlen(item) - 1] == '\n') {
        item[strlen(item) - 1] = '\0';
    }

    struct Node* temp = *headPtr;
    struct Node* prev = NULL;
    int position = 1;

    // Searches for item in the list
    while (temp != NULL && strcmp(temp->data, item) != 0) {
        prev = temp;
        temp = temp->next;
        position++;
    }

    // If item is found, delete. Otherwise, print message
    if (temp == NULL) {
        printf("The list contains no such element.\n");
    } else {
    	// If first node is to be deleted
        if (prev == NULL) {
            *headPtr = temp->next;
        } else {
            prev->next = temp->next;
        }
        free(temp);
        printf("The element %s, which is at position %d, has been deleted.\n", item, position);
    }
}

// Function to display the list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = head;
    int position = 1;
    printf("List:\n");
    while (temp != NULL) {
        printf("[%d] %s\n", position++, temp->data); // Prints each node's data
        temp = temp->next;
    }
}

// Function to delete the entire list
void deleteList(struct Node** headPtr) {
    struct Node* current = *headPtr;
    struct Node* next;

    // Frees memory for each node
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    *headPtr = NULL; // Sets head pointer to NULL
    printf("The list has been emptied!\n");
}



