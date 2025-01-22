#include "push_swap.h"
// #include <stdio.h>
void push_to_a(struct push_swap **start, int value)
{
    struct push_swap *new_value;
    new_value = malloc(sizeof(struct push_swap));
    if(!new_value)
    {
        exit(EXIT_FAILURE);
    }
    new_value->value = value;
    new_value->next = *start;
    *start = new_value;
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
//     // start = malloc(sizeof(struct push_swap));
//     push_to_a(&start_a, 45);
//     push_to_a(&start_a, 78);
//     push_to_a(&start_a, 56);
//     push_to_a(&start_a, 4);
//     push_to_a(&start_a, 65);
//     push_to_a(&start_a, 67);
//     push_to_a(&start_a, 12);
//     push_to_a(&start_a, 56);
//     push_to_a(&start_a, 22);
//     push_to_a(&start_a, 43);
//     push_to_a(&start_a, 44);
//     push_to_a(&start_a, 33);
//     printf("Stack_A\n");
//     print_list(start_a);



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