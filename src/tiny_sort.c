#include "push_swap.h"
#include <stdio.h>

void tiny_sort (struct push_swap **start_a)
{
    struct push_swap *bigges;

    bigges = find_biggest(*start_a);
    if(*start_a == bigges)
        ra(start_a);
    else if((*start_a)->next == bigges)
        rra(start_a);
    if ((*start_a)->value > (*start_a)->next->value)
        sa(*start_a);    
}