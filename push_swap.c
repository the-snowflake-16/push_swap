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
//     struct push_swap *start = NULL;
//     // start = malloc(sizeof(struct push_swap));
//     push_to_a(&start, 45);
//     push_to_a(&start, 78);
//     push_to_a(&start, 56);
//     print_list(start);
//     free_list(start);
// }