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

struct push_swap *find_low(struct push_swap *start)
{
    struct push_swap *law;
    law = start;
    while (start->next != NULL )
    {
        if(start->value < law->value)
            law = start;
        start = start->next;
    }
    return (law);
}

struct push_swap *find_biggest(struct push_swap *start)
{
    struct push_swap *biggest;
    biggest = start;
    while (start->next != NULL )
    {
        if(start->value > biggest->value)
            biggest = start;
        start = start->next;
    }
    return (biggest);
}

/*
 * Check if a given stack is sorted
*/
int	stack_sorted(struct push_swap *stack)
{
	if (NULL == stack)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}