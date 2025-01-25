#include "push_swap.h"
#include <stdio.h>

int ft_isdigit(char *c)
{
    int i = 0;
    if (c[i] == 0)
        return (0);
    if (c[i] == '-')
        i++;
    while (c[i])
    {
        if(c[i] < '0' || c[i] > '9')
            return (0);
        i++;
    }
    return (1);
}

void put_char(int c)
{
    write(1, &c, 1);
}

int cheack_double(struct push_swap *start, int value)
{
    while (start != NULL)
    {
        if(value == start->value)
            return(0);
        start = start->next;
    }
    return(1);
}

void atoj(struct push_swap **start, char *str)
{
    int i = 0;
    int result = 0;
    int is_negative = 0;

    while (str[i] != '\0')
    {
        if (str[i] == '-')
            is_negative = 1;
        else if (str[i] >= '0' && str[i] <= '9')
            result = result * 10 + (str[i] - '0');
        else if (str[i] == ' ')
        {
            if (is_negative)
                result = -result;
            else if (!cheack_double(*start, result))
            {
                printf("DOUBLE number:");
                free_list(*start);
                exit(EXIT_FAILURE);
            }
            push_to_a(start, new_stract((int)result));
            result = 0;
            is_negative = 0;

        }
        else
        {
            printf("ERROR");
            free_list(*start);
            exit(EXIT_FAILURE);
        }
        i++;
    }
    if (result != 0 || is_negative) {
        if (is_negative)
            result = -result;
        if (!cheack_double(*start, result))
        {
            printf("DOUBLE number:");
            free_list(*start);
            exit(EXIT_FAILURE);
        }
        push_to_a(start, new_stract((int)result));
    }
}

// void atoj(struct push_swap **start, char *str)
// {
//     int i = 0;
//     int result = 0;
//     int sighn = 1;
//     while (str[i] != '\0')
//     {
//         if(str[i] == '-')
//         {
//             sighn = -1;
//             i++;
//         }
//         if(str[i] >= '0' && str[i] <= '9')
//             result = result * 10 + str[i] - '0';
//         else if (str[i] == ' ' || str[i+1] == '\0')
//         {
//             if (str[i + 1] == '\0' && str[i] >= '0' && str[i] <= '9')
//                 result = result * 10 + (str[i] - '0');
//             push_to_a(start, result * sighn);
//             result = 0;
//             sighn = 1;
//         }
//         else
//         {
//             printf("ERROR");
//             free_list(*start);
//             exit(EXIT_FAILURE);
//         }
//         i++;
//     }
// }


// int main()
// {
//     struct push_swap *start = NULL;
//     char str[] = "45 76 45 34 56"; // Example string with positive and negative numbers

//     atoj(&start, str);

//     print_list(start);
//     free_list(start);
// }
