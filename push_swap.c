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

void rra(t_stack *stack_a)
{
    int i = stack_a->top;
    if(stack_a->top <1)
        return;
    int last = stack_a->data[stack_a->top];

    while(i > 0)
    {
        stack_a->data[i] = stack_a->data[i-1];
        i--;
    }
    stack_a->data[0] = last;
}

void rrb(t_stack *stack_b)
{
    int i = stack_b->top;
    if(stack_b->top < 1)
        return;
    int last = stack_b->data[stack_b->top];
    while(i > 0)
    {
        stack_b->data[i] = stack_b->data[i-1];
        i--;
    }
    stack_b->data[0] = last;
}

void rrr(t_stack *stack_a, t_stack *stack_b)
{
    rra(stack_a);
    rrb(stack_b);
}

void rr(t_stack *stack_a, t_stack *stack_b)
{
    ra(stack_a);
    rb(stack_b);
}

// void push(t_stack *stack, int value) {
//     if (stack->top + 1 ==a stack->size) {
//         printf("Error: Stack overflow\n");
//         return;
//     }
//     stack->data[++stack->top] = value;
// }

void free_stack(t_stack *stack) {
    if (stack) {
        free(stack->data); // Free the array inside the stack
        free(stack);       // Free the stack structure itself
    }
}

int main() {
    t_stack *stack_b = create_stack_b(6);
    t_stack *stack_a = create_stack_a(6);
    
    pb(stack_b, 45);
    pb(stack_b, 65);
    pb(stack_b, 76);
    pb(stack_b, 15);
    pb(stack_b, 10);
    pb(stack_b, 5);


    pa(stack_a, stack_b);
    pa(stack_a, stack_b);
    pa(stack_a, stack_b);
    // pa(stack_a, stack_b);
    // pa(stack_a, stack_b);
    // pa(stack_a, stack_b);
    printf("stack b:");
    for (int i = 0; i <= stack_b->top; i++)
        printf("%d ", stack_b->data[i]);
    printf("stack a:");
    for (int i = 0; i <= stack_a->top; i++)
        printf("%d ", stack_a->data[i]);

    rrr(stack_a, stack_b);
    // rb(stack_b);
    printf("\n");


    for (int i = 0; i <= stack_b->top; i++)
        printf("%d ", stack_b->data[i]);

    for (int i = 0; i <= stack_a->top; i++)
        printf("%d ", stack_a->data[i]);

    // Free allocated memory
    free_stack(stack_a);
    free_stack(stack_b);

    return 0;
}

