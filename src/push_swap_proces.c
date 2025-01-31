#include "push_swap.h"

void sort_a(struct push_swap *a)
{
    struct push_swap *min = find_low(a);
    while (min != a)
    {
        if (min->index > len_stack(a) / 2)
            rra(&a);
        ra(&a);
    }
}
/* 
 * Initiates the sorting process for stack A using the Push Swap algorithm.
 * If stack A has more than 3 elements, move elements to stack B until only 3 remain.
 * Then, sort the remaining three elements using `tiny_sort()`.
 * After that, initialize the sorting process for the remaining elements.
 */

void push_swap(struct push_swap **start_a, struct push_swap **start_b)
{
    int size_a = len_stack(*start_a);
    if(size_a > 3)
    {
        while (size_a-- != 3)
            pb(start_a, start_b);
        get_position(start_a);
        tiny_sort(start_a);
    }
    // print_list(*start_a);
    // init_start(start_a, start_b);
    while ((*start_b) != NULL)
    {
        init_start(start_a, start_b);
        rotatea(start_a, start_b); 
        // print_list(*start_b);
        // print_list(*start_a);
    }
    sort_a(*start_a);
        // print_list(*start_b);
    // print_list(*start_a);
    // free_list(*start_b);
}