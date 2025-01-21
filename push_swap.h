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

#endif

