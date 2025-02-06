#include "push_swap.h"


void sort_a(struct push_swap **a)
{
    struct push_swap *min = find_low(*a);
    if (min == NULL)
        return;

    int rotations = 0;
    struct push_swap *current = *a;
    while (current != min)
    {
        rotations++;
        current = current->next;
    }

    if (rotations > len_stack(*a) / 2)
    {
        while ((*a) != min)
            rra(a);
    }
    else
    {
        while ((*a) != min)
            ra(a);
    }
}


void push_swap(struct push_swap **start_a, struct push_swap **start_b)
{
    int size_a = len_stack(*start_a);

    if (size_a > 3)
    {
        while (size_a-- > 3)
            pb(start_a, start_b);
        get_position(start_a);
        tiny_sort(start_a);
    }

    while (*start_b != NULL)
    {
        init_start(start_a, start_b);
        proces(start_a, start_b);
    }
    sort_a(start_a);
}