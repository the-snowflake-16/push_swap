#include "push_swap.h"

void rotate(struct push_swap **start)
{
    struct push_swap *tmp;
    struct push_swap *tmp2;
    tmp = (*start);
    *start = (*start)->next;
    tmp2 = get_last(*start);
    tmp->next = NULL;
    tmp2->next = tmp;
}
void ra(struct push_swap **start_a)
{
    rotate(start_a);
    write(1, "ra\n", 3);
}

void rb(struct push_swap **start_b)
{
    rotate(start_b);
    write(1, "rb\n", 3);
}

void rr(struct push_swap **start_a, struct push_swap **start_b)
{
    ra(start_a);
    rb(start_b);
}