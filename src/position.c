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
int best_position(struct push_swap *start, int value)
{
    if (!start)
        return(-1);

    int closest_bigerr = INT_MAX;
    struct push_swap *min = find_low(start);
    struct push_swap *max = find_biggest(start);
    struct push_swap *target_pos = NULL;

    while (start)
    {
        if (value < start->value && start->value < closest_bigerr)
        {
            closest_bigerr = start->value;
            target_pos = start;
        }
        else if (value > max->value)
        {
            closest_bigerr = min->value;
            target_pos = min;
        }

        start = start->next;
    }

    if (target_pos)
        return (target_pos->index);
        // printf("Best position for value b %d is before %d (index = %d)\n",
        //        value, target_pos->value, target_pos->index);
    else
        return (-1);
        // printf("Best position for value b %d is before %d (index = %d)\n", value, target_pos->value, target_pos->index);
}

/* 
 * Find the optimal insertion position for each element in stack B within stack A.
 * For each element in B, determine the index in A where it should be inserted 
 * to maintain a sorted order and store this position in `target_pos`.
 */

void best_position_elements(struct push_swap *a, struct push_swap *b)
{
    struct push_swap *tmp_b;
    tmp_b = b;
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
    best_position_elements(a, b);
    struct push_swap *tmp_b = b;

    int len_a = len_stack(a);
    int len_b = len_stack(b);

    while (tmp_b)
    {
        if(tmp_b->target_pos > len_a / 2)
        {
            tmp_b->cost_b = len_a - tmp_b->target_pos;
            printf("first if %d > %d\n %d\n", tmp_b->target_pos ,len_a/2, tmp_b->cost_b);
        }
        else
        {
            tmp_b->cost_b = tmp_b->target_pos;
            printf("first else %d\n",tmp_b->cost_b);
        }
           
        if (tmp_b->index > len_b / 2)
        {
             tmp_b->cost_b += len_b - tmp_b->index;
             printf("second if %d\n", tmp_b->cost_b);
        } 

        else
            tmp_b->cost_b += tmp_b->index;
        printf("Value: %d, Total Cost: %d\n",
               tmp_b->value, tmp_b->cost_b);
        printf("Value: %d, best position %d\n",
               tmp_b->value, tmp_b->target_pos);
        tmp_b = tmp_b->next;

        }
}
void init_start(struct push_swap **a, struct push_swap **b)
{
    get_position(a);
    get_position(b);
    count_position(*a, *b);
}
// int main()
// {
//     struct push_swap *start_a = NULL;
//     struct push_swap *start_b = NULL;

//     push_to_a(&start_a, new_stract(300));
//     push_to_a(&start_a, new_stract(29));
//     push_to_a(&start_a, new_stract(5));
//     push_to_a(&start_a, new_stract(14));
//     push_to_a(&start_a, new_stract(15));
//     push_to_a(&start_a, new_stract(6));
//     push_to_a(&start_a, new_stract(16));
//     push_to_a(&start_a, new_stract(22));
//     push_to_a(&start_a, new_stract(28));
//     push_to_a(&start_a, new_stract(76));
//     // push_to_a(&start_a, new_stract(55));
//     // push_to_a(&start_a, new_stract(45));
//     // print_list(start_a);
//     pb(&start_a, &start_b);
//     pb(&start_a, &start_b);
//     pb(&start_a, &start_b); 
//     pb(&start_a, &start_b);
//     pb(&start_a, &start_b);
//     // tiny_sort(&start_a);
//     // get_position(&start_a);
//     // get_position(&start_b);
//     // print_list(start_a);
//     // print_list(start_b);
//     // count(start_a, start_b);
//     init_start(&start_a, &start_b);
//     free_list(start_a);

//     free_list(start_b);
// }