#include <stdio.h>
#include "push_swap.h"
#include "push_swap.h"

#include <stdio.h>
#include "push_swap.h"



#include <string.h>
// void	free_matrix(char **argv)
// {
// 	int	i;

// 	i = -1;
// 	if (NULL == argv || NULL == *argv)
// 		return ;
// 	while (argv[i])
// 		free(argv[i++]);
// 	free(argv - 1);
// }
void str_concat(int argc, char *argv[])
{
    int i = 0;
    int j = 2;
    int n = strlen(argv[1]);
    // printf("%s\n", argv[1]);
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
    // free_matrix(argv);
    // printf("%s\n", argv[1]);
    // printf("%d", argc);
}

int main(int argc, char *argv[]) {
    if (argc < 2 || (2 == argc && !argv[1][0])) {
        printf("Usage: %s <numbers>\n", argv[0]);
        return 1;
    }
    if(argc > 2)
    {
        str_concat(argc, argv);
    }

    struct push_swap *start_a = NULL;
    struct push_swap *start_b = NULL;

    atoj(&start_a, argv[1]);
    print_list(start_a);
    if(stack_sorted(start_a))
    {
        free_list(start_a);
        return (0);
    }
    if(!stack_sorted(start_a))
    {
        tiny_sort(&start_a);
    }

    print_list(start_a);
    free_list(start_a);
    free_list(start_b);

    return 0;
}

// int main()
// {
//     struct push_swap *start = NULL;
//     char str[] = "45 76 -87 34 56"; // Example string with positive and negative numbers
//     atoj(&start, str);
//     print_list(start);
//     free_list(start);
// }

// #include <stddef.h>
// #include <stdio.h>
// #include <stdlib.h>

// typedef struct s_struc
// {
//     int value;
//     struct s_struc *next;
// } t_struc;

// void prinf_linked_list(t_struc *head)
// {
//     t_struc *temp = head;
//     while (temp != NULL)
//     {
//         printf("%d - ", temp->value);
//         temp = temp->next;
//     }
//     printf("NULL\n");
// }

// void crate_struct(t_struc **head, int value)
// {
//     t_struc *a;
//     a = malloc(sizeof(t_struc));
//     if(!a)
//         exit(EXIT_FAILURE);
//     a->value = value;
//     a->next = (*head);
//     (*head) = a;
// }
// void create_end(t_struc **head, int value)
// {
//     while ((*head) != NULL)
//     {
//         (*head) = (*head)->next;
//     }
//     t_struc *head_now = malloc(sizeof(t_struc));
//     head_now->value = value;
//     (*head) = head_now;
//     head_now->next = NULL;
    
// }
// void add_to_end(t_struc **head, int new_value)
// {
//     t_struc *new = malloc(sizeof(t_struc));
//     t_struc *lastone = *head;
//     new->value = new_value;
//     new->next = NULL;
//     if(*head == NULL)
//     {
//         *head = new;
//         return;
//     }
//     while ((lastone->next != NULL))
//     {
//         lastone = lastone->next;
//     }
//     lastone->next = new;
//     return;
// }
// int main()
// {
//     t_struc *head = NULL;

//     // crate_struct(&head, 10);
//     // crate_struct(&head, 20);
//     // crate_struct(&head, 30);
//     add_to_end(&head, 10);
//     add_to_end(&head, 20);
//     add_to_end(&head, 30);
//     prinf_linked_list(head);
// }
