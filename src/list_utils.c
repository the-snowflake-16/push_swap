#include "push_swap.h"

/* 
 * Allocates memory for a new node of the linked list, 
 * initializes its values, and returns a pointer to the new node.
 */

struct push_swap *new_stract(int value)
{
    struct push_swap *new_value;
    new_value = malloc(sizeof(struct push_swap));
    if(!new_value)
    {
        exit(EXIT_FAILURE);
    }
    new_value->next = NULL;
    new_value->value = value;
    new_value->index = 0;
    // new_value->target_pos = NULL;
    new_value->cost_b = 0;
    // new_value->cheapest = NULL;
    return (new_value);
}

/* 
 * Adds a new node to the end of the linked list (stack A).
 * If the list is empty, the new node becomes the first element.
 */

void push_to_a(struct push_swap **start, struct push_swap *new_value)
{

    struct push_swap *last;
    if(!new_value)
        return ;
    if(!*start)
    {
        *start = new_value;
        return ;
    }
    last = get_last(*start);
    last->next = new_value;
}

/* 
 * Prints the linked list, displaying both values and indices.
 * Format: "value -> index".
 */

void print_list (struct push_swap *start)
{
    while (start != NULL)
    {
        printf("|%d -> ", start->value);
        printf(" %d| ", start->index);
        start = start->next;
    }
    printf("NULL\n");
}

/* 
 * Frees all nodes of the linked list, preventing memory leaks.
 */

void free_list(struct push_swap *start)
{
    struct push_swap *tmp;
    while(start != NULL)
    {
        tmp = start;
        start = start->next;
        free(tmp);
    }
}
