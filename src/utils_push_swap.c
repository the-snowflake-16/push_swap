#include "push_swap.h"

/* 
 * Returns the last element of the stack.
 * If the stack is empty, returns NULL.
 */

struct push_swap *get_last(struct push_swap *start)
{
    if(start == NULL)
        return (NULL);

    while (start && start->next != NULL)
        start = start->next;
    return (start);    
}

/* 
 * Returns the penultimate (second-to-last) element of the stack.
 * If the stack has one or zero elements, returns NULL.
 */

struct push_swap *get_plast(struct push_swap *start)
{
    if (start == NULL || start->next == NULL)
        return (NULL);
    while (start && start->next->next != NULL)
        start = start->next;
    return (start);    
}

/* 
 * Finds and returns the node with the smallest value in the stack.
 * If the stack is empty, returns NULL.
 */

struct push_swap *find_low(struct push_swap *start)
{
    struct push_swap *law;
    if(start == NULL)
        return (NULL);
    law = start;
    while (start != NULL )
    {
        if(start->value < law->value)
            law = start;
        start = start->next;
    }
    return (law);
}

/* 
 * Finds and returns the node with the largest value in the stack.
 * If the stack is empty, returns NULL.
 */

struct push_swap *find_biggest(struct push_swap *start)
{
    struct push_swap *biggest;
    if(start == NULL)
        return (NULL);
    biggest = start;
    while (start != NULL )
    {
        if(start->value > biggest->value)
            biggest = start;
        start = start->next;
    }
    return (biggest);
}

/* 
 * Returns the number of elements in the stack.
 * If the stack is empty, returns 0.
 */

int len_stack(struct push_swap *start)
{
    if(start == NULL)
        return (0);
    int i = 0;
    while (start)
    {
        start = start->next;
        i++;
    }
    return(i);
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