#include <stdio.h>
#include <stdlib.h>

typedef struct s_stack {
    int *data;
    int top;
    int size;
} t_stack;

t_stack *create_stack_a(int size) {
    t_stack *stack_a = malloc(sizeof(t_stack));
    stack_a->data = malloc(sizeof(int) * size);
    stack_a->top = -1;
    stack_a->size = size;
    return stack_a;
}
t_stack *create_stack_b(int size) {
    t_stack *stack_b = malloc(sizeof(t_stack));
    stack_b->data = malloc(sizeof(int) * size);
    stack_b->top = -1;
    stack_b->size = size;
    return stack_b;
}

void pa(t_stack *stack_a, t_stack *stack_b)
{
    // if (stack_a->top + 1 == stack_a->size)
    //     return;
    stack_a->data[++stack_a->top] = stack_b->data[--stack_b->top + 1];
}
void pb(t_stack *stack_b, int value)
{
    stack_b->data[++stack_b->top] = value;
}
void sb(t_stack *stack_b) {
    // Check if there are at least two elements to swap
    if (stack_b->top < 1) {
        return; // Do nothing if there's one or no element
    }

    // Swap the first two elements
    int temp = stack_b->data[stack_b->top];
    stack_b->data[stack_b->top] = stack_b->data[stack_b->top - 1];
    stack_b->data[stack_b->top - 1] = temp;
}

void sa(t_stack *stack_a)
{
    if(stack_a->top < 1)
        return;

    int tem = stack_a->data[stack_a->top-1];
    stack_a->data[stack_a->top-1] = stack_a->data[stack_a->top];
    stack_a->data[stack_a->top] = tem;
}

void ss(t_stack *stack_a, t_stack *stack_b) {
    sa(stack_a); // Swap the top two elements of stack_a
    sb(stack_b); // Swap the top two elements of stack_b
}

void rb(t_stack *stack_b) {
    // Check if the stack has at least two elements
    if (stack_b->top < 1) {
        return; // Do nothing if there's one or no element
    }

    // Save the first element
    int first = stack_b->data[0];

    // Shift all elements up by 1
    int i = 0;
    while (i < stack_b->top) {
        stack_b->data[i] = stack_b->data[i + 1];
        i++;
    }

    // Put the first element at the end
    stack_b->data[stack_b->top] = first;
}
void ra(t_stack *stack_a)
{
    if(stack_a->top < 1)
        return;
    int first = stack_a->data[0];
    int i = 0;
    while(i < stack_a->top)
    {
        stack_a->data[i] = stack_a->data[i+1];
        i++;
    }
    stack_a->data[stack_a->top] = first;
}

// void push(t_stack *stack, int value) {
//     if (stack->top + 1 == stack->size) {
//         printf("Error: Stack overflow\n");
//         return;
//     }
//     stack->data[++stack->top] = value;
// }

int pop(t_stack *stack) {
    if (stack->top == -1) {
        printf("Error: Stack underflow\n");
        return -1;
    }
    return stack->data[stack->top--];
}

int peek(t_stack *stack) {
    if (stack->top == -1) {
        printf("Error: Stack is empty\n");
        return -1;
    }
    return stack->data[stack->top];
}

int is_empty(t_stack *stack) {
    return (stack->top == -1);
}
int main()
{
   t_stack *stack_b = create_stack_b(6);
   t_stack *stack_a = create_stack_a(6);
    pb(stack_b, 45);
    pb(stack_b, 65);
    pb(stack_b, 76);
    // for(int i = 0; i<=stack_b->top; i++)
    //     printf("%d ", stack_b->data[i]);
    // sb(stack_b);
    // for(int i = 0; i<=stack_b->top; i++)
    //     printf("%d ", stack_b->data[i]);
    // t_stack *stack_a = create_stack_a(6);
    pa(stack_a, stack_b);
    pa(stack_a, stack_b);
    pa(stack_a, stack_b);
    for(int i = 0; i<=stack_a->top; i++)
        printf("%d ", stack_a->data[i]);
    // sa(stack_a);
    ra(stack_a);
    for(int i = 0; i<=stack_a->top; i++)
        printf("%d ", stack_a->data[i]);
    // pb(stack_b, 15);
    // pb(stack_b, 10);
    // pb(stack_b, 5);
    // for(int i = 0; i<=stack_b->top; i++)
    //     printf("%d ", stack_b->data[i]);
    // ss(stack_a, stack_b);
    // for(int i = 0; i<=stack_a->top; i++)
    //     printf("%d ", stack_a->data[i]);
    // for(int i = 0; i<=stack_b->top; i++)
    //     printf("%d ", stack_b->data[i]);
    // rb(stack_b);
    // for(int i = 0; i<=stack_b->top; i++)
    //     printf("%d ", stack_b->data[i]);
}

// int main() {
//     t_stack *stack_a = create_stack_a(5);
//     t_stack *stack_b = create_stack_b(7);

//     push(stack_a, 10);
//     push(stack_a, 20);
//     push(stack_a, 30);

//     printf("Top of stack: %d\n", peek(stack_a));  // Output: 30
//     printf("Pop: %d\n", pop(stack_a));           // Output: 30
//     printf("Top of stack: %d\n", peek(stack_a)); // Output: 20
    
//     push(stack_b, 14);
//     push(stack_b, 22);
//     push(stack_b, 34);
//     for (int i = 0; i <= stack_b->top; i++)
//         printf("%d ", stack_b->data[i]);
//     free(stack_b->data);
//     free(stack_b);
//     pa(stack_a, 34);
//     for (int i = 0; i <= stack_a->top; i++)
//         printf("%d ", stack_a->data[i]);
//     free(stack_a->data);
//     free(stack_a);
//     return 0;
// }
