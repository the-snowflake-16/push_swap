#include "push_swap.h"
// #include <stdio.h>
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
    return (new_value);
}
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

void print_list (struct push_swap *start)
{
    while (start != NULL)
    {
        printf("%d -> ", start->value);
        start = start->next;
    }
    printf("NULL\n");
}

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

// int main()
// {
//     struct push_swap *start_a = NULL;
//     struct push_swap *start_b = NULL;

//     push_to_a(&start_a, 1);
//     push_to_a(&start_a, 3);
//     push_to_a(&start_a, 2);
//     push_to_a(&start_a, 4);

//     printf("Stack_A\n");
//     print_list(start_a);
//     rra(&start_a);
//     pb(&start_a, &start_b);
//     pb(&start_a, &start_b);
//     printf("Stack_A\n");
//     print_list(start_a);
//     printf("Stack_B\n");
//     print_list(start_b);


//     pb(&start_a, &start_b);
//     pb(&start_a, &start_b);
//     pb(&start_a, &start_b);
//     pb(&start_a, &start_b);
//     printf("Stack_B\n");
//     print_list(start_b);
//     rr(&start_a, &start_b);
//     print_list(start_a);
//     printf("Stack_B\n");
//     print_list(start_b);
    // ra(&start_a);
    // rb(&start_b);
    // printf("Stack_A\n");
    // print_list(start_a);
    // printf("Stack_B\n");
    // print_list(start_b);
    // rr(&start_a, &start_b);
    // printf("Stack_A\n");
    // print_list(start_a);
    // printf("Stack_B\n");
    // print_list(start_b);
    // print_list(start_a);
    // print_list(start_b);
    // rb(&start_b);
    // print_list(start_b);
    // sa(start_a);
    // print_list(start_a);
    // sb(start_b);
    // print_list(start_b);
    // pa(&start_b, &start_a);
    // print_list(start_b);
    // print_list(start_a);
//     free_list(start_a);
//     free_list(start_b);
// }