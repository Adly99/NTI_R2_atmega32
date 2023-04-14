
#include"stack.h"


// Function to create an empty stack
// Takes a pointer to the stack
void createEmptyStack(ST_stack_t *stack) {
    stack->top = -1;
}


/*******************************************************************************/
// Function to push an element onto the stack
// Takes a pointer to the stack and the data to be pushed
// Returns 1 if successful, 0 if the stack is full and push fails
int push(ST_stack_t *stack, int data) {
    // Check if the stack is full
    if (isFull(stack)) {
        return 0; // Push failed
    }

    // Increment the top index and add the new element to the stack
    stack->top++;
    stack->elements[stack->top] = data;

    return 1; // Push successful
}
/******************************************************************************/
// Function to pop an element from the stack
// Takes a pointer to the stack and a pointer to a variable to hold the popped value
// Returns 1 if successful, 0 if the stack is empty and pop fails
int pop(ST_stack_t *stack, int *data) {
    // Check if the stack is empty
    if (isEmpty(stack)) {
        return 0; // Pop failed
    }

    // Get the value at the top of the stack and decrement the top index
    *data = stack->elements[stack->top];
    stack->top--;

    return 1; // Pop successful
}
/*******************************************************************************/
// Function to check if the stack is full
// Takes a pointer to the stack
// Returns 1 if the stack is full, 0 otherwise
int isFull(struct stack *stack) {
    return stack->top == stack_size - 1;
}

// Function to check if the stack is empty
// Takes a pointer to the stack
// Returns 1 if the stack is empty, 0 otherwise
int isEmpty(struct stack *stack) {
    return stack->top == -1;
}
/*******************************************************************************/
// Function to print the contents of the stack
// Takes a pointer to the stack
// Returns the number of elements printed
int printStack(ST_stack_t *stack) {
    int i;

    printf("Stack contents:");

    // Iterate over the stack elements and print each one
    for (i = stack->top; i >= 0; i--) {
        printf(" %d", stack->elements[i]);
    }

    printf("\n");

    return stack->top + 1;
}
/*******************************************************************************/
// Function to get the top element of the stack without popping it
// Takes a pointer to the stack and a pointer to a variable to hold the top element
// Returns 1 if successful, 0 if the stack is empty and the operation fails
int getStack(ST_stack_t *stack, int *data) {
    // Check if the stack is empty
    if (isEmpty(stack)) {
        return 0; // Get operation failed
    }

    // Get the value at the top of the stack and store it in the data variable
    *data = stack->elements[stack->top];

    return 1; // Get operation successful
}

