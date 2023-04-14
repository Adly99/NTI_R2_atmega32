typedef struct stack { int elements [stack_size]; int top }ST_stack_t;
void createEmptyStack(ST_stack_t *stack);
int push(ST_stack_t *stack, int data); 
int pop(ST_stack_t *stack, int data);  
int isFull(struct stack *stack);
int isEmpty(struct stack *stack); 
int printStack(ST_stack_t *s);
int getStack(ST_stack_t *stack);
