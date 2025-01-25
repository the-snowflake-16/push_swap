#include "push_swap.h"

//  Swap the first 2 elements at the top of stack

void swap(struct push_swap *start)
{
    if(start == NULL)
        exit(EXIT_FAILURE);        
    int tmp;
    tmp = start->value;
    start->value = start->next->value;
    start->next->value = tmp;
}

void sa(struct push_swap *start_a)
{
    swap(start_a);
    write(1, "sa\n", 3);
}

void sb(struct push_swap *start_b)
{
    swap(start_b);
    write(1, "sb\n", 3);
}
void ss(struct push_swap *start_a, struct push_swap *start_b)
{
    swap(start_a);
    swap(start_b);
    write(1, "ss\n", 3);
}