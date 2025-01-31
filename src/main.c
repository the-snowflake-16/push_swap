#include <stdio.h>
#include <string.h>
#include "push_swap.h"

void str_concat(int argc, char *argv[])
{
    int i = 0;
    int j = 2;
    int n = strlen(argv[1]);

    argv[1][n++] = ' ';
    while (j < argc)
    {
        i = 0;
        while(argv[j][i])
        {
            argv[1][n++] = argv[j][i++];
        }
        argv[1][n++] = ' ';
        j++;
    }
    argv[1][n++] = '\0';
}

int main(int argc, char *argv[]) {

    struct push_swap *start_a = NULL;
    struct push_swap *start_b = NULL;

    if (argc < 2 || (2 == argc && !argv[1][0])) {
        printf("Usage: %s <numbers>\n", argv[0]);
        return 1;
    }
    if(argc > 2)
    {
        str_concat(argc, argv);
    }
    atoj(&start_a, argv[1]);
    if (len_stack(start_a ) < 2)
    {
        printf("ERROR less than 2 numbers\n");
        return (0);
    }
    push_swap(&start_a, &start_b);
    if(stack_sorted(start_a))
    {
        free_list(start_a);
        return (0);
    }
    if (len_stack(start_a) == 3)
        tiny_sort(&start_a);
    free_list(start_a);
    // free_list(start_b);
    return 0;
}
