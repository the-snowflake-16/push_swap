#include "push_swap.h"

struct push_swap *get_last(struct push_swap *start)
{

    while (start && start->next != NULL)
        start = start->next;
    return (start);    
}

struct push_swap *get_plast(struct push_swap *start)
{

    while (start && start->next->next != NULL)
        start = start->next;
    return (start);    
}
