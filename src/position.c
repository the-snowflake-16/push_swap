#include "push_swap.h"

/* giving index for each position on linkned list */
void get_position (struct push_swap **start)
{
    struct push_swap *tmp;

    tmp = *start;
    int i = 0;
    while (tmp)
    {
        tmp->index= i;
        i++;
        tmp = tmp->next;
    }
    
}

/* find the best position for value in start_a */
struct push_swap *best_position(struct push_swap *start, int value)
{
    if (!start)
        return NULL;

    struct push_swap *min = find_low(start);
    struct push_swap *max = find_biggest(start);
    struct push_swap *target_pos = NULL;
    int closest_bigger = INT_MAX;

    while (start)
    {
        if (value < start->value && start->value < closest_bigger)
        {
            closest_bigger = start->value;
            target_pos = start;
        }
        start = start->next;
    }
    if (!target_pos || value > max->value)
        target_pos = min;

    return target_pos;
}

void best_position_elements(struct push_swap *a, struct push_swap *b)
{
    struct push_swap *tmp_b = b;

    while (tmp_b)
    {
        tmp_b->target_pos = best_position(a, tmp_b->value);
        tmp_b = tmp_b->next;
    }
}


/* 
 * Calculate the cost of moving each element from stack B to its best position in stack A.
 * The cost is determined by the number of operations required to bring both 
 * the element in B and its target position in A to the top of their respective stacks.
 */

void count_position(struct push_swap *a, struct push_swap *b)
{

    struct push_swap *tmp_b = b;

    int len_a = len_stack(a);
    int len_b = len_stack(b);

    while (tmp_b)
    {
        if(tmp_b->target_pos->index > len_a / 2)
        {
            tmp_b->cost_b = len_a - tmp_b->target_pos->index;
            // printf("first if %d > %d\n %d\n", tmp_b->target_pos ,len_a/2, tmp_b->cost_b);
        }
        else
        {
            tmp_b->cost_b = tmp_b->target_pos->index;
            // printf("first else %d\n",tmp_b->cost_b);
        }
           
        if (tmp_b->index > len_b / 2)
        {
             tmp_b->cost_b += len_b - tmp_b->index;
            //  printf("second if %d\n", tmp_b->cost_b);
        } 

        else
            tmp_b->cost_b += tmp_b->index;
        // printf("Value: %d, Total Cost: %d\n",
        //        tmp_b->value, tmp_b->cost_b);
        // printf("Value: %d, best position %d\n",
        //        tmp_b->value, tmp_b->target_pos);
        tmp_b = tmp_b->next;

        }
}

void get_cheapest(struct push_swap *b)
{
    if (!b) return;

    struct push_swap *tmp_b = b;
    struct push_swap *cheapest = b;

    while(tmp_b)
    {
        if(tmp_b->cost_b < cheapest->cost_b)
            cheapest = tmp_b;
        tmp_b = tmp_b->next;
    }

    // Назначаем cheapest для всех элементов списка
    tmp_b = b;
    while (tmp_b)
    {
        tmp_b->cheapest = cheapest;
        tmp_b = tmp_b->next;
    }
}



void init_start(struct push_swap **a, struct push_swap **b)
{
    get_position(a);
    get_position(b);
    best_position_elements(*a, *b);
    count_position(*a, *b);
    get_cheapest(*b);
}

/* Get target position */

struct push_swap *get_target(struct push_swap *a)
{
    while (a)
    {
        if (a == a->target_pos)
            return a;
        a = a->next;
    }
    return NULL;
}


void rotatea(struct push_swap **a, struct push_swap **b, struct push_swap *cheapest_index, struct push_swap *target_index)
{
    int size_b = len_stack(*b);  // Cache the size of stack b
    int size_a = len_stack(*a);  // Cache the size of stack a

    // Rotate stack b to the cheapest_index
    while (*b != cheapest_index)
    {
        if (cheapest_index->index > size_b / 2)
            rrb(b);
        else
            rb(b);
    }

    // Rotate stack a to the target_index
    while (*a != target_index)
    {
        if (target_index->index > size_a / 2)
            rra(a);
        else
            ra(a);
    }

}


void proces(struct push_swap **a, struct push_swap **b)
{


    while (*b)
    {
        struct push_swap *cheapest_index = (*b)->cheapest;
        struct push_swap *target_index = best_position(*a, cheapest_index->value);

        rotatea(a, b, cheapest_index, target_index);
    
        pa(b, a);  // Push the element from b to a

        // Reset the stacks to their starting position
        init_start(a, b);
    }

}
