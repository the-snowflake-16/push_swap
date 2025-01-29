#include "push_swap.h"

/* 
 * Sorts a stack of three elements in ascending order.
 * Uses rotations (ra, rra) and swap (sa) to achieve the correct order.
 */

void tiny_sort (struct push_swap **start_a)
{
    struct push_swap *bigges;

    bigges = find_biggest(*start_a);
    if(*start_a == bigges)
        ra(start_a);
    if((*start_a)->next == bigges)
        rra(start_a);
    if ((*start_a)->value > (*start_a)->next->value)
        sa(*start_a);    
}