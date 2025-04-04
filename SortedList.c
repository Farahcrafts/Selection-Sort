#include <stdio.h>
#include <stdlib.h>


// Define the structure of a Node in the linked list
typedef struct Node{
    int data;// Data to store the integer value
    struct Node *next;// Pointer to the next node in the list
}Node;


// Function to perform selection sort on the linked list
Node* SelectionSort(Node *Head){
    Node *temp1, *temp2 ,*min;// Pointers for iteration and minimum node tracking
    int minValue; // To store the minimum value temporarily


    // If the list is empty, return immediately
    if(Head == NULL){
        return Head;
    }


     // Outer loop: traverse the list from the beginning
    for (temp1=Head;temp1->next!=NULL;temp1=temp1->next){
        min=temp1;// Set the first element as the initial minimum
        minValue=temp1->data;// Store its value


        // Inner loop: find the smallest value in the remaining unsorted portion
        for(temp2=temp1->next;temp2!=NULL;temp2=temp2->next){
            if(temp2->data < minValue){
                min=temp2;// Update the minimum node pointer
                minValue=temp2->data;// Update the minimum value
            }
        }

        // If the minimum node is different from the current node, swap their data
        if(min!=temp1){
                int temp;
                temp=temp1->data;// Swap the data between temp1 and min
                temp1->data = min->data;
                min->data= temp;
        }
        }
        return Head;// Return the sorted list
    }


// Function to display the linked list
void DisplayList(Node *Head){
    Node *current=Head;// Temporary pointer to traverse the list


    // Traverse the list and print the data
    while(current!=NULL){
            printf("%d->",current->data);// Print the current node's data
            current=current->next;// Move to the next node
    }
    printf("NULL\n");// End of the list
}


// Function to insert a node at the end of the list
Node* InsertNode(Node *Head, int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));// Allocate memory for a new node
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");// Check for memory allocation failure
        return Head;
    }

    newNode->data = value;// Set the data of the new node
    newNode->next = NULL;// Set its next pointer to NULL (it will be the last node)


    // If the list is empty, return the new node as the head of the list
    if (Head == NULL) {
        return newNode;
    }

    Node *temp = Head;// Temporary pointer to traverse the list
    // Traverse to the last node
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;// Link the last node to the new node

    return Head;// Return the updated head of the list
}


// Function to free the allocated memory of the linked list
void FreeList(Node *Head) {
    Node *temp;// Temporary pointer for memory deallocation

    // Traverse the list and free each node
    while (Head) {
        temp = Head;// Store the current node
        Head = Head->next;// Store the current node
        free(temp); // Free the memory of the current node
    }
}

int main()
{
    // Main function to drive the program
    Node *Head=NULL;// Initialize the head pointer to NULL (empty list)


    // Insert nodes into the linked list
    Head = InsertNode(Head, 18);
    Head = InsertNode(Head, 5);
    Head = InsertNode(Head, 42);
    Head = InsertNode(Head, 9);

    // Display the original list
    printf("Original List:\n");
    DisplayList(Head);
    // Sort the list using selection sort
    Head=SelectionSort(Head);
    // Display the sorted list
    printf("Sorted List:\n");
    DisplayList(Head);
    // Free the memory allocated for the list
    FreeList(Head);

    return 0;// Return 0 to indicate successful execution
}
