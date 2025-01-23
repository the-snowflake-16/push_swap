#ifndef PUSHSWAP_H

# define PUSHSWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

struct push_swap
{
    int value;
    struct push_swap *next;
};

int ft_isdigit(char *c);
void put_char(int c);
void free_list(struct push_swap *start);
void push_to_a(struct push_swap **start, int value);
void print_list (struct push_swap *start);
void atoj(struct push_swap **start, char *str);

void sa(struct push_swap *start_a);
void sb(struct push_swap *start_b);
void pb(struct push_swap **start_a, struct push_swap **start_b);
void pa(struct push_swap **start_b, struct push_swap **start_a);
void ss(struct push_swap *start_a, struct push_swap *start_b);
void ra(struct push_swap **start_a);
void rb(struct push_swap **start_b);
void rr(struct push_swap **start_a, struct push_swap **start_b);
void rra(struct push_swap **start_a);
void rrb(struct push_swap **start_b);
void rrr(struct push_swap **start_a, struct push_swap **start_b);

struct push_swap *get_last(struct push_swap *start);
struct push_swap *get_plast(struct push_swap *start);

#endif

