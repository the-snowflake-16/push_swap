#include "push_swap.h"

void rrotate(struct push_swap **start)
{
    struct push_swap *tmp1;
    struct push_swap *tmp2;
    struct push_swap *tmp3;
    tmp1 = (*start);
    tmp2 = get_plast(*start);
    tmp3 = get_last(*start);
    *start = (*start)->next; 
    tmp1->next = NULL;
    tmp3->next = *start;
    tmp2->next = tmp1;
    (*start) = tmp3;
    
}

void rra(struct push_swap **start_a)
{
    rrotate(start_a);
    write(1, "rra\n", 4);
}

void rrb(struct push_swap **start_b)
{
    rrotate(start_b);
    write(1, "rrb\n", 4);
}

void rrr(struct push_swap **start_a, struct push_swap **start_b)
{
    rra(start_a);
    rrb(start_b);
}