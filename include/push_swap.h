#ifndef PUSHSWAP_H

# define PUSHSWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

struct push_swap
{
    int value;
    int index;
    struct push_swap *target_pos;
    int cost_b;
    struct push_swap *cheapest;
    struct push_swap *next;
};

// utils
int ft_isdigit(char *c);

// swap
void sa(struct push_swap *start_a);
void sb(struct push_swap *start_b);
void ss(struct push_swap *start_a, struct push_swap *start_b);

// push 
void pb(struct push_swap **start_a, struct push_swap **start_b);
void pa(struct push_swap **start_b, struct push_swap **start_a);

// rotate
void ra(struct push_swap **start_a);
void rb(struct push_swap **start_b);
void rr(struct push_swap **start_a, struct push_swap **start_b);

// rrotate
void rra(struct push_swap **start_a);
void rrb(struct push_swap **start_b);
void rrr(struct push_swap **start_a, struct push_swap **start_b);

// utils_push_swap
struct push_swap *get_last(struct push_swap *start);
struct push_swap *get_plast(struct push_swap *start);
struct push_swap *find_low(struct push_swap *start);
struct push_swap *find_biggest(struct push_swap *start);
int len_stack(struct push_swap *start);
int	stack_sorted(struct push_swap *stack);

// tiny_sort
void tiny_sort (struct push_swap **start_a);

//list_utils
struct push_swap *new_stract(int value);
void push_to_a(struct push_swap **start, struct push_swap *new_value);
void print_list (struct push_swap *start);
void free_list(struct push_swap *start);

// position
void init_start(struct push_swap **a, struct push_swap **b);
void get_position (struct push_swap **start);

// push_swap_proces
void push_swap(struct push_swap **start_a, struct push_swap **start_b);


int ft_isdigit(char *c);
int ft_strlen(const char *s);
int count_words(const char *s, char sep);
int check_double(struct push_swap *start, int value);
char **ft_split(const char *str, char separator);
void	stack_init(char **argv, struct push_swap **a);

void proces(struct push_swap **a, struct push_swap **b);
#endif

