#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>

// Check if a string is a valid integer
int ft_isdigit(char *c)
{
    int i = 0;
    if (c[i] == 0)
        return (0);
    if (c[i] == '-')
        i++;
    while (c[i])
    {
        if (c[i] < '0' || c[i] > '9')
            return (0);
        i++;
    }
    return (1);
}

// Check for duplicate values in the linked list
int check_double(struct push_swap *start, int value)
{
    while (start != NULL)
    {
        if (value == start->value)
            return (0);
        start = start->next;
    }
    return (1);
}
