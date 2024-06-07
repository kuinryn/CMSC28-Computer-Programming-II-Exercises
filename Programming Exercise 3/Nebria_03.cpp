//Quennie A. Nebria I_BSCS
//Programming Exercise 03 QUEUE IMPLEMENTATION 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_SIZE 50

// Structure for a cell in the queue
typedef struct CustomerNode {
    char customerName[NAME_SIZE];
    float totalAmount;
    struct CustomerNode* next;
} CustomerNode;

// Structure for the queue
typedef struct Queue {
    CustomerNode* front;
    CustomerNode* rear;
} Queue;

// Function prototypes
Queue* INIT();
int EMPTY(Queue* Q);
void ENQUEUE(char* name, float amount, Queue* Q);
void DEQUEUE(Queue* Q);
char* FRONT(Queue* Q);

// Function definitions:

// Creates and returns an empty queue
Queue* INIT() {
    Queue* Q = (Queue*)malloc(sizeof(Queue));
    Q->front = NULL;
    Q->rear = NULL;
    return Q;
}

// Returns true if queue Q is empty, otherwise, returns false
int EMPTY(Queue* Q) {
    return (Q->front == NULL);
}

// Inserts customer's name and total amount to be paid by the customer in queue Q
void ENQUEUE(char* name, float amount, Queue* Q) {
    CustomerNode* newNode = (CustomerNode*)malloc(sizeof(CustomerNode));
    strcpy(newNode->customerName, name);
    newNode->totalAmount = amount;
    newNode->next = NULL;
    if (EMPTY(Q)) {
        Q->front = newNode;
        Q->rear = newNode;
    } else {
        Q->rear->next = newNode;
        Q->rear = newNode;
    }
}

// Removes and returns the front item of queue Q
void DEQUEUE(Queue* Q) {
    if (!EMPTY(Q)) {
        CustomerNode* temp = Q->front;
        Q->front = Q->front->next;
        free(temp);
        if (Q->front == NULL) {
            Q->rear = NULL;
        }
    }
}

// Returns a copy of the front item of queue Q
char* FRONT(Queue* Q) {
    if (!EMPTY(Q)) {
        return Q->front->customerName;
    } else {
        return "";
    }
}

// Main program
int main() {
	// Initialize the checkout queue
    Queue* listQueue = INIT();
    int choice;
    char name[NAME_SIZE];
    float amount;
    
    // Main menu loop
    do {
    	// Display the main menu options
        printf("Kaluy-an Counter 0:\n");
        printf("[1] Fall in line\n");
        printf("[2] Serve customer\n");
        printf("[3] Next customer\n");
        printf("[4] Closing time\n");
        printf("[0] Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice); // Scan and read the user's choice

		// Perform action based on user's choice
        switch (choice) {
        	
        	// Prompt user to enter customer's name and total amount payable
            case 1: {
                printf("Enter customer's name: ");
                scanf("%s", name);
                printf("Enter total amount payable: ");
                scanf("%f", &amount);
                ENQUEUE(name, amount, listQueue); // Add customer to the list queue
                break;
            }
            
            // Serve the first customer in the queue if queue is not empty
            case 2: {
                if (!EMPTY(listQueue)) {
                    strcpy(name, FRONT(listQueue)); // Retrieve customer's name and total amount payable (together with the next line)
                    amount = listQueue->front->totalAmount;
                    DEQUEUE(listQueue); // Remove the served customer from the queue
                    printf("Now serving %s with total amount payable of %.4f.\n", name, amount);  // Display message about serving the customer
                } else {
                    printf("The QUEUE is EMPTY. No orders to serve.\n"); // Display message if queue is empty
                }
                break;
            }
            
            // Display information about the next customer to be served if queue is not empty
            case 3: {
                if (!EMPTY(listQueue)) {
                    strcpy(name, FRONT(listQueue)); // Retrieve customer's name and total amount payable (together with the next line)
                    amount = listQueue->front->totalAmount;
                    printf("Next order: For %s with total amount payable of %.4f.\n", name, amount); // Display information about the next customer
                } else {
                    printf("The QUEUE is EMPTY. No order to serve.\n"); // Display message if queue is empty
                }
                break;
            }
            
            // Serve all remaining customers in the queue
            case 4: {
                while (!EMPTY(listQueue)) {
                    strcpy(name, FRONT(listQueue)); // Retrieve customer's name and total amount payable (together with the next line) 
                    amount = listQueue->front->totalAmount;
                    DEQUEUE(listQueue); // Remove the served customer from the queue
                    printf("Now serving %s with total amount payable of %.4f.\n", name, amount); // Display message about serving the customer
                }
                printf("All customers have been served.\n"); // Display message after serving all customers
                break;
            }
            
            // Terminate the system
            case 0:
                printf("Terminating the checkout system.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n"); // Display message for invalid choice
        }
    } while (choice != 0);

    // Free memory allocated for the queue
    while (!EMPTY(listQueue)) {
        DEQUEUE(listQueue);
    }
    free(listQueue);

    return 0;
}
