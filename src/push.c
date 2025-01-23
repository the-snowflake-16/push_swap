#include "push_swap.h"

void push (struct push_swap **src, struct push_swap **dest)
{
    struct push_swap *new;
    if (*src == NULL)
        return ;
    new = (*src)->next;
	(*src)->next = *dest;
    (*dest) = (*src);
    (*src) = new;
}

void pb(struct push_swap **start_a, struct push_swap **start_b)
{
    push(start_a, start_b);
    write(1, "pb\n", 3);
}

void pa(struct push_swap **start_b, struct push_swap **start_a)
{
    push(start_b, start_a);
    write(1, "pa\n", 3);
}